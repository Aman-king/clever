/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */




#include "parser.hh"

/* User implementation prologue.  */


/* Unqualified %code blocks.  */


#include "core/driver.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace clever {


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Driver& driver_yyarg, ScannerState& state_yyarg, Compiler& c_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      state (state_yyarg),
      c (c_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
{
yylloc.begin.filename = yylloc.end.filename = driver.getFile();
}


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, driver, state);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

    { c.init(driver.getFile()); }
    break;

  case 3:

    { c.setAST((yysemantic_stack_[(2) - (2)].block)); }
    break;

  case 4:

    { (yyval.block) = new ast::Block(yyloc); }
    break;

  case 5:

    { (yysemantic_stack_[(2) - (1)].block)->append((yysemantic_stack_[(2) - (2)].node));       }
    break;

  case 24:

    { (yyval.block) = (yysemantic_stack_[(3) - (2)].block); }
    break;

  case 25:

    { (yyval.inst) = new ast::Instantiation((yysemantic_stack_[(3) - (1)].type), NULL, yyloc); }
    break;

  case 26:

    { (yyval.inst) = new ast::Instantiation((yysemantic_stack_[(6) - (1)].type), (yysemantic_stack_[(6) - (5)].narray),   yyloc); }
    break;

  case 27:

    { (yyval.break_) = new ast::Break(yyloc); }
    break;

  case 28:

    { (yyval.continue_) = new ast::Continue(yyloc); }
    break;

  case 29:

    { (yyval.threadblock) = new ast::ThreadBlock((yysemantic_stack_[(3) - (3)].block), (yysemantic_stack_[(3) - (2)].ident), yyloc); }
    break;

  case 30:

    { (yyval.threadblock) = new ast::ThreadBlock((yysemantic_stack_[(6) - (6)].block), (yysemantic_stack_[(6) - (2)].ident), (yysemantic_stack_[(6) - (4)].node), yyloc); }
    break;

  case 31:

    { (yyval.criticalblock) = new ast::CriticalBlock((yysemantic_stack_[(2) - (2)].block), yyloc); }
    break;

  case 42:

    { (yyval.node) = (yysemantic_stack_[(3) - (2)].node); }
    break;

  case 57:

    { (yyval.class_) = new ast::ClassDef((yysemantic_stack_[(6) - (2)].type), (yysemantic_stack_[(6) - (4)].narray), (yysemantic_stack_[(6) - (5)].narray), yyloc); }
    break;

  case 58:

    { (yyval.narray) = NULL; }
    break;

  case 60:

    { (yyval.narray) = new ast::NodeArray(yyloc); }
    break;

  case 61:

    { (yyval.narray) = (yysemantic_stack_[(3) - (1)].narray); }
    break;

  case 62:

    { (yyval.narray) = (yysemantic_stack_[(1) - (1)].narray); }
    break;

  case 64:

    { (yyval.narray) = (yysemantic_stack_[(1) - (0)].narray); }
    break;

  case 66:

    { (yyval.narray) = (yysemantic_stack_[(1) - (0)].narray); }
    break;

  case 76:

    { (yysemantic_stack_[(1) - (0)].narray)->append((yysemantic_stack_[(1) - (1)].attr)); }
    break;

  case 77:

    { (yysemantic_stack_[(3) - (0)].narray)->append((yysemantic_stack_[(3) - (3)].attr)); }
    break;

  case 78:

    { (yyval.attr) = new ast::AttrDecl((yysemantic_stack_[(3) - (1)].ident), (yysemantic_stack_[(3) - (3)].node), false, yyloc); }
    break;

  case 79:

    { (yyval.attr) = new ast::AttrDecl((yysemantic_stack_[(1) - (1)].ident), NULL, false, yyloc);     }
    break;

  case 80:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].attr)); }
    break;

  case 81:

    { (yysemantic_stack_[(3) - (1)].narray)->append((yysemantic_stack_[(3) - (3)].attr)); }
    break;

  case 82:

    { (yyval.attr) = new ast::AttrDecl((yysemantic_stack_[(3) - (1)].ident), (yysemantic_stack_[(3) - (3)].node), true, yyloc);   }
    break;

  case 83:

    { (yyval.narray) = NULL; }
    break;

  case 85:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].fdecl)); }
    break;

  case 86:

    { (yysemantic_stack_[(2) - (1)].narray)->append((yysemantic_stack_[(2) - (2)].fdecl)); }
    break;

  case 87:

    { (yyval.inst) = new ast::Instantiation(CSTRING("Array"), (yysemantic_stack_[(3) - (2)].narray), yyloc); }
    break;

  case 88:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(3) - (1)].strlit)); (yyval.narray)->append((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 89:

    { (yysemantic_stack_[(5) - (1)].narray)->append((yysemantic_stack_[(5) - (3)].strlit)); (yysemantic_stack_[(5) - (1)].narray)->append((yysemantic_stack_[(5) - (5)].node));                                 }
    break;

  case 90:

    { (yyval.inst) = new ast::Instantiation(CSTRING("Map"), NULL, yyloc); }
    break;

  case 91:

    { (yyval.inst) = new ast::Instantiation(CSTRING("Map"), (yysemantic_stack_[(3) - (2)].narray), yyloc);   }
    break;

  case 92:

    { (yyval.throw_) = new ast::Throw((yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 94:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].catch_)); }
    break;

  case 95:

    { (yysemantic_stack_[(2) - (1)].narray)->append((yysemantic_stack_[(2) - (2)].catch_));                                 }
    break;

  case 96:

    { (yyval.catch_) = new ast::Catch((yysemantic_stack_[(5) - (3)].ident), (yysemantic_stack_[(5) - (5)].block), yyloc); }
    break;

  case 97:

    { (yyval.block) = NULL; }
    break;

  case 98:

    { (yyval.block) = (yysemantic_stack_[(2) - (2)].block);   }
    break;

  case 99:

    { (yyval.except) = new ast::Try((yysemantic_stack_[(4) - (2)].block), (yysemantic_stack_[(4) - (3)].narray), (yysemantic_stack_[(4) - (4)].block), yyloc); }
    break;

  case 100:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 101:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].type), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 102:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 103:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].type), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 104:

    { (yyval.mcall) = new ast::MethodCall((yysemantic_stack_[(6) - (1)].node), (yysemantic_stack_[(6) - (3)].ident), (yysemantic_stack_[(6) - (5)].narray), yyloc); }
    break;

  case 105:

    { (yyval.mcall) = new ast::MethodCall((yysemantic_stack_[(6) - (1)].type), (yysemantic_stack_[(6) - (3)].ident), (yysemantic_stack_[(6) - (5)].narray), yyloc); }
    break;

  case 106:

    { (yyval.inc_dec) = new ast::IncDec(ast::IncDec::POS_INC, (yysemantic_stack_[(2) - (1)].node), yyloc); }
    break;

  case 107:

    { (yyval.inc_dec) = new ast::IncDec(ast::IncDec::POS_DEC, (yysemantic_stack_[(2) - (1)].node), yyloc); }
    break;

  case 108:

    { (yyval.inc_dec) = new ast::IncDec(ast::IncDec::PRE_INC, (yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 109:

    { (yyval.inc_dec) = new ast::IncDec(ast::IncDec::PRE_DEC, (yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 110:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_EQUAL,   (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 111:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_NEQUAL,  (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 112:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_GREATER, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 113:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_GEQUAL,  (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 114:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_LESS,    (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 115:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_LEQUAL,  (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 116:

    { (yyval.boolean) = new ast::Boolean(ast::Boolean::BOP_OR, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);  }
    break;

  case 117:

    { (yyval.boolean) = new ast::Boolean(ast::Boolean::BOP_AND, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 118:

    { (yyval.logic) = new ast::Logic(ast::Logic::LOP_OR, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);      }
    break;

  case 119:

    { (yyval.logic) = new ast::Logic(ast::Logic::LOP_AND, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);     }
    break;

  case 120:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_ADD, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 121:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_SUB, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 122:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_MUL, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 123:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_DIV, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 124:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_MOD, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 125:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_AND, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);    }
    break;

  case 126:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_OR, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);     }
    break;

  case 127:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_XOR, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);    }
    break;

  case 128:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_LSHIFT, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 129:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_RSHIFT, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 130:

    { (yyval.narray) = (yysemantic_stack_[(2) - (2)].narray); }
    break;

  case 131:

    { (yyval.narray) = (yysemantic_stack_[(2) - (2)].narray); }
    break;

  case 132:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].vardecl)); }
    break;

  case 133:

    { (yysemantic_stack_[(3) - (1)].narray)->append((yysemantic_stack_[(3) - (3)].vardecl)); }
    break;

  case 134:

    { (yyval.vardecl) = new ast::VariableDecl((yysemantic_stack_[(3) - (1)].ident), new ast::Assignment((yysemantic_stack_[(3) - (1)].ident), (yysemantic_stack_[(3) - (3)].node), yyloc), false, yyloc); }
    break;

  case 135:

    { (yyval.vardecl) = new ast::VariableDecl((yysemantic_stack_[(1) - (1)].ident), new ast::Assignment((yysemantic_stack_[(1) - (1)].ident), NULL, yyloc), false, yyloc); }
    break;

  case 136:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].vardecl)); }
    break;

  case 137:

    { (yysemantic_stack_[(3) - (1)].narray)->append((yysemantic_stack_[(3) - (3)].vardecl)); }
    break;

  case 138:

    { (yyval.vardecl) = new ast::VariableDecl((yysemantic_stack_[(3) - (1)].ident), new ast::Assignment((yysemantic_stack_[(3) - (1)].ident), (yysemantic_stack_[(3) - (3)].node), yyloc), true, yyloc); }
    break;

  case 139:

    { (yyval.assignment) = new ast::Assignment((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 140:

    { (yyval.ident) = (yysemantic_stack_[(1) - (1)].ident); }
    break;

  case 141:

    { (yysemantic_stack_[(3) - (1)].ident)->append('.', (yysemantic_stack_[(3) - (3)].ident)); (yyval.ident) = (yysemantic_stack_[(3) - (1)].ident); }
    break;

  case 142:

    { (yyval.import) = new ast::Import((yysemantic_stack_[(4) - (2)].ident), yyloc);     }
    break;

  case 143:

    { (yyval.import) = new ast::Import((yysemantic_stack_[(4) - (2)].ident), (yysemantic_stack_[(4) - (4)].ident), yyloc); }
    break;

  case 144:

    { (yyval.import) = new ast::Import((yysemantic_stack_[(4) - (2)].ident), (yysemantic_stack_[(4) - (4)].type), yyloc); }
    break;

  case 145:

    { (yyval.vardecl) = new ast::VariableDecl((yysemantic_stack_[(4) - (1)].ident), new ast::Assignment((yysemantic_stack_[(4) - (1)].ident), NULL, yyloc), false, yyloc); }
    break;

  case 146:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(5) - (2)].ident), NULL, (yysemantic_stack_[(5) - (5)].block), NULL, yyloc); }
    break;

  case 147:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(6) - (2)].ident), NULL, (yysemantic_stack_[(6) - (6)].block), (yysemantic_stack_[(6) - (4)].vardecl), yyloc); }
    break;

  case 148:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(6) - (2)].ident), (yysemantic_stack_[(6) - (4)].narray), (yysemantic_stack_[(6) - (6)].block), NULL, yyloc); }
    break;

  case 149:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(8) - (2)].ident), (yysemantic_stack_[(8) - (4)].narray), (yysemantic_stack_[(8) - (8)].block), (yysemantic_stack_[(8) - (6)].vardecl), yyloc); }
    break;

  case 150:

    { (yyval.fdecl) = new ast::FunctionDecl(NULL, NULL, (yysemantic_stack_[(4) - (4)].block), NULL, yyloc); }
    break;

  case 151:

    { (yyval.fdecl) = new ast::FunctionDecl(NULL, NULL, (yysemantic_stack_[(5) - (5)].block), (yysemantic_stack_[(5) - (3)].vardecl), yyloc); }
    break;

  case 152:

    { (yyval.fdecl) = new ast::FunctionDecl(NULL, (yysemantic_stack_[(5) - (3)].narray), (yysemantic_stack_[(5) - (5)].block), NULL, yyloc); }
    break;

  case 153:

    { (yyval.fdecl) = new ast::FunctionDecl(NULL, (yysemantic_stack_[(7) - (3)].narray), (yysemantic_stack_[(7) - (7)].block), (yysemantic_stack_[(7) - (5)].vardecl), yyloc); }
    break;

  case 154:

    { (yyval.narray) = NULL; }
    break;

  case 156:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 157:

    { (yysemantic_stack_[(3) - (1)].narray)->append((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 158:

    { (yyval.fcall) = (yysemantic_stack_[(0) - (0)].fcall); }
    break;

  case 159:

    { (yyval.fcall) = new ast::FunctionCall((yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (3)].narray), yyloc); }
    break;

  case 160:

    { (yyval.fcall) = new ast::FunctionCall((yysemantic_stack_[(4) - (1)].ident), (yysemantic_stack_[(4) - (3)].narray), yyloc); }
    break;

  case 161:

    { (yyval.fcall) = (yysemantic_stack_[(6) - (6)].fcall); }
    break;

  case 162:

    { (yyval.ret) = new ast::Return((yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 163:

    { (yyval.ret) = new ast::Return(NULL, yyloc); }
    break;

  case 164:

    { (yyval.while_loop) = new ast::While((yysemantic_stack_[(5) - (3)].node), (yysemantic_stack_[(5) - (5)].block), yyloc); }
    break;

  case 166:

    { (yysemantic_stack_[(6) - (0)].ifcond)->addConditional((yysemantic_stack_[(6) - (4)].node), (yysemantic_stack_[(6) - (6)].block)); }
    break;

  case 167:

    { (yyval.ifcond) = (yysemantic_stack_[(0) - (0)].ifcond); }
    break;

  case 168:

    { (yysemantic_stack_[(2) - (0)].ifcond)->setElseNode((yysemantic_stack_[(2) - (2)].node)); (yyval.ifcond) = (yysemantic_stack_[(2) - (0)].ifcond); }
    break;

  case 169:

    { (yyval.ifcond) = new ast::If((yysemantic_stack_[(5) - (3)].node), (yysemantic_stack_[(5) - (5)].node), yyloc); }
    break;

  case 170:

    { (yyval.ifcond) = (yysemantic_stack_[(7) - (6)].ifcond); }
    break;

  case 171:

    { (yyval.ifcond) = (yysemantic_stack_[(9) - (9)].ifcond); }
    break;



	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Parser::yypact_ninf_ = -178;
  const short int
  Parser::yypact_[] =
  {
      -178,    41,  -178,  -178,   278,    40,   -55,    -7,  -178,  -178,
    -178,   -29,   -24,  -178,    69,    18,  -178,  -178,    21,    74,
      82,    24,   102,   102,  -178,    24,    18,  -178,  -178,    93,
      18,     9,    18,  -178,  -178,    23,    25,  -178,  -178,    98,
      44,  -178,  -178,  -178,    36,  -178,  -178,    61,    63,    65,
      72,    73,  -178,    75,    76,  -178,  -178,    55,    99,  -178,
      37,    18,    18,    18,  -178,    89,    92,    84,    86,     9,
    -178,    98,   497,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,   101,   108,  -178,    91,   -16,  -178,  -178,
    -178,  -178,  -178,   115,   497,   100,   497,    97,   126,   124,
     117,   221,    -3,   345,  -178,  -178,  -178,  -178,    39,    18,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,    18,    40,
     112,  -178,   114,   400,   421,    10,    38,     6,    18,    18,
      18,    18,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,    18,    18,    18,    18,    18,    18,    21,
       8,    18,  -178,   116,   144,   115,  -178,    13,  -178,    18,
      18,  -178,  -178,   186,  -178,  -178,   130,  -178,   497,   497,
    -178,    18,  -178,    24,    24,  -178,   125,  -178,   138,    -6,
      24,   -37,   139,   238,   238,   238,   238,   113,   113,    14,
      14,   576,   552,   587,   564,   642,   653,   181,   119,   119,
    -178,  -178,  -178,   497,  -178,    24,   -10,   141,   324,   210,
      24,  -178,  -178,   177,    30,    32,   497,   497,   161,    18,
     145,  -178,  -178,  -178,    18,   156,  -178,   218,    24,    24,
    -178,   218,    24,    24,    24,   157,  -178,   160,   177,  -178,
      32,  -178,  -178,   164,    18,   158,  -178,   162,  -178,   159,
     175,   165,  -178,  -178,   180,  -178,  -178,  -178,    24,  -178,
    -178,   166,   264,   265,  -178,   497,  -178,    18,   266,  -178,
    -178,    24,    24,  -178,  -178,   223,   222,  -178,   233,   235,
    -178,   219,   231,   283,  -178,  -178,   163,   264,   163,   265,
    -178,    18,    24,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,   476,  -178,    24,  -178
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         2,     0,     4,     1,     3,     0,     0,    32,    35,    36,
      34,     0,     0,    27,     0,   163,    38,    39,     0,     0,
       0,     0,     0,     0,    37,     0,     0,    28,    33,     0,
     154,     4,     0,     5,    16,     0,     0,    17,    18,     0,
       0,    23,    41,    40,     0,    22,    56,     0,     0,     0,
       0,     0,    11,     0,     0,    14,    13,   135,   130,   132,
       0,   154,     0,     0,   140,     0,     0,    32,     0,     0,
      52,    43,   162,    53,    54,    49,    48,    47,    45,    44,
      46,    51,    50,     0,   131,   136,     0,     0,     4,    31,
      32,   108,   109,     0,    92,     0,   156,     0,   155,     0,
       0,     0,     0,     0,    20,    21,   106,   107,     0,     0,
      19,    10,    15,     7,     8,     6,     9,    12,     0,     0,
     101,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,    97,    93,    94,    58,    87,     0,
       0,    90,    24,     0,    91,    42,   100,   102,   139,   134,
     133,   154,   160,     0,     0,   144,   141,   142,    25,   135,
       0,     0,     0,   115,   113,   114,   112,   129,   128,   110,
     111,   116,   118,   117,   119,   126,   127,   125,   121,   120,
     122,   123,   124,   138,   137,     0,     0,     0,     0,     0,
       0,    99,    95,    83,    59,     0,   157,    88,     0,   154,
       0,   158,   164,   169,   154,     0,   150,     0,     0,     0,
     146,     0,     0,     0,     0,     0,    98,     0,    84,    85,
       0,    64,    66,     0,     0,     0,   105,   161,   165,     0,
       0,     0,   152,   151,     0,   148,   147,    30,     0,    57,
      86,     0,     0,     0,    61,    89,   104,   154,   170,    26,
     145,     0,     0,    96,    63,    79,    65,    76,     0,    67,
      80,     0,     0,   167,   153,   149,     0,     0,     0,     0,
     159,     0,     0,   171,    68,    71,    72,    70,    74,    75,
      73,    69,    78,    77,    82,    81,     0,   168,     0,   166
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -178,  -178,  -178,   296,  -178,   -21,  -178,  -178,  -178,  -178,
    -178,    -2,   -14,  -178,  -178,  -178,  -178,  -178,  -178,    59,
    -178,  -178,    20,  -178,    22,  -178,    26,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,   155,  -178,  -178,     1,     2,
       4,  -178,  -178,  -178,  -178,  -178,  -178,   -88,   -92,  -178,
     178,  -178,  -178,  -178,  -143,  -177,  -178,   -58,  -178,  -178,
       5,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     1,     2,   101,    33,    34,    70,    35,    36,    37,
      38,    71,    96,    40,    41,   213,   214,   215,   240,   243,
     262,   263,   302,   276,   277,   279,   280,   237,   238,    42,
     102,    43,    44,   154,   155,   156,   211,    45,    73,    74,
      75,    76,    77,    78,    79,    80,    49,    58,    59,    84,
      85,    50,    65,    51,   182,    52,    81,    97,    98,   247,
      82,   221,    54,    55,   268,   293,    56,   248,   283
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int Parser::yytable_ninf_ = -144;
  const short int
  Parser::yytable_[] =
  {
        89,    72,    39,   122,    93,    46,    47,   207,    48,    53,
      60,   179,    94,   179,   175,   176,   -60,    99,   103,   227,
      91,    92,    66,    67,     8,     9,    10,   170,   128,   129,
     130,   131,   132,   -62,   133,   241,   239,  -144,  -144,   181,
     228,     3,   120,   120,   166,    57,   231,    62,   123,   124,
     -55,   118,    63,   163,   -60,   151,    88,    16,    17,   225,
      68,   260,   206,    22,    23,    24,   152,   232,   100,    61,
     164,   -62,    28,   242,    64,    83,   177,   143,   144,    86,
     145,   146,   147,   180,   251,   205,   178,    87,   254,    30,
      69,   121,   121,   167,    32,   168,    88,    95,   104,    39,
     105,   109,    46,    47,   169,    48,    53,    90,     8,     9,
      10,   110,   118,   220,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   170,   111,   208,   112,   170,
     113,    16,    17,   106,   107,   216,   217,   114,   115,    24,
     116,   117,   222,   223,   125,   119,    28,   126,   148,   226,
      61,   245,   127,   108,   149,   153,   249,   150,   294,   295,
     296,   297,   157,    30,    69,   158,   143,   144,    32,   145,
     146,   147,   159,   160,   230,   145,   146,   147,   171,   236,
     161,   172,   209,   210,   218,   128,   129,   130,   131,   132,
    -143,   133,   298,   299,   134,   135,   219,   252,   253,   281,
     300,   255,   256,   257,   224,   235,   229,   301,   233,    19,
     244,   250,   246,   179,     5,     6,     7,     8,     9,    10,
     265,    11,    12,   259,   258,   266,   269,   273,   267,   264,
     270,   274,   271,    13,   143,   144,    14,   145,   146,   147,
     284,   285,  -144,  -144,  -144,  -144,   132,   272,   133,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   275,
     278,   307,    25,    26,    27,    28,    29,   306,   287,   282,
     286,     5,     6,     7,     8,     9,    10,   309,    11,    12,
     288,   289,    30,    31,   162,   292,   290,    32,     4,   261,
      13,   143,   144,    14,   145,   146,   147,   291,   304,   303,
     212,     0,     0,     0,     0,   305,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,   204,     0,    25,
      26,    27,    28,    29,     0,     0,     0,     0,   128,   129,
     130,   131,   132,     0,   133,     0,     0,   134,   135,    30,
      31,     0,     0,     0,    32,   136,   137,   138,   139,   128,
     129,   130,   131,   132,     0,   133,     0,     0,   134,   135,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
       0,     0,     0,     0,   140,   141,   142,   143,   144,     0,
     145,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,   140,   141,   142,   143,   144,
       0,   145,   146,   147,   128,   129,   130,   131,   132,     0,
     133,     0,   165,   134,   135,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,   128,   129,   130,   131,   132,
       0,   133,     0,     0,   134,   135,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   139,     0,     0,     0,     0,
     140,   141,   142,   143,   144,     0,   145,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,   173,     0,     0,
       0,   140,   141,   142,   143,   144,     0,   145,   146,   147,
     128,   129,   130,   131,   132,     0,   133,     0,   174,   134,
     135,     0,     0,     0,     0,     0,     0,   136,   137,   138,
     139,   128,   129,   130,   131,   132,     0,   133,     0,     0,
     134,   135,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,     0,     0,     0,     0,   140,   141,   142,   143,
     144,     0,   145,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,     0,     0,   140,   141,   142,
     143,   144,     0,   145,   146,   147,   128,   129,   130,   131,
     132,     0,   133,     0,     0,   134,   135,     0,   128,   129,
     130,   131,   132,   136,   133,   138,   139,   134,   135,     0,
     128,   129,   130,   131,   132,   136,   133,   138,     0,   134,
     135,   128,   129,   130,   131,   132,     0,   133,     0,   138,
     134,   135,   140,   141,   142,   143,   144,     0,   145,   146,
     147,     0,     0,     0,   140,   141,   142,   143,   144,     0,
     145,   146,   147,     0,     0,     0,   140,   141,   142,   143,
     144,     0,   145,   146,   147,     0,     0,   140,   141,   142,
     143,   144,     0,   145,   146,   147,   128,   129,   130,   131,
     132,     0,   133,     0,     0,   134,   135,   128,   129,   130,
     131,   132,     0,   133,     0,     0,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,     0,   145,   146,
     147,     0,     0,     0,     0,   142,   143,   144,     0,   145,
     146,   147
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        21,    15,     4,    61,    25,     4,     4,   150,     4,     4,
      65,     5,    26,     5,     4,     5,     3,     8,    32,    56,
      22,    23,     4,     5,     6,     7,     8,   119,    14,    15,
      16,    17,    18,     3,    20,     3,   213,    23,    24,   127,
      77,     0,     5,     5,     5,     5,    56,    76,    62,    63,
      57,    57,    76,    56,    41,    71,    72,    39,    40,    65,
      42,   238,   150,    45,    46,    47,    87,    77,    59,    76,
      73,    41,    54,    41,     5,    54,    66,    63,    64,     5,
      66,    67,    68,    77,   227,    77,    48,     5,   231,    71,
      72,    54,    54,    54,    76,   109,    72,     4,    75,   101,
      75,    57,   101,   101,   118,   101,   101,     5,     6,     7,
       8,    75,    57,   171,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   227,    75,   151,    75,   231,
      75,    39,    40,    45,    46,   159,   160,    75,    75,    47,
      75,    75,   173,   174,    65,    56,    54,    65,    57,   180,
      76,   219,    76,    65,    56,    50,   224,    76,     5,     6,
       7,     8,    72,    71,    72,    78,    63,    64,    76,    66,
      67,    68,    56,    59,   205,    66,    67,    68,    76,   210,
      73,    77,    76,    49,     8,    14,    15,    16,    17,    18,
      75,    20,    39,    40,    23,    24,    76,   228,   229,   267,
      47,   232,   233,   234,    76,     5,    77,    54,    77,    42,
      59,    65,    77,     5,     3,     4,     5,     6,     7,     8,
     244,    10,    11,    73,    77,    77,    77,   258,    76,    75,
      65,    75,    77,    22,    63,    64,    25,    66,    67,    68,
     271,   272,    14,    15,    16,    17,    18,    77,    20,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     5,
       5,   292,    51,    52,    53,    54,    55,   291,    56,    13,
      57,     3,     4,     5,     6,     7,     8,   308,    10,    11,
      57,    56,    71,    72,    73,    12,    77,    76,     2,   240,
      22,    63,    64,    25,    66,    67,    68,    76,   288,   287,
     155,    -1,    -1,    -1,    -1,   289,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,   149,    -1,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    20,    -1,    -1,    23,    24,    71,
      72,    -1,    -1,    -1,    76,    31,    32,    33,    34,    14,
      15,    16,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    14,    15,    16,    17,    18,    -1,
      20,    -1,    77,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    14,    15,    16,    17,    18,
      -1,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      14,    15,    16,    17,    18,    -1,    20,    -1,    77,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    14,    15,    16,    17,
      18,    -1,    20,    -1,    -1,    23,    24,    -1,    14,    15,
      16,    17,    18,    31,    20,    33,    34,    23,    24,    -1,
      14,    15,    16,    17,    18,    31,    20,    33,    -1,    23,
      24,    14,    15,    16,    17,    18,    -1,    20,    -1,    33,
      23,    24,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    14,    15,    16,    17,
      18,    -1,    20,    -1,    -1,    23,    24,    14,    15,    16,
      17,    18,    -1,    20,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    66,
      67,    68
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    80,    81,     0,    82,     3,     4,     5,     6,     7,
       8,    10,    11,    22,    25,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    51,    52,    53,    54,    55,
      71,    72,    76,    83,    84,    86,    87,    88,    89,    90,
      92,    93,   108,   110,   111,   116,   117,   118,   119,   125,
     130,   132,   134,   139,   141,   142,   145,     5,   126,   127,
      65,    76,    76,    76,     5,   131,     4,     5,    42,    72,
      85,    90,    91,   117,   118,   119,   120,   121,   122,   123,
     124,   135,   139,    54,   128,   129,     5,     5,    72,    84,
       5,    90,    90,    84,    91,     4,    91,   136,   137,     8,
      59,    82,   109,    91,    75,    75,    45,    46,    65,    57,
      75,    75,    75,    75,    75,    75,    75,    75,    57,    56,
       5,    54,   136,    91,    91,    65,    65,    76,    14,    15,
      16,    17,    18,    20,    23,    24,    31,    32,    33,    34,
      60,    61,    62,    63,    64,    66,    67,    68,    57,    56,
      76,    71,    84,    50,   112,   113,   114,    72,    78,    56,
      59,    73,    73,    56,    73,    77,     5,    54,    91,    91,
     127,    76,    77,    77,    77,     4,     5,    66,    48,     5,
      77,   126,   133,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,   129,    77,   126,   133,    91,    76,
      49,   115,   114,    94,    95,    96,    91,    91,     8,    76,
     136,   140,    84,    84,    76,    65,    84,    56,    77,    77,
      84,    56,    77,    77,    78,     5,    84,   106,   107,   134,
      97,     3,    41,    98,    59,   136,    77,   138,   146,   136,
      65,   133,    84,    84,   133,    84,    84,    84,    77,    73,
     134,    98,    99,   100,    75,    91,    77,    76,   143,    77,
      65,    77,    77,    84,    75,     5,   102,   103,     5,   104,
     105,   136,    13,   147,    84,    84,    57,    56,    57,    56,
      77,    76,    12,   144,     5,     6,     7,     8,    39,    40,
      47,    54,   101,   103,   101,   105,    91,    84,    77,    84
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    44,    61,   311,    58,
     124,    94,    38,    45,    43,    46,    42,    47,    37,    33,
     126,    91,   123,   125,   312,    59,    40,    41,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    79,    81,    80,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    85,    85,    86,    87,    88,
      88,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    92,    92,    93,    94,    94,
      96,    95,    97,    95,    99,    98,   100,    98,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   106,   106,   107,   107,   108,   109,   109,
     110,   110,   111,   112,   113,   113,   114,   115,   115,   116,
     117,   117,   117,   117,   118,   118,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123,   123,   124,   124,   124,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   130,
     131,   131,   132,   132,   132,   133,   134,   134,   134,   134,
     135,   135,   135,   135,   136,   136,   137,   137,   138,   138,
     140,   139,   141,   141,   142,   143,   143,   144,   144,   146,
     147,   145
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     0,     2,     2,     2,     2,     2,
       2,     1,     2,     1,     1,     2,     1,     1,     1,     2,
       2,     2,     1,     1,     3,     3,     6,     1,     1,     3,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     0,     1,
       0,     3,     0,     4,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     3,     3,     0,     1,     1,     2,     3,     3,     5,
       3,     3,     2,     1,     1,     2,     5,     0,     2,     4,
       3,     3,     3,     3,     6,     6,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     3,     3,     1,     1,     3,     3,     3,
       1,     3,     4,     4,     4,     4,     5,     6,     6,     8,
       4,     5,     5,     7,     0,     1,     1,     3,     0,     4,
       0,     6,     2,     1,     5,     0,     6,     0,     2,     0,
       0,     9
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"var\"",
  "\"type specification\"", "\"identifier\"", "\"number\"",
  "\"float-number\"", "\"string\"", "\"for\"", "\"while\"", "\"if\"",
  "\"else\"", "\"else if\"", "\"<=\"", "\">=\"", "\"<\"", "\">\"",
  "\">>\"", "\">>=\"", "\"<<\"", "\"<<=\"", "\"break\"", "\"==\"",
  "\"!=\"", "\"import\"", "\"+=\"", "\"*=\"", "\"/=\"", "\"-=\"", "\"%=\"",
  "\"||\"", "\"or\"", "\"&&\"", "\"and\"", "\"&=\"", "\"|=\"", "\"^=\"",
  "\"return\"", "\"true\"", "\"false\"", "\"const\"", "\"function\"",
  "\"spawn\"", "\"critical\"", "\"++\"", "\"--\"", "\"null\"", "\"new\"",
  "\"finally\"", "\"catch\"", "\"try\"", "\"throw\"", "\"continue\"",
  "\"constant identifier\"", "\"class\"", "','", "'='", "XOR_EQUAL", "':'",
  "'|'", "'^'", "'&'", "'-'", "'+'", "'.'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "'['", "'{'", "'}'", "UMINUS", "';'", "'('", "')'", "']'",
  "$accept", "program", "$@1", "statement_list", "statement", "block",
  "instantiation", "break", "continue", "thread_block", "critical_block",
  "object", "rvalue", "lvalue", "class_def", "class_attr_decl",
  "class_attr_list", "@2", "@3", "non_empty_class_attr_list", "@4", "@5",
  "attr_rvalue", "class_attr_decl_list", "class_attr_decl_impl",
  "class_attr_const_decl_list", "class_attr_const_decl_impl",
  "class_method_decl", "class_method_list", "array", "key_value_list",
  "map", "throw", "catch", "not_empty_catch", "catch_impl", "finally",
  "try_catch_finally", "property_access", "mcall", "inc_dec", "comparison",
  "boolean", "logic", "arithmetic", "bitwise", "variable_decl",
  "variable_decl_list", "variable_decl_impl", "const_decl_list",
  "const_decl_impl", "assignment", "import_ident_list", "import", "vararg",
  "fdecl", "anonymous_fdecl", "call_args", "non_empty_call_args",
  "fcall_chain", "fcall", "@6", "return_stmt", "while", "elseif", "else",
  "if", "@7", "@8", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        80,     0,    -1,    -1,    81,    82,    -1,    -1,    82,    83,
      -1,   132,    75,    -1,   125,    75,    -1,   130,    75,    -1,
     139,    75,    -1,   118,    75,    -1,   134,    -1,   141,    75,
      -1,   145,    -1,   142,    -1,   119,    75,    -1,    84,    -1,
      88,    -1,    89,    -1,   111,    75,    -1,    86,    75,    -1,
      87,    75,    -1,   116,    -1,    93,    -1,    72,    82,    73,
      -1,     4,    65,    48,    -1,     4,    65,    48,    76,   136,
      77,    -1,    22,    -1,    53,    -1,    43,     5,    84,    -1,
      43,     5,    71,    91,    78,    84,    -1,    44,    84,    -1,
       5,    -1,    54,    -1,     8,    -1,     6,    -1,     7,    -1,
      47,    -1,    39,    -1,    40,    -1,   110,    -1,   108,    -1,
      76,    91,    77,    -1,    90,    -1,   123,    -1,   122,    -1,
     124,    -1,   121,    -1,   120,    -1,   119,    -1,   139,    -1,
     135,    -1,    85,    -1,   117,    -1,   118,    -1,     5,    -1,
     117,    -1,    55,     4,    72,    94,   106,    73,    -1,    -1,
      95,    -1,    -1,    96,    98,    75,    -1,    -1,    95,    97,
      98,    75,    -1,    -1,     3,    99,   102,    -1,    -1,    41,
     100,   104,    -1,     5,    -1,    54,    -1,     8,    -1,     6,
      -1,     7,    -1,    47,    -1,    39,    -1,    40,    -1,   103,
      -1,   102,    56,   103,    -1,     5,    57,   101,    -1,     5,
      -1,   105,    -1,   104,    56,   105,    -1,     5,    57,   101,
      -1,    -1,   107,    -1,   134,    -1,   107,   134,    -1,    71,
     136,    78,    -1,     8,    59,    91,    -1,   109,    56,     8,
      59,    91,    -1,    72,    59,    73,    -1,    72,   109,    73,
      -1,    52,    91,    -1,   113,    -1,   114,    -1,   113,   114,
      -1,    50,    76,     5,    77,    84,    -1,    -1,    49,    84,
      -1,    51,    84,   112,   115,    -1,    90,    65,     5,    -1,
       4,    65,     5,    -1,    90,    65,    54,    -1,     4,    65,
      54,    -1,    90,    65,     5,    76,   136,    77,    -1,     4,
      65,     5,    76,   136,    77,    -1,    90,    45,    -1,    90,
      46,    -1,    45,    90,    -1,    46,    90,    -1,    91,    23,
      91,    -1,    91,    24,    91,    -1,    91,    17,    91,    -1,
      91,    15,    91,    -1,    91,    16,    91,    -1,    91,    14,
      91,    -1,    91,    31,    91,    -1,    91,    33,    91,    -1,
      91,    32,    91,    -1,    91,    34,    91,    -1,    91,    64,
      91,    -1,    91,    63,    91,    -1,    91,    66,    91,    -1,
      91,    67,    91,    -1,    91,    68,    91,    -1,    91,    62,
      91,    -1,    91,    60,    91,    -1,    91,    61,    91,    -1,
      91,    20,    91,    -1,    91,    18,    91,    -1,     3,   126,
      -1,    41,   128,    -1,   127,    -1,   126,    56,   127,    -1,
       5,    57,    91,    -1,     5,    -1,   129,    -1,   128,    56,
     129,    -1,    54,    57,    91,    -1,    92,    57,    91,    -1,
       5,    -1,   131,    65,     5,    -1,    25,   131,    65,    66,
      -1,    25,   131,    65,     5,    -1,    25,   131,    65,     4,
      -1,     5,    65,    65,    65,    -1,    42,     5,    76,    77,
      84,    -1,    42,     5,    76,   133,    77,    84,    -1,    42,
       5,    76,   126,    77,    84,    -1,    42,     5,    76,   126,
      56,   133,    77,    84,    -1,    42,    76,    77,    84,    -1,
      42,    76,   133,    77,    84,    -1,    42,    76,   126,    77,
      84,    -1,    42,    76,   126,    56,   133,    77,    84,    -1,
      -1,   137,    -1,    91,    -1,   137,    56,    91,    -1,    -1,
     138,    76,   136,    77,    -1,    -1,     5,    76,   136,    77,
     140,   138,    -1,    38,    91,    -1,    38,    -1,    10,    76,
      91,    77,    84,    -1,    -1,   143,    13,    76,    91,    77,
      84,    -1,    -1,    12,    84,    -1,    -1,    -1,    11,    76,
      91,    77,    84,   146,   143,   147,   144,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     8,    11,    14,    17,    20,
      23,    26,    28,    31,    33,    35,    38,    40,    42,    44,
      47,    50,    53,    55,    57,    61,    65,    72,    74,    76,
      80,    87,    90,    92,    94,    96,    98,   100,   102,   104,
     106,   108,   110,   114,   116,   118,   120,   122,   124,   126,
     128,   130,   132,   134,   136,   138,   140,   142,   149,   150,
     152,   153,   157,   158,   163,   164,   168,   169,   173,   175,
     177,   179,   181,   183,   185,   187,   189,   191,   195,   199,
     201,   203,   207,   211,   212,   214,   216,   219,   223,   227,
     233,   237,   241,   244,   246,   248,   251,   257,   258,   261,
     266,   270,   274,   278,   282,   289,   296,   299,   302,   305,
     308,   312,   316,   320,   324,   328,   332,   336,   340,   344,
     348,   352,   356,   360,   364,   368,   372,   376,   380,   384,
     388,   391,   394,   396,   400,   404,   406,   408,   412,   416,
     420,   422,   426,   431,   436,   441,   446,   452,   459,   466,
     475,   480,   486,   492,   500,   501,   503,   505,   509,   510,
     515,   516,   523,   526,   528,   534,   535,   542,   543,   546,
     547,   548
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   211,   211,   211,   215,   216,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   241,   245,   246,   250,   254,   258,
     259,   263,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   296,   297,   301,   305,   306,
     310,   310,   311,   311,   315,   315,   316,   316,   320,   321,
     322,   323,   324,   325,   326,   327,   331,   332,   336,   337,
     341,   342,   346,   350,   351,   355,   356,   360,   364,   365,
     369,   370,   374,   378,   382,   383,   387,   391,   392,   396,
     400,   401,   402,   403,   407,   408,   412,   413,   414,   415,
     419,   420,   421,   422,   423,   424,   428,   429,   433,   434,
     438,   439,   440,   441,   442,   446,   447,   448,   449,   450,
     454,   455,   459,   460,   464,   465,   469,   470,   474,   478,
     482,   483,   487,   488,   489,   493,   497,   499,   501,   503,
     508,   510,   512,   514,   519,   520,   524,   525,   529,   530,
     534,   534,   538,   539,   543,   547,   549,   554,   555,   559,
     560,   559
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,     2,     2,    68,    62,     2,
      76,    77,    66,    64,    56,    63,    65,    67,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    75,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,     2,    78,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    60,    73,    70,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    58,    74
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 721;
  const int Parser::yynnts_ = 69;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 3;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 79;

  const unsigned int Parser::yyuser_token_number_max_ = 312;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // clever





namespace clever {

void Parser::error(const Parser::location_type& line, const std::string& msg)
{
	driver.error(line, msg);
}

} // clever

