%{

  #include <stdio.h>
  #include <ctype.h>
  #include <stdlib.h>
  #include <string.h>

  extern int yylex();
  int yyerror(const char *msg);
  int pile=1;
  ts table=NULL;
%}

%token DEBUT FIN AFFECT
%token <nb> NB
%token <id> ID
%left '+' '-'
%left '*' '/'
%left AFFECT
%start PROG

%union{
  int nb;
  char id[32];
 }

%%

PROG : DEBUT INSTS FIN {ts_free_table(table);}
INSTS : INSTS INST
|INST
ISNT:EXP ';'
EXP : ID {if (table==NULL){
              table=ts_init_table($1);}}
| ID AFFECT EXP {}  {ts_ajouter_id(table,$1);printf("LOAD %d\nWRITE\nSTOP\n",pile-1);}
| EXP '+' EXP {printf("LOAD %d\nADD %d\nSTORE %d\n",pile-2,pile-1,pile-2);pile--;}
| EXP '-' EXP {printf("LOAD %d\nSUB %d\nSTORE %d\n",pile-2,pile-1,pile-2);pile--;}
| EXP '*' EXP {printf("LOAD %d\nMUL %d\nSTORE %d\n",pile-2,pile-1,pile-2);pile--;}
| EXP '/' EXP {printf("LOAD %d\nDIV %d\nSTORE %d\n",pile-2,pile-1,pile-2);pile--;}
| '-' EXP {printf("LOAD #%d\nMUL #-1\nSTORE %d\n",pile-1,pile-1);}
| '(' EXP ')'
| NB {printf("LOAD #%d\nSTORE %d\n",$1,pile);pile++;}
;
{ts_free_table(table);}
%%

int main( int argc, char * argv[] ) {

  extern FILE * yyin;
  if (argc < 2){
    printf("usage: %s <file_name>\n",argv[0]);
    return 1;
  } else {

    if ( (yyin= fopen(argv[1],"r"))== NULL ){
      printf("Could not open file %s\n",argv[1]);
      return 1;
    }
  }
  yyparse() ;
  fclose(yyin);
  return 0;
}

int yyerror(const char *msg){
  fprintf(stderr,"%s\n",msg);
  return -1;
}
