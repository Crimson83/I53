%{
  #include <stdio.h>
  #include <ctype.h>
  #include <unistd.h>

  #include "asa.h"
  #include "ts.h"

  extern int yylex();

%}

%union{
  int nb;
  char id[32];
  struct asa * noeud;
 };

%define parse.error verbose

%token <nb> NB
%token <id> ID
%token DEBUT FIN

%type <noeud> EXP INSTS INST

%left '+' '-'
%left '/' '*' '%'

%start PROG

%%

PROG : DEBUT INSTS FIN      {affich_arbre($2);printf("\n");}
;

INSTS : INSTS INST
|INST
;

INST:EXP ';'
;

EXP : NB                   { $$ = creer_feuilleNb(yylval.nb); }
| EXP '+' EXP              { $$ = creer_noeudOp('+', $1, $3); }
| EXP '-' EXP              { $$ = creer_noeudOp('-', $1, $3); }
| EXP '*' EXP              { $$ = creer_noeudOp('*', $1, $3); }
| EXP '/' EXP              { $$ = creer_noeudOp('/', $1, $3); }
| EXP '%' EXP              { $$ = creer_noeudOp('%', $1, $3); }
| '(' EXP ')'              { $$ = $2;}
| '-' EXP                  { $$ = creer_noeudUnaire('-',$2);}
;

%%

int main( int argc, char * argv[] ) {

  extern FILE *yyin;
  if (argc == 1){
    fprintf(stderr, "aucun fichier fournie\n");
    return 1;
  }
  yyin = fopen(argv[1],"r");
  yyparse();
  return 0;
}
