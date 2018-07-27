
/**
 * @file print.c
 *
 * Functions needed by print traversal.
 *
 */

/**
 * @defgroup print Print Functions.
 *
 * Functions needed by print traversal.
 *
 * @{
 */


#include "print.h"
#include "traverse.h"
#include "tree_basic.h"
#include "dbug.h"
#include "memory.h"
#include "globals.h"


/*
 * INFO structure
 */
struct INFO {
  bool firsterror;
  int indent;
};

#define INFO_FIRSTERROR(n) ((n)->firsterror)
#define INFO_INDENT(n) ((n)->indent)

static info *MakeInfo()
{
  info *result;

  result = MEMmalloc(sizeof(info));

  INFO_INDENT(result) = 0;
  INFO_FIRSTERROR(result) = FALSE;

  return result;
}

static info *FreeInfo( info *info)
{
  info = MEMfree( info);

  return info;
}

void printIndent(info *arg_info) {
  for(int i = 0; i < INFO_INDENT(arg_info); i++) {
    printf("    ");
  }
}

char *type_string(basictype type) {
    switch (type) {
    case BT_bool:
      return "boolean ";
    case BT_int:
      return "int ";
    case BT_float:
      return "float ";
    case RT_void:
      return "void ";
    case BT_unknown:
      DBUG_ASSERT(0, "unknown basictype selected!");
  }
  return " ";
}

node *PRTprogram(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTprogram");
  PROGRAM_DECLARATIONS(arg_node) = TRAVdo(PROGRAM_DECLARATIONS(arg_node), arg_info);
  PROGRAM_SYMBOLTABLE(arg_node) = TRAVopt(PROGRAM_SYMBOLTABLE(arg_node), arg_info);
  DBUG_RETURN(arg_node);
}

node *PRTdeclarations(node * arg_node, info * arg_info) {
   DBUG_ENTER("PRTdeclarations");
   DECLARATIONS_DECLARATION(arg_node) = TRAVdo(DECLARATIONS_DECLARATION(arg_node), arg_info);
   DECLARATIONS_NEXT(arg_node) = TRAVopt(DECLARATIONS_NEXT(arg_node), arg_info);
   DBUG_RETURN(arg_node);
 }

node *PRTfundefdec(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTfundefdec");
  printf("\n");
  printIndent(arg_info);

  if (FUNDEFDEC_EXPORT(arg_node)) {
    printf("export ");
  }
  if (!FUNDEFDEC_BODY(arg_node)) {
    printf("extern ");
  }

  char* type = type_string(FUNDEFDEC_RETTYPE(arg_node));
  printf("%s ", type);
  printf("%s ", FUNDEFDEC_ID(arg_node));
  printf("(");
  FUNDEFDEC_PARAM(arg_node) = TRAVopt(FUNDEFDEC_PARAM(arg_node), arg_info);
  if (FUNDEFDEC_BODY(arg_node)) {
    printf(") {\n");
    INFO_INDENT(arg_info) += 1;
    FUNDEFDEC_BODY(arg_node) = TRAVopt(FUNDEFDEC_BODY(arg_node), arg_info);
    INFO_INDENT(arg_info) -= 1;
    printIndent(arg_info);
    printf("}\n");
  } else {
    printf(");\n");
  }

  printf("\n");
  DBUG_RETURN(arg_node);
}

node *PRTfunbody(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTfunbody");
  FUNBODY_VARDEC(arg_node) = TRAVopt(FUNBODY_VARDEC(arg_node), arg_info);
  FUNBODY_LOCALFUNDEFS(arg_node) = TRAVopt(FUNBODY_LOCALFUNDEFS(arg_node), arg_info);
  FUNBODY_STATEMENTS(arg_node) = TRAVopt(FUNBODY_STATEMENTS(arg_node), arg_info);
  DBUG_RETURN(arg_node);
}

