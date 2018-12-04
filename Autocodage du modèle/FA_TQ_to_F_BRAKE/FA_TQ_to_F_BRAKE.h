//
// File: FA_TQ_to_F_BRAKE.h
//
// Code generated for Simulink model 'FA_TQ_to_F_BRAKE'.
//
// Model version                  : 1.2
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 06:31:15 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_FA_TQ_to_F_BRAKE_h_
#define RTW_HEADER_FA_TQ_to_F_BRAKE_h_
#include <stddef.h>
#ifndef FA_TQ_to_F_BRAKE_COMMON_INCLUDES_
# define FA_TQ_to_F_BRAKE_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // FA_TQ_to_F_BRAKE_COMMON_INCLUDES_

#include "FA_TQ_to_F_BRAKE_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T CMD_FA_MECHANICAL_BRAKE;      // '<Root>/CMD_FA_MECANICAL_BRAKE'
} ExtU_FA_TQ_to_F_BRAKE_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T FA_PLA_F_BRAKE;               // '<Root>/FA_PLA_F_BRAKE'
} ExtY_FA_TQ_to_F_BRAKE_T;

// Real-time Model Data Structure
struct tag_RTM_FA_TQ_to_F_BRAKE_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model FA_TQ_to_F_BRAKE
class FA_TQ_to_F_BRAKEModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_FA_TQ_to_F_BRAKE_T FA_TQ_to_F_BRAKE_U;

  // External outputs
  ExtY_FA_TQ_to_F_BRAKE_T FA_TQ_to_F_BRAKE_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  FA_TQ_to_F_BRAKEModelClass();

  // Destructor
  ~FA_TQ_to_F_BRAKEModelClass();

  // Real-Time Model get method
  RT_MODEL_FA_TQ_to_F_BRAKE_T * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_FA_TQ_to_F_BRAKE_T FA_TQ_to_F_BRAKE_M;
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
//  hilite_system('BLOC_FA_TQ_to_F_BRAKE/FA_TQ_to_F_BRAKE')    - opens subsystem BLOC_FA_TQ_to_F_BRAKE/FA_TQ_to_F_BRAKE
//  hilite_system('BLOC_FA_TQ_to_F_BRAKE/FA_TQ_to_F_BRAKE/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_FA_TQ_to_F_BRAKE'
//  '<S1>'   : 'BLOC_FA_TQ_to_F_BRAKE/FA_TQ_to_F_BRAKE'

#endif                                 // RTW_HEADER_FA_TQ_to_F_BRAKE_h_

//
// File trailer for generated code.
//
// [EOF]
//
