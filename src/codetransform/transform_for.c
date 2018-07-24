#include "transform_for.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "memory.h"
#include "str.h"

#include "copy.h"
#include "lookup_table.h"

struct INFO {
    int depth;
    node *vardecs_last;
    node *fundef_body;
    char *new_varname;
    char *old_varname;

    lut_t *lut_varname;
};

#define INFO_LOOP_DEPTH(n) ((n)->depth)
#define INFO_VARDECS_LAST(n) ((n)->vardecs_last)
#define INFO_FUNDEF_BODY(n) ((n)->fundef_body)
#define INFO_NEW_VARNAME(n) ((n)->new_varname)
#define INFO_OLD_VARNAME(n) ((n)->old_varname)
#define INFO_LUT_VARNAME(n) ((n)->lut_varname)

// TODO: replace the varname in the other expressions(?)

static info *MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");
    result = (info*)MEMmalloc(sizeof(info));
    
    INFO_LOOP_DEPTH(result) = 0;
    INFO_VARDECS_LAST(result) = NULL;
    INFO_FUNDEF_BODY(result) = NULL;
    INFO_NEW_VARNAME(result) = STRnull();
    INFO_OLD_VARNAME(result) = STRnull();

    INFO_LUT_VARNAME(result) = LUTgenerateLut();

    DBUG_RETURN(result);
}

static info *FreeInfo(info *info) {
    DBUG_ENTER("FreeInfo");

    LUTremoveLut(INFO_LUT_VARNAME(info));
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

    // Store the old variable name
    char *old_id = STRcpy(FOR_ID(arg_node));

    // Create new name like: "_for_[depth]_[name]"
    const char *depth = STRitoa(INFO_LOOP_DEPTH(arg_info));
    char *new_id = STRcatn(4, "_for_", FOR_ID(arg_node), "_", depth);
    FOR_ID(arg_node) = STRcpy(new_id);

    LUTinsertIntoLutS(INFO_LUT_VARNAME(arg_info), old_id, new_id);

    // Create a new variable declaration
    node *new_vardec = TBmakeVardec(BT_int, new_id, COPYdoCopy(FOR_EXPRSTART(arg_node)), NULL);
    
    // Add the new vardec to the list of vardecs
    node *vardec_last = INFO_VARDECS_LAST(arg_info);
    
    if(vardec_last) {
        VARDEC_NEXT(vardec_last) = new_vardec;
    } else {
        node *body = INFO_FUNDEF_BODY(arg_info);
        FUNBODY_VARDEC(body) = new_vardec;
    }
    INFO_VARDECS_LAST(arg_info) = new_vardec;

    // Rename all the identifiers in the expressions
    FOR_EXPRSTOP(arg_node) = TRAVdo(FOR_EXPRSTOP(arg_node), arg_info);
    FOR_EXPRINCR(arg_node) = TRAVopt(FOR_EXPRINCR(arg_node), arg_info);

    // Find more forloops
    INFO_LOOP_DEPTH(arg_info) += 1;
    FOR_BLOCK(arg_node) = TRAVdo(FOR_BLOCK(arg_node), arg_info);
    INFO_LOOP_DEPTH(arg_info) -= 1;



    DBUG_RETURN(arg_node);
}

// Apply the renaming to all variables
node *TFvar(node *arg_node, info *arg_info) {
    DBUG_ENTER("TFvar");

    char *new_id = LUTsearchInLutSs(INFO_LUT_VARNAME(arg_info), VAR_NAME(arg_node));

    if(new_id) {
        printf("equal!\n");
        VAR_NAME(arg_node) = new_id;
    }

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