
/**
 * @file copy_node.c
 *
 * Functions needed by copy traversal.
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * copy_node.c.xsl.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

/**
 * @defgroup copy Copy Tree Functions.
 *
 * Functions needed by copy traversal.
 *
 * @{
 */


#include "copy_node.h"
#include "copy_info.h"
#include "traverse.h"
#include "dbug.h"
#include "tree_basic.h"
#include "str.h"
#include "lookup_table.h"


#define COPYTRAV( node, info) (node != NULL) ? TRAVdo( node, info) : node


/** <!--******************************************************************-->
 *
 * @fn COPYassign
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Assign node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYassign (node * arg_node, info * arg_info)
{
  node *result = TBmakeAssign (NULL, NULL);
  DBUG_ENTER ("COPYassign");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  ASSIGN_ID (result) = STRcpy (ASSIGN_ID (arg_node));
  /* Copy sons */
  ASSIGN_EXPR (result) = COPYTRAV (ASSIGN_EXPR (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYbinop
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYbinop (node * arg_node, info * arg_info)
{
  node *result = TBmakeBinop (BO_unknown, NULL, NULL);
  DBUG_ENTER ("COPYbinop");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  BINOP_OP (result) = BINOP_OP (arg_node);
  BINOP_EXPRESSIONTYPE (result) = BINOP_EXPRESSIONTYPE (arg_node);
  /* Copy sons */
  BINOP_LEFT (result) = COPYTRAV (BINOP_LEFT (arg_node), arg_info);
  BINOP_RIGHT (result) = COPYTRAV (BINOP_RIGHT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYbool
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Bool node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYbool (node * arg_node, info * arg_info)
{
  node *result = TBmakeBool (FALSE);
  DBUG_ENTER ("COPYbool");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  BOOL_VALUE (result) = BOOL_VALUE (arg_node);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYcast
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Cast node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYcast (node * arg_node, info * arg_info)
{
  node *result = TBmakeCast (BT_unknown, NULL);
  DBUG_ENTER ("COPYcast");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  CAST_CASTTYPE (result) = CAST_CASTTYPE (arg_node);
  /* Copy sons */
  CAST_EXPR (result) = COPYTRAV (CAST_EXPR (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYcondexpr
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node CondExpr node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYcondexpr (node * arg_node, info * arg_info)
{
  node *result = TBmakeCondexpr (NULL, NULL, NULL);
  DBUG_ENTER ("COPYcondexpr");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  CONDEXPR_PRED (result) = COPYTRAV (CONDEXPR_PRED (arg_node), arg_info);
  CONDEXPR_THEN (result) = COPYTRAV (CONDEXPR_THEN (arg_node), arg_info);
  CONDEXPR_ELSE (result) = COPYTRAV (CONDEXPR_ELSE (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYdeclarations
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Declarations node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYdeclarations (node * arg_node, info * arg_info)
{
  node *result = TBmakeDeclarations (NULL, NULL);
  DBUG_ENTER ("COPYdeclarations");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  DECLARATIONS_DECLARATION (result) =
    COPYTRAV (DECLARATIONS_DECLARATION (arg_node), arg_info);
  DECLARATIONS_NEXT (result) =
    COPYTRAV (DECLARATIONS_NEXT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYdowhile
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node DoWhile node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYdowhile (node * arg_node, info * arg_info)
{
  node *result = TBmakeDowhile (NULL, NULL);
  DBUG_ENTER ("COPYdowhile");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  DOWHILE_EXPR (result) = COPYTRAV (DOWHILE_EXPR (arg_node), arg_info);
  DOWHILE_BLOCK (result) = COPYTRAV (DOWHILE_BLOCK (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYerror
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Error node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYerror (node * arg_node, info * arg_info)
{
  node *result = TBmakeError (NULL, PH_initial, NULL);
  DBUG_ENTER ("COPYerror");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  ERROR_MESSAGE (result) = STRcpy (ERROR_MESSAGE (arg_node));
  ERROR_ANYPHASE (result) = ERROR_ANYPHASE (arg_node);
  /* Copy sons */
  ERROR_NEXT (result) = COPYTRAV (ERROR_NEXT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYexprs
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Exprs node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYexprs (node * arg_node, info * arg_info)
{
  node *result = TBmakeExprs (NULL, NULL);
  DBUG_ENTER ("COPYexprs");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  EXPRS_FIRST (result) = COPYTRAV (EXPRS_FIRST (arg_node), arg_info);
  EXPRS_NEXT (result) = COPYTRAV (EXPRS_NEXT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYfloat
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Float node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYfloat (node * arg_node, info * arg_info)
{
  node *result = TBmakeFloat (0.0);
  DBUG_ENTER ("COPYfloat");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  FLOAT_VALUE (result) = FLOAT_VALUE (arg_node);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYfor
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node For node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYfor (node * arg_node, info * arg_info)
{
  node *result = TBmakeFor (NULL, NULL, NULL, NULL, NULL);
  DBUG_ENTER ("COPYfor");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  FOR_ID (result) = STRcpy (FOR_ID (arg_node));
  /* Copy sons */
  FOR_EXPRSTART (result) = COPYTRAV (FOR_EXPRSTART (arg_node), arg_info);
  FOR_EXPRSTOP (result) = COPYTRAV (FOR_EXPRSTOP (arg_node), arg_info);
  FOR_EXPRINCR (result) = COPYTRAV (FOR_EXPRINCR (arg_node), arg_info);
  FOR_BLOCK (result) = COPYTRAV (FOR_BLOCK (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYfunbody
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node FunBody node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYfunbody (node * arg_node, info * arg_info)
{
  node *result = TBmakeFunbody (NULL, NULL, NULL);
  DBUG_ENTER ("COPYfunbody");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  FUNBODY_VARDEC (result) = COPYTRAV (FUNBODY_VARDEC (arg_node), arg_info);
  FUNBODY_LOCALFUNDEFS (result) =
    COPYTRAV (FUNBODY_LOCALFUNDEFS (arg_node), arg_info);
  FUNBODY_STATEMENTS (result) =
    COPYTRAV (FUNBODY_STATEMENTS (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYfuncall
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node FunCall node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYfuncall (node * arg_node, info * arg_info)
{
  node *result = TBmakeFuncall (NULL, NULL);
  DBUG_ENTER ("COPYfuncall");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  FUNCALL_ID (result) = STRcpy (FUNCALL_ID (arg_node));
  /* Copy sons */
  FUNCALL_EXPRS (result) = COPYTRAV (FUNCALL_EXPRS (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYfundefdec
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node FunDefDec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYfundefdec (node * arg_node, info * arg_info)
{
  node *result = TBmakeFundefdec (FALSE, BT_unknown, NULL, NULL, NULL, NULL);
  DBUG_ENTER ("COPYfundefdec");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  FUNDEFDEC_EXPORT (result) = FUNDEFDEC_EXPORT (arg_node);
  FUNDEFDEC_RETTYPE (result) = FUNDEFDEC_RETTYPE (arg_node);
  FUNDEFDEC_ID (result) = STRcpy (FUNDEFDEC_ID (arg_node));
  /* Copy sons */
  FUNDEFDEC_PARAM (result) = COPYTRAV (FUNDEFDEC_PARAM (arg_node), arg_info);
  FUNDEFDEC_BODY (result) = COPYTRAV (FUNDEFDEC_BODY (arg_node), arg_info);
  FUNDEFDEC_SYMBOLTABLE (result) =
    COPYTRAV (FUNDEFDEC_SYMBOLTABLE (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYglobaldec
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node GlobalDec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYglobaldec (node * arg_node, info * arg_info)
{
  node *result = TBmakeGlobaldec (BT_unknown, NULL);
  DBUG_ENTER ("COPYglobaldec");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  GLOBALDEC_TYPE (result) = GLOBALDEC_TYPE (arg_node);
  GLOBALDEC_ID (result) = STRcpy (GLOBALDEC_ID (arg_node));
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYglobaldef
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node GlobalDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYglobaldef (node * arg_node, info * arg_info)
{
  node *result = TBmakeGlobaldef (BT_unknown, FALSE, NULL, NULL);
  DBUG_ENTER ("COPYglobaldef");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  GLOBALDEF_TYPE (result) = GLOBALDEF_TYPE (arg_node);
  GLOBALDEF_EXPORT (result) = GLOBALDEF_EXPORT (arg_node);
  GLOBALDEF_ID (result) = STRcpy (GLOBALDEF_ID (arg_node));
  /* Copy sons */
  GLOBALDEF_EXPR (result) = COPYTRAV (GLOBALDEF_EXPR (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYif
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node If node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYif (node * arg_node, info * arg_info)
{
  node *result = TBmakeIf (NULL, NULL, NULL);
  DBUG_ENTER ("COPYif");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  IF_EXPR (result) = COPYTRAV (IF_EXPR (arg_node), arg_info);
  IF_BLOCK (result) = COPYTRAV (IF_BLOCK (arg_node), arg_info);
  IF_ELSEBLOCK (result) = COPYTRAV (IF_ELSEBLOCK (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYlocalfundefs
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node LocalFunDefs node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYlocalfundefs (node * arg_node, info * arg_info)
{
  node *result = TBmakeLocalfundefs (NULL, NULL);
  DBUG_ENTER ("COPYlocalfundefs");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  LOCALFUNDEFS_FIRST (result) =
    COPYTRAV (LOCALFUNDEFS_FIRST (arg_node), arg_info);
  LOCALFUNDEFS_NEXT (result) =
    COPYTRAV (LOCALFUNDEFS_NEXT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYmonop
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node MonOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYmonop (node * arg_node, info * arg_info)
{
  node *result = TBmakeMonop (MO_unknown, NULL);
  DBUG_ENTER ("COPYmonop");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  MONOP_OP (result) = MONOP_OP (arg_node);
  MONOP_EXPRESSIONTYPE (result) = MONOP_EXPRESSIONTYPE (arg_node);
  /* Copy sons */
  MONOP_EXPR (result) = COPYTRAV (MONOP_EXPR (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYnum
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Num node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYnum (node * arg_node, info * arg_info)
{
  node *result = TBmakeNum (0);
  DBUG_ENTER ("COPYnum");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  NUM_VALUE (result) = NUM_VALUE (arg_node);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYparam
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Param node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYparam (node * arg_node, info * arg_info)
{
  node *result = TBmakeParam (BT_unknown, NULL, NULL);
  DBUG_ENTER ("COPYparam");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  PARAM_TYPE (result) = PARAM_TYPE (arg_node);
  /* Copy sons */
  PARAM_ID (result) = COPYTRAV (PARAM_ID (arg_node), arg_info);
  PARAM_NEXT (result) = COPYTRAV (PARAM_NEXT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYprogram
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Program node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYprogram (node * arg_node, info * arg_info)
{
  node *result = TBmakeProgram (NULL, NULL);
  DBUG_ENTER ("COPYprogram");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  PROGRAM_DECLARATIONS (result) =
    COPYTRAV (PROGRAM_DECLARATIONS (arg_node), arg_info);
  PROGRAM_SYMBOLTABLE (result) =
    COPYTRAV (PROGRAM_SYMBOLTABLE (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYreturn
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Return node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYreturn (node * arg_node, info * arg_info)
{
  node *result = TBmakeReturn (NULL);
  DBUG_ENTER ("COPYreturn");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  RETURN_EXPR (result) = COPYTRAV (RETURN_EXPR (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYstatements
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Statements node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYstatements (node * arg_node, info * arg_info)
{
  node *result = TBmakeStatements (NULL, NULL);
  DBUG_ENTER ("COPYstatements");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  STATEMENTS_FIRST (result) =
    COPYTRAV (STATEMENTS_FIRST (arg_node), arg_info);
  STATEMENTS_NEXT (result) = COPYTRAV (STATEMENTS_NEXT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYsymboltable
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node SymbolTable node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYsymboltable (node * arg_node, info * arg_info)
{
  node *result = TBmakeSymboltable (NULL);
  DBUG_ENTER ("COPYsymboltable");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  SYMBOLTABLE_PARENT (result) =
    LUTsearchInLutPp (INFO_LUT (arg_info), SYMBOLTABLE_PARENT (arg_node));
  /* Copy sons */
  SYMBOLTABLE_HEAD (result) =
    COPYTRAV (SYMBOLTABLE_HEAD (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYsymboltableentry
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node SymbolTableEntry node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYsymboltableentry (node * arg_node, info * arg_info)
{
  node *result = TBmakeSymboltableentry (NULL, BT_unknown, FALSE, NULL);
  DBUG_ENTER ("COPYsymboltableentry");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  SYMBOLTABLEENTRY_NAME (result) = STRcpy (SYMBOLTABLEENTRY_NAME (arg_node));
  SYMBOLTABLEENTRY_TYPE (result) = SYMBOLTABLEENTRY_TYPE (arg_node);
  SYMBOLTABLEENTRY_FUNCTION (result) = SYMBOLTABLEENTRY_FUNCTION (arg_node);
  SYMBOLTABLEENTRY_PARAMS (result) =
    LUTsearchInLutPp (INFO_LUT (arg_info),
		      SYMBOLTABLEENTRY_PARAMS (arg_node));
  /* Copy sons */
  SYMBOLTABLEENTRY_NEXT (result) =
    COPYTRAV (SYMBOLTABLEENTRY_NEXT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYvar
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node Var node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYvar (node * arg_node, info * arg_info)
{
  node *result = TBmakeVar (NULL);
  DBUG_ENTER ("COPYvar");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  VAR_NAME (result) = STRcpy (VAR_NAME (arg_node));
  VAR_LINK (result) =
    LUTsearchInLutPp (INFO_LUT (arg_info), VAR_LINK (arg_node));
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYvardec
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node VarDec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYvardec (node * arg_node, info * arg_info)
{
  node *result = TBmakeVardec (BT_unknown, NULL, NULL, NULL);
  DBUG_ENTER ("COPYvardec");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy attributes */
  VARDEC_TYPE (result) = VARDEC_TYPE (arg_node);
  VARDEC_ID (result) = STRcpy (VARDEC_ID (arg_node));
  /* Copy sons */
  VARDEC_EXPR (result) = COPYTRAV (VARDEC_EXPR (arg_node), arg_info);
  VARDEC_NEXT (result) = COPYTRAV (VARDEC_NEXT (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/** <!--******************************************************************-->
 *
 * @fn COPYwhile
 *
 * @brief Copies the node and its sons/attributes
 *
 * @param arg_node While node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
COPYwhile (node * arg_node, info * arg_info)
{
  node *result = TBmakeWhile (NULL, NULL);
  DBUG_ENTER ("COPYwhile");
  LUTinsertIntoLutP (INFO_LUT (arg_info), arg_node, result);
  /* Copy sons */
  WHILE_EXPR (result) = COPYTRAV (WHILE_EXPR (arg_node), arg_info);
  WHILE_BLOCK (result) = COPYTRAV (WHILE_BLOCK (arg_node), arg_info);
  /* Return value */
  DBUG_RETURN (result);
}

/**
 * @}
 */
