SHELL=/bin/bash
compte_rendu_final.pdf:compte_rendu.tex timingOx.png timing.png pi.png
	pdflatex compte_rendu.tex

timingOx.png : timingOx.plot timingOx.dat crible.exe
	for n in 1 2 3; do \
	> timingO$$n.dat;\
	gcc crible.c -O$$n -o cribleO$$n.exe;\
	for i in {10..28}; do (./cribleO$$n.exe -t -l $$i >> timingO$$n.dat) done;\
	done
	gnuplot timingOx.plot

timing.png : timing.plot timing.dat
	gnuplot $<

timing.dat : crible.exe
	> timing.dat
	for n in {10..28}; do (./crible.exe -t -l $$n >> timing.dat) done

pi.png : data.plot
	gnuplot $<

data.dat : crible.exe
	./crible.exe -p100 -l10 | tr [=] " " | tr -d ["pi()"]  > data.dat

crible.exe : crible.o
	gcc $< -Wall -o $@

crible.o : crible.c
	gcc -c $<
