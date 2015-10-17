
#include <stdio.h>
#include <stdlib.h>
#include "../kernel/kernel.h"
#include "../ppm/ppm.h"

/**
 * Structure convolve_st 
 * The convolution structure is composed
 * typedef convolve_t
 */
typedef struct convolve_st{
	int n_thread; 
	img_t* img_src;
	img_t* img_dst;
	kernel_t* k;

}convolve_t;

/**
 * Structure convolve_param_st 
 * The convolution parameter structure is composed
 * typedef convolve_param_t
 */
typedef struct convolve_param_st{
	convolve_t* c;
	int current_thread;

}convolve_param_t;



void convolve_pixel(img_t* img_src, img_t* img_dst, kernel_t* k, int x, int y);
void convolve(img_t* img_src, img_t* img_dst, kernel_t* k);
void* convolve_thread(void* c);
uint8_t float_to_uint8_t(float v);
pixel_t float_to_pixel_t(float r, float g, float b);
