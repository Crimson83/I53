%{
  /*Prologue*/
  #include <stdio.h>
  #include <string.h>
  int longmax = 0;
  char motlepluslong[256];
  int ligne=1,lignemax;
  int column=1,columnmax;
  int cpt=0;
%}
%option nounput
%option noinput
/*Définitions*/
BLANC    [ \t]
SAUT     [\n]
LETTRE   [a-zA-Z]
MOT      {LETTRE}+
CHIFFRE  [0-9]
NOMBRE   {CHIFFRE}+

%%
{MOT} {column++;} { if (yyleng > longmax){
    longmax = yyleng;
    lignemax=ligne;
    columnmax=column;
    strcpy(motlepluslong, yytext);
    printf("\n%s",yytext);
  } column=column+yyleng-1;
}

{NOMBRE} {
  cpt=cpt+atoi(yytext);
  column=column+yyleng;}
{SAUT} {ligne++;column=0;}
. {column++;}

%%
int main(int argc,char** argv) {
  if(argc>0){
    yyin=fopen(argv[1],"r");
  }
  yylex();
  printf("\nMot le plus long: %s, de longueur: %d, à la ligne %d, et à la colonne %d, Somme des nombre = %d\n", motlepluslong, longmax, lignemax, columnmax, cpt);
  return 0;
}
