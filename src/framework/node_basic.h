
/**
 * @file node_basic.h
 *
 * Functions to allocate node structures
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: node_basic.h.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_NODE_BASIC_H_
#define _SAC_NODE_BASIC_H_

#include "types.h"


#define _SAC_AST_VERSION_ "0.9"


/*****************************************************************************
 * macros and functions for N_declarations
 *****************************************************************************/

#define DECLARATIONS_DECLARATION( n) ((n)->sons.N_declarations->Declaration)
#define DECLARATIONS_NEXT( n) ((n)->sons.N_declarations->Next)
extern node *TBmakeDeclarations (node * Declaration, node * Next);

/*****************************************************************************
 * macros and functions for N_fundefdec
 *****************************************************************************/

#define FUNDEFDEC_PARAM( n) ((n)->sons.N_fundefdec->Param)
#define FUNDEFDEC_BODY( n) ((n)->sons.N_fundefdec->Body)
#define FUNDEFDEC_EXPORT( n) ((n)->attribs.N_fundefdec->Export)
#define FUNDEFDEC_RETTYPE( n) ((n)->attribs.N_fundefdec->RetType)
#define FUNDEFDEC_ID( n) ((n)->attribs.N_fundefdec->Id)
extern node *TBmakeFundefdec (bool Export, basictype RetType, char *Id,
			      node * Param, node * Body);

/*****************************************************************************
 * macros and functions for N_funbody
 *****************************************************************************/

#define FUNBODY_VARDEC( n) ((n)->sons.N_funbody->VarDec)
#define FUNBODY_LOCALFUNDEFS( n) ((n)->sons.N_funbody->LocalFunDefs)
#define FUNBODY_STATEMENTS( n) ((n)->sons.N_funbody->Statements)
extern node *TBmakeFunbody (node * VarDec, node * LocalFunDefs,
			    node * Statements);

/*****************************************************************************
 * macros and functions for N_vardec
 *****************************************************************************/

#define VARDEC_EXPR( n) ((n)->sons.N_vardec->Expr)
#define VARDEC_NEXT( n) ((n)->sons.N_vardec->Next)
#define VARDEC_TYPE( n) ((n)->attribs.N_vardec->Type)
#define VARDEC_ID( n) ((n)->attribs.N_vardec->Id)
extern node *TBmakeVardec (basictype Type, char *Id, node * Expr,
			   node * Next);

/*****************************************************************************
 * macros and functions for N_localfundefs
 *****************************************************************************/

#define LOCALFUNDEFS_FIRST( n) ((n)->sons.N_localfundefs->First)
#define LOCALFUNDEFS_NEXT( n) ((n)->sons.N_localfundefs->Next)
extern node *TBmakeLocalfundefs (node * First, node * Next);

/*****************************************************************************
 * macros and functions for N_globaldec
 *****************************************************************************/

#define GLOBALDEC_TYPE( n) ((n)->attribs.N_globaldec->Type)
#define GLOBALDEC_ID( n) ((n)->attribs.N_globaldec->Id)
extern node *TBmakeGlobaldec (basictype Type, char *Id);

/*****************************************************************************
 * macros and functions for N_globaldef
 *****************************************************************************/

#define GLOBALDEF_EXPR( n) ((n)->sons.N_globaldef->Expr)
#define GLOBALDEF_TYPE( n) ((n)->attribs.N_globaldef->Type)
#define GLOBALDEF_EXPORT( n) ((n)->attribs.N_globaldef->Export)
#define GLOBALDEF_ID( n) ((n)->attribs.N_globaldef->Id)
extern node *TBmakeGlobaldef (basictype Type, bool Export, char *Id,
			      node * Expr);

/*****************************************************************************
 * macros and functions for N_param
 *****************************************************************************/

#define PARAM_NEXT( n) ((n)->sons.N_param->Next)
#define PARAM_TYPE( n) ((n)->attribs.N_param->Type)
#define PARAM_ID( n) ((n)->attribs.N_param->Id)
extern node *TBmakeParam (basictype Type, char *Id, node * Next);

/*****************************************************************************
 * macros and functions for N_id
 *****************************************************************************/

#define ID_NAME( n) ((n)->attribs.N_id->Name)
extern node *TBmakeId (char *Name);

/*****************************************************************************
 * macros and functions for N_stmts
 *****************************************************************************/

#define STMTS_FIRST( n) ((n)->sons.N_stmts->First)
#define STMTS_NEXT( n) ((n)->sons.N_stmts->Next)
extern node *TBmakeStmts (node * First, node * Next);

/*****************************************************************************
 * macros and functions for N_assign
 *****************************************************************************/

#define ASSIGN_ID( n) ((n)->sons.N_assign->Id)
#define ASSIGN_EXPR( n) ((n)->sons.N_assign->Expr)
extern node *TBmakeAssign (node * Id, node * Expr);

/*****************************************************************************
 * macros and functions for N_funcall
 *****************************************************************************/

#define FUNCALL_ID( n) ((n)->sons.N_funcall->Id)
#define FUNCALL_EXPRS( n) ((n)->sons.N_funcall->Exprs)
extern node *TBmakeFuncall (node * Id, node * Exprs);

/*****************************************************************************
 * macros and functions for N_if
 *****************************************************************************/

#define IF_EXPR( n) ((n)->sons.N_if->Expr)
#define IF_BLOCK( n) ((n)->sons.N_if->Block)
#define IF_ELSEBLOCK( n) ((n)->sons.N_if->ElseBlock)
extern node *TBmakeIf (node * Expr, node * Block, node * ElseBlock);

