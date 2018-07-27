#ifndef _CODEANALYSIS_HELPER_H_
#define _CODEANALYSIS_HELPER_H_

#include "types.h"

extern node *getSymboltableEntry(char *name, bool isfunction, node *symboltable);
extern basictype getExpressionType(node *expr, node *symboltable);
extern binopcat getBinopCat(binop op);

#endif