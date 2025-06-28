#include "math.h"
#include <stdint.h>

/*
    typedef union {
            double val;
            uint64_t bits;
    } flop_t;
*/

double absolute(double x) {
    flop_t dec;

    dec.val = x;
    dec.bits &= ~(0x01 << 63);

    return dec.val;
}

double square_root(double x) {
    flop_t in, out;

    in.val = x;


    if ((in.bits >> 63) == 1 && (in.bits << 1)) kill(getpid(), SIGTERM);

}

double base_power(double base, double exp) {

}


double reduce_range_radians(double rad) {

}

double reduce_range_degrees(double rad) {

}


double trig_sine(double x) {

}

double trig_cosine(double x) {

}

double trig_tangent(double x) {

}

double arc_tangent(double y, double x) {

}
