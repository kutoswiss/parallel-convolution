CC=gcc -std=gnu99 -Wall 

all: conv

conv: filter.o main.o ppm.o
	$(CC) -o conv filter.o ppm.o main.o

main.o: main.c filter.o ppm.o
	$(CC) -c main.c

filter.o:
	$(CC) -c filter/filter.c

ppm.o:
	$(CC) -c ppm/ppm.c

clean: 
	rm -f *.o conv
	echo Clean done