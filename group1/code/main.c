#include <stdio.h>
#include <stdlib.h>
#include "filter/filter.h"
#include "ppm/ppm.h"

#define ARGC_MIN 3

/**
 * @brief Function used to apply a filter to a ppm image
 * @param filter_t* The convolution filter (struct type)
 * @param img_t* The image ppm format
 */
void apply_filter(img_t* img, filter_t* f) {
	// TODO: Ecrire la fonction permettant d'appliquer le filtre
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
	if (img == NULL) {
		fprintf(stderr, "Failed loading %s!\n", img_input_filename);
		return EXIT_FAILURE;
    }

    // Load the filter
	filter_t* f = malloc(sizeof(filter_t));
	set_edge_filter(f);
	// print_filter(f);

	// Apply the filter
	apply_filter(img, f);

	// Write the new image
	if (!write_ppm(img_output_filename, img)) {
		fprintf(stderr, "Failed writing %s!\n", img_output_filename);
		free_img(img);
		return EXIT_FAILURE;
	}

	// Free the memory :)
	free_filter(f);
	free_img(img);

	return EXIT_SUCCESS;
}