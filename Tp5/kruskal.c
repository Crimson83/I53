#include "kruskal.h"
#include <math.h>
#include <stdlib.h>
#include "disjoint.h"
#include <time.h>

static int compare(const void * p1, const void * p2)
{
  float x,y;
  x=((arete*)p1)->w;
  y=((arete*)p2)->w;
  if(x<y)return -1;
  if(y<x)return 1;
  return 0;
}

float dist(point i,point j)
{
  float distx,disty,distp;
  distx=i.x-j.x;
  disty=i.y-j.y;
  distp=distx*distx+disty*disty;
  distp=sqrt(distp);
  return distp;
}

point *nuage(int n)
{
  point* res;
  srand( time( NULL ) );
  res=calloc(n,sizeof(point));
  int i;
  for(i=0;i<n;i++)
  {
    float r=rand();
    r=(r-RAND_MAX/2)/RAND_MAX*2;
    res[i].x=r;
    r=rand();
    r=(r-RAND_MAX/2)/RAND_MAX*2;
    res[i].y=r;
  }
  return res;
}

graphe kruskal(point *pts, int n)
{
  graphe res=initgraphe(n);
  int m=n*(n-1)/2;
  arete *a=calloc(m,sizeof(arete));
  int i,j,k;
  k=0;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      a[k].i=i;
      a[k].j=j;
      a[k].w=dist(pts[i],pts[j]);
      k++;
    }
  }
  qsort(a,m,sizeof(arete),compare);
  disjoint *table=calloc(n,sizeof(disjoint));
  for(i=0;i<n;i++)
    table[i]=singleton(i);
  k=0;
  int p=n;
  while(p>1)
  {
    i=a[k].i;
    j=a[k].j;
    disjoint ri = representant(table[i]);
    disjoint rj = representant(table[j]);
    if(ri != rj){
      reunion(ri,rj);
      p--;
      res.mat[i][j]=1;
      res.mat[j][i]=1;
    }
    k++;
  }
  free(a);
  free(table);
  return res;
}

void parcours(int s,int *ptr,graphe *g,int *visite){
  (*g).clr[*ptr]=s;
  *ptr=*ptr+1;
  for(int i=0;i<(*g).nbs;i++){
    if(!visite[i]&&(*g).mat[s][i]){
      visite[i]=1;
      parcours(i,ptr,g,visite);
      visite[i]=0;
    }
  }
}
