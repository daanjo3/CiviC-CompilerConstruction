#include "transform_bool_cast.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "memory.h"
#include "codeanalysis_helper.h"

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

node *TBCprogram(node *arg_node, info *arg_info) {
    DBUG_ENTER("TBCprogram");

    INFO_SYMBOLTABLE(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);

    DBUG_RETURN(arg_node);
}

node *TBCfundefdec(node *arg_node, info *arg_info) {
    DBUG_ENTER("TBCfundefdec");

    if(FUNDEFDEC_BODY(arg_node)) {

        node *prev_symboltable = INFO_SYMBOLTABLE(arg_info);
        INFO_SYMBOLTABLE(arg_info) = FUNDEFDEC_SYMBOLTABLE(arg_node);

        FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), arg_info);

        INFO_SYMBOLTABLE(arg_info) = prev_symboltable;
    }

    DBUG_RETURN(arg_node);
}

node *TBCcast(node *arg_node, info *arg_info) {
    DBUG_ENTER("TBCcast");

    basictype expr_type = getExpressionType(CAST_EXPR(arg_node), INFO_SYMBOLTABLE(arg_info));
    basictype cast_type = CAST_CASTTYPE(arg_node);

    // (cast_type)expr_type
    if(cast_type == BT_bool) {

        // Float to Boolean        
        if(expr_type == BT_float) {
            node *pred = TBmakeBinop(BO_le, CAST_EXPR(arg_node), TBmakeFloat(0.0));
            arg_node = TBmakeCondexpr(pred, TBmakeBool(FALSE), TBmakeBool(TRUE));
        }
        // Num to Boolean
        else if(expr_type == BT_int) {
            node *pred = TBmakeBinop(BO_lt, CAST_EXPR(arg_node), TBmakeNum(0));
            arg_node = TBmakeCondexpr(pred, TBmakeBool(FALSE), TBmakeBool(TRUE));
        }
    } else if(expr_type == BT_bool) {

        // Boolean to Float
        if(cast_type == BT_float) {
            arg_node = TBmakeCondexpr(CAST_EXPR(arg_node), TBmakeFloat(1.0), TBmakeFloat(0.0));
        }
        // Boolean to Num
        else if(cast_type == BT_int) {
            arg_node = TBmakeCondexpr(CAST_EXPR(arg_node), TBmakeNum(1), TBmakeNum(0));
        }
    }

    DBUG_RETURN(arg_node);
}

node *TBCdoTransformBooleanCast(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("TBCdoTransformBooleanCast");
    arg_info = MakeInfo();

    TRAVpush(TR_tbj);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();

    arg_info = FreeInfo(arg_info);

    DBUG_RETURN(syntaxtree);
}