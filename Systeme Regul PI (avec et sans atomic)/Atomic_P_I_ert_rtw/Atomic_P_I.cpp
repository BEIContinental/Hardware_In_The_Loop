/*
 * File: Atomic_P_I.cpp
 *
 * Code generated for Simulink model 'Atomic_P_I'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Fri Jan 22 10:35:09 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Atomic_P_I.h"
#include "Atomic_P_I_private.h"

/* Block signals (auto storage) */
B_Atomic_P_I_T Atomic_P_I_B;

/* Block states (auto storage) */
DW_Atomic_P_I_T Atomic_P_I_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Atomic_P_I_T Atomic_P_I_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Atomic_P_I_T Atomic_P_I_Y;

/* Real-time model */
RT_MODEL_Atomic_P_I_T Atomic_P_I_M_;
RT_MODEL_Atomic_P_I_T *const Atomic_P_I_M = &Atomic_P_I_M_;

/* Model step function */
void Atomic_P_I_step(void)
{
  real_T rtb_Systeme;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem=Systeme' */
  /* DiscreteTransferFcn: '<S1>/Systeme' */
  rtb_Systeme = 0.0369 * Atomic_P_I_DW.Systeme_states[0] + 0.0302 *
    Atomic_P_I_DW.Systeme_states[1];

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/y' */
  Atomic_P_I_Y.y = rtb_Systeme;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem1=PI+sum' */
  /* Sum: '<S2>/Sum' incorporates:
   *  Inport: '<Root>/x'
   */
  rtb_Systeme = Atomic_P_I_U.x - rtb_Systeme;

  /* DiscreteTransferFcn: '<S2>/PI' */
  rtb_Systeme -= -Atomic_P_I_DW.PI_states;
  Atomic_P_I_B.PI = 0.25 * rtb_Systeme + -0.175 * Atomic_P_I_DW.PI_states;

  /* Update for DiscreteTransferFcn: '<S2>/PI' */
  Atomic_P_I_DW.PI_states = rtb_Systeme;

  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* Update for Atomic SubSystem: '<Root>/Subsystem' */
  /* Update for DiscreteTransferFcn: '<S1>/Systeme' */
  rtb_Systeme = (Atomic_P_I_B.PI - -1.4816 * Atomic_P_I_DW.Systeme_states[0]) -
    0.5488 * Atomic_P_I_DW.Systeme_states[1];
  Atomic_P_I_DW.Systeme_states[1] = Atomic_P_I_DW.Systeme_states[0];
  Atomic_P_I_DW.Systeme_states[0] = rtb_Systeme;

  /* End of Update for SubSystem: '<Root>/Subsystem' */
}

/* Model initialize function */
void Atomic_P_I_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Atomic_P_I_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Atomic_P_I_B), 0,
                sizeof(B_Atomic_P_I_T));

  /* states (dwork) */
  (void) memset((void *)&Atomic_P_I_DW, 0,
                sizeof(DW_Atomic_P_I_T));

  /* external inputs */
  Atomic_P_I_U.x = 0.0;

  /* external outputs */
  Atomic_P_I_Y.y = 0.0;
}

/* Model terminate function */
void Atomic_P_I_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
