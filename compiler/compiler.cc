/**
 * Clever programming language
 * Copyright (c) 2011-2012 Clever Team
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "compiler/cstring.h"
#include "compiler/compiler.h"
#include "compiler/scope.h"
#include "compiler/value.h"
#include "interpreter/location.hh"
#include "types/native_types.h"

namespace clever {

// Declaration of namespace global type ptrs for Clever native types
DECLARE_CLEVER_NATIVE_TYPES();

/// Compiler initialization phase
void Compiler::init()
{
	m_scope = new Scope;

	m_ir.reserve(20);
	m_scope_pool.reserve(10);
	m_type_pool.reserve(15);

	m_scope_pool[m_scope_id++] = m_scope;

	// Native type allocation
	m_type_pool[m_type_id++] = CLEVER_INT_TYPE    = new IntType;
	m_type_pool[m_type_id++] = CLEVER_DOUBLE_TYPE = new DoubleType;
	m_type_pool[m_type_id++] = CLEVER_STR_TYPE    = new StrType;
	m_type_pool[m_type_id++] = CLEVER_FUNC_TYPE   = new FuncType;

	m_pkg.init();
}

/// Frees all resource used by the compiler
void Compiler::shutdown()
{
	m_pkg.shutdown();

	CLEVER_SAFE_DELETE(g_cstring_tbl);
	CLEVER_SAFE_DELETE(m_scope);

	TypePool::const_iterator it2 = m_type_pool.begin(),
		end2 = m_type_pool.end();

	while (it2 != end2) {
		delete *it2;
		++it2;
	}
}

// Compiler termination phase
void Compiler::end()
{
}

/// Displays an error message and exits
void Compiler::error(const char* msg) const
{
	std::cerr << "Compile error: " << msg << std::endl;
	CLEVER_EXIT_FATAL();
}

/// Displays an error message
void Compiler::error(const std::string& message, const location& loc) const
{
	if (loc.begin.filename) {
		std::cerr << "Compile error: " << message << " on "
			<< *loc.begin.filename << " line " << loc.begin.line << "\n";
	} else {
		std::cerr << "Compile error: " << message << " on line "
			<< loc.begin.line << "\n";
	}
	CLEVER_EXIT_FATAL();
}

/// Displays a formatted error message and abort the compilation
void Compiler::errorf(const location& loc, const char* format, ...) const
{
	std::ostringstream out;
	va_list args;

	va_start(args, format);

	vsprintf(out, format, args);

	va_end(args);

	error(out.str(), loc);
}

/// Abstracts the Value* ptr gets from Node
// NOTE: When the Node is a STRCONST, it automatically increments the Value's
// refcount related to the Symbol
Value* Compiler::getValue(Node& node, Symbol** symbol, const location& loc) const
{
	if (node.type == VALUE) {
		return node.data.val;
	} else if (node.type == STRCONST) {
		Symbol* sym = m_scope->getAny(node.data.str);

		if (!sym) {
			errorf(loc, "Variable `%S' cannot be found!", node.data.str);
		}
		if (symbol) {
			*symbol = sym;
		}

		return m_scope_pool[sym->scope->getId()]->getVar(sym->value_id);
	}
	return NULL;
}

/// Compiles a variable declaration
void Compiler::varDeclaration(Node& var, Node* node, const location& loc)
{
	Symbol* sym = m_scope->getLocal(var.data.str);

	if (sym) {
		errorf(loc, "Variable `%S' already declared in the scope!", var.data.str);
	}

	size_t sym_id = m_scope->pushVar(var.data.str, new Value());

	// A NULL value is created for uninitialized declaration
	sym = NULL;
	Value* val = node ? getValue(*node, &sym, loc) : new Value();

	// Value to be assigned
	if (sym) {
		m_ir.push_back(
			IR(OP_ASSIGN, FETCH_VAL, sym_id, FETCH_VAL, sym->value_id));

		m_ir.back().op2_scope = sym->scope->getId();
	} else {
		m_ir.push_back(
			IR(OP_ASSIGN, FETCH_VAL, sym_id, FETCH_VAL, m_scope->pushConst(val)));

		m_ir.back().op2_scope = m_scope->getId();
	}
	m_ir.back().op1_scope = m_scope->getId();
}

/// Compiles a variable assignment
void Compiler::assignment(Node& var, Node& value, const location& loc)
{
	Symbol* var_sym = NULL, *val_sym = NULL;
	(void)getValue(var, &var_sym, loc);
	Value* val = getValue(value, &val_sym, loc);

	if (val_sym) {
		m_ir.push_back(
			IR(OP_ASSIGN, FETCH_VAL, var_sym->value_id, FETCH_VAL, val_sym->value_id));

		m_ir.back().op1_scope = var_sym->scope->getId();
		m_ir.back().op2_scope = val_sym->scope->getId();
	} else {
		m_ir.push_back(
			IR(OP_ASSIGN, FETCH_VAL, var_sym->value_id, FETCH_VAL, m_scope->pushConst(val)));

		m_ir.back().op1_scope = var_sym->scope->getId();
		m_ir.back().op1_scope = m_scope->getId();

	}
}

/// Compiles a set of binary operation
void Compiler::binOp(Opcode op, Node& lhs, Node& rhs, Node& res,
	const location& loc)
{/*
	size_t rhs_id = 0, lhs_id = 0;
	Value* result = new Value();

	Value* val = getValue(lhs, &lhs_id, loc);

	if (!lhs_id) {
		lhs_id = m_value_id++;
		m_value_pool[lhs_id] = val;
	}

	val = getValue(rhs, &rhs_id, loc);

	if (!rhs_id) {
		rhs_id = m_value_id++;
		m_value_pool[rhs_id] = val;
	}

	m_ir.push_back(
		IR(op, FETCH_VAL, lhs_id, FETCH_VAL, rhs_id, result));

	res.type = VALUE;
	res.data.val = result;*/
}

