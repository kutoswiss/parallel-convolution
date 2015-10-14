#ifndef __KERNEL_H__
#define __KERNEL_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "kernel.h"


/**
 * @brief Function to load a kernel from .msk file
 * @param kernel_t* A pointer to the convolution filter (struct type)
 */
bool load_kernel(kernel_t* k, char* name) {
	FILE *f;
	int i = -1; // Start at -1 to be able to read the first line (size of the kernel)
	char *str = malloc(sizeof(char) * 99);
	char *path = malloc(sizeof(char) * 99);

	strcpy(path, KERNEL_PATH);
	strcat(path, name);
	strcat(path, ".msk");

	f = fopen(path, "r");

	if(f != NULL) {
		while(fscanf(f, "%s", str) != EOF) {
			char *token;
			char *line = malloc(sizeof(char) * 99);
			strcpy(line, str);

			if(i < 0) {
				k->size = atoi(line);
				k->matrix = malloc(sizeof(int) * k->size * k->size);
			}

			while((token = strsep(&line, ";")) != NULL) {
				if(i >= 0)
					k->matrix[i] = atoi(token);
				i++;
			}
		}

		fclose(f);
		free(str);
		free(path);

		return true;	
	}
	else 
		return false;
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
