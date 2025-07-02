#include "complex.h"

complex_t phasor_to_complex(phasor_t p) {
    return (complex_t) {
        .re = p.mag * trig_cosine(p.pha),
        .im = p.mag * trig_sine(p.pha)
    };
}

phasor_t complex_to_phasor(complex_t c) {
    return (phasor_t ) {
        .mag = square_root((c.re * c.re) + (c.im * c.im)),
        .pha = trig_arc_tangent(c.im, c.re)
    };
}

complex_t complex_add(complex_t a, complex_t b) {
    return (complex_t) {
        .re = a.re + b.re,
        .im = a.im + b.im
    };
}   

complex_t complex_mult(complex_t a, complex_t b) {
    return (complex_t){
        .re = a.re * b.re - a.im * b.im,
        .im = a.re * b.im + a.im * b.re
    };
}   

void complex_conjugate(complex_t *c) {
    c->im = reverse_absolute(c->im);
}
