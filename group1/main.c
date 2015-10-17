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
	const int N = 3; // Nbr de thread

	pthread_t* thread = malloc(sizeof(pthread_t) * N);
	struct timespec start, finish;
	get_time(&start);

	convolve_param_t** p = malloc(sizeof(convolve_param_t*) * N);
	convolve_t *c = malloc(sizeof(convolve_t));

	if(argc < ARGC_MIN) {
		error_input_arg();	
		return EXIT_FAILURE;
	}

	// Get the input and output filename
	char* img_input_filename = argv[1];
	char* img_output_filename = argv[2];
	char* kernel_select = argv[3];

	// Load the image from filename
	c->img_src = load_ppm(img_input_filename);
	
	c->img_dst = alloc_img(c->img_src->width, c->img_src->height);
	if (c->img_src == NULL) {
		fprintf(stderr, "Failed loading %s!\n", img_input_filename);
		return EXIT_FAILURE;
    }

    // Load the kernel
	c->k = malloc(sizeof(kernel_t));
	if(!load_kernel(c->k, kernel_select)) {
		error_kernel_not_found();
		return EXIT_FAILURE;
	}

	print_kernel(c->k);

	c->n_thread = N;

    /*for(int i = 0; i < N; i++){
		p[i] = malloc(sizeof(convolve_param_t));
		p[i]->c = c;
		p[i]->current_thread = i;
	}

	convolve_thread(p[0]);
	convolve_thread(p[1]);*/

	// Create threads
	for(int i = 0; i < N; i++) {
		p[i] = malloc(sizeof(convolve_param_t));
		p[i]->c = c;
		p[i]->current_thread = i;
		if(pthread_create(&thread[i], NULL, convolve_thread, p[i])) {
			perror("error");
			return EXIT_FAILURE;
		}
	}

	// Join threads
	for(int i = 0; i < N; i++) {
		if(pthread_join(thread[i], NULL) != 0) {
			perror("error on join");
			return EXIT_FAILURE;
		}
	}


	// Write the new image
	if (!write_ppm(img_output_filename, c->img_dst)) {
		fprintf(stderr, "Failed writing %s!\n", img_output_filename);
		free_img(c->img_src);
		return EXIT_FAILURE;
	}

	//Free the memory :)
	free_kernel(c->k);
	free_img(c->img_src);
	free_img(c->img_dst);

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
