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
#line 1 "sintatica.y" /* yacc.c:339  */

	#include <iostream>
	#include <string>
	#include <sstream>
	#include <vector>
	#include <stack>
	#include "stdlib.h"

	#define YYSTYPE atributos
	#include "operationsSoft.h"

#line 78 "y.tab.c" /* yacc.c:339  */

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
    TK_CAST = 258,
    TK_OPL = 259,
    TK_OPA = 260,
    TK_TRUE = 261,
    TK_FALSE = 262,
    TK_ADD1 = 263,
    TK_SUB1 = 264,
    TK_ADDI = 265,
    TK_SUBI = 266,
    TK_INVERT = 267,
    TK_MAIN = 268,
    TK_ID = 269,
    TK_CHAR = 270,
    TK_STRING = 271,
    TK_INT = 272,
    TK_FLOAT = 273,
    TK_BOOL = 274,
    TK_TYPES = 275,
    TK_GLOBAL = 276,
    TK_VAR = 277,
    TK_FIM = 278,
    TK_ERROR = 279,
    TK_BEGIN = 280,
    TK_END = 281,
    TK_FUNCTION = 282,
    TK_FUNCTIONS = 283,
    TK_PROCEDURE = 284,
    TK_WHILE = 285,
    TK_FOR = 286,
    TK_DO = 287,
    TK_BREAK = 288,
    TK_CONTINUE = 289,
    TK_UNTIL = 290,
    TK_DEFAULT = 291,
    TK_IF = 292,
    TK_ELSE = 293,
    TK_ELIF = 294,
    TK_CASE = 295,
    TK_SWITCH = 296,
    TK_READLN = 297,
    TK_WRITELN = 298,
    TK_RETURN = 299,
    TK_POW = 300,
    TK_MULTI = 301,
    TK_DIVI = 302,
    TK_FACTORIAL = 303,
    TK_IN = 304,
    TK_FOREACH = 305,
    TK_NOT = 306,
    TK_AS = 307,
    TK_MOD = 308,
    TK_MODI = 309
  };
#endif
/* Tokens.  */
#define TK_CAST 258
#define TK_OPL 259
#define TK_OPA 260
#define TK_TRUE 261
#define TK_FALSE 262
#define TK_ADD1 263
#define TK_SUB1 264
#define TK_ADDI 265
#define TK_SUBI 266
#define TK_INVERT 267
#define TK_MAIN 268
#define TK_ID 269
#define TK_CHAR 270
#define TK_STRING 271
#define TK_INT 272
#define TK_FLOAT 273
#define TK_BOOL 274
#define TK_TYPES 275
#define TK_GLOBAL 276
#define TK_VAR 277
#define TK_FIM 278
#define TK_ERROR 279
#define TK_BEGIN 280
#define TK_END 281
#define TK_FUNCTION 282
#define TK_FUNCTIONS 283
#define TK_PROCEDURE 284
#define TK_WHILE 285
#define TK_FOR 286
#define TK_DO 287
#define TK_BREAK 288
#define TK_CONTINUE 289
#define TK_UNTIL 290
#define TK_DEFAULT 291
#define TK_IF 292
#define TK_ELSE 293
#define TK_ELIF 294
#define TK_CASE 295
#define TK_SWITCH 296
#define TK_READLN 297
#define TK_WRITELN 298
#define TK_RETURN 299
#define TK_POW 300
#define TK_MULTI 301
#define TK_DIVI 302
#define TK_FACTORIAL 303
#define TK_IN 304
#define TK_FOREACH 305
#define TK_NOT 306
#define TK_AS 307
#define TK_MOD 308
#define TK_MODI 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   661

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    64,     2,     2,
      69,    70,    68,    65,    73,    66,     2,    67,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    71,
      60,    55,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,    77,     2,     2,     2,     2,
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
      56,    57,    58,    59,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    84,    88,    91,    96,   100,   104,   111,
     122,   133,   134,   135,   138,   144,   150,   161,   165,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   187,   197,   205,   217,
     229,   241,   250,   254,   257,   269,   282,   311,   349,   357,
     367,   393,   424,   449,   479,   507,   543,   586,   629,   690,
     753,   764,   784,   811,   835,   848,   853,   858,   863,   868,
     875,   879,   897,   908,   919,   930,   941,   950,   959,   963,
     967,   971,   977,  1069,  1079,  1089,  1092,  1098,  1111,  1117,
    1125,  1133,  1144,  1176,  1204,  1222,  1227,  1232,  1239,  1244,
    1249,  1256,  1263,  1271,  1281,  1285,  1288,  1301,  1305,  1308,
    1319,  1325,  1331,  1337,  1343,  1349,  1355,  1373,  1399,  1434,
    1438,  1442,  1446,  1452,  1456,  1460,  1463,  1471,  1477,  1519,
    1582,  1596,  1617,  1633
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_CAST", "TK_OPL", "TK_OPA", "TK_TRUE",
  "TK_FALSE", "TK_ADD1", "TK_SUB1", "TK_ADDI", "TK_SUBI", "TK_INVERT",
  "TK_MAIN", "TK_ID", "TK_CHAR", "TK_STRING", "TK_INT", "TK_FLOAT",
  "TK_BOOL", "TK_TYPES", "TK_GLOBAL", "TK_VAR", "TK_FIM", "TK_ERROR",
  "TK_BEGIN", "TK_END", "TK_FUNCTION", "TK_FUNCTIONS", "TK_PROCEDURE",
  "TK_WHILE", "TK_FOR", "TK_DO", "TK_BREAK", "TK_CONTINUE", "TK_UNTIL",
  "TK_DEFAULT", "TK_IF", "TK_ELSE", "TK_ELIF", "TK_CASE", "TK_SWITCH",
  "TK_READLN", "TK_WRITELN", "TK_RETURN", "TK_POW", "TK_MULTI", "TK_DIVI",
  "TK_FACTORIAL", "TK_IN", "TK_FOREACH", "TK_NOT", "TK_AS", "TK_MOD",
  "TK_MODI", "'='", "\"||\"", "\"&&\"", "\"==\"", "\"!=\"", "'<'", "'>'",
  "\">=\"", "\"<=\"", "'%'", "'+'", "'-'", "'/'", "'*'", "'('", "')'",
  "';'", "':'", "','", "'['", "']'", "'{'", "'}'", "$accept", "S", "MAINS",
  "MAIN", "FUN", "PROCEDURE", "DECS", "DEC_FUN", "BLOCO", "COMANDOS",
  "COMANDO", "BREAK", "CONTINUE", "GLOBAL", "DECLARACOES", "VECTOR_MATRIX",
  "TERMS", "VECTOR_MATRIX_OPERATIONS", "SLICE", "OPERACOES",
  "OPERACOES_COMPOSTAS", "EXPR", "CALL_FUN", "FUN_PARAMS", "FUN_PARAM",
  "LOGICO", "WHILE", "UNTIL", "FOR", "FOREACH", "CAST", "CONIF",
  "CONIF_NO_MATCHED", "CONIF_MATCHED", "SWITCH", "CASES", "CASE",
  "DEFAULT", "TERM", "WRITE", "PRINT", "PARAMS", "PARAM", "PRINT_SLICER",
  "PRINT_ELEMENT_VECTOR", "PRINT_VECTORS", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    61,   310,   311,   312,   313,
      60,    62,   314,   315,    37,    43,    45,    47,    42,    40,
      41,    59,    58,    44,    91,    93,   123,   125
};
# endif

