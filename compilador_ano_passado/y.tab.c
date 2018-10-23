/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_NUM = 258,
     TK_REAL = 259,
     TK_CHAR = 260,
     TK_BOOL = 261,
     TK_STRING = 262,
     TK_MAIN = 263,
     TK_ID = 264,
     TK_TIPO_VAR = 265,
     TK_TIPO_INT = 266,
     TK_TIPO_FLOAT = 267,
     TK_TIPO_CHAR = 268,
     TK_TIPO_BOOL = 269,
     TK_TIPO_STRING = 270,
     TK_TIPO_VOID = 271,
     TK_EQUAL = 272,
     TK_GTE = 273,
     TK_LTE = 274,
     TK_NEQUAL = 275,
     TK_AND = 276,
     TK_OR = 277,
     TK_NOT = 278,
     TK_IF = 279,
     TK_ELSE = 280,
     TK_DO = 281,
     TK_WHILE = 282,
     TK_FOR = 283,
     TK_BREAK = 284,
     TK_CONTINUE = 285,
     TK_PRINT = 286,
     TK_READ = 287,
     TK_FIM = 288,
     TK_ERROR = 289,
     TK_MM = 290,
     TK_PP = 291,
     TK_GLOBAL = 292
   };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_BOOL 261
#define TK_STRING 262
#define TK_MAIN 263
#define TK_ID 264
#define TK_TIPO_VAR 265
#define TK_TIPO_INT 266
#define TK_TIPO_FLOAT 267
#define TK_TIPO_CHAR 268
#define TK_TIPO_BOOL 269
#define TK_TIPO_STRING 270
#define TK_TIPO_VOID 271
#define TK_EQUAL 272
#define TK_GTE 273
#define TK_LTE 274
#define TK_NEQUAL 275
#define TK_AND 276
#define TK_OR 277
#define TK_NOT 278
#define TK_IF 279
#define TK_ELSE 280
#define TK_DO 281
#define TK_WHILE 282
#define TK_FOR 283
#define TK_BREAK 284
#define TK_CONTINUE 285
#define TK_PRINT 286
#define TK_READ 287
#define TK_FIM 288
#define TK_ERROR 289
#define TK_MM 290
#define TK_PP 291
#define TK_GLOBAL 292




