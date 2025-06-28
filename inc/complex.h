#ifndef COMPLEX_H
#define COMPLEX_H

#include "math.h"
#include "stdint.h"

typedef struct {
    double re;
    double im;
} complex_t;

typedef struct {
    double mag;
    double phase;
} phasor_t;

complex_t phasor_to_complex(phasor_t p);
phasor_t complex_to_phasor(complex_t c);

complex_t complex_add(complex_t a, complex_t b);
complex_t complex_mult(complex_t a, complex_t b);

double complex_re(complex_t c);
double complex_im(complex_t c);

#endif


