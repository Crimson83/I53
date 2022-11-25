#include "graphe.h"
#include "kruskal.h"
#include "point.h"
#include "disjoint.h"
#include <math.h>
int dist(point p1,point p2){
  float dx,dy;
  flaot distance=0;
  dx=p1.x-p2.x;
  dy=p1.y-p2.y;
  distance=sqrt(dx*dx+dy*dy);
  return distance;
}
graphe kruskal(point * pts ,int n){
  graphe res=initgraphe(n);
  int m=n*(n-1)/2;
  arete *a=calloc(m,sizeof(arete));
  int i,s,k=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      a[k].i=i;
      a[k].j=j;
      a[k].w=dist(pts[i],pts[j]);
      k++;
    }
  }
  qsort(a,m,sizeof(arete),compare);
  disjoint *table=calloc(n,sizeof(disjoint));
  for(i=0;i<n;i++){
    table[i]=singleton(i);
  }
  disjoint ri;
  disjoint rj;

  free(a);
  return res;
}
