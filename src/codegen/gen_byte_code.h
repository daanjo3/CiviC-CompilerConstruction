#ifndef _GEN_BYTE_CODE_H_
#define _GEN_BYTE_CODE_H_
#include "types.h"

extern node *GBCprogram(node * arg_node, info * arg_info);
extern node *GBCdeclarations(node * arg_node, info * arg_info);

extern node *GBCfundefdec(node * arg_node, info * arg_info);
extern node *GBCfunbody(node * arg_node, info * arg_info);
extern node *GBCvardec(node * arg_node, info * arg_info);
extern node *GBClocalfundefs(node *arg_node, info *arg_info);
extern node *GBCglobaldec(node * arg_node, info * arg_info);
extern node *GBCglobaldef(node * arg_node, info * arg_info);
extern node *GBCparam(node * arg_node, info * arg_info);
extern node *GBCvar(node * arg_node, info * arg_info);
extern node *GBCstatements(node * arg_node, info * arg_info);
extern node *GBCassign(node * arg_node, info * arg_info);
extern node *GBCfuncall(node * arg_node, info * arg_info);
extern node *GBCif(node * arg_node, info * arg_info);
extern node *GBCwhile(node * arg_node, info * arg_info);
extern node *GBCdowhile(node * arg_node, info * arg_info);
extern node *GBCfor(node * arg_node, info * arg_info);
extern node *GBCreturn(node * arg_node, info * arg_info);
extern node *GBCexprs(node * arg_node, info * arg_info);
extern node *GBCbinop(node * arg_node, info * arg_info);
extern node *GBCmonop(node * arg_node, info * arg_info);
extern node *GBCcondexpr(node *arg_node, info *arg_info);
extern node *GBCcast(node * arg_node, info * arg_info);
extern node *GBCnum(node * arg_node, info * arg_info);
extern node *GBCfloat(node * arg_node, info * arg_info);
extern node *GBCbool(node * arg_node, info * arg_info);

extern node *GBCdoGenByteCode( node *syntaxtree);

#endif
