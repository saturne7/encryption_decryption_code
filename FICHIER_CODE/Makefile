all: main

main: main.c cesar.o
	gcc cesar.o main.c -o main

ceasar.o: cesar.c cesar.h
	gcc -c cesar.c