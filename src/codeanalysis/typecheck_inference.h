#ifndef _TYPECHECK_INFERENCE_H_
#define _TYPECHECK_INFERENCE_H_

#include "types.h"

// Nodes for the symboltable
extern node *TCIprogram(node *arg_node, info *arg_info);
extern node *TCIfundefdec(node *arg_node, info *arg_info);

// Statements to check
extern node *TCIbinop(node *arg_node, info *arg_info);
extern node *TCImonop(node *arg_node, info *arg_info);
extern node *TCIcast(node *arg_node, info *arg_info);
extern node *TCIfuncall(node *arg_node, info *arg_info);
extern node *TCIvar(node *arg_node, info *arg_info);
extern node *TCInum(node *arg_node, info *arg_info);
extern node *TCIfloat(node *arg_node, info *arg_info);
extern node *TCIbool(node *arg_node, info *arg_info);

extern node *TCIdoTypeCheckInference(node *syntaxtree);

#endif