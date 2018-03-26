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
#line 23 "src/scanparse/civic.y" /* yacc.c:1909  */

 nodetype            nodetype;
 char               *id;
 int                 cint;
 float               cflt;
 binop               cbinop;
 monop               monop;
 node               *node;
 basictype          basictype;

#line 149 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