/* Copy the first part of user declarations.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include "variaveis.h"
#include "loop.h"

#define YYSTYPE atributos

using namespace std;


struct atributos
{
	string label;
	string traducao;
	int tipo;

	int tamanho;
};

struct Funcoes
{
	string name;
	string new_name;

	string tipo;

	int qtd_params;

};

vector<Funcoes> funcoes_lista;

// Funcoes *funcoes_lista;

// Variaveis Planistas
string error_msg = "Wubba Lubba Dub Dub";

// roubando pra fazer else if, gambiarra demais
string else_if_string = "";

// roubando para fazer declaracao de funcao gambiarra demais
string funcao_declaracoes = "";

maps* tack = criarMaps();
varsDeclaradas varsDec;

Loop_stack* loop_tack = criarLoopStack();


// Functions
int yylex(void);
void yyerror(string);
string exibirVarsDeclaradas();
variavel criadorDeVariavel(string, string, string, int);
void deletadorDeVariavel(string);
string geradoraDeNomeDeVariaveis();
int getTipoToken(string);
string getTipoString(int);
atributos tratadoraLogic(int, string, int, string, string);
atributos tratarArithComCast(int, string, int, string, string);
atributos concatenarStrings(atributos, atributos);
int tipoResult(int, int);
atributos tratadoraArith(atributos, atributos, string);
variavel getVarPorNome(string);
string geradorTextGoto(int);


const vector<string> explode(const string& s, const char& c);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 252 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   319

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    40,    38,    48,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      50,    42,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    17,    18,    19,    22,    23,    29,
      36,    40,    43,    46,    49,    52,    55,    58,    61,    64,
      67,    70,    73,    76,    79,    83,    89,    94,   101,   103,
     107,   109,   116,   124,   125,   128,   133,   136,   143,   151,
     153,   155,   157,   165,   171,   181,   182,   183,   186,   190,
     192,   194,   197,   201,   203,   205,   208,   209,   212,   214,
     216,   218,   220,   222,   224,   226,   230,   234,   238,   240,
     244,   248,   251,   255,   259,   263,   267,   271,   275,   279,
     283,   287,   291,   295,   299,   302,   304,   306,   308,   310,
     312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    77,    62,    11,     8,    43,    44,    53,
      -1,    54,    45,    56,    46,    55,    -1,    -1,    -1,    57,
      56,    -1,    -1,    24,    43,    82,    44,    53,    -1,    24,
      43,    82,    44,    53,    64,    -1,    69,    65,    70,    -1,
      78,    47,    -1,    81,    47,    -1,    71,    47,    -1,    74,
      47,    -1,    29,    47,    -1,    30,    47,    -1,    58,    47,
      -1,    59,    47,    -1,    60,    47,    -1,     9,    36,    -1,
      36,     9,    -1,     9,    35,    -1,    35,     9,    -1,    37,
      79,     9,    -1,    37,    79,     9,    42,    82,    -1,     9,
      43,    61,    44,    -1,     9,    42,     9,    43,    61,    44,
      -1,     9,    -1,     9,    48,    61,    -1,    60,    -1,    79,
       9,    43,    63,    44,    53,    -1,    62,    79,     9,    43,
      63,    44,    53,    -1,    -1,    79,     9,    -1,    79,     9,
      48,    63,    -1,    25,    53,    -1,    25,    24,    43,    82,
      44,    53,    -1,    25,    24,    43,    82,    44,    53,    64,
      -1,    66,    -1,    67,    -1,    68,    -1,    26,    53,    27,
      43,    82,    44,    47,    -1,    27,    43,    82,    44,    53,
      -1,    28,    43,    78,    47,    82,    47,    58,    44,    53,
      -1,    -1,    -1,    31,    72,    -1,    72,    48,    73,    -1,
      73,    -1,    82,    -1,    32,    75,    -1,    75,    48,    76,
      -1,    76,    -1,     9,    -1,    78,    47,    -1,    -1,    79,
      80,    -1,    11,    -1,    12,    -1,    13,    -1,    14,    -1,
      15,    -1,    10,    -1,    16,    -1,    80,    48,     9,    -1,
      80,    48,    81,    -1,     9,    42,    82,    -1,     9,    -1,
       9,    42,    82,    -1,    43,    82,    44,    -1,    39,    82,
      -1,    82,    39,    82,    -1,    82,    38,    82,    -1,    82,
      40,    82,    -1,    82,    41,    82,    -1,    82,    49,    82,
      -1,    82,    50,    82,    -1,    82,    18,    82,    -1,    82,
      19,    82,    -1,    82,    17,    82,    -1,    82,    20,    82,
      -1,    82,    21,    82,    -1,    82,    22,    82,    -1,    23,
      82,    -1,     3,    -1,     4,    -1,     5,    -1,     9,    -1,
       6,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    99,   109,   117,   125,   140,   145,   169,
     201,   205,   211,   215,   220,   225,   235,   246,   251,   256,
     264,   283,   298,   317,   336,   365,   423,   480,   555,   562,
     567,   573,   600,   626,   630,   638,   648,   659,   694,   731,
     735,   739,   744,   771,   801,   831,   851,   858,   863,   869,
     876,   886,   891,   895,   900,   910,   915,   919,   934,   939,
     944,   949,   954,   960,   964,   970,   985,  1000,  1078,  1103,
    1196,  1200,  1217,  1221,  1234,  1238,  1242,  1251,  1260,  1269,
    1278,  1287,  1296,  1311,  1326,  1341,  1352,  1363,  1375,  1400,
    1411
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_REAL", "TK_CHAR",
  "TK_BOOL", "TK_STRING", "TK_MAIN", "TK_ID", "TK_TIPO_VAR", "TK_TIPO_INT",
  "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL", "TK_TIPO_STRING",
  "TK_TIPO_VOID", "TK_EQUAL", "TK_GTE", "TK_LTE", "TK_NEQUAL", "TK_AND",
  "TK_OR", "TK_NOT", "TK_IF", "TK_ELSE", "TK_DO", "TK_WHILE", "TK_FOR",
  "TK_BREAK", "TK_CONTINUE", "TK_PRINT", "TK_READ", "TK_FIM", "TK_ERROR",
  "TK_MM", "TK_PP", "TK_GLOBAL", "'+'", "'-'", "'*'", "'/'", "'='", "'('",
  "')'", "'{'", "'}'", "';'", "','", "'>'", "'<'", "$accept", "S", "BLOCO",
  "PUSH_SCOPE", "POP_SCOPE", "COMANDOS", "COMANDO", "OPERADOR_UNARIO",
  "GLOBAL", "FUNCAO_CHAMADA", "PARAMS_FUNCAO_CHAMADA", "FUNCAO_DECLARADA",
  "PARAMS_FUNCAO", "ELSE", "LOOP", "DO", "WHILE", "FOR", "PUSH_LOOP",
  "POP_LOOP", "PRINT", "PRINT_THINGS", "PRINT_THING", "READ",
  "READ_THINGS", "READ_THING", "DECLARATION_GLOBAL", "DECLARATION", "TIPO",
  "VARLIST", "ATRIB", "E", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    43,    45,
      42,    47,    61,    40,    41,   123,   125,    59,    44,    62,
      60
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    65,    66,    67,    68,    69,    70,    71,    72,    72,
      73,    74,    75,    75,    76,    77,    77,    78,    79,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     5,     0,     0,     2,     0,     5,     6,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     5,     4,     6,     1,     3,
       1,     6,     7,     0,     2,     4,     2,     6,     7,     1,
       1,     1,     7,     5,     9,     0,     0,     2,     3,     1,
       1,     2,     3,     1,     1,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    63,    58,    59,    60,    61,    62,    64,     0,     0,
       0,     0,     1,     0,     0,    55,    68,    57,    58,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    89,
      90,    88,     0,     0,     0,    67,    65,    66,     0,     0,
       0,     0,    84,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       4,    34,    70,    80,    78,    79,    81,    82,    83,    73,
      72,    74,    75,    76,    77,    69,     2,     0,     4,    31,
       0,    45,    32,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    20,     0,     0,     0,    15,    16,
      47,    49,    50,    54,    51,    53,    23,    21,     0,     5,
       6,    17,    18,    19,     4,     0,     0,    46,    39,    40,
      41,    13,    14,    11,    12,    88,    28,    30,     0,     0,
       0,     0,    24,     3,     0,     0,     0,    10,     0,     0,
       0,    26,     4,    48,    52,     0,     0,     0,     0,     0,
       0,    29,     8,    25,     0,     4,     0,    27,     4,     9,
       0,    43,     0,     0,    36,     0,     0,     0,    42,     0,
       0,     0,     4,     4,    44,    37,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,    76,    77,   143,    93,    94,    95,    96,   137,
     138,    13,    40,   169,   127,   128,   129,   130,    98,   147,
      99,   110,   111,   100,   114,   115,     9,   101,    11,    17,
     102,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
      48,  -113,  -113,  -113,  -113,  -113,  -113,  -113,    16,    48,
     -42,    33,  -113,   125,    43,  -113,     8,     6,    58,    69,
      13,    14,    70,    37,    39,    48,  -113,  -113,  -113,  -113,
    -113,  -113,    14,    14,    14,   229,    45,  -113,    44,    48,
      54,    90,   229,   235,    53,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,  -113,    56,
    -113,    57,  -113,   229,   229,   229,   229,   229,   229,   235,
     235,   269,   269,   229,   229,   229,  -113,    59,  -113,  -113,
      48,   139,  -113,  -113,    41,    63,    60,    61,    14,    92,
     102,   104,    48,    68,   139,    71,    73,    74,   -20,    76,
      78,    81,    82,  -113,  -113,    42,   106,    14,  -113,  -113,
      83,  -113,   229,  -113,    84,  -113,  -113,  -113,   107,  -113,
    -113,  -113,  -113,  -113,  -113,    87,    99,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,   101,    47,  -113,    89,   140,
      14,    92,    75,  -113,   119,    14,    48,  -113,   106,   155,
     106,  -113,  -113,  -113,  -113,    14,   122,   174,   120,   128,
     101,  -113,   141,   229,    14,  -113,    14,  -113,   149,  -113,
     181,  -113,   188,   134,  -113,   135,     5,    14,  -113,   -26,
     142,   222,  -113,  -113,  -113,   141,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,   -56,  -113,  -113,    93,  -113,     7,  -113,   -79,
    -112,  -113,   -36,     3,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,    64,  -113,  -113,    91,  -113,     1,    30,  -113,
     175,   -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int16 yytable[] =
{
      35,    10,    97,    59,    79,    15,   124,   125,   126,   103,
     104,    42,    43,    44,   179,    97,    12,    26,    27,    28,
      29,    30,    82,    31,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   159,    32,   161,    14,
      90,    91,    16,    19,    83,    26,    27,    28,    29,    30,
      21,   135,    20,    33,    22,    41,    25,    34,     1,     2,
       3,     4,     5,     6,     7,    32,    23,   112,   144,    41,
      45,    46,    47,    48,    49,    50,   103,   104,    24,    36,
      38,    33,    39,   105,   106,    34,   139,    57,    58,   149,
     106,    51,    52,    53,    54,   150,   162,    62,    60,    61,
      78,   113,    55,    56,    81,    80,   107,   108,   109,   171,
      41,   116,   174,   117,   119,   136,   142,   155,   121,   112,
     122,   123,   118,   131,   157,   132,   184,   185,   133,   134,
     145,   140,   141,   151,   163,     1,    18,     3,     4,     5,
       6,     7,   146,   170,   148,   172,   156,   158,    84,     1,
       2,     3,     4,     5,     6,     7,   181,    45,    46,    47,
      48,    49,    50,    85,   160,   164,   168,   166,    86,    87,
      88,    89,   167,   173,    90,    91,    92,   177,    51,    52,
      53,    54,   178,   180,   152,    -7,   182,   120,   186,    55,
      56,    45,    46,    47,    48,    49,    50,    37,    45,    46,
      47,    48,    49,    50,   153,    45,    46,    47,    48,    49,
      50,     0,    51,    52,    53,    54,     0,     0,   165,    51,
      52,    53,    54,    55,    56,   175,    51,    52,    53,    54,
      55,    56,   154,     0,     0,   176,     0,    55,    56,    45,
      46,    47,    48,    49,    50,     0,    45,    46,    47,    48,
      49,    50,    45,    46,    47,    48,    49,    50,     0,     0,
      51,    52,    53,    54,     0,     0,   183,    51,    52,    53,
      54,    55,    56,     0,     0,    53,    54,     0,    55,    56,
       0,     0,     0,     0,    55,    56,    45,    46,    47,    48,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56
};

static const yytype_int16 yycheck[] =
{
      21,     0,    81,    39,    60,    47,    26,    27,    28,    35,
      36,    32,    33,    34,     9,    94,     0,     3,     4,     5,
       6,     7,    78,     9,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,   148,    23,   150,     9,
      35,    36,     9,    13,    80,     3,     4,     5,     6,     7,
      42,     9,     9,    39,    48,    25,    43,    43,    10,    11,
      12,    13,    14,    15,    16,    23,     8,    88,   124,    39,
      17,    18,    19,    20,    21,    22,    35,    36,     9,     9,
      43,    39,    43,    42,    43,    43,   107,    42,    44,    42,
      43,    38,    39,    40,    41,    48,   152,    44,    44,     9,
      44,     9,    49,    50,    45,    48,    43,    47,    47,   165,
      80,     9,   168,     9,    46,     9,     9,    42,    47,   140,
      47,    47,    92,    47,   145,    47,   182,   183,    47,    47,
      43,    48,    48,    44,   155,    10,    11,    12,    13,    14,
      15,    16,    43,   164,    43,   166,    27,   146,     9,    10,
      11,    12,    13,    14,    15,    16,   177,    17,    18,    19,
      20,    21,    22,    24,     9,    43,    25,    47,    29,    30,
      31,    32,    44,    24,    35,    36,    37,    43,    38,    39,
      40,    41,    47,   176,    44,    46,    44,    94,   185,    49,
      50,    17,    18,    19,    20,    21,    22,    22,    17,    18,
      19,    20,    21,    22,   140,    17,    18,    19,    20,    21,
      22,    -1,    38,    39,    40,    41,    -1,    -1,    44,    38,
      39,    40,    41,    49,    50,    44,    38,    39,    40,    41,
      49,    50,   141,    -1,    -1,    47,    -1,    49,    50,    17,
      18,    19,    20,    21,    22,    -1,    17,    18,    19,    20,
      21,    22,    17,    18,    19,    20,    21,    22,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    44,    38,    39,    40,
      41,    49,    50,    -1,    -1,    40,    41,    -1,    49,    50,
      -1,    -1,    -1,    -1,    49,    50,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    52,    77,
      78,    79,     0,    62,    79,    47,     9,    80,    11,    79,
       9,    42,    48,     8,     9,    43,     3,     4,     5,     6,
       7,     9,    23,    39,    43,    82,     9,    81,    43,    43,
      63,    79,    82,    82,    82,    17,    18,    19,    20,    21,
      22,    38,    39,    40,    41,    49,    50,    42,    44,    63,
      44,     9,    44,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    53,    54,    44,    53,
      48,    45,    53,    63,     9,    24,    29,    30,    31,    32,
      35,    36,    37,    56,    57,    58,    59,    60,    69,    71,
      74,    78,    81,    35,    36,    42,    43,    43,    47,    47,
      72,    73,    82,     9,    75,    76,     9,     9,    79,    46,
      56,    47,    47,    47,    26,    27,    28,    65,    66,    67,
      68,    47,    47,    47,    47,     9,     9,    60,    61,    82,
      48,    48,     9,    55,    53,    43,    43,    70,    43,    42,
      48,    44,    44,    73,    76,    42,    27,    82,    78,    61,
       9,    61,    53,    82,    43,    44,    47,    44,    25,    64,
      82,    53,    82,    24,    53,    44,    47,    43,    47,     9,
      58,    82,    44,    44,    53,    53,    64
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 94 "sintatica.y"
    {
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n" << exibirVarsDeclaradas() << "\n" << funcao_declaracoes << "\n" << "\nint main(void)\n{\n" << else_if_string << (yyvsp[(7) - (7)]).traducao << "\n\treturn 0;\n}" << endl; 
			}
    break;

  case 3:
#line 100 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(3) - (5)]).traducao;
				(yyval).tamanho = (yyvsp[(3) - (5)]).tamanho;

				cout << "taamnaho aqui 33" << endl;
				cout << (yyval).tamanho << endl;
			}
    break;

  case 4:
#line 109 "sintatica.y"
    {
				Var_table escopo;
				pushEsc(tack,escopo);
				
				(yyval).traducao = "";
				(yyval).label = "";
			}
    break;

  case 5:
#line 117 "sintatica.y"
    {
				popEsc(tack);
				
				(yyval).traducao = "";
				(yyval).label = "";
			}
    break;

  case 6:
#line 126 "sintatica.y"
    {

				cout << "taamnaho aqui 22" << endl;
				cout << (yyval).tamanho << endl;

				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;

				(yyval).tamanho = (yyvsp[(1) - (2)]).tamanho;




			}
    break;

  case 7:
#line 140 "sintatica.y"
    {
				(yyval).traducao = "";
			}
    break;

  case 8:
#line 146 "sintatica.y"
    {

				int tipo_atual = tipoResult((yyvsp[(3) - (5)]).tipo, (yyvsp[(3) - (5)]).tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(3) - (5)]).tamanho);
				string gotoText = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(3) - (5)]).traducao; 
				line += "\t" +nome+ " = !" +(yyvsp[(3) - (5)]).label+ ";\n";

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText+ ";\n";
				(yyval).traducao += (yyvsp[(5) - (5)]).traducao+ "\n";
				(yyval).traducao += "\t" +gotoText+ ":\n";

			}
    break;

  case 9:
#line 170 "sintatica.y"
    {
				int tipo_atual = tipoResult((yyvsp[(3) - (6)]).tipo, (yyvsp[(3) - (6)]).tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(3) - (6)]).tamanho);
				string gotoText_ir_para_else = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(3) - (6)]).traducao;
				line += "\t" +nome+ " = !" +(yyvsp[(3) - (6)]).label+ ";\n";


				// $$.traducao = line + "\tif(" +$3.label+ "){\n" +$5.traducao+ "\t}\n";
				// $$.traducao += $6.traducao;

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText_ir_para_else+ ";\n";
				(yyval).traducao += (yyvsp[(5) - (6)]).traducao+ "\n";
				(yyval).traducao += "\tgoto " +(yyvsp[(6) - (6)]).label+ ";\n";
				(yyval).traducao += "\t" +gotoText_ir_para_else+ ":\n";
				(yyval).traducao += (yyvsp[(6) - (6)]).traducao;


				

			}
    break;

  case 10:
#line 202 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(2) - (3)]).traducao;
			}
    break;

  case 11:
#line 206 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);

				// cout << "AQUIII ________ \n" << "Label: " << $1.label << "\nTrad: " << $1.traducao << "\n ACABOUU ---" <<endl; 
			}
    break;

  case 12:
#line 212 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 13:
#line 216 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);

			}
    break;

  case 14:
#line 221 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);

			}
    break;

  case 15:
#line 226 "sintatica.y"
    {
				if(loop_tack->loops.empty()){
			 		cout << "erro compilação. break deve estar em um loop ";
			 		exit(0);
			 	}else{
			 		Loop loopAtual = getLoop(loop_tack);
			 		(yyval).traducao = "\tgoto " + loopAtual.fimL + ";\n";
			 	}
			}
    break;

  case 16:
#line 236 "sintatica.y"
    {
				if(loop_tack->loops.empty()){
			 		cout << "erro compilação. continue deve estar em um loop ";
			 		exit(0);
			 	}else{
			 		Loop loopAtual = getLoop(loop_tack);
			 		(yyval).traducao = "\tgoto " + loopAtual.contL + ";\n";
			 	}

			}
    break;

  case 17:
#line 247 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 18:
#line 252 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 19:
#line 257 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 20:
#line 265 "sintatica.y"
    {
				
				variavel v = getVarPorNome((yyvsp[(1) - (2)]).label);
				if(v.tipo != getTipoString(TK_TIPO_INT)){
					cout << "operador ++ não é permitido para o tipo " << v.tipo << endl;
					exit(0);
				}
				
				string nome = geradoraDeNomeDeVariaveis();
				variavel var = criadorDeVariavel(nome, nome, v.tipo, 0);
				
				string linha = "\t" + nome + " =  1;\n";
				string linha2 = "\t" + var.temp_name + " = "+ nome +" + " + v.temp_name + ";\n";
				
				(yyval).traducao = linha + linha2;


			}
    break;

  case 21:
#line 284 "sintatica.y"
    {
				variavel v = getVarPorNome((yyvsp[(1) - (2)]).label);
				if(v.tipo != getTipoString(TK_TIPO_INT)){
					cout << "operador ++ não é permitido para o tipo " << v.tipo << endl;
					exit(0);
				}
				
				addVarEsc(tack, v);
				varsDec.push_back(v);
				
				string linha2 = "\t" + v.temp_name + " = " + v.temp_name + " + "+ "1" + ";\n";
				
				(yyval).traducao = linha2;
			}
    break;

  case 22:
#line 299 "sintatica.y"
    {
				
				variavel v = getVarPorNome((yyvsp[(1) - (2)]).label);
				if(v.tipo != getTipoString(TK_TIPO_INT)){
					cout << "operador -- não é permitido para o tipo " << v.tipo << endl;
					exit(0);
				}
				
				string nome = geradoraDeNomeDeVariaveis();
				variavel var = criadorDeVariavel(nome, nome, v.tipo, 0);
				
				string linha = "\t" + nome + " =  1;\n";
				string linha2 = "\t" + var.temp_name + " = " + v.temp_name + " - " + nome + ";\n";
				
				(yyval).traducao = linha + linha2;


			}
    break;

  case 23:
#line 318 "sintatica.y"
    {
				
				variavel v = getVarPorNome((yyvsp[(1) - (2)]).label);
				if(v.tipo != getTipoString(TK_TIPO_INT)){
					cout << "operador -- não é permitido para o tipo " << v.tipo << endl;
					exit(0);
				}
				
				addVarEsc(tack, v);
				varsDec.push_back(v);

				
				//string linha = "\t" + nome + " =  1;\n";
				string linha2 = "\t" + v.temp_name + " = " + v.temp_name + " - " + "1" + ";\n";
				
				(yyval).traducao = linha2;
			}
    break;

  case 24:
#line 337 "sintatica.y"
    {
			

				//nao existe no escopo global
				if ( tack->variaveis_map[0][(yyvsp[(3) - (3)]).label].var_name == ""  ){
					
					string nome = geradoraDeNomeDeVariaveis();

					variavel v;
					if (getTipoString((yyvsp[(2) - (3)]).tipo) == "string")
					{
						// criando sting com tamanho predeterminado, deve melhorar [to-do]
						v = criarVar(nome, nome, getTipoString((yyvsp[(2) - (3)]).tipo), 10);
						
					}else{
						v = criarVar(nome, nome, getTipoString((yyvsp[(2) - (3)]).tipo), 0);
					}

					addVarEscGlobal(tack, v);
					varsDec.push_back(v);

				}else{
					cout << "Variavel " << (yyvsp[(3) - (3)]).label << " ja foi declarada no escopo global" <<endl;
					exit(0);
				}
	
			}
    break;

  case 25:
#line 366 "sintatica.y"
    {
			
				//nao existe no escopo global
				if ( tack->variaveis_map[0][(yyvsp[(3) - (5)]).label].var_name == ""  ){

					string nome = geradoraDeNomeDeVariaveis();

					variavel v;
					if (getTipoString((yyvsp[(2) - (5)]).tipo) == "string")
					{
						// criando sting com tamanho predeterminado, deve melhorar [to-do]
						v = criarVar(nome, nome, getTipoString((yyvsp[(2) - (5)]).tipo), 10);
						
					}else{
						v = criarVar(nome, nome, getTipoString((yyvsp[(2) - (5)]).tipo), 0);
					}

					addVarEscGlobal(tack, v);
					varsDec.push_back(v);
					
					// Cast na atribuição
					if( v.tipo != getTipoString((yyvsp[(5) - (5)]).tipo) ) {
						string store = geradoraDeNomeDeVariaveis();
						string linha =  store + " = (" +v.tipo+") " + (yyvsp[(5) - (5)]).label + ";\n";
						string linha2 = "\t"  + nome + " = " + store + ";\n";
						
						(yyval).traducao = (yyvsp[(3) - (5)]).traducao + (yyvsp[(5) - (5)]).traducao + "\t"  + linha + linha2;
	
						variavel v;
						if (getTipoString((yyvsp[(2) - (5)]).tipo) == "string")
						{
							// criando sting com tamanho predeterminado, deve melhorar [to-do]
							v = criarVar(nome, nome, getTipoString((yyvsp[(2) - (5)]).tipo), 10);
							
						}else{
							v = criarVar(nome, nome, getTipoString((yyvsp[(2) - (5)]).tipo), 0);
						}

						addVarEscGlobal(tack, v);
						varsDec.push_back(v);
				
					}
					else
					{
						// tipo igual, inferido?

						if (getTipoString((yyvsp[(5) - (5)]).tipo) == "char*"){
							(yyval).traducao = (yyvsp[(3) - (5)]).traducao + (yyvsp[(5) - (5)]).traducao + "\tstrcpy(" + nome  + ", " + (yyvsp[(5) - (5)]).label +");\n";
						}
						else
							(yyval).traducao = (yyvsp[(3) - (5)]).traducao + (yyvsp[(5) - (5)]).traducao + "\t" + nome  + " = " + (yyvsp[(5) - (5)]).label +";\n";
						
					}
				
				}	
			}
    break;

  case 26:
#line 424 "sintatica.y"
    {
				cout << "ASDSAD " << (yyvsp[(1) - (4)]).label << " " << (yyvsp[(3) - (4)]).tamanho << endl;

				

				for (int i = 0; i < funcoes_lista.size(); ++i)
				{
					// checar se ja existe uma funcao com mesmo nome
					if (funcoes_lista.at(i).name == (yyvsp[(1) - (4)]).label && funcoes_lista.at(i).qtd_params != (yyvsp[(3) - (4)]).tamanho)
					{
						cout << "Funcao com o mesmo nome mas nao com esse numero de parametros -> " << funcoes_lista.at(i).name << endl;
						exit(0);
					}
					else if (funcoes_lista.at(i).name == (yyvsp[(1) - (4)]).label && funcoes_lista.at(i).qtd_params == (yyvsp[(3) - (4)]).tamanho)
					{
						// string params = $3.traducao;
						// string call = "\tcall " + $1.label + ", " + to_string($3.tamanho); 


						// VOLTAR AQUI
						string var_parametros = "";
						cout << "nome das variaveis buscada " << (yyvsp[(3) - (4)]).traducao << endl;
						string tradu = (yyvsp[(3) - (4)]).traducao;
						vector<string> nome_vars = explode(tradu, ',');
						for (int j = 0; j < (yyvsp[(3) - (4)]).tamanho; ++j)
						{

							cout << "nome da variavel buscada " << nome_vars.at(j) << endl;
							variavel var = getVarPorNome(nome_vars.at(j));

							// variavel nao existe
							if (var.var_name == "")
							{
								cout << "essa variavel nao existe " << endl;
								exit(0);
							}

							var_parametros += var.temp_name;

							if (j < (yyvsp[(3) - (4)]).tamanho - 1)
							{
								var_parametros += ", ";
							}

						}


						(yyval).traducao = "\t" + (yyvsp[(1) - (4)]).label + "(" + var_parametros + ");\n";

						cout << (yyval).traducao << endl;
					}

					cout << "nome da funcao: " << funcoes_lista.at(i).name << " parametros " << (yyvsp[(3) - (4)]).traducao << endl;
				}	

			}
    break;

  case 27:
#line 481 "sintatica.y"
    {
				cout << "ASDSAD " << (yyvsp[(3) - (6)]).label << " " << (yyvsp[(5) - (6)]).tamanho << endl;

				

				for (int i = 0; i < funcoes_lista.size(); ++i)
				{
					// checar se ja existe uma funcao com mesmo nome
					if (funcoes_lista.at(i).name == (yyvsp[(3) - (6)]).label && funcoes_lista.at(i).qtd_params != (yyvsp[(5) - (6)]).tamanho)
					{
						cout << "Funcao com o mesmo nome mas nao com esse numero de parametros -> " << funcoes_lista.at(i).name << endl;
						exit(0);
					}
					else if (funcoes_lista.at(i).name == (yyvsp[(3) - (6)]).label && funcoes_lista.at(i).qtd_params == (yyvsp[(5) - (6)]).tamanho)
					{
						// string params = $3.traducao;
						// string call = "\tcall " + $1.label + ", " + to_string($3.tamanho); 


						// VOLTAR AQUI
						string var_parametros = "";
						cout << "nome das variaveis buscada " << (yyvsp[(5) - (6)]).traducao << endl;
						string tradu = (yyvsp[(5) - (6)]).traducao;
						vector<string> nome_vars = explode(tradu, ',');
						for (int j = 0; j < (yyvsp[(5) - (6)]).tamanho; ++j)
						{

							cout << "nome da variavel buscada " << nome_vars.at(j) << endl;
							variavel var = getVarPorNome(nome_vars.at(j));

							// variavel nao existe
							if (var.var_name == "")
							{
								cout << "essa variavel nao existe " << endl;
								exit(0);
							}

							var_parametros += var.temp_name;

							if (j < (yyvsp[(5) - (6)]).tamanho - 1)
							{
								var_parametros += ", ";
							}

						}

						variavel v = getVarPorNome((yyvsp[(1) - (6)]).label);

						if (v.var_name == "")
						{
							cout << "Nao existe variavel que a funcao vai ser atribuida" << endl;
							exit(0);
						}
						else if(v.tipo != funcoes_lista.at(i).tipo){
							cout << "Tipo de variavel que a funcao vai ser atribuida diferente do tipo da cuncao" << endl;
							cout << v.tipo << " " << funcoes_lista.at(i).tipo << endl;
							exit(0);
						}
						else{
							(yyval).traducao = "\t" + v.temp_name + " = " + (yyvsp[(3) - (6)]).label + "(" + var_parametros + ");\n";

						}



						cout << (yyval).traducao << endl;
					}

					cout << "nome da funcao: " << funcoes_lista.at(i).name << " parametros " << (yyvsp[(5) - (6)]).traducao << endl;
				}	

			}
    break;

  case 28:
#line 556 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).label;
				(yyval).tamanho = 1;
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;

			}
    break;

  case 29:
#line 563 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (3)]).label + "," + (yyvsp[(3) - (3)]).traducao;
				(yyval).tamanho = (yyvsp[(3) - (3)]).tamanho + 1;
			}
    break;

  case 30:
#line 568 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 31:
#line 574 "sintatica.y"
    {
				cout << "Declrando func " << (yyvsp[(2) - (6)]).label << endl;

				for (int i = 0; i < funcoes_lista.size(); ++i)
				{
					// checar se ja existe uma funcoes_lista com mesmo nome
					if (funcoes_lista.at(i).name == (yyvsp[(2) - (6)]).label && funcoes_lista.at(i).qtd_params == (yyvsp[(4) - (6)]).tamanho)
					{
						cout << "Funcao com o mesmo nome e tamanho de parametros ja declarada -> " << funcoes_lista.at(i).name << endl;
						exit(0);
					}
				}

				Funcoes funcao = {.name = (yyvsp[(2) - (6)]).label, .qtd_params = (yyvsp[(4) - (6)]).tamanho, .tipo = getTipoString((yyvsp[(1) - (6)]).tipo)};
				funcoes_lista.push_back(funcao);

				// funcoes_lista = (Funcoes*) malloc(sizeof(struct Funcoes));
				// funcoes_lista.at(i).name = $2.label;
				// funcoes_lista.at(i).qtd_params = $4.tamanho;

				cout << "QTD PARAMS_1 " << funcao.qtd_params << " " << endl;


				// funcoes_lista.at(i).new_name por questao de debug :)
				funcao_declaracoes += getTipoString((yyvsp[(1) - (6)]).tipo) + " " + funcao.name + "(" + (yyvsp[(4) - (6)]).traducao + ") {\n" + (yyvsp[(6) - (6)]).traducao + "\n}";
			}
    break;

  case 32:
#line 601 "sintatica.y"
    {

				cout << "Declrando func " << (yyvsp[(3) - (7)]).label << endl;

				for (int i = 0; i < funcoes_lista.size(); ++i)
				{
					// checar se ja existe uma funcoes_lista com mesmo nome
					if (funcoes_lista.at(i).name == (yyvsp[(3) - (7)]).label && funcoes_lista.at(i).qtd_params == (yyvsp[(5) - (7)]).tamanho)
					{
						cout << "Funcao com o mesmo nome e tamanho de parametros ja declarada -> " << funcoes_lista.at(i).name << endl;
						exit(0);
					}
				}

				Funcoes funcao = {.name = (yyvsp[(3) - (7)]).label, .qtd_params = (yyvsp[(5) - (7)]).tamanho, .tipo = getTipoString((yyvsp[(1) - (7)]).tipo)};
				funcoes_lista.push_back(funcao);

				cout << "QTD PARAMS_2 " << funcao.qtd_params << " " << endl;

				// funcoes_lista.at(i).new_name por questao de debug :)
				funcao_declaracoes += "\n" + getTipoString((yyvsp[(2) - (7)]).tipo) + " " + funcao.name + "(" + (yyvsp[(5) - (7)]).traducao + ") {\n" + (yyvsp[(7) - (7)]).traducao + "\n}";
				

			}
    break;

  case 33:
#line 626 "sintatica.y"
    {
				(yyval).traducao = "";
			}
    break;

  case 34:
#line 631 "sintatica.y"
    {
				(yyval).traducao = getTipoString((yyvsp[(1) - (2)]).tipo) + " " + (yyvsp[(2) - (2)]).label;
				(yyval).tamanho = 1;
				// cout << "TAAAMNHOooooooo " << $$.tamanho << endl;


			}
    break;

  case 35:
#line 639 "sintatica.y"
    {
				(yyval).traducao = getTipoString((yyvsp[(1) - (4)]).tipo) + " " + (yyvsp[(2) - (4)]).label + "," + (yyvsp[(4) - (4)]).traducao;
				(yyval).tamanho = (yyvsp[(4) - (4)]).tamanho + 1;

				// cout << "TAAAMNHO " << $$.tamanho << " " << $4.tamanho << endl;

			}
    break;

  case 36:
#line 649 "sintatica.y"
    {
				string gotoText_final_if = geradorTextGoto(TK_IF); // ou $1.tipo e mudar a func

				(yyval).traducao += (yyvsp[(2) - (2)]).traducao+ "\n";
				(yyval).traducao += "\t" +gotoText_final_if+ ":\n";

				(yyval).label = gotoText_final_if;


			}
    break;

  case 37:
#line 660 "sintatica.y"
    {

				int tipo_atual = tipoResult((yyvsp[(4) - (6)]).tipo, (yyvsp[(4) - (6)]).tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(4) - (6)]).tamanho);
				string gotoText_final_if = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(4) - (6)]).traducao; 
				line += "\t" +nome+ " = !" +(yyvsp[(4) - (6)]).label+ ";\n";

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText_final_if+ ";\n";
				(yyval).traducao += (yyvsp[(6) - (6)]).traducao+ "\n";
				(yyval).traducao += "\t" +gotoText_final_if+ ":\n";


				(yyval).label = gotoText_final_if;


				// // string line = $4.traducao;
				// else_if_string += $4.traducao;
				// // deletadorDeVariavel($4.label);


				// $$.traducao = "\telse if(" +$4.label+ "){\n" +$6.traducao+ "\t}\n";

			}
    break;

  case 38:
#line 695 "sintatica.y"
    {
				int tipo_atual = tipoResult((yyvsp[(4) - (7)]).tipo, (yyvsp[(4) - (7)]).tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(4) - (7)]).tamanho);
				string gotoText_ir_para_else = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(4) - (7)]).traducao;
				line += "\t" +nome+ " = !" +(yyvsp[(4) - (7)]).label+ ";\n";

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText_ir_para_else+ ";\n";
				(yyval).traducao += (yyvsp[(6) - (7)]).traducao+ "\n";
				(yyval).traducao += "\tgoto " +(yyvsp[(7) - (7)]).label+ ";\n";
				(yyval).traducao += "\t" +gotoText_ir_para_else+ ":\n";
				(yyval).traducao += (yyvsp[(7) - (7)]).traducao;

				(yyval).label = (yyvsp[(7) - (7)]).label;


				// else_if_string += $4.traducao;
				// // deletadorDeVariavel($4.label);



				// $$.traducao = "\telse if(" +$4.label+ "){\n" +$6.traducao+ "\t}\n";
				// $$.traducao += $7.traducao;
			}
    break;

  case 39:
#line 732 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 40:
#line 736 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 41:
#line 740 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 42:
#line 745 "sintatica.y"
    {
				int tipo_atual = tipoResult((yyvsp[(5) - (7)]).tipo, (yyvsp[(5) - (7)]).tipo);

				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT)
				{
					cout << "nao aceita esse tipo no while" << endl;
					exit(0);
				}

				else_if_string += (yyvsp[(5) - (7)]).traducao;
				
				Loop loop = getLoop(loop_tack);
				
				string comecoL = loop.comecoL;
				string fimL = loop.fimL;
				string contL = loop.contL;
	
				string linha = "\tif(" + (yyvsp[(5) - (7)]).label + ")";
				string showLabel = "{goto "+ comecoL;
				
				(yyval).traducao  = "\t" + comecoL + ":\n" + (yyvsp[(2) - (7)]).traducao + "\n\t" + contL + ":\n";
				// $$.traducao += $5.traducao; 
				(yyval).traducao += linha + " " + showLabel + "};\n\t" + fimL + ":\n"; 
				
			}
    break;

  case 43:
#line 772 "sintatica.y"
    {
				int tipo_atual = tipoResult((yyvsp[(3) - (5)]).tipo, (yyvsp[(3) - (5)]).tipo);

				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT)
				{
					cout << "nao aceita esse tipo no while" << endl;
					exit(0);
				}
				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(3) - (5)]).tamanho);
				
				Loop loop = getLoop(loop_tack);
				
				string comecoL = loop.comecoL;
				string fimL = loop.fimL;
				string contL = loop.contL;
	
				string voltarProComecoL = "\tgoto "+ comecoL + ";\n\n";

			    (yyval).traducao = (yyvsp[(3) - (5)]).traducao;
			    (yyval).traducao += "\t" + nome + " = !" + (yyvsp[(3) - (5)]).label + ";\n";
			    (yyval).traducao += "\t" + comecoL +":"+ "\n\tif(" + nome + ") {goto " + fimL +"};";
			    (yyval).traducao += "\n" + (yyvsp[(5) - (5)]).traducao + "\n";
			    (yyval).traducao += "\t" + contL + ":\n" + voltarProComecoL;
			    (yyval).traducao += "\t"  + fimL + ":\n\n";


			}
    break;

  case 44:
#line 802 "sintatica.y"
    {
				
				if( (yyvsp[(5) - (9)]).tipo != TK_TIPO_BOOL ){
					cout <<  "COMPILACAO com erro: FOR espera um bool no segundo parametro" <<endl;
					exit(0);
				}


				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyvsp[(5) - (9)]).tipo), 0);
					
					
				Loop loop = getLoop(loop_tack);

				string comecoL = loop.comecoL;
				string fimL = loop.fimL;
				string contL = loop.contL;
				
				string linha = "\t" + nome + " = !" + (yyvsp[(5) - (9)]).label + ";\n";
				
				string atrib_inicial = (yyvsp[(3) - (9)]).traducao;
				string showLabel = "\n\t" + comecoL + ": \n" + (yyvsp[(5) - (9)]).traducao + linha + "\n";
				string verifica = "\tif(" + nome + ") " + "\tgoto "+ fimL + ";\n";
				
				string dentroFor = (yyvsp[(9) - (9)]).traducao + "\n\t" + contL + ": \n" + (yyvsp[(7) - (9)]).traducao + (yyvsp[(5) - (9)]).traducao + linha + "\n";
				
				(yyval).traducao = atrib_inicial + showLabel + verifica + dentroFor + "\tgoto " + comecoL + ";\n\t" + fimL + ":\n";
			}
    break;

  case 45:
#line 831 "sintatica.y"
    {
				// mudar de tk_while pra loop, ou mudar na func pra ser so loop? [to-do]
				string label = geradorTextGoto(TK_WHILE);

				string comecoL = "inicio_" + label;
				string fimL = "fim_" + label;
				string contL = "continue_" + label;
				
				Loop loop;
				loop.fimL = fimL;
				loop.comecoL = comecoL;
				loop.contL = contL;
				
				
				pushLoop(loop, loop_tack);
				
				(yyval).traducao = "";
				(yyval).label = "";
			}
    break;

  case 46:
#line 851 "sintatica.y"
    {
				popLoop(loop_tack);

				(yyval).traducao = "";
				(yyval).label = "";
			}
    break;

  case 47:
#line 859 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(2) - (2)]).traducao + "\tstd::cout << " +(yyvsp[(2) - (2)]).label+ "std::endl;\n";
			}
    break;

  case 48:
#line 864 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
				(yyval).label = (yyvsp[(1) - (3)]).label + (yyvsp[(3) - (3)]).label ;

			}
    break;

  case 49:
#line 870 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;

			}
    break;

  case 50:
#line 877 "sintatica.y"
    {
				// else_if_string += $1.traducao;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				// deletadorDeVariavel($1.label);
				(yyval).label = (yyvsp[(1) - (1)]).label + " << ";

			}
    break;

  case 51:
#line 887 "sintatica.y"
    {
				(yyval).traducao = "\tstd::cin " +(yyvsp[(2) - (2)]).traducao+ ";\n";
			}
    break;

  case 52:
#line 892 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
			}
    break;

  case 53:
#line 896 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 54:
#line 901 "sintatica.y"
    {
				else_if_string += (yyvsp[(1) - (1)]).traducao;
				// deletadorDeVariavel($1.label);
				(yyval).traducao = " >> " +(yyvsp[(1) - (1)]).label;

			}
    break;

  case 55:
#line 911 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao;
			}
    break;

  case 56:
#line 915 "sintatica.y"
    {
				(yyval).traducao = "";
			}
    break;

  case 57:
#line 920 "sintatica.y"
    {
				(yyvsp[(2) - (2)]).tipo = (yyvsp[(1) - (2)]).tipo;
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;

				(yyval).tamanho = (yyvsp[(2) - (2)]).tamanho;



				// cout << "AQUIII ________ \n" << "Label: " << $$.label << "\nTrad: " << $$.traducao << "\n ACABOUU ---" <<endl; 

			}
    break;

  case 58:
#line 935 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_INT;
				// $$.traducao = "int";
			}
    break;

  case 59:
#line 940 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_FLOAT;
				// $$.traducao = "float";
			}
    break;

  case 60:
#line 945 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_CHAR;
				// $$.traducao = "char";
			}
    break;

  case 61:
#line 950 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;
				// $$.traducao = "bool";
			}
    break;

  case 62:
#line 955 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_STRING;
				// $$.traducao = "string";
			}
    break;

  case 63:
#line 961 "sintatica.y"
    {
				// $$.traducao = "var";
			}
    break;

  case 64:
#line 965 "sintatica.y"
    {
				// $$.traducao = "void";;
			}
    break;

  case 65:
#line 971 "sintatica.y"
    {
				// cout << "VARLIST, TK_ID _______" <<endl;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;

				variavel v = criadorDeVariavel((yyvsp[(3) - (3)]).label, nome, getTipoString((yyvsp[(0) - (3)]).tipo), 0);
				// addVarEsc(tack, v);

				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].var_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].temp_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].tipo << endl;

			}
    break;

  case 66:
#line 986 "sintatica.y"
    {
				// verificar [to-do] tudo
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;

				(yyvsp[(1) - (3)]).tipo = (yyvsp[(0) - (3)]).tipo;
				(yyvsp[(3) - (3)]).tipo = (yyvsp[(0) - (3)]).tipo;

				cout << "label>>>>> " << (yyvsp[(1) - (3)]).label << endl;
				cout << "traducao>>>>> " << (yyvsp[(1) - (3)]).traducao << endl;

				cout << "label>>>>> " << (yyvsp[(3) - (3)]).label << endl;
				cout << "traducao>>>>> " << (yyvsp[(3) - (3)]).traducao << endl;

			}
    break;

  case 67:
#line 1001 "sintatica.y"
    {
				// cout << "TK_ID = E_______ " << $1.label <<endl;
				string nome = geradoraDeNomeDeVariaveis();
				// inferir tipo
				string tipo_v = "";

				// se o tipo foi dito -> int x = 9
				if (getTipoString((yyvsp[(0) - (3)]).tipo) != "")
				{	
					// cout << "1" << endl;
					tipo_v = getTipoString((yyvsp[(0) - (3)]).tipo);
				}
				else // se tipo nao foi dito -> x = 9
				{
					// cout << "2" << endl;
					// cout << $3.tipo << endl;

					tipo_v = getTipoString((yyvsp[(3) - (3)]).tipo);
				}

				// tipo da expressao = bool e tipo da variavel nao for bool
				if ((yyvsp[(3) - (3)]).tipo == TK_TIPO_BOOL && tipo_v != "bool")
				{
					cout << error_msg << endl;
					cout << "tipo de expressao = bool e tipo variavel != bool" << endl;
					exit(0);
				}

				// if (tipo_v == "string")
				// {
					// cout << "é igual string" << endl;
					// cout << $3.label << endl;
					// cout << $3.tamanho << endl;
				// }


				variavel v = criadorDeVariavel((yyvsp[(1) - (3)]).label, nome, tipo_v, (yyvsp[(3) - (3)]).tamanho);
				(yyval).tamanho = (yyvsp[(3) - (3)]).tamanho;

				cout << "Tamanhoa aqui" << endl;
				cout << (yyval).tamanho << endl;

				// addVarEsc(tack, v);

				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].var_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].temp_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].tipo << endl;

				// cout << " ->>>> " << getTipoString($3.tipo) << endl;


				// cout << " ->>>> " << getVarPorNome($1.label).var_name << endl;
				// cout << " ->>>> " << getVarPorNome($1.label).temp_name << endl;
				// cout << " ->>>> " << getVarPorNome($1.label).tipo << endl;


				variavel minha_var = getVarPorNome((yyvsp[(1) - (3)]).label);

				// variavel com tipo diferente da expressao
				if (minha_var.tipo != getTipoString((yyvsp[(3) - (3)]).tipo))
				{
					string nomeReal = geradoraDeNomeDeVariaveis();

					// castiando [to-do] verificar isso aqui, se nomeReal troca de lugar com nome
					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao; 
					(yyval).traducao += "\t" + nome + " = (" + minha_var.tipo + ") " + (yyvsp[(3) - (3)]).label +";\n";
					(yyval).traducao += "\t" + nomeReal + " = " + nome + ";\n";
					
					v = criadorDeVariavel(nomeReal, nomeReal, minha_var.tipo, 0);
				}
				else{ // se o tipo eh igual

					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + nome + " = " + (yyvsp[(3) - (3)]).label + ";\n";

				}
	 
			}
    break;

  case 68:
#line 1079 "sintatica.y"
    {
				// cout << "TK_ID _______" <<endl;

				// tipo nome_var;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;

				variavel v = criadorDeVariavel((yyval).label, geradoraDeNomeDeVariaveis(), getTipoString((yyvsp[(0) - (1)]).tipo), 0);

				// cout << v.var_name << endl;

				// addVarEsc(tack, v);

				// for (int i = 0; i < tack->variaveis_map.size(); ++i)
				// {
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].var_name << endl;
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].temp_name << endl;
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].tipo << endl;
					 
				// }

			}
    break;

  case 69:
#line 1104 "sintatica.y"
    {
				variavel v = getVarPorNome((yyvsp[(1) - (3)]).label);
				string nome = v.temp_name;

				(yyval).tamanho = (yyvsp[(3) - (3)]).tamanho;


				// variavel nao existe
				if (nome == "")
				{
					string tipo_v;

					nome = geradoraDeNomeDeVariaveis();


					// cout << getTipoString($-2.tipo) << endl;

					// cout << getTipoString($3.tipo) << endl;

					// $-2 pois pra chegar em ATRIB eu vim por VARLIST de DECLARATION
					// se vier direto de COMANDO deve ser $0
					if (getTipoString((yyvsp[(-2) - (3)]).tipo) != "")
					{	
						tipo_v = getTipoString((yyvsp[(-2) - (3)]).tipo);
						// cout << "1" << endl;
					}
					else // se tipo nao foi dito -> x = 9
					{
						tipo_v = getTipoString((yyvsp[(3) - (3)]).tipo);
						// cout << "2" << endl;
						
					}

					// tipo da expressao = bool e tipo da variavel nao for bool
					if ((yyvsp[(3) - (3)]).tipo == TK_TIPO_BOOL && tipo_v != "bool")
					{
						cout << error_msg << endl;
						cout << "tipo de expressao = bool e tipo variavel != bool" << endl;

						exit(0);
					}

					v = criadorDeVariavel((yyvsp[(1) - (3)]).label, nome, tipo_v, (yyvsp[(3) - (3)]).tamanho);




				}
				else{
					// if (getTipoString($0.tipo) != "")
					// {	
					// 	tipo_v = getTipoString($0.tipo);
					// 	cout << "1" << endl;
					// }
					
					if ((yyvsp[(3) - (3)]).tipo == TK_TIPO_BOOL && v.tipo != "bool")
					{
						cout << error_msg << endl;
						cout << "tipo de expressao = bool e tipo variavel != bool" << endl;

						exit(0);
					}
				}




				if (v.tipo != getTipoString((yyvsp[(3) - (3)]).tipo))
				{
					string nomeReal = geradoraDeNomeDeVariaveis();

					// castiando [to-do] verificar isso aqui, se nomeReal troca de lugar com nome
					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao; 
					(yyval).traducao += "\t" + nome + " = (" + v.tipo + ") " + (yyvsp[(3) - (3)]).label +";\n";
					(yyval).traducao += "\t" + nomeReal + " = " + nome + ";\n";
					
					v = criadorDeVariavel(nomeReal, nomeReal, v.tipo, 0);
				}
				else{ // se o tipo eh igual

					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + nome + " = " + (yyvsp[(3) - (3)]).label + ";\n";

				}

				// cout << "TA AQUI2" << endl;




			}
    break;

  case 70:
#line 1197 "sintatica.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
			}
    break;

  case 71:
#line 1201 "sintatica.y"
    {
				(yyval).tipo = (yyvsp[(2) - (2)]).tipo;

				string nome = geradoraDeNomeDeVariaveis();
				// temp(x+1) = -temp(x); usa -temp(x)
				// $$.label = "-" + $2.label; 
				// temp(x+1) = -temp(x); usa temp(x+1)
				(yyval).label = nome;

				(yyval).traducao = (yyvsp[(2) - (2)]).traducao + "\t" + nome + " = -" + (yyvsp[(2) - (2)]).label + ";\n";

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

				 

			}
    break;

  case 72:
#line 1218 "sintatica.y"
    {
				(yyval) = tratadoraArith((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "-");
			}
    break;

  case 73:
#line 1222 "sintatica.y"
    {
				if ((yyvsp[(1) - (3)]).tipo == TK_TIPO_STRING && (yyvsp[(3) - (3)]).tipo == TK_TIPO_STRING)
				{
					cout << "TAAAAMMAMAMA" << endl;
					cout << (yyvsp[(1) - (3)]).tamanho << endl;
					cout << (yyvsp[(3) - (3)]).tamanho << endl;
					(yyval) = concatenarStrings((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				}
				else{
					(yyval) = tratadoraArith((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "+");
				}
			}
    break;

  case 74:
#line 1235 "sintatica.y"
    {
				(yyval) = tratadoraArith((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "*");
			}
    break;

  case 75:
#line 1239 "sintatica.y"
    {
				(yyval) = tratadoraArith((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "/");
			}
    break;

  case 76:
#line 1243 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, ">");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 77:
#line 1252 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, "<");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 78:
#line 1261 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, ">=");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 79:
#line 1270 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, "<=");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 80:
#line 1279 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, "==");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 81:
#line 1288 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, "!=");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 82:
#line 1297 "sintatica.y"
    {	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				(yyval).tipo = TK_TIPO_BOOL;
				(yyval).tipo = tipoResult((yyvsp[(1) - (3)]).tipo, (yyvsp[(3) - (3)]).tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + nome +" = "+ (yyvsp[(1) - (3)]).label +" && "+ (yyvsp[(3) - (3)]).label +";\n";
				
				(yyval).label = nome;
			}
    break;

  case 83:
#line 1312 "sintatica.y"
    {	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				(yyval).tipo = TK_TIPO_BOOL;
				(yyval).tipo = tipoResult((yyvsp[(1) - (3)]).tipo, (yyvsp[(3) - (3)]).tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + nome +" = "+ (yyvsp[(1) - (3)]).label +" || "+ (yyvsp[(3) - (3)]).label +";\n";

				(yyval).label = nome;
			}
    break;

  case 84:
#line 1327 "sintatica.y"
    {	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				(yyval).tipo = tipoResult((yyvsp[(2) - (2)]).tipo, (yyvsp[(2) - (2)]).tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);


				(yyval).traducao = (yyvsp[(2) - (2)]).traducao + "\t" + nome +" = !"+ (yyvsp[(2) - (2)]).label +";\n";

				(yyval).label = nome;
			}
    break;

  case 85:
#line 1342 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_INT;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\t" + nome + " = " + (yyvsp[(1) - (1)]).label + ";\n";
				(yyval).label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

			}
    break;

  case 86:
#line 1353 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_FLOAT;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\t" + nome + " = " + (yyvsp[(1) - (1)]).label + ";\n";
				(yyval).label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

			}
    break;

  case 87:
#line 1364 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_CHAR;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\t" + nome + " = " + (yyvsp[(1) - (1)]).label + ";\n";
				(yyval).label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);
				// [to-do] checar isso $1.label.size() - 2

			}
    break;

  case 88:
#line 1376 "sintatica.y"
    {
				variavel v = getVarPorNome((yyvsp[(1) - (1)]).label);

				(yyval).tamanho = v.tamanho;


				// verifica se variavel existe
				if (v.var_name == "")
				{
					cout << error_msg << endl;
					cout << "variavel nao existe" << endl;
					exit(0);
				}
				else{
					(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
					(yyval).label = v.temp_name;
					(yyval).tipo = getTipoToken(v.tipo);
				}

				// cout << "TA AQUI" << endl;
				// cout << $$.label << endl;
				// cout << $$.tipo << endl;

			}
    break;

  case 89:
#line 1401 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\t" + nome + " = " + (yyvsp[(1) - (1)]).label + ";\n";
				(yyval).label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

			}
    break;

  case 90:
#line 1412 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_STRING;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\tstrcpy(" + nome + "," + (yyvsp[(1) - (1)]).label + ");\n";
				(yyval).label = nome;

				(yyval).tamanho = (yyvsp[(1) - (1)]).label.size()-2;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), (yyvsp[(1) - (1)]).label.size()-2);

			}
    break;


/* Line 1267 of yacc.c.  */
#line 3190 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1426 "sintatica.y"


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	// for (int i = 0; i < varsDec.size(); ++i)
	// {
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).var_name << endl;
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).temp_name << endl;
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).tipo << "\n" << endl;
	// }

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string exibirVarsDeclaradas(){

	// varsDeclaradas varsDec_aux;

	// for (int i = 0; i < varsDec.size(); ++i)
	// {
	// 	variavel v = getVarPorNome(varsDec[i].var_name);

	// 	cout << "VAAAA " << varsDec[i].var_name << endl;
	// 	if ( varsDec.count(v.var_name) )
	// 	{
	// 		cout << "VBBBB " << v.var_name << endl;
		
	// 	}

	// 	varsDec_aux.push_back(v);
	// 	cout << "VCCCC " << varsDec_aux[i].var_name << endl;

	// }

	return getDeclaradas(varsDec);
}
variavel criadorDeVariavel(string nome, string temp_nome, string tipo, int tamanho){

	variavel v;

	if (tipo == "string" && tamanho == 0)
	{
		// criando sting com tamanho predeterminado, deve melhorar [to-do]
		v = criarVar(nome, temp_nome, tipo, 0);
		
	}else{
		v = criarVar(nome, temp_nome, tipo, tamanho);
	}

	addVarEsc(tack, v);
	varsDec.push_back(v);

	return v;
}
 
