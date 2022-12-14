#include "asa.h"

int pile;
int init_pile=0;
asa * creer_feuilleNb(int val)
{
  asa *p;

  if ((p = malloc(sizeof(asa))) == NULL)
    yyerror("echec allocation mémoire");

  p->type = typeNb;
  p->nb.val = val;
  return p;
}

asa * creer_noeudOp( int ope, asa * p1, asa * p2)
{
  asa * p;

  if ((p = malloc(sizeof(asa))) == NULL)
    yyerror("echec allocation mémoire");

  p->type = typeOp;
  p->op.ope = ope;
  p->op.noeud[0]=p1;
  p->op.noeud[1]=p2;
  p->ninst = p1->ninst+p2->ninst+3;

  return p;
}

asa * creer_noeudUnaire(int ope,asa *p1){
  asa *p;
  if((p=malloc(sizeof(asa)))==NULL)
    yyerror("echec allocation mémoire");
  p->type=typeUnaire;
  p->unaire.ope=ope;
  p->unaire.noeud[0]=p1;
  p->ninst=p1->ninst+3;
  return p;
}

asa * creer_noeudInst(asa *p1,asa *p2){
  asa *p;
  if((p=malloc(sizeof(asa)))==NULL)
    yyerror("echec allocation mémoire");
  p->type=typeInst;
  p->op.noeud[0]=p1;
  p->op.noeud[1]=p2;
  if(p2!=NULL){
    p->ninst=p1->ninst+p2->ninst;
  }
  else{
    p->ninst=p1->ninst;
  }
  return p;
}

void affich_arbre(asa *p){
  if(!p)return;
  if(p->type==typeOp){
    affich_arbre(p->op.noeud[0]);
    affich_arbre(p->op.noeud[1]);
    printf("%c ",p->op.ope);
  }
  if(p->type==typeUnaire){
    affich_arbre(p->op.noeud[0]);
    printf("%c ",p->op.ope);
  }
  if(p->type==typeNb){
    printf("%d ",p->nb.val);
  }
}


void free_asa(asa *p)
{

  if (!p) return;
  switch (p->type) {
  case typeOp:
    free_asa(p->op.noeud[0]);
    free_asa(p->op.noeud[1]);
    break;
  default: break;
  }
  free(p);
}


void codegen(asa *p)
{
  if (!p) return;
  if(init_pile==0){
    pile=1; //+ts_derniere_adr(tsymb);
    init_pile=1;
  }
  switch(p->type) {
  case typeNb:
    printf("LOAD #%d\n",p->nb.val);
    printf("STORE %d\n",pile);
    pile++;
    break;
  case typeOp:
    codegen(p->op.noeud[0]);
    codegen(p->op.noeud[1]);
    switch(p->op.ope){
    case('+'):
      printf("LOAD %d\n",pile-2);
      printf("ADD %d\n",pile-1);
      printf("STORE %d\n",pile-2);
      pile--;
      break;
    case('-'):
      printf("LOAD %d\n",pile-2);
      printf("SUB %d\n",pile-1);
      printf("STORE %d\n",pile-2);
      pile--;
      break;
    case('*'):
      printf("LOAD %d\n",pile-2);
      printf("MUL %d\n",pile-1);
      printf("STORE %d\n",pile-2);
      pile--;
      break;
    case('/'):
      printf("LOAD %d\n",pile-2);
      printf("DIV %d\n",pile-1);
      printf("STORE %d\n",pile-2);
      pile--;
      break;
    case('%'):
      printf("LOAD %d\n",pile-2);
      printf("MOD %d\n",pile-1);
      printf("STORE %d\n",pile-2);
      pile--;
      break;
    case('='):
      printf("STORE %d/n",ts_retrouver_id(tsymb,p->op.noeud[0]->id.Nid));
      break;
    }
    break;
  case typeUnaire:
    codegen(p->unaire.noeud[0]);
    printf("LOAD %d\n",pile-1);
    printf("MUL #-1\n");
    printf("STORE %d\n",pile-1);
    break;
  case typeInst:
    codegen(p->Inst.noeud[0]);
    codegen(p->Inst.noeud[1]);
  default:
    break;
  }
}


void yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  exit(0);
}
