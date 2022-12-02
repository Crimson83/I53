OBJ=graphe.o disjoint.o kruskal.o
FLAGS=-Wall -g

exec:essai
	./essai

essai:main.c $(OBJ)
	gcc $(FLAGS) -o essai main.c $(OBJ) -lm

kruskal.o:kruskal.c kruskal.h disjoint.h graphe.h
	gcc $(FLAGS) -c kruskal.c

disjoint.o:disjoint.c disjoint.h
	gcc $(FLAGS) -c disjoint.c

graphe.o:graphe.c graphe.h
	gcc $(FLAGS) -c graphe.c

clean:
	rm *.o *.dot
