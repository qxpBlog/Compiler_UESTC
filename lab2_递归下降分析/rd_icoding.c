#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaration Kinds
#ifndef COMPILER_LAB_NODE_TYPE_H
#define COMPILER_LAB_NODE_TYPE_H

enum _node_type{

	// A declaration whose specific kind is not exposed via this interface
	//

	// A C or C++ struct
	STRUCT_DECL = 2,

	// A C or C++ union
	UNION_DECL = 3,

	// An enumeration
	ENUM_DECL = 5,

	// A field in C, or non-static data member in C++, in a struct, union, or C++
	// class
	FIELD_DECL = 6,

	// An enumerator constant
	ENUM_CONSTANT_DECL = 7,

	// A function
	FUNCTION_DECL = 8,

	// A variable
	VAR_DECL = 9,

	// A function or method parameter
	PARM_DECL = 10,


	// A typedef
	TYPEDEF_DECL = 20,

	// A Type alias decl
	TYPE_ALIAS_DECL = 36,


	// A reference to a member of a struct, union, or class that occurs in
	// some non-expression context, eg, a designated initializer
	MEMBER_REF = 47,

	// A reference to a labeled statement
	LABEL_REF = 48,

	// A reference to a set of overloaded functions or function templates
	// that has not yet been resolved to a specific function or function template
	OVERLOADED_DECL_REF = 49,

	// A reference to a variable that occurs in some non-expression
	// context, eg, a C++ lambda capture list
	VARIABLE_REF = 50,


	//////
	// Invalid/Error Kinds

	INVALID_FILE = 70,
	NO_DECL_FOUND = 71,
	NOT_IMPLEMENTED = 72,
	INVALID_CODE = 73,
	

	//////
	// Expression Kinds

	// An expression whose specific kind is not exposed via this interface
	//
	// Unexposed expressions have the same operations as any other kind of
	// expression; one can extract their location information, spelling, children,
	// etc However, the specific kind of the expression is not reported
	UNEXPOSED_EXPR = 100,

	// An expression that refers to some value declaration, such as a function,
	// variable, or enumerator
	DECL_REF_EXPR = 101,

	// An expression that refers to a member of a struct, union, class, Objective-C
	// class, etc
	MEMBER_REF_EXPR = 102,

	// An expression that calls a function
	CALL_EXPR = 103,


	// An expression that represents a block literal
	BLOCK_EXPR = 105,

	// An integer literal
	INTEGER_LITERAL = 106,

	// A floating point number literal
	FLOATING_LITERAL = 107,

	// An imaginary number literal
	IMAGINARY_LITERAL = 108,

	// A string literal
	STRING_LITERAL = 109,

	// A character literal
	CHARACTER_LITERAL = 110,

	// A parenthesized expression, eg "1,"
	//
	// This AST node is only formed if full location information is requested
	PAREN_EXPR = 111,

	// This represents the unary-expression's except sizeof and
	// alignof,
	UNARY_OPERATOR = 112,

	// [C99 6521] Array Subscripting
	ARRAY_SUBSCRIPT_EXPR = 113,

	// A builtin binary operation expression such as "x + y" or
	// "x <= y"
	BINARY_OPERATOR = 114,

	// Compound assignment such as "+="
	COMPOUND_ASSIGNMENT_OPERATOR = 115,

	// The ?: ternary operator
	CONDITIONAL_OPERATOR = 116,

	// An explicit cast in C C99 654, or a C-style cast in C++
	// C++ [exprcast],, which uses the syntax Type,expr
	//
	// For example: int,f
	CSTYLE_CAST_EXPR = 117,

	// [C99 6525]
	COMPOUND_LITERAL_EXPR = 118,

	// Describes an C or C++ initializer list
	INIT_LIST_EXPR = 119,

	// The GNU address of label extension, representing &&label
	ADDR_LABEL_EXPR = 120,



