/* ------------------------------------------
 * Project: 2D Convolution with Pthread
 * Authors: Rejas C. & Poroli F.
 * Version: 1.0, 2015-10-16
 * ------------------------------------------*/

#ifndef __CONVOLUTION_H__
#define __CONVOLUTION_H__

#include "../kernel/kernel.h"
#include "../ppm/ppm.h"
#include <stdio.h>
#include <stdlib.h>

///
/// Structure convolve_st
/// The convolution structure
/// typedef convolve_t
///
typedef struct convolve_st {
    int n_thread;
    img_t* img_src;
    img_t* img_dst;
    kernel_t* k;
} convolve_t;

///
/// Structure convolve_param_st
/// The convolution parameter structure used for the thread
/// typedef convolve_param_t
///
typedef struct convolve_param_st {
    convolve_t* c;
    int current_thread;
} convolve_param_t;

///
/// @brief Function used to apply a filter to a ppm image on a specific pixel
/// @param img_t* The ppm image source
/// @param img_t* The ppm image destination
/// @param kernel_t* The kernel (mask) to be applied
/// @param int Position x
/// @param int Position y
///
void convolve_pixel(img_t* img_src, img_t* img_dst, kernel_t* k, int x, int y);

///
/// @brief Function used to apply a 2D convolution to a ppm image
/// @param img_t* The ppm image source
/// @param img_t* The ppm image destination
/// @param kernel_t* The kernel
///
void convolve(img_t* img_src, img_t* img_dst, kernel_t* k);

///
/// @brief Function used to apply a 2D convolution to a ppm image
///
void* convolve_thread(void* c);

///
/// @brief Function to convert float to uint8_t
/// @param v A float value
///
uint8_t float_to_uint8_t(float v);

///
/// @brief Function to convert float to pixel_t struct type
/// @param r Red value (float)
/// @param g Green value (float)
/// @param b Blue value (float)
///
pixel_t float_to_pixel_t(float r, float g, float b);

#endif
