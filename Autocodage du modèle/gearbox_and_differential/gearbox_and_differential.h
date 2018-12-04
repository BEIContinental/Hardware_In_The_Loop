//
// File: gearbox_and_differential.h
//
// Code generated for Simulink model 'gearbox_and_differential'.
//
// Model version                  : 1.2
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 02:56:48 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_gearbox_and_differential_h_
#define RTW_HEADER_gearbox_and_differential_h_
#include <stddef.h>
#include <string.h>
#ifndef gearbox_and_differential_COMMON_INCLUDES_
# define gearbox_and_differential_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // gearbox_and_differential_COMMON_INCLUDES_ 

#include "gearbox_and_differential_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Constant parameters (auto storage)
typedef struct {
  // Expression: fa_gearbox_ratio
  //  Referenced by: '<S1>/ gear_ratio'

  real_T gear_ratio_table[7];
} ConstP_gearbox_and_differenti_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T FA_TQ_AND_MINMAX_ICE[3];      // '<Root>/FA_TQ_AND_MINMAX_ICE'
  real_T DRI_GBX_SP;                   // '<Root>/DRI_GBX_SP'
  real_T PLA_N;                        // '<Root>/PLA_N'
  real_T FA_N_ICE;                     // '<Root>/FA_N_ICE'
} ExtU_gearbox_and_differential_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T FA_TQ_AND_MINMAX[3];          // '<Root>/FA_TQ_AND_MINMAX'
  real_T FA_N_GBX;                     // '<Root>/FA_N_GBX'
} ExtY_gearbox_and_differential_T;

// Real-time Model Data Structure
struct tag_RTM_gearbox_and_different_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstP_gearbox_and_differenti_T gearbox_and_differential_ConstP;

// Class declaration for model gearbox_and_differential
class gearbox_and_differentialModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_gearbox_and_differential_T gearbox_and_differential_U;

  // External outputs
  ExtY_gearbox_and_differential_T gearbox_and_differential_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  gearbox_and_differentialModelClass();

  // Destructor
  ~gearbox_and_differentialModelClass();

  // Real-Time Model get method
  RT_MODEL_gearbox_and_differen_T * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_gearbox_and_differen_T gearbox_and_differential_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('BLOC_gearbox_and_differential/gearbox_and_differential')    - opens subsystem BLOC_gearbox_and_differential/gearbox_and_differential
//  hilite_system('BLOC_gearbox_and_differential/gearbox_and_differential/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_gearbox_and_differential'
//  '<S1>'   : 'BLOC_gearbox_and_differential/gearbox_and_differential'

#endif                                 // RTW_HEADER_gearbox_and_differential_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
