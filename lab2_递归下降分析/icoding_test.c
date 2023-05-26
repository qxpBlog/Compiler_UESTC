/*
 * 完成人　：2021090910009(秦鑫鹏)
 * 提交时间：2023-02-25, Sat, 17:47:09
 * 系统评分：100
 */


#include "rdlab2.h"

int cord = 0;

past newParaDecl(past left, past right, past next);
past newBinaryOper(int oper, past left, past right);
past newCompoundStmt(past left, past right);
past newWhileStmt(past left, past right);
past newIfStmt(past if_cond, past left, past right);
past newReturnStmt(past left, past right);
past newDeclRefExp(char * name, past left, past right);
past newBreakStmt();
past newContinueStmt();
past astAddExp();
past astMulExp();
past astMulExp();
past astUnaryExp();
past astPrimaryExp();
past astLOrExp();
past astLAndExp();
past astEqExp();

past rd_call_paras(){
	past l = astAddExp();
	past t = l;
	while(cur_token.token == Y_COMMA){
		advance();
		past r = astAddExp();
		l->next = r;
		l = l->next;
	}
	return t;
}


past rd_relexp(){  //
	past l = astAddExp();
	while(cur_token.token == Y_LESS || cur_token.token == Y_LESSEQ || cur_token.token == Y_GREAT || cur_token.token == Y_GREATEQ){
		int oper = cur_token.token;
		advance();
		past r = astAddExp();
		l = newBinaryOper(oper, l, r);
	}
	return l;
}


past rd_stmt(){
	past t;
	if(cur_token.token == Y_ID){  
		char* s = cur_token.attr.svalue;
		advance();
		rd_array_subscripts();
		if(cur_token.token != Y_ASSIGN){
			return NULL;
		}
		advance();
		past l = astAddExp();
		if(cur_token.token != Y_SEMICOLON){
			return NULL;
		}
		advance();
		past r = newDeclRefExp(s, NULL, NULL);
		return newBinaryOper(Y_ASSIGN, r, l);
	} else if(cur_token.token == Y_SEMICOLON){
		advance();
		return NULL;
	} else if((t = astAddExp())){
		if(cur_token.token != Y_SEMICOLON){
			return NULL;
		}
		advance();
		return t;
	} else if(cur_token.token == Y_LBRACKET){  
		advance(); 
		past l = rd_block();
		if(cur_token.token != Y_RBRACKET){
			return NULL;
		}
		advance();
		return l;
	} else if(cur_token.token == Y_WHILE){
		cord = 1;
		advance();
		if(cur_token.token != Y_LPAR){
			return NULL;
		}
		advance();
		past l = astLOrExp();
		if(cur_token.token != Y_RPAR){
			return NULL;
		}
		advance();
		past r = rd_stmt();
		return newWhileStmt(l, r);
	} else if(cur_token.token == Y_IF){
		advance();
		if(cur_token.token != Y_LPAR){
			return NULL;
		}
		advance();
		past l1 = astLOrExp();
		if(cur_token.token != Y_RPAR){
			return NULL;
		}
		advance();
		past l2 = rd_stmt();
		if(cur_token.token != Y_ELSE){
			return newIfStmt(l1, l2, NULL);
		}
		advance();
		past l3 = rd_stmt();
		return newIfStmt(l1, l2, l3);
	} else if(cur_token.token == Y_BREAK){
		advance();
		if(cur_token.token != Y_SEMICOLON){
			return NULL;
		}
		advance();
		return newBreakStmt();
	} else if(cur_token.token == Y_CONTINUE){
		advance();
		if(cur_token.token != Y_SEMICOLON){
			return NULL;
		}
		advance();
		return newContinueStmt();
	} else if(cur_token.token == Y_RETURN){
		advance();
		past l = astAddExp();
		if(cur_token.token != Y_SEMICOLON){
			return NULL;
		}
		advance();
		return newReturnStmt(l, NULL);
	} else {
		return NULL;
	}
}

past astLOrExp(){
	past l = astLAndExp();
	while(cur_token.token == Y_OR){
		advance();
		past r = astLAndExp();
		l = newBinaryOper(Y_OR, l, r);
	}
	return l;
}

past astLAndExp(){
	past l = astEqExp();
	while(cur_token.token == Y_AND){
		advance();
		past r = astEqExp();
		l = newBinaryOper( Y_AND, l, r);
	}
	
	return l;
}

