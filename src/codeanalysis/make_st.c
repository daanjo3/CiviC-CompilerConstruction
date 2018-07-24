#include "make_st.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"

#include "memory.h"
#include "ctinfo.h"
#include "lookup_table.h"
#include "print_st.h"

// -------------------- Macro's & Structs ---------------------

struct INFO {
    node *current_table;
};

#define INFO_CURRENT_TABLE(n) ((n)->current_table)

static info* MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");
    result = (info*)MEMmalloc(sizeof(info));
    INFO_CURRENT_TABLE(result) = TBmakeSymboltable(NULL);
    DBUG_RETURN(result);
}

static info* FreeInfo(info* info) {
    DBUG_ENTER("FreeInfo");
    info = MEMfree(info);
    DBUG_RETURN(info);
}

// -------------------- Symbol Table Functions ----------------

// Print a symbol table entry
void printEntry(node *entry) {
    printf("Added Entry:\n");
    char *name = SYMBOLTABLEENTRY_NAME(entry);
    char *type = type_to_string(SYMBOLTABLEENTRY_TYPE(entry));
    bool function = SYMBOLTABLEENTRY_FUNCTION(entry);
    printf("Name: %s\nType: %s\nIs Function:\t%d\n", name, type, function);

    if(function) {
        node *params = SYMBOLTABLEENTRY_PARAMS(entry);
        while(params) {
            char *paramname = VAR_NAME(PARAM_ID(params));
            printf("Param: %s\n", paramname);
            params = PARAM_NEXT(params);
        }
    }
    printf("\n");
}

// Check whether an entry is already present in the table
bool checkEntry(info *arg_info, char* name, bool is_function) {
    node *table = INFO_CURRENT_TABLE(arg_info);
    node *entry = SYMBOLTABLE_HEAD(table);
    char* entry_name;
    bool entry_function;

    while (entry) {
        entry_name = SYMBOLTABLEENTRY_NAME(entry);
        entry_function = SYMBOLTABLEENTRY_FUNCTION(entry);

        if (STReq(name, entry_name) && (is_function == entry_function)) {
            return FALSE;
        }
        entry = SYMBOLTABLEENTRY_NEXT(entry);
    }
    return TRUE;
}

// Add a symbol to the symboltable
void addSymbolTableEntry(info *arg_info, char* name, basictype type, bool isfunction, node *params) {
    if(checkEntry(arg_info, name, isfunction)) {
        node *new_entry = TBmakeSymboltableentry(name, type, isfunction, NULL);
        if(isfunction) {
            SYMBOLTABLEENTRY_PARAMS(new_entry) = params;
        }

        // Get the current table and its head
        node *table = INFO_CURRENT_TABLE(arg_info);
        node *table_entry = SYMBOLTABLE_HEAD(table);

        // If there is a head traverse to the last entry in the list
        if(table_entry) {
            while(SYMBOLTABLEENTRY_NEXT(table_entry)) {
                table_entry = SYMBOLTABLEENTRY_NEXT(table_entry);
            }
            SYMBOLTABLEENTRY_NEXT(table_entry) = new_entry;
        }
        // Otherwise set the new entry as the current head
        else {
            SYMBOLTABLE_HEAD(table) = new_entry;
        }
        // printEntry(new_entry);
    }
}

// --------------------- Nodes ------------------------------

node *MSfundefdec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSfundefdec");

    // Store the function in the current table
    char* name = FUNDEFDEC_ID(arg_node);
    basictype type = FUNDEFDEC_RETTYPE(arg_node);
    node *param = FUNDEFDEC_PARAM(arg_node);

    addSymbolTableEntry(arg_info, name, type, TRUE, param);
 
    // If the function has a body it is a definition
    if(FUNDEFDEC_BODY(arg_node)) {
        node *current_table = INFO_CURRENT_TABLE(arg_info);
        
        INFO_CURRENT_TABLE(arg_info) = TBmakeSymboltable(NULL);

        // Add the params to the block symbol table
        if (param) {
            do {
                name = VAR_NAME(PARAM_ID(param));
                type = PARAM_TYPE(param);
                addSymbolTableEntry(arg_info, name, type, FALSE, NULL);
                param = PARAM_NEXT(param);
            } while (param);
        }

        // Traverse the function body
        FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), arg_info);

        // Make the current table the parent of the block symbol table
        node *body_table = INFO_CURRENT_TABLE(arg_info);

        SYMBOLTABLE_PARENT(body_table) = current_table;
        
        FUNDEFDEC_SYMBOLTABLE(arg_node) = body_table;
        INFO_CURRENT_TABLE(arg_info) = current_table;
    }

    DBUG_RETURN(arg_node);
}

node *MSfor(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSfor");
    // Add the parameter to the new symbol table
    addSymbolTableEntry(arg_info, FOR_ID(arg_node), BT_int, FALSE, NULL);
    DBUG_RETURN(arg_node);
}

// Add a variable declaration
node *MSvardec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSvardec");

    char *id = VARDEC_ID(arg_node);
    basictype type = VARDEC_TYPE(arg_node);
    addSymbolTableEntry(arg_info, id, type, FALSE, NULL);

    VARDEC_NEXT(arg_node) = TRAVopt(VARDEC_NEXT(arg_node), arg_info);

    DBUG_RETURN(arg_node);
}

// Add a global definition
node *MSglobaldef(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSglobaldef");

    char *id = GLOBALDEF_ID(arg_node);
    basictype type = GLOBALDEF_TYPE(arg_node);
    addSymbolTableEntry(arg_info, id, type, FALSE, NULL);

    DBUG_RETURN(arg_node);
}

// Add a global declaration
node *MSglobaldec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSglobaldec");

    char *id = GLOBALDEC_ID(arg_node);
    basictype type = GLOBALDEC_TYPE(arg_node);
    addSymbolTableEntry(arg_info, id, type, FALSE, NULL);

    DBUG_RETURN(arg_node);
}

// Add the global symboltable to the program node
node *MSprogram(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSprogram");

    PROGRAM_DECLARATIONS(arg_node) = TRAVdo(PROGRAM_DECLARATIONS(arg_node), arg_info);
    PROGRAM_SYMBOLTABLE(arg_node) = INFO_CURRENT_TABLE(arg_info);

    DBUG_RETURN(arg_node);
}

// Traversal entry point:
node *MSdoMakeSymbolTable(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("MSdoMakeSymbolTable");

    arg_info = MakeInfo();
    TRAVpush(TR_ms);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();
    arg_info = FreeInfo(arg_info);
    DBUG_RETURN(syntaxtree);
}