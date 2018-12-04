//
// File: ICE.h
//
// Code generated for Simulink model 'ICE'.
//
// Model version                  : 1.5
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Thu Jan 25 15:29:09 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ICE_h_
#define RTW_HEADER_ICE_h_
#include <stddef.h>
#include <string.h>
#ifndef ICE_COMMON_INCLUDES_
# define ICE_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // ICE_COMMON_INCLUDES_

#include "ICE_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  real_T FA_GAS_CONSUMPTION;           // '<S2>/Chart'
} B_ICE_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T DiscreteTransferFcn3_states;  // '<S1>/Discrete Transfer Fcn3'
  real_T Delay_DSTATE;                 // '<S2>/Delay'
  uint8_T tp_STATE_1;                  // '<S2>/Chart'
  uint8_T is_active_c1_ICE;            // '<S2>/Chart'
  uint8_T is_c1_ICE;                   // '<S2>/Chart'
} DW_ICE_T;

// Constant parameters (auto storage)
typedef struct {
  // Expression: fa_starter_tq
  //  Referenced by: '<S1>/TQ_STARTER'

  real_T TQ_STARTER_tableData[101];

  // Expression: fa_starter_rpm
  //  Referenced by: '<S1>/TQ_STARTER'

  real_T TQ_STARTER_bp01Data[101];

  // Expression: fa_tq_loss
  //  Referenced by: '<S1>/TQ_LOSS'

  real_T TQ_LOSS_tableData[18];

  // Expression: fa_n_ice
  //  Referenced by: '<S1>/TQ_LOSS'

  real_T TQ_LOSS_bp01Data[18];

  // Expression: fa_conso_torque
  //  Referenced by: '<S2>/Lookup table consumption'

  real_T Lookuptableconsumption_bp01Data[43];

  // Expression: fa_conso_speed
  //  Referenced by: '<S2>/Lookup table consumption'

  real_T Lookuptableconsumption_bp02Data[56];

  // Computed Parameter: Lookuptableconsumption_maxIndex
  //  Referenced by: '<S2>/Lookup table consumption'

  uint32_T Lookuptableconsumption_maxIndex[2];
} ConstP_ICE_T;

// Constant parameters with dynamic initialization (auto storage)
typedef struct {
  // Expression: fa_fuel_consumption
  //  Referenced by: '<S2>/Lookup table consumption'

  real_T Lookuptableconsumption_tableDat[2408];
} ConstInitP_ICE_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T FA_N_ICE;                     // '<Root>/FA_N_ICE'
  real_T FA_ICE_TQ_SP;                 // '<Root>/FA_ICE_TQ_SP'
  real_T FA_STARTER_REQUEST;           // '<Root>/FA_STARTER_REQUEST'
  real_T FA_ICE_STATE;                 // '<Root>/FA_ICE_STATE'
} ExtU_ICE_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T FA_GAS_CONSUMPTION;           // '<Root>/FA_GAS_CONSUMPTION'
  real_T FA_TQ_ICE;                    // '<Root>/FA_TQ_ICE'
  real_T FA_TQ_STARTER;                // '<Root>/FA_TQ_STARTER'
} ExtY_ICE_T;

// Real-time Model Data Structure
struct tag_RTM_ICE_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstP_ICE_T ICE_ConstP;

// Constant parameters with dynamic initialization (auto storage)
extern ConstInitP_ICE_T ICE_ConstInitP;// constant parameters

// Class declaration for model ICE
class ICEModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_ICE_T ICE_U;

  // External outputs
  ExtY_ICE_T ICE_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  ICEModelClass();

  // Destructor
  ~ICEModelClass();

  // Real-Time Model get method
  RT_MODEL_ICE_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_ICE_T ICE_B;

  // Block states
  DW_ICE_T ICE_DW;

  // Real-Time Model
  RT_MODEL_ICE_T ICE_M;
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
//  hilite_system('BLOC_ICE/ICE')    - opens subsystem BLOC_ICE/ICE
//  hilite_system('BLOC_ICE/ICE/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_ICE'
//  '<S1>'   : 'BLOC_ICE/ICE'
//  '<S2>'   : 'BLOC_ICE/ICE/Gas consumption'
//  '<S3>'   : 'BLOC_ICE/ICE/Gas consumption/Chart'

#endif                                 // RTW_HEADER_ICE_h_

//
// File trailer for generated code.
//
// [EOF]
//
