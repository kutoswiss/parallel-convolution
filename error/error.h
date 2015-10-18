/* ------------------------------------------
 * Project: 2D Convolution with Pthread
 * Authors: Rejas C. & Poroli F.
 * Version: 1.0, 2015-10-16
 * ------------------------------------------*/

#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///
/// @brief Function to print the error
///
void error_input_arg();

///
/// @brief Function to print the error
///
void error_kernel_not_found();

///
/// @brief Function to print the error
///
void error_ppm_not_found();

///
/// @brief Function to print the error
///
void error_amount_threads();

#endif
