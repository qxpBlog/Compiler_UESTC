/*
	@author:qinxinpeng
	@time:2023.1.2
	！！！说明：本程序生成三地址代码
*/

#include<stdio.h>
#include "ast.h"
#include "genthreeaddress.h"
#include "threeaddress.tab.h" 
extern int temVarNum;
past astRoot;


void yyerror(char *s) {
	return;
}

int main() {
    yyparse();
	//抽象语法树打印
	printf("==========抽象语法树结构==========\n\n");
	showAst("|", astRoot->next, 0);
	past expr = astRoot->next;
	while( expr != NULL) {
		switch (get_sym(expr)) {
			case 1: genArithmeticExpr(expr, NULL);
					break;
			case 2: genLogicExpr(expr, NULL);
					break;
			case 3: genAssignStmt(expr, NULL);
					break;
			case 4: genIfStmt(expr, NULL);
					break;
			case 5: genWhileStmt(expr, NULL);
					break;
			default:printf("ERROR:node结点为空");
					break;
		}
		expr = expr->next;
	}
	//三地址代码打印
	printf("\n\n");
	printf("==========三地址代码==========\n\n");
	print_func();
	return 0;
}



