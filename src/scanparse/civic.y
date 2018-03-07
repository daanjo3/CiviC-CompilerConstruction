%{


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

%}

%union {
 nodetype            nodetype;
 char               *id;
 int                 cint;
 float               cflt;
 binop               cbinop;
 node               *node;
 basictype          basictype;
}

%token BRACKET_L BRACKET_R BRACE_L BRACE_R COMMA SEMICOLON
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE OR AND
%token TRUEVAL FALSEVAL LET NEG
%token DO WHILE FOR IF ELSE RETURN EXTERN EXPORT

%token <basictype> TYPE_BOOL
%token <basictype> TYPE_INT
%token <basictype> TYPE_FLOAT
%token <basictype> TYPE_VOID

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

%type <node> declarations declaration
%type <node>fundec fundef globaldec globaldef

/* All types above is new, all types below are example code */

%type <node> intval floatval boolval constant expr
%type <node> stmts stmt assign varlet program
%type <cbinop> binop

%start program

%%

/* TOP LEVEL SYNTAX */

program: declarations
          {
            parseresult = $1;
          }
          ;

declarations: declaration declarations
          {
            $$ = TBmakeDeclarations($1, $2);
          }
          |   declaration
          {
            $$ = TBmakeDeclarations($1, NULL);
          }
          ;

declaration:  fundec
          { $$ = $1; }
          |   fundef
          { $$ = $1; }
          | globaldec
          { $$ = $1; }
          | globaldef
          { $$ = $1; }
          ;

fundec:   EXTERN funheader SEMICOLON
          {
            $$ = TBmakeFundec($2);
          }
          ;

fundef:    export funheader BRACE_L funbody BRACE_R
          { $$ = TBmakeFundef(TRUE, $2, $4); }
          ;

globaldec:  EXTERN type ID SEMICOLON
          {
            $$ = TBmakeGlobaldec($2, $3);
          }
          ;

globaldef:  EXPORT type ID LET expr
          { $$ = TBmakeGlobaldef($2, $1, $3, $4); }
          | EXPORT type ID
          { $$ = TBmakeGlobaldef($2, $1, $3, NULL); }
          ;

funheader:  rettype ID BRACKET_L BRACKET_R
          { $$ = TBmakeFunheader($1, NULL, $2); }
          | rettype ID BRACKET_L params BRACKET_R
          { $$ = TBmakeFunheader($1, $4, $2); }
          ;

params:     param COMMA params
          { $$ = TBmakeParams($1, $3); }
          | param
          { $$ = TBmakeParams($1, NULL); }

param:     type ID
          { $$ = TBmakeParam($1, $2); }

rettype:  TYPE_VOID
          { $$ = $1; }
          | type
          { $$ = $1; }
          ;

type:     TYPE_INT
          { $$ = $1; }
          | TYPE_FLOAT
          { $$ = $1; }
          | TYPE_BOOL
          { $$ = $1; }
          ;

export:   EXPORT
          { $$ = TRUE; }
          | %empty
          { $$ = FALSE; }
          ;

/* STATEMENT LANGUAGE */


/* Everything above is new, everything below is example code */

program: stmts
         {
           parseresult = $1;
         }
         ;

stmts: stmt stmts
        {
          $$ = TBmakeStmts( $1, $2);
        }
      | stmt
        {
          $$ = TBmakeStmts( $1, NULL);
        }
        ;

stmt: assign
       {
         $$ = $1;
       }
       ;

assign: varlet LET expr SEMICOLON
        {
          $$ = TBmakeAssign( $1, $3);
        }
        ;

varlet: ID
        {
          $$ = TBmakeVarlet( STRcpy( $1));
        }
        ;


expr: constant
      {
        $$ = $1;
      }
    | ID
      {
        $$ = TBmakeVar( STRcpy( $1));
      }
    | BRACKET_L expr binop expr BRACKET_R
      {
        $$ = TBmakeBinop( $3, $2, $4);
      }
    ;

constant: floatval
          {
            $$ = $1;
          }
        | intval
          {
            $$ = $1;
          }
        | boolval
          {
            $$ = $1;
          }
        ;

floatval: FLOAT
           {
             $$ = TBmakeFloat( $1);
           }
         ;

intval: NUM
        {
          $$ = TBmakeNum( $1);
        }
      ;

boolval: TRUEVAL
         {
           $$ = TBmakeBool( TRUE);
         }
       | FALSEVAL
         {
           $$ = TBmakeBool( FALSE);
         }
       ;

binop: PLUS      { $$ = BO_add; }
     | MINUS     { $$ = BO_sub; }
     | STAR      { $$ = BO_mul; }
     | SLASH     { $$ = BO_div; }
     | PERCENT   { $$ = BO_mod; }
     | LE        { $$ = BO_le; }
     | LT        { $$ = BO_lt; }
     | GE        { $$ = BO_ge; }
     | GT        { $$ = BO_gt; }
     | EQ        { $$ = BO_eq; }
     | OR        { $$ = BO_or; }
     | AND       { $$ = BO_and; }
     ;

%%

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
