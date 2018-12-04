//
// File: Electrical_System_supervision.h
//
// Code generated for Simulink model 'Electrical_System_supervision'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 09:11:10 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Electrical_System_supervision_h_
#define RTW_HEADER_Electrical_System_supervision_h_
#include <stddef.h>
#include <string.h>
#ifndef Electrical_System_supervision_COMMON_INCLUDES_
# define Electrical_System_supervision_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Electrical_System_supervision_COMMON_INCLUDES_ 

#include "Electrical_System_supervision_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Constant parameters (auto storage)
typedef struct {
  // Expression: -syse_max_charge_current
  //  Referenced by: '<S2>/Courant Charge Lookup Table'

  real_T CourantChargeLookupTable_tableD[12];

  // Pooled Parameter (Expression: syse_soc_current_limits/100)
  //  Referenced by:
  //    '<S2>/Courant Charge Lookup Table'
  //    '<S2>/Courant Decharge Lookup Table'

  real_T pooled1[12];

  // Expression: syse_max_discharge_current
  //  Referenced by: '<S2>/Courant Decharge Lookup Table'

  real_T CourantDechargeLookupTable_tabl[12];

  // Pooled Parameter (Expression: syse_electrical_machine_torque_vs_power_speed_nneg)
  //  Referenced by:
  //    '<S4>/Min //w power neg'
  //    '<S4>/max //w power neg'

  real_T pooled2[220];

  // Pooled Parameter (Expression: ra_electrical_machine_speed(1:10))
  //  Referenced by:
  //    '<S4>/Min //w power neg'
  //    '<S4>/max //w power neg'

  real_T pooled3[10];

  // Pooled Parameter (Expression: syse_em_in_power*1000)
  //  Referenced by:
  //    '<S4>/Min //w power neg'
  //    '<S4>/Min //w power pos'
  //    '<S4>/max //w power neg'
  //    '<S4>/max //w power pos'

  real_T pooled4[22];

  // Pooled Parameter (Expression: syse_electrical_machine_torque_vs_power_speed_npos)
  //  Referenced by:
  //    '<S4>/Min //w power pos'
  //    '<S4>/max //w power pos'

  real_T pooled5[198];

  // Pooled Parameter (Expression: ra_electrical_machine_speed(12:20))
  //  Referenced by:
  //    '<S4>/Min //w power pos'
  //    '<S4>/max //w power pos'

  real_T pooled6[9];

  // Pooled Parameter (Expression: )
  //  Referenced by:
  //    '<S4>/Min //w power neg'
  //    '<S4>/max //w power neg'

  uint32_T pooled8[2];

  // Pooled Parameter (Expression: )
  //  Referenced by:
  //    '<S4>/Min //w power pos'
  //    '<S4>/max //w power pos'

  uint32_T pooled9[2];
} ConstP_Electrical_System_supe_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T RA_N_EM;                      // '<Root>/RA_N_EM'
  real_T SYSE_SOC;                     // '<Root>/SYSE_SOC'
  real_T SYSE_AUX_CURRENT;             // '<Root>/SYSE_AUX_CURRENT'
  real_T SYSE_VOLTAGE_HV;              // '<Root>/SYSE_VOLTAGE_HV'
} ExtU_Electrical_System_superv_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T SYSE_TQ_MAX;                  // '<Root>/SYSE_TQ_MAX'
  real_T SYSE_TQ_MIN;                  // '<Root>/SYSE_TQ_MIN'
} ExtY_Electrical_System_superv_T;

// Real-time Model Data Structure
struct tag_RTM_Electrical_System_sup_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstP_Electrical_System_supe_T Electrical_System_superv_ConstP;

// Class declaration for model Electrical_System_supervision
class Electrical_System_supervisionModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_Electrical_System_superv_T Electrical_System_supervision_U;

  // External outputs
  ExtY_Electrical_System_superv_T Electrical_System_supervision_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Electrical_System_supervisionModelClass();

  // Destructor
  ~Electrical_System_supervisionModelClass();

  // Real-Time Model get method
  RT_MODEL_Electrical_System_su_T * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_Electrical_System_su_T Electrical_System_supervisio_M;
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
//  hilite_system('BLOC_Electrical_System_supervision/Electrical_System_supervision')    - opens subsystem BLOC_Electrical_System_supervision/Electrical_System_supervision
//  hilite_system('BLOC_Electrical_System_supervision/Electrical_System_supervision/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BLOC_Electrical_System_supervision'
//  '<S1>'   : 'BLOC_Electrical_System_supervision/Electrical_System_supervision'
//  '<S2>'   : 'BLOC_Electrical_System_supervision/Electrical_System_supervision/Battery charge // discharge limits'
//  '<S3>'   : 'BLOC_Electrical_System_supervision/Electrical_System_supervision/Current loop'
//  '<S4>'   : 'BLOC_Electrical_System_supervision/Electrical_System_supervision/Min max '
//  '<S5>'   : 'BLOC_Electrical_System_supervision/Electrical_System_supervision/Torque conversion'

#endif                                 // RTW_HEADER_Electrical_System_supervision_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
