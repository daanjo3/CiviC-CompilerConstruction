/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/scanparse/civic.y" /* yacc.c:339  */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "types.h"
#include "tree_basic.h"
#include "str.h"
#include "dbug.h"
#include "ctinfo.h"
#include "free.h"
#include "globals.h"

static node *parseresult = NULL;
extern int yylex();
static int yyerror( char *errname);


#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPE_BOOL = 258,
    TYPE_INT = 259,
    TYPE_VOID = 260,
    TYPE_FLOAT = 261,
    BRACKET_L = 262,
    BRACKET_R = 263,
    BRACE_L = 264,
    BRACE_R = 265,
    COMMA = 266,
    SEMICOLON = 267,
    MINUS = 268,
    PLUS = 269,
    STAR = 270,
    SLASH = 271,
    PERCENT = 272,
    LE = 273,
    LT = 274,
    GE = 275,
    GT = 276,
    EQ = 277,
    NE = 278,
    AND = 279,
    OR = 280,
    NOT = 281,
    LET = 282,
    DO = 283,
    WHILE = 284,
    FOR = 285,
    IF = 286,
    ELSE = 287,
    RETURN = 288,
    EXTERN = 289,
    EXPORT = 290,
    TRUEVAL = 291,
    FALSEVAL = 292,
    COMMENT_SINGLE = 293,
    COMMENT_MULT = 294,
    NUM = 295,
    FLOAT = 296,
    ID = 297
  };
#endif
/* Tokens.  */
#define TYPE_BOOL 258
#define TYPE_INT 259
#define TYPE_VOID 260
#define TYPE_FLOAT 261
#define BRACKET_L 262
#define BRACKET_R 263
#define BRACE_L 264
#define BRACE_R 265
#define COMMA 266
#define SEMICOLON 267
#define MINUS 268
#define PLUS 269
#define STAR 270
#define SLASH 271
#define PERCENT 272
#define LE 273
#define LT 274
#define GE 275
#define GT 276
#define EQ 277
#define NE 278
#define AND 279
#define OR 280
#define NOT 281
#define LET 282
#define DO 283
#define WHILE 284
#define FOR 285
#define IF 286
#define ELSE 287
#define RETURN 288
#define EXTERN 289
#define EXPORT 290
#define TRUEVAL 291
#define FALSEVAL 292
#define COMMENT_SINGLE 293
#define COMMENT_MULT 294
#define NUM 295
#define FLOAT 296
#define ID 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "src/scanparse/civic.y" /* yacc.c:355  */

 nodetype            nodetype;
 char               *id;
 int                 cint;
 float               cflt;
 binop               cbinop;
 monop               monop;
 node               *node;
 basictype          basictype;

