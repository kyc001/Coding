/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1


/* "%code top" blocks.  */
#line 11 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "ast.h"

#line 60 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_START_PROGRAM = 3,              /* START_PROGRAM  */
  YYSYMBOL_START_TERM = 4,                 /* START_TERM  */
  YYSYMBOL_NUM = 5,                        /* NUM  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_COLON = 8,                      /* COLON  */
  YYSYMBOL_ELLIPSIS = 9,                   /* ELLIPSIS  */
  YYSYMBOL_UNDERSCORE = 10,                /* UNDERSCORE  */
  YYSYMBOL_CARET = 11,                     /* CARET  */
  YYSYMBOL_VERTICAL_BAR = 12,              /* VERTICAL_BAR  */
  YYSYMBOL_QUESTION_MARK = 13,             /* QUESTION_MARK  */
  YYSYMBOL_LPAREN = 14,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 15,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 16,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 17,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_GOAL = 20,                      /* GOAL  */
  YYSYMBOL_PROVE = 21,                     /* PROVE  */
  YYSYMBOL_CONCLUDE = 22,                  /* CONCLUDE  */
  YYSYMBOL_FWD_NOHINT = 23,                /* FWD_NOHINT  */
  YYSYMBOL_BWD_NOHINT = 24,                /* BWD_NOHINT  */
  YYSYMBOL_POSE_NOHINT = 25,               /* POSE_NOHINT  */
  YYSYMBOL_CONCL_NOHINT = 26,              /* CONCL_NOHINT  */
  YYSYMBOL_USE = 27,                       /* USE  */
  YYSYMBOL_INTROS = 28,                    /* INTROS  */
  YYSYMBOL_FIX = 29,                       /* FIX  */
  YYSYMBOL_EXISTSVAR = 30,                 /* EXISTSVAR  */
  YYSYMBOL_SUCH_THAT = 31,                 /* SUCH_THAT  */
  YYSYMBOL_SUPPOSE = 32,                   /* SUPPOSE  */
  YYSYMBOL_SET = 33,                       /* SET  */
  YYSYMBOL_SINCE = 34,                     /* SINCE  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_THEN = 36,                      /* THEN  */
  YYSYMBOL_SAME = 37,                      /* SAME  */
  YYSYMBOL_TRANS = 38,                     /* TRANS  */
  YYSYMBOL_BOTH = 39,                      /* BOTH  */
  YYSYMBOL_SQUARE = 40,                    /* SQUARE  */
  YYSYMBOL_FOR = 41,                       /* FOR  */
  YYSYMBOL_EQU_ADD = 42,                   /* EQU_ADD  */
  YYSYMBOL_REMEMBER = 43,                  /* REMEMBER  */
  YYSYMBOL_POSE_INDUCTION = 44,            /* POSE_INDUCTION  */
  YYSYMBOL_CUSTOMIZE = 45,                 /* CUSTOMIZE  */
  YYSYMBOL_PLUS = 46,                      /* PLUS  */
  YYSYMBOL_MINUS = 47,                     /* MINUS  */
  YYSYMBOL_MULT = 48,                      /* MULT  */
  YYSYMBOL_DIV = 49,                       /* DIV  */
  YYSYMBOL_FRAC = 50,                      /* FRAC  */
  YYSYMBOL_SQRT = 51,                      /* SQRT  */
  YYSYMBOL_MAX = 52,                       /* MAX  */
  YYSYMBOL_MIN = 53,                       /* MIN  */
  YYSYMBOL_SUP = 54,                       /* SUP  */
  YYSYMBOL_INF = 55,                       /* INF  */
  YYSYMBOL_DERI = 56,                      /* DERI  */
  YYSYMBOL_INTERSECTION = 57,              /* INTERSECTION  */
  YYSYMBOL_UNION = 58,                     /* UNION  */
  YYSYMBOL_COMPOSITION = 59,               /* COMPOSITION  */
  YYSYMBOL_MOD = 60,                       /* MOD  */
  YYSYMBOL_SUM = 61,                       /* SUM  */
  YYSYMBOL_PROD = 62,                      /* PROD  */
  YYSYMBOL_EMPTYSET = 63,                  /* EMPTYSET  */
  YYSYMBOL_LIM = 64,                       /* LIM  */
  YYSYMBOL_INFTY = 65,                     /* INFTY  */
  YYSYMBOL_POS_INFTY = 66,                 /* POS_INFTY  */
  YYSYMBOL_NEG_INFTY = 67,                 /* NEG_INFTY  */
  YYSYMBOL_FORALL = 68,                    /* FORALL  */
  YYSYMBOL_EXISTS = 69,                    /* EXISTS  */
  YYSYMBOL_NOT = 70,                       /* NOT  */
  YYSYMBOL_CONJ = 71,                      /* CONJ  */
  YYSYMBOL_DISJ = 72,                      /* DISJ  */
  YYSYMBOL_ARROW = 73,                     /* ARROW  */
  YYSYMBOL_EQUIV = 74,                     /* EQUIV  */
  YYSYMBOL_EQ = 75,                        /* EQ  */
  YYSYMBOL_LE = 76,                        /* LE  */
  YYSYMBOL_GE = 77,                        /* GE  */
  YYSYMBOL_NEQ = 78,                       /* NEQ  */
  YYSYMBOL_LT = 79,                        /* LT  */
  YYSYMBOL_GT = 80,                        /* GT  */
  YYSYMBOL_BELONG = 81,                    /* BELONG  */
  YYSYMBOL_SUBSET = 82,                    /* SUBSET  */
  YYSYMBOL_SUBSETNEQ = 83,                 /* SUBSETNEQ  */
  YYSYMBOL_BAR = 84,                       /* BAR  */
  YYSYMBOL_VEC = 85,                       /* VEC  */
  YYSYMBOL_UNARYFUNC = 86,                 /* UNARYFUNC  */
  YYSYMBOL_BINARYFUNC = 87,                /* BINARYFUNC  */
  YYSYMBOL_CARTESIANPROD = 88,             /* CARTESIANPROD  */
  YYSYMBOL_UNARYPRED = 89,                 /* UNARYPRED  */
  YYSYMBOL_BINARYPRED = 90,                /* BINARYPRED  */
  YYSYMBOL_PATTERN_VAR = 91,               /* PATTERN_VAR  */
  YYSYMBOL_PATTERN_CONST = 92,             /* PATTERN_CONST  */
  YYSYMBOL_PATTERN_UNARY_OPER = 93,        /* PATTERN_UNARY_OPER  */
  YYSYMBOL_PATTERN_BINARY_OPER = 94,       /* PATTERN_BINARY_OPER  */
  YYSYMBOL_PATTERN_UNARY_PRED = 95,        /* PATTERN_UNARY_PRED  */
  YYSYMBOL_PATTERN_BINARY_PRED = 96,       /* PATTERN_BINARY_PRED  */
  YYSYMBOL_PATTERN_TERMLIST = 97,          /* PATTERN_TERMLIST  */
  YYSYMBOL_IF_THEN = 98,                   /* IF_THEN  */
  YYSYMBOL_TERM_COMMA = 99,                /* TERM_COMMA  */
  YYSYMBOL_OPER_HEAD = 100,                /* OPER_HEAD  */
  YYSYMBOL_UMINUS = 101,                   /* UMINUS  */
  YYSYMBOL_YYACCEPT = 102,                 /* $accept  */
  YYSYMBOL_start = 103,                    /* start  */
  YYSYMBOL_program = 104,                  /* program  */
  YYSYMBOL_goal_statement = 105,           /* goal_statement  */
  YYSYMBOL_proof_statement = 106,          /* proof_statement  */
  YYSYMBOL_proof = 107,                    /* proof  */
  YYSYMBOL_partial_proof = 108,            /* partial_proof  */
  YYSYMBOL_forward_clause = 109,           /* forward_clause  */
  YYSYMBOL_backward_clause = 110,          /* backward_clause  */
  YYSYMBOL_pose_clause = 111,              /* pose_clause  */
  YYSYMBOL_pose_induction = 112,           /* pose_induction  */
  YYSYMBOL_conclude_clause = 113,          /* conclude_clause  */
  YYSYMBOL_method_clause = 114,            /* method_clause  */
  YYSYMBOL_action_clause = 115,            /* action_clause  */
  YYSYMBOL_since_clause = 116,             /* since_clause  */
  YYSYMBOL_memory_list = 117,              /* memory_list  */
  YYSYMBOL_memory_term = 118,              /* memory_term  */
  YYSYMBOL_knowledge = 119,                /* knowledge  */
  YYSYMBOL_memory = 120,                   /* memory  */
  YYSYMBOL_term = 121,                     /* term  */
  YYSYMBOL_lim_head = 122,                 /* lim_head  */
  YYSYMBOL_oper_head = 123,                /* oper_head  */
  YYSYMBOL_interval = 124,                 /* interval  */
  YYSYMBOL_infty = 125,                    /* infty  */
  YYSYMBOL_term_comma_list = 126,          /* term_comma_list  */
  YYSYMBOL_term_paren_list = 127           /* term_paren_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Unqualified %code blocks.  */
#line 21 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"

    int yylex(YYSTYPE *yylvalp, YYLTYPE *yyllocp, yyscan_t scanner);
    void yyerror(YYLTYPE *yyllocp, yyscan_t unused, parser_mode *pm, const char *msg);

