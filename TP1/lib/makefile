SHELL = /bin/bash
CFLAGS = -Wall -g -I$$GRAPHE -L$$GRAPHE
libgraphe.a : graphe.o inout.o
	ar crs libgraphe.a $^
	ranlib libgraphe.a

graphe.o : graphe.c
	gcc $(CFLAGS) graphe.c -c
