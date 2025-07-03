#ifndef JULIA_H
#define JULIA_H

#include "complex.h"
#include "../display/buffer.h"
#include "../display/render.h"
#include "../display/color.h"

#define MAX_ITER (512)
#define SCALEV (1.5F)

void julia_compute(int width, int height);
unsigned int julia_iterations(complex_t z0, complex_t c, int max_iterations);
complex_t map_pixel_to_complex(int x, int y, int width, int height);

#endif
