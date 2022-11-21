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

void reunion(disjoint u, disjoint v){
  disjoint ru, rv;
  ru = representant(u);
  rv = representant(v);
  if(ru -> rang > rv -> rang) rv -> route = ru;
  else{
    if(ru -> rang == rv -> rang){
      rv -> route = ru;
      ru -> rang++;
    }
    else ru -> route = rv;
  }
}
