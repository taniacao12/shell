all: shell.o main.o
	gcc -o main.out main.o shell.o
shell.o: shell.c shell.h
	gcc -c -g shell.c
main.o: main.c shell.h
	gcc -c -g main.c
run:
	./main.out
clean:
	rm -rf *~
	rm -rf *.out
	rm -rf *.o
	rm -rf *.txt
