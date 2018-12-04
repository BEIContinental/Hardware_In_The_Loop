//
// File: ICE_control.h
//
// Code generated for Simulink model 'ICE_control'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 02:00:31 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ICE_control_h_
#define RTW_HEADER_ICE_control_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef ICE_control_COMMON_INCLUDES_
# define ICE_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // ICE_control_COMMON_INCLUDES_

#include "ICE_control_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;// '<S4>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_c;// '<S9>/Discrete-Time Integrator'
  real_T DelayInput1_DSTATE;           // '<S13>/Delay Input1'
  real_T PrevY;                        // '<S5>/Rate Limiter'
  uint8_T Delay_DSTATE;                // '<S9>/Delay'
  boolean_T Delay1_DSTATE;             // '<S9>/Delay1'
  boolean_T Delay_DSTATE_g;            // '<S12>/Delay'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S4>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_g;// '<S9>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;// '<S4>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_d;// '<S9>/Discrete-Time Integrator'
  uint8_T is_active_c2_ICE_control;    // '<S1>/ICE state machine'
  uint8_T is_c2_ICE_control;           // '<S1>/ICE state machine'
  uint8_T is_Start;                    // '<S1>/ICE state machine'
  uint8_T is_Running;                  // '<S1>/ICE state machine'
  uint8_T is_Force_tracking;           // '<S1>/ICE state machine'
  boolean_T Relay_Mode;                // '<S2>/Relay'
} DW_ICE_control_T;

// Invariant block signals (auto storage)
typedef const struct tag_ConstB_ICE_control_T {
  real_T Add2;                         // '<S2>/Add2'
  real_T Gain;                         // '<S2>/Gain'
  real_T Add6;                         // '<S2>/Add6'
  real_T Add7;                         // '<S2>/Add7'
  real_T Add5;                         // '<S2>/Add5'
} ConstB_ICE_control_T;

// Constant parameters (auto storage)
typedef struct {
  // Expression: fa_tq_loss
  //  Referenced by: '<S1>/TQ LOSS'

  real_T TQLOSS_tableData[18];

  // Expression: fa_n_ice
  //  Referenced by: '<S1>/TQ LOSS'

  real_T TQLOSS_bp01Data[18];

  // Expression: fa_kp_idle_tr_on
  //  Referenced by: '<S4>/fa_kp_idle_tr_on'

  real_T fa_kp_idle_tr_on_table[7];

  // Expression: fa_max_tq_ice
  //  Referenced by: '<S1>/MAX TQ ICE'

  real_T MAXTQICE_tableData[52];

  // Expression: fa_tq_max_speed
  //  Referenced by: '<S1>/MAX TQ ICE'

  real_T MAXTQICE_bp01Data[52];
} ConstP_ICE_control_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T FA_N_ICE;                     // '<Root>/FA_N_ICE'
  real_T CMD_FA_TQ_SP;                 // '<Root>/CMD_FA_TQ_SP'
  real_T DRI_GBX_SP;                   // '<Root>/DRI_GBX_SP'
  real_T FA_CLU_STUCK;                 // '<Root>/FA_CLU_STUCK'
  real_T FA_START_ICE;                 // '<Root>/FA_START_ICE'
  boolean_T FA_ICE_RESET_SYNCHRO;      // '<Root>/FA_ICE_RESET_SYNCHRO'
  real_T FA_TQ_STARTER;                // '<Root>/FA_TQ_STARTER'
} ExtU_ICE_control_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T FA_TQ_MAX_ICE;                // '<Root>/FA_TQ_MAX_ICE'
  real_T FA_ICE_TQ_SP;                 // '<Root>/FA_ICE_TQ_SP'
  boolean_T FA_STARTER_REQUEST;        // '<Root>/FA_STARTER_REQUEST'
  real_T FA_ICE_STATE;                 // '<Root>/FA_ICE_STATE'
  real_T FA_TQ_MIN_ICE;                // '<Root>/FA_TQ_MIN_ICE'
} ExtY_ICE_control_T;

// Real-time Model Data Structure
struct tag_RTM_ICE_control_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
  } Timing;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

extern const ConstB_ICE_control_T ICE_control_ConstB;// constant block i/o

// Constant parameters (auto storage)
extern const ConstP_ICE_control_T ICE_control_ConstP;

// Class declaration for model ICE_control
class ICE_controlModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_ICE_control_T ICE_control_U;

  // External outputs
  ExtY_ICE_control_T ICE_control_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  ICE_controlModelClass();

  // Destructor
  ~ICE_controlModelClass();

  // Real-Time Model get method
  RT_MODEL_ICE_control_T * getRTM();

  // private data and function members
 private:
  // Block states
  DW_ICE_control_T ICE_control_DW;

  // Real-Time Model
  RT_MODEL_ICE_control_T ICE_control_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/DERATING_IN5' : Unused code path elimination
//  Block '<S11>/Data Type Duplicate' : Unused code path elimination
//  Block '<S11>/Data Type Propagation' : Unused code path elimination
//  Block '<S7>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/Data Type Propagation' : Unused code path elimination


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
//  hilite_system('BLOC_ICE_control/ICE_control')    - opens subsystem BLOC_ICE_control/ICE_control
//  hilite_system('BLOC_ICE_control/ICE_control/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_ICE_control'
//  '<S1>'   : 'BLOC_ICE_control/ICE_control'
//  '<S2>'   : 'BLOC_ICE_control/ICE_control/ICE Torque derating from N_ICE'
//  '<S3>'   : 'BLOC_ICE_control/ICE_control/ICE state machine'
//  '<S4>'   : 'BLOC_ICE_control/ICE_control/Idle regulator'
//  '<S5>'   : 'BLOC_ICE_control/ICE_control/Injection shutdown'
//  '<S6>'   : 'BLOC_ICE_control/ICE_control/Loss compentation'
//  '<S7>'   : 'BLOC_ICE_control/ICE_control/Saturation Dynamic'
//  '<S8>'   : 'BLOC_ICE_control/ICE_control/Starter request'
//  '<S9>'   : 'BLOC_ICE_control/ICE_control/TopCrank for start'
//  '<S10>'  : 'BLOC_ICE_control/ICE_control/Transfer of the command'
//  '<S11>'  : 'BLOC_ICE_control/ICE_control/Idle regulator/Saturation Dynamic'
//  '<S12>'  : 'BLOC_ICE_control/ICE_control/Idle regulator/anti windup clamping'
//  '<S13>'  : 'BLOC_ICE_control/ICE_control/TopCrank for start/Detect Decrease'

#endif                                 // RTW_HEADER_ICE_control_h_

//
// File trailer for generated code.
//
// [EOF]
//
