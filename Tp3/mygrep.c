# include <regex.h>
# include <stdio.h>
# include <stdlib.h>

int main(int argc, char* argv[]){
  FILE* fichier=NULL;
  fichier=fopen(argv[2],"r");
  char chaine[100]="";
  regex_t regex ;
  regmatch_t pmatch[2];
  if(fichier!=NULL){
    while(fgets(chaine,100,fichier)){
      int i=0;
      if(regcomp(&regex,argv[1],REG_EXTENDED)!=0)
        return 1;
      if(regexec(&regex,&chaine[i],2,pmatch,0)==0)
        printf("%s",chaine);
      while(regexec(&regex,&chaine[i],2,pmatch,0)==0){
        for(int k=0;k<pmatch[0].rm_eo;k++){
          if((k>=pmatch[0].rm_so)&& k<=(pmatch[0].rm_eo-1)){
            printf("^");
          }
          else
            printf(" ");
          i++;

        }
      }
      printf("\n");
      if(regexec(&regex,&chaine[i],2,pmatch,0)!=0)
        printf ( "motif non trouve !\n" );
      regfree(&regex);
    }
  }
  fclose(fichier);
  return 0;
}
