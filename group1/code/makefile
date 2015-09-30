CC=gcc -std=gnu99 -Wall -Wextra

all: conv

conv: filter.o main.o
	$(CC) -o conv filter.o main.o

main.o: main.c filter.o
	$(CC) -c main.c

filter.o:
	$(CC) -c filter/filter.c

clean: 
	rm -f *.o conv
	echo Clean done