void deletadorDeVariavel(string nome){

	tack->variaveis_map[tack->escopo_num].erase(nome);
	cout << "APAGOU " << nome << endl;

	exibirVarsDeclaradas();

	// variavel v = getVarPorNome(nome);
	// cout << v.var_name << endl;
	// variavel v = getVarPorNome(nome);
	// delete v;

}
string geradoraDeNomeDeVariaveis(){
	static int num_para_gerar_nomes = 0;
	// string nome;
	// nome = "temp_" + to_string(num_para_gerar_nomes);

	// num_para_gerar_nomes++;
	return "temp_" + to_string(num_para_gerar_nomes++);
}

string geradoraDeNomeDeFuncoes(){
	static int num_para_gerar_nomes = 0;
	// string nome;
	// nome = "temp_" + to_string(num_para_gerar_nomes);

	// num_para_gerar_nomes++;
	return "func_temp_" + to_string(num_para_gerar_nomes++);
}

int getTipoToken(string tipo){

	if (tipo == "int")
		return TK_TIPO_INT;
	if (tipo == "float")
		return TK_TIPO_FLOAT;
	if (tipo == "char")
		return TK_TIPO_CHAR;
	if (tipo == "bool")
		return TK_TIPO_BOOL;
	if (tipo == "string")
		return TK_TIPO_STRING;

	return 0;
}

