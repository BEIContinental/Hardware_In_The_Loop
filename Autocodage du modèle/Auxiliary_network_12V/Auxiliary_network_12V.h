//
// File: Auxiliary_network_12V.h
//
// Code generated for Simulink model 'Auxiliary_network_12V'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 08:13:27 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Auxiliary_network_12V_h_
#define RTW_HEADER_Auxiliary_network_12V_h_
#include <stddef.h>
#include <string.h>
#ifndef Auxiliary_network_12V_COMMON_INCLUDES_
# define Auxiliary_network_12V_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Auxiliary_network_12V_COMMON_INCLUDES_ 

#include "Auxiliary_network_12V_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T Delay_DSTATE;                 // '<S3>/Delay'
} DW_Auxiliary_network_12V_T;

// Constant parameters (auto storage)
typedef struct {
  // Expression: syse_dcdc_efficency/100
  //  Referenced by: '<S3>/rendement CVS'

  real_T rendementCVS_tableData[6];

  // Expression: syse_dcdc_in_power.*(syse_dcdc_efficency/100)
  //  Referenced by: '<S3>/rendement CVS'

  real_T rendementCVS_bp01Data[6];
} ConstP_Auxiliary_network_12V_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T SYSE_VOLTAGE_HV;              // '<Root>/SYSE_VOLTAGE_HV'
} ExtU_Auxiliary_network_12V_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T SYSE_AUX_CURRENT;             // '<Root>/SYSE_AUX_CURRENT'
} ExtY_Auxiliary_network_12V_T;

// Real-time Model Data Structure
struct tag_RTM_Auxiliary_network_12V_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstP_Auxiliary_network_12V_T Auxiliary_network_12V_ConstP;

// Class declaration for model Auxiliary_network_12V
class Auxiliary_network_12VModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_Auxiliary_network_12V_T Auxiliary_network_12V_U;

  // External outputs
  ExtY_Auxiliary_network_12V_T Auxiliary_network_12V_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Auxiliary_network_12VModelClass();

  // Destructor
  ~Auxiliary_network_12VModelClass();

  // Real-Time Model get method
  RT_MODEL_Auxiliary_network_12_T * getRTM();

  // private data and function members
 private:
  // Block states
  DW_Auxiliary_network_12V_T Auxiliary_network_12V_DW;

  // Real-Time Model
  RT_MODEL_Auxiliary_network_12_T Auxiliary_network_12V_M;
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
//  hilite_system('BLOC_Auxiliary_network_12V/Auxiliary_network_12V')    - opens subsystem BLOC_Auxiliary_network_12V/Auxiliary_network_12V
//  hilite_system('BLOC_Auxiliary_network_12V/Auxiliary_network_12V/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_Auxiliary_network_12V'
//  '<S1>'   : 'BLOC_Auxiliary_network_12V/Auxiliary_network_12V'
//  '<S2>'   : 'BLOC_Auxiliary_network_12V/Auxiliary_network_12V/Auxliliary network'
//  '<S3>'   : 'BLOC_Auxiliary_network_12V/Auxiliary_network_12V/CVS'

#endif                                 // RTW_HEADER_Auxiliary_network_12V_h_

//
// File trailer for generated code.
//
// [EOF]
//