#line 243 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3813

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   356

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   112,   123,   136,   143,   150,   157,   164,
     172,   180,   190,   196,   203,   210,   223,   230,   237,   245,
     252,   265,   279,   290,   304,   319,   336,   353,   363,   375,
     389,   401,   416,   428,   441,   457,   469,   483,   496,   509,
     522,   534,   547,   559,   571,   584,   599,   607,   617,   625,
     636,   643,   650,   658,   666,   674,   686,   702,   714,   730,
     738,   746,   754,   763,   768,   777,   789,   805,   817,   833,
     849,   865,   881,   897,   909,   925,   937,   953,   965,   981,
     993,  1009,  1021,  1036,  1048,  1063,  1075,  1087,  1099,  1108,
    1113,  1118,  1126,  1142,  1158,  1174,  1192,  1207,  1229,  1248,
    1260,  1272,  1288,  1304,  1312,  1327,  1342,  1351,  1367,  1383,
    1399,  1415,  1431,  1447,  1460,  1473,  1485,  1501,  1517,  1533,
    1549,  1568,  1584,  1603,  1619,  1638,  1654,  1675,  1696,  1712,
    1728,  1744,  1756,  1770,  1786,  1802,  1820,  1828,  1836,  1846,
    1857,  1874,  1882
};
#endif

#define YYPACT_NINF (-319)
#define YYTABLE_NINF (-130)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,   -15,   408,    17,    12,  -319,   -14,  -319,  -319,  -319,
    -319,   408,  -319,   408,   408,   408,    16,   408,    30,    35,
      37,    43,    46,    47,    24,    54,  -319,   112,  -319,  -319,
    -319,    16,    16,   408,     9,   116,   118,   122,   128,   136,
     140,  -319,  -319,   141,   142,   143,   144,  -319,  2192,   145,
     408,  -319,  -319,    65,  -319,   408,   156,  -319,   712,   766,
      -7,  2246,   658,   259,   408,   158,   342,   408,   408,   408,
     408,   408,   408,   133,   148,   149,   161,   162,  2732,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,  -319,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   474,   408,
     408,   408,  2192,    13,  -319,   408,  -319,  -319,   408,   408,
    -319,  -319,   820,   146,  2300,   874,   928,    48,   982,   105,
    1036,  1090,   408,   408,   170,   408,   408,  1167,  1244,  1298,
    2192,   130,   134,  1352,   137,  1406,   160,  1460,   169,  3733,
    -319,  2786,    -1,    15,  1514,   176,  1146,  1622,   423,   528,
     567,  1144,  1173,   565,  2840,  2894,  2948,  3002,  3218,  3246,
    3274,  3302,  3330,  3358,   114,  3386,  3412,  1568,  3417,  3443,
    3471,   172,  -319,   408,   408,   408,  -319,   135,   408,   408,
     173,   408,   408,   220,  -319,    97,   175,  -319,   171,   187,
     165,   180,   197,   315,     3,   188,   164,   211,  3571,  3497,
    1645,   278,    16,   408,   408,   408,  -319,  -319,  -319,  -319,
    -319,  -319,  -319,  1722,  1799,   155,  3056,  3110,  -319,  -319,
    -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,
    -319,  -319,   214,  -319,  1853,  2354,  -319,  -319,   223,  2408,
      65,  1907,   265,  -319,  2462,  2516,   501,  -319,   208,  2570,
    -319,   229,  -319,   203,    13,    13,    13,    13,   234,    13,
    -319,    13,  1237,   408,  -319,  -319,  -319,  -319,  -319,  -319,
    -319,  -319,  3164,  3625,  3679,   250,   255,   408,  -319,   211,
    -319,   408,   408,   214,  -319,   212,   408,  -319,  -319,   260,
     261,  -319,  -319,  -319,   272,   262,   274,   408,     7,   188,
    -319,  -319,  -319,   275,   276,  1984,  -319,  2624,  2678,  -319,
    -319,    13,    13,    13,  1237,    13,  1237,  1237,   408,   408,
    -319,  -319,  -319,  -319,  -319,   279,  -319,   282,  2061,  2138,
    1237,  1237,  -319,   594,  -319,  -319
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,    62,    61,   103,
      60,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,     0,     0,     0,     0,    59,     3,     0,
       0,    89,    90,     0,     1,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     5,     0,    73,     0,    63,   104,     0,     0,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     140,   102,    72,    71,     0,     0,    66,    68,    69,    70,
      93,    92,    94,   101,   116,   117,   118,   119,   107,   110,
     109,   108,   112,   111,   121,   123,   125,     0,   122,   124,
     126,     0,    11,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     6,     0,     0,
       0,     0,     0,     0,     0,    28,     0,    46,   139,   139,
       0,     0,   141,     0,     0,     0,    75,    81,    82,    83,
      84,    85,    86,     0,     0,     0,   113,   114,    99,   100,
      77,    78,   105,    79,    80,    55,    56,    57,    58,    64,
      65,    88,     0,    21,    48,     0,    24,    50,     0,    30,
      31,     0,     0,    32,    35,    36,     0,    37,    39,    38,
      42,     0,    43,     0,     0,     0,     0,     0,     0,     0,
      25,     0,    16,     0,    45,    47,   134,   133,   135,    97,
      98,   142,   120,   139,   139,   131,   132,     0,    51,     0,
      29,     0,     0,    62,    41,     0,     0,     7,     8,     0,
       0,    12,    13,    14,     0,     0,     0,     0,     0,     0,
      22,    74,    76,     0,     0,     0,    49,    33,    34,    44,
      26,     0,     0,     0,    16,     0,    16,    16,     0,     0,
     127,     9,    10,    15,    17,     0,    19,     0,     0,     0,
      16,    16,   128,   129,    18,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -319,  -319,  -319,  -319,  -319,   113,  -318,  -278,  -319,   -97,
    -319,  -319,   -74,    21,    91,    85,  -167,   123,  -202,    -2,
    -319,  -319,  -319,  -319,   120,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     5,     6,    57,   207,   314,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   280,   258,   217,   254,
      49,    50,    51,    52,    53,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,   268,    76,    77,   315,     4,    90,    56,   127,    58,
     281,    59,    61,    62,   336,    66,   344,    54,   346,   347,
      55,   282,    90,     1,     2,   337,   253,    79,   256,   191,
      64,    78,   354,   355,    73,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    67,   201,   202,   203,   118,    68,
     204,    69,   205,   122,   206,    99,   315,    70,   315,   315,
      71,    72,   132,   228,    74,   134,   135,   136,   138,   140,
     141,    99,   315,   315,   119,   120,   121,   147,   148,   149,
     150,   150,   153,   150,   155,   150,   157,   150,   159,   161,
     162,   163,   164,   166,   167,   168,   169,   326,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   320,   188,   189,   190,
     230,    90,    75,   218,    92,    93,   219,   220,    94,   119,
     120,   121,    81,    60,    80,    63,    82,   270,   271,   330,
     233,   234,    83,   236,   237,   241,   119,   120,   121,   242,
      84,   142,   244,   272,    85,    86,    87,    88,    89,   117,
      95,    96,    97,    98,   123,   133,   143,   144,   145,   146,
      99,   100,   101,   102,   103,   246,   235,   252,   274,   263,
     257,   273,   223,   276,   248,   316,   119,   120,   121,   137,
     139,   250,   255,   291,   275,  -130,   259,   261,   277,   264,
     265,   269,   151,   152,   278,   154,   284,   156,   317,   158,
     160,   119,   120,   121,   165,   119,   120,   121,   119,   120,
     121,   292,   293,   294,   283,     7,     8,   191,   297,     9,
      10,   298,    11,    12,    13,   305,   266,   316,    15,   316,
     316,   119,   120,   121,   300,   160,   304,   306,   160,   221,
     119,   120,   121,   316,   316,    16,   311,   119,   120,   121,
     317,   323,   317,   317,    61,   257,   324,    17,   329,   334,
      18,    19,    20,    21,    22,    23,   317,   317,   131,   331,
     332,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,   333,   335,   338,   339,   325,   302,   290,   350,   327,
     328,   351,   285,   318,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,   260,   262,
       7,     8,   279,     0,     9,    10,   267,    11,    12,    13,
       0,    14,     0,    15,     0,     0,   348,   349,     0,     0,
     119,   120,   121,     0,   160,   160,   119,   120,   121,    90,
      16,     0,    92,    93,     0,   318,    94,   318,   318,   119,
     120,   121,    17,     0,     0,    18,    19,    20,    21,    22,
      23,   318,   318,   319,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,   307,   308,   309,
     310,     0,   312,     0,   313,     0,     0,     0,    99,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     7,     8,     0,     0,     9,    10,     0,
      11,    12,    13,     0,    14,   319,    15,   319,   319,     0,
      90,     0,     0,    92,    93,     0,     0,    94,     0,     0,
       0,   319,   319,    16,   341,   342,   343,     0,   345,     0,
       0,     0,     0,     0,     0,    17,     0,     0,    18,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    99,
       0,    90,     0,     0,    92,    93,     0,     0,    94,     0,
       0,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,   303,     8,     0,     0,
       9,    10,     0,    11,    12,    13,     0,    14,     0,    15,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,    90,    16,     0,    92,    93,
       0,     0,    94,     0,     0,     0,     0,     0,    17,     0,
       0,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    90,     0,    90,    92,    93,    92,    93,    94,
       0,    94,     0,     0,    99,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,  -129,
    -129,     0,     0,  -129,  -129,     0,  -129,  -129,  -129,     0,
    -129,     0,  -129,    95,    96,    97,    98,     0,     0,     0,
       0,    99,     0,    99,     0,     0,   102,   103,     0,  -129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -129,     0,     0,  -129,  -129,  -129,  -129,  -129,  -129,
       0,     0,     0,     0,     0,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,    90,    91,     0,    92,    93,
     129,     0,    94,     0,     0,     0,     0,   130,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,    90,
      91,     0,    92,    93,   124,     0,    94,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   125,    91,     0,    92,    93,     0,     0,
      94,   126,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,    90,    91,     0,
      92,    93,     0,     0,    94,   222,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   225,    91,     0,    92,    93,     0,     0,    94,   226,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,    90,    91,     0,    92,    93,
       0,     0,    94,   227,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,    90,
      91,     0,    92,    93,     0,     0,    94,   229,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,    90,    91,     0,    92,    93,     0,     0,
      94,   231,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,    90,    91,     0,
      92,    93,     0,     0,    94,   232,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,    90,     0,    90,    92,    93,    92,    93,    94,     0,
      94,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    90,    91,     0,    92,    93,     0,
      90,    94,     0,    92,    93,     0,   238,    94,     0,     0,
      95,    96,    97,    98,    97,    98,     0,     0,     0,     0,
      99,     0,    99,   102,   103,     0,   103,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,    99,
       0,     0,  -130,   103,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    90,    91,   191,    92,    93,     0,     0,    94,     0,
     193,     0,   195,   239,   197,   198,   199,   200,     0,   201,
     202,   203,     0,     0,   204,     0,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,    90,    91,     0,    92,    93,
       0,     0,    94,   240,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,    90,
      91,     0,    92,    93,     0,     0,    94,   243,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,    90,    91,     0,    92,    93,     0,     0,
      94,   245,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,    90,    91,     0,
      92,    93,     0,     0,    94,   247,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,    90,    91,     0,    92,    93,     0,     0,    94,   249,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,    90,    91,     0,    92,    93,
       0,     0,    94,   251,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,    90,
       0,     0,    92,    93,     0,     0,    94,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    90,    91,     0,    92,    93,     0,     0,    94,
       0,     0,     0,     0,   289,     0,     0,     0,     0,     0,
      97,    98,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    90,
      91,     0,    92,    93,     0,     0,    94,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    90,    91,     0,    92,
      93,     0,     0,    94,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
      90,    91,     0,    92,    93,     0,     0,    94,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,    90,    91,     0,    92,    93,     0,
       0,    94,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    90,    91,     0,    92,    93,     0,     0,    94,     0,
       0,     0,     0,   340,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    90,    91,
       0,    92,    93,     0,     0,    94,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    90,    91,     0,    92,    93,
       0,     0,    94,     0,     0,     0,     0,   353,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,    90,
      91,     0,    92,    93,     0,     0,    94,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   128,    91,     0,    92,    93,     0,     0,
      94,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   224,    91,     0,
      92,    93,     0,     0,    94,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,    90,    91,     0,    92,    93,     0,     0,    94,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,    90,    91,     0,    92,    93,
       0,     0,    94,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,    90,
      91,     0,    92,    93,     0,     0,    94,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,    90,    91,     0,    92,    93,     0,     0,
      94,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,    90,    91,     0,
      92,    93,     0,     0,    94,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,    90,    91,     0,    92,    93,     0,     0,    94,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,    90,    91,     0,    92,    93,
       0,     0,    94,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,    90,
       0,     0,    92,    93,     0,     0,    94,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,    90,     0,     0,    92,    93,     0,     0,
      94,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,    90,     0,     0,
      92,    93,     0,     0,    94,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,    90,     0,     0,    92,    93,     0,     0,    94,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,    90,     0,     0,    92,    93,
       0,     0,    94,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,    90,
       0,     0,    92,    93,     0,     0,    94,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,    90,     0,     0,    92,    93,     0,     0,
      94,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,    90,     0,     0,
      92,    93,     0,     0,    94,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,    90,     0,     0,    92,    93,     0,     0,    94,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,    90,     0,     0,    92,    93,
       0,     0,    94,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,    90,     0,     0,    92,    93,     0,     0,
      94,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,    90,     0,     0,    92,    93,     0,     0,    94,     0,
       0,     0,    95,    96,    97,    98,     0,     0,     0,   114,
     115,   116,    99,   100,   101,   102,   103,     0,     0,    90,
       0,     0,    92,    93,     0,     0,    94,     0,     0,     0,
      95,    96,    97,    98,     0,     0,     0,   114,   115,   116,
      99,   100,   101,   102,   103,     0,     0,    90,     0,     0,
      92,    93,     0,     0,    94,     0,     0,     0,    95,    96,
      97,    98,     0,     0,     0,   114,   115,   116,    99,   100,
     101,   102,   103,     0,     0,    90,     0,     0,    92,    93,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
       0,     0,     0,   114,   115,   116,    99,   100,   101,   102,
     103,     0,     0,    90,     0,     0,    92,    93,     0,     0,
      94,     0,     0,     0,    95,    96,    97,    98,     0,     0,
       0,   114,   115,   116,    99,   100,   101,   102,   103,    90,
       0,     0,    92,    93,    90,     0,    94,    92,    93,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,   114,
     115,   116,    99,   100,   101,   102,   103,     0,     0,     0,
      90,     0,     0,    92,    93,     0,     0,    94,    95,    96,
      97,    98,     0,    95,    96,    97,    98,   114,    99,   100,
     101,   102,   103,    99,   100,   101,   102,   103,    90,     0,
       0,    92,    93,     0,     0,    94,     0,     0,     0,    95,
      96,    97,    98,   114,     0,     0,     0,     0,  -130,    99,
     100,   101,   102,   103,    90,    91,     0,    92,    93,     0,
       0,    94,   287,     0,   288,     0,     0,    95,    96,    97,
      98,     0,     0,     0,   114,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,     0,     0,     0,
       0,     0,   114,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    90,    91,
       0,    92,    93,     0,     0,    94,     0,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,    90,    91,     0,    92,    93,     0,     0,    94,
     321,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,    90,    91,     0,    92,
      93,     0,     0,    94,   322,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
      90,    91,     0,    92,    93,     0,     0,    94,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113
};