	// A statement whose specific kind is not exposed via this interface
	//
	// Unexposed statements have the same operations as any other kind of statement;
	// one can extract their location information, spelling, children, etc However,
	// the specific kind of the statement is not reported
	UNEXPOSED_STMT = 200,

	// A labelled statement in a function
	LABEL_STMT = 201,

	// A compound statement
	COMPOUND_STMT = 202,

	// A case statement
	CASE_STMT = 203,

	// A default statement
	DEFAULT_STMT = 204,

	// An if statement
	IF_STMT = 205,

	// A switch statement
	SWITCH_STMT = 206,

	// A while statement
	WHILE_STMT = 207,

	// A do statement
	DO_STMT = 208,

	// A for statement
	FOR_STMT = 209,

	// A goto statement
	GOTO_STMT = 210,

	// An indirect goto statement
	INDIRECT_GOTO_STMT = 211,

	// A continue statement
	CONTINUE_STMT = 212,

	// A break statement
	BREAK_STMT = 213,

	// A return statement
	RETURN_STMT = 214,


	// The null statement
	NULL_STMT = 230,

	// Adaptor class for mixing declarations with statements and expressions
	DECL_STMT = 231,


	//////
	// Other Kinds

	// Cursor that represents the translation unit itself
	//
	// The translation unit cursor exists primarily to act as the root cursor for
	// traversing the contents of a translation unit
	TRANSLATION_UNIT = 300,
};

typedef enum _node_type node_type;

#endif
//词法分析单词类型
enum yytokentype {
	num_INT = 258,  
	num_FLOAT = 259,  

	Y_ID = 260,  

	Y_INT = 261,
	Y_VOID = 262,
	Y_CONST = 263,
	Y_IF = 264,
	Y_ELSE = 265,
	Y_WHILE = 266,
	Y_BREAK = 267,
	Y_CONTINUE = 268,
	Y_RETURN = 269,

	Y_ADD = 270,
	Y_SUB = 271,
	Y_MUL = 272,
	Y_DIV = 273,
	Y_MODULO = 274,  
	Y_LESS = 275,  
	Y_LESSEQ = 276, 
	Y_GREAT = 277, 
	Y_GREATEQ = 278,
	Y_NOTEQ = 279,  
	Y_EQ = 280,   
	Y_NOT = 281,
	Y_AND = 282,
	Y_OR = 283,
	Y_ASSIGN = 284,  

	Y_LPAR = 285,    
	Y_RPAR = 286,  
	Y_LBRACKET = 287,
	Y_RBRACKET = 288,
	Y_LSQUARE = 289, 
	Y_RSQUARE = 290,
	Y_COMMA = 291, 
	Y_SEMICOLON = 292,

	Y_FLOAT = 293
};

//全局变量~
extern int yylex();
extern int yylval;
extern char* yytext;
extern int yyleng;
int paranum;
int callParaNum;
int compoundStmtNum;
int if_DeclStmt;
int tok;

//结点声明
typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
	char* stype;
	int ivalue;
	float fvalue;
	char* svalue;
	node_type nodeType;
	char* snodeType;
	int if_const;
	past left;
	past right;
	past if_cond;
	past next;
};

//函数声明

//返回ast结点函数
past newAstNode();
//显示ast
void showAst(char* sym, past node, int nest);
void showParaDecl(past node);
void showCompoundStmt(past node, int nest);
void showCallExp(past node, int nest);
void showTranstion(past node, int nest);
//匹配函数
int match(int x);
//移进函数
void advance();

