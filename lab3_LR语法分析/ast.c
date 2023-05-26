#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "lrparser.tab.h"


past newAstNode(){
	past node = malloc(sizeof(ast));
	if(node == NULL)
	{
		printf("run out of memory.\n");
		exit(0);
	}
	memset(node, 0, sizeof(ast));
	return node;
}

void showAst(char* sym, past node, int nest){
	if(node == NULL)
		return;
	int i = 0;
	for(i = 0; i < nest; i ++)
		printf("  ");
	if(node->nodeType == TRANSLATION_UNIT){
		printf("%s-%s\n", sym, node->snodeType);
		showTranstion(node, nest + 1);
		return;
	} else if(node->nodeType == INTEGER_LITERAL){
		printf("%s-%s  %d\n", sym, node->snodeType, node->ivalue);
	} else if(node->nodeType == FLOATING_LITERAL){
		printf("%s-%s  %f\n", sym, node->snodeType, node->fvalue);
	} else if(node->nodeType == IF_STMT){
		printf("%s-%s  %s\n", sym, node->snodeType, node->svalue);
		showAst("|", node->if_cond, nest+1);
	} else if(node->nodeType == FUNCTION_DECL){
		printf("%s-%s  %s '%s'\n", sym, node->snodeType, node->svalue, node->stype);
	} else if(node->nodeType == PARM_DECL){
		showParaDecl(node);
		return;
	} else if(node->nodeType == COMPOUND_STMT){
		printf("%s-%s\n", sym, node->snodeType);
		node = node->right;
		showCompoundStmt(node, nest + 1);
		return;
	} else if(node->nodeType == VAR_DECL){
		printf("%s-%s  %s '%s'\n", sym, node->snodeType, node->svalue, node->stype);
	} else if(node->nodeType == CALL_EXPR){
		printf("%s-%s  %s\n", sym, node->snodeType, node->svalue);
		node = node->left;
		showCallExp(node, nest + 1);
		return;
	} else if(node->svalue != NULL){
		printf("%s-%s  '%s'\n", sym, node->snodeType, node->svalue);
	} else{
		printf("%s-%s\n", sym, node->snodeType);
	}
	showAst("|", node->left, nest+1);
	showAst("`", node->right, nest+1);
}

void showTranstion(past node, int nest){ //函数块
	if(node == NULL){
		return;
	}
	while(node->right != NULL){
		showAst("|", node->left, nest);
		node = node->right;
	}
	showAst("`", node->left, nest);
}

void showCallExp(past node, int nest){ //函数调用遍历
	if(node == NULL){
		return;
	}
	while(node->right != NULL){
		showAst("|", node->left, nest);
		node = node->right;
	}
	showAst("'", node->left, nest);
}

void showCompoundStmt(past node, int nest){ //复合语句遍历
	if(node == NULL){
		return;
	}
	while(node->right != NULL){
		showAst("|", node->left, nest);
		node = node->right;
	}
	showAst("'", node->left, nest);
}

void showParaDecl(past node){ //函数参数，非递归中序遍历
	if(node == NULL){
		return;
	}
	int sym = 1;
	past stack[100];
	int top = 0;
    while(top || node){
		if(node != NULL){ 
			stack[top++] = node;
            node = node->left;
        }else if(top != 0){   
			node = stack[--top];
			if(sym == 1){
				printf("|-%s  used %s '%s'\n", node->snodeType, node->svalue, node->stype);
				sym--;
			} else {
				printf("    |-%s  used %s '%s'\n", node->snodeType, node->svalue, node->stype);
			}
            node = node->right;
        }
    }
}

char* get_id(char* id){
	int i = 0;
	while(id[i] != '\0'){
		i++;
	}
	char* s = malloc(sizeof(char) * (i + 1));
	memcpy(s, id, i + 1);
	return s;
}

char* get_stype(int type){
	char* stype;
	if(type == 0){
		return NULL;
	} else if(type == Y_INT){
		stype = "int";
	} else if(type == Y_FLOAT){
		stype = "float";
	} else {
		stype = "void";
	}
	return stype;
}

char* get_conststype(int type){
	char* stype;
	if(type == 0){
		return NULL;
	} else if(type == Y_INT){
		stype = "const int";
	} else if(type == Y_FLOAT){
		stype = "const float";
	} else {
		stype = "const void";
	}
	return stype;
}

past newCompUnit(past left, past right){
	past node = newAstNode();
	node->nodeType = TRANSLATION_UNIT;
	node->snodeType = "TRANSLATION_UNIT";
	node->left = left;
	node->right = right;
	return node;
}

past newDeclStmt(past left, past right){  //声明语句，left 为变量/常声明结点，right为下一个声明语句
	past node = newAstNode();
	node->nodeType = DECL_STMT;
	node->snodeType = "DECL_STMT";
	node->left = left;
	node->right = right; 
	return node;
}

