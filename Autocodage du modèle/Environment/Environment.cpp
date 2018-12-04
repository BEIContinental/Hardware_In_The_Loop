//
// File: Environment.cpp
//
// Code generated for Simulink model 'Environment'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 07:16:30 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Environment.h"
#include "Environment_private.h"

// Model step function
void EnvironmentModelClass::step()
{
  // Outport: '<Root>/Slope[%]' incorporates:
  //   Constant: '<S1>/Constant2'

  Environment_Y.Slope = 0.0;

  // Outport: '<Root>/F_ext' incorporates:
  //   Constant: '<S1>/Constant'

  Environment_Y.F_ext = 0.0;

  // Outport: '<Root>/Wind' incorporates:
  //   Constant: '<S1>/Constant1'

  Environment_Y.Wind = 0.0;
}

// Model initialize function
void EnvironmentModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&Environment_M), (NULL));

  // external outputs
  (void) memset((void *)&Environment_Y, 0,
                sizeof(ExtY_Environment_T));
}

// Model terminate function
void EnvironmentModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
EnvironmentModelClass::EnvironmentModelClass()
{
}

// Destructor
EnvironmentModelClass::~EnvironmentModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Environment_T * EnvironmentModelClass::getRTM()
{
  return (&Environment_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