static const yytype_int16 yycheck[] =
{
       2,   203,    31,    32,   282,    20,     7,    21,    15,    11,
       7,    13,    14,    15,     7,    17,   334,     0,   336,   337,
       8,    18,     7,     3,     4,    18,   193,    18,   195,    16,
      14,    33,   350,   351,    10,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    14,    32,    33,    34,    50,    14,
      37,    14,    39,    55,    41,    56,   334,    14,   336,   337,
      14,    14,    64,    15,    10,    67,    68,    69,    70,    71,
      72,    56,   350,   351,    81,    82,    83,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   299,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   283,   119,   120,   121,
      15,     7,    10,   125,    10,    11,   128,   129,    14,    81,
      82,    83,    14,    13,    18,    15,    14,    40,    41,   306,
     142,   143,    14,   145,   146,    15,    81,    82,    83,    15,
      14,    18,    15,    56,    14,    14,    14,    14,    14,    14,
      46,    47,    48,    49,     8,     7,    18,    18,     7,     7,
      56,    57,    58,    59,    60,    15,     6,     5,     7,     6,
      45,     6,    36,    18,    15,   282,    81,    82,    83,    69,
      70,    15,   194,   222,     7,    81,   198,   199,    18,   201,
     202,   203,    82,    83,     7,    85,    42,    87,   282,    89,
      90,    81,    82,    83,    94,    81,    82,    83,    81,    82,
      83,   223,   224,   225,    36,     5,     6,    16,    73,     9,
      10,    17,    12,    13,    14,     6,    16,   334,    18,   336,
     337,    81,    82,    83,    21,   125,    38,    44,   128,   129,
      81,    82,    83,   350,   351,    35,    22,    81,    82,    83,
     334,    11,   336,   337,   266,    45,    11,    47,    56,     7,
      50,    51,    52,    53,    54,    55,   350,   351,    19,    19,
      19,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    19,    18,    18,    18,   297,    31,    19,    19,   301,
     302,    19,   217,   282,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   198,   199,
       5,     6,     7,    -1,     9,    10,   203,    12,    13,    14,
      -1,    16,    -1,    18,    -1,    -1,   338,   339,    -1,    -1,
      81,    82,    83,    -1,   224,   225,    81,    82,    83,     7,
      35,    -1,    10,    11,    -1,   334,    14,   336,   337,    81,
      82,    83,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,   350,   351,   282,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    -1,   274,   275,   276,
     277,    -1,   279,    -1,   281,    -1,    -1,    -1,    56,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     5,     6,    -1,    -1,     9,    10,    -1,
      12,    13,    14,    -1,    16,   334,    18,   336,   337,    -1,
       7,    -1,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,
      -1,   350,   351,    35,   331,   332,   333,    -1,   335,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    56,
      -1,     7,    -1,    -1,    10,    11,    -1,    -1,    14,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     5,     6,    -1,    -1,
       9,    10,    -1,    12,    13,    14,    -1,    16,    -1,    18,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,     7,    35,    -1,    10,    11,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     7,    -1,     7,    10,    11,    10,    11,    14,
      -1,    14,    -1,    -1,    56,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     5,
       6,    -1,    -1,     9,    10,    -1,    12,    13,    14,    -1,
      16,    -1,    18,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    56,    -1,    56,    -1,    -1,    59,    60,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     7,     8,    -1,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    19,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,     7,
       8,    -1,    10,    11,    12,    -1,    14,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,     7,     8,    -1,    10,    11,    -1,    -1,
      14,    15,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,     7,     8,    -1,
      10,    11,    -1,    -1,    14,    15,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,     7,     8,    -1,    10,    11,    -1,    -1,    14,    15,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,     7,     8,    -1,    10,    11,
      -1,    -1,    14,    15,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,     7,
       8,    -1,    10,    11,    -1,    -1,    14,    15,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,     7,     8,    -1,    10,    11,    -1,    -1,
      14,    15,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,     7,     8,    -1,
      10,    11,    -1,    -1,    14,    15,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,     7,    -1,     7,    10,    11,    10,    11,    14,    -1,
      14,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     7,     8,    -1,    10,    11,    -1,
       7,    14,    -1,    10,    11,    -1,    19,    14,    -1,    -1,
      46,    47,    48,    49,    48,    49,    -1,    -1,    -1,    -1,
      56,    -1,    56,    59,    60,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    46,
      47,    48,    49,    56,    57,    58,    59,    60,    -1,    56,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     7,     8,    16,    10,    11,    -1,    -1,    14,    -1,
      23,    -1,    25,    19,    27,    28,    29,    30,    -1,    32,
      33,    34,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,     7,     8,    -1,    10,    11,
      -1,    -1,    14,    15,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,     7,
       8,    -1,    10,    11,    -1,    -1,    14,    15,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,     7,     8,    -1,    10,    11,    -1,    -1,
      14,    15,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,     7,     8,    -1,
      10,    11,    -1,    -1,    14,    15,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,     7,     8,    -1,    10,    11,    -1,    -1,    14,    15,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,     7,     8,    -1,    10,    11,
      -1,    -1,    14,    15,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,     7,
      -1,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     7,     8,    -1,    10,    11,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     7,
       8,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     7,     8,    -1,    10,
      11,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
       7,     8,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    60,     7,     8,    -1,    10,    11,    -1,
      -1,    14,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     7,     8,    -1,    10,    11,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     7,     8,
      -1,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     7,     8,    -1,    10,    11,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,     7,
       8,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,     7,     8,    -1,    10,    11,    -1,    -1,
      14,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,     7,     8,    -1,
      10,    11,    -1,    -1,    14,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,     7,     8,    -1,    10,    11,    -1,    -1,    14,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,     7,     8,    -1,    10,    11,
      -1,    -1,    14,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,     7,
       8,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,     7,     8,    -1,    10,    11,    -1,    -1,
      14,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,     7,     8,    -1,
      10,    11,    -1,    -1,    14,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,     7,     8,    -1,    10,    11,    -1,    -1,    14,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,     7,     8,    -1,    10,    11,
      -1,    -1,    14,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,     7,
      -1,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,     7,    -1,    -1,    10,    11,    -1,    -1,
      14,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,     7,    -1,    -1,
      10,    11,    -1,    -1,    14,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,     7,    -1,    -1,    10,    11,    -1,    -1,    14,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,     7,    -1,    -1,    10,    11,
      -1,    -1,    14,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,     7,
      -1,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,     7,    -1,    -1,    10,    11,    -1,    -1,
      14,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,     7,    -1,    -1,
      10,    11,    -1,    -1,    14,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,     7,    -1,    -1,    10,    11,    -1,    -1,    14,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,     7,    -1,    -1,    10,    11,
      -1,    -1,    14,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,    -1,
      14,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    -1,    14,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    81,
      82,    83,    56,    57,    58,    59,    60,    -1,    -1,     7,
      -1,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    81,    82,    83,
      56,    57,    58,    59,    60,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    -1,    14,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    81,    82,    83,    56,    57,
      58,    59,    60,    -1,    -1,     7,    -1,    -1,    10,    11,
      -1,    -1,    14,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    81,    82,    83,    56,    57,    58,    59,
      60,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,    -1,
      14,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      -1,    81,    82,    83,    56,    57,    58,    59,    60,     7,
      -1,    -1,    10,    11,     7,    -1,    14,    10,    11,    -1,
      -1,    14,    46,    47,    48,    49,    -1,    -1,    -1,    81,
      82,    83,    56,    57,    58,    59,    60,    -1,    -1,    -1,
       7,    -1,    -1,    10,    11,    -1,    -1,    14,    46,    47,
      48,    49,    -1,    46,    47,    48,    49,    81,    56,    57,
      58,    59,    60,    56,    57,    58,    59,    60,     7,    -1,
      -1,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,    46,
      47,    48,    49,    81,    -1,    -1,    -1,    -1,    81,    56,
      57,    58,    59,    60,     7,     8,    -1,    10,    11,    -1,
      -1,    14,    15,    -1,    17,    -1,    -1,    46,    47,    48,
      49,    -1,    -1,    -1,    81,    -1,    -1,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    81,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     7,     8,
      -1,    10,    11,    -1,    -1,    14,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,     7,     8,    -1,    10,    11,    -1,    -1,    14,
      15,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,     7,     8,    -1,    10,
      11,    -1,    -1,    14,    15,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
       7,     8,    -1,    10,    11,    -1,    -1,    14,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,   103,    20,   104,   105,     5,     6,     9,
      10,    12,    13,    14,    16,    18,    35,    47,    50,    51,
      52,    53,    54,    55,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   121,   122,
     123,   124,   125,   126,     0,     8,    21,   106,   121,   121,
     126,   121,   121,   126,    14,   127,   121,    14,    14,    14,
      14,    14,    14,    10,    10,    10,   127,   127,   121,    18,
      18,    14,    14,    14,    14,    14,    14,    14,    14,    14,
       7,     8,    10,    11,    14,    46,    47,    48,    49,    56,
      57,    58,    59,    60,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    14,   121,    81,
      82,    83,   121,     8,    12,     7,    15,    15,     7,    12,
      19,    19,   121,     7,   121,   121,   121,   126,   121,   126,
     121,   121,    18,    18,    18,     7,     7,   121,   121,   121,
     121,   126,   126,   121,   126,   121,   126,   121,   126,   121,
     126,   121,   121,   121,   121,   126,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,    16,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    32,    33,    34,    37,    39,    41,   107,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   120,   121,   121,
     121,   126,    15,    36,     7,     7,    15,    15,    15,    15,
      15,    15,    15,   121,   121,     6,   121,   121,    19,    19,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,     5,   118,   121,   121,   118,    45,   119,   121,
     126,   121,   126,     6,   121,   121,    16,   119,   120,   121,
      40,    41,    56,     6,     7,     7,    18,    18,     7,     7,
     118,     7,    18,    36,    42,   117,    17,    15,    17,    19,
      19,   127,   121,   121,   121,    19,    19,    73,    17,    43,
      21,    31,    31,     5,    38,     6,    44,   107,   107,   107,
     107,    22,   107,   107,   108,   109,   111,   114,   115,   116,
     118,    15,    15,    11,    11,   121,   120,   121,   121,    56,
     118,    19,    19,    19,     7,    18,     7,    18,    18,    18,
      19,   107,   107,   107,   108,   107,   108,   108,   121,   121,
      19,    19,    19,    19,   108,   108
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,   102,   103,   103,   104,   105,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   109,   109,   110,   111,   111,   112,   113,   113,   114,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   117,   117,   118,   118,
     119,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   122,   123,   123,
     123,   123,   123,   124,   124,   124,   125,   125,   125,   126,
     126,   127,   127
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     3,     3,     3,     3,     5,
       5,     1,     3,     3,     3,     5,     0,     3,     5,     3,
       5,     2,     3,     2,     2,     2,     4,     1,     1,     3,
       2,     2,     2,     4,     4,     2,     2,     2,     2,     2,
       1,     3,     2,     2,     4,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     4,     4,     4,     4,     1,
       1,     1,     1,     3,     4,     4,     3,     2,     3,     3,
       3,     3,     3,     3,     6,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     4,     1,
       1,     1,     3,     3,     3,     3,     3,     5,     5,     4,
       4,     3,     3,     1,     3,     4,     2,     3,     3,     3,
       3,     3,     3,     4,     4,     2,     3,     3,     3,     3,
       5,     3,     3,     3,     3,     3,     3,     7,     9,     9,
       9,     5,     5,     5,     5,     5,     1,     1,     1,     3,
       3,     3,     4
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_uint8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      87,     0,     0,    89,    91,     0,    93,    95,    97,     0,
      99,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,   107,   109,   111,   113,   115,   117,
       0,     0,     0,     0,     0,   119,   121,   123,   125,   127,
     129,   131,   133,   135,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   141,
     143,   145,   147,   149,   151,   153,   155,   157,   159,   161,
     163,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    67,     0,   115,     0,   106,     0,   139,     0,   102,
       0,    72,     0,    71,     0,    66,     0,    68,     0,    69,
       0,    70,     0,    93,     0,    92,     0,    94,     0,   101,
       0,   116,     0,   117,     0,   118,     0,   119,     0,   107,
       0,   110,     0,   109,     0,   108,     0,   112,     0,   111,
       0,   121,     0,   123,     0,   125,     0,   122,     0,   124,
       0,   126,     0,   113,     0,   114,     0,    48,     0,    23,
       0,    30,     0,    35,     0,    36,     0,    38,     0,   120,
       0,    33,     0,    34,     0,   130,     0,   130,     0,   130,
       0,   130,     0,   130,     0,   130,     0,   130,     0,   130,
       0,   130,     0,   130,     0,   130,     0,   130,     0,   130,
       0,   130,     0,   130,     0,   130,     0,   130,     0,   130,
       0,   130,     0,   130,     0,   130,     0,   130,     0,   130,
       0,   130,     0,   130,     0,   130,     0,   130,     0,   130,
       0,   130,     0,   130,     0,   130,     0,   130,     0,   130,
       0,   130,     0,   130,     0,   130,     0,   130,     0,   130,
       0,   130,     0,   130,     0,   130,     0
};


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, yyscan_t scanner, parser_mode *pm, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, scanner, pm, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "START_PROGRAM", "START_TERM",
  "NUM", "VAR", "COMMA", "COLON", "ELLIPSIS", "UNDERSCORE", "CARET",
  "VERTICAL_BAR", "QUESTION_MARK", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "GOAL", "PROVE", "CONCLUDE",
  "FWD_NOHINT", "BWD_NOHINT", "POSE_NOHINT", "CONCL_NOHINT", "USE",
  "INTROS", "FIX", "EXISTSVAR", "SUCH_THAT", "SUPPOSE", "SET", "SINCE",
  "IF", "THEN", "SAME", "TRANS", "BOTH", "SQUARE", "FOR", "EQU_ADD",
  "REMEMBER", "POSE_INDUCTION", "CUSTOMIZE", "PLUS", "MINUS", "MULT",
  "DIV", "FRAC", "SQRT", "MAX", "MIN", "SUP", "INF", "DERI",
  "INTERSECTION", "UNION", "COMPOSITION", "MOD", "SUM", "PROD", "EMPTYSET",
  "LIM", "INFTY", "POS_INFTY", "NEG_INFTY", "FORALL", "EXISTS", "NOT",
  "CONJ", "DISJ", "ARROW", "EQUIV", "EQ", "LE", "GE", "NEQ", "LT", "GT",
  "BELONG", "SUBSET", "SUBSETNEQ", "BAR", "VEC", "UNARYFUNC", "BINARYFUNC",
  "CARTESIANPROD", "UNARYPRED", "BINARYPRED", "PATTERN_VAR",
  "PATTERN_CONST", "PATTERN_UNARY_OPER", "PATTERN_BINARY_OPER",
  "PATTERN_UNARY_PRED", "PATTERN_BINARY_PRED", "PATTERN_TERMLIST",
  "IF_THEN", "TERM_COMMA", "OPER_HEAD", "UMINUS", "$accept", "start",
  "program", "goal_statement", "proof_statement", "proof", "partial_proof",
  "forward_clause", "backward_clause", "pose_clause", "pose_induction",
  "conclude_clause", "method_clause", "action_clause", "since_clause",
  "memory_list", "memory_term", "knowledge", "memory", "term", "lim_head",
  "oper_head", "interval", "infty", "term_comma_list", "term_paren_list", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, parser_mode *pm)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (pm);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, parser_mode *pm)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner, pm);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value, Location, scanner, pm);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, yyscan_t scanner, parser_mode *pm);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp, yyGLRStack* yystackp, yyscan_t scanner, parser_mode *pm)
{
  yysymbol_kind_t yytoken;
  YY_USE (scanner);
  YY_USE (pm);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex (&yylval, &yylloc, scanner);
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, yyscan_t scanner, parser_mode *pm)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yylocp);
  YY_USE (scanner);
  YY_USE (pm);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, scanner, pm, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule, scanner, pm));
  switch (yyrule)
    {
  case 2: /* start: START_PROGRAM program  */
#line 104 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "start: START_PROGRAM program\n");
        if (*(pm->pr) != NULL) {
            if (pm->debug) fprintf(stderr, "Something very wrong happends.\n");
            free(*(pm->pr));
        }
        *(pm->pr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.r);
    }