string getTipoString(int tipo){

	if (tipo == TK_TIPO_INT)
		return "int";
	if (tipo == TK_TIPO_FLOAT)
		return "float";
	if (tipo == TK_TIPO_CHAR)
		return "char";
	if (tipo == TK_TIPO_BOOL)
		return "bool";
	if (tipo == TK_TIPO_STRING)
		return "string";

	return "";
}

atributos tratadoraLogic(int t1, string atr1_label, int t2, string atr2_label, string sinal){

	atributos retorno;
	// o retorno de uma expressao logica deve ser bool
	retorno.tipo = TK_TIPO_BOOL;
	string nome = geradoraDeNomeDeVariaveis();

	// usando a mesma da arith, depois devo mudar pra uma tabela [to-do]
	int tipo_das_entradas = tipoResult(t1, t2);

	if (tipo_das_entradas == TK_TIPO_INT)
	{
		retorno.label = nome;

		retorno.traducao = "\t" + nome + " = " + atr1_label + " " + sinal + " " + atr2_label + ";\n";

		// tipo da variavel deve ser do tipo int por ser um bool, ou deve ser o tipo da tipo_das_entradas? [to-do]
		variavel v =  criadorDeVariavel(nome, nome, getTipoString(tipo_das_entradas), 0);
	}
	else if(tipo_das_entradas == TK_TIPO_FLOAT){

		string nomeReal = geradoraDeNomeDeVariaveis();
		
		retorno.label = nomeReal;

		// variavel usada pra fazer o cast pra float
		variavel v =  criadorDeVariavel(nome, nome, "float", 0);
		// int por ser bool? [to-do]
		v =  criadorDeVariavel(nomeReal, nomeReal, "int", 0);

		if (t1 == TK_TIPO_INT)
		{
			retorno.traducao = "\t" + nome + " = (float) " + atr1_label + ";\n";
			retorno.traducao += "\t" + nomeReal + " = " + nome + " " + sinal + " " + atr2_label + ";\n";
		}
		else if (t2 == TK_TIPO_INT)
		{	
			retorno.traducao = "\t" + nome + " = (float) " + atr2_label + ";\n";
			retorno.traducao += "\t" + nomeReal + " = " + atr1_label + " " + sinal + " " + nomeReal + ";\n";
		}

	}




	return retorno;


}

