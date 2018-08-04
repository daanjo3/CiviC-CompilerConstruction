#include "typecheck_inference.h"

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
    basictype type_current;
};

#define INFO_SYMBOLTABLE_PROGRAM(n) ((n)->symboltable_program)
#define INFO_SYMBOLTABLE_CURRENT(n) ((n)->symboltable_current)
#define INFO_TYPE_CURRENT(n) ((n)->type_current)

static info *MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");

    result = (info*)MEMmalloc(sizeof(info));
    INFO_SYMBOLTABLE_PROGRAM(result) = NULL;
    INFO_SYMBOLTABLE_CURRENT(result) = NULL;
    INFO_TYPE_CURRENT(result) = BT_unknown;

    DBUG_RETURN(result);
}

static info *FreeInfo(info *info) {
    DBUG_ENTER("FreeInfo");
    info = MEMfree(info);
    DBUG_RETURN(info);
}

// Nodes for the symboltable
node *TCIprogram(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCIprogram");

    INFO_SYMBOLTABLE_PROGRAM(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    INFO_SYMBOLTABLE_CURRENT(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    PROGRAM_DECLARATIONS(arg_node) = TRAVdo(PROGRAM_DECLARATIONS(arg_node), arg_info);

    DBUG_RETURN(arg_node);
}

node *TCIfundefdec(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCIfundefdec");

    if(FUNDEFDEC_BODY(arg_node)) {
        INFO_SYMBOLTABLE_CURRENT(arg_info) = FUNDEFDEC_SYMBOLTABLE(arg_node);

        FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), arg_info);

        INFO_SYMBOLTABLE_CURRENT(arg_info) = SYMBOLTABLE_PARENT(FUNDEFDEC_SYMBOLTABLE(arg_node));
    }

    DBUG_RETURN(arg_node);
}

// Expressions to check
node *TCIbinop(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCIbinop");
    basictype left;
    basictype right;

    // Obtain the left and right-hand side expression types
    BINOP_LEFT(arg_node) = TRAVdo(BINOP_LEFT(arg_node), arg_info);
    left = INFO_TYPE_CURRENT(arg_info);
    BINOP_RIGHT(arg_node) = TRAVdo(BINOP_RIGHT(arg_node), arg_info);
    right = INFO_TYPE_CURRENT(arg_info);

    // Check whether the expressions are of the same type
    if(left == right) {
        binop op = BINOP_OP(arg_node);
        binopcat category = getBinopCat(op);
        // Check if the rules of areithmetic operators are followed
        if(category == BC_arith) {
            if(left == BT_bool) {
                CTIerror("TypeError; boolean values cannot be used with Arithmetic Operators");
            }
            if(op == BO_mod && left != BT_int) {
                CTIerror("TypeError; modulo requires integer values");
            }
            INFO_TYPE_CURRENT(arg_info) = left;
            BINOP_EXPRESSIONTYPE(arg_node) = left;
        // Check if the rules of relational operators are followed
        } else if(category == BC_rel) {
            if(left == BT_bool) {
                if(op != BO_eq && op != BO_ne) {
                    CTIerror("TypeError; boolean values with RelOp can only be used with == or !=");
                }
                INFO_TYPE_CURRENT(arg_info) = BT_bool;
                BINOP_EXPRESSIONTYPE(arg_node) = BT_bool;
            } else {
                INFO_TYPE_CURRENT(arg_info) = left;
                BINOP_EXPRESSIONTYPE(arg_node) = left;
            }
        // Check if the rules of logical operators are followed
        } else if(category == BC_logic) {
            if(left != BT_bool) {
                CTIerror("TypeError; Logic operators can only be used with booleans");
            }
            INFO_TYPE_CURRENT(arg_info) = left;
            BINOP_EXPRESSIONTYPE(arg_node) = left;
        }
    } else {
        CTIerror("TypeError; incompatible expression types");
    }

    DBUG_RETURN(arg_node);
}

node *TCImonop(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCImonop");

    MONOP_EXPR(arg_node) = TRAVdo(MONOP_EXPR(arg_node), arg_info);

    // Check if the types match the current operator
    monop op = MONOP_OP(arg_node);
    if(op == MO_neg && INFO_TYPE_CURRENT(arg_info) == BT_bool) {
        CTIerror("TypeError; Unary minus can only be used with integers and floats");
    }
    if(op == MO_not && INFO_TYPE_CURRENT(arg_info) != BT_bool) {
        CTIerror("TypeError; Negation operator can only be applied to booleans");
    }

    // Remeber the type of the expressions
    MONOP_EXPRESSIONTYPE(arg_node) = INFO_TYPE_CURRENT(arg_info);

    DBUG_RETURN(arg_node);
}

node *TCIcast(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCIcast");

    INFO_TYPE_CURRENT(arg_info) = CAST_CASTTYPE(arg_node);

    DBUG_RETURN(arg_node);
}

node *TCIfuncall(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCIfuncall");

    node *entry = getSymboltableEntry(FUNCALL_ID(arg_node), TRUE, INFO_SYMBOLTABLE_CURRENT(arg_info));

    if(entry) {
        INFO_TYPE_CURRENT(arg_info) = SYMBOLTABLEENTRY_TYPE(entry);
    } else {
        CTIerror("Error; Function '%s' not declared", FUNCALL_ID(arg_node));
    }

    DBUG_RETURN(arg_node);
}

node *TCIvar(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCIvar");

    node *entry = getSymboltableEntry(VAR_NAME(arg_node), FALSE, INFO_SYMBOLTABLE_CURRENT(arg_info));

    if(entry) {
        INFO_TYPE_CURRENT(arg_info) = SYMBOLTABLEENTRY_TYPE(entry);
    } else {
        CTIerror("Error; Var '%s' not declared", VAR_NAME(arg_node));
    }

    DBUG_RETURN(arg_node);
}

// Integer constant
node *TCInum(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCInum");

    INFO_TYPE_CURRENT(arg_info) = BT_int;

    DBUG_RETURN(arg_node);
}

// Float constant
node *TCIfloat(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCIfloat");

    INFO_TYPE_CURRENT(arg_info) = BT_float;

    DBUG_RETURN(arg_node);
}

// Boolean constant
node *TCIbool(node *arg_node, info *arg_info) {
    DBUG_ENTER("TCIbool");

    INFO_TYPE_CURRENT(arg_info) = BT_bool;

    DBUG_RETURN(arg_node);
}

node *TCIdoTypeCheckInference(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("TCIdoTypeCheckInference");
    arg_info = MakeInfo();

    TRAVpush(TR_tci);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();

    arg_info = FreeInfo(arg_info);
    DBUG_RETURN(syntaxtree);
}