#line 2594 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 3: /* start: START_TERM term  */
#line 113 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "start: START_TERM term\n");
        if (*(pm->tm) != NULL) {
            if (pm->debug) fprintf(stderr, "Something very wrong happends.\n");
            free(*(pm->tm));
        }
        *(pm->tm) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
    }
#line 2607 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 4: /* program: goal_statement proof_statement  */
#line 124 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "program: goal_statement proof_statement\n");
        program *tmp1 = (program *) calloc(1, sizeof(program));
        proof_goal *tmp2 = (proof_goal *) calloc(1, sizeof(proof_goal));
        tmp2->assus = NULL;
        tmp2->concl = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        tmp1->pg = tmp2;
        tmp1->pr = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).r) = tmp1;
    }
#line 2622 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 5: /* goal_statement: GOAL COLON term  */
#line 137 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "goal_statement: GOAL COLON term\n");
        ((*yyvalp).t) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
    }
#line 2631 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 6: /* proof_statement: PROVE COLON proof  */
#line 144 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof_statement: PROVE COLON proof\n");
        ((*yyvalp).p) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
    }
#line 2640 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 7: /* proof: forward_clause COMMA proof  */
#line 151 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: forward_clause COMMA proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.PoseWithoutProof.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2651 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 8: /* proof: backward_clause COMMA proof  */
#line 158 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: backward_clause COMMA proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.ClaimSuffice.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2662 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 9: /* proof: pose_clause LBRACE proof RBRACE proof  */
#line 165 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: pose_clause LBRACE proof RBRACE proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.p);
        tmp->content.PoseAndProve.curr_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.PoseAndProve.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2674 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 10: /* proof: pose_induction LBRACE proof RBRACE proof  */
