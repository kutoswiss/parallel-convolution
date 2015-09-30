#ifndef __FILTER_H__
#define __FILTER_H__

#include <stdio.h>
#include "filter.h"

void set_identity_filter(filter_t* f)
{
	f->size = 3;

	f->matrix = (int**) malloc(f->size * sizeof(int*));
	for (int i = 0; i < f->size; i++)
   		f->matrix[i] = (int*) malloc(f->size*sizeof(double));


	for(int y = 0; y < f->size; y++)
		for(int x = 0; x < f->size; x++)
			f->matrix[y][x] = 0;
		
	f->matrix[1][1] = 1;
}

#endif