#define YYPACT_NINF -224

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-224)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,    -6,    -3,     1,    19,    44,  -224,    -4,  -224,  -224,
       5,  -224,   341,  -224,    -1,    10,    25,  -224,  -224,  -224,
     559,  -224,  -224,  -224,  -224,   -42,  -224,  -224,  -224,  -224,
      43,    43,   112,  -224,  -224,  -224,    31,    -5,    54,    54,
      29,  -224,   559,    43,   436,  -224,    20,    43,    43,    43,
      43,    43,    43,    79,    91,    37,    36,    51,    52,    40,
    -224,   131,  -224,   -46,   112,   112,     3,     3,     9,     9,
     479,  -224,   559,    48,    54,   104,  -224,   559,    57,    43,
     559,   250,   118,    65,    70,    79,  -224,  -224,    72,    73,
      78,    80,    82,    83,   127,   479,    84,    90,    97,    98,
      99,   100,   101,   413,   102,  -224,  -224,  -224,  -224,  -224,
    -224,   103,   105,  -224,   134,  -224,   479,  -224,    43,   142,
      86,   108,    43,    43,   559,   559,    43,    43,  -224,    43,
      43,    43,  -224,   112,  -224,    43,    27,   159,    43,    43,
      43,    39,   176,   559,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,   168,   174,   316,
     125,  -224,   559,   112,   112,  -224,  -224,   112,   112,   112,
     121,    92,   514,   133,   136,   112,   132,   141,   552,   143,
     145,  -224,   146,   158,   154,   155,   163,   169,   189,   479,
    -224,  -224,   559,  -224,    43,   299,    79,    43,    43,    79,
      79,   216,   220,    75,  -224,    50,  -224,  -224,  -224,  -224,
      -8,   202,   171,   337,   559,    43,  -224,   112,  -224,   178,
     558,  -224,    62,   210,   210,   177,   218,  -224,  -224,   200,
     240,   559,  -224,   320,  -224,   356,   249,  -224,    79,   201,
    -224,  -224,   559,   233,   210,   233,   198,    43,   203,   261,
     224,   207,    43,  -224,   112,   543,   524,   209,  -224,    43,
     215,   217,   255,  -224,   256,  -224,   360,    43,   222,   280,
     273,   162,   559,  -224,   112,    79,   230,   479,   479,  -224,
    -224,   227,   376,    79,   242,  -224,    43,  -224,  -224,    79,
    -224,  -224,    43,  -224,  -224,    79,   381,    62,   397,  -224,
     592,  -224,  -224,    43,  -224,   112,   392,  -224
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     2,     4,     6,     7,
       0,    43,    41,    42,     0,     0,     0,     1,     3,     8,
       0,   110,   111,    76,    77,   109,   113,   115,   112,   114,
       0,     0,    39,    81,    78,    79,    80,     0,    13,    13,
     109,    94,    85,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,    83,
      86,     0,    70,    44,    87,    75,    71,    72,    74,    73,
      18,     5,    14,     0,    13,     0,    82,    85,   116,     0,
       0,   109,     0,     0,     0,     0,    36,    37,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    24,    26,    25,    29,    27,
      28,     0,     0,    15,     0,    12,    18,    84,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,    63,     0,
      85,     0,    64,    60,    38,     0,     0,     0,     0,     0,
       0,   125,     0,     0,    16,    17,    30,    31,    35,    19,
      21,    34,    20,    32,    22,    33,    23,     0,     0,     0,
      45,    46,     0,    65,    66,    61,    62,    67,    68,    69,
      80,     0,     0,     0,     0,     0,    78,    78,     0,    80,
     126,   127,     0,   123,     0,     0,     0,     0,     0,    18,
      10,   117,     0,    49,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   125,   122,   121,   120,   118,
       0,     0,     0,     0,     0,     0,    52,    50,    88,    78,
       0,    90,    95,   105,   105,   132,     0,   126,   124,     0,
       0,     0,    47,     0,    54,     0,     0,    89,     0,     0,
      96,    97,     0,   108,   105,   108,     0,     0,   130,     0,
       0,     0,     0,    56,    57,   117,     0,     0,   101,     0,
       0,     0,     0,   104,     0,   133,     0,     0,     0,     0,
       0,     0,     0,    53,    51,     0,    78,    18,    18,   102,
     103,   128,     0,     0,     0,     9,     0,    55,    91,     0,
     106,   107,     0,   131,    92,     0,     0,   100,     0,    93,
       0,    98,    99,     0,    58,    59,     0,   129
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,   296,  -224,  -224,  -224,   -29,  -224,   -63,   -90,
    -224,  -224,  -224,  -224,     2,  -224,  -158,  -224,  -224,    85,
    -192,   -12,  -224,   241,  -224,   -41,  -224,  -224,  -224,  -224,
    -224,  -224,    28,    35,  -224,  -223,  -224,    77,     0,  -224,
    -224,   128,  -224,  -224,  -224,  -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    55,    56,    71,    94,
      95,    96,    97,    98,    99,    11,   120,   100,   101,   102,
     132,   103,    33,    58,    59,    34,   105,   106,   107,   108,
      35,   109,   240,   241,   110,   243,   244,   262,    45,   111,
     112,   182,   183,   184,   185,   186
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   245,    10,   216,   193,   145,   229,    47,    12,    10,
      57,    13,    36,    47,    14,    15,     1,     2,    44,    46,
      41,   263,   137,     3,    47,     4,   158,    42,    79,   104,
      80,    61,    43,    16,   212,    64,    65,    66,    67,    68,
      69,   253,    60,   230,    17,   115,    20,     1,     2,    21,
      22,    23,    24,   180,   104,   181,    48,    25,    26,    27,
      28,    29,    48,   273,   227,    53,   181,   119,    37,   133,
      51,    52,   113,    48,    54,   104,    19,    60,    20,    38,
     121,    21,    22,    23,    24,    49,    50,    51,    52,    25,
      26,    27,    28,    29,    39,    63,    47,   176,   177,   211,
     238,   239,   -40,    43,    70,    72,   159,    73,   304,    74,
     163,   164,    30,    77,   167,   168,    47,   169,    44,   171,
     114,    75,    76,   172,   165,   166,   175,   175,   178,   116,
     170,   118,   134,   218,   135,    47,   221,   222,   173,   136,
     179,   138,   139,   188,    30,    48,    47,   140,   104,   141,
     225,   142,   143,   144,   157,   146,   219,    49,    50,    51,
      52,   147,   121,   161,   194,    48,    47,   195,   148,   149,
     150,   151,   152,   154,   155,   258,   156,    49,    50,    51,
      52,   162,   213,   217,    48,   175,   220,   290,   291,   174,
     187,   226,   121,   189,   -86,    48,    49,    50,    51,    52,
     190,   192,   199,   235,   197,   198,    78,    49,    50,    51,
      52,   200,   288,   202,   234,    48,   204,   160,   276,   203,
     294,   254,    47,   205,   206,   207,   297,    49,    50,    51,
      52,   251,   299,   208,   286,   266,   104,   104,   210,   209,
     271,   223,   260,   274,   133,   224,   231,   175,   232,   236,
     242,   246,   249,    20,   250,   282,    21,    22,    23,    24,
     122,   123,   124,   256,    25,    26,    27,    28,    29,   261,
     259,    48,   287,   265,   296,   268,   269,   267,   270,   275,
     298,   279,   280,    49,    50,    51,    52,   277,   305,   278,
     247,   306,   283,   248,   284,   125,   126,   127,   128,   285,
     289,   292,    20,    18,   129,    21,    22,    23,    24,   122,
     123,   214,   295,    25,    26,    27,    28,    29,   117,   130,
      47,   257,   264,    20,   131,   301,    21,    22,    23,    24,
     122,   123,   302,   228,    25,    26,    27,    28,    29,     0,
       0,    47,     0,     0,    20,   126,   127,    21,    22,    23,
      24,     0,     0,   129,     0,    25,    26,    27,    28,    29,
      47,     0,     0,     0,    47,     0,   126,   127,    30,    48,
       0,     0,     0,   215,   129,     0,     0,     0,     0,     0,
      47,    49,    50,    51,    52,    47,     0,     0,     0,    30,
      48,   191,     0,     0,   252,     0,    47,     0,     0,     0,
       0,    47,    49,    50,    51,    52,     0,     0,     0,    48,
      30,     0,   233,    48,     0,    31,     0,    47,     0,     0,
       0,    49,    50,    51,    52,    49,    50,    51,    52,    48,
       0,   255,     0,     0,    48,   281,     0,     0,     0,     0,
      47,    49,    50,    51,    52,    48,    49,    50,    51,    52,
      48,   293,     0,     0,     0,     0,   300,    49,    50,    51,
      52,     0,    49,    50,    51,    52,    48,   307,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    50,
      51,    52,    20,     0,   153,    21,    22,    23,    24,    48,
       0,     0,     0,    81,    26,    27,    28,    29,     0,     1,
      82,    49,    50,    51,    52,     0,    62,     0,     0,    83,
      84,    85,    86,    87,    88,     0,    89,     0,    47,     0,
      90,    91,    92,     0,     0,     0,     0,    20,     0,    93,
      21,    22,    23,    24,   122,   123,   124,     0,    25,    26,
      27,    28,    29,     0,     0,     0,    20,     0,    30,    21,
      22,    23,    24,   122,   123,   272,    47,    25,    26,    27,
      28,    29,    47,     0,     0,    21,    22,    48,     0,   125,
     126,   127,   128,    40,    26,    27,    28,    29,   129,    49,
      50,    51,    52,     0,   196,     0,     0,     0,     0,   126,
     127,     0,     0,    30,     0,    20,     0,   129,    21,    22,
      23,    24,   122,   123,     0,    48,    25,    26,    27,    28,
      29,    48,    30,     0,     0,     0,     0,    49,    50,    51,
      52,     0,   201,    49,    50,    51,    52,     0,   237,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30
};

