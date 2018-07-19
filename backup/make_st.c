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

// Check whether an entry is already present in the table
bool checkEntry(info *arg_info, char* name, bool is_function) {
    node *table = INFO_CURRENT_TABLE(arg_info);
    node *entry = SYMBOLTABLE_HEAD(table);
    char* entry_name;
    bool entry_function;

    while (entry) {
        entry_name = SYMBOLTABLEENTRY_NAME(entry);
        node *entry_funparams = SYMBOLTABLEENTRY_FUNPARAMS(entry);
        if (entry_funparams == NULL) {
            entry_function = FALSE;
        } else {
            entry_function = TRUE;
        }

        if (STReq(name, entry_name) && (is_function == entry_function)) {
            return FALSE;
        }
        entry = SYMBOLTABLEENTRY_NEXT(entry);
    }
    return TRUE;
}

// Print a symbol table entry
void printEntry(node *entry) {
    char *name = SYMBOLTABLEENTRY_NAME(entry);

    char *type = type_to_string(SYMBOLTABLEENTRY_TYPE(entry));
    printf("%s %s\n", type,name);

    node *params = SYMBOLTABLEENTRY_FUNPARAMS(entry);
    while(params) {
        char *paramname = PARAM_ID(params);
        printf("Param: %s\n", paramname);
        params = PARAM_NEXT(params);
    }
}

// Insert a new entry in the table
void insertSymbolTableEntry(info *arg_info, node *new_entry) {
    node *table = INFO_CURRENT_TABLE(arg_info);
    node *entry = SYMBOLTABLE_HEAD(table);

    if (!entry) {
        SYMBOLTABLE_HEAD(table) = new_entry;
    } else {
        while (SYMBOLTABLEENTRY_NEXT(entry)) {
            entry = SYMBOLTABLEENTRY_NEXT(entry);
        }
        SYMBOLTABLEENTRY_NEXT(entry) = new_entry;
    }
}

// Add an entry in the table
void createSymbolTableEntry(info *arg_info, char* name, basictype type, bool isfunction, node *params) {
    if (!(checkEntry(arg_info, name, isfunction))) {
        CTIerror("Syntax Error: Variable already declared");
        return;
    }
    node *new_entry = TBmakeSymboltableentry(name, type, isfunction, NULL, params);
    insertSymbolTableEntry(arg_info, new_entry);
    printEntry(new_entry);
}

// --------------------- Nodes ------------------------------

node *MSfundefdec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSfundefdec");
    
    // Store the function in the current table
    char* name = FUNDEFDEC_ID(arg_node);
    basictype type = FUNDEFDEC_RETTYPE(arg_node);
    node *param = FUNDEFDEC_PARAM(arg_node);
    createSymbolTableEntry(arg_info, name, type, TRUE, param);

    // If the function has a body it is a definition
    if(FUNDEFDEC_BODY(arg_node)) {
        info *body_info = MakeInfo();

        // Add the params to the block symbol table
        if (param) {
            do {
                name = PARAM_ID(param);
                type = PARAM_TYPE(param);
                createSymbolTableEntry(body_info, name, type, FALSE, NULL);
                param = PARAM_NEXT(param);
            } while (param);
        }

        // Traverse the function body
        FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), body_info);

        // Make the current table the parent of the block symbol table
        node *body_table = INFO_CURRENT_TABLE(body_info);
        SYMBOLTABLE_PARENT(body_table) = INFO_CURRENT_TABLE(arg_info);
        FUNDEFDEC_SYMBOLTABLE(arg_node) = INFO_CURRENT_TABLE(body_info);

        body_info = FreeInfo(body_info);
    }

    DBUG_RETURN(arg_node);
}

node *MSfor(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSfor");

    char* name = VAR_NAME(FOR_VAR(arg_node));
    // Create a new info struct with symbol table
    info *block_info = MakeInfo();

    // Add the parameters to the new symbol table
    createSymbolTableEntry(block_info, name, BT_int, FALSE, NULL);
    
    // Traverse over the block node to fill the symbol table
    FOR_BLOCK(arg_node) = TRAVdo(FOR_BLOCK(arg_node), block_info);

    // The block table's parent will be the current table
    node *block_table = INFO_CURRENT_TABLE(block_info);
    SYMBOLTABLE_PARENT(block_table) = INFO_CURRENT_TABLE(arg_info);
    FOR_SYMBOLTABLE(arg_node) = INFO_CURRENT_TABLE(block_info);
    
    // Free the block info struct
    block_info = FreeInfo(block_info);
    DBUG_RETURN(arg_node);
}

// Add a variable declaration
node *MSvardec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSvardec");

    char* name = VARDEC_ID(arg_node);
    basictype type = VARDEC_TYPE(arg_node);
    createSymbolTableEntry(arg_info, name, type, FALSE, NULL);

    VARDEC_NEXT(arg_node) = TRAVopt(VARDEC_NEXT(arg_node), arg_info);

    DBUG_RETURN(arg_node);
}

// Add a global definition
node *MSglobaldef(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSglobaldef");

    char* name = GLOBALDEF_ID(arg_node);
    basictype type = GLOBALDEF_TYPE(arg_node);
    createSymbolTableEntry(arg_info, name, type, FALSE, NULL);
    
    DBUG_RETURN(arg_node);
}

// Add a global declaration
node *MSglobaldec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSglobaldec");

    char* name = GLOBALDEC_ID(arg_node);
    basictype type = GLOBALDEC_TYPE(arg_node);
    createSymbolTableEntry(arg_info, name, type, FALSE, NULL);

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
    DBUG_ENTER("MSdoScopeResolution");

    arg_info = MakeInfo();
    TRAVpush(TR_ms);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();
    DBUG_RETURN(syntaxtree);
}