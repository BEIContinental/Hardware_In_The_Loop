//
// File: simulink_testcode.h
//
// Code generated for Simulink model 'simulink_testcode'.
//
// Model version                  : 1.26
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Tue Dec  5 17:39:51 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_simulink_testcode_h_
#define RTW_HEADER_simulink_testcode_h_
#include <stddef.h>
#include <string.h>
#ifndef simulink_testcode_COMMON_INCLUDES_
# define simulink_testcode_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // simulink_testcode_COMMON_INCLUDES_

#include "simulink_testcode_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T UnitDelay_DSTATE;             // '<Root>/Unit Delay'
  real_T H_states;                     // '<Root>/H'
} DW_simulink_testcode_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T u;                            // '<Root>/u'
} ExtU_simulink_testcode_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T y;                            // '<Root>/y'
} ExtY_simulink_testcode_T;

// Parameters (auto storage)
struct P_simulink_testcode_T_ {
  real_T ka;                           // Variable: ka
                                       //  Referenced by: '<Root>/K'

};

// Real-time Model Data Structure
struct tag_RTM_simulink_testcode_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model simulink_testcode
class simulink_testcodeModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_simulink_testcode_T simulink_testcode_U;

  // External outputs
  ExtY_simulink_testcode_T simulink_testcode_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  simulink_testcodeModelClass();

  // Destructor
  ~simulink_testcodeModelClass();

  // Real-Time Model get method
  RT_MODEL_simulink_testcode_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  P_simulink_testcode_T simulink_testcode_P;

  // Block states
  DW_simulink_testcode_T simulink_testcode_DW;

  // Real-Time Model
  RT_MODEL_simulink_testcode_T simulink_testcode_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'simulink_testcode'

#endif                                 // RTW_HEADER_simulink_testcode_h_

//
// File trailer for generated code.
//
// [EOF]
//