static const yytype_int16 yycheck[] =
{
      12,   224,     0,   195,   162,    95,    14,     4,    14,     7,
      39,    14,    12,     4,    13,    14,    20,    21,    30,    31,
      20,   244,    85,    27,     4,    29,   116,    69,    74,    70,
      76,    43,    74,    14,   192,    47,    48,    49,    50,    51,
      52,   233,    42,    51,     0,    74,     3,    20,    21,     6,
       7,     8,     9,    14,    95,    16,    53,    14,    15,    16,
      17,    18,    53,   255,    14,    70,    16,    79,    69,    81,
      67,    68,    72,    53,    20,   116,    71,    77,     3,    69,
      80,     6,     7,     8,     9,    65,    66,    67,    68,    14,
      15,    16,    17,    18,    69,    75,     4,   138,   139,   189,
      38,    39,    71,    74,    25,    14,   118,    70,   300,    73,
     122,   123,    69,    73,   126,   127,     4,   129,   130,   131,
      72,    70,    70,   135,   124,   125,   138,   139,   140,    25,
     130,    74,    14,   196,    69,     4,   199,   200,   136,    69,
     140,    69,    69,   143,    69,    53,     4,    69,   189,    69,
      75,    69,    69,    26,    20,    71,   197,    65,    66,    67,
      68,    71,   162,    77,    72,    53,     4,    75,    71,    71,
      71,    71,    71,    71,    71,   238,    71,    65,    66,    67,
      68,    73,   194,   195,    53,   197,   198,   277,   278,    30,
      14,   203,   192,    25,    73,    53,    65,    66,    67,    68,
      26,    76,    70,   215,    71,    69,    75,    65,    66,    67,
      68,    70,   275,    70,   214,    53,    70,    75,   259,    74,
     283,   233,     4,    65,    70,    70,   289,    65,    66,    67,
      68,   231,   295,    70,    72,   247,   277,   278,    49,    70,
     252,    25,   242,   255,   256,    25,    44,   259,    77,    71,
      40,    74,    52,     3,    14,   267,     6,     7,     8,     9,
      10,    11,    12,    14,    14,    15,    16,    17,    18,    36,
      69,    53,   272,    75,   286,    14,    52,    74,    71,    70,
     292,    26,    26,    65,    66,    67,    68,    72,   300,    72,
      72,   303,    70,    75,    14,    45,    46,    47,    48,    26,
      70,    74,     3,     7,    54,     6,     7,     8,     9,    10,
      11,    12,    70,    14,    15,    16,    17,    18,    77,    69,
       4,   236,   245,     3,    74,   297,     6,     7,     8,     9,
      10,    11,   297,   205,    14,    15,    16,    17,    18,    -1,
      -1,     4,    -1,    -1,     3,    46,    47,     6,     7,     8,
       9,    -1,    -1,    54,    -1,    14,    15,    16,    17,    18,
       4,    -1,    -1,    -1,     4,    -1,    46,    47,    69,    53,
      -1,    -1,    -1,    74,    54,    -1,    -1,    -1,    -1,    -1,
       4,    65,    66,    67,    68,     4,    -1,    -1,    -1,    69,
      53,    75,    -1,    -1,    74,    -1,     4,    -1,    -1,    -1,
      -1,     4,    65,    66,    67,    68,    -1,    -1,    -1,    53,
      69,    -1,    75,    53,    -1,    74,    -1,     4,    -1,    -1,
      -1,    65,    66,    67,    68,    65,    66,    67,    68,    53,
      -1,    75,    -1,    -1,    53,    75,    -1,    -1,    -1,    -1,
       4,    65,    66,    67,    68,    53,    65,    66,    67,    68,
      53,    75,    -1,    -1,    -1,    -1,    75,    65,    66,    67,
      68,    -1,    65,    66,    67,    68,    53,    75,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,     3,    -1,    71,     6,     7,     8,     9,    53,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,    20,
      21,    65,    66,    67,    68,    -1,    70,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    37,    -1,     4,    -1,
      41,    42,    43,    -1,    -1,    -1,    -1,     3,    -1,    50,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,     3,    -1,    69,     6,
       7,     8,     9,    10,    11,    12,     4,    14,    15,    16,
      17,    18,     4,    -1,    -1,     6,     7,    53,    -1,    45,
      46,    47,    48,    14,    15,    16,    17,    18,    54,    65,
      66,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    69,    -1,     3,    -1,    54,     6,     7,
       8,     9,    10,    11,    -1,    53,    14,    15,    16,    17,
      18,    53,    69,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    70,    65,    66,    67,    68,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    27,    29,    79,    80,    81,    82,    83,
      92,    93,    14,    14,    13,    14,    14,     0,    80,    71,
       3,     6,     7,     8,     9,    14,    15,    16,    17,    18,
      69,    74,    99,   100,   103,   108,   116,    69,    69,    69,
      14,   116,    69,    74,    99,   116,    99,     4,    53,    65,
      66,    67,    68,    70,    20,    84,    85,    84,   101,   102,
     116,    99,    70,    75,    99,    99,    99,    99,    99,    99,
      25,    86,    14,    70,    73,    70,    70,    73,    75,    74,
      76,    14,    21,    30,    31,    32,    33,    34,    35,    37,
      41,    42,    43,    50,    87,    88,    89,    90,    91,    92,
      95,    96,    97,    99,   103,   104,   105,   106,   107,   109,
     112,   117,   118,   116,    72,    84,    25,   101,    74,    99,
      94,   116,    10,    11,    12,    45,    46,    47,    48,    54,
      69,    74,    98,    99,    14,    69,    69,    86,    69,    69,
      69,    69,    69,    69,    26,    87,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    20,    87,    99,
      75,    77,    73,    99,    99,   116,   116,    99,    99,    99,
     116,    99,    99,    92,    30,    99,   103,   103,    99,   116,
      14,    16,   119,   120,   121,   122,   123,    14,   116,    25,
      26,    75,    76,    94,    72,    75,    70,    71,    69,    70,
      70,    70,    70,    74,    70,    65,    70,    70,    70,    70,
      49,    87,    94,    99,    12,    74,    98,    99,    86,   103,
      99,    86,    86,    25,    25,    75,    99,    14,   119,    14,
      51,    44,    77,    75,   116,    99,    71,    70,    38,    39,
     110,   111,    40,   113,   114,   113,    74,    72,    75,    52,
      14,   116,    74,    98,    99,    75,    14,    97,    86,    69,
     116,    36,   115,   113,   115,    75,    99,    74,    14,    52,
      71,    99,    12,    98,    99,    70,   103,    72,    72,    26,
      26,    75,    99,    70,    14,    26,    72,   116,    86,    70,
      87,    87,    74,    75,    86,    70,    99,    86,    99,    86,
      75,   110,   111,    72,    98,    99,    99,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    81,    81,    82,
      83,    84,    84,    84,    85,    85,    86,    87,    87,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    89,    90,    91,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   101,   101,   101,   102,   103,   104,   104,
     105,   106,   107,   107,   108,   109,   109,   109,   110,   110,
     110,   111,   112,   112,   113,   113,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   118,
     118,   118,   118,   119,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     1,     1,     2,    13,
       8,     1,     3,     0,     2,     3,     3,     2,     0,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     1,     1,     2,     3,
       3,     2,     2,     1,     5,     8,     8,    11,     1,     3,
       5,     8,     5,     8,     6,     9,     7,     7,    12,    12,
       2,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     0,     1,     3,     5,     6,
       5,     9,     9,    10,     2,     5,     6,     6,     6,     6,
       5,     2,     8,     8,     2,     0,     4,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     7,     4,     4,
       4,     4,     4,     1,     3,     0,     1,     1,     6,    11,
       4,     7,     3,     5
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
#line 79 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 92 "sintatica.y" /* yacc.c:1646  */
    {
				cout << "\n#include <iostream>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <string>\nusing namespace std;\n\nint main (){" << endl;
				cout << "\n" << "\n" << (yyvsp[0]).traducao << "\n\treturn 0;\n}" << endl;
			}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = " ";
			}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = " ";
			}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "sintatica.y" /* yacc.c:1646  */
    {
				declaracoes_globais += (yyval).traducao;
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "sintatica.y" /* yacc.c:1646  */
    {
				pilha.top().type_return = (yyvsp[-6]).var_tipo;
				pilha.top().name_return = (yyvsp[-2]).label;
				pilha.top().name = (yyvsp[-11]).nome;
				pilha.top().body = (yyvsp[-4]).traducao;
				funs.push_back(pilha.top());
				pilha.pop();
			}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "sintatica.y" /* yacc.c:1646  */
    {
				pilha.top().type_return = "none";
				pilha.top().name_return = "procedure";
				pilha.top().name = (yyvsp[-6]).nome;
				pilha.top().body = (yyvsp[-1]).traducao;
				funs.push_back(pilha.top());
				pilha.pop();
			}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 139 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_param_names();
				set_parameters((yyvsp[-1]).var_tipo, (yyvsp[0]).nome, "none", (yyval).label);
				set_var((yyvsp[-1]).var_tipo, (yyvsp[0]).nome, "none", (yyval).label);
			}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 145 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_param_names();
			}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 151 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
				if(pilha.size() == 2){
						format_declarations(&(yyval));
						/*free_all(&$$);*/
				}
				pilha.pop();
			}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 162 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + "\n" + (yyvsp[0]).traducao;
			}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 188 "sintatica.y" /* yacc.c:1646  */
    {
				if(pilha.top().name == "switch"){
					(yyval).traducao = "\tgoto switch"+to_string(switches) + ";";
				} else{
					(yyval).traducao = "\tgoto loop" + to_string(loops) + ";\n";
				}
			}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 198 "sintatica.y" /* yacc.c:1646  */
    {
				int l = loops;
				l--;
				(yyval).traducao = "\tgoto loop" + to_string(l) + ";\n";
			}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 206 "sintatica.y" /* yacc.c:1646  */
    {
				for(int i=0; i < first_exestack->map_vars.size(); i++){
					if(first_exestack->map_vars[i].name == (yyvsp[0]).nome){
						(yyval).traducao = "\n\t" + first_exestack->map_vars[i].id + " = " + first_exestack->map_vars[i].value + ";\n";
						break;
					}
					if(i+1 == first_exestack->map_vars.size()) yyerror(in_line() + " Variável global não declarada!");
				}
			}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 218 "sintatica.y" /* yacc.c:1646  */
    {
				if(search_var((yyvsp[-1]).nome)) yyerror(in_line() + " Variável" + (yyvsp[-1]).nome + "já existe");
				if(get_vector((yyvsp[-1]).nome)){
					yyerror(in_line() + " Existe um vetor " + (yyvsp[-1]).nome + " declarado.");
				}
				(yyval).label = create_var_names();
				(yyval).var_tipo = (yyvsp[-2]).var_tipo;
				implicit_return(&(yyval), &(yyvsp[0]));
				set_var((yyvsp[-2]).var_tipo, (yyvsp[-1]).nome, (yyvsp[0]).valor, (yyval).label);
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
			}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 230 "sintatica.y" /* yacc.c:1646  */
    {
				if(search_var((yyvsp[-1]).nome)) yyerror(in_line() + " Variável " + (yyvsp[-1]).nome + " já existe");
				if(get_vector((yyvsp[-1]).nome)){
					yyerror(in_line() + " Existe um vetor " + (yyvsp[-1]).nome + " declarado.");
				}
				(yyval).label = create_var_names();
				(yyval).var_tipo = (yyvsp[-2]).var_tipo;
				implicit_return(&(yyval), &(yyvsp[0]));
				set_var((yyvsp[-2]).var_tipo, (yyvsp[-1]).nome, (yyvsp[0]).valor, (yyval).label);
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[0]).label + ";";
			}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "sintatica.y" /* yacc.c:1646  */
    {
				if(search_var((yyvsp[0]).nome)) yyerror(in_line() + " Variável" + (yyvsp[0]).nome + "já existe");
				if(get_vector((yyvsp[0]).nome)){
					yyerror(in_line() + " Existe um vetor " + (yyvsp[0]).nome + " declarado.");
				}
				(yyval).label = create_var_names();
				set_var((yyvsp[-1]).var_tipo, (yyvsp[0]).nome, " ", (yyval).label);
			}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 251 "sintatica.y" /* yacc.c:1646  */
    {

			}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 258 "sintatica.y" /* yacc.c:1646  */
    {
					error_indextype((yyvsp[-1]).var_tipo);

					(yyval).label = create_vectors_names();
					(yyval).var_tipo = (yyvsp[-4]).var_tipo;

					(yyval).traducao = (yyvsp[-1]).traducao + "\t" + (yyval).label + " = (" + (yyval).var_tipo 
					+ "*)malloc(" + (yyvsp[-1]).label + "*sizeof(" + (yyvsp[-4]).var_tipo + "));\n";

					set_vector((yyval).var_tipo, (yyvsp[-3]).nome, (yyvsp[-1]).label, "0", (yyval).label);
				}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 270 "sintatica.y" /* yacc.c:1646  */
    {
					error_indextype((yyvsp[-4]).var_tipo);
					error_indextype((yyvsp[-1]).var_tipo);

					(yyval).label = create_vectors_names();
					(yyval).var_tipo = (yyvsp[-7]).var_tipo;

					(yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-1]).traducao + "\t" + (yyval).label + " = (" + (yyval).var_tipo 
					+ "*)malloc(" + (yyvsp[-4]).label + "*" + (yyvsp[-1]).label + "*sizeof(" + (yyvsp[-7]).var_tipo + "));\n";

					set_vector((yyval).var_tipo, (yyvsp[-6]).nome, (yyvsp[-4]).label, (yyvsp[-1]).label, (yyval).label);
				}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 283 "sintatica.y" /* yacc.c:1646  */
    {
					error_indextype((yyvsp[-4]).var_tipo);

					(yyval).label = create_vectors_names();
					(yyval).var_tipo = (yyvsp[-7]).var_tipo;

					(yyval).traducao = (yyvsp[-4]).traducao + "\t" + (yyval).label + " = (" + (yyval).var_tipo 
					+ "*)malloc(" + (yyvsp[-4]).label + "*sizeof(" + (yyvsp[-7]).var_tipo + "));\n";

					set_vector((yyval).var_tipo, (yyvsp[-6]).nome, (yyvsp[-4]).label, "0", (yyval).label);

					(yyval).traducao += (yyvsp[-1]).traducao;
					int total = vec_att.size();
					ATR var;

					if(atoi((yyvsp[-4]).valor.c_str()) < vec_att.size()) yyerror(in_line() + " Limite de atribuição ultrapassado!");

					for(int i = 0; i < total; i++){
						var.label = vec_att.back().name;
						var.var_tipo = vec_att.back().type;
						implicit_return(&(yyval),&var);
						(yyval).traducao += "\n" + var.traducao + "\t" + (yyval).label + "[" + to_string(i) + "] = " + var.label + ";";
						vec_att.pop_back();
						var.traducao = "";
					}
					vec_att.clear();

				}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 312 "sintatica.y" /* yacc.c:1646  */
    {
					error_indextype((yyvsp[-7]).var_tipo);
					error_indextype((yyvsp[-4]).var_tipo);

					(yyval).label = create_vectors_names();
					(yyval).var_tipo = (yyvsp[-10]).var_tipo;

					(yyval).traducao = (yyvsp[-7]).traducao + (yyvsp[-4]).traducao + "\t" + (yyval).label + " = (" + (yyval).var_tipo 
					+ "*)malloc(" + (yyvsp[-7]).label + "*" + (yyvsp[-4]).label + "*sizeof(" + (yyvsp[-10]).var_tipo + "));\n";

					set_vector((yyval).var_tipo, (yyvsp[-9]).nome, (yyvsp[-7]).label, (yyvsp[-4]).label, (yyval).label);

					(yyval).traducao += (yyvsp[-1]).traducao;
					int total = vec_att.size();
					int limit = 0;
					ATR var;

					if(atoi((yyvsp[-4]).valor.c_str())*atoi((yyvsp[-7]).valor.c_str()) < vec_att.size()) yyerror(in_line() + " Limite de atribuição ultrapassado!");

					for(int i = 0; i < total && !vec_att.empty(); i++){
						if(i == atoi((yyvsp[-4]).valor.c_str())){
							limit++;
							i = 0;
						}

						var.label = vec_att.back().name;
						var.var_tipo = vec_att.back().type;
						implicit_return(&(yyval),&var);
						(yyval).traducao += "\n" + var.traducao + "\t" + (yyval).label + "[" + to_string(limit) + "*" + (yyvsp[-4]).valor + "+" + to_string(i) + "] = " + var.label + ";";
						vec_att.pop_back();
						var.traducao = "";
					}

					vec_att.clear();
				}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 350 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;
			VAR temp;
			temp.type = (yyvsp[0]).var_tipo;
			temp.name = (yyvsp[0]).label;
			vec_att.push_back(temp);
		}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 358 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
			VAR temp;
			temp.type = (yyvsp[-2]).var_tipo;
			temp.name = (yyvsp[-2]).label;
			vec_att.push_back(temp);
		}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 368 "sintatica.y" /* yacc.c:1646  */
    {
								error_indextype((yyvsp[-1]).var_tipo);
								VECTORS* temp = get_vector((yyvsp[-4]).nome);

								if(!temp){
									yyerror(in_line() + "Vetor " + (yyvsp[-4]).nome + " não existe!");
								} else if (temp->column != "0"){
									yyerror(in_line() + "Vetor não encontrado");
								}

								(yyval).label = temp->id + "[" + temp->row + "]";
								(yyval).var_tipo = temp->type;

								string jump = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" <<endl;";

								string condition = "\n\tif(" + (yyvsp[-2]).label + "<" + temp->row + ") goto " 
								+ jump + ";\n" + error_msg + "\n\texit(1);\n";

								implicit_return(&(yyval), &(yyvsp[0]));

								(yyval).traducao += (yyvsp[-2]).traducao + (yyvsp[0]).traducao + condition + "\n\t" + jump 
								+ ":\n\t" + temp->id + "[" + (yyvsp[-2]).label + "] = " + (yyvsp[0]).label + ";\n";

							}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 394 "sintatica.y" /* yacc.c:1646  */
    {
								error_indextype((yyvsp[-4]).var_tipo);
								error_indextype((yyvsp[-1]).var_tipo);
								VECTORS* temp = get_matrix((yyvsp[-7]).nome);

								if(!temp){
									yyerror(in_line() + "Matriz " + (yyvsp[-7]).nome + " não existe!");
								}  else if (temp->column == "0"){
									yyerror(in_line() + "Matriz não encontrada");
								}

								(yyval).label = temp->id + "[" + (yyvsp[-5]).label + "*" + temp->column + "+" + (yyvsp[-2]).label + "]";
								(yyval).var_tipo = temp->type;

								string jump1 = create_jump_names();
								string jump2 = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\"<<endl;";

								string condition = "\n\tif(" + (yyvsp[-5]).label + "<" + temp->row + ") goto " 
								+ jump1 + ";\n" + error_msg + "\n\texit(1);\n";

								condition += "\n\t" + jump1 + ":\n\tif(" + (yyvsp[-2]).label + "<" + temp->column + ") goto " 
								+ jump2 + ";\n" + error_msg + "\n\texit(1);\n";

								implicit_return(&(yyval), &(yyvsp[-3]));

								(yyval).traducao += (yyvsp[-5]).traducao + (yyvsp[-2]).traducao + (yyvsp[0]).traducao + condition + "\n\t" + jump2 
								+ ":\n\t" + (yyval).label + " = " + (yyvsp[0]).label + ";\n";

							}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 425 "sintatica.y" /* yacc.c:1646  */
    {
								error_indextype((yyvsp[-1]).var_tipo);
								VECTORS* temp = get_vector((yyvsp[-4]).nome);

								if(!temp){
									yyerror(in_line() + "Vetor " + (yyvsp[-4]).nome + " não existe!");
								} else if (temp->column != "0"){
									yyerror(in_line() + "Vetor não encontrado");
								}

								(yyval).label = temp->id + "[" + temp->row + "]";
								(yyval).var_tipo = temp->type;

								string jump = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" <<endl;";

								string condition = "\n\tif(" + (yyvsp[-2]).label + "<" + temp->row + ") goto " 
								+ jump + ";\n" + error_msg + "\n\texit(1);\n";

								implicit_return(&(yyval), &(yyvsp[0]));

								(yyval).traducao += (yyvsp[-2]).traducao + (yyvsp[0]).traducao + condition + "\n\t" + jump 
								+ ":\n\t" + temp->id + "[" + (yyvsp[-2]).label + "] = " + temp->id + "[" + (yyvsp[-2]).label + "]" + (yyvsp[0]).op + (yyvsp[0]).label + ";\n";
							}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 450 "sintatica.y" /* yacc.c:1646  */
    {
								error_indextype((yyvsp[-4]).var_tipo);
								error_indextype((yyvsp[-1]).var_tipo);
								VECTORS* temp = get_matrix((yyvsp[-7]).nome);

								if(!temp){
									yyerror(in_line() + "Matriz " + (yyvsp[-7]).nome + " não existe!");
								}  else if (temp->column == "0"){
									yyerror(in_line() + "Matriz não encontrada");
								}

								(yyval).label = temp->id + "[" + (yyvsp[-5]).label + "*" + temp->column + "+" + (yyvsp[-2]).label + "]";
								(yyval).var_tipo = temp->type;

								string jump1 = create_jump_names();
								string jump2 = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\"<<endl;";

								string condition = "\n\tif(" + (yyvsp[-5]).label + "<" + temp->row + ") goto " 
								+ jump1 + ";\n" + error_msg + "\n\texit(1);\n";

								condition += "\n\t" + jump1 + ":\n\tif(" + (yyvsp[-2]).label + "<" + temp->column + ") goto " 
								+ jump2 + ";\n" + error_msg + "\n\texit(1);\n";

								implicit_return(&(yyval), &(yyvsp[-3]));

								(yyval).traducao += (yyvsp[-5]).traducao + (yyvsp[-2]).traducao + (yyvsp[0]).traducao + condition + "\n\t" + jump2 
								+ ":\n\t" + (yyval).label + " = " + (yyval).label + (yyvsp[0]).op + (yyvsp[0]).label + ";\n";
							}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 480 "sintatica.y" /* yacc.c:1646  */
    {
								if(!get_vector((yyvsp[-5]).nome)){
									yyerror(in_line() + "Vetor não existe");
								}

								if(!get_var((yyvsp[0]).nome) && !get_vector((yyvsp[0]).nome) && !get_matrix((yyvsp[0]).nome)){
									yyerror(in_line() + "A operação de inversão somente é permitida com variáveis");
								}

								if(get_vector((yyvsp[-5]).nome)->type != (yyvsp[0]).var_tipo){
									yyerror(in_line() + "As variáveis devem ser da mesma aridade para essa operação");
								}

								string jump = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" <<endl;";

								string condition = "\n\tif(" + (yyvsp[-3]).label + "<" + get_vector((yyvsp[-5]).nome)->row + ") goto " 
								+ jump + ";\n" + error_msg + "\n\texit(1);\n";

								(yyval).label = get_vector((yyvsp[-5]).nome)->id + "[" + (yyvsp[-3]).label + "]";

								string box = create_temp_names();
								set_var((yyvsp[-3]).var_tipo, "", "", box);
								(yyval).traducao = (yyvsp[-3]).traducao + condition + "\n\t" + jump + ":\n\t" + box + " = " + (yyvsp[0]).label + ";\n\t"
								+ (yyvsp[0]).label + " = " + (yyval).label + ";\n\t"
								+ (yyval).label + " = " + box + ";";
							}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 508 "sintatica.y" /* yacc.c:1646  */
    {
								if(!get_matrix((yyvsp[-8]).nome)){
									yyerror(in_line() + "Vetor não existe");
								}

								if(!get_var((yyvsp[0]).nome) && !get_vector((yyvsp[0]).nome) && !get_matrix((yyvsp[0]).nome)){
									yyerror(in_line() + "A operação de inversão somente é permitida com variáveis");
								}

								if(get_matrix((yyvsp[-8]).nome)->type != (yyvsp[0]).var_tipo){
									yyerror(in_line() + "As variáveis devem ser da mesma aridade para essa operação");
								}

								string jump1 = create_jump_names();
								string jump2 = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\"<<endl;";

								string condition = "\n\tif(" + (yyvsp[-6]).label + "<" + get_matrix((yyvsp[-8]).nome)->row + ") goto " 
								+ jump1 + ";\n" + error_msg + "\n\texit(1);\n";

								condition += "\n\t" + jump1 + ":\n\tif(" + (yyvsp[-3]).label + "<" + get_matrix((yyvsp[-8]).nome)->column + ") goto " 
								+ jump2 + ";\n" + error_msg + "\n\texit(1);\n";

								(yyval).label = get_matrix((yyvsp[-8]).nome)->id + "[" + (yyvsp[-6]).label + "*" + get_matrix((yyvsp[-8]).nome)->column + "+" + (yyvsp[-3]).label + "]";
								(yyval).var_tipo = get_matrix((yyvsp[-8]).nome)->type;

								string box = create_temp_names();
								set_var((yyvsp[-6]).var_tipo, "", "", box);
								(yyval).traducao = (yyvsp[-6]).traducao + (yyvsp[-3]).traducao + condition + "\n\t" + jump2 + ":\n\t" 
								+ box + " = " + (yyvsp[0]).label + ";\n\t"
								+ (yyvsp[0]).label + " = " + (yyval).label + ";\n\t"
								+ (yyval).label + " = " + box + ";";
							}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 544 "sintatica.y" /* yacc.c:1646  */
    {
			error_indextype((yyvsp[-4]).var_tipo);
			error_indextype((yyvsp[-2]).var_tipo);
			VECTORS* temp = get_vector((yyvsp[-6]).nome);

			if(!temp){
				yyerror(in_line() + "Vetor " + (yyvsp[-6]).nome + " não existe!");
			} else if (temp->column != "0"){
				yyerror(in_line() + "Você procura uma tabela seu malakoi");
			}

			(yyval).label = temp->id + "[" + temp->row + "]";
			(yyval).var_tipo = temp->type;

			string jump1 = create_jump_names();
			string jump2 = create_jump_names();
			string jump3 = create_jump_names();
			string control = create_temp_names();
			set_var("int", "", "", control);
			string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" <<endl;";

			string condition1 = "\n\tif(" + (yyvsp[-4]).label + "<" + temp->row + ") goto " 
			+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":";

			string condition2 = "\n\tif(" + (yyvsp[-2]).label + ">" + (yyvsp[-4]).label + ") goto " 
			+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":";

			string condition3 = "\n\tif(" + (yyvsp[-2]).label + "<" + temp->row + ") goto " 
			+ jump3 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump3 + ":\n";

			(yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-2]).traducao + condition1 + condition2 + condition3;

			string l1 = create_loop_names();
			string l2 = create_loop_names();

			string loop = "\n\t" + control + " = " + (yyvsp[-4]).label + ";\n\t" + l1 + ":\n\tif(" +
			control + " == " + (yyvsp[-2]).label + ") goto " +l2+ ";\n\t"
			+ temp->id + "[" + control + "] = " + temp->id + "[" + control + "]" + (yyvsp[0]).op + (yyvsp[0]).label + ";\n\t" + control + " = " + control + "+ 1;\n\tgoto " + l1 + ";\n\t" + l2 + ":\n\t";

			(yyval).traducao += (yyvsp[0]).traducao + loop;

		}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 587 "sintatica.y" /* yacc.c:1646  */
    {
			error_indextype((yyvsp[-4]).var_tipo);
			error_indextype((yyvsp[-2]).var_tipo);
			VECTORS* temp = get_vector((yyvsp[-6]).nome);

			if(!temp){
				yyerror(in_line() + "Vetor " + (yyvsp[-6]).nome + " não existe!");
			} else if (temp->column != "0"){
				yyerror(in_line() + "Você procura uma tabela seu malakoi");
			}

			(yyval).label = temp->id + "[" + temp->row + "]";
			(yyval).var_tipo = temp->type;

			string jump1 = create_jump_names();
			string jump2 = create_jump_names();
			string jump3 = create_jump_names();
			string control = create_temp_names();
			set_var("int", "", "", control);
			string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" <<endl;";

			string condition1 = "\n\tif(" + (yyvsp[-4]).label + "<" + temp->row + ") goto " 
			+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":";

			string condition2 = "\n\tif(" + (yyvsp[-2]).label + ">" + (yyvsp[-4]).label + ") goto " 
			+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":";

			string condition3 = "\n\tif(" + (yyvsp[-2]).label + "<" + temp->row + ") goto " 
			+ jump3 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump3 + ":\n";

			(yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-2]).traducao + condition1 + condition2 + condition3;

			string l1 = create_loop_names();
			string l2 = create_loop_names();

			string loop = "\n\t" + control + " = " + (yyvsp[-4]).label + ";\n\t" + l1 + ":\n\tif(" +
			control + " == " + (yyvsp[-2]).label + ") goto " +l2+ ";\n\t"
			+ temp->id + "[" + control + "] = " + (yyvsp[0]).label + ";\n\t" + control + " = " + control 
			+ "+ 1;\n\tgoto " + l1 + ";\n\t" + l2 + ":\n\t";

			(yyval).traducao += (yyvsp[0]).traducao + loop;
		}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 630 "sintatica.y" /* yacc.c:1646  */
    {
			error_indextype((yyvsp[-9]).var_tipo);
			error_indextype((yyvsp[-7]).var_tipo);
			error_indextype((yyvsp[-4]).var_tipo);
			error_indextype((yyvsp[-2]).var_tipo);
			VECTORS* temp = get_matrix((yyvsp[-11]).nome);

			if(!temp) yyerror(in_line() + "Matriz " + (yyvsp[-11]).nome + " não existe!");

			string jump1 = create_jump_names();
			string jump2 = create_jump_names();
			string jump3 = create_jump_names();
			string jump4 = create_jump_names();
			string jump5 = create_jump_names();
			string jump6 = create_jump_names();

			string control1 = create_temp_names();
			string control2 = create_temp_names();
			set_var("int", "", "", control1);
			set_var("int", "", "", control2);

			string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\" <<endl;";

			string condition1 = "\n\tif(" + (yyvsp[-9]).label + "<" + temp->row + ") goto " 
			+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":";

			string condition2 = "\n\tif(" + (yyvsp[-7]).label + ">" + (yyvsp[-9]).label + ") goto " 
			+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":";

			string condition3 = "\n\tif(" + (yyvsp[-7]).label + "<" + temp->row + ") goto " 
			+ jump3 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump3 + ":\n";

			string condition4 = "\n\tif(" + (yyvsp[-4]).label + "<" + temp->column + ") goto " 
			+ jump4 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump4 + ":";

			string condition5 = "\n\tif(" + (yyvsp[-2]).label + ">" + (yyvsp[-4]).label + ") goto " 
			+ jump5 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump5 + ":";

			string condition6 = "\n\tif(" + (yyvsp[-2]).label + "<" + temp->column + ") goto " 
			+ jump6 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump6 + ":\n";

			string l1 = create_loop_names();
			string l2 = create_loop_names();
			string l3 = create_loop_names();

			(yyval).traducao = (yyvsp[-9]).traducao + (yyvsp[-7]).traducao + (yyvsp[-4]).traducao + (yyvsp[-2]).traducao
			+ condition1 + condition2 + condition3 + condition4 + condition5 + condition6;

			(yyval).label = temp->id + "[" + control2 + "*" + temp->column + "+" + control1 + "]"; 

			(yyval).traducao += (yyvsp[0]).traducao
			+ "\n\t" + control1 + " = " + (yyvsp[-4]).label + ";\n\t"
			+ control2 + " = " + (yyvsp[-9]).label + ";\n\t"
			+ l1 + ":\n\tif(" + control2 + "<=" + (yyvsp[-7]).label + ") goto " + l2 + ";\n\t"
			+ control1 + " = " + control1 + " + 1;\n\t"
			+ control2 + " = " + (yyvsp[-9]).label + ";\n\t"
			+ l2 + ":\n\tif(" + control1 + " == " + (yyvsp[-2]).label + ") goto " + l3 + ";\n\t"
			+ (yyval).label + " = " + (yyval).label + (yyvsp[0]).op + (yyvsp[0]).label + ";\n\t" + control2 + " = " + control2 + " + 1;\n\t"
			+ "goto " + l1 + ";\n\t" + l3 + ":";
		}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 691 "sintatica.y" /* yacc.c:1646  */
    {
			error_indextype((yyvsp[-9]).var_tipo);
			error_indextype((yyvsp[-7]).var_tipo);
			error_indextype((yyvsp[-4]).var_tipo);
			error_indextype((yyvsp[-2]).var_tipo);
			VECTORS* temp = get_matrix((yyvsp[-11]).nome);

			if(!temp) yyerror(in_line() + "Matriz " + (yyvsp[-11]).nome + " não existe!");

			string jump1 = create_jump_names();
			string jump2 = create_jump_names();
			string jump3 = create_jump_names();
			string jump4 = create_jump_names();
			string jump5 = create_jump_names();
			string jump6 = create_jump_names();

			string control1 = create_temp_names();
			string control2 = create_temp_names();
			set_var("int", "", "", control1);
			set_var("int", "", "", control2);

			string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\" <<endl;";

			string condition1 = "\n\tif(" + (yyvsp[-9]).label + "<" + temp->row + ") goto " 
			+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":";

			string condition2 = "\n\tif(" + (yyvsp[-7]).label + ">" + (yyvsp[-9]).label + ") goto " 
			+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":";

			string condition3 = "\n\tif(" + (yyvsp[-7]).label + "<" + temp->row + ") goto " 
			+ jump3 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump3 + ":\n";

			string condition4 = "\n\tif(" + (yyvsp[-4]).label + "<" + temp->column + ") goto " 
			+ jump4 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump4 + ":";

			string condition5 = "\n\tif(" + (yyvsp[-2]).label + ">" + (yyvsp[-4]).label + ") goto " 
			+ jump5 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump5 + ":";

			string condition6 = "\n\tif(" + (yyvsp[-2]).label + "<" + temp->column + ") goto " 
			+ jump6 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump6 + ":\n";

			string l1 = create_loop_names();
			string l2 = create_loop_names();
			string l3 = create_loop_names();

			(yyval).traducao = (yyvsp[-9]).traducao + (yyvsp[-7]).traducao + (yyvsp[-4]).traducao + (yyvsp[-2]).traducao
			+ condition1 + condition2 + condition3 + condition4 + condition5 + condition6;

			(yyval).label = temp->id + "[" + control2 + "*" + temp->column + "+" + control1 + "]"; 

			(yyval).traducao += (yyvsp[0]).traducao
			+ "\n\t" + control1 + " = " + (yyvsp[-4]).label + ";\n\t"
			+ control2 + " = " + (yyvsp[-9]).label + ";\n\t"
			+ l1 + ":\n\tif(" + control2 + "<=" + (yyvsp[-7]).label + ") goto " + l2 + ";\n\t"
			+ control1 + " = " + control1 + " + 1;\n\t"
			+ control2 + " = " + (yyvsp[-9]).label + ";\n\t"
			+ l2 + ":\n\tif(" + control1 + " == " + (yyvsp[-2]).label + ") goto " + l3 + ";\n\t"
			+ (yyval).label + " = " + (yyvsp[0]).label + ";\n\t" + control2 + " = " + control2 + " + 1;\n\t"
			+ "goto " + l1 + ";\n\t" + l3 + ":";
		}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 754 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-1]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[0]).var_tipo, (yyvsp[-1]).nome, (yyvsp[0]).valor, (yyval).label);
				}
				(yyval).var_tipo = get_var((yyvsp[-1]).nome)->type;
				implicit_return(&(yyval), &(yyvsp[0]));
				(yyval).traducao = (yyvsp[0]).traducao + "\n \t" + get_var((yyvsp[-1]).nome)->id + " = " + (yyvsp[0]).label + ";\n";
				(yyvsp[0]).traducao = " ";
			}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 765 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-2]).nome)){
					yyerror(in_line() + "Variável não existe");
				}

				if(!get_var((yyvsp[0]).nome) && !get_vector((yyvsp[0]).nome) && !get_matrix((yyvsp[0]).nome)){
					 yyerror(in_line() + "A operação de inversão somente é permitida com variáveis");
				}

				if(get_var((yyvsp[-2]).nome)->type != (yyvsp[0]).var_tipo){
					yyerror(in_line() + "As variáveis devem ser da mesma aridade para essa operação");
				}

				string box = create_temp_names();
				set_var((yyvsp[0]).var_tipo, "", "", box);
				(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + box + " = " + (yyvsp[0]).label + ";\n\t"
				+ (yyvsp[0]).label + " = " + get_var((yyvsp[-2]).nome)->id + ";\n\t"
				+ get_var((yyvsp[-2]).nome)->id + " = " + box + ";";
			}
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 785 "sintatica.y" /* yacc.c:1646  */
    {
				VAR* temp = get_var((yyvsp[-2]).nome);

				if(!temp) yyerror(in_line() + "Variável não existe");

				if((yyvsp[0]).valor == "0"){
					(yyval).traducao = "\n\t" + temp->id + " = " + " 1;";
				} else if((yyvsp[0]).valor == "1"){
					(yyval).traducao = "\n\t" + temp->id + " = " + temp->id + ";";
				} else{
					string l1 = create_loop_names();
					string control = create_temp_names();
					string aux = create_temp_names();
					set_var("int", "", "", control);
					set_var(temp->type, "", "", aux);

					string s1 = (yyvsp[0]).traducao + "\n\t" + control + " = " + " 1;\n\t";
					string s2 = aux + " = " + temp->id + ";";
					string s3 = "\n\t" + l1 + ":\n\t";
					string s4 = temp->id + " = " + temp->id + " * " + aux + ";\n\t";
					string s5 = control + " = " + control + "+ 1;\n\t";
					string s6 = "if(" + control + "<" + (yyvsp[0]).label + ") goto " + l1+";";

					(yyval).traducao = s1 + s2 + s3 + s4 + s5 + s6;
				}
			}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 812 "sintatica.y" /* yacc.c:1646  */
    {
				string loop = create_loop_names();
				string control = create_temp_names();

				VAR* temp = get_var((yyvsp[-1]).nome);

				(yyval).label = temp->id;
				(yyval).var_tipo = temp->type;

				if(!temp){
					yyerror(in_line() + " Variável não existe, operação requer que já exista");
				}

				if((yyval).var_tipo != "int"){
					yyerror(in_line() + "Operação permitida somente com inteiros!");
				}

				set_var("int", "", "0", control);

				(yyval).traducao = "\n\t" + control + " = " + (yyval).label + ";\n";
				(yyval).traducao += "\t" + loop + ":\n\t" + control + " = " + control + " - 1;\n\t"
				+ (yyval).label + " *= " + control + ";\n\t" + "if(" + control + " != 1) goto " + loop + ";\n";
			}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 836 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[-1]).nome)){
					(yyval).label = create_var_names();
					set_var((yyvsp[0]).var_tipo, (yyvsp[-1]).nome, (yyvsp[0]).valor, (yyval).label);
				}
				(yyval).var_tipo = get_var((yyvsp[-1]).nome)->type;
				implicit_return(&(yyval), &(yyvsp[0]));
				(yyval).traducao = (yyvsp[0]).traducao + "\n \t" + get_var((yyvsp[-1]).nome)->id + " = " + get_var((yyvsp[-1]).nome)->id + (yyvsp[0]).op + (yyvsp[0]).label + ";\n";
				(yyvsp[0]).traducao = " ";
			}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 849 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
							(yyval).op = (yyvsp[-1]).op;
						}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 854 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
							(yyval).op = (yyvsp[-1]).op;
						}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 859 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
							(yyval).op = (yyvsp[-1]).op;
						}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 864 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
							(yyval).op = (yyvsp[-1]).op;	
						}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 869 "sintatica.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
							(yyval).op = (yyvsp[-1]).op;
						}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 876 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[-1]);
			}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 880 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo == "string" || (yyvsp[0]).var_tipo == "string"){
					(yyval).label = create_temp_names();
					(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
					implicit_string(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
					set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				} else{
					if((yyvsp[-2]).var_tipo == "bool" || (yyvsp[0]).var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
					(yyval).op = "+";
					(yyval).label = create_temp_names();
					(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
					implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
					set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
					(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '+' + (yyvsp[0]).label + ";\n";
					(yyval).valor = (yyval).label;
				}
			}
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 898 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo == "bool" || (yyvsp[0]).var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
				(yyval).op = "-";
				(yyval).label = create_temp_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '-' + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyval).label;
			}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 909 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo == "bool" || (yyvsp[0]).var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
				(yyval).op = "*";
				(yyval).label = create_temp_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '*' + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyval).label;
			}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 920 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo == "bool" || (yyvsp[0]).var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
				(yyval).op = "/";
				(yyval).label = create_temp_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '/' + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyval).label;
			}
