/*
 * File: platform.h
 *
 * Code generated for Simulink model 'platform'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Feb 17 11:51:33 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_platform_h_
#define RTW_HEADER_platform_h_
#ifndef platform_COMMON_INCLUDES_
# define platform_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* platform_COMMON_INCLUDES_ */

#include "platform_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  real_T DiscreteZeroPole_DSTATE;      /* '<S2>/Discrete Zero-Pole' */
} DW_platform_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T FA_TQ;                        /* '<Root>/FA_TQ' */
  real_T RA_TQ;                        /* '<Root>/RA_TQ' */
  real_T CMD_BRAKE_SP;                 /* '<Root>/CMD_BRAKE_SP' */
  real_T Slope;                        /* '<Root>/SLOPE' */
  real_T F_ext;                        /* '<Root>/F_EXT' */
  real_T Wind;                         /* '<Root>/WIND' */
} ExtU_platform_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T PLA_SPEED;                    /* '<Root>/PLA_SPEED' */
  real_T PLA_N;                        /* '<Root>/PLA_N' */
} ExtY_platform_T;

/* Parameters (auto storage) */
struct P_platform_T_ {
  real_T hev_dt;                       /* Variable: hev_dt
                                        * Referenced by: '<S2>/Gain7'
                                        */
  real_T pla_csat;                     /* Variable: pla_csat
                                        * Referenced by:
                                        *   '<S7>/Constant2'
                                        *   '<S10>/Constant'
                                        */
  real_T pla_equivalent_weight;        /* Variable: pla_equivalent_weight
                                        * Referenced by:
                                        *   '<S2>/Gain'
                                        *   '<S7>/Constant'
                                        *   '<S7>/Constant2'
                                        *   '<S7>/Gain1'
                                        *   '<S8>/Gain2'
                                        *   '<S10>/Constant'
                                        */
  real_T pla_f;                        /* Variable: pla_f
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S7>/Constant2'
                                        *   '<S10>/Constant'
                                        */
  real_T pla_k;                        /* Variable: pla_k
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T pla_kaero;                    /* Variable: pla_kaero
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T pla_max_f_brakes;             /* Variable: pla_max_f_brakes
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T pla_wheel_radius;             /* Variable: pla_wheel_radius
                                        * Referenced by:
                                        *   '<S1>/m//s -> tr//min'
                                        *   '<S5>/Gain1'
                                        *   '<S6>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_platform_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_platform_T platform_P;

#ifdef __cplusplus

}
#endif

/* Block states (auto storage) */
extern DW_platform_T platform_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with auto storage) */
  extern ExtU_platform_T platform_U;

  /* External outputs (root outports fed by signals with auto storage) */
  extern ExtY_platform_T platform_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void platform_initialize(void);
  extern void platform_step(void);
  extern void platform_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_platform_T *const platform_M;

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
 * '<Root>' : 'platform'
 * '<S1>'   : 'platform/Platform'
 * '<S2>'   : 'platform/Platform/Mechanical behavior'
 * '<S3>'   : 'platform/Platform/Mechanical behavior/Adherence'
 * '<S4>'   : 'platform/Platform/Mechanical behavior/Faero'
 * '<S5>'   : 'platform/Platform/Mechanical behavior/Fbrakes'
 * '<S6>'   : 'platform/Platform/Mechanical behavior/Fengines'
 * '<S7>'   : 'platform/Platform/Mechanical behavior/Ffriction'
 * '<S8>'   : 'platform/Platform/Mechanical behavior/Fslope'
 * '<S9>'   : 'platform/Platform/Mechanical behavior/Adherence/Compare To Constant'
 * '<S10>'  : 'platform/Platform/Mechanical behavior/Adherence/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_platform_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
