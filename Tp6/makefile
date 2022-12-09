test:main.o clique.o
	gcc -Wall -g -o $@ main.c clique.o

main.o:main.c clique.h
	gcc -Wall -g -c main.c clique.h
clique.o:clique.c clique.h
	gcc -Wall -g -c clique.c clique.h

clean:
	rm *.o
