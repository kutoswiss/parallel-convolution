#include <stdio.h>
#include <stdlib.h>
#include "filter/filter.h"
#include "ppm/ppm.h"

int main()
{
	filter_t* f = malloc(sizeof(filter_t));
	set_identity_filter(f);

	for(int y = 0; y < f->size; y++)
		printf("%d %d %d\n", f->matrix[y][0], f->matrix[y][1], f->matrix[y][2]);


	return EXIT_SUCCESS;
}