/// Creates a list of arguments
ArgDeclList* Compiler::newArgDeclList(const CString* arg) const
{
	ArgDeclList* arg_list = new ArgDeclList;
	arg_list->push_back(arg);

	return arg_list;
}

/// Starts the function compilation
void Compiler::funcDecl(Node& node, ArgDeclList* arg_list, const location& loc)
{
	Symbol* sym = m_scope->getAny(node.data.str);

	if (sym) {
		errorf(loc, "Name `%S' already in used!", node.data.str);
	}
	// Saves the current instruction size to be used as a index for
	// changing the jmp address to right after the end of function declaration
	m_curr_func = m_ir.size();

	Value* func = new Value();
	Function* funcdata = static_cast<Function*>(CLEVER_FUNC_TYPE->allocData());

	func->setType(CLEVER_FUNC_TYPE);
	func->setObj(funcdata);

	funcdata->setName(*node.data.str);
	funcdata->setUserDefined();
	funcdata->setAddr(m_curr_func + 1);

	m_ir.push_back(IR(OP_JMP, JMP_ADDR, 0));

	// Adds the function symbol to the current scope
	m_scope->pushVar(node.data.str, func);

	// Create a scope for argument list when used
	if (arg_list) {
		ArgDeclList::const_iterator it = arg_list->begin(),
			end = arg_list->end();

		newScope();

		while (it != end) {
			m_scope->pushVar(*it, new Value());
			++it;
		}
		delete arg_list;

		funcdata->setArgVars(m_scope);
	}

	// Creates a scope for the local vars
	newScope();

	funcdata->setLocalVars(m_scope);
}

/// Adds new argument to the call argument list
ArgCallList* Compiler::addArgCall(ArgCallList* arg_list, Node& arg, const location& loc)
{
	Symbol* sym = NULL;
	Value* val = getValue(arg, &sym, loc);

	if (!arg_list) {
		arg_list = new ArgCallList;
	}

	if (sym) {
		arg_list->push_back(std::pair<size_t, size_t>(sym->scope->getId(), sym->value_id));
	} else {
		arg_list->push_back(std::pair<size_t, size_t>(m_scope->getId(), m_scope->pushConst(val)));
	}

	return arg_list;
}

/// Ends the current function compilation
void Compiler::funcEndDecl(bool has_args)
{
	m_ir.push_back(IR(OP_LEAVE));
	// Changes the JMP's addr created right before the func declaration
	// to point to the end of current function, thus skipping its opcodes
	m_ir[m_curr_func].op1 = m_ir.size();

	// Switchs to the global scope again
	if (has_args) {
		endScope();
	}
	endScope();
}

/// Function call compilation
void Compiler::funcCall(Node& name, ArgCallList* arg_list, Node& res,
	const location& loc)
{
	Symbol* sym = m_scope->getAny(name.data.str);

	if (!sym) {
		errorf(loc, "Function `%S' cannot be found!", name.data.str);
	}

	Value* result = new Value();

	if (arg_list) {
		for (size_t i = 0, j = arg_list->size(); i < j; ++i) {
			m_ir.push_back(IR(OP_SEND_VAL, FETCH_VAL, arg_list->at(i).second));

			m_ir.back().op1_scope = arg_list->at(i).first;
		}
	}

	res.type = VALUE;
	res.data.val = result;

	m_ir.push_back(
		IR(OP_FCALL, FETCH_VAL, sym->value_id, result));

	m_ir.back().op1_scope = sym->scope->getId();

	if (arg_list) {
		delete arg_list;
	}
}

/// Compiles a return statement
void Compiler::retStmt(Node* expr, const location& loc)
{
	if (expr) {
		Symbol* sym;
		Value* value = getValue(*expr, &sym, loc);

		if (sym) {
			m_ir.push_back(IR(OP_RET, FETCH_VAL, sym->value_id));
		} else {
			m_ir.push_back(IR(OP_RET, FETCH_VAL, m_scope->pushConst(value)));
		}
	} else {
		m_ir.push_back(IR(OP_RET));
	}
}

void Compiler::importStmt(Node& package)
{
	m_pkg.importPackage(m_scope, package.data.str);
}

void Compiler::importStmt(Node& package, Node& module)
{
	m_pkg.importModule(m_scope, package.data.str, module.data.str);
}

void Compiler::whileLoop(Node& cond, const location& loc)
{
	Symbol* sym = NULL;
	Value* val = getValue(cond, &sym, loc);

	m_jmps.push(std::vector<size_t>());
	m_jmps.top().push_back(m_ir.size());

	if (sym) {
		m_ir.push_back(IR(OP_JMPZ, FETCH_VAL, sym->value_id, JMP_ADDR, 0));

		m_ir.back().op1_scope = sym->scope->getId();
	} else {
		m_ir.push_back(IR(OP_JMPZ, FETCH_VAL, m_scope->pushConst(val), JMP_ADDR, 0));
	}
}

void Compiler::endWhileLoop()
{
	m_ir.push_back(IR(OP_JMP, JMP_ADDR, m_jmps.top().at(0)));

	m_ir[m_jmps.top().at(0)].op2 = m_ir.size();
}

/// Creates a new lexical scope
void Compiler::newScope()
{
	m_scope = m_scope->newLexicalScope();
	m_scope->setId(m_scope_id);

	m_scope_pool[m_scope_id++] = m_scope;
}

/// Scope end marker to switch to parent scope
void Compiler::endScope()
{
	m_scope = m_scope->getParent();
}

} // clever