#line 173 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: pose_clause LBRACE proof RBRACE proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.p);
        tmp->content.PoseInduction.curr_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.PoseInduction.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2686 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 11: /* proof: CONCLUDE  */
#line 181 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: CONCLUDE\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = ConclWithoutProof;
        tmp1->content.ConclWithoutProof.fwd = tmp2;
        ((*yyvalp).p) = tmp1;
    }
#line 2700 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 12: /* proof: conclude_clause COMMA CONCLUDE  */
#line 191 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: conclude_clause COMMA CONCLUDE\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2710 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 13: /* proof: method_clause COMMA proof  */
#line 197 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: method_clause COMMA proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.ConclAndProve.curr_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2721 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 14: /* proof: action_clause COMMA proof  */
#line 204 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: action_clause COMMA proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.Action.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2732 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 15: /* proof: action_clause LBRACE partial_proof RBRACE proof  */
#line 211 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "proof: action_clause LBRACE partial_proof RBRACE proof\n");
        proof *tmp = (proof *) calloc(1, sizeof(proof));
        tmp->type = PosePartialProof;
        tmp->content.PosePartialProof.act = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.p)->content.Action.act;
        tmp->content.PosePartialProof.curr_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.PosePartialProof.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        free((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.p));
        ((*yyvalp).p) = tmp;
    }
#line 2747 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 16: /* partial_proof: %empty  */
#line 224 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "partial_proof: %%empty\n");
        proof *tmp = (proof *) calloc(1, sizeof(proof));
        tmp->type = EndPartialProof;
        ((*yyvalp).p) = tmp;
    }
#line 2758 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 17: /* partial_proof: forward_clause COMMA partial_proof  */
#line 231 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "partial_proof: forward_clause COMMA partial_proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.PoseWithoutProof.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2769 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 18: /* partial_proof: pose_clause LBRACE proof RBRACE partial_proof  */
#line 238 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "partial_proof: pose_clause LBRACE proof RBRACE partial_proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.p);
        tmp->content.PoseAndProve.curr_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.PoseAndProve.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2781 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 19: /* partial_proof: action_clause COMMA partial_proof  */
#line 246 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "partial_proof: action_clause COMMA partial_proof\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.Action.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        ((*yyvalp).p) = tmp;
    }
#line 2792 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 20: /* partial_proof: action_clause LBRACE partial_proof RBRACE partial_proof  */
#line 253 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "partial_proof: action_clause LBRACE partial_proof RBRACE partial_proof\n");
        proof *tmp = (proof *) calloc(1, sizeof(proof));
        tmp->type = PosePartialProof;
        tmp->content.PosePartialProof.act = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.p)->content.Action.act;
        tmp->content.PosePartialProof.curr_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.PosePartialProof.next_proof = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        free((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.p));
        ((*yyvalp).p) = tmp;
    }
#line 2807 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 21: /* forward_clause: FWD_NOHINT memory_term  */
#line 266 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "forward_clause: FWD_NOHINT memory_term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->t;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        tmp1->remember = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->name;
        free((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt));
        ((*yyvalp).p) = tmp1;
    }
#line 2825 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 22: /* forward_clause: since_clause THEN memory_term  */
#line 280 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "forward_clause: since_clause THEN memory_term\n");
        proof *tmp = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.p);
        tmp->content.PoseWithoutProof.curr_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->t;
        tmp->remember = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->name;
        free((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt));
        ((*yyvalp).p) = tmp;
    }
#line 2838 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 23: /* backward_clause: BWD_NOHINT term  */
#line 291 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "backward_clause: BWD_NOHINT term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        backward *tmp2 = (backward *) calloc(1, sizeof(backward));
        tmp2->type = BNoHint;
        tmp1->type = ClaimSuffice;
        tmp1->content.ClaimSuffice.bwd = tmp2;
        tmp1->content.ClaimSuffice.curr_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        tmp1->content.ClaimSuffice.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 2854 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 24: /* pose_clause: POSE_NOHINT memory_term  */
