
%{
#include <stdio.h>
int nb_ligne = 1;
#include "parser.tab.h"
%}

lettre [a-zA-Z]
chiffre [0-9]

locked (int|float|string)

IDF {lettre}({lettre}|{chiffre})*
CST {chiffre}+
LOCKED {locked}
EQUAL =

%%

{LOCKED}    { printf("LOCKED: %s\n", yytext); }

{IDF}       { printf("IDF: %s\n", yytext); }

{CST}       { printf("CST: %s\n", yytext); }

{EQUAL}     { printf("EQUAL: %s\n", yytext); }

;           { printf("PVG: %s\n", yytext); }

[ \t]+      { /* Ignore spaces and tabs */ }

\n          { nb_ligne++; }

.           {
                printf("Lexical error at line %d: %s\n",
                       nb_ligne, yytext);
            }

%%

int main(void)
{
    printf("Enter the code:\n");
    yylex();
    return 0;
}