#line 2585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 931 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo != "int" || (yyvsp[0]).var_tipo != "int") yyerror(in_line () + "Operação válida somente com inteiros");
				(yyval).op = "%";
				(yyval).label = create_temp_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + '%' + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyval).label;
			}
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 942 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[0]).nome)) yyerror(in_line() + "Variável " + (yyvsp[0]).nome +  "não existe");
				if(get_var((yyvsp[0]).nome)->type == "bool" || get_var((yyvsp[0]).nome)->type == "char") yyerror(in_line () + "Operação só permitida com float e int");
				(yyval).label = create_temp_names();
				(yyval).var_tipo = get_var((yyvsp[0]).nome)->type;
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao = "\t" + (yyval).label + " = "+ get_var((yyvsp[0]).nome)->id + "+1;";
			}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 951 "sintatica.y" /* yacc.c:1646  */
    {
				if(!get_var((yyvsp[0]).nome)) yyerror(in_line() + "Variável " + (yyvsp[0]).nome +  "não existe");
				if(get_var((yyvsp[0]).nome)->type == "bool" || get_var((yyvsp[0]).nome)->type == "char") yyerror(in_line () + "Operação só permitida com float e int");
				(yyval).label = create_temp_names();
				(yyval).var_tipo = get_var((yyvsp[0]).nome)->type;
				set_var((yyval).var_tipo, "temp", (yyval).valor, (yyval).label);
				(yyval).traducao = "\t" + (yyval).label + " = "+ get_var((yyvsp[0]).nome)->id + "-1;";
			}
