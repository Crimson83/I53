#include "graphe.h"
#include <stdlib.h>

graphe initgraphe(int n)
{
  graphe res;
  res.nbs=n;
  res.mat=calloc(n,sizeof(char*));
  for(int i=0;i<n;i++)
  {
    res.mat[i]=calloc(n,sizeof(char));
  }
  return res;
}