past astDecl();
past astConstDecl();
past astConstDefs(char* stype, int type);
past astConstDef(char* stype, int type);
past astConstInitVal();
past astVarDecl();
past astVarDecls();
past astVarDef(char* stype, int type);
past astInitVal();
past astFuncDef();
past astFuncParams();
past astFuncParam();
past astBlock();
int  astType();
past astCompUnit();
past astStmt();
past astBlockItems();
past astBlockItem();
past astLOrExp();
past astLAndExp();
past astEqExp();
past astRelExp();
past astExp();
past astAddExp();
past astMulExp();
past astUnaryExp();
past astCallParams();
past astPrimaryExp();
past astArraySubscriptsExp();
past newDeclStmt(past left, past right);
past newCompUnit(past left, past right);
past newDeclRefExp(char* name, past left, past right);
past newFuncDecl(char* stype, int type,char* svalue, past left, past right);
past newBinaryOper(char* soper, int oper, past left, past right);
past newArraySubscriptsExp(past left, past right);
past newCallExp(char* stype, int type, char* name, past left, past right);
past newParaDecl(char* stype, char* name, past left, past right);
past newCompoundStmt(past left, past right);
past newIntVal(int ival);
past newFloatVal(float fval);
past newVarDecl(char* stype, int type, int if_cond, char* s, past left, past right);
past newIfStmt(past if_cond, past left, past right);
past newWhileStmt(past left, past right);
past newContinueStmt();
past newBreakStmt();
past newReturnStmt(past left, past right);


int main(int argc, char **argv){
	advance();
	past node = astCompUnit();
	showAst("|", node, 0);
	return 0;
}

int match(int x){
	if(tok == x){
		return 1;
	}
	return 0;
}

void advance(){
	tok = yylex();
	printf("tok: %s\n", yytext);
}

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

void showTranstion(past node, int nest){ ////编译单元
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
	showAst("`", node->left, nest);
}

void showCompoundStmt(past node, int nest){ //复合语句遍历
	if(node == NULL){
		return;
	}
	while(node->right != NULL){
		showAst("|", node->left, nest);
		node = node->right;
	}
	showAst("`", node->left, nest);
}

void showParaDecl(past node){ //函数参数，非递归中序遍历
	if(node == NULL){
		return;
	}
	int i = paranum;
	past stack[paranum];
	int top = 0;
    while(top || node){
		if(node != NULL){ 
			stack[top++] = node;
            node = node->left;
        }else if(top != 0){   
			node = stack[--top];
			if(i == paranum){
				printf("|-%s  used %s '%s'\n", node->snodeType, node->svalue, node->stype);
				i--;
			} else {
				printf("    |-%s  used %s '%s'\n", node->snodeType, node->svalue, node->stype);
			}
            node = node->right;
        }
    }
}

past astCompUnit(){
	past l = astDecl();
	if(l == NULL){
		l = astFuncDef();
	} 
	l = newCompUnit(l, NULL);
	past res = l;
	past r = astDecl();
	if(r == NULL){
		r = astFuncDef();
	} 
	while(r != NULL){
		r = newCompUnit(r, NULL);
		l->right = r;
		l = r;
		r = astDecl();
		if(r == NULL){
			r = astFuncDef();
		} 
	}
	return res;
} 

past astDecl(){
	past l;
	if((l = astConstDecl())){
		return l;
	} else if((l = astVarDecl())){
		return l;
	} else {
		return NULL;
	}
}

past astConstDecl(){
	if(!match(Y_CONST)){
		return NULL;
	}
	advance();
	int type = astType();
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

	past r = astConstDefs(stype, type);
	if(!match(Y_SEMICOLON)){
		return NULL;
	} 
	advance();
	return newDeclStmt(NULL, r);
}


past astConstDefs(char* stype, int type){
	past l = astConstDef(stype, type);
	while(match(Y_COMMA)){
		advance();
		past r = astConstDef(stype, type);
		l = newDeclStmt(l, r);
	}
	return l;
}

