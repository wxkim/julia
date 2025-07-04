#ifndef PMATH_H
#define PMATH_H

#include <stdint.h>


#include "../core/core.h"

#define HALFPI  1.570796326794896619
#define PI      3.141592653589793238
#define TAU     6.283185307179586476

#define LUT_SIZE 2048
#define LUT_STEP (TAU / LUT_SIZE)

#define NAN     0.0 / 0.0
#define EPSILON 1E-10

#define SIGN_BIT_MASK       ~(0x0001ULL << 63)
#define EXPN_BIT_MASK       ~(0x07FFULL << 52)
#define MANT_BIT_MASK       0x000FFFFFFFFFFFFF

typedef union {
        double val;
        uint64_t bits;
} flop64_t;

typedef union {
        float val;
        uint32_t bits;
} flop32_t;

typedef enum {
        PLUS_ZERO,
        MINUS_ZERO,
        NORMAL_VALUE,
        DENORMAL_VALUE,
        PLUS_INFINITY,
        MINUS_INFINITY,
        QUIET_NAN,
        SIGNALING_NAN
} fp_reserved_status_t;

fp_reserved_status_t check_reserve_value(double x);

double absolute(double x);
double reverse_absolute(double x);
double square_root(double x);
double inverse_square_root(double x);
double base_power(double base, int exp);

double trig_sine(double x);
double trig_cosine(double x);
double trig_tangent(double x);
double trig_arc_tangent(double y, double x);

#endif 