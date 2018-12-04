//
// File: RA_TQ_to_F_BRAKE.cpp
//
// Code generated for Simulink model 'RA_TQ_to_F_BRAKE'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Fri Jan 26 01:23:45 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "RA_TQ_to_F_BRAKE.h"
#include "RA_TQ_to_F_BRAKE_private.h"

// Model step function
void RA_TQ_to_F_BRAKEModelClass::step()
{
  // Outputs for Atomic SubSystem: '<Root>/RA_TQ_to_F_BRAKE'
  // Outport: '<Root>/RA_PLA_F_BRAKE' incorporates:
  //   Gain: '<S1>/Gain'
  //   Inport: '<Root>/CMD_RA_MECANICAL_BRAKE'

  RA_TQ_to_F_BRAKE_Y.RA_PLA_F_BRAKE = 1.0 / RA_TQ_to_F_BRAKE_P.pla_wheel_radius *
    RA_TQ_to_F_BRAKE_U.CMD_RA_MECHANICAL_BRAKE;

  // End of Outputs for SubSystem: '<Root>/RA_TQ_to_F_BRAKE'
}

// Model initialize function
void RA_TQ_to_F_BRAKEModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&RA_TQ_to_F_BRAKE_M), (NULL));

  // external inputs
  RA_TQ_to_F_BRAKE_U.CMD_RA_MECHANICAL_BRAKE = 0.0;

  // external outputs
  RA_TQ_to_F_BRAKE_Y.RA_PLA_F_BRAKE = 0.0;
}

// Model terminate function
void RA_TQ_to_F_BRAKEModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
RA_TQ_to_F_BRAKEModelClass::RA_TQ_to_F_BRAKEModelClass()
{
  static const P_RA_TQ_to_F_BRAKE_T RA_TQ_to_F_BRAKE_P_temp = {
    0.314                              // Variable: pla_wheel_radius
                                       //  Referenced by: '<S1>/Gain'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  RA_TQ_to_F_BRAKE_P = RA_TQ_to_F_BRAKE_P_temp;
}

// Destructor
RA_TQ_to_F_BRAKEModelClass::~RA_TQ_to_F_BRAKEModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_RA_TQ_to_F_BRAKE_T * RA_TQ_to_F_BRAKEModelClass::getRTM()
{
  return (&RA_TQ_to_F_BRAKE_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
