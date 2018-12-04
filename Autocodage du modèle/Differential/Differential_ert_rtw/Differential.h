//
// File: Differential.h
//
// Code generated for Simulink model 'Differential'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Fri Jan 26 01:30:15 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Differential_h_
#define RTW_HEADER_Differential_h_
#include <stddef.h>
#include <string.h>
#ifndef Differential_COMMON_INCLUDES_
# define Differential_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Differential_COMMON_INCLUDES_

#include "Differential_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T signal1;                      // '<Root>/signal1'
  real_T signal2;                      // '<Root>/signal2'
  real_T signal3;                      // '<Root>/signal3'
  real_T PLA_N;                        // '<Root>/PLA_N'
} ExtU_Differential_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T RA_TQ__MINMAX[3];             // '<Root>/RA_TQ_&_MINMAX'
  real_T RA_N_EM;                      // '<Root>/RA_N_EM'
} ExtY_Differential_T;

// Parameters (auto storage)
struct P_Differential_T_ {
  real_T ra_differential_ratio;        // Variable: ra_differential_ratio
                                       //  Referenced by:
                                       //    '<S1>/Differential ratio'
                                       //    '<S1>/differential ratio'

  real_T ra_transmission_efficiency;   // Variable: ra_transmission_efficiency
                                       //  Referenced by:
                                       //    '<S1>/Efficiency P neg'
                                       //    '<S1>/Efficiency P pos'

  real_T Switch_Threshold;             // Expression: 0
                                       //  Referenced by: '<S1>/Switch'

};

// Real-time Model Data Structure
struct tag_RTM_Differential_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model Differential
class DifferentialModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_Differential_T Differential_U;

  // External outputs
  ExtY_Differential_T Differential_Y;

  // Model entry point functions

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  DifferentialModelClass();

  // Destructor
  ~DifferentialModelClass();

  // Real-Time Model get method
  RT_MODEL_Differential_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  P_Differential_T Differential_P;

  // Real-Time Model
  RT_MODEL_Differential_T Differential_M;
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
//  hilite_system('BLOC_Differential/Differential')    - opens subsystem BLOC_Differential/Differential
//  hilite_system('BLOC_Differential/Differential/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_Differential'
//  '<S1>'   : 'BLOC_Differential/Differential'

#endif                                 // RTW_HEADER_Differential_h_

//
// File trailer for generated code.
//
// [EOF]
//
