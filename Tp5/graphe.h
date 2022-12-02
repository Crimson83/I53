#ifndef GRAPHE_H
#define GRAPHE_H
typedef struct graphe {
  char** mat;
  int nbs;
}graphe;


graphe initgraphe(int);
#endif
