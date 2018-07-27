#include "typecheck_match.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "memory.h"
#include "ctinfo.h"
#include "str.h"
#include "codeanalysis_helper.h"

struct INFO {
    node *symboltable_program;
    node *symboltable_current;
    node *current_function;
};

#define INFO_SYMBOLTABLE_PROGRAM(n) ((n)->symboltable_program)
#define INFO_SYMBOLTABLE_CURRENT(n) ((n)->symboltable_current)
#define INFO_CURRENT_FUNCTION(n) ((n)->current_function)

static info *MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");

    result = (info*)MEMmalloc(sizeof(info));
    INFO_SYMBOLTABLE_PROGRAM(result) = NULL;
    INFO_SYMBOLTABLE_CURRENT(result) = NULL;
    INFO_CURRENT_FUNCTION(result) = NULL;
    
    DBUG_RETURN(result);
}

static info *FreeInfo(info *info) {
    DBUG_ENTER("FreeInfo");
    info = MEMfree(info);
    DBUG_RETURN(info);
}

// --------------------------  Helper Functions  ----------------------------------

// // Return the corresponding symboltable entry
// node *getSymboltableEntry(char *name, bool isfunction, info *arg_info) {
//     node *symboltable = INFO_SYMBOLTABLE_CURRENT(arg_info);
//     node *entry = SYMBOLTABLE_HEAD(symboltable);

//     while(entry) {
//         while(entry) {
//         char *entryname = SYMBOLTABLEENTRY_NAME(entry);
//         if(STReq(name, entryname) && SYMBOLTABLEENTRY_FUNCTION(entry) == isfunction) {
//             return entry;
//         }
//         entry = SYMBOLTABLEENTRY_NEXT(entry);
//         }
//         symboltable = SYMBOLTABLE_PARENT(symboltable);
//         if(symboltable) {
//             entry = SYMBOLTABLE_HEAD(symboltable);
//         }
//     }
//     CTIerror("SymbolError: entry not present in symboltable");
//     return NULL;
// }

// Returns the type belonging to the expression
// basictype getExpressionType(node *expr, node *symboltable) {
//     node *entry;
//     switch(NODE_TYPE(expr)) {
//         case N_binop:
//             return BINOP_EXPRESSIONTYPE(expr);
//         case N_monop:
//             return MONOP_EXPRESSIONTYPE(expr);
//         case N_cast:
//             return CAST_CASTTYPE(expr);
//         case N_funcall:
//             entry = getSymboltableEntry(FUNCALL_ID(expr), TRUE, symboltable);
//             return SYMBOLTABLEENTRY_TYPE(entry);
//         case N_var:
//             entry = getSymboltableEntry(VAR_NAME(expr), FALSE, symboltable);
//             return SYMBOLTABLEENTRY_TYPE(entry);
//         case N_num:
//             return BT_int;
//         case N_float:
//             return BT_float;
//         case N_bool:
//             return BT_bool;
//         default:
//             CTInote("getExpressionType: undefined node");
//             return BT_unknown;   
//     }
// }

// ------------------------- Symboltable Managing Nodes --------------------------------

node *TCMprogram(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMprogram");

    INFO_SYMBOLTABLE_PROGRAM(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    INFO_SYMBOLTABLE_CURRENT(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    PROGRAM_DECLARATIONS(arg_node) = TRAVdo(PROGRAM_DECLARATIONS(arg_node), arg_info);

    DBUG_RETURN(arg_node);
}
node *TCMfundefdec(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMfundefdec");

    if(FUNDEFDEC_BODY(arg_node)) {
        INFO_SYMBOLTABLE_CURRENT(arg_info) = FUNDEFDEC_SYMBOLTABLE(arg_node);
        INFO_CURRENT_FUNCTION(arg_info) = arg_node;

        FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), arg_info);

        INFO_SYMBOLTABLE_CURRENT(arg_info) = SYMBOLTABLE_PARENT(FUNDEFDEC_SYMBOLTABLE(arg_node));
    }

    DBUG_RETURN(arg_node);
}

// ---------------------------  Nodes to be matched  --------------------------------

