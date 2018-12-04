//
// File: Clutch_data.cpp
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
#include "Clutch.h"
#include "Clutch_private.h"

// Constant parameters (auto storage)
const ConstP_Clutch_T Clutch_ConstP = {
  // Expression: fa_clu_pos
  //  Referenced by: '<S1>/CLU_PV_SENSITIVITY'

  { 1.0, 1.0, 0.7, 0.5, 0.3, 0.0, 0.0 },

  // Expression: fa_clu_pv
  //  Referenced by: '<S1>/CLU_PV_SENSITIVITY'

  { 0.0, 0.1, 0.3, 0.5, 0.7, 0.9, 1.0 },

  // Computed Parameter: CombinatorialLogic3_table
  //  Referenced by: '<S2>/Combinatorial  Logic3'

  { 0, 1, 0, 0, 1, 1, 0, 1 }
};

//
// File trailer for generated code.
//
// [EOF]
//
