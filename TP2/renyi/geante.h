#include "../lib/graphe.h"
#ifndef GEANTE_H
#define GEANTE_H
typedef struct paire{
    int sommet;
    int taille;
    struct paire *suivant;
}enrpaire *lpaire;
typedef struct{
  int sommet;
  int taille;
}info;
info* geante(graphe);
int geante(graphe);
void PPR2(int,graphe,int*);
#endif
