#include "geante.h"
#include <stdlib.h>
#include <stdio.h>
int geante(graphe g){
  int maxc=1,s,cpt=0;
  paire res=NULL;
  g.clr=calloc(g.nbs,sizeof(unsigned char));
  for(s=0;s<g.nbs-maxc;s++){
    if(res.taille==0){
    cpt=0
    PPR2(s,g,&cpt);
    if(*cpt>maxc)
      maxc=cpt;
    free(g.clr);
    }
  return maxc;
  }
}
int PPR2(int s,graphe g,int *cpt){
  g.clr[s]=1;
  *cpt=*cpt+1;
  for(int t=0;t<g.nbs;t++){
    if(g.mat[s][t]&&g.clr[r]==0)
      PPR2(s,g,cpt);
  }
}
info* geante(graphe g){
  info *res;
  int p=0;
  res=calloc(g.nbs+1,sizeof(info));
  res[p].sommet=s;
  res[p].taille=taille;
  p++;
}
