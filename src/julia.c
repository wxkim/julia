#include "julia.h"

complex_t map_pixel_to_complex(int x, int y, int width, int height) {
	complex_t z = {
		.re = SCALEV * (x - width / 2.0F) / (0.5F * width),
		.im = SCALEV * (y - height / 2.0F) / (0.5F * height)
	};

	return z;
}

static int compute_escape(int width, int height, complex_t cs) {
	complex_t c0 = {
		.re = -0.7F,
		.im = 0.7015F 
	};

	return julia_iterations(cs, c0, MAX_ITER);

}

void julia_compute(int width, int height) {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			complex_t z0 = map_pixel_to_complex(x, y, width, height);
			int iter = compute_escape(width, height, z0);
			pixel_t color = color_grad(iter, MAX_ITER);
			buffer_set(x, y, color);
		}
	}

	// for (int y = 0; y < height; ++y)
    // for (int x = 0; x < width; ++x)
    //     buffer_set(x, y, (pixel_t){255, 0, 0});
}

unsigned int julia_iterations(complex_t z0, complex_t c, int max_iterations) {
	unsigned int iterations = 0;
	while (iterations < MAX_ITER) {
		double re2 = z0.re * z0.re;
        double im2 = z0.im * z0.im;

        if (re2 + im2 > 4.0) break;

		z0 = complex_add( complex_mult(z0, z0) , c);
		iterations++;
	}

	return iterations;
}