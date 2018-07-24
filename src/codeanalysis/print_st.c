#include "print_st.h"
#include "types.h"
#include "tree_basic.h"
#include "traverse.h"

#include "dbug.h"
#include "str.h"

#include "memory.h"
#include "ctinfo.h"
#include "lookup_table.h"

char *type_to_string(basictype type) {
    switch (type) {
    case BT_bool:
      return "boolean";
    case BT_int:
      return "int";
    case BT_float:
      return "float";
    case RT_void:
      return "void";
    case BT_unknown:
      DBUG_ASSERT(0, "unknown basictype selected!");
  }
  return " ";
}

node *PSsymboltable(node *arg_node, info *arg_info) {
    DBUG_ENTER("PSsymboltable");
    printf("-- Symbol Table -- ");
    if(SYMBOLTABLE_PARENT(arg_node)) {
        node *parent = SYMBOLTABLE_PARENT(arg_node);
        char* head_id = SYMBOLTABLEENTRY_NAME(SYMBOLTABLE_HEAD(parent));
        printf("Parent: %s", head_id);
    } else {
        printf("Global");
    }
    printf("\n");
    SYMBOLTABLE_HEAD(arg_node) = TRAVopt(SYMBOLTABLE_HEAD(arg_node), arg_info);
    DBUG_RETURN(arg_node);
}

node *PSsymboltableentry(node *arg_node, info *arg_info) {
    DBUG_ENTER("PSsymboltableentry");

    char *name = SYMBOLTABLEENTRY_NAME(arg_node);
    basictype type = SYMBOLTABLEENTRY_TYPE(arg_node);
    char *type_s = type_to_string(type);
    printf("%s %s", type_s, name);

    if(SYMBOLTABLEENTRY_PARAMS(arg_node)) {
        printf("(");
        node *param = SYMBOLTABLEENTRY_PARAMS(arg_node);
        char *paramtype;
        while(param) {
            paramtype = type_to_string(PARAM_TYPE(param));
            node *var = PARAM_ID(param);
            char *name = VAR_NAME(var);
            printf("%s %s", paramtype, name);
            param = PARAM_NEXT(param);
        }
        printf(")");
    }
    printf("\n");
    SYMBOLTABLEENTRY_NEXT(arg_node) = TRAVopt(SYMBOLTABLEENTRY_NEXT(arg_node), arg_info);
    DBUG_RETURN(arg_node);
}

node *PSdoPrintSymbolTable(node *syntaxtree) {
    DBUG_ENTER("PSdoPrintSymbolTable");

    printf( "\n\n------------------------------\n\n");

    TRAVpush(TR_ps);
    syntaxtree = TRAVdo(syntaxtree, NULL);
    TRAVpop();

    printf( "\n\n------------------------------\n\n");
    
    DBUG_RETURN(syntaxtree);
}