#line 305 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "pose_clause: POSE_NOHINT memory_term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = PoseAndProve;
        tmp1->content.PoseAndProve.fwd = tmp2;
        tmp1->content.PoseAndProve.curr_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->t;
        tmp1->content.PoseAndProve.curr_proof = NULL;
        tmp1->content.PoseAndProve.next_proof = NULL;
        tmp1->remember = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->name;
        free((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt));
        ((*yyvalp).p) = tmp1;
    }
#line 2873 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 25: /* pose_clause: method_clause memory_term  */
#line 320 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "pose_clause: method_clause memory_term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        proof *tmp2 = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.p);
        tmp1->type = PoseAndProve;
        tmp1->content.PoseAndProve.fwd = tmp2->content.ConclAndProve.fwd;
        tmp1->content.PoseAndProve.curr_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->t;
        tmp1->content.PoseAndProve.curr_proof = NULL;
        tmp1->content.PoseAndProve.next_proof = NULL;
        tmp1->remember = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->name;
        free((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt));
        free(tmp2);
        ((*yyvalp).p) = tmp1;
    }
#line 2892 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 26: /* pose_induction: FOR VAR POSE_INDUCTION memory_term  */
#line 337 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "pose_induction: FOR VAR POSE_INDUCTION memory_term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = PoseInduction;
        tmp1->content.PoseInduction.fwd = tmp2;
        tmp1->content.PoseInduction.induct_var = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.s);
        tmp1->content.PoseInduction.curr_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->t;
        tmp1->content.PoseInduction.curr_proof = NULL;
        tmp1->content.PoseInduction.next_proof = NULL;
        tmp1->remember = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nt)->name;
        ((*yyvalp).p) = tmp1;
    }
#line 2911 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 27: /* conclude_clause: CONCL_NOHINT  */
#line 354 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "conclude_clause: CONCL_NOHINT\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = ConclWithoutProof;
        tmp1->content.ConclWithoutProof.fwd = tmp2;
        ((*yyvalp).p) = tmp1;
    }
#line 2925 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 28: /* conclude_clause: since_clause  */
#line 364 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "conclude_clause: since_clause\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        proof *tmp2 = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p);
        tmp1->type = ConclWithoutProof;
        tmp1->content.ConclWithoutProof.fwd = tmp2->content.PoseWithoutProof.fwd;
        free(tmp2);
        ((*yyvalp).p) = tmp1;
    }
#line 2939 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 29: /* method_clause: USE knowledge PROVE  */
#line 376 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "method_clause: USE knowledge PROVE\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Knowledge;
        tmp2->content.knowledge = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.s);
        tmp1->type = ConclAndProve;
        tmp1->content.ConclAndProve.fwd = tmp2;
        tmp1->content.ConclAndProve.curr_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 2955 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 30: /* action_clause: INTROS term  */
#line 390 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "action_clause: INTROS term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = IntroTerm;
        tmp2->content.intro_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 2971 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 31: /* action_clause: INTROS term_comma_list  */
#line 402 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "action_clause: INTROS term_comma_list\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tl);
        tmp2->type = IntroTerm;
        tmp2->content.intro_term = tmp3;
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 2990 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 32: /* action_clause: EXISTSVAR VAR  */
#line 417 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "action_clause: EXISTSVAR VAR\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = ExistsVar;
        tmp2->content.exists_var = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.s);
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3006 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 33: /* action_clause: FIX term SUCH_THAT term  */
#line 429 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "action_clause: FIX term SUCH_THAT term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = IntroTermWithProp;
        tmp2->content.intro_term_with_prop[0] = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp2->content.intro_term_with_prop[1] = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3023 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 34: /* action_clause: FIX term_comma_list SUCH_THAT term  */
#line 442 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "action_clause: FIX term_comma_list SUCH_THAT term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tl);
        tmp2->type = IntroTermWithProp;
        tmp2->content.intro_term_with_prop[0] = tmp3;
        tmp2->content.intro_term_with_prop[1] = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3043 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 35: /* action_clause: SUPPOSE term  */
#line 458 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "action_clause: SUPPOSE term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = Suppose;
        tmp2->content.suppose_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3059 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 36: /* action_clause: SET term  */
#line 470 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "action_clause: SET term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = Set;
        tmp2->content.set_term = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3075 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 37: /* since_clause: SINCE knowledge  */
#line 484 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: SINCE knowledge\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Knowledge;
        tmp2->content.knowledge = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.s);
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3092 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 38: /* since_clause: SINCE term  */
#line 497 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: SINCE term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Inference;
        tmp2->content.evidence = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3109 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 39: /* since_clause: SINCE memory  */
#line 510 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: SINCE memory\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Inference;
        tmp2->content.equ = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n);
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3126 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 40: /* since_clause: SAME  */
#line 523 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: SAME\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Same;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3142 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 41: /* since_clause: SINCE memory TRANS  */
#line 535 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: SINCE memory TRANS\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = EquTrans;
        tmp2->content.equ = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n);
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3159 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 42: /* since_clause: BOTH SQUARE  */
#line 548 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: BOTH SQUARE\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = SquareBothTerms;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3175 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 43: /* since_clause: BOTH DERI  */
#line 560 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: BOTH DERI\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = DeriBothTerms;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3191 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 44: /* since_clause: BOTH FOR VAR DERI  */
#line 572 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: BOTH FOR VAR DERI\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = DeriBothTerms;
        tmp2->content.var = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.s);
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3208 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 45: /* since_clause: memory_list EQU_ADD  */
#line 585 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "since_clause: memory_list EQU_ADD\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = AddEqn;
        tmp2->content.equ_list = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.nl);
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        ((*yyvalp).p) = tmp1;
    }
#line 3225 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 46: /* memory_list: memory  */
#line 600 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "memory_list: memory\n");
        int_list *tmp = (int_list *) calloc(1, sizeof(int_list));
        tmp->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n);
        tmp->next = NULL;
        ((*yyvalp).nl) = tmp;
    }
#line 3237 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 47: /* memory_list: memory memory_list  */
#line 608 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "memory_list: memory memory_list\n");
        int_list *tmp = (int_list *) calloc(1, sizeof(int_list));
        tmp->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n);
        tmp->next = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nl);
        ((*yyvalp).nl) = tmp;
    }
#line 3249 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 48: /* memory_term: term  */
#line 618 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "memory_term: term\n");
        named_term *tmp = (named_term *) calloc(1, sizeof(named_term));
        tmp->name = NULL;
        tmp->t = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).nt) = tmp;
    }
#line 3261 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 49: /* memory_term: term REMEMBER memory  */
#line 626 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "memory_term: term REMEMBER memory\n");
        named_term *tmp = (named_term *) calloc(1, sizeof(named_term));
        tmp->name = (int *) calloc(1, sizeof(int));
        *(tmp->name) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n);
        tmp->t = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        ((*yyvalp).nt) = tmp;
    }
#line 3274 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 50: /* knowledge: CUSTOMIZE  */
#line 637 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "knowledge: CUSTOMIZE\n");
        ((*yyvalp).s) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.s);
    }
#line 3283 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 51: /* memory: LBRACKET NUM RBRACKET  */
#line 644 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "memory: LBRACKET NUM RBRACKET\n");
        ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n);
    }
#line 3292 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 52: /* term: QUESTION_MARK  */
#line 651 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: QUESTION_MARK\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternWildCard;
        ((*yyvalp).t) = tmp;
    }
#line 3304 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 53: /* term: PATTERN_VAR  */
#line 659 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_VAR\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternVar;
        ((*yyvalp).t) = tmp;
    }
#line 3316 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 54: /* term: PATTERN_CONST  */
#line 667 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_CONST\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternConst;
        ((*yyvalp).t) = tmp;
    }
#line 3328 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 55: /* term: PATTERN_UNARY_OPER LPAREN term RPAREN  */
#line 675 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_UNARY_OPER LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Pattern;
        tmp2->content.Pattern = PatternOper;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3344 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 56: /* term: PATTERN_BINARY_OPER LPAREN term_comma_list RPAREN  */
#line 687 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_BINARY_OPER LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pattern;
        tmp3->content.Pattern = PatternOper;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl))->element;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl))->next->element;
        ((*yyvalp).t) = tmp1;
    }
#line 3364 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 57: /* term: PATTERN_UNARY_PRED LPAREN term RPAREN  */
#line 703 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_UNARY_PRED LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Pattern;
        tmp2->content.Pattern = PatternPred;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3380 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 58: /* term: PATTERN_BINARY_PRED LPAREN term_comma_list RPAREN  */
#line 715 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_BINARY_PRED LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pattern;
        tmp3->content.Pattern = PatternPred;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl))->element;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl))->next->element;
        ((*yyvalp).t) = tmp1;
    }
#line 3400 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 59: /* term: PATTERN_TERMLIST  */
#line 731 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_TERMLIST\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternTermList;
        ((*yyvalp).t) = tmp;
    }
#line 3412 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 60: /* term: UNDERSCORE  */
#line 739 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: UNDERSCORE\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternIgnore;
        ((*yyvalp).t) = tmp;
    }
#line 3424 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 61: /* term: VAR  */
#line 747 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: VAR(\"%s\")\n", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.s));
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Var;
        tmp->content.Var = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.s);
        ((*yyvalp).t) = tmp;
    }
#line 3436 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 62: /* term: NUM  */
#line 755 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: NUM\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Num;
        tmp->content.Const.content = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n);
        ((*yyvalp).t) = tmp;
    }
