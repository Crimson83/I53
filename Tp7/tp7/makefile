all:exec

exec:parser
	./parser exemple.algo > algo.ram

parser:parser.c lexer.c ts.c
	gcc -Wall -o parser parser.c lexer.c -lfl

parser.c:parser.y ts.h
	bison -o parser.c -d parser.y

lexer.c:lexer.lex
	flex -o lexer.c lexer.lex
