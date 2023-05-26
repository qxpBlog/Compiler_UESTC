%{

// token definition
#ifndef COMPILER_LAB_TOKEN_H
#define COMPILER_LAB_TOKEN_H
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

typedef union _YYLVAL{
	int		token;
	int		int_value;
	float   float_value;
	char*	id_name;
}_YYLVAL;

_YYLVAL yylval;
#endif //COMPILER_LAB_TOKEN_H

%}

/* Regular definition */ 
DELIM          [\t \n]
WS               {DELIM}+
DIGIT            [0-9]
LETTER 	     [A-Za-z]	
     
%%

(\/\/.*\n)|(\/\*.*\*\/)											{/* noaction */}
{WS}   												{/* noaction */}
{DIGIT}+	     											{yylval.int_value = atoi(yytext); return num_INT;}
{DIGIT}+"."{DIGIT}+											{yylval.float_value = (float)atof(yytext); return num_FLOAT;}
int												{return Y_INT;}
float												{return Y_FLOAT;}
void												{return Y_VOID;}
const												{return Y_CONST;}
if												{return Y_IF;}
else												{return Y_ELSE;}
while												{return Y_WHILE;}
break												{return Y_BREAK;}
continue												{return Y_CONTINUE;}
return												{return Y_RETURN;}
("_"|{LETTER})({DIGIT}|"_"|{LETTER})*									{return Y_ID;}
"+"												{return Y_ADD;}
"-"												{return Y_SUB;}
"*"												{return Y_MUL;}
"/"												{return Y_DIV;}
"%"												{return Y_MODULO;}
"<"												{return Y_LESS;}
"<="												{return Y_LESSEQ;}
">"												{return Y_GREAT;}
">="												{return Y_GREATEQ;}
"!="												{return Y_NOTEQ;}
"=="												{return Y_EQ;}
"!"												{return Y_NOT;}
"&&"												{return Y_AND;}
"||"												{return Y_OR;}
"="												{return Y_ASSIGN;}
"("												{return Y_LPAR;}
")"												{return Y_RPAR;}
"["												{return Y_LSQUARE;}
"]"												{return Y_RSQUARE;}
"{"												{return Y_LBRACKET;}
"}"												{return Y_RBRACKET;}
","												{return Y_COMMA;}
";"												{return Y_SEMICOLON;}


%%

//auxiliary function

int main() {
	int tok;
	while(tok = yylex()){
		if (tok == num_INT){
			printf("<%d, %d> \n", tok, yylval.int_value);
		} else if (tok == num_FLOAT){
			printf("<%d, %f> \n", tok, yylval.float_value);
		} else if (tok == Y_ID){
			printf("<%d, %s> \n", tok, yytext);
		} else if ((tok >= 261 && tok <= 269) || tok == 293){
			printf("<%d, KEYWORD> \n", tok);
		} else if(tok >= 270 && tok <= 284){
			printf("<%d, OPERATOR> \n", tok);
		} else{
			printf("<%d, SYMBOL> \n", tok);
		}
	}
	
	return 1;
} 


int yywrap() {
	return 1;
}