#line 2626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 960 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 964 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 968 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 972 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 978 "sintatica.y" /* yacc.c:1646  */
    {
				FUN* function = get_function((yyvsp[-3]).nome);

				if(!function){
					yyerror(in_line() + " A função requisitada não existe ou está declarada abaixo do escopo.");
				}

				set_vars_functions(function);
				(yyval).var_tipo = function->type_return;

				if(params.size() < function->map_parameters.size()){
					yyerror(in_line() + " Passagem de parâmetros menor do que o esperado");
				}

				if(params.size() > function->map_parameters.size()){
					yyerror(in_line() + " Passagem de parâmetros maior do que o esperado");
				}

				int j = params.size()-1;

				if((yyval).var_tipo == "none"){
					for(int i=0; i<params.size(); i++){
						ATR passagem;
						ATR parametro;

						passagem.label = params[j].id;
						passagem.var_tipo = params[j].type;
						passagem.nome = params[j].name;
						parametro.label = function->map_parameters[i].id;
						parametro.var_tipo = function->map_parameters[i].type;

						if(!get_var(passagem.nome)) (yyval).traducao += "\n\t" + passagem.label + " = " + params[j].value + ";\n";
						implicit_return(&parametro, &passagem);

						(yyval).traducao += passagem.traducao;
						(yyval).traducao += "\n\t" + parametro.label + " = " + passagem.label + ";\n";
						j--;
					}

					(yyval).traducao += function->body;
					j = params.size()-1;

					for(int i=0; i<params.size(); i++){
						ATR passagem;
						ATR parametro;

						passagem.label = params[j].id;
						passagem.var_tipo = params[j].type;
						passagem.nome = params[j].name;
						parametro.label = function->map_parameters[i].id;
						parametro.var_tipo = function->map_parameters[i].type;

						if(!get_var(passagem.nome)) (yyval).traducao += "\n\t" + passagem.label + " = " + params[j].value + ";\n";
						implicit_return(&passagem, &parametro);

						(yyval).traducao += parametro.traducao;
						(yyval).traducao += "\n\t" + passagem.label + " = " + parametro.label + ";\n";
						j--;
					}
					
				} else{
					(yyval).var_tipo = function->type_return;
					(yyval).label = function->name_return;

					for(int i=0; i<params.size(); i++){
						ATR passagem;
						ATR parametro;

						passagem.label = params[j].id;
						passagem.var_tipo = params[j].type;
						passagem.nome = params[j].name;
						parametro.label = function->map_parameters[i].id;
						parametro.var_tipo = function->map_parameters[i].type;

						if(!get_var(passagem.nome)){
							(yyval).traducao += "\n\t" + passagem.label + " = " + params[j].value + ";\n";
						} 
						
						implicit_return(&parametro, &passagem);

						(yyval).traducao += passagem.traducao;
						(yyval).traducao += "\n\t" + parametro.label + " = " + passagem.label + ";\n";
						j--;
					}
					(yyval).traducao += function->body;
				}

				params.clear();
			}
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1070 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				VAR temp;
				temp.value = (yyvsp[0]).valor;
				temp.type = (yyvsp[0]).var_tipo;
				temp.id = (yyvsp[0]).label;
				temp.name = (yyvsp[0]).nome;
				params.push_back(temp);
			}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1080 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao;
				VAR temp;
				temp.value = (yyvsp[-2]).valor;
				temp.type = (yyvsp[-2]).var_tipo;
				temp.id = (yyvsp[-2]).label;
				temp.name = (yyvsp[-2]).nome;
				params.push_back(temp);
			}
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1093 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1099 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_temp_names();
				(yyval).op = (yyvsp[-1]).op;
				(yyval).var_tipo = "bool";
				(yyval).traducao = (yyvsp[-2]).traducao + "\n" + (yyvsp[0]).traducao + "\n";
				implicit_cast(&(yyvsp[-2]), &(yyvsp[0]), &(yyval));
				set_var(format_boolean(&(yyval)), "temp", (yyval).valor, (yyval).label);
				(yyval).traducao += "\t" + (yyval).label + " = " + (yyvsp[-2]).label + (yyvsp[-1]).op + (yyvsp[0]).label + ";\n";
				(yyval).valor = (yyvsp[-2]).valor + (yyvsp[-1]).op + (yyvsp[0]).valor;
			}
