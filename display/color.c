#include "color.h"

const pixel_t COLOR_BLACK = (pixel_t) {0,0,0};
const pixel_t COLOR_WHITE = (pixel_t) {255,255,255};

pixel_t color_greyscale(int iterations, int max_iterations) {
    uint8_t a = (uint8_t)(255.0F * iterations / max_iterations);
    return (pixel_t) {a, a, a};
}

pixel_t color_grad(int iterations, int max_iterations) {
    double t = (double)(iterations / (double)max_iterations);

    uint8_t r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
    uint8_t g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
    uint8_t b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (pixel_t) {r, g, b};
}

pixel_t color_rgb(int iterations, int max_iterations) {
    const int band = iterations % 3;

    uint8_t candela =  (uint8_t)(255.0F * iterations / max_iterations);

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


