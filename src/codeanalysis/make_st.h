#ifndef _MAKE_ST_H_
#define _MAKE_ST_H_
#include "types.h"

extern node *MSprogram(node *arg_node, info *arg_info);
extern node *MSfundefdec(node *arg_node, info *arg_info);
extern node *MSfor(node *arg_node, info *arg_info);

extern node *MSvardec(node *arg_node, info *arg_info);
extern node *MSglobaldef(node *arg_node, info *arg_info);
extern node *MSglobaldec(node *arg_node, info *arg_info);
extern node *MSdoMakeSymbolTable(node *syntaxtree);

#endif