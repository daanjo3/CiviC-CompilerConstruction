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
 monop               monop;
 node               *node;
 basictype          basictype;
}

%token TYPE_BOOL TYPE_INT TYPE_VOID TYPE_FLOAT
%token BRACKET_L BRACKET_R BRACE_L BRACE_R COMMA SEMICOLON
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE AND OR NOT LET
%token DO WHILE FOR IF ELSE RETURN EXTERN EXPORT
%token TRUEVAL FALSEVAL 
%token COMMENT_SINGLE COMMENT_MULT

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

%type <node> declarations declaration fundefdec globaldec globaldef
%type <node> param id binop monop cast funcall
%type <node> funbody vardecs localfundefs stmts stmt for if block
%type <node> exprs expr

%type <basictype> type

%left MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE AND OR NOT
%left BRACKET_R SEMICOLON

%expect 1
%start program

%%

program:  declarations
          { parseresult = $1; }
          ;

declarations: declarations declaration
              { $$ = TBmakeDeclarations($2, $1); }
              | declaration
              { $$ = TBmakeDeclarations($1, NULL); }
              ;

declaration:  fundefdec
              { $$ = $1; }
              | globaldec
              { $$ = $1; }
              | globaldef
              { $$ = $1; }
              ;

fundefdec:  EXPORT type ID BRACKET_L BRACKET_R BRACE_L funbody BRACE_R
            { $$ = TBmakeFundefdec(TRUE, $2, $3, NULL, $7); }
            | EXPORT type ID BRACKET_L BRACKET_R param BRACE_L funbody BRACE_R
            { $$ = TBmakeFundefdec(TRUE, $2, $3, $6, $8); }
            | type ID BRACKET_L BRACKET_R BRACE_L funbody BRACE_R
            { $$ = TBmakeFundefdec(FALSE, $1, $2, NULL, $6); }
            | type ID BRACKET_L BRACKET_R param BRACE_L funbody BRACE_R
            { $$ = TBmakeFundefdec(FALSE, $1, $2, $5, $7); }
            | EXTERN type ID BRACKET_L BRACKET_R SEMICOLON
            { $$ = TBmakeFundefdec(FALSE, $2, $3, NULL, NULL); }
            | EXTERN type ID BRACKET_L param BRACKET_R SEMICOLON
            { $$ = TBmakeFundefdec(FALSE, $2, $3, $5, NULL); }
            ;

globaldec:  EXTERN type ID SEMICOLON
            { $$ = TBmakeGlobaldec($2, $3); }
            ;

globaldef:  EXPORT type ID LET expr SEMICOLON
            { $$ = TBmakeGlobaldef($2, TRUE, $3, $5); }
            | EXPORT type ID SEMICOLON
            { $$ = TBmakeGlobaldef($2, TRUE, $3, NULL); }
            | type ID LET expr SEMICOLON
            { $$ = TBmakeGlobaldef($1, FALSE, $2, $4); }
            | type ID SEMICOLON
            { $$ = TBmakeGlobaldef($1, FALSE, $2, NULL); }
          ;

param:     type ID COMMA param
          { $$ = TBmakeParam($1, $2, $4); }
          | type ID
          { $$ = TBmakeParam($1, $2, NULL); }
          ;

type:     TYPE_INT
          { $$ = BT_int; }
          | TYPE_FLOAT
          { $$ = BT_float; }
          | TYPE_BOOL
          { $$ = BT_bool; }
          | TYPE_VOID
          { $$ = RT_void; }
          ;

funbody:  vardecs localfundefs stmts
          { $$ = TBmakeFunbody($1, $2, $3); }
          | vardecs localfundefs
          { $$ = TBmakeFunbody($1, $2, NULL); }
          | vardecs stmts
          { $$ = TBmakeFunbody($1, NULL, $2); }
          | localfundefs stmts
          { $$ = TBmakeFunbody(NULL, $1, $2); }
          | vardecs
          { $$ = TBmakeFunbody($1, NULL, NULL); }
          | localfundefs
          { $$ = TBmakeFunbody(NULL, $1, NULL); }
          | stmts
          { $$ = TBmakeFunbody(NULL, NULL, $1); }
          ;

vardecs:  vardecs type ID LET expr SEMICOLON
          { $$ = TBmakeVardec($2, $3, $5, $1); }
          | vardecs type ID SEMICOLON
          { $$ = TBmakeVardec($2, $3, NULL, $1); }
          | type ID LET expr SEMICOLON
          { $$ = TBmakeVardec($1, $2, $4, NULL); }
          | type ID SEMICOLON
          { $$ = TBmakeVardec($1, $2, NULL, NULL); }
          ;

