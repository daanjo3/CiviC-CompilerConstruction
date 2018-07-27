#ifndef _TYPECHECK_MATCH_H_
#define _TYPECHECK_MATCH_H_

#include "types.h"

extern node *TCMprogram(node *arg_node, info *arg_info);
extern node *TCMfundefdec(node *arg_node, info *arg_info);

extern node *TCMglobaldef(node *arg_node, info *arg_info);
extern node *TCMassign(node *arg_node, info *arg_info);
extern node *TCMfuncall(node *arg_node, info *arg_info);
extern node *TCMif(node *arg_node, info *arg_info);
extern node *TCMwhile(node *arg_node, info *arg_info);
extern node *TCMdowhile(node *arg_node, info *arg_info);
extern node *TCMfor(node *arg_node, info *arg_info);
extern node *TCMreturn(node *arg_node, info *arg_info);

extern node *TCMdoTypeCheckMatch(node *syntaxtree);

#endif