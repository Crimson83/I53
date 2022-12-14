%{
  #include <stdio.h>
  #include <ctype.h>
  #include <unistd.h>

  #include "asa.h"
  #include "ts.h"

  extern int yylex();
  ts *tsymb=NULL;

%}

%union{
  int nb;
  char id[32];
  struct asa * noeud;
 };

%define parse.error verbose

%token <nb> NB
%token <id> ID
%token DEBUT FIN AFFI VAR AFF

%type <noeud> EXP INSTS INST

%left AFF
%left '+' '-'
%left '/' '*' '%'

%start PROG

%%

PROG : DEBUT INSTS FIN      {codegen($2);printf("\n");}
;

INSTS : INSTS INST         { $$ = creer_noeudInst($1,$2);}
|INST                      { $$ = $1;}
;

INST:EXP ';'               { $$ = creer_noeudInst($1,NULL);}
|VAR ID ';'                {if(tsymb == NULL) tsymb = ts_init_table($2); //si la liste chainee est vide, on l'initialise 
                            $$ = ts_ajouter_id(tsymb, $2);}
;

EXP : NB                   { $$ = creer_feuilleNb(yylval.nb); }
| EXP '+' EXP              { $$ = creer_noeudOp('+', $1, $3); }
| EXP '-' EXP              { $$ = creer_noeudOp('-', $1, $3); }
| EXP '*' EXP              { $$ = creer_noeudOp('*', $1, $3); }
| EXP '/' EXP              { $$ = creer_noeudOp('/', $1, $3); }
| EXP '%' EXP              { $$ = creer_noeudOp('%', $1, $3); }
| '(' EXP ')'              { $$ = $2;}
| '-' EXP                  { $$ = creer_noeudUnaire('-',$2);}
| ID AFF EXP               {if(!ts_retrouver_id(tsymb,$1)){fprintf(stderr,"la variable n'as pas été déclarée");exit(1);}
                            $$=creer_noeudOp('=',$1,$3);//Sauvegarde de la valeur contenue dasn l'ACC vers la case pointee par ID}
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
