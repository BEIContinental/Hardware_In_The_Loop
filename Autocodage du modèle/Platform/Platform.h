//
// File: Platform.h
//
// Code generated for Simulink model 'Platform'.
//
// Model version                  : 1.4
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 03:57:00 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Platform_h_
#define RTW_HEADER_Platform_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Platform_COMMON_INCLUDES_
# define Platform_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Platform_COMMON_INCLUDES_

#include "Platform_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T Delay_DSTATE;                 // '<S2>/Delay'
  real_T DiscreteZeroPole_DSTATE;      // '<S2>/Discrete Zero-Pole'
} DW_Platform_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T FA_TQ;                        // '<Root>/FA_TQ'
  real_T RA_TQ;                        // '<Root>/RA_TQ'
  real_T FA_PLA_F_BRAKE;               // '<Root>/FA_PLA_F_BRAKE'
  real_T RA_PLA_F_BRAKE;               // '<Root>/RA_PLA_F_BRAKE'
  real_T Slope;                        // '<Root>/Slope'
  real_T F_ext;                        // '<Root>/F_ext'
  real_T Wind;                         // '<Root>/Wind'
} ExtU_Platform_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T PLA_SPEED;                    // '<Root>/PLA_SPEED'
  real_T PLA_N;                        // '<Root>/PLA_N'
} ExtY_Platform_T;

// Real-time Model Data Structure
struct tag_RTM_Platform_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model Platform
class PlatformModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_Platform_T Platform_U;

  // External outputs
  ExtY_Platform_T Platform_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  PlatformModelClass();

  // Destructor
  ~PlatformModelClass();

  // Real-Time Model get method
  RT_MODEL_Platform_T * getRTM();

  // private data and function members
 private:
  // Block states
  DW_Platform_T Platform_DW;

  // Real-Time Model
  RT_MODEL_Platform_T Platform_M;
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
//  hilite_system('BLOC_Platform/Platform')    - opens subsystem BLOC_Platform/Platform
//  hilite_system('BLOC_Platform/Platform/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_Platform'
//  '<S1>'   : 'BLOC_Platform/Platform'
//  '<S2>'   : 'BLOC_Platform/Platform/Mechanical behavior'
//  '<S3>'   : 'BLOC_Platform/Platform/Mechanical behavior/Adherence'
//  '<S4>'   : 'BLOC_Platform/Platform/Mechanical behavior/Faero'
//  '<S5>'   : 'BLOC_Platform/Platform/Mechanical behavior/Fbrakes'
//  '<S6>'   : 'BLOC_Platform/Platform/Mechanical behavior/Fengines'
//  '<S7>'   : 'BLOC_Platform/Platform/Mechanical behavior/Ffriction'
//  '<S8>'   : 'BLOC_Platform/Platform/Mechanical behavior/Fslope'
//  '<S9>'   : 'BLOC_Platform/Platform/Mechanical behavior/Adherence/Compare To Constant'
//  '<S10>'  : 'BLOC_Platform/Platform/Mechanical behavior/Adherence/Compare To Constant1'

#endif                                 // RTW_HEADER_Platform_h_

//
// File trailer for generated code.
//
// [EOF]
//
