/*
 * File: simulink_seance4_2sorties.h
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

#ifndef RTW_HEADER_simulink_seance4_2sorties_h_
#define RTW_HEADER_simulink_seance4_2sorties_h_
#ifndef simulink_seance4_2sorties_COMMON_INCLUDES_
# define simulink_seance4_2sorties_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* simulink_seance4_2sorties_COMMON_INCLUDES_ */

#include "simulink_seance4_2sorties_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T H_states;                     /* '<Root>/H' */
  real_T UnitDelay2_DSTATE;            /* '<S2>/Unit Delay2' */
  real_T H2_states;                    /* '<S2>/H2' */
  real_T UnitDelay_DSTATE_d;           /* '<S1>/Unit Delay' */
  real_T H_states_b;                   /* '<S1>/H' */
} DW_simulink_seance4_2sorties_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T u;                            /* '<Root>/u' */
} ExtU_simulink_seance4_2sortie_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T y_sortie1;                    /* '<Root>/y_sortie1 ' */
  real_T y_sortie2;                    /* '<Root>/y_sortie2' */
} ExtY_simulink_seance4_2sortie_T;

/* Parameters (auto storage) */
struct P_simulink_seance4_2sorties_T_ {
  real_T Ka;                           /* Variable: Ka
                                        * Referenced by: '<S1>/K'
                                        */
  real_T Kb;                           /* Variable: Kb
                                        * Referenced by: '<S2>/K1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_simulink_seance4_2sor_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_simulink_seance4_2sorties_T simulink_seance4_2sorties_P;

#ifdef __cplusplus

}
#endif

/* Block states (auto storage) */
extern DW_simulink_seance4_2sorties_T simulink_seance4_2sorties_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with auto storage) */
  extern ExtU_simulink_seance4_2sortie_T simulink_seance4_2sorties_U;

  /* External outputs (root outports fed by signals with auto storage) */
  extern ExtY_simulink_seance4_2sortie_T simulink_seance4_2sorties_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void simulink_seance4_2sorties_initialize(void);
  extern void simulink_seance4_2sorties_step(void);
  extern void simulink_seance4_2sorties_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_simulink_seance4_2so_T *const simulink_seance4_2sorties_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'simulink_seance4_2sorties'
 * '<S1>'   : 'simulink_seance4_2sorties/1er_bloc'
 * '<S2>'   : 'simulink_seance4_2sorties/2eme_bloc'
 */
#endif                                 /* RTW_HEADER_simulink_seance4_2sorties_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