#line 223 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 240 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    64,    66,    70,    72,    74,    78,    80,
      82,    84,    86,    88,    92,    96,    98,   100,   102,   106,
     108,   112,   114,   116,   118,   122,   124,   126,   128,   130,
     132,   134,   138,   140,   142,   144,   148,   150,   155,   157,
     161,   163,   165,   167,   169,   171,   173,   177,   179,   183,
     185,   189,   191,   195,   197,   201,   203,   205,   207,   209,
     211,   213,   215,   217,   219,   223,   227,   231,   232,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   250
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE_BOOL", "TYPE_INT", "TYPE_VOID",
  "TYPE_FLOAT", "BRACKET_L", "BRACKET_R", "BRACE_L", "BRACE_R", "COMMA",
  "SEMICOLON", "MINUS", "PLUS", "STAR", "SLASH", "PERCENT", "LE", "LT",
  "GE", "GT", "EQ", "NE", "AND", "OR", "NOT", "LET", "DO", "WHILE", "FOR",
  "IF", "ELSE", "RETURN", "EXTERN", "EXPORT", "TRUEVAL", "FALSEVAL",
  "COMMENT_SINGLE", "COMMENT_MULT", "NUM", "FLOAT", "ID", "$accept",
  "program", "declarations", "declaration", "fundefdec", "globaldec",
  "globaldef", "param", "type", "funbody", "vardecs", "localfundefs",
  "statements", "stmt", "for", "if", "block", "exprs", "expr", "cast",
  "funcall", "monop", "binop", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -77

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   -77,   -77,   -77,   -77,   170,   170,    16,   -77,    25,
     -77,   -77,   -77,   -24,   -16,   -10,   -77,   -77,    -5,     1,
       7,   177,   -77,   190,   463,   -77,     9,   -77,   190,    46,
      53,    31,   165,   190,   190,   -77,   -77,   -77,   -77,   -77,
     370,   -77,   -77,   -77,   -77,    60,    74,    64,    79,   384,
     206,    84,    87,    92,   254,   -77,   -77,   -77,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   -77,    83,   206,    94,   -77,    48,   109,   114,
     116,   190,   170,   170,   130,    59,   132,   206,    99,   -77,
      99,   -77,   -77,   112,    -3,   206,   170,   190,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   118,   341,   -77,   133,   206,    99,   -77,   115,
     190,   144,   190,   398,   108,   110,   124,   -77,    41,   -77,
     125,    99,   -77,   -77,   -77,   -77,   190,   141,   -77,   -77,
     -77,   190,   -77,   146,   147,   153,   272,   135,   290,   -77,
     179,   183,   187,   -77,   190,    44,   -77,   412,   -77,   -77,
     -77,   -77,   190,    48,   127,    48,   426,   -77,   190,   -77,
     308,   -77,   190,   152,   -77,   440,   184,   356,    48,   -77,
     -77,   190,   -77,   236,    48,   190,   -77,   326,    48,   -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    21,    24,    22,     0,     0,     0,     2,     4,
       5,     6,     7,     0,     0,     0,     1,     3,     0,     0,
       0,     0,    18,     0,     0,    14,     0,    16,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    62,    61,    82,
       0,    58,    60,    57,    56,    59,     0,     0,     0,     0,
       0,     0,    20,     0,     0,    67,    68,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,    29,    30,    31,
      39,    45,    44,     0,     0,     0,     0,     0,    55,    70,
      69,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      81,    80,     0,    54,    13,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    10,
       0,    26,    27,    28,    38,    41,     0,     0,    19,    65,
      66,     0,     8,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,    35,     0,     0,    25,     0,    11,    53,
       9,    51,     0,     0,     0,     0,     0,    33,     0,    40,
       0,    42,     0,    50,    34,     0,     0,     0,     0,    32,
      43,     0,    49,     0,     0,     0,    48,     0,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   189,   -77,     6,   -77,   -77,   -21,   105,   -62,
     -77,   -18,   -67,   -76,   -77,   -77,   -69,    58,   -23,   -77,
      30,   -77,   -77,   -25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    84,    11,    12,    30,    31,    86,
      87,    88,    89,    90,    91,    92,   119,   112,   113,    41,
      42,    43,    44,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,   118,    21,    47,    71,    49,    10,    22,    24,    54,
      55,    56,   115,    25,    26,    10,    16,    48,    18,    27,
     132,   133,    23,   134,   136,    94,    19,    75,     1,     2,
       3,     4,    20,   137,    28,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    21,    94,
     144,    21,    94,   153,   143,    50,   167,   117,   123,     5,
       6,    51,    94,    94,   156,    94,   127,    71,   154,   131,
      94,   168,    73,    52,   139,   138,    77,    78,    79,    80,
      93,    81,     1,     2,     3,     4,    72,   118,    74,   118,
      39,    94,    94,    95,   171,   114,   173,   146,    96,   148,
      97,   128,   118,   116,    93,    13,    94,    93,   118,   182,
      14,    15,   118,   157,    13,   186,   120,    93,    93,   189,
      93,   121,   164,   122,   135,    93,   140,    77,    78,    79,
      80,   166,    81,     1,     2,     3,     4,    53,    94,   170,
      94,    39,   129,   142,   145,   175,    93,    93,   147,   177,
     150,   158,   151,    94,   172,    85,   160,   161,   183,    94,
     162,    93,   187,    94,    82,    83,   152,   155,     1,     2,
       3,     4,    32,     1,     2,     3,     4,    39,    33,    85,
       1,     2,     3,     4,   178,    29,    24,   124,   125,   126,
      26,    34,   130,    93,    21,    93,   180,    32,    17,   159,
      85,    35,    36,    33,     0,    37,    38,    39,    93,     1,
       2,     3,     4,     0,    93,     0,    34,     0,    93,     0,
       0,    85,     0,     0,     0,     0,    35,    36,     0,     0,
      37,    38,    39,     0,    77,    78,    79,    80,     0,    81,
      82,    83,     0,     0,   184,     0,     0,   185,    39,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    98,     0,     0,     0,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     163,     0,     0,     0,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,   165,     0,
       0,     0,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   176,     0,     0,     0,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   188,     0,     0,     0,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,   141,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,   181,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    76,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     149,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   169,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,   174,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,   179,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     1,     2,     3,     4,
       0,    46
};