#line 2803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1112 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo != "bool") yyerror(in_line () + "A condição do While só permite booleano como retorno");
				string l_end = create_loop_names();
				(yyval).traducao = "\t" + (yyvsp[-4]).label + ":" + "\n" + (yyvsp[-2]).traducao + "\n\tif(!" + (yyvsp[-2]).label + ") goto " + l_end + ";\n" + (yyvsp[0]).traducao + "\tgoto "+ (yyvsp[-4]).label + ";\n\t" + l_end + ":\n\t";
			}
#line 2813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1118 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).var_tipo != "bool") yyerror(in_line () + "A condição do While só permite booleano como retorno");
				(yyval).traducao = "\t" + (yyvsp[-5]).label + ":" + "\n" + (yyvsp[-4]).traducao + (yyvsp[-1]).traducao + "\tif(" + (yyvsp[-1]).label + ") goto " + (yyvsp[-5]).label + ";\n";
				pilha.pop();
			}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1126 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).var_tipo != "bool") yyerror(in_line () + "A condição do Until só permite booleano como retorno");
				string l_end = create_loop_names();
				(yyval).traducao = "\t" + (yyvsp[-4]).label + ":" + "\n" + (yyvsp[-2]).traducao + "\n\tif(" + (yyvsp[-2]).label + ") goto " + l_end + ";\n" + (yyvsp[0]).traducao + "\tgoto "+ (yyvsp[-4]).label + ";\n\t" + l_end + ":\n\t";
			}