int tipoResult(int t1, int t2){

	// verificando com if, deveria ter uma tabela, fazer depois por demandar mais tempo

	if ( (t1 != TK_TIPO_FLOAT && t1 != TK_TIPO_INT) || (t2 != TK_TIPO_FLOAT && t2 != TK_TIPO_INT) )
	{

		if (t1 == TK_TIPO_CHAR && t2 == TK_TIPO_CHAR)
		{
			return TK_TIPO_CHAR;
		}
		else if (t1 == TK_TIPO_BOOL && t2 == TK_TIPO_BOOL)
		{
			return TK_TIPO_BOOL;
		}
		else if (t1 == TK_TIPO_STRING && t2 == TK_TIPO_STRING)
		{
			return TK_TIPO_STRING;
		}
		// tipo de operadores invalidos
		cout << error_msg << endl;
		cout << "tipo de operadores invalidos" << endl;
		exit(0);

	}

	if (t1 == TK_TIPO_FLOAT || t2 == TK_TIPO_FLOAT)
	{
		return TK_TIPO_FLOAT;
	}
	else{
		return TK_TIPO_INT;
	}
}

atributos tratarArithComCast(int tipo1, string atr1_label, int tipo2, string atr2_label, string sinal){

	int tipo_atual = tipoResult(tipo1, tipo2);

	string line = "", line2 = "";

	string nome = geradoraDeNomeDeVariaveis();
	string nomeReal = geradoraDeNomeDeVariaveis();

	// devo castiar
	if (tipo_atual == TK_TIPO_FLOAT)
	{
		
		if (tipo1 == TK_TIPO_INT)
		{
			line = "\t" + nome + " = (float) " + atr1_label + ";\n";
			line2 = "\t" + nomeReal + " = " + nome + " " + sinal + " " + atr2_label + ";\n";
		}
		else if (tipo2 == TK_TIPO_INT)
		{
			line = "\t" + nome + " = (float) " + atr2_label + ";\n";
			line2 = "\t" + nomeReal + " = " + atr1_label + " " + sinal + " " + nome + ";\n";
		}

		variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), 0);
		v = criadorDeVariavel(nomeReal, nomeReal, getTipoString(tipo_atual), 0);

	}

	atributos turn;
	turn.traducao = line + line2;
	turn.label = nomeReal;
	return turn;

}

