#include "graphe.h"
#include <stdlib.h>
graphe initgraphe(int n){
  graphe g;
  g.nbs=n;
  int i;
  g.mat=calloc(n,sizeof(char *));
  for(i=0;i<n;i++){
    g.mat[i]=calloc(n,sizeof(char));
  }
  return g;
}
