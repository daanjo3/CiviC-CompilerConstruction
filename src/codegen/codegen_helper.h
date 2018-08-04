#ifndef _CODEGEN_HELPER_H_
#define _CODEGEN_HELPER_H_

#include "types.h"

// Input N_fundefdec with body
extern int getLocalVarCount(node *arg_node);
// extern int getParamCount(node *arg_node);

extern int getIndexFromLut(lut_t *lookup, char* name, bool function);
extern void insertSymbolsIntoLut(lut_t *lookup, node *symboltable);

#endif