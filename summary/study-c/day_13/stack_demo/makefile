a.out : stack.o main.o
	gcc -DSIZE=10 stack.c main.c
stack.o : stack.c
	gcc -c stack.c
main.o : main.c
	gcc -c -DSIZE=10 main.c
