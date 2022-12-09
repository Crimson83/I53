#include "clique.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
  int n=atoi(argv[1]);
  printf("%d\n",n);
  int *t;
  for(int i=0;i<n;i++){
    t=calloc(i+1,sizeof(int));
    soluce=0;
    partition(1,i,t);
    free(t);
    printf("s=%d,soluce=%d\n",i,soluce);
  }
  return 0;
}
