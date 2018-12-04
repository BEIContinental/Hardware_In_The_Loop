/* Source code to ensure the traffic on CAN bus is with 16 bits type.
 * Designed by Nicolas Berling
 * January 2018
*/

#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

class FixedPoint {
public:
    FixedPoint();
    ~FixedPoint();
    
    uint16_t to_can_u16(float val, float max, float min);
    int16_t to_can_s16(float val, float max, float min);
    float from_can_u16(uint16_t n, float max, float min);
    float from_can_s16(int16_t n, float max, float min);
    
private:
    float q;
};

#endif
