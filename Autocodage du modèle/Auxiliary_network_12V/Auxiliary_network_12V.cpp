//
// File: Auxiliary_network_12V.cpp
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
#include "Auxiliary_network_12V.h"
#include "Auxiliary_network_12V_private.h"

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Interpolation 1-D
  // Interpolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

// Model step function
void Auxiliary_network_12VModelClass::step()
{
  real_T rtb_rendementCVS;

  // Outputs for Atomic SubSystem: '<Root>/Auxiliary_network_12V'
  // Outport: '<Root>/SYSE_AUX_CURRENT' incorporates:
  //   Delay: '<S3>/Delay'

  Auxiliary_network_12V_Y.SYSE_AUX_CURRENT =
    Auxiliary_network_12V_DW.Delay_DSTATE;

  // Lookup_n-D: '<S3>/rendement CVS'
  rtb_rendementCVS = look1_binlxpw(399.59999999999997, *(real_T (*)[6])&
    Auxiliary_network_12V_ConstP.rendementCVS_bp01Data[0], *(real_T (*)[6])&
    Auxiliary_network_12V_ConstP.rendementCVS_tableData[0], 5U);

  // Update for Delay: '<S3>/Delay' incorporates:
  //   Inport: '<Root>/SYSE_VOLTAGE_HV'
  //   Product: '<S3>/Divide'
  //   Product: '<S3>/Divide1'

  Auxiliary_network_12V_DW.Delay_DSTATE = 1.0 / rtb_rendementCVS *
    399.59999999999997 / Auxiliary_network_12V_U.SYSE_VOLTAGE_HV;

  // End of Outputs for SubSystem: '<Root>/Auxiliary_network_12V'
}

// Model initialize function
void Auxiliary_network_12VModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&Auxiliary_network_12V_M), (NULL));

  // states (dwork)
  (void) memset((void *)&Auxiliary_network_12V_DW, 0,
                sizeof(DW_Auxiliary_network_12V_T));

  // external inputs
  Auxiliary_network_12V_U.SYSE_VOLTAGE_HV = 0.0;

  // external outputs
  Auxiliary_network_12V_Y.SYSE_AUX_CURRENT = 0.0;
}

// Model terminate function
void Auxiliary_network_12VModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
Auxiliary_network_12VModelClass::Auxiliary_network_12VModelClass()
{
}

// Destructor
Auxiliary_network_12VModelClass::~Auxiliary_network_12VModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Auxiliary_network_12_T * Auxiliary_network_12VModelClass::getRTM()
{
  return (&Auxiliary_network_12V_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
