/* ------------------------------------------
 * Project: 2D Convolution with Pthread
 * Authors: Rejas C. & Poroli F.
 * Version: 1.0, 2015-10-16
 * ------------------------------------------*/

#ifndef __KERNEL_H__
#define __KERNEL_H__

#include <stdbool.h>
#define KERNEL_PATH "msk/"

///
/// Structure kernel_st
/// The kernel structure is composed
/// typedef kernel_t
///
typedef struct kernel_st {
    int size;      /**< integer type for the size of the matrix (always a square size) */
    float* matrix; /**< Pointer to a float to store the matrix on a one dimension dynmaic array*/
} kernel_t;

///
/// @brief Function to load a kernel from .msk file
/// @param kernel_t* A pointer to the convolution filter (struct type)
/// @param char* name of the kernel (concretly the filename without .msk extension)
/// @return Returns false if it fails
///
extern bool load_kernel();

///
/// @brief Function who print the filter on output terminal
/// @param kernel_t* The convolution filter (struct type)
///
extern void print_kernel(kernel_t* k);

///
/// @brief Function used to free the filter
/// @param kernel_t* The convolution filter (struct type)
///
extern void free_kernel(kernel_t* k);

///
/// @brief Kernel value getter
/// @param kernel_t Kernel structure type
/// @param integer x
/// @param integer y
/// @return Kernel value at position x and y
///
extern float get_kernel_value(kernel_t* k, int x, int y);

#endif
