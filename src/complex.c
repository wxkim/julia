#include "complex.h"

complex_t phasor_to_complex(phasor_t p) {
    complex_t c = {
        .re = p.mag * trig_cosine(p.pha),
        .im = p.mag * trig_sine(p.pha)
    };

    return c;
}

phasor_t complex_to_phasor(complex_t c) {
    phasor_t p = {
        .mag = square_root((c.re * c.re) + (c.im * c.im)),
        .pha = trig_arc_tangent(c.im, c.re)
    };

    return p;
}

complex_t complex_add(complex_t a, complex_t b) {
    complex_t c = {
        .re = a.re + b.re,
        .im = a.im + b.im
    };

    return c;
}   

complex_t complex_mult(complex_t a, complex_t b) {

}   

phasor_t phasor_add(phasor_t m, phasor_t n) {

} 

void complex_conjugate(complex_t *c) {
    c->im = reverse_absolute(c->im);
}
