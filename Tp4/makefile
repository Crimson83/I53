all:clean exec

exec:main.exe mainunique.exe
	/usr/bin/time --format="cpu=%U" ./mainunique.exe 1000000
	/usr/bin/time --format="cpu=%U" ./main.exe 26000 > data.dat #26000 car limite de mon pc
	gnuplot courbe.txt -persist

main.exe:main.o disjoint.o
	gcc -Wall $^ -o $@

mainunique.exe:mainunique.o disjoint.o
	gcc -Wall $^ -o $@

mainunique.o:mainunique.c disjoint.h
	gcc -c $<

main.o:main.c disjoint.h
	gcc -c $<

disjoint.o:disjoint.c disjoint.h
	gcc -c $<

clean:
	rm *.o *.dat *.exe
