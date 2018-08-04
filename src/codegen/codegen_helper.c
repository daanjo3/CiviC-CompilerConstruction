#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "ctinfo.h"
#include "lookup_table.h"
#include "str.h"
#include "memory.h"

int getLocalVarCount(node *arg_node) {
    if(NODE_TYPE(arg_node) != N_fundefdec) {
        CTIerror("codegen_helper: getLocalVarCount: wrong node type");
    }
    // if(FUNDEFDEC_BODY(arg_node) == NULL) {
    //     CTIerror("codegen_helper: getLocalVarCount: fundef must have a body");
    // }

    node *vardecs = FUNBODY_VARDEC(FUNDEFDEC_BODY(arg_node));
    if(vardecs) {
        int count = 0;
        while(vardecs) {
            count += 1;
            vardecs = VARDEC_NEXT(vardecs);
        }
        return count;
    } else {
        return 0;
    }
}

// Perhaps somehow combine these two?
// int getParamCount(node *arg_node) {
//     if(NODE_TYPE(arg_node) != N_fundefdec) {
//         CTIerror("codegen_helper: getLocalVarCount: wrong node type");
//     }

//     node *params = FUNDEFDEC_PARAM(arg_node);
//     if(params) {
//         int count = 0;
//         while(params) {
//             count += 1;
//             params = PARAM_NEXT(params);
//         }
//         return count;
//     } else {
//         return 0;
//     }
// }

// Retrieve an index from the lookup-table
int getIndexFromLut(lut_t *lookup, char* name, bool function) {

    // If the entry is a function prepend the string
    char* name_search;
    if(function) {
        name_search = STRcat("_f_", name);
    } else {
        name_search = name;
    }

    return *(int*)LUTsearchInLutP(lookup, name_search);
}

// Insert the to be used symboltable in a lut matching indexes
void insertSymbolsIntoLut(lut_t *lookup, node *symboltable) {
    if(!LUTisEmptyLut(lookup)) {
        lookup = LUTremoveContentLut(lookup);
    }

    node *entry = SYMBOLTABLE_HEAD(symboltable);
    node *parent = SYMBOLTABLE_PARENT(symboltable);
    int index = 0;

    while(entry) {
        char *name = STRcpy(SYMBOLTABLEENTRY_NAME(entry));
        // Prepend the name in case it is a function
        if(SYMBOLTABLEENTRY_FUNCTION(entry)) {
            name = STRcat("_f_", name);
        }
        // int index_store = index;
        void *index_store = MEMmalloc(sizeof(index));
        index_store = &index;
        LUTinsertIntoLutP(lookup, name, index_store);
        
        // Increment the index counter and get the next entry
        index += 1;
        entry = SYMBOLTABLEENTRY_NEXT(entry);

        // Check if a parent table can be added
        if(entry == NULL && parent != NULL) {    
            entry = SYMBOLTABLE_HEAD(parent);
            parent = SYMBOLTABLE_PARENT(parent);
        }
    }
}