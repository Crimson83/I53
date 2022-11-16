%{
  
  #include <stdio.h>
  #include <ctype.h>
  #include <stdlib.h>
  
  int yylval;
  int yylex();
  int yyerror(char *msg);
  
  
%}


%token NB PLUS FIN
%left PLUS

%start PROG

%%

PROG : EXP FIN { printf("%d\n", $1 ); return 1;}
EXP  : NB { $$ = $1 ;} 
| EXP PLUS EXP { $$ = $1 + $3 ;}
;
%%

int main( void ) {
  yyparse() ;
  return 0;
}

int yylex( ){
  int car;
  car = getchar() ;
  if ( car == EOF ) return 0 ;
  if ( isdigit(car) ) {
    yylval = car - '0';
    return NB;
  }
  switch ( car ) {
  case '+' : return PLUS;
  case '\n': return FIN;
  }
  return -1;
}
 
int yyerror(char *msg) {
  printf("\n%s\n", msg);
  return 1;
}

