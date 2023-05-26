
#ifndef GENTHREEADDRESS_H
#define GENTHREEADDRESS_H

#include "ast.h"


#define true 1
#define false 0
int get_sym(past node);
void print_func();
int getTemVarNum();
void addCodes(char* codes);
int genPrimaryExpr(past node, char* result);
int genArithmeticExpr(past node, char* result);
int genLogicExpr(past node, char* result);
int genIfStmt(past node, char* result);
int genWhileStmt(past node, char* result);
int genAssignStmt(past node, char* result);

#endif
