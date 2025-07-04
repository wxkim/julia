#ifndef JULIA_H
#define JULIA_H

#include "../core/core.h"
#include "../display/color.h"
#include "complex.h"


#include "../display/buffer.h"
#include "../display/render.h"
#include "../core/thread.h"

#define MAX_ITER (512)
#define SCALEV (1.5F)

void julia_compute(frame_dimensions_t* f, pixel_t* framebuffer, uint32_t max_iter);
void mandelbrot_compute(frame_dimensions_t* f, pixel_t* framebuffer, uint32_t max_iter);

unsigned int compute_iterations(complex_t z0, complex_t c, uint32_t max_iter);
complex_t map_pixel_to_complex(int x, int y, int width, int height);

#endif
