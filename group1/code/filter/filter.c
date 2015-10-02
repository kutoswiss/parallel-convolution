#ifndef __FILTER_H__
#define __FILTER_H__

#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

/**
 * @brief Function who set the identity filter on the parameter
 * @param filter_t* A pointer to the convolution filter (struct type)
 */
void set_identity_filter(filter_t* f) {
	f->size = 3;
	f->matrix = malloc(sizeof(int) * f->size * f->size );

	for(int i = 0; i < f->size * f->size; i++)
		f->matrix[i] = 0;
		
	f->matrix[4] = 1;
}

/**
 * @brief Function who set the edge filter on the parameter
 * @param filter_t* A pointer to the convolution filter (struct type)
 */
void set_edge_filter(filter_t* f) {
	f->size = 3;
	f->matrix = malloc(sizeof(int) * f->size * f->size );

	for(int i = 0; i < f->size * f->size; i++)
		f->matrix[i] = -1;
		
	f->matrix[4] = 8;
}


/**
 * @brief Function who print the filter on output terminal
 * @param filter_t* The convolution filter (struct type)
 */
void print_filter(filter_t* f) {
	for(int h = 0; h < f->size * f->size; h+=(f->size)) {
		for(int w = 0; w < f->size; w++)
			printf("%d ", f->matrix[h + w]);

		printf("\n");
	}
}

/**
 * @brief Function used to free the filter 
 * @param filter_t* The convolution filter (struct type)
 */
void free_filter(filter_t* f) {
	free(f->matrix);
	free(f);
}



#endif