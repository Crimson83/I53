#include "kruskal.h"
#include "graphe.h"
#include "point.h"
void dessinerarbre(point *pts,int n){
  FILE *fichier;
  char nom[128]="arbre.dot";
  char cmd[1024];
  fichier=fopen("arbre.dot","w");
  if(fichier==NULL){
    perror("erreur fonction DessinerGraphe");
    exit(1);
  }
  fprintf(fichier,"arbre{\n");
  //fprintf(fichier,"node [shape = circle]");
  for(int i=0;i<n;i++){
    fprintf(fichier,"%d [pos = \"%f,%f!\"]");
  }
  fputc('}',fichier);
  fclose(fichier);
  sprintf(cmd,"dot -Kfdp -n -Tpng %s -o arbre.png",nom);
  system(cmd);
}
void dessinernuage(point *pts,int n){
  FILE *fichier;
  char nom[128]="nuage.dot";
  char cmd[1024];
  fichier=fopen("nuage.dot","w");
  if(fichier==NULL){
    perror("erreur fonction DessinerGraphe");
    exit(1);
  }
  fprintf(fichier,"graphe nuage{\n");
  fprintf(fichier,"node [shape = circle]");
  for(int i=0;i<n;i++){
    fprintf(fichier,"%d [pos = \"%f,%f!\"]",i,pts[i].x,pts[i].y);
  }
  fputc('}',fichier);
  fclose(fichier);
  sprintf(cmd,"dot -Kfdp -n -Tpng %s -o arbre.png",nom);
  system(cmd);
}

int main(int argc,char **argv){
  point *pts=nuage(10);
  dessinernuage(pts,10);
  graphe g=kruskal(pts,10);

}
