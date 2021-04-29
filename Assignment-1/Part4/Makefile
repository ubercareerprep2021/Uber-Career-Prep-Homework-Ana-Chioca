all: prog

run: prog
	./prog

valgrind: prog
	gcc -o prog -g -Wall -ggdb3 Part4.o main.o -g
	valgrind --leak-check=full --show-leak-kinds=all ./prog
	
prog: Part4.o main.o
	gcc -o prog Part4.o main.o -g

main.o: main.c
	gcc -c main.c

Part4.o: Part4.c
	gcc -c Part4.c

clean: 
	rm -rf *o prog
