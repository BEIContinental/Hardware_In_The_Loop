/*
 * File: simulink_seance4_2sorties.cpp
 *
 * Code generated for Simulink model 'simulink_seance4_2sorties'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Fri Jan 15 09:10:47 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simulink_seance4_2sorties.h"
#include "simulink_seance4_2sorties_private.h"

/* Block states (auto storage) */
DW_simulink_seance4_2sorties_T simulink_seance4_2sorties_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_simulink_seance4_2sortie_T simulink_seance4_2sorties_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_simulink_seance4_2sortie_T simulink_seance4_2sorties_Y;

/* Real-time model */
RT_MODEL_simulink_seance4_2so_T simulink_seance4_2sorties_M_;
RT_MODEL_simulink_seance4_2so_T *const simulink_seance4_2sorties_M =
  &simulink_seance4_2sorties_M_;

/* Model step function */
void simulink_seance4_2sorties_step(void)
{
  real_T rtb_H2;
  real_T rtb_H;
  real_T rtb_H_i;
  real_T H_tmp;
  real_T H2_tmp;

  /* DiscreteTransferFcn: '<Root>/H' incorporates:
   *  Inport: '<Root>/u'
   *  Sum: '<Root>/Add'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  H_tmp = (simulink_seance4_2sorties_U.u -
           simulink_seance4_2sorties_DW.UnitDelay_DSTATE) -
    simulink_seance4_2sorties_DW.H_states;
  rtb_H_i = 10.0 * simulink_seance4_2sorties_DW.H_states + H_tmp;

  /* DiscreteTransferFcn: '<S2>/H2' incorporates:
   *  Gain: '<S2>/K1'
   *  Sum: '<S2>/Add1'
   *  UnitDelay: '<S2>/Unit Delay2'
   */
  H2_tmp = (rtb_H_i - simulink_seance4_2sorties_DW.UnitDelay2_DSTATE) *
    simulink_seance4_2sorties_P.Kb - -0.99 *
    simulink_seance4_2sorties_DW.H2_states;
  rtb_H2 = 0.0 * simulink_seance4_2sorties_DW.H2_states + H2_tmp;

  /* Outport: '<Root>/y_sortie1 ' */
  simulink_seance4_2sorties_Y.y_sortie1 = rtb_H2;

  /* DiscreteTransferFcn: '<S1>/H' incorporates:
   *  Gain: '<S1>/K'
   *  Sum: '<S1>/Add'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_H_i = (rtb_H_i - simulink_seance4_2sorties_DW.UnitDelay_DSTATE_d) *
    simulink_seance4_2sorties_P.Ka - -0.99 *
    simulink_seance4_2sorties_DW.H_states_b;
  rtb_H = 0.0 * simulink_seance4_2sorties_DW.H_states_b + rtb_H_i;

  /* Outport: '<Root>/y_sortie2' */
  simulink_seance4_2sorties_Y.y_sortie2 = rtb_H;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  simulink_seance4_2sorties_DW.UnitDelay_DSTATE = rtb_H2;

  /* Update for DiscreteTransferFcn: '<Root>/H' */
  simulink_seance4_2sorties_DW.H_states = H_tmp;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  simulink_seance4_2sorties_DW.UnitDelay2_DSTATE = rtb_H2;

  /* Update for DiscreteTransferFcn: '<S2>/H2' */
  simulink_seance4_2sorties_DW.H2_states = H2_tmp;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  simulink_seance4_2sorties_DW.UnitDelay_DSTATE_d = rtb_H;

  /* Update for DiscreteTransferFcn: '<S1>/H' */
  simulink_seance4_2sorties_DW.H_states_b = rtb_H_i;
}

/* Model initialize function */
void simulink_seance4_2sorties_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(simulink_seance4_2sorties_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&simulink_seance4_2sorties_DW, 0,
                sizeof(DW_simulink_seance4_2sorties_T));

  /* external inputs */
  simulink_seance4_2sorties_U.u = 0.0;

  /* external outputs */
  (void) memset((void *)&simulink_seance4_2sorties_Y, 0,
                sizeof(ExtY_simulink_seance4_2sortie_T));
}

/* Model terminate function */
void simulink_seance4_2sorties_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
