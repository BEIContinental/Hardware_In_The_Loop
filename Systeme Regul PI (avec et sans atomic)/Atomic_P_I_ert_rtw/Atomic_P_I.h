/*
 * File: Atomic_P_I.h
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

#ifndef RTW_HEADER_Atomic_P_I_h_
#define RTW_HEADER_Atomic_P_I_h_
#ifndef Atomic_P_I_COMMON_INCLUDES_
# define Atomic_P_I_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* Atomic_P_I_COMMON_INCLUDES_ */

#include "Atomic_P_I_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T PI;                           /* '<S2>/PI' */
} B_Atomic_P_I_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T PI_states;                    /* '<S2>/PI' */
  real_T Systeme_states[2];            /* '<S1>/Systeme' */
} DW_Atomic_P_I_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T x;                            /* '<Root>/x' */
} ExtU_Atomic_P_I_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T y;                            /* '<Root>/y' */
} ExtY_Atomic_P_I_T;

/* Real-time Model Data Structure */
struct tag_RTM_Atomic_P_I_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_Atomic_P_I_T Atomic_P_I_B;

/* Block states (auto storage) */
extern DW_Atomic_P_I_T Atomic_P_I_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with auto storage) */
  extern ExtU_Atomic_P_I_T Atomic_P_I_U;

  /* External outputs (root outports fed by signals with auto storage) */
  extern ExtY_Atomic_P_I_T Atomic_P_I_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void Atomic_P_I_initialize(void);
  extern void Atomic_P_I_step(void);
  extern void Atomic_P_I_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Atomic_P_I_T *const Atomic_P_I_M;

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
 * '<Root>' : 'Atomic_P_I'
 * '<S1>'   : 'Atomic_P_I/Subsystem'
 * '<S2>'   : 'Atomic_P_I/Subsystem1'
 */
#endif                                 /* RTW_HEADER_Atomic_P_I_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
