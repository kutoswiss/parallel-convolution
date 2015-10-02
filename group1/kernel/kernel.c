#ifndef __KERNEL_H__
#define __KERNEL_H__

#include <stdio.h>
#include <stdlib.h>
#include "kernel.h"



/**
 * @brief Function who set the identity filter on the parameter
 * @param kernel_t* A pointer to the convolution filter (struct type)
 */
void set_identity_kernel(kernel_t* k) {
	k->size = 3;
	k->matrix = malloc(sizeof(int) * k->size * k->size );

	for(int i = 0; i < k->size * k->size; i++)
		k->matrix[i] = 0;
		
	k->matrix[4] = 1;
}

/**
 * @brief Function who set the edge filter on the parameter
 * @param kernel_t* A pointer to the convolution filter (struct type)
 */
void set_edge_kernel(kernel_t* k) {
	k->size = 3;
	k->matrix = malloc(sizeof(int) * k->size * k->size );

	for(int i = 0; i < k->size * k->size; i++)
		k->matrix[i] = -1;
		
	k->matrix[4] = 8;
}

/**
 * @brief Function who set the edge filter on the parameter
 * @param kernel_t* A pointer to the convolution filter (struct type)
 */
void set_sharpen_kernel(kernel_t* k) {
	k->size = 3;
	k->matrix = malloc(sizeof(int) * k->size * k->size );

	for(int i = 0; i < k->size * k->size; i++)
		k->matrix[i] = 0;
		
	k->matrix[1] = -1;
	k->matrix[3] = -1;
	k->matrix[4] = 5;
	k->matrix[5] = -1;
	k->matrix[7] = -1;
}


/**
 * @brief Function who print the filter on output terminal
 * @param kernel_t* The convolution filter (struct type)
 */
void print_kernel(kernel_t* k) {
	for(int h = 0; h < k->size * k->size; h+=(k->size)) {
		for(int w = 0; w < k->size; w++)
			printf("%d ", k->matrix[h + w]);

		printf("\n");
	}
}

/**
 * @brief Function used to free the filter 
 * @param kernel_t* The convolution filter (struct type)
 */
void free_kernel(kernel_t* k) {
	free(k->matrix);
	free(k);
}

/**
 * @brief 
 * @param kernel_t Kernel structure type
 * @param integer x
 * @param integer y
 */
int get_kernel_value(kernel_t* k, int x, int y) {
	return k->matrix[(y+1) * k->size + (x+1)];
}



#endif