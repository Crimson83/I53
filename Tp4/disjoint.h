#ifndef STRUCT_
#define STRUCT_

typedef struct ed{
  struct ed* route;
  int s;
  int rang;
}enrdisjoint,*disjoint;

disjoint singleton(int s);
disjoint representant(disjoint s);
void reunion(disjoint u, disjoint v);//cette fonction n'est appliquée qu'a des representants

#endif
