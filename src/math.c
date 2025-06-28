#include "math.h"
#include <stdint.h>

double absolute(double x) {
    union {
        double value;
        uint64_t bits;
    } dec;

    dec.value = x;
    dec.bits &= ~(0x01 << 63);

    return dec.value;
}

double square_root(double x) {

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
