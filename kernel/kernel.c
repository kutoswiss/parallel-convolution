/* ------------------------------------------
 * Project: 2D Convolution with Pthread
 * Authors: Rejas C. & Poroli F.
 * Version: 1.0, 2015-10-16
 * ------------------------------------------*/

#include "kernel.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool load_kernel(kernel_t* k, char* name) {
    int i = -1; // Start at -1 to be able to read the first line (size of the kernel)
    char* str = malloc(sizeof(char) * 99);
    char* path = malloc(sizeof(char) * 99);

    strcpy(path, KERNEL_PATH);
    strcat(path, name);
    strcat(path, ".msk");

    FILE* f = fopen(path, "r");
    if (f == NULL) {
        free(str);
        free(path);
        return false;
    }

    while (fscanf(f, "%s", str) != EOF) {
        char* token;
        char* line = malloc(sizeof(char) * 99);
        strcpy(line, str);

        if (i < 0) {
            k->size = atoi(line);
            k->matrix = malloc(sizeof(int) * k->size * k->size);
        }

        while ((token = strsep(&line, ";")) != NULL) {
            if (i >= 0)
                k->matrix[i] = atof(token);
            i++;
        }
    }

    fclose(f);
    free(str);
    free(path);
    return true;
}

void print_kernel(kernel_t* k) {
    for (int h = 0; h < k->size * k->size; h += (k->size)) {
        for (int w = 0; w < k->size; w++)
            printf("%f ", k->matrix[h + w]);
        printf("\n");
    }
}

void free_kernel(kernel_t* k) {
    free(k->matrix);
    free(k);
}

float get_kernel_value(kernel_t* k, int x, int y) {
    int half = k->size / 2;
    return k->matrix[(y + half) * k->size + (x + half)];
}
