#ifndef _PRINT_ST_H_
#define _PRINT_ST_H_
#include "types.h"

char* type_to_string(basictype type);

extern node *PSsymboltable(node *arg_node, info *arg_info);
extern node *PSsymboltableentry(node *arg_node, info *arg_info);
extern node *PSdoPrintSymbolTable(node *syntaxtree);

#endif