#line 3449 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 63: /* term: LPAREN term RPAREN  */
#line 764 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LPAREN term RPAREN\n");
        ((*yyvalp).t) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
    }
#line 3458 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 64: /* term: term LPAREN term RPAREN  */
#line 769 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term LPAREN term RPAREN\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Apply;
        tmp->content.Apply.left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp;
    }
#line 3471 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 65: /* term: term LPAREN term_comma_list RPAREN  */
#line 778 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = TermList;
        tmp2->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl);
        tmp1->type = Apply;
        tmp1->content.Apply.left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp1->content.Apply.right = tmp2;
        ((*yyvalp).t) = tmp1;
    }
#line 3487 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 66: /* term: term PLUS term  */
#line 790 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term PLUS term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Plus;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3507 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 67: /* term: MINUS term  */
#line 806 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: MINUS term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Neg;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3523 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 68: /* term: term MINUS term  */
#line 818 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term MINUS term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Minus;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3543 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 69: /* term: term MULT term  */
#line 834 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term MULT term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Mult;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3563 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 70: /* term: term DIV term  */
#line 850 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term DIV term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Div;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3583 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 71: /* term: term CARET term  */
#line 866 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term CARET term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Power;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3603 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 72: /* term: term UNDERSCORE term  */
#line 882 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term UNDERSCORE term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Index;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3623 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 73: /* term: VERTICAL_BAR term VERTICAL_BAR  */
#line 898 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: VERTICAL_BAR term VERTICAL_BAR\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Abs;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3639 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 74: /* term: FRAC LPAREN term COMMA term RPAREN  */
#line 910 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: FRAC LPAREN term COMMA term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Div;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3659 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 75: /* term: SQRT LPAREN term RPAREN  */
#line 926 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: SQRT LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Sqrt;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3675 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 76: /* term: SQRT LPAREN term COMMA term RPAREN  */
#line 938 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: SQRT LPAREN term COMMA term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Sqrt_n;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3695 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 77: /* term: UNARYFUNC LPAREN term RPAREN  */
#line 954 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: UNARYFUNC LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.oper);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3711 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 78: /* term: BINARYFUNC LPAREN term_comma_list RPAREN  */
#line 966 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: BINARYFUNC LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.oper);
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl))->element;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl))->next->element;
        ((*yyvalp).t) = tmp1;
    }
#line 3731 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 79: /* term: UNARYPRED LPAREN term RPAREN  */
#line 982 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: UNARYPRED LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Pred;
        tmp2->content.Pred = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.oper);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3747 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 80: /* term: BINARYPRED LPAREN term_comma_list RPAREN  */
#line 994 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: BINARYPRED LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.oper);
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl))->element;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl))->next->element;
        ((*yyvalp).t) = tmp1;
    }
#line 3767 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 81: /* term: MAX LPAREN term RPAREN  */
#line 1010 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: MAX LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Max;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3783 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 82: /* term: MAX LPAREN term_comma_list RPAREN  */
#line 1022 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: MAX LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl);
        tmp2->type = Oper;
        tmp2->content.Oper = Max;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        ((*yyvalp).t) = tmp1;
    }
#line 3802 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 83: /* term: MIN LPAREN term RPAREN  */
#line 1037 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: MIN LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Min;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3818 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 84: /* term: MIN LPAREN term_comma_list RPAREN  */
#line 1049 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: MIN LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl);
        tmp2->type = Oper;
        tmp2->content.Oper = Min;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        ((*yyvalp).t) = tmp1;
    }
#line 3837 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 85: /* term: SUP LPAREN term RPAREN  */
#line 1064 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: SUP LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Sup;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3853 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 86: /* term: INF LPAREN term RPAREN  */
#line 1076 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: INF LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Inf;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3869 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 87: /* term: term DERI  */
#line 1088 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term DERI\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Deri;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3885 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 88: /* term: lim_head LPAREN term RPAREN  */
#line 1100 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: lim_head LPAREN term RPAREN\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Apply;
        tmp->content.Apply.left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp;
    }
#line 3898 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 89: /* term: interval  */
#line 1109 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: interval\n");
        ((*yyvalp).t) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
    }
#line 3907 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 90: /* term: infty  */
#line 1114 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: infty\n");
        ((*yyvalp).t) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
    }
#line 3916 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 91: /* term: EMPTYSET  */
#line 1119 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: EMPTYSET\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = EmptySet;
        ((*yyvalp).t) = tmp;
    }
#line 3928 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 92: /* term: term UNION term  */
#line 1127 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term UNION term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = SetUnion;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3948 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 93: /* term: term INTERSECTION term  */
#line 1143 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term INTERSECTION term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = SetIntersection;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3968 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 94: /* term: term COMPOSITION term  */
#line 1159 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term COMPOSITION term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Composition;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 3988 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 95: /* term: LBRACE term RBRACE  */
#line 1175 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term_list *tmp4 = (term_list *) calloc(1, sizeof(term_list));
        tmp4->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        tmp4->next = NULL;
        tmp3->type = TermList;
        tmp3->content.TermList = tmp4;
        tmp2->type = Oper;
        tmp2->content.Oper = Set_enum;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        ((*yyvalp).t) = tmp1;
    }
#line 4010 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 96: /* term: LBRACE term_comma_list RBRACE  */
#line 1193 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LBRACE term_comma_list RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl);
        tmp2->type = Oper;
        tmp2->content.Oper = Set_enum;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        ((*yyvalp).t) = tmp1;
    }
#line 4029 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 97: /* term: LBRACE term VERTICAL_BAR term RBRACE  */
#line 1208 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LBRACE term VERTICAL_BAR term RBRACE\n");
        term *tmp0 = (term *) calloc(1, sizeof(term));
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term_list *tmp4 = (term_list *) calloc(1, sizeof(term_list));
        tmp4->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        tmp4->next = NULL;
        tmp3->type = TermList;
        tmp3->content.TermList = tmp4;
        tmp2->type = Oper;
        tmp2->content.Oper = Set_build;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp0->type = Apply;
        tmp0->content.Apply.left = tmp1;
        tmp0->content.Apply.right = tmp3;
        ((*yyvalp).t) = tmp0;
    }
#line 4055 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 98: /* term: LBRACE term VERTICAL_BAR term_comma_list RBRACE  */
#line 1230 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LBRACE term VERTICAL_BAR term_comma_list RBRACE\n");
        term *tmp0 = (term *) calloc(1, sizeof(term));
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl);
        tmp2->type = Oper;
        tmp2->content.Oper = Set_build;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp0->type = Apply;
        tmp0->content.Apply.left = tmp1;
        tmp0->content.Apply.right = tmp3;
        ((*yyvalp).t) = tmp0;
    }
#line 4078 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 99: /* term: BAR LBRACE term RBRACE  */
#line 1249 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: BAR LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Bar;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4094 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 100: /* term: VEC LBRACE term RBRACE  */
#line 1261 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: VEC LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Vec;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4110 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 101: /* term: term MOD term  */
#line 1273 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term MOD term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Mod;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4130 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 102: /* term: term COLON term  */
#line 1289 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term COLON term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Colon;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4150 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 103: /* term: ELLIPSIS  */
#line 1305 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: ELLIPSIS\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Ellipsis;
        ((*yyvalp).t) = tmp;
    }
#line 4162 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 104: /* term: LPAREN term_comma_list RPAREN  */
#line 1313 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl);
        tmp2->type = Oper;
        tmp2->content.Oper = Tuple;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        ((*yyvalp).t) = tmp1;
    }
#line 4181 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 105: /* term: CARTESIANPROD LPAREN term_comma_list RPAREN  */
#line 1328 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: CARTESIANPROD LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tl);
        tmp2->type = Oper;
        tmp2->content.Oper = CartesianProd;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        ((*yyvalp).t) = tmp1;
    }
#line 4200 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 106: /* term: oper_head term  */
#line 1343 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: oper_head term\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Apply;
        tmp->content.Apply.left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        tmp->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp;
    }
#line 4213 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 107: /* term: term EQ term  */
#line 1352 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term EQ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Eq;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4233 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 108: /* term: term NEQ term  */
#line 1368 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term NEQ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Neq;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4253 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 109: /* term: term GE term  */
#line 1384 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term GE term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Ge;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4273 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 110: /* term: term LE term  */
#line 1400 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term LE term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Le;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4293 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 111: /* term: term GT term  */
#line 1416 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term GT term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Gt;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4313 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 112: /* term: term LT term  */
#line 1432 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term LT term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Lt;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4333 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 113: /* term: FORALL term_paren_list COMMA term  */
#line 1448 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: FORALL term_paren_list COMMA term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = TermList;
        tmp2->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tl);
        tmp1->type = RawQuant;
        tmp1->content.RawQuant.type = Forall;
        tmp1->content.RawQuant.raw_var = tmp2;
        tmp1->content.RawQuant.body = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4350 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 114: /* term: EXISTS term_paren_list COMMA term  */
#line 1461 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: EXISTS term_paren_list COMMA term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = TermList;
        tmp2->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tl);
        tmp1->type = RawQuant;
        tmp1->content.RawQuant.type = Exists;
        tmp1->content.RawQuant.raw_var = tmp2;
        tmp1->content.RawQuant.body = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4367 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 115: /* term: NOT term  */
#line 1474 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: NOT term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Connect;
        tmp2->content.Connect = Not;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4383 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 116: /* term: term CONJ term  */