atributos tratadoraArith(atributos a1, atributos a2, string sinal){
	
	atributos retorno;
	cout << "tipo" << endl;
	cout << a1.tipo << endl;
	cout << a2.tipo << endl;
	cout << a1.label << endl;
	retorno.tipo = tipoResult(a1.tipo, a2.tipo);
	

	// sem precisar cast
	if (a1.tipo == a2.tipo)
	{
		string nome = geradoraDeNomeDeVariaveis();
		
		retorno.traducao = a1.traducao + a2.traducao + "\t" + nome + " = " + a1.label + " " + sinal + " " + a2.label + ";\n";
	
		retorno.label = nome;

		variavel v = criadorDeVariavel(nome, nome, getTipoString(retorno.tipo), 0);

	}
	else{ // CASTando

		// fazer o cast dependendo do tipo
		atributos atr = tratarArithComCast(a1.tipo, a1.label, a2.tipo, a2.label, sinal);
		atr.tipo = retorno.tipo;

		retorno.traducao = a1.traducao + a2.traducao + atr.traducao;
	
		retorno.label = atr.label;
	}
	

	return retorno;
}	

atributos concatenarStrings(atributos a1, atributos a2){

	string nome = geradoraDeNomeDeVariaveis();

	variavel v1 = getVarPorNome(a1.label);
	variavel v2 = getVarPorNome(a2.label);
	
	variavel v = criadorDeVariavel(nome, nome, getTipoString(TK_TIPO_STRING), (a1.tamanho + a2.tamanho));

	cout << "nome" << endl;
	cout << nome << endl;
	cout << a1.tamanho << endl;
	cout << a2.tamanho << endl;
	cout << v.tamanho << endl;

	string l1 = "\tstrcat(" +nome+ ", " +a1.label+ ");\n";
	string l2 = "\tstrcat(" +nome+ ", " +a2.label+ ");\n";

	atributos atr;
	atr.label = nome;
	atr.traducao = l1 + l2;
	atr.tipo = TK_TIPO_STRING;
	atr.tamanho = (a1.tamanho + a2.tamanho);

	cout << "nome" << endl;

	return atr;

}


