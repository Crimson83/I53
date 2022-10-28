#include "graphe.h"
#include <stdlib.h>
#include <stdio.h>
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
