#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "kruskal.h"


void DessinerACM(point *pts, int n,graphe g){
	FILE *dst;
	char name[128] = "ACM.dot";
	char cmd[1028];
	dst = fopen("ACM.dot", "w");
	if (dst == NULL ) {
		perror("erreur fonction DessinerACM");
		exit(1);

	}
	fprintf(dst, "graph nuage {\n" );
	fprintf(dst, "node [shape=circle]\n");
	for (int i = 0; i < n; ++i) {
    fprintf(dst,"%d [pos = \"%f,%f!\" ];\n",i,pts[i].x,pts[i].y);
	}
  for (int i = 0; i < g.nbs; ++i) {
    for (int j = i+1; j < g.nbs; j++) {
      if (g.mat[i][j]) {
        fprintf(dst,"%d -- %d\n", i, j);
      }
    }
  }
	fputc('}',dst);
	fclose(dst);
	sprintf(cmd, "dot -Kfdp -n -Tpng %s -o acm.png", name);
	system(cmd);
}

void DessinerNuage(point *pts, int n){
	FILE *dst;
	char name[128] = "nuage.dot";
	char cmd[1028];
	dst = fopen("nuage.dot", "w");
	if (dst == NULL ) {
		perror("erreur fonction DessinerNuage");
		exit(1);

	}
	fprintf(dst, "graph nuage {\n" );
	fprintf(dst, "node [shape=circle]\n");
	for (int i = 0; i < n; ++i) {
    fprintf(dst,"%d [pos = \"%f,%f!\" ];\n",i,pts[i].x,pts[i].y);
	}
	fputc('}',dst);
	fclose(dst);
	sprintf(cmd, "dot -Kfdp -n -Tpng %s -o nuage.png", name);
	system(cmd);
}


void AFFICHER(graphe g)
{
  printf("nbs=%d\n",g.nbs);
  for (int i = 0; i < g.nbs; ++i) {
    for (int j = i+1; j < g.nbs; j++) {
      if (g.mat[i][j]) {
        printf("%d -- %d\n", i, j);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  point *pts=nuage(10);
  graphe g=kruskal(pts,10);
	g.clr=calloc(g.nbs,sizeof(int));
	int ptr=0;
	int *visite=calloc(g.nbs,sizeof(int));
	parcours(0,&ptr,&g,&visite);
  DessinerNuage(pts,10);
  DessinerACM(pts,10,g);
  AFFICHER(g);
	free(visite);
	free(g.clr);
  return 0;
}
