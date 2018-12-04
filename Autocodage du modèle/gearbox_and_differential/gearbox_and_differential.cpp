//
// File: gearbox_and_differential.cpp
//
// Code generated for Simulink model 'gearbox_and_differential'.
//
// Model version                  : 1.2
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 02:56:48 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "gearbox_and_differential.h"
#include "gearbox_and_differential_private.h"

// Model step function
void gearbox_and_differentialModelClass::step()
{
  real_T rtb_differentialratio;
  real_T tmp;

  // Outputs for Atomic SubSystem: '<Root>/gearbox_and_differential'
  // LookupNDDirect: '<S1>/ gear_ratio' incorporates:
  //   Inport: '<Root>/DRI_GBX_SP'
  //
  //  About '<S1>/ gear_ratio':
  //   1-dimensional Direct Look-Up returning a Scalar

  if (gearbox_and_differential_U.DRI_GBX_SP > 6.0) {
    tmp = 6.0;
  } else if (gearbox_and_differential_U.DRI_GBX_SP < 0.0) {
    tmp = 0.0;
  } else {
    tmp = gearbox_and_differential_U.DRI_GBX_SP;
  }

  // Gain: '<S1>/differential ratio' incorporates:
  //   LookupNDDirect: '<S1>/ gear_ratio'
  //
  //  About '<S1>/ gear_ratio':
  //   1-dimensional Direct Look-Up returning a Scalar

  rtb_differentialratio = 3.72 *
    gearbox_and_differential_ConstP.gear_ratio_table[(int32_T)tmp];

  // LookupNDDirect: '<S1>/ gear_ratio' incorporates:
  //   Inport: '<Root>/DRI_GBX_SP'
  //
  //  About '<S1>/ gear_ratio':
  //   1-dimensional Direct Look-Up returning a Scalar

  if (gearbox_and_differential_U.DRI_GBX_SP > 6.0) {
    tmp = 6.0;
  } else if (gearbox_and_differential_U.DRI_GBX_SP < 0.0) {
    tmp = 0.0;
  } else {
    tmp = gearbox_and_differential_U.DRI_GBX_SP;
  }

  // Switch: '<S1>/Switch1' incorporates:
  //   LookupNDDirect: '<S1>/ gear_ratio'
  //
  //  About '<S1>/ gear_ratio':
  //   1-dimensional Direct Look-Up returning a Scalar

  if (gearbox_and_differential_ConstP.gear_ratio_table[(int32_T)tmp] != 0.0) {
    // Switch: '<S1>/Switch' incorporates:
    //   Gain: '<S1>/Efficiency P neg'
    //   Gain: '<S1>/Efficiency P pos'
    //   Inport: '<Root>/FA_TQ_AND_MINMAX_ICE'
    //   Inport: '<Root>/PLA_N'
    //   Product: '<S1>/Divide1'

    if (gearbox_and_differential_U.PLA_N *
        gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[0] >= 0.0) {
      tmp = 0.92 * gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[0];
    } else {
      tmp = 1.08 * gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[0];
    }

    // Outport: '<Root>/FA_TQ_AND_MINMAX' incorporates:
    //   Product: '<S1>/Divide2'

    gearbox_and_differential_Y.FA_TQ_AND_MINMAX[0] = tmp * rtb_differentialratio;

    // Switch: '<S1>/Switch' incorporates:
    //   Gain: '<S1>/Efficiency P neg'
    //   Gain: '<S1>/Efficiency P pos'
    //   Inport: '<Root>/FA_TQ_AND_MINMAX_ICE'
    //   Inport: '<Root>/PLA_N'
    //   Product: '<S1>/Divide1'

    if (gearbox_and_differential_U.PLA_N *
        gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[1] >= 0.0) {
      tmp = 0.92 * gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[1];
    } else {
      tmp = 1.08 * gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[1];
    }

    // Outport: '<Root>/FA_TQ_AND_MINMAX' incorporates:
    //   Product: '<S1>/Divide2'

    gearbox_and_differential_Y.FA_TQ_AND_MINMAX[1] = tmp * rtb_differentialratio;

    // Switch: '<S1>/Switch' incorporates:
    //   Gain: '<S1>/Efficiency P neg'
    //   Gain: '<S1>/Efficiency P pos'
    //   Inport: '<Root>/FA_TQ_AND_MINMAX_ICE'
    //   Inport: '<Root>/PLA_N'
    //   Product: '<S1>/Divide1'

    if (gearbox_and_differential_U.PLA_N *
        gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[2] >= 0.0) {
      tmp = 0.92 * gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[2];
    } else {
      tmp = 1.08 * gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[2];
    }

    // Outport: '<Root>/FA_TQ_AND_MINMAX' incorporates:
    //   Product: '<S1>/Divide2'

    gearbox_and_differential_Y.FA_TQ_AND_MINMAX[2] = tmp * rtb_differentialratio;
  } else {
    // Outport: '<Root>/FA_TQ_AND_MINMAX'
    gearbox_and_differential_Y.FA_TQ_AND_MINMAX[0] = 0.0;
    gearbox_and_differential_Y.FA_TQ_AND_MINMAX[1] = 0.0;
    gearbox_and_differential_Y.FA_TQ_AND_MINMAX[2] = 0.0;
  }

  // End of Switch: '<S1>/Switch1'

  // LookupNDDirect: '<S1>/ gear_ratio' incorporates:
  //   Inport: '<Root>/DRI_GBX_SP'
  //
  //  About '<S1>/ gear_ratio':
  //   1-dimensional Direct Look-Up returning a Scalar

  if (gearbox_and_differential_U.DRI_GBX_SP > 6.0) {
    tmp = 6.0;
  } else if (gearbox_and_differential_U.DRI_GBX_SP < 0.0) {
    tmp = 0.0;
  } else {
    tmp = gearbox_and_differential_U.DRI_GBX_SP;
  }

  // Switch: '<S1>/Switch2' incorporates:
  //   LookupNDDirect: '<S1>/ gear_ratio'
  //
  //  About '<S1>/ gear_ratio':
  //   1-dimensional Direct Look-Up returning a Scalar

  if (gearbox_and_differential_ConstP.gear_ratio_table[(int32_T)tmp] != 0.0) {
    // Outport: '<Root>/FA_N_GBX' incorporates:
    //   Inport: '<Root>/PLA_N'
    //   Product: '<S1>/Product1'

    gearbox_and_differential_Y.FA_N_GBX = rtb_differentialratio *
      gearbox_and_differential_U.PLA_N;
  } else {
    // Outport: '<Root>/FA_N_GBX' incorporates:
    //   Inport: '<Root>/FA_N_ICE'

    gearbox_and_differential_Y.FA_N_GBX = gearbox_and_differential_U.FA_N_ICE;
  }

  // End of Switch: '<S1>/Switch2'
  // End of Outputs for SubSystem: '<Root>/gearbox_and_differential'
}

// Model initialize function
void gearbox_and_differentialModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&gearbox_and_differential_M), (NULL));

  // external inputs
  (void) memset((void *)&gearbox_and_differential_U, 0,
                sizeof(ExtU_gearbox_and_differential_T));

  // external outputs
  (void) memset((void *)&gearbox_and_differential_Y, 0,
                sizeof(ExtY_gearbox_and_differential_T));
}

// Model terminate function
void gearbox_and_differentialModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
gearbox_and_differentialModelClass::gearbox_and_differentialModelClass()
{
}

// Destructor
gearbox_and_differentialModelClass::~gearbox_and_differentialModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_gearbox_and_differen_T * gearbox_and_differentialModelClass::getRTM()
{
  return (&gearbox_and_differential_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
