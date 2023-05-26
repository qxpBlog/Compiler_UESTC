%{
	#include<stdio.h>
	#include<string.h>
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
    //终结符的种别码
	int		token;
    //以下三个都是终结符可能的属性值，int值，float值，string值
	int		int_value;
	float   float_value;
	char*	id_name;
}_YYLVAL;

 _YYLVAL yylval;
// 显示行列信息
// int line=1;
// int column=1;
%}
SPACE         [ \f\r\v\n\t]
line_comment  (\/\/.*\n)|(\/\*.*\*\/)
ID            [a-zA-Z_]+[a-zA-Z0-9_]*
%%
"int"  		{yylval.id_name="int"; return Y_INT;}
 
"void" 		{yylval.id_name="void";return Y_VOID;}
 
"const" 	{yylval.id_name="const";return Y_CONST;}
 
"if" 		{yylval.id_name="if";return Y_IF;}
 
"else" 		{yylval.id_name="else";return Y_ELSE;} 
 
"while" 	{yylval.id_name="while";return Y_WHILE;}
 
"break" 	{yylval.id_name="break";return Y_BREAK;} 

"continue" 	{yylval.id_name="continue";return Y_CONTINUE;}
 
"return" 	{yylval.id_name="return";return Y_RETURN;}
 
"float" 	{yylval.id_name="float";return Y_FLOAT;}
 
[0-9]+ 		{yylval.int_value=atoi(yytext);return num_INT;}

"0xa"		{yylval.int_value=10;return num_INT;}

"0xb"		{yylval.int_value=11;return num_INT;}

"0xc"		{yylval.int_value=12;return num_INT;}

"0xd"		{yylval.int_value=13;return num_INT;}

"0xe"		{yylval.int_value=14;return num_INT;}

"0xf"		{yylval.int_value=15;return num_INT;}
 
[0-9]+"."+[0-9]+ 	{yylval.float_value=atof(yytext);return num_FLOAT;}
 
"+" 		{yylval.id_name="+";return Y_ADD;}
 
"-" 		{yylval.id_name="-";return Y_SUB;}
 
"*" 		{yylval.id_name="*";return Y_MUL;}
 
"/" 		{yylval.id_name="/";return Y_DIV;}
 
"%" 		{yylval.id_name="%";return Y_MODULO;}
 
"<=" 		{yylval.id_name="<=";return Y_LESSEQ;}
 
">"  		{yylval.id_name=">";return Y_GREAT;}
 
"<"  		{yylval.id_name="<";return Y_LESS;}
 
">=" 		{yylval.id_name=">=";return Y_GREATEQ;}

"!=" 		{yylval.id_name="!=";return Y_NOTEQ;}
 
"==" 		{yylval.id_name="==";return Y_EQ;}
 
"!" 		{yylval.id_name="!";return Y_NOT;}

"&&" 		{yylval.id_name="&&";return Y_AND;}
 
"||" 		{yylval.id_name="||";return Y_OR;}
 
"=" 		{yylval.id_name="=";return Y_ASSIGN;}

"(" 		{yylval.id_name="(";return Y_LPAR;}
 
")" 		{yylval.id_name=")";return Y_RPAR;}
 
"{" 		{yylval.id_name="{";return Y_LBRACKET;}

"}" 		{yylval.id_name="}";return Y_RBRACKET;}
 
"[" 		{yylval.id_name="[";return Y_LSQUARE;}
 
"]" 		{yylval.id_name="]";return Y_RSQUARE;}

"," 		{yylval.id_name=",";return Y_COMMA;}
 
";" 		{yylval.id_name=";";return Y_SEMICOLON;}

{ID} 		{yylval.id_name=yytext;return Y_ID;}
 
{line_comment} {/*ignore line_comment*/}

{SPACE} {/*ignore whitespace*/}

%%
main(int argc, char **argv){
	int token_type;

    while(token_type = yylex())
    {
        printf("<%d", token_type);
        if(token_type > 284 && token_type <293)
        {
            printf(", SYMBOL>\n");
        }
        else if(token_type >269&& token_type<285)
        {
            printf(", OPERATOR>\n");
        }
        else if(token_type >260 &&token_type<270 ) 
        {
            printf(", KEYWORD>\n");
        }
        else if(token_type==Y_ID)
        {
            printf(", %s>\n", yylval.id_name);
        }
        else if(token_type==num_INT)
		{
			printf(", %d>\n",yylval.int_value);
		}
		else if(token_type==num_FLOAT)
		{
			printf(", %f>\n",yylval.float_value);
		}
    }
	
}

int yywrap(){
    return 1;
}