localfundefs: fundefdec localfundefs
          { $$ = TBmakeLocalfundefs($1, $2); }
          | fundefdec
          { $$ = TBmakeLocalfundefs($1, NULL); }
          ;

stmts:    stmt stmts
          { $$ = TBmakeStmts( $1, $2); }
          | stmt
          { $$ = TBmakeStmts( $1, NULL); }
          ;

stmt:  id LET expr SEMICOLON
       { $$ = TBmakeAssign($1, $3); }
       | funcall SEMICOLON
       { $$ = $1; }
       | WHILE BRACKET_L expr BRACKET_R block
       { $$ = TBmakeWhile($3, $5); }
       | DO block WHILE BRACKET_L expr BRACKET_R SEMICOLON
       { $$ = TBmakeDowhile($5, $2); }
       | if
       { $$ = $1; }
       | for
       { $$ = $1; }
       | RETURN expr SEMICOLON
       { $$ = TBmakeReturn($2); }
       ;

for:      FOR BRACKET_L TYPE_INT id LET expr COMMA expr COMMA expr BRACKET_R block
          { $$ = TBmakeFor($4, $6, $8, $10, $12); }
          | FOR BRACKET_L TYPE_INT id LET expr COMMA expr BRACKET_R block
          { $$ = TBmakeFor($4, $6, $8, NULL, $10); }
          ;

if:       IF BRACKET_L expr BRACKET_R block ELSE block
          { $$ = TBmakeIf($3, $5, $7); }
          | IF BRACKET_L expr BRACKET_R block
          { $$ = TBmakeIf($3, $5, NULL); }
          ;

block:    BRACE_L stmts BRACE_R
          { $$ = $2; }
          | stmt
          { $$ = $1; }
          ;

exprs:  expr COMMA exprs
        { $$ = TBmakeExprs($1, $3); }
        | expr
        { $$ = TBmakeExprs($1, NULL); }
        ;

expr:   BRACKET_L expr BRACKET_R
        { $$ = $2; }
        | binop
        { $$ =  $1; }
        | monop
        { $$ = $1; }
        | cast
        { $$ = $1; }
        | id
        { $$ = $1; }
        | funcall
        { $$ = $1; }
        | FLOAT
        { $$ = TBmakeFloat($1); }
        | NUM
        { $$ = TBmakeNum($1); }
        | TRUEVAL
        { $$ = TBmakeBool(TRUE); }
        | FALSEVAL
        { $$ = TBmakeBool(FALSE); }
        ;

cast:   BRACKET_L type BRACKET_R expr
        { $$ = TBmakeCast($2, $4); }
        ;

funcall: id BRACKET_L exprs BRACKET_R
        { $$ = TBmakeFuncall($1, $3); }
        ;

monop:  MINUS expr      { $$ = TBmakeMonop(MO_neg, $2); }
        | NOT expr      { $$ = TBmakeMonop(MO_not, $2); }
        ;

binop:  expr PLUS expr       { $$ = TBmakeBinop(BO_add, $1, $3); }
       | expr MINUS expr     { $$ = TBmakeBinop(BO_sub, $1, $3); }
       | expr STAR expr      { $$ = TBmakeBinop(BO_mul, $1, $3); }
       | expr SLASH expr     { $$ = TBmakeBinop(BO_div, $1, $3); }
       | expr PERCENT expr   { $$ = TBmakeBinop(BO_mod, $1, $3); }
       | expr LE expr        { $$ = TBmakeBinop(BO_le, $1, $3); }
       | expr LT expr        { $$ = TBmakeBinop(BO_lt, $1, $3); }
       | expr GE expr        { $$ = TBmakeBinop(BO_ge, $1, $3); }
       | expr GT expr        { $$ = TBmakeBinop(BO_gt, $1, $3); }
       | expr EQ expr        { $$ = TBmakeBinop(BO_eq, $1, $3); }
       | expr NE expr        { $$ = TBmakeBinop(BO_ne, $1, $3); }
       | expr OR expr        { $$ = TBmakeBinop(BO_or, $1, $3); }
       | expr AND expr       { $$ = TBmakeBinop(BO_and, $1, $3); }
       ;

id:    ID 
      { $$ = TBmakeId($1); }
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
