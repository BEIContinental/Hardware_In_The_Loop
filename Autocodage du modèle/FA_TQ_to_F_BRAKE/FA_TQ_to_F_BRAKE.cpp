//
// File: FA_TQ_to_F_BRAKE.cpp
//
// Code generated for Simulink model 'FA_TQ_to_F_BRAKE'.
//
// Model version                  : 1.2
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 06:31:15 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FA_TQ_to_F_BRAKE.h"
#include "FA_TQ_to_F_BRAKE_private.h"

// Model step function
void FA_TQ_to_F_BRAKEModelClass::step()
{
  // Outputs for Atomic SubSystem: '<Root>/FA_TQ_to_F_BRAKE'
  // Outport: '<Root>/FA_PLA_F_BRAKE' incorporates:
  //   Gain: '<S1>/Gain'
  //   Inport: '<Root>/CMD_FA_MECANICAL_BRAKE'

  FA_TQ_to_F_BRAKE_Y.FA_PLA_F_BRAKE = 3.1847133757961785 *
    FA_TQ_to_F_BRAKE_U.CMD_FA_MECHANICAL_BRAKE;

  // End of Outputs for SubSystem: '<Root>/FA_TQ_to_F_BRAKE'
}

// Model initialize function
void FA_TQ_to_F_BRAKEModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&FA_TQ_to_F_BRAKE_M), (NULL));

  // external inputs
  FA_TQ_to_F_BRAKE_U.CMD_FA_MECHANICAL_BRAKE = 0.0;

  // external outputs
  FA_TQ_to_F_BRAKE_Y.FA_PLA_F_BRAKE = 0.0;
}

// Model terminate function
void FA_TQ_to_F_BRAKEModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
FA_TQ_to_F_BRAKEModelClass::FA_TQ_to_F_BRAKEModelClass()
{
}

// Destructor
FA_TQ_to_F_BRAKEModelClass::~FA_TQ_to_F_BRAKEModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_FA_TQ_to_F_BRAKE_T * FA_TQ_to_F_BRAKEModelClass::getRTM()
{
  return (&FA_TQ_to_F_BRAKE_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
