#ifndef __PPM_H__
#define __PPM_H__

#include <stdbool.h>
#include <stdint.h>

///
/// Store a pixel with 8-bit per component
///
typedef struct pixel_st {
    uint8_t r, g, b; // Red, green, blue components of the pixel
} pixel_t;

///
/// Store a 24-bit per pixel image: dimension and pixel data
///
typedef struct img_st {
    int width;
    int height;
    pixel_t* data; // Pixel data
} img_t;

///
/// @brief Allocate the memory for an image of size width*height
/// @param width Width size of the image
/// @param height Height size of the image
/// @return Allocated image
///
extern img_t* alloc_img(int width, int height);

///
/// @brief Free an image
/// @param img Allocated image to be freed
///
extern void free_img(img_t* img);

///
/// @brief Write a 24-bit RGB PPM file.
/// @param filename Output filename
/// @param img Allocated image
/// @return false if the image wasn't written properly.
///
extern bool write_ppm(char* filename, img_t* img);

///
/// @brief Load a 24-bit RGB PPM file and return the loaded image.
///        The function takes care of allocating the memory for the image.
/// @param filename Image filename
///
extern img_t* load_ppm(char* filename);

///
/// @brief Pixel getter
/// @param img Allocated image
/// @param x Position in x axis
/// @param y Position in y axis
/// @return Pixel at position x and y of img
///
extern pixel_t get_pixel(img_t* img, int x, int y);

///
/// @brief Pixel setter
/// @param img Allocated image
/// @param value Value to be written
/// @param x Position in x axis
/// @param y Position in y axis
///
extern void set_pixel(img_t* img, pixel_t value, int x, int y);

#endif