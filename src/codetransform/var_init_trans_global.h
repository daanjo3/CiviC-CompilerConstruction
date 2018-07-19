#ifndef _VAR_INIT_TRANSFORM_GLOBAL_H_
#define _VAR_INIT_TRANSFORM_GLOBAL_H_
#include "types.h"

extern node *TGprogram(node *arg_node, info *arg_info);
extern node *TGglobaldef(node *arg_node, info *arg_info);
extern node *TGdoTransformGlobalInit(node *syntaxtree);

#endif