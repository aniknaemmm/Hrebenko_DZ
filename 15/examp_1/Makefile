

all: obj/main.o obj/Home_15_function_of_numbers.o bin/
	gcc -o bin/app obj/*

obj/main.o: main.c obj/
	gcc --std=c11 -o obj/main.o -c  main.c

obj/funs.o: ../../modules/src/Home_15_function_of_numbers.c obj/
	gcc --std=c11 -o obj/Home_15_function_of_numbers.o -c ../../modules/src/Home_15_function_of_numbers.c

bin/:
	mkdir bin

obj/: 
	mkdir obj

clean:
	rm -rf bin obj
