#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "genthreeaddress.h"
#include "threeaddress.tab.h"
#define arry_len 1000
char* codearry[1000];
char sprintfBuffer[500];
int temVarNum = 0;
int ad_num = 100;
int count = 0;
int if_record = 0;

void addCodes(char* codes) {
	if(count < arry_len){
		codearry[count] = (char *)malloc(sizeof(char) * 100);
		strcpy(codearry[count], codes);
		codearry[count][99] = '\0';
		count++;
	} 
}

int getTemVarNum() {
	temVarNum ++;
	return temVarNum;
}

void print_func(){
	int i = 0;
	while(i < arry_len && codearry[i] != NULL){
		printf("%s", codearry[i]);
		i++;
	}
	printf("%d:  中间代码结束", ad_num);
}

int get_sym(past node){
	if(node == NULL){
		return 0;
	} else if(node->nodeType == BINARY_OPERATOR && (node->ivalue == Y_ADD || node->ivalue == Y_SUB || node->ivalue == Y_MUL || node->ivalue == Y_DIV || node->ivalue == Y_MODULO)){
		return 1;
	} else if(node->nodeType == BINARY_OPERATOR && (node->ivalue == Y_NOT || node->ivalue == Y_AND || node->ivalue == Y_OR || node->ivalue == Y_EQ || node->ivalue == Y_NOTEQ || node->ivalue == Y_LESS || node->ivalue == Y_LESSEQ || node->ivalue == Y_GREAT || node->ivalue == Y_GREATEQ)){
		return 2;
	} else if(node->nodeType == BINARY_OPERATOR && node->ivalue == Y_ASSIGN){
		return 3;
	} else if(node->nodeType == IF_STMT){
		return 4;
	} else {
		return 5;
	}
}

int genPrimaryExpr(past node, char* result){  //基本表达式
	if(node->nodeType == INTEGER_LITERAL){
		if(result != NULL){
			sprintf(result, "%d", node->ivalue);
		}
	} else if(node->nodeType == FLOATING_LITERAL){
		if(result != NULL){
			sprintf(result, "%f", node->fvalue);
		}
	} else if(node->nodeType == BINARY_OPERATOR){
		//表达式的中间结果用临时变量保存
		//其结果为当前的 temVarNum
		if_record = 0;
		int tep = get_sym(node);
		if(tep == 2){
			genLogicExpr(node, NULL);
		} else {
			genArithmeticExpr(node, NULL);
		}
		if(result != NULL){
			sprintf(result, "t%d", temVarNum);
		}
		if_record = 1;
	} else if(node->nodeType == COMPOUND_STMT){ 
		//复合语句处理
		if(node->left == NULL && node->right != NULL){
			node = node->right; 
		} 
		int tep = get_sym(node->left);
		if(tep == 1){
			genArithmeticExpr(node->left, NULL);
		} else if(tep == 0){
			return 1;
		} else if(tep == 2){
			genLogicExpr(node->left, NULL);
		} else if(tep == 3){
			genAssignStmt(node->left, NULL);
		} else if(tep == 4){
			genIfStmt(node->left, NULL);
		} else{
			genWhileStmt(node->left, NULL);
		}
		if(node->right != NULL){
			genPrimaryExpr(node->right, NULL);
		}
		return 1;
	} else if(node->nodeType == DECL_REF_EXPR){
		if(result != NULL){
			sprintf(result, "%s", node->svalue);
		}
	} else {
		printf("ERROR!");
		return -1;
	}
	return 1;
}
 
int genArithmeticExpr(past node, char* result){  //算术表达式
	if(node == NULL){
		return -1;
	}

	int ltype = -1;
	int rtype = -1;

	if(node->nodeType == BINARY_OPERATOR){
		char loperand[100];
		char roperand[100];
		char oper[5];

		//一元表达式左操作符为空
		if( node->left != NULL){
			ltype = genPrimaryExpr(node->left, loperand);
		}
		rtype = genPrimaryExpr(node->right, roperand);
		if(node->left == NULL) {
			//处理一元表达式
			ltype = rtype;
			sprintf(loperand, "0");
		}

		if( ltype == rtype && ltype != -1) {
			switch(node->ivalue) {
				case Y_ADD: sprintf(oper, "+"); 
						break;
				case Y_SUB: sprintf(oper, "-"); 
						break;
				case Y_MUL: sprintf(oper, "*"); 
						break;
				case Y_DIV: sprintf(oper, "/"); 
						break;
				case Y_MODULO: sprintf(oper, "%"); 
						break;
			}

			sprintf(sprintfBuffer, "%d:  t%d = %s %s %s\n",	ad_num, getTemVarNum(), loperand, oper, roperand);
			ad_num++;
			addCodes(sprintfBuffer);
			result = sprintfBuffer;
			return 1;
		}

	}
	return -1;
}

