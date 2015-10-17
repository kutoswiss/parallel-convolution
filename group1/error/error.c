/* ------------------------------------------
 * Project: 2D Convolution with Pthread
 * Authors: Rejas C. & Poroli F.
 * Version: 1.0, 2015-10-16
 * ------------------------------------------*/

#ifndef __ERROR_H__
#define __ERROR_H__

#include "error.h"

/**
 * @brief Function to print the error
 */
void error_input_arg() {
	printf("Bad input arguments : ./conv input output K N\n");
	printf("input & output = PPM file\n");
	printf("K = Kernel to use :\n\tidentity(3x3)\n\tsharpen(3x3)\n\tedge(3x3)\n\temboss(3x3)\n\tblur(3x3)\n\tgauss(5x5)\n\tunsharp(5x5)\n");
	printf("N = number of thread (0 = without thread)\n");
}

/**
 * @brief Function to print the error
 */
void error_kernel_not_found() {
	printf("Error: Kernel not found\n");
	printf("-K = Kernel to use :\n\tidentity(3x3)\n\tsharpen(3x3)\n\tedge(3x3)\n\temboss(3x3)\n\tblur(3x3)\n\tgauss(5x5)\n\tunsharp(5x5)\n");
}

/**
 * @brief Function to print the error
 */
void error_ppm_not_found() {
	printf("Error: ppm file not found\n");
}

/**
 * @brief Function to print the error
 */
void error_amount_threads() {
	printf("N must be higher than 0\n");
}


#endif