past astEqExp(){
	past l = rd_relexp();
	while(cur_token.token == Y_EQ || cur_token.token == Y_NOTEQ){
		int oper = cur_token.token;
		advance();
		past r = rd_relexp();
		l = newBinaryOper(oper, l, r);
	}
	
	return l;
}

past astPrimaryExp(){
	if(cur_token.token == Y_LPAR){
		advance();
		past n1 = astAddExp();
		if(cur_token.token != Y_RPAR){
			return NULL;
		}
		return n1;
	} else if(cur_token.token == Y_ID){  
		char* s = cur_token.attr.svalue;
		past l = newDeclRefExp(s, NULL, NULL);
		advance();
		if(cur_token.token == Y_LPAR){ 
			rd_array_subscripts();
		}
		return l;
	} else if(cur_token.token == num_INT){
		past n2 = newInt(cur_token.attr.ivalue);
		advance();
		return n2;
	} else if(cur_token.token == num_FLOAT){
		past n3 = newAstNode();
		advance();
		n3->fvalue = cur_token.attr.fvalue;
		return n3;
	} else {
		return NULL;
	}
}

past astUnaryExp(){
	past l = astPrimaryExp();
	if(l != NULL){
		return l;
	} else if(cur_token.token == Y_ID){ 
		char* s = cur_token.attr.svalue;
		advance();
		if(cur_token.token != Y_LPAR){
			return NULL;
		}
		advance();
		if(cur_token.token == Y_RPAR){
			advance();
			return newDeclRefExp(s, NULL, NULL);
		} else {
			rd_call_paras();
			if(cur_token.token != Y_RPAR){
				return NULL;
			}
			advance();
			return newDeclRefExp(s, NULL, NULL);
		}
	} else if(cur_token.token == Y_ADD){
		advance();
		past l = astUnaryExp();
		return newBinaryOper(Y_ADD, NULL, l);
	} else if(cur_token.token == Y_SUB){
		advance();
		past l = astUnaryExp();
		return newBinaryOper(Y_SUB, NULL, l);
	} else if(cur_token.token == Y_NOT){
		advance();
		past l = astUnaryExp();
		return newBinaryOper(Y_NOT, NULL, l);
	} else {
		return NULL;
	}
}

past astMulExp(){
	past l = astUnaryExp();
	while(cur_token.token == Y_MUL || cur_token.token == Y_DIV ||cur_token.token == Y_MODULO){
		int oper = cur_token.token;
		advance();
		past r = astUnaryExp();
		l = newBinaryOper(oper, l, r);
	}
	return l;
}

past astAddExp(){
    past l = astMulExp();
	while(cur_token.token == Y_ADD || cur_token.token == Y_SUB){
		int oper = cur_token.token;
		advance();
		past r = astMulExp();
		l = newBinaryOper(oper, l, r);
	}
	return l;
}

past newWhileStmt(past left, past right){  
	past node = newAstNode();
	node->nodeType = WHILE_STMT;
	node->left = left;
	node->right = right;
	return node;
}

past newIfStmt(past if_cond, past left, past right){ 
	past node = newAstNode();
	node->nodeType = IF_STMT;
	node->if_cond = if_cond;
	node->left = left;
	node->right = right;
	return node;
}

past newCompoundStmt(past left, past right){  
	past node = newAstNode();
	node->nodeType = COMPOUND_STMT;
	node->left = left;
	node->right = right;
	return node;
}

past newBinaryOper(int oper, past left, past right){  
	past node = newAstNode();
	node->nodeType = BINARY_OPERATOR;
	node->ivalue = oper;
	node->left = left;
	node->right = right;
	return node;
}

past newParaDecl(past left, past right, past next){  
	past node = newAstNode();
	node->nodeType = PARM_DECL;
	node->left = left;
	node->right = right;
	return node;
}
past newBreakStmt(){
	past node = newAstNode();
	node->nodeType = BREAK_STMT;
	return node;
}

past newContinueStmt(){
	past node = newAstNode();
	node->nodeType = CONTINUE_STMT;
	return node;
}

past newReturnStmt(past left, past right){   
	past node = newAstNode();
	node->nodeType = RETURN_STMT;
	node->left = left;
	node->right = right;
	return node;
}

past newDeclRefExp(char * name, past left, past right){ 
	past node = newAstNode();
	node->nodeType = DECL_REF_EXPR;
	node->svalue = name;
	node->left = left;
	node->right = right;
	return node;
}