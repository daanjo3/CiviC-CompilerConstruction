#ifndef _CODEANALYSIS_HELPER_H_
#define _CODEANALYSIS_HELPER_H_

#include "types.h"

extern char *getTypeChar(basictype type);

extern node *getSymboltableEntry(char *name, bool isfunction, node *symboltable);

// Returns the type of the expression
extern basictype getExpressionType(node *expr, node *symboltable);

// Returns the category to which the binary operator belongs
extern binopcat getBinopCat(binop op);

#endif