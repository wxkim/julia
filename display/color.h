#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>

typedef struct __attribute__((packed)) {
    uint8_t r,g,b;
} pixel_t;

extern const pixel_t COLOR_BLACK;
extern const pixel_t COLOR_WHITE;

void color_invert(pixel_t *p);

pixel_t color_greyscale(int iterations, int max_iterations);
pixel_t color_grad(int iterations, int max_iterations);
pixel_t color_rgb(int iterations, int max_iterations);
pixel_t color_black_white(int iterations, int max_iterations);

#endif
