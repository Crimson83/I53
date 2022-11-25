all:clean exec

exec:main
	./main

main:main.o graphe.o point.o kruskal.o
	gcc -Wall $^ -o $@

main.o:main.c point.h graphe.h kruskal.h
	gcc -c $<

acm.o:acm.c acm.h graphe.h point.h
	gcc -c $<

graphe.o:graphe.c graphe.h
	gcc -c $<

point.o:point.c point.h
	gcc -c $<