past astConstDef(char* stype, int type){
	if(!match(Y_ID)){
		return NULL;
	}
	char* s = malloc(sizeof(char) * (yyleng + 1));
    strcpy(s, yytext);
	advance();
	if(match(Y_ASSIGN)){
		advance();
		past l = astConstInitVal();
		return newVarDecl(stype, type, 1, s, NULL, l);
	} else if(match(Y_LSQUARE)){
		advance();
		past l = astAddExp();
		if(!match(Y_RSQUARE)){
			return NULL;
		}
		advance();
		while(match(Y_LSQUARE)){
			advance();
			past r = astAddExp();
			if(!match(Y_RSQUARE)){
				return NULL;
			}
			advance();
			// l = newArraySubscriptsExp(l,r); //待修改
		}
		if(!match(Y_ASSIGN)){
			return NULL;
		}
		advance();
		past r = astConstInitVal();
		return newVarDecl(stype, type, 1, s, NULL, r);
	} else {
		return NULL;
	}
}

past astConstInitVal(){
	past l = astAddExp();
	if(l != NULL){
		return l;
	} else if(match(Y_LBRACKET)){
		advance();
		if(match(Y_RBRACKET)){
			advance();
			// return newBinaryOper(0,NULL,NULL);//待修改
		} else {
			past l = astConstInitVal();
			while(match(Y_COMMA)){
				advance();
				past r = astConstInitVal();
				// l = newBinaryOper(Y_COMMA,l,r);
			}
			if(!match(Y_RBRACKET)){
				return NULL;
			}
			advance();
			return l;
		}
	} else {
		return NULL;
	}
}

past astVarDecl(){
	int type = astType();
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
	past r = astVarDecls(stype, type);
	if(r->nodeType == FUNCTION_DECL){
		return r;
	}
	if(!match(Y_SEMICOLON)){
		return NULL;
	}
	advance();
	return newDeclStmt(NULL, r);
}

past astVarDecls(char* stype, int type){
	past l = astVarDef(stype, type);
	if(l->nodeType == FUNCTION_DECL){
		return l;
	}
	while(match(Y_COMMA)){
		advance();
		past r = astVarDef(stype, type);
		l = newDeclStmt(l, r); //要有专门的遍历函数
	}
	return l;
}

past astVarDef(char* stype, int type){
	if(!match(Y_ID)){
		return NULL;
	}
	char* s = malloc(sizeof(char) * (yyleng + 1));
    strcpy(s, yytext);
	advance();
	if(match(Y_LPAR)){ 
		advance();
		if(match(Y_RPAR)){
			advance();
			past l = astBlock();
			l = newCompoundStmt(NULL, l);
			return newFuncDecl(stype, type, s, NULL, l);
		} else {
			past r = astFuncParams();
			if(!match(Y_RPAR)){
			return NULL;
		}
		advance();
		past b = astBlock();
		b = newCompoundStmt(NULL, b);
		return newFuncDecl(stype, type, s, r, b);
		}
	} else if(match(Y_ASSIGN)){
		advance();
		past l = astInitVal();
		return newVarDecl(stype, type, 0, s, NULL, l);
	} else if(match(Y_LSQUARE)){
		advance();
		past l = astAddExp();
		if(!match(Y_RSQUARE)){
			return NULL;
		}
		advance();
		while(match(Y_LSQUARE)){
			advance();
			past r = astAddExp();
			if(!match(Y_RSQUARE)){
				return NULL;
			}
			advance();
			// l = newArraySubscriptsExp(l,r); //需要修改
		}

		if(match(Y_ASSIGN)){
			advance();
			past r = astInitVal();
			return newVarDecl(stype, type, 0, s, NULL, r);
		} else {
			return newVarDecl(stype, type, 0, s, NULL, NULL);
		}
	} else {
		return newVarDecl(stype, type, 0, s, NULL, NULL);
	}
}

