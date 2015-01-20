all: obj/main.o bin/ 
	gcc -o bin/app  obj/*

obj/main.o:main.c obj/
	gcc -o obj/main.o -c main.c

bin/:
	mkdir bin

obj/: 
	mkdir obj

clean:
	rm -rf bin obj
