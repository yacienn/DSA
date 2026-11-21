
%{
#include <stdio.h>

int yylex(void);
void yyerror(const char *s);

extern int nb_ligne;
%}

%token LOCKED IDF CST EQUAL PVG

%%

program:
      declaration
    ;
declaration:
      LOCKED IDF EQUAL CST PVG
      {
          printf("Declaration correct!\n");
      }
    ;

%%

void yyerror(const char *s)
{
    printf("Syntax error at line %d: %s\n", nb_ligne, s);
}

int main(void)
{
    printf("Enter your code:\n");
    yyparse();
    yywrap();
    return 0;
}
