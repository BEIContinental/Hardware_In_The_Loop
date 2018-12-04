//
// File: Differential.cpp
//
// Code generated for Simulink model 'Differential'.
//
// Model version                  : 1.4
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Fri Jan 26 02:04:11 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Differential.h"
#include "Differential_private.h"

// Model step function
void DifferentialModelClass::step()
{
  real_T tmp;

  // Outputs for Atomic SubSystem: '<Root>/Differential'
  // Switch: '<S1>/Switch' incorporates:
  //   Gain: '<S1>/Efficiency P neg'
  //   Gain: '<S1>/Efficiency P pos'
  //   Inport: '<Root>/PLA_N'
  //   Inport: '<Root>/RA_TQ_ME'
  //   Product: '<S1>/Divide1'

  if (Differential_U.PLA_N * Differential_U.RA_TQ_ME >=
      Differential_P.Switch_Threshold) {
    tmp = Differential_P.ra_transmission_efficiency * Differential_U.RA_TQ_ME;
  } else {
    tmp = (2.0 - Differential_P.ra_transmission_efficiency) *
      Differential_U.RA_TQ_ME;
  }

  // Outport: '<Root>/RA_TQ_&_MINMAX' incorporates:
  //   Gain: '<S1>/Differential ratio'

  Differential_Y.RA_TQ__MINMAX[0] = Differential_P.ra_differential_ratio * tmp;

  // Switch: '<S1>/Switch' incorporates:
  //   Gain: '<S1>/Efficiency P neg'
  //   Gain: '<S1>/Efficiency P pos'
  //   Inport: '<Root>/PLA_N'
  //   Inport: '<Root>/RA_TQ_MIN_ME'
  //   Product: '<S1>/Divide1'

  if (Differential_U.PLA_N * Differential_U.RA_TQ_MIN_ME >=
      Differential_P.Switch_Threshold) {
    tmp = Differential_P.ra_transmission_efficiency *
      Differential_U.RA_TQ_MIN_ME;
  } else {
    tmp = (2.0 - Differential_P.ra_transmission_efficiency) *
      Differential_U.RA_TQ_MIN_ME;
  }

  // Outport: '<Root>/RA_TQ_&_MINMAX' incorporates:
  //   Gain: '<S1>/Differential ratio'

  Differential_Y.RA_TQ__MINMAX[1] = Differential_P.ra_differential_ratio * tmp;

  // Switch: '<S1>/Switch' incorporates:
  //   Gain: '<S1>/Efficiency P neg'
  //   Gain: '<S1>/Efficiency P pos'
  //   Inport: '<Root>/PLA_N'
  //   Inport: '<Root>/RA_TQ_MAX_ME'
  //   Product: '<S1>/Divide1'

  if (Differential_U.PLA_N * Differential_U.RA_TQ_MAX_ME >=
      Differential_P.Switch_Threshold) {
    tmp = Differential_P.ra_transmission_efficiency *
      Differential_U.RA_TQ_MAX_ME;
  } else {
    tmp = (2.0 - Differential_P.ra_transmission_efficiency) *
      Differential_U.RA_TQ_MAX_ME;
  }

  // Outport: '<Root>/RA_TQ_&_MINMAX' incorporates:
  //   Gain: '<S1>/Differential ratio'

  Differential_Y.RA_TQ__MINMAX[2] = Differential_P.ra_differential_ratio * tmp;

  // Outport: '<Root>/RA_N_EM' incorporates:
  //   Gain: '<S1>/differential ratio'
  //   Inport: '<Root>/PLA_N'

  Differential_Y.RA_N_EM = Differential_P.ra_differential_ratio *
    Differential_U.PLA_N;

  // End of Outputs for SubSystem: '<Root>/Differential'
}

// Model initialize function
void DifferentialModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&Differential_M), (NULL));

  // external inputs
  (void) memset((void *)&Differential_U, 0,
                sizeof(ExtU_Differential_T));

  // external outputs
  (void) memset((void *)&Differential_Y, 0,
                sizeof(ExtY_Differential_T));
}

// Model terminate function
void DifferentialModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
DifferentialModelClass::DifferentialModelClass()
{
  static const P_Differential_T Differential_P_temp = {
    10.0,                              // Variable: ra_differential_ratio
                                       //  Referenced by:
                                       //    '<S1>/Differential ratio'
                                       //    '<S1>/differential ratio'

    0.92,                              // Variable: ra_transmission_efficiency
                                       //  Referenced by:
                                       //    '<S1>/Efficiency P neg'
                                       //    '<S1>/Efficiency P pos'

    0.0                                // Expression: 0
                                       //  Referenced by: '<S1>/Switch'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  Differential_P = Differential_P_temp;
}

// Destructor
DifferentialModelClass::~DifferentialModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Differential_T * DifferentialModelClass::getRTM()
{
  return (&Differential_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
