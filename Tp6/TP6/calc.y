%{

  #include <stdio.h>
  #include <ctype.h>
  #include <stdlib.h>

  int yylval;
  int yylex();
  int yyerror(char *msg);
  int myexp(int x,int n);
  int mem[26];

%}


%token NB PLUS FIN MULT DIV SOUS POW OPA FPA AFF MEM QUIT
%left AFF
%left PLUS SOUS
%left MULT DIV
%left POW
%start PROG

%%

PROG : %empty
| PROG EXP FIN { printf("%d\n", $2 );}
EXP  : NB { $$ = $1 ;}
| QUIT {return 1;}
| MEM {$$=mem[$1-'A'];}
| EXP PLUS EXP { $$ = $1 + $3 ;}
| EXP SOUS EXP { $$ = $1 - $3 ;}
| EXP MULT EXP { $$ = $1 * $3 ;}
| EXP DIV EXP { $$ = $1 / $3 ;}
| EXP POW EXP { $$ = myexp($1,$3);}
| OPA EXP FPA { $$ = $2;}
| MEM AFF EXP {$$=mem[$1-'A']=$3;}
%%

int main( void ) {
  yyparse() ;
  return 0;
}
int yylex( ){
  int car;
  car = getchar() ;
  if ( car == EOF ) return 0 ;
  while(car==' '||car=='\t')car=getchar();
  if ( isdigit(car) ) {
    yylval = car - '0';
    char c;
    while(isdigit(c=getchar())){
      yylval*=10;
      yylval+=c-'0';
    }
    ungetc(c,stdin);
    return NB;
  }
  switch ( car ) {
  case '+' : return PLUS;
  case '-' : return SOUS;
  case '*' : {
    char c=getchar();
    if(c!='*'){
      ungetc(c,stdin);
      return MULT;
    }
    else
      return POW;
  }
  case '/' : return DIV;
  case '\n': return FIN;
  case '(' : return OPA;
  case ')' : return FPA;
  case '=' : return AFF;
  case 'q' : return QUIT;
  default :{
    yylval=car;
    return MEM;
  }
  return -1;
  }
}
int myexp(int x,int n){
  int rep=1;
  for(int i=0;i<n;i++){
    rep=rep*x;
  }
  return rep;
}
int yyerror(char *msg) {
  printf("\n%s\n", msg);
  return 1;
}
