#ifndef MATH_H
#define MATH_H

#include <stdint.h>

#define PI      3.141592653589793238
#define TAU     6.283185307179586476

#define SIGN_BIT_MASK       ~(0x0001ULL << 63)
#define EXPN_BIT_MASK       ~(0x07FFULL << 52)
#define MANT_BIT_MASK       0x000FFFFFFFFFFFFF

typedef union {
        double val;
        uint64_t bits;
} flop_t;

double absolute(double x);
double square_root(double x);
double base_power(double base, double exp);

double reduce_range_radians(double rad);
double reduce_range_degrees(double rad);

double trig_sine(double x);
double trig_cosine(double x);
double trig_tangent(double x);
double arc_tangent(double y, double x);

#endif 