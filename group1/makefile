CC=gcc -std=gnu99 -Wall 

all: conv

conv: kernel.o main.o ppm.o
	$(CC) -o conv kernel.o ppm.o main.o

main.o: main.c kernel.o ppm.o
	$(CC) -c main.c

kernel.o:
	$(CC) -c kernel/kernel.c

ppm.o:
	$(CC) -c ppm/ppm.c

clean: 
	rm -f *.o conv
	echo Clean done