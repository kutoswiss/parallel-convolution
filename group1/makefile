CC=gcc -std=gnu99 -Wall 

all: conv

conv: error.o convolution.o kernel.o main.o ppm.o
	$(CC) -o conv error.o convolution.o kernel.o ppm.o main.o -lpthread -lrt -O3

main.o: main.c error.o convolution.o
	$(CC) -c main.c

error.o:
	$(CC) -c error/error.c

convolution.o: kernel.o ppm.o
	$(CC) -c convolution/convolution.c

kernel.o:
	$(CC) -c kernel/kernel.c

ppm.o:
	$(CC) -c ppm/ppm.c

clean: 
	rm -f *.o conv
	echo Clean done