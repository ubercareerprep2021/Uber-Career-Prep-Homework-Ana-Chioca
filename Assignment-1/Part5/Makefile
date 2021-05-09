all: prog

run: prog
	./prog

valgrind: prog
	gcc -o prog -g -Wall -ggdb3 LinkedList.o main.o -g
	valgrind --leak-check=full --show-leak-kinds=all ./prog
	
prog: LinkedList.o main.o
	gcc -o prog LinkedList.o main.o -g

main.o: main.c
	gcc -c main.c

Part4.o: LinkedList.c
	gcc -c LinkedList.c

clean: 
	rm -rf *o prog