int genLogicExpr(past node, char* result){  //逻辑表达式
	if(node == NULL){
		return -1;
	}

	int ltype = -1;
	int rtype = -1;

	if(node->nodeType == BINARY_OPERATOR){
		char loperand[100];
		char roperand[100];
		char oper[5];
		//一元表达式左操作符为空
		if( node->left != NULL){
			ltype = genPrimaryExpr(node->left, loperand);
		}
		rtype = genPrimaryExpr(node->right, roperand);
		if(node->left == NULL) {
			//处理一元表达式
			ltype = rtype;
			sprintf(loperand, "0");
		}
		if( ltype == rtype && ltype != -1) {
			switch(node->ivalue) {
				case Y_NOT: sprintf(oper, "!"); 
						break;
				case Y_AND: sprintf(oper, "&&"); 
						break;
				case Y_OR: sprintf(oper, "||"); 
						break;
				case Y_EQ: sprintf(oper, "=="); 
						break;
				case Y_NOTEQ: sprintf(oper, "!="); 
						break;
				case Y_LESS: sprintf(oper, "<"); 
						break;
				case Y_LESSEQ: sprintf(oper, "<="); 
						break;
				case Y_GREAT: sprintf(oper, ">"); 
						break;
				case Y_GREATEQ: sprintf(oper, ">="); 
						break;
			}
			if(if_record == 1){
				sprintf(sprintfBuffer, "%s %s %s", loperand, oper, roperand);
				strncpy(result, sprintfBuffer, 100);
				result[99] = '\0';
			} else {
				sprintf(sprintfBuffer, "%d:  t%d = %s %s %s\n",	ad_num, getTemVarNum(), loperand, oper, roperand);
				ad_num++;
				addCodes(sprintfBuffer);
			}
			return 1;
		}
	}
	return -1;
}

int genLVal(past node, char* result){ //赋值表达式的左值
	if(node->nodeType == DECL_REF_EXPR){
		if(result != NULL){
			sprintf(result, "%s", node->svalue);
		}
	} else {
		printf("ERROR: 发现不支持的运算类型");
		return -1;
	}
	return 1;
}

int genAssignStmt(past node, char* result){ //赋值表达式
	if(node == NULL){
		return -1;
	}

	int ltype = -1;
	int rtype = -1;

	if(node->nodeType == BINARY_OPERATOR){
		char loperand[100];
		char roperand[100];
		ltype = genLVal(node->left, loperand);
		rtype = genPrimaryExpr(node->right, roperand);
		if(rtype == 1 && ltype == 1) {
			sprintf(sprintfBuffer, "%d:  %s = %s\n", ad_num, loperand, roperand);
			ad_num++;
			addCodes(sprintfBuffer);
			result = sprintfBuffer;
			return 1;
		}
	}
	return -1;
}

int genIfStmt(past node, char* result){
	if(node == NULL){
		return -1;
	}

	int Texpr = -1;
	int Fexpr = -1;
	int ifexpr = -1;
	int Trecord = 0; 
	int Frecord = 0;
	if(node->nodeType == IF_STMT){
		char sTexpr[100];
		char sFexpr[100];
		char sifexpr[100];
		if_record = 1;
		ifexpr = genLogicExpr(node->if_cond, sifexpr);
		if_record = 0;
		if(ifexpr == 1){
			sprintf(sprintfBuffer, "%d:  if %s goto %d\n", ad_num, sifexpr, ad_num + 2);
			ad_num++;
			addCodes(sprintfBuffer);
			sprintf(sprintfBuffer, "%d:  goto", ad_num);
			ad_num++;
			Trecord = count;
			addCodes(sprintfBuffer);
		}
		Texpr = genPrimaryExpr(node->left, sTexpr);
		if(Texpr == 1){
			if(node->right != NULL){
				sprintf(sprintfBuffer, " %d\n", ad_num + 1);
			} else {
				sprintf(sprintfBuffer, " %d\n", ad_num);
			}
			strcat(codearry[Trecord], sprintfBuffer);
		} 
		if(node->right != NULL){
			sprintf(sprintfBuffer, "%d:  goto", ad_num, ad_num + 1);
			ad_num++;
			Frecord = count;
			addCodes(sprintfBuffer);
			Fexpr = genPrimaryExpr(node->right, sFexpr);
			sprintf(sprintfBuffer, " %d\n", ad_num);
			strcat(codearry[Frecord], sprintfBuffer);
		}
		
		return 1;
	}
	return -1;	
}

int genWhileStmt(past node, char* result){
	if(node == NULL){
		return -1;
	}

	int lexpr = -1;
	int rexpr = -1;
	int record;
	int loop = ad_num;
	if(node->nodeType == WHILE_STMT){
		char slexpr[100];
		char srexpr[100];
		if_record = 1;
		lexpr = genLogicExpr(node->left, slexpr);
		if_record = 0;
		if(lexpr == 1){
			sprintf(sprintfBuffer, "%d:  if %s goto %d\n", ad_num, slexpr, ad_num + 2);
			ad_num++;
			addCodes(sprintfBuffer);
			sprintf(sprintfBuffer, "%d:  goto", ad_num);
			ad_num++;
			record = count;
			addCodes(sprintfBuffer);
		}
		rexpr = genPrimaryExpr(node->right, srexpr);
		if(rexpr == 1){
			sprintf(sprintfBuffer, " %d\n", ad_num);
			strcat(codearry[record], sprintfBuffer);
		} 
		sprintf(sprintfBuffer, "%d:  goto %d\n", ad_num, loop);
		ad_num++;
		addCodes(sprintfBuffer);
		return 1;
	}
	return -1;	
}
