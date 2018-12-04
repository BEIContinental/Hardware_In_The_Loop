//
// File: Environment.h
//
// Code generated for Simulink model 'Environment'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 07:16:30 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Environment_h_
#define RTW_HEADER_Environment_h_
#include <stddef.h>
#include <string.h>
#ifndef Environment_COMMON_INCLUDES_
# define Environment_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Environment_COMMON_INCLUDES_

#include "Environment_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T Slope;                        // '<Root>/Slope[%]'
  real_T F_ext;                        // '<Root>/F_ext'
  real_T Wind;                         // '<Root>/Wind'
} ExtY_Environment_T;

// Real-time Model Data Structure
struct tag_RTM_Environment_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model Environment
class EnvironmentModelClass {
  // public data and function members
 public:
  // External outputs
  ExtY_Environment_T Environment_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  EnvironmentModelClass();

  // Destructor
  ~EnvironmentModelClass();

  // Real-Time Model get method
  RT_MODEL_Environment_T * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_Environment_T Environment_M;
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
//  hilite_system('BLOC_Environment/Environment')    - opens subsystem BLOC_Environment/Environment
//  hilite_system('BLOC_Environment/Environment/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_Environment'
//  '<S1>'   : 'BLOC_Environment/Environment'

#endif                                 // RTW_HEADER_Environment_h_

//
// File trailer for generated code.
//
// [EOF]
//
