#include "type_check.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "memory.h"

struct INFO {
    node *symboltable;
};

#define INFO_SYMBOLTABLE(n) ((n)->symboltable)

static info *MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");

    result = (info*)MEMmalloc(sizeof(info));
    INFO_SYMBOLTABLE(result) = NULL;

    DBUG_RETURN(result);
}

static info *FreeInfo(info *info) {
    DBUG_ENTER("FreeInfo");
    info = MEMfree(info);
    DBUG_RETURN(info);
}

node *TCprogram(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCprogram");
    INFO_SYMBOLTABLE(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    PROGRAM_DECLARATIONS(arg_node) = TRAVdo(PROGRAM_DECLARATIONS(arg_node), arg_info);
    DBUG_RETURN(arg_node);
}

node *TCfundefdec(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCpfundefdec");

    if(FUNDEFDEC_BODY(arg_node)) {
        node *prev_symboltable = INFO_SYMBOLTABLE(arg_info);
        INFO_SYMBOLTABLE(arg_info) = FUNDEFDEC_SYMBOLTABLE(arg_node);

        FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), arg_info);

        INFO_SYMBOLTABLE(arg_info) = prev_symboltable;
    }

    DBUG_RETURN(arg_node);
}

node *TCvar(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCvar");
    DBUG_RETURN(arg_node);
}

node *TCdoTypeCheck(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("TCdoTypeCheck");

    arg_info = MakeInfo();
    TRAVpush(TR_tc);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();
    arg_info = FreeInfo(arg_info);
    DBUG_RETURN(syntaxtree);
}