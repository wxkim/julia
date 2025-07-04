#include "../inc/julia.h"


#include "../core/core.h"
//#include "../core/thread.h"
#include "../display/color.h"
#include "../display/buffer.h"


complex_t julia_map_pixel_to_complex(int x, int y, int width, int height) {
	complex_t z = {
		.re = SCALEV * (x - width / 2.0F) / (0.5F * width),
		.im = SCALEV * (y - height / 2.0F) / (0.5F * height)
	};

	return z;
}

complex_t mandelbrot_map_pixel_to_complex(int x, int y, int width, int height) {
    float re_min = -2.5F, re_max = 1.0F;
    float im_min = -1.0F, im_max = 1.0F;

    float re = re_min + x * (re_max - re_min) / (float)(width - 1);
    float im = im_max - y * (im_max - im_min) / (float)(height - 1);  

    return (complex_t){ .re = re, .im = im };
}

static int compute_escape(int width, int height, complex_t cs, complex_t c0) {
	return compute_iterations(cs, c0, MAX_ITER);
}

void julia_compute(frame_dimensions_t* f, pixel_t* framebuffer, uint32_t max_iter) {

	complex_t c0 = {
		.re = 0.355F,
		.im = 0.355F 
	};

	for(uint32_t y = f->ybound_begin; y < f->ybound_end; ++y) {
		for(uint32_t x = f->xbound_begin; x < f->xbound_end; ++x) {

			complex_t z0 = julia_map_pixel_to_complex(x, y, f->img_width, f->img_height);
			int iter = compute_escape(f->img_width, f->img_height, z0, c0);

			pixel_t color = color_greyscale(iter, max_iter);

			buffer_set(x, y, color);

		}
	}
	
}

void mandelbrot_compute(frame_dimensions_t* f, pixel_t* framebuffer, uint32_t max_iter) {
	complex_t z0 = {
		.re = 0.0F,
		.im = 0.0F 
	};

	for(uint32_t y = f->ybound_begin; y < f->ybound_end; ++y) {
		for(uint32_t x = f->xbound_begin; x < f->xbound_end; ++x) {

			complex_t c0 = mandelbrot_map_pixel_to_complex(x, y, f->img_width, f->img_height);
			int iter = compute_escape(f->img_width, f->img_height, z0, c0);

			pixel_t color = color_rgb(iter, max_iter);

			buffer_set(x, y, color);
			
		}
	}
}

unsigned int compute_iterations(complex_t z0, complex_t c, uint32_t max_iter) {
	unsigned int iterations = 0;
	while (iterations < max_iter) {
		double re2 = z0.re * z0.re;
        double im2 = z0.im * z0.im;

        if (re2 + im2 > 4.0) break;

		z0 = complex_add( complex_mult(z0, z0) , c);
		iterations++;
	}

	return iterations;
}