#line 2833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1134 "sintatica.y" /* yacc.c:1646  */
    {
				string l_end = create_loop_names();
				if((yyvsp[-4]).traducao == ""){
					(yyval).traducao = (yyvsp[-6]).traducao + "\n\t" + (yyvsp[-8]).label + ":\n\t" + (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "goto " + (yyvsp[-8]).label + ";\n\t" + l_end + ":\n\t";
				}else{
					(yyval).traducao = (yyvsp[-6]).traducao + "\n\t" + (yyvsp[-8]).label + ":\n\t" + (yyvsp[-4]).traducao + "\tif(!" + (yyvsp[-4]).label + ") goto " + l_end + ";\n" + (yyvsp[0]).traducao + (yyvsp[-2]).traducao + "\tgoto " + (yyvsp[-8]).label + ";\n\t" + l_end + ":\n\t";
				}
			}
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1145 "sintatica.y" /* yacc.c:1646  */
    {
				VECTORS* temp = get_vector((yyvsp[-4]).nome);
				
				if(!temp){
					temp = get_matrix((yyvsp[-4]).nome);
				}
			
				if(!temp) yyerror(in_line() + "Estrutura não existe");

				string control = create_temp_names();
				string total_loop = create_temp_names();

				(yyvsp[-2]).label = create_temp_names();

				set_var("int", "", "", control);
				set_var("int", "", "", total_loop);
				set_var(temp->type, (yyvsp[-2]).nome, "", (yyvsp[-2]).label);

				if(temp->column == "0"){
					(yyval).traducao = "\n\t" + total_loop + " = " + temp->row + ";\n";
				}else{
					(yyval).traducao = "\n\t" + total_loop + " = " + temp->row + " * " + temp->column + ";\n";
				}

				string jump1 = create_jump_names();
				string jump2 = create_jump_names();
				
				(yyval).traducao += (yyvsp[-6]).traducao + "\n\t" + control + " = " + "0;\n\t" + jump1 + ":\n\t" + (yyvsp[-2]).label + " = " + temp->id + '[' + control
				+ "];\n\t" + control + " = " + control + " + 1;\n\t" + "if(" + (yyvsp[-2]).label + " != " + (yyvsp[-6]).label + ") goto " + jump2 + ";\n\t" 
				+ "\n" + (yyvsp[0]).traducao + "\n\t" + jump2 + ":\n\t" + "if(" + control + "<" + total_loop + ") goto " + jump1 + ";\n";
			}
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1177 "sintatica.y" /* yacc.c:1646  */
    {
				VECTORS* temp = get_vector((yyvsp[-4]).nome);

				if(!temp){
					temp = get_matrix((yyvsp[-4]).nome);
				}

				if(!temp) yyerror(in_line() + "Estrutura não existe");

				string control = create_temp_names();
				string total_loop = create_temp_names();
				(yyvsp[-2]).label = create_temp_names();

				set_var("int", "", "", control);
				set_var("int", "", "", total_loop);
				set_var(temp->type, (yyvsp[-2]).nome, "", (yyvsp[-2]).label);

				string jump1 = create_jump_names();
				string jump2 = create_jump_names();

				(yyval).traducao = "\n\t" + total_loop + " = " + temp->row + " + " + temp->column + ";\n";
				(yyval).traducao += (yyvsp[-7]).traducao + "\n\t" + control + " = " + "0;\n\t" + jump1 + ":\n\t" + (yyvsp[-2]).label + " = " + temp->id + '[' + control
				+ "];\n\t" + control + " = " + control + " + 1;\n\t" + "if(" + (yyvsp[-2]).label + " == " + (yyvsp[-7]).label + ") goto " + jump2 + " ;\n\t" 
				+ "\n" + (yyvsp[0]).traducao + "\n\t " + jump2 + " :\n\t" + "if(" + control + "<" + total_loop + ") goto " + jump1 + " ;\n";
			}
#line 2912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1205 "sintatica.y" /* yacc.c:1646  */
    {
				if(search_var((yyvsp[0]).nome)){
					(yyval).traducao = (yyvsp[0]).traducao;
					explicit_cast(&(yyvsp[0]), (yyvsp[-1]).cast);
					(yyval).traducao += (yyvsp[0]).traducao;
					(yyval).label = (yyvsp[0]).label;
					(yyval).var_tipo = (yyvsp[0]).var_tipo;
				}else{
					(yyval).traducao = (yyvsp[0]).traducao;
					explicit_cast(&(yyvsp[0]), (yyvsp[-1]).cast);
					(yyval).traducao += (yyvsp[0]).traducao;
					(yyval).label = (yyvsp[0]).label;
					(yyval).var_tipo = (yyvsp[0]).var_tipo;
				}
			}
#line 2932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1223 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_jump_names();
				(yyval).traducao = (yyvsp[-2]).traducao + "\tif(!" + (yyvsp[-2]).label + ") goto " + (yyval).label + ";\n" + (yyvsp[0]).traducao + "\n\t" + "goto global_end;\n\t" + (yyval).label + ":\n";
			}
#line 2941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1228 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_jump_names();
				(yyval).traducao = (yyvsp[-3]).traducao + "\tif(!" + (yyvsp[-3]).label + ") goto " + (yyval).label + ";\n" + (yyvsp[-1]).traducao + "\n\t" + "goto global_end;\n\t" + (yyval).label + ":\n" + (yyvsp[0]).traducao + "\n\t" + "global_end:\n";
			}
#line 2950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1233 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = create_jump_names();
				(yyval).traducao = (yyvsp[-3]).traducao + "\tif(!" + (yyvsp[-3]).label + ") goto " + (yyvsp[0]).label + ";\n" + (yyvsp[-1]).traducao + "\tgoto " + (yyval).label + ";\n\t" + (yyvsp[0]).label + ":\n" + (yyvsp[0]).traducao + "\n\t" + "goto global_end;\n\t" + (yyval).label + ":\n\t" + "global_end:\n";
			}
#line 2959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1240 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = create_jump_names();
					(yyval).traducao = (yyvsp[-3]).traducao + "\tif(!" + (yyvsp[-3]).label + ") goto " + (yyval).label + ";\n" + (yyvsp[-1]).traducao + "\t" + "goto global_end;\n\t" + (yyval).label + ":\n" + (yyvsp[0]).traducao;
				}
#line 2968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1245 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = create_jump_names();
					(yyval).traducao = (yyvsp[-3]).traducao + "\tif(!" + (yyvsp[-3]).label + ") goto " + (yyvsp[0]).label + ";\n" + (yyvsp[-1]).traducao + "\tgoto " + (yyval).label + ";\n\t" + (yyvsp[0]).label + ":\n" + (yyvsp[0]).traducao + "\n\t" + "goto global_end;\n\t" + (yyval).label + ":";
				}
#line 2977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1250 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = create_jump_names();
					(yyval).traducao = (yyvsp[-2]).traducao + "\tif(!" + (yyvsp[-2]).label + ") goto " + (yyval).label + ";\n" + (yyvsp[0]).traducao + "\n\t" + (yyval).label + ":\n";
				}
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1257 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).label = create_jump_names();
					(yyval).traducao = (yyvsp[0]).traducao;
				}
#line 2995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1264 "sintatica.y" /* yacc.c:1646  */
    {
			set_var((yyvsp[-5]).var_tipo, "", (yyvsp[-5]).label, (yyvsp[-7]).label);
			(yyval).label = create_switch_names();
			(yyval).traducao = "\n" + (yyvsp[-5]).traducao + "\n\t" + (yyvsp[-7]).label + " = " + (yyvsp[-5]).label + ";\n\t" 
			+ (yyvsp[-2]).traducao + "\n" + (yyvsp[-1]).traducao + "\t" + (yyval).label + ":\n";
			pilha.pop();
		}
#line 3007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1272 "sintatica.y" /* yacc.c:1646  */
    {
			set_var((yyvsp[-5]).var_tipo, "", (yyvsp[-5]).label, (yyvsp[-7]).label);
			(yyval).label = create_switch_names();
			(yyval).traducao = "\n" + (yyvsp[-5]).traducao + "\n\t" + (yyvsp[-7]).label + " = " + (yyvsp[-5]).label + ";\n\t" 
			+ (yyvsp[-2]).traducao + "\n" + (yyvsp[-1]).traducao + "\t" + (yyval).label + ":\n";
			pilha.pop();
		}
#line 3019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1282 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[-1]).traducao + "\n" + (yyvsp[0]).traducao;
		}
#line 3027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1289 "sintatica.y" /* yacc.c:1646  */
    {
				int swt = switches;
				swt--;
				(yyval).label = create_jump_names();
				string logical = create_temp_names();
				set_var("int", "", "", logical);
				(yyval).traducao = "\n" + (yyvsp[-2]).traducao + "\n\t" + logical + " = " + "switch" + to_string(swt) + " == " + (yyvsp[-2]).label + ";\n\tif(!" 
				+ logical + ") goto " + (yyval).label + ";\n" + (yyvsp[0]).traducao + "\n\t" + (yyval).label + ":\n"; 
				(yyvsp[-2]).traducao = " ";
 			}
#line 3042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1302 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 3050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1309 "sintatica.y" /* yacc.c:1646  */
    {
				VAR* temp = get_var((yyvsp[0]).nome);

				if(!temp){
					yyerror(in_line() + "Variável " + (yyvsp[0]).nome +  " não existe");
				}else{
					(yyval).var_tipo = temp->type;
					(yyval).label = temp->id;
				}
			}
#line 3065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1320 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 3075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1326 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 3085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1332 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 3095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1338 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1344 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 3115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1350 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
				format_variable(&(yyval));
				set_var((yyvsp[0]).var_tipo, "temp", (yyvsp[0]).valor, (yyvsp[0]).label);
			}
#line 3125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1356 "sintatica.y" /* yacc.c:1646  */
    {
				VECTORS* temp = get_vector((yyvsp[-3]).nome);

				if(!temp){
					yyerror(in_line() + "Vetor " + (yyvsp[-3]).nome + " não existe!");
				}

				string jump = create_jump_names();
				string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\";";

				string condition = (yyvsp[-1]).traducao + "\n\tif(" + (yyvsp[-1]).label + "<" + temp->row + ") goto " 
				+ jump + ";\n" + error_msg + "\n\texit(1);\n\t" + jump + ":\n";

				(yyval).label = temp->id + "[" + (yyvsp[-1]).label + "]";
				(yyval).var_tipo = temp->type;
				(yyval).traducao = condition + (yyvsp[-1]).traducao;
			}
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1374 "sintatica.y" /* yacc.c:1646  */
    {
				error_indextype((yyvsp[-3]).var_tipo);
				error_indextype((yyvsp[0]).var_tipo);
				VECTORS* temp = get_matrix((yyvsp[-6]).nome);

				if(!temp){
					yyerror(in_line() + "Matriz " + (yyvsp[-6]).nome + " não existe!");
				}

				string jump1 = create_jump_names();
				string jump2 = create_jump_names();
				string error_msg = "\n\tcout << " + in_line() + "<< \"limite da Matriz excedido\" <<endl;";

				string condition = (yyvsp[-4]).traducao + "\n\tif(" + (yyvsp[-4]).label + "<" + temp->row + ") goto "
				+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":\n";

				condition += (yyvsp[-1]).traducao + "\n\tif(" + (yyvsp[-4]).label + "<" + temp->row + ") goto "
				+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":\n";

				(yyval).label = temp->id + "[" + (yyvsp[-4]).label + "*" + temp->column + "+" + (yyvsp[-1]).label + "]";
				(yyval).var_tipo = temp->type;
				(yyval).traducao = condition + (yyvsp[-4]).traducao + (yyvsp[-1]).traducao;
			}