node *PRTvardec(node * arg_node, info * arg_info) {
  char* tmp;
  DBUG_ENTER("PRTvardec");

  printIndent(arg_info);
  tmp = type_string(VARDEC_TYPE(arg_node));
  printf("%s ", tmp);
  printf("%s", VARDEC_ID(arg_node));
  if (VARDEC_EXPR(arg_node) != NULL) {
    printf(" = ");
    VARDEC_EXPR(arg_node) = TRAVopt(VARDEC_EXPR(arg_node), arg_info);
  }
  printf(";\n");
  VARDEC_NEXT(arg_node) = TRAVopt(VARDEC_NEXT(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}
node *PRTlocalfundefs(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTlocalfundefs");
  printIndent(arg_info);
  LOCALFUNDEFS_FIRST(arg_node) = TRAVdo(LOCALFUNDEFS_FIRST(arg_node), arg_info);
  LOCALFUNDEFS_NEXT(arg_node) = TRAVopt(LOCALFUNDEFS_NEXT(arg_node), arg_info);
  DBUG_RETURN(arg_node);
}

node *PRTglobaldec(node * arg_node, info * arg_info) {
  char* tmp;
  DBUG_ENTER("PRTglobaldec");
  printf("extern ");
  tmp = type_string(GLOBALDEC_TYPE(arg_node));
  printf("%s ", tmp);
  printf("%s ", GLOBALDEC_ID(arg_node));
  printf(";\n");
  DBUG_RETURN(arg_node);
}

node *PRTglobaldef(node * arg_node, info * arg_info) {
  char* tmp;
  DBUG_ENTER("PRTglobaldef");
  if (GLOBALDEF_EXPORT(arg_node)) {
    printf("Export ");
  }
  tmp = type_string(GLOBALDEF_TYPE(arg_node));
  printf("%s ", tmp);
  printf("%s", GLOBALDEF_ID(arg_node));
  if (GLOBALDEF_EXPR(arg_node) != NULL) {
    printf(" ");
    GLOBALDEF_EXPR(arg_node) = TRAVopt(GLOBALDEF_EXPR(arg_node), arg_info);
  }
  printf(";\n");
  DBUG_RETURN(arg_node);
}

node *PRTparam(node * arg_node, info * arg_info) {
  char* tmp;
  DBUG_ENTER("PRTparam");
  tmp = type_string(PARAM_TYPE(arg_node));
  printf("%s", tmp);
  PARAM_ID(arg_node) = TRAVdo(PARAM_ID(arg_node), arg_info);
  if(PARAM_NEXT(arg_node)) {
    printf(", ");
    PARAM_NEXT(arg_node) = TRAVopt(PARAM_NEXT(arg_node), arg_info);
  }
  DBUG_RETURN(arg_node);
}

node *PRTvar(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTvar");
  printf("%s", VAR_NAME(arg_node));
  DBUG_RETURN(arg_node);
}

node *PRTstatements(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTstatements");
  printIndent(arg_info);
  STATEMENTS_FIRST(arg_node) = TRAVdo(STATEMENTS_FIRST(arg_node), arg_info);
  STATEMENTS_NEXT(arg_node) = TRAVopt(STATEMENTS_NEXT(arg_node), arg_info);
  DBUG_RETURN(arg_node);
}

node *PRTassign(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTassign");
  printf("%s = ", ASSIGN_ID(arg_node));
  ASSIGN_EXPR(arg_node) = TRAVdo(ASSIGN_EXPR(arg_node), arg_info);
  printf(";\n");
  DBUG_RETURN(arg_node);
}

node *PRTfuncall(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTfuncall");
  printf("%s(", FUNCALL_ID(arg_node));
  FUNCALL_EXPRS(arg_node) = TRAVopt(FUNCALL_EXPRS(arg_node), arg_info);
  printf(")");
  DBUG_RETURN(arg_node);
}

node *PRTif(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTif");
  printf("if (");
  IF_EXPR(arg_node) = TRAVdo(IF_EXPR(arg_node), arg_info);
  printf(") {\n");
  INFO_INDENT(arg_info) += 1;
  IF_BLOCK(arg_node) = TRAVdo(IF_BLOCK(arg_node), arg_info);
  INFO_INDENT(arg_info) -= 1;
  if (IF_ELSEBLOCK(arg_node) != NULL) {
    printIndent(arg_info);
    printf("} else {\n");
    INFO_INDENT(arg_info) += 1;
    IF_ELSEBLOCK(arg_node) = TRAVopt(IF_ELSEBLOCK(arg_node), arg_info);
    INFO_INDENT(arg_info) -= 1;
  }
  printIndent(arg_info);
  printf("}\n");
  DBUG_RETURN(arg_node);
}

node *PRTwhile(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTwhile");
  printf("while (");
  WHILE_EXPR(arg_node) = TRAVdo(WHILE_EXPR(arg_node), arg_info);
  printIndent(arg_info);
  printf(") {\n");
  INFO_INDENT(arg_info) += 1;
  WHILE_BLOCK(arg_node) = TRAVdo(WHILE_BLOCK(arg_node), arg_info);
  INFO_INDENT(arg_info) -= 1;
  printIndent(arg_info);
  printf("}\n");
  DBUG_RETURN(arg_node);
}

node *PRTdowhile(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTdowhile");
  printf("do {\n");
  INFO_INDENT(arg_info) += 1;
  DOWHILE_BLOCK(arg_node) = TRAVdo(DOWHILE_BLOCK(arg_node), arg_info);
  INFO_INDENT(arg_info) -= 1;
  printIndent(arg_info);
  printf("} while (");
  DOWHILE_EXPR(arg_node) = TRAVdo(DOWHILE_EXPR(arg_node), arg_info);
  printIndent(arg_info);
  printf(");\n");
  DBUG_RETURN(arg_node);
}

node *PRTfor(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTfor");
  printf("for (");
  printf("%s = ", FOR_ID(arg_node));
  FOR_EXPRSTART(arg_node) = TRAVdo(FOR_EXPRSTART(arg_node), arg_info);
  printf(", ");
  FOR_EXPRSTOP(arg_node) = TRAVdo(FOR_EXPRSTOP(arg_node), arg_info);
  if (FOR_EXPRINCR(arg_node) != NULL) {
    printf(", ");
    FOR_EXPRINCR(arg_node) = TRAVopt(FOR_EXPRINCR(arg_node), arg_info);
  }
  printf(") {\n");
  INFO_INDENT(arg_info) += 1;
  FOR_BLOCK(arg_node) = TRAVdo(FOR_BLOCK(arg_node), arg_info);
  INFO_INDENT(arg_info) -= 1;
  printIndent(arg_info);
  printf("}\n");
  DBUG_RETURN(arg_node);
}

node *PRTreturn(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTreturn");
  printf("return ");
  RETURN_EXPR(arg_node) = TRAVopt(RETURN_EXPR(arg_node), arg_info);
  printf(";\n");
  DBUG_RETURN(arg_node);
}

node *PRTexprs(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTexprs");
  EXPRS_FIRST(arg_node) = TRAVdo(EXPRS_FIRST(arg_node), arg_info);
  EXPRS_NEXT(arg_node) = TRAVopt(EXPRS_NEXT(arg_node), arg_info);
  DBUG_RETURN(arg_node);
}

node * PRTbinop (node * arg_node, info * arg_info) {
  char *tmp;
  DBUG_ENTER ("PRTbinop");
  printf( " ");
  BINOP_LEFT( arg_node) = TRAVdo( BINOP_LEFT( arg_node), arg_info);
  switch (BINOP_OP( arg_node)) {
    case BO_add:
      tmp = "+";
      break;
    case BO_sub:
      tmp = "-";
      break;
    case BO_mul:
      tmp = "*";
      break;
    case BO_div:
      tmp = "/";
      break;
    case BO_mod:
      tmp = "%";
      break;
    case BO_lt:
      tmp = "<";
      break;
    case BO_le:
      tmp = "<=";
      break;
    case BO_gt:
      tmp = ">";
      break;
    case BO_ge:
      tmp = ">=";
      break;
    case BO_eq:
      tmp = "==";
      break;
    case BO_ne:
      tmp = "!=";
      break;
    case BO_or:
      tmp = "||";
      break;
    case BO_and:
      tmp = "&&";
      break;
    case BO_unknown:
      DBUG_ASSERT( 0, "unknown binop detected!");
  }
  printf( " %s ", tmp);
  BINOP_RIGHT( arg_node) = TRAVdo( BINOP_RIGHT( arg_node), arg_info);

  DBUG_RETURN (arg_node);
}

node *PRTmonop(node * arg_node, info * arg_info) {
  char* tmp;
  DBUG_ENTER("PRTmonop");
  switch(MONOP_OP(arg_node)) {
    case MO_not:
      tmp = "!";
      break;
    case MO_neg:
      tmp = "-";
      break;
    case MO_unknown:
      DBUG_ASSERT( 0, "unknown monop detected!");
  }
  printf("%s ", tmp);
  MONOP_EXPR(arg_node) = TRAVdo(MONOP_EXPR(arg_node), arg_info);
  DBUG_RETURN(arg_node);
}

node *PRTcast(node * arg_node, info * arg_info) {
  char* tmp;
  DBUG_ENTER("PRTcast");
  switch (CAST_CASTTYPE(arg_node)) {
    case BT_bool:
      tmp = "(bool) ";
      break;
    case BT_int:
      tmp = "(int) ";
      break;
    case BT_float:
      tmp = "float) ";
      break;
    case RT_void:
      DBUG_ASSERT(0, "var can't be of type: void");
      break;
    case BT_unknown:
      DBUG_ASSERT(0, "unknown basictype selected!");
  }
  printf("(%s) ", tmp);
  CAST_EXPR(arg_node) = TRAVdo(CAST_EXPR(arg_node), arg_info);
  DBUG_RETURN(arg_node);
}

node * PRTnum (node * arg_node, info * arg_info) {
  DBUG_ENTER ("PRTnum");
  printf( "%i", NUM_VALUE( arg_node));
  DBUG_RETURN (arg_node);
}

node * PRTfloat (node * arg_node, info * arg_info) {
  DBUG_ENTER ("PRTfloat");
  printf( "%f", FLOAT_VALUE( arg_node));
  DBUG_RETURN (arg_node);
}

node * PRTbool (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTbool");
  if (BOOL_VALUE( arg_node)) {
    printf( "true");
  }
  else {
    printf( "false");
  }
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn PRTsymboltableentry
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node letrec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *PRTsymboltable(node * arg_node, info * arg_info) {
  DBUG_ENTER("PRTsymboltable");
  DBUG_RETURN(arg_node);
}

node *PRTsymboltableentry (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTsymboltableentry");
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn PRTerror
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node letrec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTerror (node * arg_node, info * arg_info)
{
  bool first_error;

  DBUG_ENTER ("PRTerror");

  if (NODE_ERROR (arg_node) != NULL) {
    NODE_ERROR (arg_node) = TRAVdo (NODE_ERROR (arg_node), arg_info);
  }

  first_error = INFO_FIRSTERROR( arg_info);

  if( (global.outfile != NULL)
      && (ERROR_ANYPHASE( arg_node) == global.compiler_anyphase)) {

    if ( first_error) {
      printf ( "\n/******* BEGIN TREE CORRUPTION ********\n");
      INFO_FIRSTERROR( arg_info) = FALSE;
    }

    printf ( "%s\n", ERROR_MESSAGE( arg_node));

    if (ERROR_NEXT (arg_node) != NULL) {
      TRAVopt (ERROR_NEXT (arg_node), arg_info);
    }

    if ( first_error) {
      printf ( "********  END TREE CORRUPTION  *******/\n");
      INFO_FIRSTERROR( arg_info) = TRUE;
    }
  }

  DBUG_RETURN (arg_node);
}


/** <!-- ****************************************************************** -->
 * @brief Prints the given syntaxtree
 *
 * @param syntaxtree a node structure
 *
 * @return the unchanged nodestructure
 ******************************************************************************/

node
*PRTdoPrint( node *syntaxtree)
{
  info *info;

  DBUG_ENTER("PRTdoPrint");

  DBUG_ASSERT( (syntaxtree!= NULL), "PRTdoPrint called with empty syntaxtree");

  printf( "\n\n------------------------------\n\n");

  info = MakeInfo();

  TRAVpush( TR_prt);

  syntaxtree = TRAVdo( syntaxtree, info);

  TRAVpop();

  info = FreeInfo(info);

  printf( "\n------------------------------\n\n");

  DBUG_RETURN( syntaxtree);
}

/**
 * @}
 */