past astInitVal(){
	past l = astExp();
	if(l != NULL){
		return l;
	} else if(match(Y_LBRACKET)){ //待修改
		advance();
		if(match(Y_RBRACKET)){
			advance();
			// return newBinaryOper(0,NULL,NULL);
		} else {
			past l = astInitVal();
			while(match(Y_COMMA)){
				advance();
				past r = astInitVal();
				// l = newBinaryOper(Y_COMMA,l,r);
			}
			if(!match(Y_RBRACKET)){
				return NULL;
			}
			advance();
			return l;
		}
	} else {
		return NULL;
	}
}

past astFuncDef(){
	int type = astType();
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
	if(!match(Y_ID)){
		return NULL;
	}
	char* s = malloc(sizeof(char) * (yyleng + 1));
    strcpy(s, yytext);
	advance();
	if(!match(Y_LPAR)){
		return NULL;
	}
	advance();
	if(match(Y_RPAR)){
		advance();
		past l = astBlock();
		l = newCompoundStmt(NULL, l);
		return newFuncDecl(stype, type, s, NULL, l);
	} else {
		past r = astFuncParams();
		if(!match(Y_RPAR)){
			return NULL;
		}
		advance();
		past b = astBlock();
		b = newCompoundStmt(NULL, b);
		return newFuncDecl(stype, type, s, r, b);
	}
}

past astFuncParams(){
	paranum = 1;
	past l = astFuncParam();
	while(match(Y_COMMA)){
		advance();
		past r = astFuncParam();
		r->left = l;
		l = r;
		paranum++;
	}
	return l;
}

past astFuncParam(){ 
	int type = astType();
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

	if(!match(Y_ID)){
		return NULL;
	}
	char* s = malloc(sizeof(char) * (yyleng + 1));
    strcpy(s, yytext);
	advance();
	past l = NULL;
	if(match(Y_LSQUARE)){
		advance();
		if(!match(Y_RSQUARE)){
			return NULL;
		}
		advance();
		l = astArraySubscriptsExp(); //需要修改
		return newParaDecl(stype, s, NULL, NULL);
	} else {
		l = astArraySubscriptsExp();
		return newParaDecl(stype, s, NULL, NULL);
	}
}

//检查部分

past astStmt(){
	past t;
	if(match(Y_ID)){  
		char* s = malloc(sizeof(char) * (yyleng + 1));
        strcpy(s, yytext);
		advance();
		past n = astArraySubscriptsExp();
		if(n == NULL){
			if(!match(Y_ASSIGN)){
				return NULL;
			}
			advance();
			past l = astExp();
			if(!match(Y_SEMICOLON)){
				return NULL;
			}
			advance();
			past r = newDeclRefExp(s, NULL, NULL);
			return newBinaryOper("=", Y_ASSIGN, r, l);
		} else {
			if(!match(Y_ASSIGN)){
				return NULL;
			}
			advance();
			past l = astExp();
			if(!match(Y_SEMICOLON)){
				return NULL;
			}
			advance();
			past r = newDeclRefExp(s, NULL, NULL);
			n = newArraySubscriptsExp(r, n);

			return newBinaryOper("=", Y_ASSIGN, n, l);
		}
	} else if(match(Y_SEMICOLON)){
		advance();
		return NULL;
	} else if((t = astExp())){
		if(!match(Y_SEMICOLON)){
			return NULL;
		}
		advance();
		return t;
	} else if(match(Y_LBRACKET)){  //Block
		advance();
		past l = astBlockItems();
		if(!match(Y_RBRACKET)){
			return NULL;
		}
		advance();
		return l;
	} else if(match(Y_WHILE)){
		advance();
		if(!match(Y_LPAR)){
			return NULL;
		}
		advance();
		past l = astLOrExp();
		if(!match(Y_RPAR)){
			return NULL;
		}
		advance();
		past r = astStmt();
		r = newCompoundStmt(NULL, r);
		return newWhileStmt(l, r);
	} else if(match(Y_IF)){
		advance();
		if(!match(Y_LPAR)){
			return NULL;
		}
		advance();
		past l1 = astLOrExp();
		if(!match(Y_RPAR)){
			return NULL;
		}
		advance();
		past l2 = astStmt();
		l2 = newCompoundStmt(NULL, l2);
		if(!match(Y_ELSE)){
			return newIfStmt(l1, l2, NULL);
		}
		advance();
		past l3 = astStmt();
		l3 = newCompoundStmt(NULL, l3);
		return newIfStmt(l1, l2, l3);
	} else if(match(Y_BREAK)){
		advance();
		if(!match(Y_SEMICOLON)){
			return NULL;
		}
		advance();
		return newBreakStmt();
	} else if(match(Y_CONTINUE)){
		advance();
		if(!match(Y_SEMICOLON)){
			return NULL;
		}
		advance();
		return newContinueStmt();
	} else if(match(Y_RETURN)){
		advance();
		past l = astExp();
		if(!match(Y_SEMICOLON)){
			return NULL;
		}
		advance();
		return newReturnStmt(l, NULL);
	} else {
		return NULL;
	}
}

