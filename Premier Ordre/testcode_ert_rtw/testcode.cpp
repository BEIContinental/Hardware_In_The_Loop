/*
 * File: testcode.c
 *
 * Code generated for Simulink model 'testcode'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Wed Jan 06 08:49:36 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testcode.h"
#include "testcode_private.h"

/* Block states (auto storage) */
DW_testcode_T testcode_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_testcode_T testcode_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_testcode_T testcode_Y;

/* Real-time model */
RT_MODEL_testcode_T testcode_M_;
RT_MODEL_testcode_T *const testcode_M = &testcode_M_;

/* Model step function */
void testcode_step(void)
{
  real_T rtb_H;
  real_T H_tmp;

  /* DiscreteTransferFcn: '<Root>/H' incorporates:
   *  Gain: '<Root>/K'
   *  Inport: '<Root>/u'
   *  Sum: '<Root>/Add'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  H_tmp = (testcode_U.u - testcode_DW.UnitDelay_DSTATE) * testcode_P.ka - -0.99 *testcode_DW.H_states;
  rtb_H = 0.0 * testcode_DW.H_states + H_tmp;

  /* Outport: '<Root>/y' */
  testcode_Y.y = rtb_H;
  
  testcode_DW.H_states = ((testcode_U.u - testcode_DW.UnitDelay_DSTATE) - 1 * testcode_DW.H_states) /(-0.99);


  /* Update for UnitDelay: '<Root>/Unit Delay' */
  testcode_DW.UnitDelay_DSTATE = rtb_H;

  /* Update for DiscreteTransferFcn: '<Root>/H' */
  testcode_DW.H_states = H_tmp;
}

/* Model initialize function */
void testcode_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(testcode_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&testcode_DW, 0,
                sizeof(DW_testcode_T));

  /* external inputs */
  testcode_U.u = 0.0;

  /* external outputs */
  testcode_Y.y = 0.0;
}

/* Model terminate function */
void testcode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
