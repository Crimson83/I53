CC = gcc -Wall
YACC = bison -v

exec: calc.exe
	./calc.exe

calc.exe: calc.o
	$(CC) -o calc.exe calc.o

calc.o: calc.c
	$(CC) -c calc.c

calc.c: calc.y
	$(YACC) calc.y -o calc.c

clean :
	rm *.c *.o* *.exe
