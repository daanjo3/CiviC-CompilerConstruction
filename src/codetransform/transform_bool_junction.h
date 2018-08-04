#ifndef _TRANSFORM_BOOL_JUNCTION_H_
#define _TRANSFORM_BOOL_JUNCTION_H_

#include "types.h"

extern node *TBJbinop(node *arg_node, info *arg_info);

extern node *TBJdoTransformBooleanJunctions(node *syntaxtree);

#endif