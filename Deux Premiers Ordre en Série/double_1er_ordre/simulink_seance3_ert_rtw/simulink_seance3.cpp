/*
 * File: simulink_seance3.cpp
 *
 * Code generated for Simulink model 'simulink_seance3'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Wed Jan 13 15:35:42 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simulink_seance3.h"
#include "simulink_seance3_private.h"

/* Block states (auto storage) */
DW_simulink_seance3_T simulink_seance3_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_simulink_seance3_T simulink_seance3_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_simulink_seance3_T simulink_seance3_Y;

/* Real-time model */
RT_MODEL_simulink_seance3_T simulink_seance3_M_;
RT_MODEL_simulink_seance3_T *const simulink_seance3_M = &simulink_seance3_M_;

/* Model step function */
void simulink_seance3_step(void)
{
  real_T rtb_H2;
  real_T rtb_H;
  real_T H_tmp;
  real_T H2_tmp;

  /* DiscreteTransferFcn: '<S1>/H' incorporates:
   *  Gain: '<S1>/K'
   *  Inport: '<Root>/u'
   *  Sum: '<S1>/Add'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  H_tmp = (simulink_seance3_U.u - simulink_seance3_DW.UnitDelay_DSTATE) *
    simulink_seance3_P.Ka - -0.99 * simulink_seance3_DW.H_states;
  rtb_H = 0.0 * simulink_seance3_DW.H_states + H_tmp;

  /* DiscreteTransferFcn: '<S2>/H2' incorporates:
   *  Gain: '<S2>/K1'
   *  Sum: '<S2>/Add1'
   *  UnitDelay: '<S2>/Unit Delay2'
   */
  H2_tmp = (rtb_H - simulink_seance3_DW.UnitDelay2_DSTATE) *
    simulink_seance3_P.Kb - -0.99 * simulink_seance3_DW.H2_states;
  rtb_H2 = 0.0 * simulink_seance3_DW.H2_states + H2_tmp;

  /* Outport: '<Root>/y_sortie' */
  simulink_seance3_Y.y_sortie = rtb_H2;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  simulink_seance3_DW.UnitDelay_DSTATE = rtb_H;

  /* Update for DiscreteTransferFcn: '<S1>/H' */
  simulink_seance3_DW.H_states = H_tmp;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  simulink_seance3_DW.UnitDelay2_DSTATE = rtb_H2;

  /* Update for DiscreteTransferFcn: '<S2>/H2' */
  simulink_seance3_DW.H2_states = H2_tmp;  
}

/* Model initialize function */
void simulink_seance3_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(simulink_seance3_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&simulink_seance3_DW, 0,
                sizeof(DW_simulink_seance3_T));

  /* external inputs */
  simulink_seance3_U.u = 0.0;

  /* external outputs */
  simulink_seance3_Y.y_sortie = 0.0;
}

/* Model terminate function */
void simulink_seance3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
