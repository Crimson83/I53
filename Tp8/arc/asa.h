#ifndef ASA_H
#define ASA_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ts.h"

typedef enum {typeNb, typeOp, typeUnaire, typeInst, feuilleid} typeNoeud;

typedef struct {
  int val;
} feuilleNb;

typedef struct {
  int ope;
  struct asa * noeud[2];
} noeudOp;

typedef struct {
  int ope;
  struct asa * noeud[1];
} noeudUnaire;

typedef struct{
  char Nid[32];
}feuilleid
typedef struct {
  struct asa * noeud[2];
} noeudInst;

typedef struct asa{
  typeNoeud type;
  int ninst;

  union {
    feuilleNb nb;
    noeudOp op;
    noeudUnaire unaire;
    noeudInst Inst;
    feuilleid id;
  };
} asa;

// fonction d'erreur utilisée également par Bison
void yyerror(const char * s);

/*
  Les fonctions creer_<type> construise un noeud de l'arbre
  abstrait du type correspondant et renvoie un pointeur celui-ci
 */
asa * creer_feuilleNb( int value );
asa * creer_noeudOp( int ope, asa * p1, asa * p2 );
asa * creer_noeudUnaire(int ope,asa *p1); //fonction pour noeud - unaire
asa * creer_noeudInst(asa *p1,asa *p2);
void affich_arbre(asa *p);
void free_asa(asa *p);

// produit du code pour la machine RAM à partir de l'arbre abstrait
// ET de la table de symbole
void codegen(asa *p);

extern ts * tsymb;

#endif
