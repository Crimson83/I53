#include "graphe.h"
#include "point.h"
#include <stdlib.h>

point* nuage(int n){
  point *res;
  int i;
  int p=n;
  float r;
  res=calloc(n,sizeof(point));
  for(i=0;i<n;i++){
    r=rand();
    r=(r-RAND_MAX/2)/RAND_MAX*2;
    res[i].x=r;
    r=rand();
    r=(r-RAND_MAX/2)/RAND_MAX*2;
    res[i].y=r;
  }
  return res;
}

static int compare(const void *p1,const void *p2){
  float x,y;
  x=((arete*)p1)->w;
  y=((arete*)p1)->w;
  if(x<y)return +1;
  if(x>y)return -1;
  return 0;
}
