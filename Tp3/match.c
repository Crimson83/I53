# include <regex.h>
# include <stdio.h>
# include <stdlib.h>

int main ( int argc , char * argv[])
{
  regex_t regex ;
  regmatch_t pmatch[2];
  if ( regcomp (&regex, argv[1], REG_EXTENDED )!=0)
    return 1;
  if ( regexec (&regex, argv[2] ,2, pmatch, 0)==0){
    printf("motif trouve\n");
    for(int i=0;i<2;i++){
      printf("%d,%d\n",pmatch[i].rm_so,pmatch[i].rm_eo-1);
    }
  }else
    printf ( "motif non trouve !\n" );
  regfree(&regex);
  return 0;
}
