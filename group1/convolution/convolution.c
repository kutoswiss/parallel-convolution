#ifndef __CONVOLUTION_H__
#define __CONVOLUTION_H__

#include "convolution.h"

/**
 * @brief Function used to apply a filter to a ppm image
 * @param kernel_t* The convolution kernel (struct type)
 * @param img_t* The image ppm format
 */
void convolve_pixel(img_t* img_src, img_t* img_dst, kernel_t* k, int x, int y) {
	int half_size = k->size / 2; // Can be optimized
	float r = 0.0;
	float g = 0.0;
	float b = 0.0;

	for(int ky = -half_size; ky <= half_size; ky++) {
		for(int kx = -half_size; kx <= half_size; kx++) {
			pixel_t src_px = get_pixel(img_src, x + kx, y + ky);
			int kernel_value = get_kernel_value(k, kx, ky);

			r += (kernel_value * src_px.r);
			g += (kernel_value * src_px.g);
			b += (kernel_value * src_px.b);
		}
	}
	set_pixel(img_dst, float_to_pixel_t(r, g, b), x, y);
}

/** 
 * @brief Function used to apply a 2D convolution to a ppm image
 */
void convolve(img_t* img_src, img_t* img_dst, kernel_t* k) {
	for(int y = 0; y < img_src->height; y++)
		for(int x = 0; x < img_src->width; x++)
			convolve_pixel(img_src, img_dst, k, x, y);
}

/**
 * @brief Function used to apply a 2D convolution to a ppm image
 */
void convolve_thread(convolve_t* p) {

	int bloc = p->img_src->height / p->nbr_thread;
	int debut = p->num_thread * bloc;

	for(int y = debut; y < debut+bloc; y++)
		for(int x = 0; x < p->img_src->width; x++)
			convolve_pixel(p->img_src, p->img_dst, p->k, x, y);
}

/**
 * @brief Function to convert float to uint8_t
 */
uint8_t float_to_uint8_t(float v) {
	uint8_t r = 0;
	if(v < 0.0)
		r = 0;
	else if(v > 255.0)
		r = 255;
	else
		r = (uint8_t)v;
	return r;
}


/**
 * @brief Function to convert float to pixel_t struct type
 */
pixel_t float_to_pixel_t(float r, float g, float b) {
	pixel_t p = {0, 0, 0};
	p.r = float_to_uint8_t(r);
	p.g = float_to_uint8_t(g);
	p.b = float_to_uint8_t(b);
	return p;
}

#endif