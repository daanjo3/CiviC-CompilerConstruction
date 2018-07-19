#include "transform_for.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "memory.h"
#include "str.h"

struct INFO {
    int depth;
    node *vardecs_last;
    node *fundef_body;
};

#define INFO_LOOP_DEPTH(n) ((n)->depth)
#define INFO_VARDECS_LAST(n) ((n)->vardecs_last)
#define INFO_FUNDEF_BODY(n) ((n)->fundef_body)

static info *MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");
    result = (info*)MEMmalloc(sizeof(info));
    
    INFO_LOOP_DEPTH(result) = 0;
    INFO_VARDECS_LAST(result) = NULL;
    INFO_FUNDEF_BODY(result) = NULL;

    DBUG_RETURN(result);
}

static info *FreeInfo(info *info) {
    DBUG_ENTER("FreeInfo");
    info = MEMfree(info);
    DBUG_RETURN(info);
}

node *TFfundefdec(node *arg_node, info *arg_info) {
    DBUG_ENTER("TFfundefdec");

    node *vardecs = FUNBODY_VARDEC(FUNDEFDEC_BODY(arg_node));

    // Set the last vardec struct info, if present
    if(vardecs) {
        while(VARDEC_NEXT(vardecs)) {
            vardecs = VARDEC_NEXT(vardecs);
        }
        INFO_VARDECS_LAST(arg_info) = vardecs;
    }
    INFO_FUNDEF_BODY(arg_info) = FUNDEFDEC_BODY(arg_node);
    FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), arg_info);

    DBUG_RETURN(arg_node);
}

node *TFfor(node *arg_node, info *arg_info) {
    DBUG_ENTER("TFfor");

    // Create new name like: "_for_[depth]_[name]"

    // TODO
    // FIX THE MISTAKE WHICH HAPPENS SOMEWHERE AROUND HERE
    // WRONG NODE ASSIGNED
    node *var = FOR_VAR(arg_node);
    const char *id = STRcpy(VAR_NAME(var));
    const char *depth = STRitoa(INFO_LOOP_DEPTH(arg_info));
    char *new_id = STRcatn(4, "_for_", id, "_", depth);

    node *expr = FOR_EXPRSTART(arg_node);

    node *new_vardec = TBmakeVardec(BT_int, new_id, expr, NULL);
    node *vardec_last = INFO_VARDECS_LAST(arg_info);
    
    if(vardec_last) {
        VARDEC_NEXT(vardec_last) = new_vardec;
    } else {
        node *body = INFO_FUNDEF_BODY(arg_info);
        FUNBODY_VARDEC(body) = new_vardec;
    }
    INFO_VARDECS_LAST(arg_info) = new_vardec;

    // Not here
    INFO_LOOP_DEPTH(arg_info) += 1;
    FOR_BLOCK(arg_node) = TRAVdo(FOR_BLOCK(arg_node), arg_info);
    INFO_LOOP_DEPTH(arg_info) -= 1;

    DBUG_RETURN(arg_node);
}

node *TFdoTransformFor(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("TFdoTransformFor");

    arg_info = MakeInfo();
    TRAVpush(TR_tf);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();
    arg_info = FreeInfo(arg_info);
    DBUG_RETURN(syntaxtree);
}