#line 1486 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term CONJ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Connect;
        tmp3->content.Connect = And;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4403 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 117: /* term: term DISJ term  */
#line 1502 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term DISJ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Connect;
        tmp3->content.Connect = Or;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4423 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 118: /* term: term ARROW term  */
#line 1518 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term ARROW term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Connect;
        tmp3->content.Connect = Impl;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4443 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 119: /* term: term EQUIV term  */
#line 1534 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term EQUIV term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Connect;
        tmp3->content.Connect = Iff;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4463 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 120: /* term: IF term_paren_list COMMA THEN term  */
#line 1550 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: IF term_paren_list COMMA THEN term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = TermList;
        tmp4->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.tl);
        tmp3->type = Connect;
        tmp3->content.Connect = Impl;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = tmp4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4486 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 121: /* term: term BELONG term  */
#line 1569 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term BELONG term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Belong;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4506 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 122: /* term: term_comma_list BELONG term  */
#line 1585 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term_comma_list BELONG term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = TermList;
        tmp4->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tl);
        tmp3->type = Pred;
        tmp3->content.Pred = Belong;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = tmp4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4529 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 123: /* term: term SUBSET term  */
#line 1604 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term SUBSET term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Subset;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4549 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 124: /* term: term_comma_list SUBSET term  */
#line 1620 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term_comma_list SUBSET term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = TermList;
        tmp4->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tl);
        tmp3->type = Pred;
        tmp3->content.Pred = Subset;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = tmp4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4572 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 125: /* term: term SUBSETNEQ term  */
#line 1639 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term SUBSETNEQ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = SubsetNeq;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4592 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 126: /* term: term_comma_list SUBSETNEQ term  */
#line 1655 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: term_comma_list SUBSETNEQ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = TermList;
        tmp4->content.TermList = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tl);
        tmp3->type = Pred;
        tmp3->content.Pred = SubsetNeq;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = tmp4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4615 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 127: /* lim_head: LIM UNDERSCORE LBRACE VAR ARROW term RBRACE  */
#line 1676 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
   {
        if (pm->debug) fprintf(stderr, "lim_head: LIM UNDERSCORE LBRACE VAR ARROW term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = Oper;
        tmp4->content.Oper = Lim;
        tmp3->type = Var;
        tmp3->content.Var = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.s);
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp4;
        tmp2->content.Apply.right = tmp3;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
   }
#line 4638 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 128: /* oper_head: SUM UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE  */
#line 1697 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "oper_head: SUM UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = BigSum_limits;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4658 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 129: /* oper_head: PROD UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE  */
#line 1713 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "oper_head: PROD UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = BigProd_limits;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4678 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 130: /* oper_head: PROD UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE  */
#line 1729 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "oper_head: PROD UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = BigProd_limits;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4698 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 131: /* oper_head: SUM UNDERSCORE LBRACE term RBRACE  */
#line 1745 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "oper_head: SUM UNDERSCORE LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = BigSum_only_index;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4714 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 132: /* oper_head: PROD UNDERSCORE LBRACE term RBRACE  */
#line 1757 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "oper_head: PROD UNDERSCORE LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = BigProd_only_index;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4730 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 133: /* interval: LBRACKET term COMMA term RPAREN  */
#line 1771 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LBRACKET term COMMA term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Interval_lclosed_ropen;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4750 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 134: /* interval: LPAREN term COMMA term RBRACKET  */
#line 1787 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LPAREN term COMMA term RBRACKET\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Interval_lopen_rclosed;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4770 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 135: /* interval: LBRACKET term COMMA term RBRACKET  */
#line 1803 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term: LBRACKET term COMMA term RBRACKET\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Interval_lclosed_rclosed;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.t);
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        ((*yyvalp).t) = tmp1;
    }
#line 4790 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 136: /* infty: INFTY  */
#line 1821 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "infty: INFTY\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Infty;
        ((*yyvalp).t) = tmp;
    }
#line 4802 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 137: /* infty: POS_INFTY  */
#line 1829 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "infty: POS_INFTY\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Pos_Infty;
        ((*yyvalp).t) = tmp;
    }
#line 4814 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 138: /* infty: NEG_INFTY  */
#line 1837 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "infty: POS_INFTY\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Neg_Infty;
        ((*yyvalp).t) = tmp;
    }
#line 4826 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 139: /* term_comma_list: term COMMA term  */
#line 1847 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term_comma_list: term COMMA term\n");
        term_list *tmp1 = (term_list *) calloc(1, sizeof(term_list));
        term_list *tmp2 = (term_list *) calloc(1, sizeof(term_list));
        tmp1->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp1->next = tmp2;
        tmp2->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.t);
        tmp2->next = NULL;
        ((*yyvalp).tl) = tmp1;
    }
#line 4841 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 140: /* term_comma_list: term COMMA term_comma_list  */
#line 1858 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term_comma_list: term COMMA term_comma_list\n");
        term_list *tmp = (term_list *) malloc(sizeof(term_list));
        tmp->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp->next = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tl);
        ((*yyvalp).tl) = tmp;

        /* term_list *tmp = $1;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp.next = (term_list *) malloc(sizeof(term_list));
        tmp.next->element = $3;
        tmp.next->next = NULL;
        $$ = $1; */
    }
#line 4860 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 141: /* term_paren_list: LPAREN term RPAREN  */
#line 1875 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term_paren_list: LPAREN term RPAREN\n");
        term_list *tmp = (term_list *) calloc(1, sizeof(term_list));
        tmp->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.t);
        tmp->next = NULL;
        ((*yyvalp).tl) = tmp;
    }
#line 4872 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;

  case 142: /* term_paren_list: LPAREN term RPAREN term_paren_list  */
#line 1883 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"
    {
        if (pm->debug) fprintf(stderr, "term_paren_list: LPAREN term RPAREN term_paren_list\n");
        term_list *tmp = (term_list *) calloc(1, sizeof(term_list));
        tmp->element = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.t);
        tmp->next = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tl);
        ((*yyvalp).tl) = tmp;
    }
#line 4884 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"
    break;


#line 4888 "/Users/sheringham/Desktop/ai4math/proofgrader/build/parser/parser.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, parser_mode *pm)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (pm);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, yyscan_t scanner, parser_mode *pm)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval, &yys->yyloc, scanner, pm);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, scanner, pm);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, yyscan_t scanner, parser_mode *pm)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , scanner, pm);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, yyscan_t scanner, parser_mode *pm)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp, yylocp, scanner, pm);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp, yylocp, scanner, pm);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval, yyscan_t scanner, parser_mode *pm)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval, &yyloc, scanner, pm);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval, &yyloc);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yyscan_t scanner, parser_mode *pm);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, yyscan_t scanner, parser_mode *pm)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, scanner, pm));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, scanner, pm));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, yyscan_t scanner, parser_mode *pm)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, scanner, pm);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, scanner, pm);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp, yylocp, scanner, pm);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, yyscan_t scanner, parser_mode *pm)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (yylocp, scanner, pm, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp, yyscan_t scanner, parser_mode *pm)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, scanner, pm);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, scanner, pm);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yyscan_t scanner, parser_mode *pm)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, scanner, pm);
              return yyreportAmbiguity (yybest, yyp, yylocp, scanner, pm);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, scanner, pm);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other, &yydummy, scanner, pm);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval, yylocp, scanner, pm);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, scanner, pm);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, yyscan_t scanner, parser_mode *pm)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , scanner, pm));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn, YYLTYPE *yylocp, yyscan_t scanner, parser_mode *pm)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], scanner, pm);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, scanner, pm);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], scanner, pm);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, scanner, pm));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], scanner, pm);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp, yyscan_t scanner, parser_mode *pm)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yystrlen (yysymbol_name (yyarg[yyi]));
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (&yylloc, scanner, pm, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, scanner, pm, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, yyscan_t scanner, parser_mode *pm)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, scanner, pm, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, scanner, pm);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, scanner, pm);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, &yylloc, scanner, pm, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, scanner, pm);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, scanner, pm, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, parser_mode *pm)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, scanner, pm);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, scanner, pm));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, scanner, pm);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack, scanner, pm);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, scanner, pm));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, scanner, pm));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, scanner, pm, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, scanner, pm));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, scanner, pm);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, scanner, pm));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, scanner, pm);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (&yylloc, scanner, pm, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, scanner, pm);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, scanner, pm);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc




#line 1892 "/Users/sheringham/Desktop/ai4math/proofgrader/src/parser/parser.y"


void yyerror(YYLTYPE *yyllocp, yyscan_t unused, parser_mode *pm, const char *msg) {
    if (pm->from_string) {
        char *tmp = malloc((yyllocp->last_column - yyllocp->first_column + 2) * sizeof(char));
        strncpy(tmp, pm->data + yyllocp->first_column, (yyllocp->last_column - yyllocp->first_column + 1));
        fprintf(stderr, "\n%s: %s.\n", tmp, msg);

        FILE *msg_file = fopen("error_msg.txt", "w");
        fprintf(msg_file, "-1");
        fclose(msg_file);

        free(tmp);
    }
    else{
        fprintf(stderr, "\n%s:%d.%d-%d.%d: %s.\n", pm->data,
        yyllocp->first_line, yyllocp->first_column, yyllocp->last_line, yyllocp->last_column, msg);

        FILE *msg_file = fopen("error_msg.txt", "w");
        fprintf(msg_file, "%d",yyllocp->first_line);
        fclose(msg_file);
    }
}
