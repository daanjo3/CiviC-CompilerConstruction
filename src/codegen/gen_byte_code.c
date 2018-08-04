#include "gen_byte_code.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "memory.h"

#include "lookup_table.h"

#include "codegen_helper.h"

/*
 * INFO structure
 */


// TODO Create lookup-table to match vars/parameters with indexes
struct INFO {
  node *symboltable_current;
  node *symboltable_program;
  lut_t *lut_index;
  
  int param_count;
};

#define INFO_SYMBOLTABLE_CURRENT(n) ((n)->symboltable_current)
#define INFO_SYMBOLTABLE_PROGRAM(n) ((n)->symboltable_program)
#define INFO_LUT_INDEX(n) ((n)->lut_index)
#define INFO_PARAM_COUNT(n) ((n)->param_count)

static info *MakeInfo()
{
  DBUG_ENTER("MakeInfo");
  info *result;

  result = MEMmalloc(sizeof(info));
  INFO_SYMBOLTABLE_CURRENT(result) = NULL;
  INFO_SYMBOLTABLE_PROGRAM(result) = NULL;
  INFO_LUT_INDEX(result) = LUTgenerateLut();
  INFO_PARAM_COUNT(result) = 0;

  DBUG_RETURN(result);
}

static info *FreeInfo( info *info)
{
  DBUG_ENTER("FreeInfo");

  info = MEMfree( info);
  return info;

  DBUG_RETURN(info);
}

// ---------------- Traversal Nodes -----------------------

node *GBCprogram(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCprogram");

  INFO_SYMBOLTABLE_PROGRAM(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
  INFO_SYMBOLTABLE_CURRENT(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);

  PROGRAM_DECLARATIONS(arg_node) = TRAVdo(PROGRAM_DECLARATIONS(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

// Necessary?
node *GBCdeclarations(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCdeclarations");

  DECLARATIONS_DECLARATION(arg_node) = TRAVdo(DECLARATIONS_DECLARATION(arg_node), arg_info);
  DECLARATIONS_NEXT(arg_node) = TRAVopt(DECLARATIONS_NEXT(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

node *GBCfundefdec(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCfundefdec");

  if(FUNDEFDEC_BODY(arg_node)) {
    printf("esr %d", getLocalVarCount(arg_node));
    // TODO load symboltable into the lut !!!
    // also load symbols from a higher table? Probably...
    INFO_SYMBOLTABLE_CURRENT(arg_info) = FUNDEFDEC_SYMBOLTABLE(arg_node);
    insertSymbolsIntoLut(INFO_LUT_INDEX(arg_info), INFO_SYMBOLTABLE_CURRENT(arg_info));

    FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), arg_info);

    INFO_SYMBOLTABLE_CURRENT(arg_info) = INFO_SYMBOLTABLE_PROGRAM(arg_info);
    insertSymbolsIntoLut(INFO_LUT_INDEX(arg_info), INFO_SYMBOLTABLE_CURRENT(arg_info));
  }
  // TODO what to do when we get a header?

  DBUG_RETURN(arg_node);
}

node *GBCfunbody(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCfunbody");

  FUNBODY_VARDEC(arg_node) = TRAVopt(FUNBODY_VARDEC(arg_node), arg_info);
  FUNBODY_LOCALFUNDEFS(arg_node) = TRAVopt(FUNBODY_LOCALFUNDEFS(arg_node), arg_info);
  FUNBODY_STATEMENTS(arg_node) = TRAVopt(FUNBODY_STATEMENTS(arg_node), arg_info);

  // Do anything more?

  DBUG_RETURN(arg_node);
}

node *GBCvardec(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCvardec");

  if(VARDEC_EXPR(arg_node)) {
    int index = getIndexFromLut(INFO_LUT_INDEX(arg_info), VARDEC_ID(arg_node), FALSE);
    VARDEC_EXPR(arg_node) = TRAVdo(VARDEC_EXPR(arg_node), arg_info);
    printf("istore %d", index);

  }

  DBUG_RETURN(arg_node);
}

node *GBClocalfundefs(node *arg_node, info *arg_info) {
  DBUG_ENTER("GBClocalfundefs");
  DBUG_RETURN(arg_node);
}

node *GBCglobaldec(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCglobaldec");
  DBUG_RETURN(arg_node);
}

node *GBCglobaldef(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCglobaldef");
  DBUG_RETURN(arg_node);
}

node *GBCparam(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCparam");
  DBUG_RETURN(arg_node);
}

node *GBCvar(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCvar");
  DBUG_RETURN(arg_node);
}

node *GBCstatements(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCstatements");
  DBUG_RETURN(arg_node);
}

node *GBCassign(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCassign");

  ASSIGN_EXPR(arg_node) = TRAVdo(ASSIGN_EXPR(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

node *GBCfuncall(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCfuncall");
  DBUG_RETURN(arg_node);
}

node *GBCif(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCif");
  DBUG_RETURN(arg_node);
}

node *GBCwhile(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCwhile");
  DBUG_RETURN(arg_node);
}

node *GBCdowhile(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCdowhile");
  DBUG_RETURN(arg_node);
}

node *GBCfor(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCfor");
  DBUG_RETURN(arg_node);
}

node *GBCreturn(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCreturn");
  DBUG_RETURN(arg_node);
}

node *GBCexprs(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCexprs");
  DBUG_RETURN(arg_node);
}

node * GBCbinop (node * arg_node, info * arg_info) {
  DBUG_ENTER ("GBCbinop");
  DBUG_RETURN (arg_node);
}

node *GBCmonop(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCmonop");
  DBUG_RETURN(arg_node);
}

node *GBCcast(node * arg_node, info * arg_info) {
  DBUG_ENTER("GBCcast");
  DBUG_RETURN(arg_node);
}

node * GBCnum (node * arg_node, info * arg_info) {
  DBUG_ENTER ("GBCnum");
  DBUG_RETURN (arg_node);
}

node * GBCfloat (node * arg_node, info * arg_info) {
  DBUG_ENTER ("GBCfloat");
  DBUG_RETURN (arg_node);
}

node * GBCbool (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("GBCbool");
  DBUG_RETURN (arg_node);
}

/*
 * Traversal start function
 */

node *GBCdoGenByteCode( node *syntaxtree) {
  info *arg_info;
  DBUG_ENTER("GBCdoGenByteCode");

  arg_info = MakeInfo();

  TRAVpush(TR_gbc);
  syntaxtree = TRAVdo(syntaxtree, arg_info);
  TRAVpop();
  arg_info = FreeInfo(arg_info);

  DBUG_RETURN( syntaxtree);
}
