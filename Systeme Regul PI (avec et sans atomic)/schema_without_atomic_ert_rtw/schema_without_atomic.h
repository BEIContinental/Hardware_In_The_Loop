/*
 * File: schema_without_atomic.h
 *
 * Code generated for Simulink model 'schema_without_atomic'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Fri Jan 22 11:24:35 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_schema_without_atomic_h_
#define RTW_HEADER_schema_without_atomic_h_
#ifndef schema_without_atomic_COMMON_INCLUDES_
# define schema_without_atomic_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* schema_without_atomic_COMMON_INCLUDES_ */

#include "schema_without_atomic_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T PI;                           /* '<Root>/PI' */
} B_schema_without_atomic_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Systeme_states[2];            /* '<Root>/Systeme' */
  real_T PI_states;                    /* '<Root>/PI' */
} DW_schema_without_atomic_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T x;                            /* '<Root>/x' */
} ExtU_schema_without_atomic_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T y;                            /* '<Root>/y' */
} ExtY_schema_without_atomic_T;

/* Real-time Model Data Structure */
struct tag_RTM_schema_without_atomic_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_schema_without_atomic_T schema_without_atomic_B;

/* Block states (auto storage) */
extern DW_schema_without_atomic_T schema_without_atomic_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with auto storage) */
  extern ExtU_schema_without_atomic_T schema_without_atomic_U;

  /* External outputs (root outports fed by signals with auto storage) */
  extern ExtY_schema_without_atomic_T schema_without_atomic_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void schema_without_atomic_initialize(void);
  extern void schema_without_atomic_step(void);
  extern void schema_without_atomic_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_schema_without_atomi_T *const schema_without_atomic_M;

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
 * '<Root>' : 'schema_without_atomic'
 */
#endif                                 /* RTW_HEADER_schema_without_atomic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
