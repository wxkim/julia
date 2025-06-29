#include "math.h"

static fp_reserved_status_t check_reserve_value(const double *restrict x) {
    flop64_t in;
    in.val = *x;

    /*
        exponent 0 and fraction 0 = +/-zero
        exponent normal = normal value
        exponent 0b111...1 and fraction 0 = +/- infinity
        exponent 0b111...1 and fraction not 0 = nan
    */
    
    uint8_t sign        = (in.bits & SIGN_BIT_MASK) >> 63;
    uint16_t exponent   = (in.bits & EXPN_BIT_MASK) >> 52;
    uint64_t mantissa   = (in.bits & MANT_BIT_MASK);

    if (exponent == 0) {
        if (mantissa == 0) 
            return sign ? MINUS_ZERO : PLUS_ZERO;
        else 
            return DENORMAL_VALUE;
    } 
    
    else if (exponent == 0x7FF) {
        if (mantissa == 0) 
            return sign ? MINUS_INFINITY : PLUS_INFINITY;
        else 
            return NOT_A_NUMBER;
    }

    return NORMAL_VALUE;
}

double absolute(double x) {
    flop64_t dec;
    dec.val = x;
    dec.bits &= ~SIGN_BIT_MASK;

    return dec.val;
}

double square_root(const double *restrict x) {
    flop64_t seed;
    double val = *x;

    // reserve value catch cases here
    if (check_reserve_value(x) != NORMAL_VALUE) _exit(0);

    seed.val = val;
    seed.bits = (seed.bits >> 1) + 0x1ff8000000000000ULL;

    seed.val = 0.5 * (seed.val + val / seed.val);
    seed.val = 0.5 * (seed.val + val / seed.val);
    seed.val = 0.5 * (seed.val + val / seed.val);

    return seed.val;
}

double inverse_square_root(double x) {
    double xHalf = 0.5F * x;
    uint64_t i;

    flop64_t cnv;
    cnv.val = x;
    i = cnv.bits;

    i = 0x5FE6EB50C7B537A9 - (i >> 1);

    cnv.bits = i;
    double res = cnv.val;

    return res = res * (1.5 - xHalf * res * res);

}

double base_power(double base, int exp) {
    double res;

    int negate = (exp < 0);
    if (negate) exp = -exp;

    while (exp) {
        if(exp & 1) res *= base;

        base *= base;
        exp >>= 1;
    }

    return negate ? 1.0 / res : res;
}


double reduce_range_radians(double rad) {
    return 0;
}



double reduce_range_degrees(double rad) {
    return 0;
}

static inline double dg_to_rad(double dg) {
    return dg * PI / 180;
}

static inline double rad_to_dg(double rad) {
    return rad * 180 / PI;
}


double trig_sine(double x) {
    return 0;
}

double trig_cosine(double x) {
    return 0;
}

double trig_tangent(double x) {
    return 0;
}

double trig_arc_tangent(double y, double x) {
    return 0;
}
