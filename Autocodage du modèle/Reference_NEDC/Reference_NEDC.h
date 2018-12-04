//
// File: Reference_NEDC.h
//
// Code generated for Simulink model 'Reference_NEDC'.
//
// Model version                  : 1.3
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 06:55:38 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Reference_NEDC_h_
#define RTW_HEADER_Reference_NEDC_h_
#include <math.h>
#include <string.h>
#ifndef Reference_NEDC_COMMON_INCLUDES_
# define Reference_NEDC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 // Reference_NEDC_COMMON_INCLUDES_

#include "Reference_NEDC_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

// Block signals (auto storage)
typedef struct {
  real_T Clock;                        // '<S1>/Clock'
} B_Reference_NEDC_T;

// Constant parameters (auto storage)
typedef struct {
  // Expression: dri_gbx_sp
  //  Referenced by: '<S1>/NEDC gear'

  real_T NEDCgear_tableData[52];

  // Expression: dri_gbx_time
  //  Referenced by: '<S1>/NEDC gear'

  real_T NEDCgear_bp01Data[52];

  // Expression: dri_cycle_speed_sp
  //  Referenced by: '<S1>/NEDC speed'

  real_T NEDCspeed_tableData[135];

  // Expression: dri_cycle_speed_time
  //  Referenced by: '<S1>/NEDC speed'

  real_T NEDCspeed_bp01Data[135];
} ConstP_Reference_NEDC_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T DRI_REF_GBX;                  // '<Root>/DRI_REF_GBX'
  real_T DRI_REF_SPEED;                // '<Root>/DRI_REF_SPEED'
} ExtY_Reference_NEDC_T;

// Real-time Model Data Structure
struct tag_RTM_Reference_NEDC_T {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstP_Reference_NEDC_T Reference_NEDC_ConstP;

// Class declaration for model Reference_NEDC
class Reference_NEDCModelClass {
  // public data and function members
 public:
  // External outputs
  ExtY_Reference_NEDC_T Reference_NEDC_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Reference_NEDCModelClass();

  // Destructor
  ~Reference_NEDCModelClass();

  // Real-Time Model get method
  RT_MODEL_Reference_NEDC_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_Reference_NEDC_T Reference_NEDC_B;

  // Real-Time Model
  RT_MODEL_Reference_NEDC_T Reference_NEDC_M;
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
//  hilite_system('BLOC_Reference_NEDC/Reference_NEDC')    - opens subsystem BLOC_Reference_NEDC/Reference_NEDC
//  hilite_system('BLOC_Reference_NEDC/Reference_NEDC/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_Reference_NEDC'
//  '<S1>'   : 'BLOC_Reference_NEDC/Reference_NEDC'

#endif                                 // RTW_HEADER_Reference_NEDC_h_

//
// File trailer for generated code.
//
// [EOF]
//
