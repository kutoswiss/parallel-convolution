/* ------------------------------------------
 * Project: 2D Convolution with Pthread
 * Authors: Rejas C. & Poroli F.
 * Version: 1.0, 2015-10-16
 * ------------------------------------------*/

#include "convolution.h"

void convolve_pixel(img_t* img_src, img_t* img_dst, kernel_t* k, int x, int y) {
    int half_size = k->size / 2;
    float r = 0.0;
    float g = 0.0;
    float b = 0.0;

    for (int ky = -half_size; ky <= half_size; ky++) {
        for (int kx = -half_size; kx <= half_size; kx++) {
            pixel_t src_px = get_pixel(img_src, x + kx, y + ky);
            float kernel_value = get_kernel_value(k, kx, ky);
            r += (kernel_value * src_px.r);
            g += (kernel_value * src_px.g);
            b += (kernel_value * src_px.b);
        }
    }
    set_pixel(img_dst, float_to_pixel_t(r, g, b), x, y);
}

void convolve(img_t* img_src, img_t* img_dst, kernel_t* k) {
    for (int y = 0; y < img_src->height; y++)
        for (int x = 0; x < img_src->width; x++)
            convolve_pixel(img_src, img_dst, k, x, y);
}

void* convolve_thread(void* c) {
    convolve_param_t* p = (convolve_param_t*)c;
    int bloc = p->c->img_src->height / p->c->n_thread;
    int row_start = p->current_thread * bloc;
    int height_size = (p->current_thread != p->c->n_thread - 1) ? (row_start + bloc) : p->c->img_src->height;

    for (int y = row_start; y < height_size; y++)
        for (int x = 0; x < p->c->img_src->width; x++)
            convolve_pixel(p->c->img_src, p->c->img_dst, p->c->k, x, y);

    return NULL;
}

uint8_t float_to_uint8_t(float v) {
    uint8_t r = 0;
    if (v < 0.0)
        r = 0;
    else if (v > 255.0)
        r = 255;
    else
        r = (uint8_t)v;
    return r;
}

pixel_t float_to_pixel_t(float r, float g, float b) {
    pixel_t p = {0, 0, 0};
    p.r = float_to_uint8_t(r);
    p.g = float_to_uint8_t(g);
    p.b = float_to_uint8_t(b);
    return p;
}
