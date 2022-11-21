#include <stdio.h>
#include <stdlib.h>

#include "disjoint.h"


int main(int argc, char ** argv){
  int max, m, n, p, i, j;
  sscanf(argv[1], "%d", &max);
  disjoint *table,ri, rj;
  for(n = 1; n < max; n++){
    table = calloc(n, sizeof(disjoint));
    for(int s = 0; s < n; s++){
      table[s] = singleton(s);
    }
    p = n;
    m = 0;
    while(p > 1){
      m++;
      i = rand() % n;
      j = rand() % n;
      ri = representant(table[i]);
      rj = representant(table[j]);
      if(ri != rj){
        reunion(ri,rj);
        p--;
      }
    }
    printf("%d %d\n",n,m);
    free(table);
  }
  return 0;
}
