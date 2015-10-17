/* ------------------------------------------
 * Project: 2D Convolution with Pthread
 * Authors: Rejas C. & Poroli F.
 * Version: 1.0, 2015-10-16
 * ------------------------------------------*/

#include <stdbool.h>
#define KERNEL_PATH "kernel/msk/"

/**
 * Structure kernel_st 
 * The kernel structure is composed
 * typedef kernel_t
 */
typedef struct kernel_st{
	int size; /**< integer type for the size of the matrix (always a square size) */
	float* matrix; /**< Pointer to a float to store the matrix on a one dimension dynmaic array*/
}kernel_t;

extern bool load_kernel();
extern void print_kernel(kernel_t* k);
extern void free_kernel(kernel_t* k);
extern float get_kernel_value(kernel_t* k, int x, int y);