//
// File: ICE_private.h
//
// Code generated for Simulink model 'ICE'.
//
// Model version                  : 1.5
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Thu Jan 25 15:29:09 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ICE_private_h_
#define RTW_HEADER_ICE_private_h_
#include "rtwtypes.h"

extern real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look2_binlcapw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);

#endif                                 // RTW_HEADER_ICE_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
