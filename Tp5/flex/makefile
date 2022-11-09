Ex2:pluslong.exe
	./pluslong.exe bordel.txt
Ex1:pluslong.exe
	./pluslong.exe < lex.yy.c

pluslong.exe : lex.yy.c
	gcc lex.yy.c -lfl -o pluslong.exe

lex.yy.c : pluslong.lex
	flex pluslong.lex

clean:
	rm *.c
