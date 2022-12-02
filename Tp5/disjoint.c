#include <stdlib.h>

#include "disjoint.h"

disjoint singleton(int s){
  disjoint res = malloc(sizeof(enrdisjoint));
  res -> s = s;
  res -> route = res;
  res -> rang = 0;
  return res;
}

disjoint representant(disjoint s){
  if(s == s->route) return s;
  return s -> route = representant(s->route);
}

void reunion(disjoint ru, disjoint rv){
  if(ru -> rang == rv -> rang){
    ru -> rang++;
  }
  if(ru->rang < rv->rang){
    rv->route=ru;
  }
  else ru->route=rv;
}
