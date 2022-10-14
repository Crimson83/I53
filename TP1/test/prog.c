#include "../lib/inout.h"
#include "../lib/graphe.h"

int main(int argc,char* argv[]){
  graphe g;
  g=liregraphe(argv[1]);
  dessiner("maison",g);
  return 0;
}
