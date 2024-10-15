ejecutable: main.o list.o
	gcc -o ejecutable main.o list.o

main.o: main.c list.h
	gcc -c -g main.c

list.o: list.h list.c 
	gcc -c -g list.c 

clean:
	rm * .o
	rm ejecutable
