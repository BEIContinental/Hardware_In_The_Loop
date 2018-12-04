/*
 * File: platform.cpp
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

/* Block states (auto storage) */
DW_platform_T platform_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_platform_T platform_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_platform_T platform_Y;

/*******************************************************************************************************************************/
/*/ truc rajouté a cause d'un probleme de linking
On a besoin de définir platform_P et il est juste déclarer
Pourtant ça marche avec visual studio
/*/
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
/*******************************************************************************************************************************/

/* Real-time model */
RT_MODEL_platform_T platform_M_;
RT_MODEL_platform_T *const platform_M = &platform_M_;

/* Model step function */
void platform_step(void)
{
  /* local block i/o variables */
  real_T rtb_Delay;
  real_T rtb_Abs1;
  real_T rtb_Abs;
  real_T rtb_Switch;
  real_T rtb_Product;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;

  /* Delay: '<S2>/Delay' */
  rtb_Delay = platform_DW.Delay_DSTATE;

  /* DiscreteZeroPole: '<S2>/Discrete Zero-Pole' */
  {
    rtb_Abs1 = 1.0*rtb_Delay;
    rtb_Abs1 += 2.0*platform_DW.DiscreteZeroPole_DSTATE;
  }

  /* Outport: '<Root>/PLA_SPEED' incorporates:
   *  Gain: '<S1>/Gain'
   */
  platform_Y.PLA_SPEED = 3.6 * rtb_Abs1;

  /* Outport: '<Root>/PLA_N' incorporates:
   *  Gain: '<S1>/m//s -> tr//min'
   */
  platform_Y.PLA_N = 60.0 / (6.2831853071795862 * platform_P.pla_wheel_radius) *
    rtb_Abs1;

  /* Abs: '<S3>/Abs' */
  rtb_Abs = fabs(rtb_Abs1);

  /* Sum: '<S4>/Sum' incorporates:
   *  Inport: '<Root>/WIND'
   */
  rtb_Switch = rtb_Abs1 + platform_U.Wind;

  /* Product: '<S4>/Product' */
  rtb_Product = rtb_Switch * rtb_Switch;

  /* Abs: '<S7>/Abs' */
  rtb_Switch = fabs(rtb_Abs1);

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant2'
   *  Gain: '<S7>/Gain1'
   *  Sum: '<S7>/Sum'
   */
  if (rtb_Switch > 0.01) {
    rtb_Switch = platform_P.pla_k * 9.80665 * platform_P.pla_equivalent_weight *
      rtb_Switch + 9.80665 * platform_P.pla_equivalent_weight * platform_P.pla_f;
  } else {
    rtb_Switch = 9.80665 * platform_P.pla_equivalent_weight * platform_P.pla_f *
      platform_P.pla_csat;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Signum: '<S4>/Sign' */
  if (rtb_Abs1 < 0.0) {
    tmp = -1.0;
  } else if (rtb_Abs1 > 0.0) {
    tmp = 1.0;
  } else if (rtb_Abs1 == 0.0) {
    tmp = 0.0;
  } else {
    tmp = rtb_Abs1;
  }

  /* Signum: '<S8>/Sign' incorporates:
   *  Inport: '<Root>/SLOPE'
   */
  if (platform_U.Slope < 0.0) {
    tmp_0 = -1.0;
  } else if (platform_U.Slope > 0.0) {
    tmp_0 = 1.0;
  } else if (platform_U.Slope == 0.0) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = platform_U.Slope;
  }

  /* Signum: '<S8>/Sign1' */
  if (rtb_Abs1 < 0.0) {
    tmp_1 = -1.0;
  } else if (rtb_Abs1 > 0.0) {
    tmp_1 = 1.0;
  } else if (rtb_Abs1 == 0.0) {
    tmp_1 = 0.0;
  } else {
    tmp_1 = rtb_Abs1;
  }

  /* Signum: '<S7>/Sign' */
  if (rtb_Abs1 < 0.0) {
    tmp_2 = -1.0;
  } else if (rtb_Abs1 > 0.0) {
    tmp_2 = 1.0;
  } else if (rtb_Abs1 == 0.0) {
    tmp_2 = 0.0;
  } else {
    tmp_2 = rtb_Abs1;
  }

  /* Signum: '<S5>/Sign' */
  if (rtb_Abs1 < 0.0) {
    tmp_3 = -1.0;
  } else if (rtb_Abs1 > 0.0) {
    tmp_3 = 1.0;
  } else if (rtb_Abs1 == 0.0) {
    tmp_3 = 0.0;
  } else {
    tmp_3 = rtb_Abs1;
  }

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain3'
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S7>/Gain'
   *  Gain: '<S8>/Gain'
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain2'
   *  Inport: '<Root>/CMD_BRAKE_SP'
   *  Inport: '<Root>/FA_TQ'
   *  Inport: '<Root>/F_EXT'
   *  Inport: '<Root>/RA_TQ'
   *  Inport: '<Root>/SLOPE'
   *  Product: '<S4>/Product1'
   *  Product: '<S5>/Product1'
   *  Product: '<S7>/Product'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Signum: '<S4>/Sign'
   *  Signum: '<S5>/Sign'
   *  Signum: '<S7>/Sign'
   *  Signum: '<S8>/Sign'
   *  Signum: '<S8>/Sign1'
   *  Sum: '<S1>/Sum'
   *  Trigonometry: '<S8>/Trigonometric Function'
   *  Trigonometry: '<S8>/Trigonometric Function1'
   */
  rtb_Switch = ((((1.0 / platform_P.pla_wheel_radius * (platform_U.FA_TQ +
    platform_U.RA_TQ) + -(platform_P.pla_kaero * rtb_Product * tmp)) + -(9.80665
    * platform_P.pla_equivalent_weight * sin(atan(0.01 * platform_U.Slope)) *
    (tmp_0 * tmp_1))) + -(rtb_Switch * tmp_2)) + -(platform_P.pla_max_f_brakes /
    platform_P.pla_wheel_radius * (0.01 * platform_U.CMD_BRAKE_SP) * tmp_3)) +
    platform_U.F_ext;

  /* Abs: '<S3>/Abs1' */
  rtb_Abs1 = fabs(rtb_Switch);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S9>/Constant'
   *  Gain: '<S2>/Gain'
   *  Logic: '<S3>/Logical Operator'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  if ((rtb_Abs <= 0.01) && (rtb_Abs1 <= 9.80665 *
       platform_P.pla_equivalent_weight * platform_P.pla_f * platform_P.pla_csat))
  {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch *= 1.0 / platform_P.pla_equivalent_weight;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  Gain: '<S2>/Gain7'
   */
  platform_DW.Delay_DSTATE = platform_P.hev_dt / 2.0 * rtb_Switch;

  /* Update for DiscreteZeroPole: '<S2>/Discrete Zero-Pole' */
  {
    platform_DW.DiscreteZeroPole_DSTATE = rtb_Delay + 1.0*
      platform_DW.DiscreteZeroPole_DSTATE;
  }
}

/* Model initialize function */
void platform_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(platform_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&platform_DW, 0,
                sizeof(DW_platform_T));

  /* external inputs */
  (void) memset((void *)&platform_U, 0,
                sizeof(ExtU_platform_T));

  /* external outputs */
  (void) memset((void *)&platform_Y, 0,
                sizeof(ExtY_platform_T));
}

/* Model terminate function */
void platform_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
