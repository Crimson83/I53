%{
#include <string.h>
#include "parser.h"
%}

%option nounput
%option noinput

NOMBRE   [1-9][0-9]*
OPE      [+\-*/]
PA       [()]
IDE      [a-z][0-9a-z]*
BLANC    [ \t\n]

%%

{BLANC}    {}
"DEBUT"    { return DEBUT;}
"FIN"      { return FIN;}
";"        { return yytext[0];}
{OPE}      { return yytext[0];}
{NOMBRE}   { yylval.nb = atoi(yytext); return NB;}
{PA}       { return yytext[0];}
.          { fprintf(stderr, "[err lexer] caractere inconnu %c\n",yytext[0]); return 1;}

%%
