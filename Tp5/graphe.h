#ifndef GRAPHE_H
#define GRAPHE_H
typedef struct graphe {
  char** mat;
  int nbs;
  int * clr;
}graphe;


graphe initgraphe(int);
#endif
