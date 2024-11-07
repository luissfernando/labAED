ejecutable: tree.o main.o
	gcc -o ejecutable main.o tree.o

main.o: main.c tree.h
	gcc -c -g main.c

tree.o: tree.h tree.c
	gcc -c -g tree.c

clean:
	rm * .o
	rm ejecutable
