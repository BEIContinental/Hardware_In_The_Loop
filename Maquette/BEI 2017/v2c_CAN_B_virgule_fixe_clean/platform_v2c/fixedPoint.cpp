/* Source code to ensure the traffic on CAN bus is with 16 bits type.
 * Designed by Nicolas Berling
 * January 2018
*/

#include "fixedPoint.hpp"

#define NB_BITS 16

FixedPoint::FixedPoint() {
}

FixedPoint::~FixedPoint() {
}

uint16_t FixedPoint::to_can_u16(float val, float max, float min) {
    uint32_t n;
    
    q = max/(pow(2, NB_BITS) - 1);
    //printf("q = %f\n", q);
    n = (uint32_t) floor(val/q);
    //printf("n = %" PRIu32 "\n", n);
    
    if (n > pow(2, NB_BITS)) {
        n = (uint16_t) pow(2, NB_BITS);
    }
    else if (n < 0) {
        n = (uint16_t) 0;
    }
    else {
        n = (uint16_t) n;
    }
    
    return n;
}

int16_t FixedPoint::to_can_s16(float val, float max, float min) {
    float max_abs;
    int32_t n;
    
    max_abs = abs(max);
    if (abs(min) > max_abs) {
        max_abs = abs(min);
    }
    
    q = max_abs/(pow(2, NB_BITS-1) - 1);
    //printf("q = %f\n", q);
    n = (int32_t) floor(val/q);
    //printf("n = %" PRId32 "\n", n);
    
    if (n > pow(2, NB_BITS - 1) - 1) {
        n = (int16_t) pow(2, NB_BITS - 1) - 1;
    }
    else if (n < -pow(2, NB_BITS - 1)) {
        n = (int16_t) -pow(2, NB_BITS - 1);
    }
    else {
        n = (int16_t) n;
    }
    
    return n;
}

float FixedPoint::from_can_u16(uint16_t n, float max, float min) {
    float val;
    
    q = max/(pow(2, NB_BITS) - 1);
    //printf("q = %f\n", q);
    val = (float) n*q;
    
    return val;
}

float FixedPoint::from_can_s16(int16_t n, float max, float min) {
    float max_abs;
    float val;
    
    max_abs = abs(max);
    if (abs(min) > max_abs) {
        max_abs = abs(min);
    }
    
    q = max_abs/(pow(2, NB_BITS-1) - 1);
    //printf("q = %f\n", q);
    val = (float) n*q;
    
    return val;
}
