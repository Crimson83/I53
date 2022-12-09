#include "clique.h"

void partition(int p,int s,int *t){
  int i,q;
  if(!s){soluce++;return;}
  if(s<p)return;
  q=s/p;
  for(i=0;i<=q;i++){
    t[p]=i;
    partition(p+1,s-i*p,t);
  }
  t[p]=0;
}
