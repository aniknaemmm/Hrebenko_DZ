all: obj/main.o obj/kvadrat.o bin/
	gcc -o bin/app obj/*

obj/main.o: main.c obj/
	gcc --std=c99  -o obj/main.o -c main.c

obj/kvadrat.o:../../modules/src/kvadrat.c obj/
	gcc --std=c99 -o obj/kvadrat.o -c ../../modules/src/kvadrat.c

bin/:
	mkdir bin

obj/:
	mkdir obj

clean: 
	rm -rf bin obj
