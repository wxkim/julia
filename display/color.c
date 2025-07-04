#include "color.h"
#include <math.h> // only doing this bc i dont want to write my own log

const pixel_t COLOR_BLACK = (pixel_t) {0,0,0};
const pixel_t COLOR_WHITE = (pixel_t) {255,255,255};

void color_invert(pixel_t *p) {
    p->r = 255.0F - p->r;
    p->g = 255.0F - p->g;
    p->b = 255.0F - p->b;
}

pixel_t color_greyscale(int iterations, int max_iterations) {
    float norm = (float)iterations / max_iterations;

    float gamma = 1.03443332F;

    norm = powf(norm, gamma); 

    uint8_t level = (uint8_t)(255.0f * norm);

    return (pixel_t){level, level, level};
}

pixel_t color_grad(int iterations, int max_iterations) {
    if (iterations == max_iterations)
        return COLOR_BLACK; 

    float t = (float)iterations / max_iterations;

    float brightness = powf(t, 0.3f);

    uint8_t r = (uint8_t)(9 * (1 - brightness) * brightness * brightness * brightness * 255);
    uint8_t g = (uint8_t)(15 * (1 - brightness) * (1 - brightness) * brightness * brightness * 255);
    uint8_t b = (uint8_t)(8.5 * (1 - brightness) * (1 - brightness) * (1 - brightness) * brightness * 255);

    return (pixel_t){r, g, b};
}

pixel_t color_rgb(int iterations, int max_iterations) {
    const int band = iterations % 3;

    uint8_t candela =  (uint8_t)(255.0F * (double)iterations / max_iterations);

    switch (band) {
        case 0: return (pixel_t) {candela, 0,0};
        case 1: return (pixel_t) {0,candela,0};
        case 2: return (pixel_t) {0,0, candela};
        default: return COLOR_BLACK;
    }
}

pixel_t color_black_white(int iterations, int max_iterations) {
    return iterations == max_iterations ? COLOR_BLACK : COLOR_WHITE;
}




