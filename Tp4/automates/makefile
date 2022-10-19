CC=gcc
CFLAGS=-Wall -g
LIBS = -lm
OBJS = afd.o afn.o


all: af

af: af.c $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

afd.o: afd.c
	$(CC) -c -g $^

afn.o: afn.c
	$(CC) -c -g $^

clean:
	rm -f *~ *.o