past astBlock(){ //需要修改
	if(!match(Y_LBRACKET)){
		return NULL;
	}
	advance();
	past l = astBlockItems();
	if(!match(Y_RBRACKET)){
		return NULL;
	}
	advance();
	return l;	
}

past astBlockItems(){
	compoundStmtNum = 1;
	past temp;
	past l = astBlockItem();
	l = newCompoundStmt(l, NULL);
	temp = l;
	past r = astBlockItem();
	while(r!= NULL){
		compoundStmtNum++;
		r = newCompoundStmt(r, NULL);
		l->right = r;
		l = r;
		r = astBlockItem();
	}
	return temp;
}

past astBlockItem(){
	past l = astDecl();
	if(l){
		return l;
	}
	return astStmt();
}

past astLOrExp(){
	past l = astLAndExp();
	while(match(Y_OR)){
		int oper = tok;
		advance();
		past r = astLAndExp();
		l = newBinaryOper("||", oper, l, r);
	}
	return l;
}

past astLAndExp(){
	past l = astEqExp();
	while(match(Y_AND)){
		int oper = tok;
		advance();
		past r = astEqExp();
		l = newBinaryOper("&&", oper, l, r);
	}
	return l;
}

past astEqExp(){
	past l = astRelExp();
	while(match(Y_EQ) || match(Y_NOTEQ)){
		int oper = tok;
		advance();
		past r = astRelExp();
		if(oper == Y_EQ){
			l = newBinaryOper("==", oper, l, r);
		} else {
			l = newBinaryOper("!=", oper, l, r);
		}
	}
	return l;
}

past astRelExp(){
	past l = astAddExp();
	while(match(Y_LESS) || match(Y_LESSEQ) || match(Y_GREAT) || match(Y_GREATEQ)){
		int oper = tok;
		advance();
		past r = astAddExp();
		if(oper == Y_LESS){
			l = newBinaryOper("<", oper, l, r);
		} else if(oper == Y_GREAT){
			l = newBinaryOper(">", oper, l, r);
		} else if(oper == Y_LESSEQ){
			l = newBinaryOper("<=", oper, l, r);
		} else {
			l = newBinaryOper(">=", oper, l, r);
		}
	}
	return l;
}

past astExp(){
	return astAddExp();
}

past astAddExp(){
	past l = astMulExp();
	while(match(Y_ADD) || match(Y_SUB)){
		int oper = tok;
		advance();
		past r = astMulExp();
		if(oper == Y_ADD){
			l = newBinaryOper("+", oper, l, r);
		} else {
			l = newBinaryOper("-", oper, l, r);
		}
	}
	return l;
}

past astMulExp(){
	past l = astUnaryExp();
	while(match(Y_MUL) || match(Y_DIV) || match(Y_MODULO)){
		int oper = tok;
		advance();
		past r = astUnaryExp();
		if(oper == Y_MUL){
			l = newBinaryOper("*", oper, l, r);
		} else if(oper == Y_DIV){
			l = newBinaryOper("/", oper, l, r);
		} else {
			l = newBinaryOper("%",oper, l, r);
		}
	}
	return l;
}

