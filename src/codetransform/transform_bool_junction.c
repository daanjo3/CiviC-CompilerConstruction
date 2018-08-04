#include "transform_bool_junction.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "memory.h"

#include "codeanalysis_helper.h"

struct INFO {
};

static info *MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");

    result = (info*)MEMmalloc(sizeof(info));

    DBUG_RETURN(result);
}

static info *FreeInfo(info *info) {
    DBUG_ENTER("FreeInfo");
    info = MEMfree(info);
    DBUG_RETURN(info);
}

node *TBJbinop(node *arg_node, info *arg_info) {
    DBUG_ENTER("TBJbinop");

    if(BINOP_OP(arg_node) == BO_and) {
        node *false_expr = TBmakeBool(FALSE);
        node *condexpr = TBmakeCondexpr(BINOP_LEFT(arg_node), BINOP_RIGHT(arg_node), false_expr);
        arg_node = condexpr;
    } else if(BINOP_OP(arg_node) == BO_or) {
        node *true_expr = TBmakeBool(TRUE);
        node *condexpr = TBmakeCondexpr(BINOP_LEFT(arg_node), true_expr, BINOP_RIGHT(arg_node));
        arg_node = condexpr;
    }

    DBUG_RETURN(arg_node);
}

node *TBJdoTransformBooleanJunctions(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("TBJdoTransformBooleanJunctions");
    arg_info = MakeInfo();

    TRAVpush(TR_tbj);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();

    arg_info = FreeInfo(arg_info);

    DBUG_RETURN(syntaxtree);
}