static const yytype_int16 yycheck[] =
{
      23,    77,     7,    24,     7,    28,     0,    12,     7,    32,
      33,    34,    74,    12,     7,     9,     0,     8,    42,    12,
      87,    88,    27,    90,    27,    50,    42,    48,     3,     4,
       5,     6,    42,    95,    27,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     7,    74,
     117,     7,    77,    12,   116,     9,    12,     9,    81,    34,
      35,     8,    87,    88,   131,    90,    84,     7,    27,    87,
      95,    27,     8,    42,    97,    96,    28,    29,    30,    31,
      50,    33,     3,     4,     5,     6,    12,   163,     9,   165,
      42,   116,   117,     9,   163,    12,   165,   120,    11,   122,
       8,    42,   178,     9,    74,     0,   131,    77,   184,   178,
       5,     6,   188,   136,     9,   184,     7,    87,    88,   188,
      90,     7,   147,     7,    12,    95,     8,    28,    29,    30,
      31,   154,    33,     3,     4,     5,     6,    32,   163,   162,
     165,    42,    10,    10,    29,   168,   116,   117,     4,   172,
      42,    10,    42,   178,    27,    50,    10,    10,   181,   184,
       7,   131,   185,   188,    34,    35,    42,    42,     3,     4,
       5,     6,     7,     3,     4,     5,     6,    42,    13,    74,
       3,     4,     5,     6,    32,     8,     7,    82,    83,    84,
       7,    26,    87,   163,     7,   165,    12,     7,     9,   141,
      95,    36,    37,    13,    -1,    40,    41,    42,   178,     3,
       4,     5,     6,    -1,   184,    -1,    26,    -1,   188,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,
      40,    41,    42,    -1,    28,    29,    30,    31,    -1,    33,
      34,    35,    -1,    -1,     8,    -1,    -1,    11,    42,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     8,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       8,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     8,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     8,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     8,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     3,     4,     5,     6,
      -1,     8
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    34,    35,    44,    45,    46,
      47,    48,    49,    51,    51,    51,     0,    45,    42,    42,
      42,     7,    12,    27,     7,    12,     7,    12,    27,     8,
      50,    51,     7,    13,    26,    36,    37,    40,    41,    42,
      61,    62,    63,    64,    65,    66,     8,    50,     8,    61,
       9,     8,    42,    51,    61,    61,    61,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     7,    12,     8,     9,    50,    12,    28,    29,    30,
      31,    33,    34,    35,    47,    51,    52,    53,    54,    55,
      56,    57,    58,    63,    66,     9,    11,     8,     8,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    60,    61,    12,    52,     9,     9,    56,    59,
       7,     7,     7,    61,    51,    51,    51,    54,    42,    10,
      51,    54,    55,    55,    55,    12,    27,    52,    50,    61,
       8,    11,    10,    52,    55,    29,    61,     4,    61,    12,
      42,    42,    42,    12,    27,    42,    55,    61,    10,    60,
      10,    10,     7,     8,    66,     8,    61,    12,    27,    12,
      61,    59,    27,    59,    12,    61,     8,    61,    32,    12,
      12,    11,    59,    61,     8,    11,    59,    61,     8,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    47,    47,    48,    49,    49,    49,    49,    50,
      50,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     8,     9,
       7,     8,     6,     7,     4,     6,     4,     5,     3,     4,
       2,     1,     1,     1,     1,     3,     2,     2,     2,     1,
       1,     1,     6,     4,     5,     3,     2,     1,     2,     1,
       4,     2,     5,     7,     1,     1,     3,    12,    10,     7,
       5,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 61 "src/scanparse/civic.y" /* yacc.c:1646  */
    { parseresult = TBmakeProgram((yyvsp[0].node), NULL); }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 65 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeDeclarations((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeDeclarations((yyvsp[0].node), NULL); }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 71 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 75 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFundefdec(TRUE, (yyvsp[-6].basictype), (yyvsp[-5].id), NULL, (yyvsp[-1].node), NULL); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 81 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFundefdec(TRUE, (yyvsp[-7].basictype), (yyvsp[-6].id), (yyvsp[-3].node), (yyvsp[-1].node), NULL); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 83 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFundefdec(FALSE, (yyvsp[-6].basictype), (yyvsp[-5].id), NULL, (yyvsp[-1].node), NULL); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 85 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFundefdec(FALSE, (yyvsp[-7].basictype), (yyvsp[-6].id), (yyvsp[-4].node), (yyvsp[-1].node), NULL); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 87 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFundefdec(FALSE, (yyvsp[-4].basictype), (yyvsp[-3].id), NULL, NULL, NULL); }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFundefdec(FALSE, (yyvsp[-5].basictype), (yyvsp[-4].id), (yyvsp[-2].node), NULL, NULL); }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 93 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeGlobaldec((yyvsp[-2].basictype), (yyvsp[-1].id)); }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 97 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeGlobaldef((yyvsp[-4].basictype), TRUE, (yyvsp[-3].id), (yyvsp[-1].node)); }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 99 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeGlobaldef((yyvsp[-2].basictype), TRUE, (yyvsp[-1].id), NULL); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 101 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeGlobaldef((yyvsp[-4].basictype), FALSE, (yyvsp[-3].id), (yyvsp[-1].node)); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 103 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeGlobaldef((yyvsp[-2].basictype), FALSE, (yyvsp[-1].id), NULL); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 107 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeParam((yyvsp[-3].basictype), (yyvsp[-2].id), (yyvsp[0].node)); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeParam((yyvsp[-1].basictype), (yyvsp[0].id), NULL); }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 113 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.basictype) = BT_int; }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.basictype) = BT_float; }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 117 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.basictype) = BT_bool; }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 119 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.basictype) = RT_void; }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 123 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFunbody((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 125 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFunbody((yyvsp[-1].node), (yyvsp[0].node), NULL); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 127 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFunbody((yyvsp[-1].node), NULL, (yyvsp[0].node)); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFunbody(NULL, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 131 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFunbody((yyvsp[0].node), NULL, NULL); }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 133 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFunbody(NULL, (yyvsp[0].node), NULL); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 135 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFunbody(NULL, NULL, (yyvsp[0].node)); }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 139 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeVardec((yyvsp[-4].basictype), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[-5].node)); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 141 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeVardec((yyvsp[-2].basictype), (yyvsp[-1].id), NULL, (yyvsp[-3].node)); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 143 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeVardec((yyvsp[-4].basictype), (yyvsp[-3].id), (yyvsp[-1].node), NULL); }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 145 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeVardec((yyvsp[-2].basictype), (yyvsp[-1].id), NULL, NULL); }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 149 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeLocalfundefs((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 151 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeLocalfundefs((yyvsp[0].node), NULL); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 156 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeStatements( (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 158 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeStatements( (yyvsp[0].node), NULL); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 162 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeAssign((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 164 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 166 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeWhile((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 168 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeDowhile((yyvsp[-2].node), (yyvsp[-5].node)); }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 170 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 172 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 174 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeReturn((yyvsp[-1].node)); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 178 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFor((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 180 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 184 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeIf((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 186 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeIf((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 190 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 192 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 196 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeExprs((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 198 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeExprs((yyvsp[0].node), NULL); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 202 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 204 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 206 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 208 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 210 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 212 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 214 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFloat((yyvsp[0].cflt)); }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 216 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeNum((yyvsp[0].cint)); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 218 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBool(TRUE); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 220 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBool(FALSE); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 224 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeCast((yyvsp[-2].basictype), (yyvsp[0].node)); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 228 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeFuncall((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 231 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeMonop(MO_neg, (yyvsp[0].node)); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 232 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeMonop(MO_not, (yyvsp[0].node)); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 235 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_add, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 236 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_sub, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 237 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_mul, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 238 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_div, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 239 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_mod, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 240 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_le, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 241 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_lt, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 242 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_ge, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 243 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_gt, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 244 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_eq, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 245 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_ne, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 246 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_or, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 247 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeBinop(BO_and, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 251 "src/scanparse/civic.y" /* yacc.c:1646  */
    { (yyval.node) = TBmakeVar((yyvsp[0].id)); }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1981 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 253 "src/scanparse/civic.y" /* yacc.c:1906  */


static int yyerror( char *error)
{
  CTIabort( "line %d, col %d\nError parsing source code: %s\n",
            global.line, global.col, error);

  return( 0);
}

node *YYparseTree( void)
{
  DBUG_ENTER("YYparseTree");

  yyparse();

  DBUG_RETURN( parseresult);
}
