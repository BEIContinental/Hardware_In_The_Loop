//
// File: simulink_testcode.cpp
//
// Code generated for Simulink model 'simulink_testcode'.
//
// Model version                  : 1.26
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Tue Dec  5 17:16:55 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "simulink_testcode.h"
#include "simulink_testcode_private.h"

// Model step function
void simulink_testcodeModelClass::step()
{
  real_T rtb_H;
  real_T H_tmp;

  // DiscreteTransferFcn: '<Root>/H' incorporates:
  //   Gain: '<Root>/K'
  //   Inport: '<Root>/u'
  //   Sum: '<Root>/Add'
  //   UnitDelay: '<Root>/Unit Delay'

  H_tmp = (simulink_testcode_U.u - simulink_testcode_DW.UnitDelay_DSTATE) *
    simulink_testcode_P.ka - -0.99 * simulink_testcode_DW.H_states;
  rtb_H = 0.0 * simulink_testcode_DW.H_states + H_tmp;

  // Outport: '<Root>/y'
  simulink_testcode_Y.y = rtb_H;

  // Update for UnitDelay: '<Root>/Unit Delay'
  simulink_testcode_DW.UnitDelay_DSTATE = rtb_H;

  // Update for DiscreteTransferFcn: '<Root>/H'
  simulink_testcode_DW.H_states = H_tmp;
}

// Model initialize function
void simulink_testcodeModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(getRTM(), (NULL));

  // states (dwork)
  (void) memset((void *)&simulink_testcode_DW, 0,
                sizeof(DW_simulink_testcode_T));

  // external inputs
  simulink_testcode_U.u = 0.0;

  // external outputs
  simulink_testcode_Y.y = 0.0;
}

// Model terminate function
void simulink_testcodeModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
simulink_testcodeModelClass::simulink_testcodeModelClass()
{
  static const P_simulink_testcode_T simulink_testcode_P_temp = {
    0.1                                // Variable: ka
                                       //  Referenced by: '<Root>/K'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  simulink_testcode_P = simulink_testcode_P_temp;
}

// Destructor
simulink_testcodeModelClass::~simulink_testcodeModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_simulink_testcode_T * simulink_testcodeModelClass::getRTM()
{
  return (&simulink_testcode_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
