#ifndef _TYPE_CHECK_H_
#define _TYPE_CHECK_H_

#include "types.h"

// Nodes for the symboltable
extern node *TCprogram(node *arg_node, info *arg_info);
extern node *TCfundefdec(node *arg_node, info *arg_info);

extern node *TCvar(node *arg_node, info *arg_info);
extern node *TCprogram(node *arg_node, info *arg_info);

extern node *TCdoTypeCheck(node *syntaxtree);

#endif