//
// File: ICE_control_private.h
//
// Code generated for Simulink model 'ICE_control'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 02:00:31 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ICE_control_private_h_
#define RTW_HEADER_ICE_control_private_h_
#include "rtwtypes.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);

#endif                                 // RTW_HEADER_ICE_control_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
