CFLAGS=-Wall -g -L$$GRAPHE/TP1/lib -I$$GRAPHE/TP1/lib

prog.exe : prog.o ../lib/libgraphe.a
	gcc $(CFLAGS) prog.c -o $@ -l graphe

prog.o : prog.c ../lib/graphe.h ../lib/inout.h
	gcc -Wall $< $@ -c
