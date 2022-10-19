# include <regex.h>
# include <stdio.h>
# include <stdlib.h>
int main ( int argc , char * argv[])
{
  regex_t regex ;
  if ( regcomp (&regex, argv[1], REG_EXTENDED )!=0)
    return 1;
  if ( regexec (&regex, argv[2], 0, NULL, 0)==0)
    printf ( "motif trouve !\n" );
  else
    printf ( "motif non trouve !\n" );
  regfree(&regex);
  return 0;
}
