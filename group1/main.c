#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "error/error.h"
#include "convolution/convolution.h"

#define ARGC_MIN 3

void get_time(struct timespec* t);
void print_measure(struct timespec start, struct timespec finish);

int main(int argc, char **argv) {
	struct timespec start, finish;
	get_time(&start);

	//pthread_t thread;
	convolve_t *p = malloc(sizeof(convolve_t));
	//convolve_param_t *p[] = malloc(sizeof(convolve_param_t) * 10); // 10 = nbr de thread

	if(argc < ARGC_MIN) {
		error_input_arg();	
		return EXIT_FAILURE;
	}

	// Get the input and output filename
	char* img_input_filename = argv[1];
	char* img_output_filename = argv[2];
	char* kernel_select = argv[3];

	// Load the image from filename
	p->img_src = load_ppm(img_input_filename);
	


	p->img_dst = alloc_img(p->img_src->width, p->img_src->height);
	if (p->img_src == NULL) {
		fprintf(stderr, "Failed loading %s!\n", img_input_filename);
		return EXIT_FAILURE;
    }


    // Load the kernel
	p->k = malloc(sizeof(kernel_t));
	if(!load_kernel(p->k, kernel_select)) {
		error_kernel_not_found();
		return EXIT_FAILURE;
	}

	print_kernel(p->k);

	// Apply the kernel
	p->nbr_thread = 50;
	p->num_thread = 0;
	convolve_thread(p);
	p->num_thread = 33;
	convolve_thread(p);


	// Write the new image
	if (!write_ppm(img_output_filename, p->img_dst)) {
		fprintf(stderr, "Failed writing %s!\n", img_output_filename);
		free_img(p->img_src);
		return EXIT_FAILURE;
	}

	//Free the memory :)
	free_kernel(p->k);
	free_img(p->img_src);
	free_img(p->img_dst);

	get_time(&finish);
	print_measure(start, finish);

	return EXIT_SUCCESS;
}

void get_time(struct timespec* t) {
	clock_gettime(CLOCK_MONOTONIC, t);
}

void print_measure(struct timespec start, struct timespec finish) {
	double elapsed_ms = 1000 * (finish.tv_sec - start.tv_sec);
	elapsed_ms += (finish.tv_nsec - start.tv_nsec) / 1000000.0;
	printf("%f [ms]\n", elapsed_ms);
}