variavel getVarPorNome(string name){

	// DECLARADAS
	cout << "DECLARADAS" << endl;
	cout << exibirVarsDeclaradas() << endl;

	// quando for blocos devo procurar no vetor

	Var_table vt = tack->variaveis_map[tack->escopo_num];

	// variavel ja declarada
	if ( vt.count(name) )
	{
		cout << "achou " << name <<endl;
		return vt[name];
	}
	else {
		int esc = tack->escopo_num-1;
		// cout << "esc " << esc << endl;
		for (int i = esc; i > -1; i--)
		{
			Var_table vt = tack->variaveis_map[i];

			if ( vt.count(name) )
			{
				cout << "achou " << name <<endl;

				return vt[name];
			}
		} 
	}
	// cout << "_______ " << tack->variaveis_map[tack->escopo_num][name].var_name << endl;
	// return criarVar("", "", "",  0);
	// return tack->variaveis_map[tack->escopo_num][name];

	cout << "Essa variavel nao 'existe' : " << name << endl;
	return vt[0];
}

string geradorTextGoto(int token){
	static int num_label = 0;
	
	if (token == TK_IF)
	{
		return "token_if_" + to_string(num_label++);
	}
	else if (token == TK_FOR)
	{
		return "token_for_" +to_string(num_label++);
	}
	else if (token == TK_WHILE)
	{
		return "token_while_" +to_string(num_label++);
	}

	return "ISSo nao deveria estar retornando 1 ";
}



const vector<string> explode(const string& s, const char& c)
{
	string buff = "";
	vector<string> v;

	for (int n = 0; n < s.size(); ++n)
	{
		if(s.at(n) != c) buff+=s.at(n); else
		if(s.at(n) == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	
	if(buff != "") v.push_back(buff);
	
	return v;
}




