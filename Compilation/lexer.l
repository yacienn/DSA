%{
#include <stdio.h>
int nbr_line = 1 ;
%}
lettre [a-zA-Z]
chiffre [0-9]
IDF {lettre}({lettre}|{chiffre})*
CST {chiffre}+
%%
{IDF}       { printf("IDF: %s\n", yytext); }

{CST}       { printf("CST: %s\n", yytext); }

=           { printf("AFF: %s\n", yytext); }

;           { printf("PVG: %s\n", yytext); }

[ \t]+      { /* Ignore spaces and tabs */ }

\n          { nb_ligne++; }

.           {
                printf("Lexical error at line %d: %s\n",
                       nb_ligne, yytext);
            }
%%

int main(void){
    printf("inter the code \n");
    yylex();
    return 0 ;
}