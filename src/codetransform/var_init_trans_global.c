#include "dbug.h"
#include "tree_basic.h"
#include "traverse.h"
#include "str.h"
#include "memory.h"
#include "ctinfo.h"

struct INFO {
    node *init_body;
    node *statement_last;
    bool expr_found;
    node *symboltable;
};

// #define INIT_FUNCTION(n) ((n)->init_function)
#define INIT_SYMBOLTABLE(n) ((n)->symboltable)
#define INIT_BODY(n) ((n)->init_body)
#define STATEMENT_LAST(n) ((n)->statement_last)
#define EXPR_FOUND(n) ((n)->expr_found)

static info* MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");

    result = (info*)MEMmalloc(sizeof(info));
    EXPR_FOUND(result) = FALSE;
    STATEMENT_LAST(result) = NULL;

    DBUG_RETURN(result);
}

static info* FreeInfo(info* info) {
    DBUG_ENTER("FreeInfo");
    info = MEMfree(info);
    DBUG_RETURN(info);
}

node *TGprogram(node *arg_node, info *arg_info) {
    DBUG_ENTER("TGprogram");

    // Create a new symboltable and functionbody
    node *symboltable = TBmakeSymboltable(NULL); // <- free?
    node *funbody = TBmakeFunbody(NULL, NULL, NULL); // <- free?
    INIT_BODY(arg_info) = funbody;
    INIT_SYMBOLTABLE(arg_info) = symboltable;

    // Loop over the declarations
    PROGRAM_DECLARATIONS(arg_node) = TRAVdo(PROGRAM_DECLARATIONS(arg_node), arg_info);

    if(EXPR_FOUND(arg_info)) {
        // Use the found statements to create a new init function
        node *initfun = TBmakeFundefdec(TRUE, RT_void, STRcpy("__init"), NULL, funbody, symboltable);
        node *old_decs = PROGRAM_DECLARATIONS(arg_node);

        // Add the new function to the declaration list AS FIRST
        node *declarations = TBmakeDeclarations(initfun, old_decs);
        PROGRAM_DECLARATIONS(arg_node) = declarations;
        SYMBOLTABLE_PARENT(INIT_SYMBOLTABLE(arg_info)) = PROGRAM_SYMBOLTABLE(arg_node);
    } else {
        CTInote("No global definitions found. Nothing done.");
    }

    DBUG_RETURN(arg_node);
}

node *TGglobaldef(node *arg_node, info *arg_info) {
    DBUG_ENTER("TGglobaldef");

    if(GLOBALDEF_EXPR(arg_node)) {
        EXPR_FOUND(arg_info) = TRUE;
        node *assign = TBmakeAssign(GLOBALDEF_ID(arg_node), GLOBALDEF_EXPR(arg_node));
        node *new_statement = TBmakeStatements(assign, NULL);

        // If statement last is set use this to append the new statement
        if(STATEMENT_LAST(arg_info)) {
            node *last = STATEMENT_LAST(arg_info);
            STATEMENTS_NEXT(last) = new_statement;
        } else {
            // Otherwise add the statement as first
            FUNBODY_STATEMENTS(INIT_BODY(arg_info)) = new_statement;
        }

        // Add a new entry to the symboltable;
        node *symboltable = INIT_SYMBOLTABLE(arg_info);
        node *entry = SYMBOLTABLE_HEAD(symboltable);
        node *new_entry = TBmakeSymboltableentry(GLOBALDEF_ID(arg_node), GLOBALDEF_TYPE(arg_node), FALSE, NULL);

        if(entry) {
            // Append new entry to the list
            while(SYMBOLTABLEENTRY_NEXT(entry)) {
                entry = SYMBOLTABLEENTRY_NEXT(entry);
            }
            SYMBOLTABLEENTRY_NEXT(entry) = new_entry;
        } else {
            // New entry is head
            SYMBOLTABLE_HEAD(symboltable) = new_entry;
        }
        // Set the statement as last in order to quickly find it
        STATEMENT_LAST(arg_info) = new_statement;
        // Remove the expression from the globaldef-node
        GLOBALDEF_EXPR(arg_node) = NULL;
    } else {
        printf("No globaldef expressions\n");
    }

    DBUG_RETURN(arg_node);
}

node *TGdoTransformGlobalInit(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("TGdoTransformGlobalInit");

    arg_info = MakeInfo();
    TRAVpush(TR_tg);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();
    arg_info = FreeInfo(arg_info);

    DBUG_RETURN(syntaxtree);
}