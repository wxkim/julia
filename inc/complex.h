#ifndef COMPLEX_H
#define COMPLEX_H

#include "pmath.h"
#include "stdint.h"

typedef struct __attribute__((packed)){
    double re, im;
} complex_t;

typedef struct __attribute__((packed)){
    double mag, pha;
} phasor_t;

complex_t phasor_to_complex(phasor_t p);
phasor_t complex_to_phasor(complex_t c);

complex_t complex_add(complex_t a, complex_t b);
complex_t complex_mult(complex_t a, complex_t b);
phasor_t phasor_add(phasor_t m, phasor_t n);

complex_t complex_conjugate(complex_t c);

#endif


