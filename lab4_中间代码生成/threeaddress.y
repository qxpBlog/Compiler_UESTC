%{

#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);
extern int type;
extern past astRoot; //链表头结点（空结点），指向链表总结点，next为链表的第一个结点

%}

%union {
     int		token;
	int		int_value;
	float     float_value;
	char*	id_name;
	past		pAst;
};


%token <int_value> num_INT Y_INT Y_VOID  Y_CONST Y_IF Y_ELSE Y_WHILE Y_BREAK Y_CONTINUE Y_FLOAT Y_RETURN
%token <int_value> Y_ADD Y_COMMA Y_DIV  Y_LPAR Y_SUB Y_LSQUARE Y_MODULO Y_MUL Y_NOT Y_RPAR Y_RSQUARE Y_RBRACKET
%token <int_value> Y_LESS Y_LESSEQ Y_GREAT Y_GREATEQ Y_NOTEQ Y_EQ Y_AND Y_OR Y_ASSIGN Y_LBRACKET Y_SEMICOLON
%token <float_value> num_FLOAT
%token <id_name> Y_ID 
%type  <pAst>	program Exp AddExp MulExp UnaryExp CallParams PrimaryExp LVal ArraySubscripts
%type  <pAst>	RelExp EqExp LAndExp LOrExp Stmt Block BlockItem BlockItems


%%
program: Stmt {$$ = newList(NULL, $1); astRoot = $$;}
       | program Stmt {$$ = newList($1, $2);}
       ;

Stmt: LVal Y_ASSIGN Exp Y_SEMICOLON {$$ = newBinaryOper("=", Y_ASSIGN, $1, $3);}
     | Y_SEMICOLON {$$ = NULL;}
     | Exp Y_SEMICOLON {$$ = $1;}
     | Block 
     | Y_WHILE Y_LPAR LOrExp Y_RPAR Stmt {$$ = newWhileStmt($3, newCompoundStmt(NULL,$5));}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt {$$ = newIfStmt($3, newCompoundStmt(NULL,$5), NULL);}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Stmt {$$ = newIfStmt($3, newCompoundStmt(NULL,$5), newCompoundStmt(NULL,$7));}
     | Y_BREAK Y_SEMICOLON {$$ = newBreakStmt();}
     | Y_CONTINUE Y_SEMICOLON {$$ = newContinueStmt();}
     | Y_RETURN Exp Y_SEMICOLON {$$ = newReturnStmt($2, NULL);}
     | Y_RETURN Y_SEMICOLON {$$ = newReturnStmt(NULL, NULL);}
     ;

Block: Y_LBRACKET BlockItems Y_RBRACKET {$$ = $2;}
      | Y_LBRACKET Y_RBRACKET {$$ = NULL;}
      ;

BlockItems: BlockItem {$$ = newCompoundStmt($1, NULL);}
           | BlockItem BlockItems {past l = newCompoundStmt($1, NULL); l->right = $2; $$ = l;}
           ;

BlockItem: Stmt 
          ;

RelExp: AddExp
       | AddExp Y_LESS RelExp {$$ = newBinaryOper("<", Y_LESS, $1, $3);}
       | AddExp Y_GREAT RelExp {$$ = newBinaryOper(">", Y_GREAT, $1, $3);}
       | AddExp Y_LESSEQ RelExp {$$ = newBinaryOper("<=", Y_LESSEQ, $1, $3);}
       | AddExp Y_GREATEQ RelExp {$$ = newBinaryOper("<=", Y_GREATEQ, $1, $3);}
       ;

EqExp: RelExp
      | RelExp Y_EQ EqExp {$$ = newBinaryOper("==", Y_EQ, $1, $3);}
      | RelExp Y_NOTEQ EqExp {$$ = newBinaryOper("!=", Y_NOTEQ, $1, $3);}
      ;

LAndExp: EqExp 
        | EqExp Y_AND LAndExp {$$ = newBinaryOper("&&", Y_AND, $1, $3);}
        ;

LOrExp: LAndExp
       | LAndExp Y_OR LOrExp {$$ = newBinaryOper("||", Y_OR, $1, $3);}
       ;

Exp: AddExp  
     ;

AddExp: MulExp
     | AddExp Y_ADD MulExp {$$ = newBinaryOper("+", Y_ADD, $1, $3);}
     | AddExp Y_SUB MulExp {$$ = newBinaryOper("-", Y_SUB, $1, $3);}
     ;

MulExp: UnaryExp
     | MulExp Y_MUL UnaryExp {$$ = newBinaryOper("*", Y_MUL, $1, $3);}
     | MulExp Y_DIV UnaryExp {$$ = newBinaryOper("/", Y_DIV, $1, $3);}
     | MulExp Y_MODULO UnaryExp {$$ = newBinaryOper("%", Y_MODULO, $1, $3);}
     ;

UnaryExp: PrimaryExp
     | Y_ID Y_LPAR Y_RPAR {$$ = newCallExp(NULL, 0, $1, NULL, NULL);}
     | Y_ID Y_LPAR CallParams Y_RPAR {$$ = newCallExp(NULL, 0, $1, $3, NULL);}
     | Y_ADD UnaryExp {$$ = newBinaryOper("+", Y_ADD, NULL, $2);}
     | Y_SUB UnaryExp {$$ = newBinaryOper("-", Y_SUB, NULL, $2);}
     | Y_NOT UnaryExp {$$ = newBinaryOper("!", Y_NOT, NULL, $2);}
     ;

CallParams: Exp
     | Exp Y_COMMA CallParams {$$ = newBinaryOper("-", Y_SUB, $1, $3);}
     ;

PrimaryExp: Y_LPAR Exp Y_RPAR {$$ = $2;}
     | LVal 
     | num_INT {$$ = newIntVal($1);}
     | num_FLOAT {$$ = newFloatVal($1);}
     ;

LVal: Y_ID {$$ = newDeclRefExp($1, NULL, NULL);}
    | Y_ID ArraySubscripts {$$ = newDeclRefExp($1, NULL, NULL);}
    ;

ArraySubscripts: Y_LSQUARE Exp Y_RSQUARE {$$ = $2}
               | Y_LSQUARE Exp Y_RSQUARE ArraySubscripts {$$ = newArraySubscriptsExp($2, $4);}
               ;

%%
