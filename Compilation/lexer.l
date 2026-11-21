
%{
#include <stdio.h>
#include "parser.tab.h"

int nb_ligne = 1;
%}

lettre [a-zA-Z]
chiffre [0-9]

locked (int|float|string)

IDF {lettre}({lettre}|{chiffre})*
CST {chiffre}+
LOCKED {locked}
EQUAL =

%%

{LOCKED}    { return LOCKED; }

{IDF}       { return IDF; }

{CST}       { return CST; }

{EQUAL}     { return EQUAL; }

;           { return PVG; }

[ \t]+      { /* Ignore spaces and tabs */ }

\n          { nb_ligne++; }

.           {
                printf("Lexical error at line %d: %s\n",
                       nb_ligne, yytext);
            }

%% 
