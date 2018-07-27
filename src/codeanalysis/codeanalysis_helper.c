#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "str.h"
#include "ctinfo.h"

// Returns the symboltableentry which is searched for
node *getSymboltableEntry(char *name, bool isfunction, node *symboltable) {
    node *entry = SYMBOLTABLE_HEAD(symboltable);

    while(entry) {
        while(entry) {
        char *entryname = SYMBOLTABLEENTRY_NAME(entry);
        if(STReq(name, entryname) && SYMBOLTABLEENTRY_FUNCTION(entry) == isfunction) {
            return entry;
        }
        entry = SYMBOLTABLEENTRY_NEXT(entry);
        }
        symboltable = SYMBOLTABLE_PARENT(symboltable);
        if(symboltable) {
            entry = SYMBOLTABLE_HEAD(symboltable);
        }
    }
    CTIerror("SymbolError: entry not present in symboltable");
    return NULL;
}

// Returns the type belonging to the expression
basictype getExpressionType(node *expr, node *symboltable) {
    node *entry;
    switch(NODE_TYPE(expr)) {
        case N_binop:
            return BINOP_EXPRESSIONTYPE(expr);
        case N_monop:
            return MONOP_EXPRESSIONTYPE(expr);
        case N_cast:
            return CAST_CASTTYPE(expr);
        case N_funcall:
            entry = getSymboltableEntry(FUNCALL_ID(expr), TRUE, symboltable);
            return SYMBOLTABLEENTRY_TYPE(entry);
        case N_var:
            entry = getSymboltableEntry(VAR_NAME(expr), FALSE, symboltable);
            return SYMBOLTABLEENTRY_TYPE(entry);
        case N_num:
            return BT_int;
        case N_float:
            return BT_float;
        case N_bool:
            return BT_bool;
        default:
            CTInote("getExpressionType: undefined node");
            return BT_unknown;   
    }
}

// Return the category of the binary operator
binopcat getBinopCat(binop op) {
    switch (op) {
    case BO_add:
      return BC_arith;
    case BO_sub:
      return BC_arith;
    case BO_mul:
      return BC_arith;
    case BO_div:
      return BC_arith;
    case BO_mod:
      return BC_arith;
    case BO_lt:
      return BC_rel;
    case BO_le:
      return BC_rel;
    case BO_gt:
      return BC_rel;
    case BO_ge:
      return BC_rel;
    case BO_eq:
      return BC_rel;
    case BO_ne:
      return BC_rel;
    case BO_or:
      return BC_logic;
    case BO_and:
      return BC_logic;
    default:
        CTInote("Warning; Unknown BinOp");
        return BC_unknown;
    }
}