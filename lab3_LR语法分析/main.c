#include<stdio.h>

void yyerror(char *s)
{
	printf("%s\n", s);
}

int main(void)
{
    yyparse();
    return 0;
}
