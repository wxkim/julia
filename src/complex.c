#include "complex.h"

complex_t phasor_to_complex(phasor_t p) {
    complex_t c = {
        .re = p.mag * trig_cosine(p.pha);
        .im = p.mag * trig_sine(p.pha);
    }

    return c;
}

phasor_t complex_to_phasor(complex_t c) {
    phasor_t p = {
        .mag = square_root(c.re * c.re + c.im * c.im);
        .pha = trig_arc_tangent(c.im, c.re);
    }

    return p;
}

