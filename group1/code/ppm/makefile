GCC=gcc -Wall -std=gnu99

display: ppm_example.o ppm.o
	$(GCC) $^ -o $@

ppm_example.o: ppm_example.c
	$(GCC) $< -c

ppm.o: ppm.c ppm.h
	$(GCC) $< -c

clean:
	rm -f *.o ppm_example
