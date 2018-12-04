//
// File: Power_efficiency0.h
//
// Code generated for Simulink model 'Power_efficiency0'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Thu Jan 25 16:08:45 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Power_efficiency0_h_
#define RTW_HEADER_Power_efficiency0_h_
#include <stddef.h>
#include <string.h>
#ifndef Power_efficiency0_COMMON_INCLUDES_
# define Power_efficiency0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Power_efficiency0_COMMON_INCLUDES_

#include "Power_efficiency0_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T RA_TQ_ME;                     // '<Root>/RA_TQ_ME'
  real_T RA_N_EM;                      // '<Root>/RA_N_EM'
  real_T SYSE_VOLTAGE_HV;              // '<Root>/SYSE_VOLTAGE_HV'
} ExtU_Power_efficiency0_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T RA_EM_CURRENT;                // '<Root>/RA_EM_CURRENT'
} ExtY_Power_efficiency0_T;

// Parameters (auto storage)
struct P_Power_efficiency0_T_ {
  real_T ra_electrical_machine_efficiency[777];// Variable: ra_electrical_machine_efficiency
                                               //  Referenced by: '<S1>/Efficiency (%)'

  real_T ra_electrical_machine_speed[21];// Variable: ra_electrical_machine_speed
                                         //  Referenced by: '<S1>/Efficiency (%)'

  real_T ra_electrical_machine_torque[37];// Variable: ra_electrical_machine_torque
                                          //  Referenced by: '<S1>/Efficiency (%)'

  real_T Efficiencyconversion_Gain;    // Expression: 1/100
                                       //  Referenced by: '<S1>/Efficiency conversion'

  real_T trminrads_Gain;               // Expression: 2*pi/60
                                       //  Referenced by: '<S1>/tr//min -> rad//s'

  real_T Switch_Threshold;             // Expression: 0
                                       //  Referenced by: '<S1>/Switch'

  uint32_T Efficiency_maxIndex[2];     // Computed Parameter: Efficiency_maxIndex
                                       //  Referenced by: '<S1>/Efficiency (%)'

};

// Real-time Model Data Structure
struct tag_RTM_Power_efficiency0_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model Power_efficiency0
class Power_efficiency0ModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_Power_efficiency0_T Power_efficiency0_U;

  // External outputs
  ExtY_Power_efficiency0_T Power_efficiency0_Y;

  // Model entry point functions

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Power_efficiency0ModelClass();

  // Destructor
  ~Power_efficiency0ModelClass();

  // Real-Time Model get method
  RT_MODEL_Power_efficiency0_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  P_Power_efficiency0_T Power_efficiency0_P;

  // Real-Time Model
  RT_MODEL_Power_efficiency0_T Power_efficiency0_M;
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
//  hilite_system('Power_Efficiency/Power_efficiency')    - opens subsystem Power_Efficiency/Power_efficiency
//  hilite_system('Power_Efficiency/Power_efficiency/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Power_Efficiency'
//  '<S1>'   : 'Power_Efficiency/Power_efficiency'

#endif                                 // RTW_HEADER_Power_efficiency0_h_

//
// File trailer for generated code.
//
// [EOF]
//
