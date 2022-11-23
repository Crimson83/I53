%{
  /*Prologue*/
  #include <stdio.h>
  #include <string.h>
  #include "parser.h"

%}
%option nounput
%option noinput

NOMBRE   [1-9][0-9]*
LETTRES  [A-Za-z]
OP       [+\*\-+/]
BLANC    [ \t\n]
PAR      [(,)]
PTV      [;]
IDEN     {LETTRES}

%%

"DEBUT"       { return DEBUT; }
"FIN"         { return FIN; }
"<-"          { return AFFECT;}
{NOMBRE}      { yylval.nb = atoi(yytext); return NB;}
{BLANC}       { }
{OP}          {return yytext[0];}
{PAR}         {return yytext[0];}
{PTV}         {return yytext[0];}
{IDEN}        {return }
.             { printf("lexer error: caractère inconnu"); exit(1);}

%%
