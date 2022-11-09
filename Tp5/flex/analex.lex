%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}
%option nounput
%option noinput
LETTRE [a-zA-Z]
MOT {LETTRE}+
BLANC [\t\n]

%%
{MOT {if}}