/*****************************************************************************
 * macros and functions for N_while
 *****************************************************************************/

#define WHILE_EXPR( n) ((n)->sons.N_while->Expr)
#define WHILE_BLOCK( n) ((n)->sons.N_while->Block)
extern node *TBmakeWhile (node * Expr, node * Block);

/*****************************************************************************
 * macros and functions for N_dowhile
 *****************************************************************************/

#define DOWHILE_EXPR( n) ((n)->sons.N_dowhile->Expr)
#define DOWHILE_BLOCK( n) ((n)->sons.N_dowhile->Block)
extern node *TBmakeDowhile (node * Expr, node * Block);

/*****************************************************************************
 * macros and functions for N_for
 *****************************************************************************/

#define FOR_ID( n) ((n)->sons.N_for->Id)
#define FOR_EXPRSTART( n) ((n)->sons.N_for->ExprStart)
#define FOR_EXPRSTOP( n) ((n)->sons.N_for->ExprStop)
#define FOR_EXPRINCR( n) ((n)->sons.N_for->ExprIncr)
#define FOR_BLOCK( n) ((n)->sons.N_for->Block)
extern node *TBmakeFor (node * Id, node * ExprStart, node * ExprStop,
			node * ExprIncr, node * Block);

/*****************************************************************************
 * macros and functions for N_return
 *****************************************************************************/

#define RETURN_EXPR( n) ((n)->sons.N_return->Expr)
extern node *TBmakeReturn (node * Expr);

/*****************************************************************************
 * macros and functions for N_exprs
 *****************************************************************************/

#define EXPRS_FIRST( n) ((n)->sons.N_exprs->First)
#define EXPRS_NEXT( n) ((n)->sons.N_exprs->Next)
extern node *TBmakeExprs (node * First, node * Next);

/*****************************************************************************
 * macros and functions for N_binop
 *****************************************************************************/

#define BINOP_LEFT( n) ((n)->sons.N_binop->Left)
#define BINOP_RIGHT( n) ((n)->sons.N_binop->Right)
#define BINOP_OP( n) ((n)->attribs.N_binop->Op)
extern node *TBmakeBinop (binop Op, node * Left, node * Right);

/*****************************************************************************
 * macros and functions for N_monop
 *****************************************************************************/

#define MONOP_EXPR( n) ((n)->sons.N_monop->Expr)
#define MONOP_OP( n) ((n)->attribs.N_monop->Op)
extern node *TBmakeMonop (monop Op, node * Expr);

/*****************************************************************************
 * macros and functions for N_cast
 *****************************************************************************/

#define CAST_EXPR( n) ((n)->sons.N_cast->Expr)
#define CAST_CASTTYPE( n) ((n)->attribs.N_cast->CastType)
extern node *TBmakeCast (basictype CastType, node * Expr);

/*****************************************************************************
 * macros and functions for N_num
 *****************************************************************************/

#define NUM_VALUE( n) ((n)->attribs.N_num->Value)
extern node *TBmakeNum (int Value);

/*****************************************************************************
 * macros and functions for N_float
 *****************************************************************************/

#define FLOAT_VALUE( n) ((n)->attribs.N_float->Value)
extern node *TBmakeFloat (float Value);

/*****************************************************************************
 * macros and functions for N_bool
 *****************************************************************************/

#define BOOL_VALUE( n) ((n)->attribs.N_bool->Value)
extern node *TBmakeBool (bool Value);

/*****************************************************************************
 * macros and functions for N_symboltable
 *****************************************************************************/

#define SYMBOLTABLE_HEAD( n) ((n)->sons.N_symboltable->Head)
#define SYMBOLTABLE_PARENT( n) ((n)->attribs.N_symboltable->Parent)
extern node *TBmakeSymboltable (node * Head);

/*****************************************************************************
 * macros and functions for N_symboltableentry
 *****************************************************************************/

#define SYMBOLTABLEENTRY_NEXT( n) ((n)->sons.N_symboltableentry->Next)
#define SYMBOLTABLEENTRY_FUNTYPES( n) ((n)->sons.N_symboltableentry->FunTypes)
#define SYMBOLTABLEENTRY_NAME( n) ((n)->attribs.N_symboltableentry->Name)
#define SYMBOLTABLEENTRY_TYPE( n) ((n)->attribs.N_symboltableentry->Type)
#define SYMBOLTABLEENTRY_FUNCTION( n) ((n)->attribs.N_symboltableentry->Function)
extern node *TBmakeSymboltableentry (char *Name, basictype Type,
				     bool Function, node * Next,
				     node * FunTypes);

/*****************************************************************************
 * macros and functions for N_stefuntype
 *****************************************************************************/

#define STEFUNTYPE_NEXT( n) ((n)->sons.N_stefuntype->Next)
#define STEFUNTYPE_TYPE( n) ((n)->attribs.N_stefuntype->Type)
extern node *TBmakeStefuntype (basictype Type, node * Next);

/*****************************************************************************
 * macros and functions for N_error
 *****************************************************************************/

#define ERROR_NEXT( n) ((n)->sons.N_error->Next)
#define ERROR_MESSAGE( n) ((n)->attribs.N_error->message)
#define ERROR_ANYPHASE( n) ((n)->attribs.N_error->anyphase)
extern node *TBmakeError (char *message, compiler_phase_t anyphase,
			  node * Next);

#endif /* _SAC_NODE_BASIC_H_ */
