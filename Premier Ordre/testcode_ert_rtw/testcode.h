/*
 * File: testcode.h
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

#ifndef RTW_HEADER_testcode_h_
#define RTW_HEADER_testcode_h_
#ifndef testcode_COMMON_INCLUDES_
# define testcode_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* testcode_COMMON_INCLUDES_ */

#include "testcode_types.h"

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
} DW_testcode_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T u;                            /* '<Root>/u' */
} ExtU_testcode_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T y;                            /* '<Root>/y' */
} ExtY_testcode_T;

/* Parameters (auto storage) */
struct P_testcode_T_ {
  real_T ka;                           /* Variable: ka
                                        * Referenced by: '<Root>/K'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testcode_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_testcode_T testcode_P;

/* Block states (auto storage) */
extern DW_testcode_T testcode_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_testcode_T testcode_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_testcode_T testcode_Y;

/* Model entry point functions */
extern void testcode_initialize(void);
extern void testcode_step(void);
extern void testcode_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testcode_T *const testcode_M;

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
 * '<Root>' : 'testcode'
 */
#endif                                 /* RTW_HEADER_testcode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
