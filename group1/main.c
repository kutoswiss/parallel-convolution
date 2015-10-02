#include <stdio.h>
#include <stdlib.h>
#include "kernel/kernel.h"
#include "ppm/ppm.h"

#define ARGC_MIN 3

/**
 * @brief Function used to apply a filter to a ppm image
 * @param kernel_t* The convolution kernel (struct type)
 * @param img_t* The image ppm format
 */
void convolve_pixel(img_t* img_src, img_t* img_dst, kernel_t* k, int x, int y) {
	int half_size = k->size / 2;

	for(int ky = 0; ky < half_size; ky++) {
		for(int kx = 0; kx < half_size; kx++) {
			pixel_t init_px = get_pixel(img_src, x + kx, y + ky);

		}
	}
}


int main(int argc, char **argv) {
	if(argc < ARGC_MIN) {
		printf("Gueule at.\n");
		return EXIT_FAILURE;
	}

	// Get the input and output filename
	char* img_input_filename = argv[1];
	char* img_output_filename = argv[2];

	// Load the image from filename
	img_t* img = load_ppm(img_input_filename);
	img_t* img_dst = load_ppm(img_input_filename);
	if (img == NULL) {
		fprintf(stderr, "Failed loading %s!\n", img_input_filename);
		return EXIT_FAILURE;
    }

    // Load the kernel
	kernel_t* k = malloc(sizeof(kernel_t));
	set_edge_kernel(k);

	// Apply the kernel

	// Write the new image
	if (!write_ppm(img_output_filename, img_dst)) {
		fprintf(stderr, "Failed writing %s!\n", img_output_filename);
		free_img(img);
		return EXIT_FAILURE;
	}

	// Free the memory :)
	free_kernel(k);
	free_img(img);

	return EXIT_SUCCESS;
}