past newDeclRefExp(char* name, past left, past right){ //声明调用，主要用于变量引用，name为变量名，left，right，默认为NULL
	past node = newAstNode();
	node->nodeType = DECL_REF_EXPR;
	node->snodeType = "DECL_REF_EXPR";
	node->svalue = name;
	node->left = left;
	node->right = right;
	return node;
}

past newFuncDecl(char* stype, int type, char* name, past left, past right){ //left为形参列表，right为函数体
	past node = newAstNode();
	node->nodeType = FUNCTION_DECL;
	node->snodeType = "FUNCTION_DECL";
	node->svalue = name;
	node->left = left;
	node->right = right;
	node->ivalue = type;
	node->stype = stype;
	return node;	
}

past newVarDecl(char* stype, int type, int if_const, char *name, past left, past right){ //left固定为空，right为变量初始赋值
	past node = newAstNode();
	node->nodeType = VAR_DECL;
	node->snodeType = "VAR_DECL";
	node->stype = stype;
	node->left = left;
	node->right = right;
	node->ivalue = type;
	node->svalue = name;
	node->if_const = if_const;
	return node;	
}


past newCompoundStmt(past left, past right){  //复合语句表达式，left代表当前语句，right代表下一条语句
	past node = newAstNode();
	node->nodeType = COMPOUND_STMT;
	node->snodeType = "COMPOUND_STMT";
	node->left = left;
	node->right = right;
	return node;
}


past newArraySubscriptsExp(past left, past right){  //数组下标表达式，left为数组名，right为数组下标，若为多维数组则right的left，right均为数组下标
	past node = newAstNode();
	node->nodeType = ARRAY_SUBSCRIPT_EXPR;
	node->snodeType = "ARRAY_SUBSCRIPT_EXPR";
	node->left = left;
	node->right = right;
	return node;
}

past newBinaryOper(char* soper, int oper, past left, past right){  //oper为运算符，left，right为操作数表达式
	past node = newAstNode();
	node->nodeType = BINARY_OPERATOR;
	node->snodeType = "BINARY_OPERATOR";
	node->ivalue = oper;
	node->svalue = soper;
	node->left = left;
	node->right = right;
	return node;
}


past newCallExp(char* stype, int type, char* name, past left, past right){  //函数调用表达式，left为实参，right为NULL，stype,type默认为NULL跟0，name为函数名
	past node = newAstNode();
	node->nodeType = CALL_EXPR;
	node->snodeType = "CALL_EXPR";
	node->stype = stype;
	node->ivalue = type;
	node->svalue = name;
	node->left = left;
	node->right = right;
	return node;
}

past newParaDecl(char* stype,char* name,  past left, past right){  //函数参数表达式，，left为下一个变量结点,right 默认为NULL,只需记录类型即可
	past node = newAstNode();
	node->nodeType = PARM_DECL;
	node->snodeType = "PARM_DECL";
	node->stype = stype;
	node->svalue = name;
	node->left = left;
	node->right = right;
	return node;
}

past newIntVal(int ival){
	past node = newAstNode();
	node->nodeType = INTEGER_LITERAL;
	node->snodeType = "INTEGER_LITERAL";
	node->ivalue = ival;
	return node;
}

past newFloatVal(float fval){
	past node = newAstNode();
	node->nodeType = FLOATING_LITERAL;
	node->snodeType = "FLOATING_LITERAL";
	node->fvalue = fval;
	return node;
}

past newIfStmt(past if_cond, past left, past right){ //if_cond为条件表达式，left为if复合语句，right为else复合语句
	past node = newAstNode();
	node->nodeType = IF_STMT;
	node->snodeType = "IF_STMT";
	node->if_cond = if_cond;
	node->left = left;
	node->right = right;
	if(right != NULL){
		node->svalue = "has else";
	} else {
		node->svalue = "no else";
	}
	return node;
}

past newWhileStmt(past left, past right){  //left为循环条件表达式，right为循环体复合语句
	past node = newAstNode();
	node->nodeType = WHILE_STMT;
	node->snodeType = "WHILE_STMT";
	node->left = left;
	node->right = right;
	return node;
}

past newContinueStmt(){
	past node = newAstNode();
	node->nodeType = CONTINUE_STMT;
	node->snodeType = "CONTINUE_STMT";
	return node;
}

past newBreakStmt(){
	past node = newAstNode();
	node->nodeType = BREAK_STMT;
	node->snodeType = "BREAK_STMT";
	return node;
}

past newReturnStmt(past left, past right){   //left为返回值结点，right默认为NULL
	past node = newAstNode();
	node->nodeType = RETURN_STMT;
	node->snodeType = "RETURN_STMT";
	node->left = left;
	node->right = right;
	return node;
}

past newType(int oper){
	past node = newAstNode();
	node->ivalue = oper;
	return node;
}
