/*
 * File: platform_data.cpp
 *
 * Code generated for Simulink model 'platform'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Feb 17 11:51:33 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "platform.h"
#include "platform_private.h"

/* Block parameters (auto storage) */
P_platform_T platform_P = {
  0.01,                                /* Variable: hev_dt
                                        * Referenced by: '<S2>/Gain7'
                                        */
  1.2,                                 /* Variable: pla_csat
                                        * Referenced by:
                                        *   '<S7>/Constant2'
                                        *   '<S10>/Constant'
                                        */
  1250.0,                              /* Variable: pla_equivalent_weight
                                        * Referenced by:
                                        *   '<S2>/Gain'
                                        *   '<S7>/Constant'
                                        *   '<S7>/Constant2'
                                        *   '<S7>/Gain1'
                                        *   '<S8>/Gain2'
                                        *   '<S10>/Constant'
                                        */
  0.0035272,                           /* Variable: pla_f
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S7>/Constant2'
                                        *   '<S10>/Constant'
                                        */
  0.0002318,                           /* Variable: pla_k
                                        * Referenced by: '<S7>/Gain1'
                                        */
  0.52992,                             /* Variable: pla_kaero
                                        * Referenced by: '<S4>/Gain1'
                                        */
  1000.0,                              /* Variable: pla_max_f_brakes
                                        * Referenced by: '<S5>/Gain1'
                                        */
  0.314                                /* Variable: pla_wheel_radius
                                        * Referenced by:
                                        *   '<S1>/m//s -> tr//min'
                                        *   '<S5>/Gain1'
                                        *   '<S6>/Gain1'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
