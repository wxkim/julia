#include "pmath.h"
#include <math.h>


static double LOOKUP_TABLE[LUT_SIZE + 1];

__attribute__((constructor)) 
static void init_lookup_table(void) {
    for (int i = 0; i <= LUT_SIZE; ++i) {
        LOOKUP_TABLE[i] = sin(i * LUT_STEP);
    }
}

static fp_reserved_status_t check_reserve_value(double x) {
    flop64_t in;
    in.val = x;
    
    uint8_t sign        = (uint8_t)(in.bits & SIGN_BIT_MASK) >> 63;
    uint16_t exponent   = (uint16_t)(in.bits & EXPN_BIT_MASK) >> 52;
    uint64_t mantissa   = (uint64_t)(in.bits & MANT_BIT_MASK);

    if (exponent == 0) {
        if (mantissa == 0) 
            return sign ? MINUS_ZERO : PLUS_ZERO;
        else 
            return DENORMAL_VALUE;
    } 
    
    else if (exponent == 0x7FFU) {
        if (mantissa == 0U) {
            return (sign != 0U) ? MINUS_INFINITY : PLUS_INFINITY;
        } 
        
        else { 
            uint64_t qnan_bit = 0x0008000000000000ULL;
            return ((mantissa & qnan_bit) != 0ULL) ? QUIET_NAN : SIGNALING_NAN;
        }
    }
    }

    return NORMAL_VALUE;
}

double absolute(double x) {
    flop64_t f;
    f.val = x;
    f.bits &= ~SIGN_BIT_MASK;  
    return f.val;
}

double reverse_absolute(double x) {
    flop64_t f;
    f.val = x;
    f.bits ^= ~SIGN_BIT_MASK;  
    return f.val;
}

double square_root(double x) {
    flop64_t seed;
    double val = x;

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

    res = res * (1.5 - xHalf * res * res);
    res = res * (1.5 - xHalf * res * res);

    return res = res * (1.5 - xHalf * res * res);
}

double base_power(double base, int exp) {
    double res = 1.0;

    int negate = (exp < 0);
    if (negate) exp = -exp;

    while (exp) {
        if(exp & 1) res *= base;

        base *= base;
        exp >>= 1;
    }

    return negate ? 1.0 / res : res;
}





double trig_sine(double angle_rad) {
    angle_rad = reduce_range_radians(angle_rad);

    double index_f = angle_rad / LUT_STEP;
    int index = (int)index_f;

    double frac = index_f - index;
    if (index >= LUT_SIZE) {
        index = LUT_SIZE - 1;
        frac = 1.0;  
    }
    double y0 = LOOKUP_TABLE[index];
    double y1 = LOOKUP_TABLE[index + 1];

    return y0 + frac * (y1 - y0);
}

double trig_cosine(double angle_rad) {
    return trig_sine(angle_rad + HALFPI);
}

double trig_tangent(double angle_rad) {
    double cos = trig_cosine(angle_rad);
    if (absolute(cos) < 1e-8) return PLUS_INFINITY;
    return trig_sine(angle_rad) / cos;
}

double trig_arc_tangent(double y, double x) {
    return atan2(y,x);
}

inline double reduce_range_radians(double rad) {
    rad -= TAU * (int) (rad / TAU);
    return rad < 0 ? rad + TAU : rad;
}

inline double reduce_range_degrees(double deg) {
    deg -= 360 * (int) (deg / 360);
    return deg < 0 ? deg + 360 : deg;
}

inline double dg_to_rad(double dg) {
    return dg * PI / 180;
}

inline double rad_to_dg(double rad) {
    return rad * 180 / PI;
}