past astUnaryExp(){
	past l = astPrimaryExp();
	if(l != NULL){
		return l;
	} else if(match(Y_ID)){ //执行不到这里，该部分在astPrinmaryExp函数执行
		char* s = malloc(sizeof(char) * (yyleng + 1));
        strcpy(s, yytext);
		advance();
		if(!match(Y_LPAR)){
			return NULL;
		}
		advance();
		if(match(Y_RPAR)){
			advance();
			return newCallExp(NULL,0, s, NULL, NULL);
		} else {
			past l = astCallParams();
			if(!match(Y_RPAR)){
				return NULL;
			}
			advance();
			return newCallExp(NULL, 0, s, l, NULL);
		}
	} else if(match(Y_ADD)){
		advance();
		past l = astUnaryExp();
		return newBinaryOper("+", Y_ADD, NULL, l);
	} else if(match(Y_SUB)){
		advance();
		past l = astUnaryExp();
		return newBinaryOper("-", Y_SUB, NULL, l);
	} else if(match(Y_NOT)){
		advance();
		past l = astUnaryExp();
		return newBinaryOper("!", Y_NOT, NULL, l);
	} else {
		return NULL;
	}
}

past astCallParams(){ 
	callParaNum = 1;
	past l = astExp();
	past t = newParaDecl(NULL, NULL, l, NULL);
	l = t;
	while(match(Y_COMMA)){
		advance();
		callParaNum++;
		past r = astExp();
		l->right = newParaDecl(NULL, NULL, r, NULL);
		l = l->right;
	}
	return t;
}

past astPrimaryExp(){
	if(match(Y_LPAR)){
		advance();
		past n1 = astExp();
		if(!match(Y_RPAR)){
			return NULL;
		}
		return n1;
	} else if(match(Y_ID)){  
		char* s = malloc(sizeof(char) * (yyleng + 1));
        strcpy(s, yytext);
		past l = newDeclRefExp(s, NULL, NULL);
		advance();
		if(match(Y_LPAR)){ //函数调用
			advance();
			if(match(Y_RPAR)){
				advance();
				return newCallExp(NULL,0, s, NULL, NULL);
			} else {
				past l = astCallParams();
				if(!match(Y_RPAR)){
					return NULL;
				}
				advance();
				return newCallExp(NULL, 0, s, l, NULL);
			}
		}
		past n = astArraySubscriptsExp();
		if(n != NULL){
			return newArraySubscriptsExp(l, n);
		} else {
			return l;
		}
	} else if(match(num_INT)){
		past n2 = newIntVal(atoi(yytext));
		advance();
		return n2;
	} else if(match(num_FLOAT)){
		past n3 = newFloatVal(atof(yytext));
		advance();
		return n3;
	} else {
		return NULL;
	}
}

past astArraySubscriptsExp(){
	if(!match(Y_LSQUARE)){
		return NULL;
	}
	advance();
	past l = astExp();
	if(!match(Y_RSQUARE)){
		return NULL;
	}
	advance();
	while(match(Y_LSQUARE)){ //多维数组不太行这里，待修改
		advance();
		past r = astExp();
		if(!match(Y_RSQUARE)){
			return NULL;
		}

		l = newArraySubscriptsExp(l,r);
	}
	return l;
}

int astType(){
	if(match(Y_INT)){
		advance();
		return Y_INT;
	} else if(match(Y_FLOAT)){
		advance();
		return Y_FLOAT;
	} else if(match(Y_VOID)){
		advance();
		return Y_VOID;
	} else {
		return 0;
	}
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

past newVarDecl(char* stype, int type, int if_const, char *name, past left, past right){ //left固定为空，right为下一个变量声明结点
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