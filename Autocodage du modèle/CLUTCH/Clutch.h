//
// File: Clutch.h
//
// Code generated for Simulink model 'Clutch'.
//
// Model version                  : 1.10
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Wed Jan 24 01:33:55 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Clutch_h_
#define RTW_HEADER_Clutch_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Clutch_COMMON_INCLUDES_
# define Clutch_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Clutch_COMMON_INCLUDES_

#include "Clutch_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T Delay2_DSTATE;                // '<S1>/Delay2'
  real_T Delay_DSTATE;                 // '<S1>/Delay'
  real_T Delay3_DSTATE;                // '<S1>/Delay3'
  real_T Delay4_DSTATE;                // '<S1>/Delay4'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S1>/Discrete-Time Integrator'
  boolean_T Delay_DSTATE_m;            // '<S2>/Delay'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S1>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S1>/Discrete-Time Integrator'
  boolean_T Relay_Mode;                // '<S1>/Relay'
} DW_Clutch_T;

// Constant parameters (auto storage)
typedef struct {
  // Expression: fa_clu_pos
  //  Referenced by: '<S1>/CLU_PV_SENSITIVITY'

  real_T CLU_PV_SENSITIVITY_tableData[7];

  // Expression: fa_clu_pv
  //  Referenced by: '<S1>/CLU_PV_SENSITIVITY'

  real_T CLU_PV_SENSITIVITY_bp01Data[7];

  // Computed Parameter: CombinatorialLogic3_table
  //  Referenced by: '<S2>/Combinatorial  Logic3'

  boolean_T CombinatorialLogic3_table[8];
} ConstP_Clutch_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T FA_TQ_ICE;                    // '<Root>/FA_TQ_ICE'
  real_T FA_N_GBX;                     // '<Root>/FA_N_GBX'
  real_T CMD_CLUTCH_SP;                // '<Root>/CMD_CLUTCH_SP'
  real_T DRI_GBX_SP;                   // '<Root>/DRI_GBX_SP'
} ExtU_Clutch_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T FA_N_ICE;                     // '<Root>/FA_N_ICE'
  real_T FA_TQ_CLU;                    // '<Root>/FA_TQ_CLU'
  boolean_T FA_CLU_STUCK;              // '<Root>/FA_CLU_STUCK'
} ExtY_Clutch_T;

// Real-time Model Data Structure
struct tag_RTM_Clutch_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstP_Clutch_T Clutch_ConstP;

// Class declaration for model Clutch
class ClutchModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_Clutch_T Clutch_U;

  // External outputs
  ExtY_Clutch_T Clutch_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  ClutchModelClass();

  // Destructor
  ~ClutchModelClass();

  // Real-Time Model get method
  RT_MODEL_Clutch_T * getRTM();

  // private data and function members
 private:
  // Block states
  DW_Clutch_T Clutch_DW;

  // Real-Time Model
  RT_MODEL_Clutch_T Clutch_M;
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
//  hilite_system('BLOC_CLUTCH/Clutch')    - opens subsystem BLOC_CLUTCH/Clutch
//  hilite_system('BLOC_CLUTCH/Clutch/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_CLUTCH'
//  '<S1>'   : 'BLOC_CLUTCH/Clutch'
//  '<S2>'   : 'BLOC_CLUTCH/Clutch/Stuck logic'
//  '<S3>'   : 'BLOC_CLUTCH/Clutch/Stuck logic/Compare To Constant'

#endif                                 // RTW_HEADER_Clutch_h_

//
// File trailer for generated code.
//
// [EOF]
//