node *TCMglobaldef(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMglobaldef");

    if(GLOBALDEF_EXPR(arg_node)) {
        if(GLOBALDEF_TYPE(arg_node) != getExpressionType(GLOBALDEF_EXPR(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info))) {
            CTIerror("TypeError; incompatible types");
        }
    }

    DBUG_RETURN(arg_node);
}

node *TCMassign(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMassign");

    node *entry = getSymboltableEntry(ASSIGN_ID(arg_node), FALSE, INFO_SYMBOLTABLE_CURRENT(arg_info));
    if(SYMBOLTABLEENTRY_TYPE(entry) != getExpressionType(ASSIGN_EXPR(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info))) {
        CTIerror("TypeError; incompatible types");
    }

    DBUG_RETURN(arg_node);
}

node *TCMfuncall(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMfuncall");

    // Get parameters
    node *entry = getSymboltableEntry(FUNCALL_ID(arg_node), TRUE, INFO_SYMBOLTABLE_CURRENT(arg_info));
    node *params = SYMBOLTABLEENTRY_PARAMS(entry);
    // Get expressions
    node *exprs = FUNCALL_EXPRS(arg_node);

    // Match expressions against parameters
    if(params) {
        while(params) {
        if(PARAM_TYPE(params) != getExpressionType(EXPRS_FIRST(exprs), INFO_SYMBOLTABLE_CURRENT(arg_info))) {
            CTIerror("TypeError; incompatible parameters");
        }
        params = PARAM_NEXT(params);
        exprs = EXPRS_NEXT(exprs);
        }

        if(exprs) {
            CTIerror("TypeError; wrong amount of expressions supplie");
        }
    } else {
        if(exprs) {
            CTIerror("TypeError; wrong amount of expressions supplied");
        }
    }

    DBUG_RETURN(arg_node);
}

// The if-expression must be a boolean
node *TCMif(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMif");

    if(getExpressionType(IF_EXPR(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info)) != BT_bool) {
        CTIerror("TypeError; Expression must return a boolean");
    }

    DBUG_RETURN(arg_node);
}

// The while expression must be a boolean
node *TCMwhile(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMwhile");

    if(getExpressionType(WHILE_EXPR(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info)) != BT_bool) {
        CTIerror("TypeError; Expression must return a boolean");
    }

    DBUG_RETURN(arg_node);
}

// The dowhile expression must be a boolean
node *TCMdowhile(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMdowhile");

    if(getExpressionType(DOWHILE_EXPR(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info)) != BT_bool) {
        CTIerror("TypeError; Expression must return a boolean");
    }
    
    DBUG_RETURN(arg_node);
}

// All for-loop expressions must be of type integer
node *TCMfor(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMfor");

    if(getExpressionType(FOR_EXPRSTART(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info)) != BT_int) {
        CTIerror("TypeError; Expression must return an integer");
    }

    if(FOR_EXPRINCR(arg_node)) {
        if(getExpressionType(FOR_EXPRINCR(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info)) != BT_int) {
            CTIerror("TypeError; Expression must return an integer");
        }
    }

    if(getExpressionType(FOR_EXPRSTOP(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info)) != BT_int) {
        CTIerror("TypeError; Expression must return an integer");
    }

    DBUG_RETURN(arg_node);
}

// The return expression-type must match the fundef return type
node *TCMreturn(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCMreturn");
    basictype rettype = FUNDEFDEC_RETTYPE(INFO_CURRENT_FUNCTION(arg_info));

    if(RETURN_EXPR(arg_node)) {
        if(rettype != getExpressionType(RETURN_EXPR(arg_node), INFO_SYMBOLTABLE_CURRENT(arg_info))) {
            CTIerror("TypeError; Return expression does not match function type");
        }
    } else {
        if(rettype != RT_void) {
            CTIerror("TypeError; Return expression does not match function type");
        }
    }

    DBUG_RETURN(arg_node);
}

// -------------------------------------------------------------

node *TCMdoTypeCheckMatch(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("TCMdoTypeCheckMatch");
    arg_info = MakeInfo();

    TRAVpush(TR_tcm);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();

    arg_info = FreeInfo(arg_info);
    DBUG_RETURN(syntaxtree);
}