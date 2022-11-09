#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "analex.h"

int inserer ( char * nom , list_symb * ptr ){
  while(ptr->suiv!=NULL && strcpy(ptr->symb,nom){
    ptr=ptr->suiv;
  }
  if(ptr->suiv==NULL){
    list_symb tmp;
    tmp->symb=nom;
    tmp->count=1;
    ptr->suiv=tmp;
    return 0;
  }
  ptr->count++;
  return 1;
}
void print_list ( list_symb * ptr ){
  while(ptr->suiv!=NULL){
    printf("%s apparait %d fois\n",ptr->symb,ptr->count);
    ptr=ptr->suiv;
  }
}
