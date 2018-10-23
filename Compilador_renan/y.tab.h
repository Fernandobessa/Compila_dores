/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
