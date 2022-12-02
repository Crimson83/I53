#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "graphe.h"

typedef struct point{
  float x;
  float y;
}point;

typedef struct arete{
  int i;
  int j;
  float w;
}arete;

float dist(point p1,point p2);
point *nuage(int n);
graphe kruskal(point *pts,int n);



#endif
