#include "ppm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entry point.
int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr,
                "usage: %s input output\n"
                "where input and output are PPM files\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    char* input = argv[1];
    char* output = argv[2];

    img_t* img = load_ppm(input);
    if (img == NULL) {
        fprintf(stderr, "Failed loading %s!\n", input);
        return EXIT_FAILURE;
    }

    // Reduce the brightness by half.
    for (int j = 0; j < img->height * img->width; j++) {
        pixel_t* p = &img->data[j];
        p->r /= 2;
        p->g /= 2;
        p->b /= 2;
    }

    if (!write_ppm(argv[2], img)) {
        fprintf(stderr, "Failed writing %s!\n", output);
        free_img(img);
        return EXIT_FAILURE;
    }

    free_img(img);
    return EXIT_SUCCESS;
}
