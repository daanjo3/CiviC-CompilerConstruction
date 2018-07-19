#ifndef _TRANSFORM_FOR_H_
#define _TRANSFORM_FOR_H_

#include "types.h"

extern node *TFfundefdec(node *arg_node, info *arg_info);
extern node *TFfor(node *arg_node, info *arg_info);

extern node *TFdoTransformFor(node *syntaxtree);

#endif