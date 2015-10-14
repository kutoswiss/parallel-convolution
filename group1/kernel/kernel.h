#include <stdbool.h>
#define KERNEL_PATH "kernel/msk/"

/**
 * Structure kernel_st 
 * The kernel structure is composed
 * typedef kernel_t
 */
typedef struct kernel_st{
	int size; /**< integer type for the size of the matrix (always a square size) */
	int* matrix; /**< Pointer to an integer to store the matrix on a one dimension array*/
}kernel_t;

extern bool load_kernel();
extern void print_kernel(kernel_t* k);
extern void free_kernel(kernel_t* k);
extern int get_kernel_value(kernel_t* k, int x, int y);