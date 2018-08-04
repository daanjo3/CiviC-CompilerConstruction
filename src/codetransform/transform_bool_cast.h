#ifndef _TRANSFORM_BOOL_CAST_H_
#define _TRANSFORM_BOOL_CAST_H_

#include "types.h"

extern node *TBCprogram(node *arg_node, info *arg_info);
extern node *TBCfundefdec(node *arg_node, info *arg_info);

extern node *TBCcast(node *arg_node, info *arg_info);

extern node *TBCdoTransformBooleanCast(node *syntaxtree);

#endif