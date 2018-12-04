//
// File: RA_TQ_to_F_BRAKE.h
//
// Code generated for Simulink model 'RA_TQ_to_F_BRAKE'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Fri Jan 26 01:23:45 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_RA_TQ_to_F_BRAKE_h_
#define RTW_HEADER_RA_TQ_to_F_BRAKE_h_
#include <stddef.h>
#ifndef RA_TQ_to_F_BRAKE_COMMON_INCLUDES_
# define RA_TQ_to_F_BRAKE_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // RA_TQ_to_F_BRAKE_COMMON_INCLUDES_

#include "RA_TQ_to_F_BRAKE_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T CMD_RA_MECHANICAL_BRAKE;      // '<Root>/CMD_RA_MECANICAL_BRAKE'
} ExtU_RA_TQ_to_F_BRAKE_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T RA_PLA_F_BRAKE;               // '<Root>/RA_PLA_F_BRAKE'
} ExtY_RA_TQ_to_F_BRAKE_T;

// Parameters (auto storage)
struct P_RA_TQ_to_F_BRAKE_T_ {
  real_T pla_wheel_radius;             // Variable: pla_wheel_radius
                                       //  Referenced by: '<S1>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_RA_TQ_to_F_BRAKE_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model RA_TQ_to_F_BRAKE
class RA_TQ_to_F_BRAKEModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_RA_TQ_to_F_BRAKE_T RA_TQ_to_F_BRAKE_U;

  // External outputs
  ExtY_RA_TQ_to_F_BRAKE_T RA_TQ_to_F_BRAKE_Y;

  // Model entry point functions

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  RA_TQ_to_F_BRAKEModelClass();

  // Destructor
  ~RA_TQ_to_F_BRAKEModelClass();

  // Real-Time Model get method
  RT_MODEL_RA_TQ_to_F_BRAKE_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  P_RA_TQ_to_F_BRAKE_T RA_TQ_to_F_BRAKE_P;

  // Real-Time Model
  RT_MODEL_RA_TQ_to_F_BRAKE_T RA_TQ_to_F_BRAKE_M;
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
//  hilite_system('BLOC_RA_TQ_to_F_BRAKE/RA_TQ_to_F_BRAKE')    - opens subsystem BLOC_RA_TQ_to_F_BRAKE/RA_TQ_to_F_BRAKE
//  hilite_system('BLOC_RA_TQ_to_F_BRAKE/RA_TQ_to_F_BRAKE/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_RA_TQ_to_F_BRAKE'
//  '<S1>'   : 'BLOC_RA_TQ_to_F_BRAKE/RA_TQ_to_F_BRAKE'

#endif                                 // RTW_HEADER_RA_TQ_to_F_BRAKE_h_

//
// File trailer for generated code.
//
// [EOF]
//
