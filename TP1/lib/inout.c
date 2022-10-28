#include <stdlib.h>
#include <stdio.h>
#include "inout.h"
#include "graphe.h"
graphe liregraphe(char *nom){
  graphe res;
  int n,i,j;
  char ligne[1024];
  FILE * source;
  source=fopen(nom,"r");
  if(!source){
    perror("Lire graphe");
    exit(1);
  }
  while(!feof(source)){
    fgets(ligne,1024,source);
    switch (ligne[0]) {
      case 'n':
        if(sscanf(ligne,"nbs=%d",&n)){
          res=initgraphe(n);
        }
        break;
        default:
          if(sscanf(ligne,"%d%d",&i,&j)==2){
            res.mat[i][j]=res.mat[j][i]=1;
          }
    }
  }
  fclose(source);
  return res;
}

void dessiner(char *nom,graphe g){
  FILE* dst;
  int i,j;
  char name[128];
  char cmd[128];
  sprintf(name,"/data/%s.dot",nom);
  dst=fopen(name,"w");
  fprintf(dst,"graphe %s{\n",nom);
  for(i=0;i<g.nbs;i++){
    for(j=i;j<g.nbs;j++){
      if(g.mat[i][j]){
        fprintf(dst,"%d%d;\n",i,j);
      }
    }
  }
  fputs("}",dst);
  fclose(dst);
  sprintf(cmd, "dot -Tpng %s.dot -o %s.png",nom,nom);
  system(cmd);
}