#line 3175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1400 "sintatica.y" /* yacc.c:1646  */
    {
				if(!search_var((yyvsp[-1]).nome)){
					yyerror(in_line () + "Variável não existe");
				}

				VAR* temp = get_var((yyvsp[-1]).nome);

				if(temp->type != "string"){
					(yyval).label = create_temp_names();
					(yyval).var_tipo = "void*";
					(yyval).traducao = "\tcin >> " + (yyval).label + ";\n";
					(yyval).traducao += "\n\t" + temp->id + " = " + "(" + temp->type + ")" + (yyval).label;
					set_var((yyval).var_tipo, "", "", (yyval).label);
				} else if (temp->type == "string"){
					string receiver = create_temp_names();
					string receptor = create_temp_names();
					string size = create_temp_names();

					set_var("char*", "", "", receiver);
					set_var("char*", "", "", receptor);
					set_var("int", "", "", size);

					string a1 = "\n\tcin >> " + receiver + ";\n\t";
					string a2 = "loop:\n\tif("+receiver+"[" + size;
					string a3 = "] == EOF)goto loop2;\n\t";
					string a4 = size + " = " + size + " + 1;\n\tgoto loop;";
					string a5 = "\n\tloop2:\n\t" + receptor + " = (char*)malloc(" + size + "*sizeof(char));\n\t";
					string a7 = "strcpy("+receptor+","+receiver+");\n\t";
					string a6 = "strcpy("+temp->id+","+receptor+");";

					(yyval).traducao = a1 + a2 + a3 + a4 + a5 + a7 + a6;
				}
			}
#line 3213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1435 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "\tcout" + (yyvsp[-1]).traducao + " << endl;\n";
			}
#line 3221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1439 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 3229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1443 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 3237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1447 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 3245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1453 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = " << " + (yyvsp[0]).traducao;
		}
#line 3253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1457 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = " << " + (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
		}
#line 3261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1464 "sintatica.y" /* yacc.c:1646  */
    {
			if(!get_var((yyvsp[0]).nome)){
				yyerror(in_line() + "Variável " + (yyvsp[0]).nome +  " não existe");
			}else{
				(yyval).traducao = get_var((yyval).nome)->id;
			}
		}
#line 3273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1472 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).valor;
		}
#line 3281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1478 "sintatica.y" /* yacc.c:1646  */
    {
					error_indextype((yyvsp[-2]).var_tipo);
					VECTORS* temp = get_vector((yyvsp[-5]).nome);

					if(!temp){
						yyerror(in_line() + "Vetor " + (yyvsp[-5]).nome + " não existe!");
					} else if (temp->column != "0"){
						yyerror(in_line() + "Matriz não encontrada");
					}

					(yyval).label = temp->id + "[" + temp->row + "]";
					(yyval).var_tipo = temp->type;

					string jump1 = create_jump_names();
					string jump2 = create_jump_names();
					string jump3 = create_jump_names();
					string control = create_temp_names();
					set_var("int", "", "", control);
					string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" <<endl;";

					string condition1 = "\n\tif(" + (yyvsp[-3]).label + "<" + temp->row + ") goto " 
					+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":";

					string condition2 = "\n\tif(" + (yyvsp[-1]).label + ">" + (yyvsp[-3]).label + ") goto " 
					+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":";

					string condition3 = "\n\tif(" + (yyvsp[-1]).label + "<" + temp->row + ") goto " 
					+ jump3 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump3 + ":\n";

					(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + condition1 + condition2 + condition3;

					string l1 = create_loop_names();
					string l2 = create_loop_names();

					string loop = "\n\t" + control + " = " + (yyvsp[-3]).label + ";\n\t" + l1 + ":\n\tif(" +
					control + " == " + (yyvsp[-1]).label + ") goto " + l2 + ";\n\tcout << "
					+ temp->id + "[" + control + "] << endl;\n\t" + control + " = " + control 
					+ "+ 1;\n\tgoto " + l1 + ";\n\t" + l2 + ":\n\t";

					(yyval).traducao += loop;
				}
#line 3327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1520 "sintatica.y" /* yacc.c:1646  */
    {
					error_indextype((yyvsp[-8]).var_tipo);
					error_indextype((yyvsp[-6]).var_tipo);
					error_indextype((yyvsp[-3]).var_tipo);
					error_indextype((yyvsp[-1]).var_tipo);
					VECTORS* temp = get_matrix((yyvsp[-10]).nome);

					if(!temp) yyerror(in_line() + "Matriz " + (yyvsp[-10]).nome + " não existe!");

					string jump1 = create_jump_names();
					string jump2 = create_jump_names();
					string jump3 = create_jump_names();
					string jump4 = create_jump_names();
					string jump5 = create_jump_names();
					string jump6 = create_jump_names();

					string control1 = create_temp_names();
					string control2 = create_temp_names();
					set_var("int", "", "", control1);
					set_var("int", "", "", control2);

					string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\" <<endl;";

					string condition1 = "\n\tif(" + (yyvsp[-8]).label + "<" + temp->row + ") goto " 
					+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":";

					string condition2 = "\n\tif(" + (yyvsp[-6]).label + ">" + (yyvsp[-8]).label + ") goto " 
					+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":";

					string condition3 = "\n\tif(" + (yyvsp[-6]).label + "<" + temp->row + ") goto " 
					+ jump3 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump3 + ":\n";

					string condition4 = "\n\tif(" + (yyvsp[-3]).label + "<" + temp->column + ") goto " 
					+ jump4 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump4 + ":";

					string condition5 = "\n\tif(" + (yyvsp[-1]).label + ">" + (yyvsp[-3]).label + ") goto " 
					+ jump5 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump5 + ":";

					string condition6 = "\n\tif(" + (yyvsp[-1]).label + "<" + temp->column + ") goto " 
					+ jump6 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump6 + ":\n";

					string l1 = create_loop_names();
					string l2 = create_loop_names();
					string l3 = create_loop_names();

					(yyval).traducao = (yyvsp[-8]).traducao + (yyvsp[-6]).traducao + (yyvsp[-3]).traducao + (yyvsp[-1]).traducao
					+ condition1 + condition2 + condition3 + condition4 + condition5 + condition6;

					(yyval).label = temp->id + "[" + control2 + "*" + temp->column + "+" + control1 + "]"; 

					(yyval).traducao +=
					+ "\n\t" + control1 + " = " + (yyvsp[-3]).label + ";\n\t"
					+ control2 + " = " + (yyvsp[-8]).label + ";\n\t"
					+ l1 + ":\n\tif(" + control2 + "<=" + (yyvsp[-6]).label + ") goto " + l2 + ";\n\t"
					+ control1 + " = " + control1 + " + 1;\n\t"
					+ control2 + " = " + (yyvsp[-8]).label + ";\n\t"
					+ l2 + ":\n\tif(" + control1 + " == " + (yyvsp[-1]).label + ") goto " + l3 + ";\n\tcout << "
					+ (yyval).label + " << endl;\n\t" + control2 + " = " + control2 + " + 1;\n\t"
					+ "goto " + l1 + ";\n\t" + l3 + ":";
				}
#line 3392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1583 "sintatica.y" /* yacc.c:1646  */
    {
							VECTORS* temp = get_vector((yyvsp[-3]).nome);

							if(!temp) yyerror(in_line() + " vetor não existe");

							string jump = create_jump_names();
							string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" << endl;";

							string condition = (yyvsp[-1]).traducao + "\n\tif(" + (yyvsp[-1]).label + "<" + temp->row + ") goto " 
							+ jump + ";\n" + error_msg + "\n\texit(1);\n\t" + jump + ":\n\t";

							(yyval).traducao = condition + "cout <<" +temp->id + "[" + (yyvsp[-1]).label + "] << endl;";
						}
#line 3410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1597 "sintatica.y" /* yacc.c:1646  */
    {
							VECTORS* temp = get_matrix((yyvsp[-6]).nome);

							if(!temp) yyerror(in_line() + " matriz não existe");

							string jump1 = create_jump_names();
							string jump2 = create_jump_names();
							string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\"<<endl;";

							string condition = "\n\tif(" + (yyvsp[-4]).label + "<" + temp->row + ") goto " 
							+ jump1 + ";\n" + error_msg + "\n\texit(1);\n";

							condition += "\n\t" + jump1 + ":\n\tif(" + (yyvsp[-1]).label + "<" + temp->column + ") goto " 
							+ jump2 + ";\n" + error_msg + "\n\texit(1);\n";

							(yyval).traducao += (yyvsp[-4]).traducao + (yyvsp[-1]).traducao + condition + "\n\t" + jump2 
							+ ":\n\tcout << " + temp->id + "[" + (yyvsp[-4]).label + "*" + temp->column + "+" + (yyvsp[-1]).label + "] << endl;";
						}
#line 3433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1618 "sintatica.y" /* yacc.c:1646  */
    {
					VECTORS* temp = get_vector((yyvsp[-2]).nome);

					if(!temp) yyerror(in_line() + " vetor não existe");

					string control = create_temp_names();
					set_var("int", "", "", control);

					string l1 = create_loop_names();
					string l2 = create_loop_names();

					(yyval).traducao = "\n\t" + control + " = " + "0;\n\t" + l1 + ":\n\tif(" + control + "==" + temp->row + ") goto " + l2 + ";\n\t"
					+ "cout << " + temp->id + "[" + control + "] << endl;\n\t" + control + " = " + control 
					+ " + 1;\n\tgoto " + l1 + ";\n\t" + l2 +  ":";
				}
#line 3453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1634 "sintatica.y" /* yacc.c:1646  */
    {
					VECTORS* temp = get_matrix((yyvsp[-4]).nome);

					if(!temp) yyerror(in_line() + " matriz não existe");

					string l1 = create_loop_names();
					string l2 = create_loop_names();

					string control = create_temp_names();
					set_var("int", "", "", control);
					string totalmatrix = create_temp_names();
					set_var("int", "", "", totalmatrix);

					(yyval).traducao = "\n\t" + control + " = " + "0;\n\t" + totalmatrix + " = " + temp->row + "*" + temp->column + ";";
					(yyval).traducao += "\n\t" + l1 + ":\n\tif(" + control + "==" + totalmatrix + ") goto " + l2 + ";\n\t"
					+ "cout << " + temp->id + "[" + control + "] << endl;\n\t" + control + " = " + control 
					+ " + 1;\n\tgoto " + l1 + ";\n\t" + l2 + ":";
				}
#line 3476 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3480 "y.tab.c" /* yacc.c:1646  */
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
#line 1653 "sintatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	FUN function;
	function.next = NULL;
	pilha.push(function);
	first_exestack = &pilha.top();

	yyparse();

	pilha.pop();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}
