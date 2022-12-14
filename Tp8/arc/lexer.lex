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

"VAR"         { return VAR;}
"DEBUT"       { return DEBUT; }
"FIN"         { return FIN; }
";"           { return yytext[0]; }
"AFFICHER"    { return AFFI; }
{IDE}         { strcpy(yylval.id, yytext); return ID; }
"<-"          { return AFF; }
{NOMBRE}      { yylval.nb = atoi(yytext); return NB; }
{OPE}         { return yytext[0]; }
{PA}          { return yytext[0]; }
{BLANC}       { }

.          { fprintf(stderr, "[err lexer] caractere inconnu %c\n",yytext[0]); return 1;}

%%
