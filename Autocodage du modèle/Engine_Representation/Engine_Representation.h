//
// File: Engine_Representation.h
//
// Code generated for Simulink model 'Engine_Representation'.
//
// Model version                  : 1.1798
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Tue Jan 23 15:26:15 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Engine_Representation_h_
#define RTW_HEADER_Engine_Representation_h_
#include <stddef.h>
#include <string.h>
#ifndef Engine_Representation_COMMON_INCLUDES_
# define Engine_Representation_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Engine_Representation_COMMON_INCLUDES_ 

#include "Engine_Representation_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T DiscreteTransferFcn3_states;  // '<S1>/Discrete Transfer Fcn3'
} DW_Engine_Representation_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T CMD_RA_TQ_SP;                 // '<Root>/CMD_RA_TQ_SP'
  real_T RA_N_EM;                      // '<Root>/RA_N_EM'
} ExtU_Engine_Representation_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T RA_TQ_ME;                     // '<Root>/RA_TQ_ME'
  real_T RA_TQ_MIN_ME;                 // '<Root>/RA_TQ_MIN_ME'
  real_T RA_TQ_MAX_ME;                 // '<Root>/RA_TQ_MAX_ME'
} ExtY_Engine_Representation_T;

// Parameters (auto storage)
struct P_Engine_Representation_T_ {
  real_T ra_electrical_machine_speed[21];// Variable: ra_electrical_machine_speed
                                         //  Referenced by:
                                         //    '<S1>/Maximum torque'
                                         //    '<S1>/Minimum torque'

  real_T ra_em_max_tq[21];             // Variable: ra_em_max_tq
                                       //  Referenced by: '<S1>/Maximum torque'

  real_T ra_em_min_tq[21];             // Variable: ra_em_min_tq
                                       //  Referenced by: '<S1>/Minimum torque'

  real_T DiscreteTransferFcn3_NumCoef[2];// Expression: [(hev_dt/(2*(ra_electrical_machine_tau)+hev_dt)) (hev_dt/(2*(ra_electrical_machine_tau)+hev_dt))]
                                         //  Referenced by: '<S1>/Discrete Transfer Fcn3'

  real_T DiscreteTransferFcn3_DenCoef[2];// Expression: [1 ((hev_dt-2*(ra_electrical_machine_tau)))/(2*(ra_electrical_machine_tau)+hev_dt)]
                                         //  Referenced by: '<S1>/Discrete Transfer Fcn3'

  real_T DiscreteTransferFcn3_InitialSta;// Expression: 0
                                         //  Referenced by: '<S1>/Discrete Transfer Fcn3'

};

// Real-time Model Data Structure
struct tag_RTM_Engine_Representation_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model Engine_Representation
class Engine_RepresentationModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_Engine_Representation_T Engine_Representation_U;

  // External outputs
  ExtY_Engine_Representation_T Engine_Representation_Y;

  // Model entry point functions

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Engine_RepresentationModelClass();

  // Destructor
  ~Engine_RepresentationModelClass();

  // Real-Time Model get method
  RT_MODEL_Engine_Representatio_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  P_Engine_Representation_T Engine_Representation_P;

  // Block states
  DW_Engine_Representation_T Engine_Representation_DW;

  // Real-Time Model
  RT_MODEL_Engine_Representatio_T Engine_Representation_M;
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
//  hilite_system('AxleSplitHEVv7_Matlab2015_Autocodage/HEV model/Rear Axle1/Electrical machine/Engine_Representation')    - opens subsystem AxleSplitHEVv7_Matlab2015_Autocodage/HEV model/Rear Axle1/Electrical machine/Engine_Representation
//  hilite_system('AxleSplitHEVv7_Matlab2015_Autocodage/HEV model/Rear Axle1/Electrical machine/Engine_Representation/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'AxleSplitHEVv7_Matlab2015_Autocodage/HEV model/Rear Axle1/Electrical machine'
//  '<S1>'   : 'AxleSplitHEVv7_Matlab2015_Autocodage/HEV model/Rear Axle1/Electrical machine/Engine_Representation'
//  '<S2>'   : 'AxleSplitHEVv7_Matlab2015_Autocodage/HEV model/Rear Axle1/Electrical machine/Engine_Representation/Saturation Dynamic'

#endif                                 // RTW_HEADER_Engine_Representation_h_

//
// File trailer for generated code.
//
// [EOF]
//
