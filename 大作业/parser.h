/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_USERS_SHERINGHAM_DESKTOP_AI4MATH_PROOFGRADER_BUILD_PARSER_PARSER_H_INCLUDED
# define YY_YY_USERS_SHERINGHAM_DESKTOP_AI4MATH_PROOFGRADER_BUILD_PARSER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 17 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"

    typedef void *yyscan_t;

#line 48 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    START_PROGRAM = 258,           /* START_PROGRAM  */
    START_TERM = 259,              /* START_TERM  */
    NUM = 260,                     /* NUM  */
    VAR = 261,                     /* VAR  */
    COMMA = 262,                   /* COMMA  */
    COLON = 263,                   /* COLON  */
    ELLIPSIS = 264,                /* ELLIPSIS  */
    UNDERSCORE = 265,              /* UNDERSCORE  */
    CARET = 266,                   /* CARET  */
    VERTICAL_BAR = 267,            /* VERTICAL_BAR  */
    QUESTION_MARK = 268,           /* QUESTION_MARK  */
    LPAREN = 269,                  /* LPAREN  */
    RPAREN = 270,                  /* RPAREN  */
    LBRACKET = 271,                /* LBRACKET  */
    RBRACKET = 272,                /* RBRACKET  */
    LBRACE = 273,                  /* LBRACE  */
    RBRACE = 274,                  /* RBRACE  */
    GOAL = 275,                    /* GOAL  */
    PROVE = 276,                   /* PROVE  */
    CONCLUDE = 277,                /* CONCLUDE  */
    FWD_NOHINT = 278,              /* FWD_NOHINT  */
    BWD_NOHINT = 279,              /* BWD_NOHINT  */
    POSE_NOHINT = 280,             /* POSE_NOHINT  */
    CONCL_NOHINT = 281,            /* CONCL_NOHINT  */
    USE = 282,                     /* USE  */
    INTROS = 283,                  /* INTROS  */
    FIX = 284,                     /* FIX  */
    EXISTSVAR = 285,               /* EXISTSVAR  */
    SUCH_THAT = 286,               /* SUCH_THAT  */
    SUPPOSE = 287,                 /* SUPPOSE  */
    SET = 288,                     /* SET  */
    SINCE = 289,                   /* SINCE  */
    IF = 290,                      /* IF  */
    THEN = 291,                    /* THEN  */
    SAME = 292,                    /* SAME  */
    TRANS = 293,                   /* TRANS  */
    BOTH = 294,                    /* BOTH  */
    SQUARE = 295,                  /* SQUARE  */
    FOR = 296,                     /* FOR  */
    EQU_ADD = 297,                 /* EQU_ADD  */
    REMEMBER = 298,                /* REMEMBER  */
    POSE_INDUCTION = 299,          /* POSE_INDUCTION  */
    CUSTOMIZE = 300,               /* CUSTOMIZE  */
    PLUS = 301,                    /* PLUS  */
    MINUS = 302,                   /* MINUS  */
    MULT = 303,                    /* MULT  */
    DIV = 304,                     /* DIV  */
    FRAC = 305,                    /* FRAC  */
    SQRT = 306,                    /* SQRT  */
    MAX = 307,                     /* MAX  */
    MIN = 308,                     /* MIN  */
    SUP = 309,                     /* SUP  */
    INF = 310,                     /* INF  */
    DERI = 311,                    /* DERI  */
    INTERSECTION = 312,            /* INTERSECTION  */
    UNION = 313,                   /* UNION  */
    COMPOSITION = 314,             /* COMPOSITION  */
    MOD = 315,                     /* MOD  */
    SUM = 316,                     /* SUM  */
    PROD = 317,                    /* PROD  */
    EMPTYSET = 318,                /* EMPTYSET  */
    LIM = 319,                     /* LIM  */
    INFTY = 320,                   /* INFTY  */
    POS_INFTY = 321,               /* POS_INFTY  */
    NEG_INFTY = 322,               /* NEG_INFTY  */
    FORALL = 323,                  /* FORALL  */
    EXISTS = 324,                  /* EXISTS  */
    NOT = 325,                     /* NOT  */
    CONJ = 326,                    /* CONJ  */
    DISJ = 327,                    /* DISJ  */
    ARROW = 328,                   /* ARROW  */
    EQUIV = 329,                   /* EQUIV  */
    EQ = 330,                      /* EQ  */
    LE = 331,                      /* LE  */
    GE = 332,                      /* GE  */
    NEQ = 333,                     /* NEQ  */
    LT = 334,                      /* LT  */
    GT = 335,                      /* GT  */
    BELONG = 336,                  /* BELONG  */
    SUBSET = 337,                  /* SUBSET  */
    SUBSETNEQ = 338,               /* SUBSETNEQ  */
    BAR = 339,                     /* BAR  */
    VEC = 340,                     /* VEC  */
    UNARYFUNC = 341,               /* UNARYFUNC  */
    BINARYFUNC = 342,              /* BINARYFUNC  */
    CARTESIANPROD = 343,           /* CARTESIANPROD  */
    UNARYPRED = 344,               /* UNARYPRED  */
    BINARYPRED = 345,              /* BINARYPRED  */
    PATTERN_VAR = 346,             /* PATTERN_VAR  */
    PATTERN_CONST = 347,           /* PATTERN_CONST  */
    PATTERN_UNARY_OPER = 348,      /* PATTERN_UNARY_OPER  */
    PATTERN_BINARY_OPER = 349,     /* PATTERN_BINARY_OPER  */
    PATTERN_UNARY_PRED = 350,      /* PATTERN_UNARY_PRED  */
    PATTERN_BINARY_PRED = 351,     /* PATTERN_BINARY_PRED  */
    PATTERN_TERMLIST = 352,        /* PATTERN_TERMLIST  */
    IF_THEN = 353,                 /* IF_THEN  */
    TERM_COMMA = 354,              /* TERM_COMMA  */
    OPER_HEAD = 355,               /* OPER_HEAD  */
    UMINUS = 356                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"

    struct program *r; 
    int n;
    struct int_list *nl;
    char *s;
    struct term *t;
    struct named_term *nt;
    struct term_list *tl;
    struct proof *p;
    enum oper_type oper;
    void *none;

#line 179 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (yyscan_t scanner, parser_mode *pm);

#endif /* !YY_YY_USERS_SHERINGHAM_DESKTOP_AI4MATH_PROOFGRADER_BUILD_PARSER_PARSER_H_INCLUDED  */
