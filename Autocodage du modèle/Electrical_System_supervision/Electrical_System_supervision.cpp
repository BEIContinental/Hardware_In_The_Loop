//
// File: Electrical_System_supervision.cpp
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
#include "Electrical_System_supervision.h"
#include "Electrical_System_supervision_private.h"

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

real_T look2_binlcapw(real_T u0, real_T u1, const real_T bp0[], const real_T
                      bp1[], const real_T table[], const uint32_T maxIndex[],
                      uint32_T stride)
{
  real_T y;
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yR_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  // Lookup 2-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear'
  // Extrapolation method: 'Clip'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    // Binary Search
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
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
    iLeft = maxIndex[0U];
    frac = 0.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    // Binary Search
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0;
  }

  // Interpolation 2-D
  // Interpolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Overflow mode: 'portable wrapping'

  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    y = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yR_1d = table[bpIdx];
    } else {
      yR_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
    }

    y += (yR_1d - y) * frac;
  }

  return y;
}

// Model step function
void Electrical_System_supervisionModelClass::step()
{
  real_T rtb_Switch1;
  real_T rtb_Minwpowerneg;
  real_T rtb_A;
  real_T rtb_Switch;

  // Outputs for Atomic SubSystem: '<Root>/Electrical_System_supervision'
  // Lookup_n-D: '<S2>/Courant Charge Lookup Table' incorporates:
  //   Inport: '<Root>/SYSE_SOC'

  rtb_Minwpowerneg = look1_binlxpw(Electrical_System_supervision_U.SYSE_SOC,
    *(real_T (*)[12])&Electrical_System_superv_ConstP.pooled1[0], *(real_T (*)
    [12])&Electrical_System_superv_ConstP.CourantChargeLookupTable_tableD[0],
    11U);

  // Lookup_n-D: '<S2>/Courant Decharge Lookup Table' incorporates:
  //   Inport: '<Root>/SYSE_SOC'

  rtb_Switch1 = look1_binlxpw(Electrical_System_supervision_U.SYSE_SOC, *(real_T
    (*)[12])&Electrical_System_superv_ConstP.pooled1[0], *(real_T (*)[12])&
    Electrical_System_superv_ConstP.CourantDechargeLookupTable_tabl[0], 11U);

  // Sum: '<S3>/Subtract2'
  rtb_A = rtb_Switch1;

  // Product: '<S4>/Product2' incorporates:
  //   Inport: '<Root>/SYSE_VOLTAGE_HV'
  //   Sum: '<S3>/Subtract3'

  rtb_Switch1 = rtb_Minwpowerneg *
    Electrical_System_supervision_U.SYSE_VOLTAGE_HV;

  // Lookup_n-D: '<S4>/Min //w power neg' incorporates:
  //   Inport: '<Root>/RA_N_EM'

  rtb_Minwpowerneg = look2_binlcapw(Electrical_System_supervision_U.RA_N_EM,
    rtb_Switch1, *(real_T (*)[10])&Electrical_System_superv_ConstP.pooled3[0],
    *(real_T (*)[22])&Electrical_System_superv_ConstP.pooled4[0], *(real_T (*)
    [220])&Electrical_System_superv_ConstP.pooled2[0], *(uint32_T (*)[2])&
    Electrical_System_superv_ConstP.pooled8[0], 10U);

  // Lookup_n-D: '<S4>/Min //w power pos' incorporates:
  //   Inport: '<Root>/RA_N_EM'

  rtb_Switch1 = look2_binlcapw(Electrical_System_supervision_U.RA_N_EM,
    rtb_Switch1, *(real_T (*)[9])&Electrical_System_superv_ConstP.pooled6[0],
    *(real_T (*)[22])&Electrical_System_superv_ConstP.pooled4[0], *(real_T (*)
    [198])&Electrical_System_superv_ConstP.pooled5[0], *(uint32_T (*)[2])&
    Electrical_System_superv_ConstP.pooled9[0], 9U);

  // Product: '<S4>/Product' incorporates:
  //   Inport: '<Root>/SYSE_VOLTAGE_HV'

  rtb_A *= Electrical_System_supervision_U.SYSE_VOLTAGE_HV;

  // Lookup_n-D: '<S4>/max //w power pos' incorporates:
  //   Inport: '<Root>/RA_N_EM'

  rtb_Switch = look2_binlcapw(Electrical_System_supervision_U.RA_N_EM, rtb_A,
    *(real_T (*)[9])&Electrical_System_superv_ConstP.pooled6[0], *(real_T (*)[22])
    &Electrical_System_superv_ConstP.pooled4[0], *(real_T (*)[198])&
    Electrical_System_superv_ConstP.pooled5[0], *(uint32_T (*)[2])&
    Electrical_System_superv_ConstP.pooled9[0], 9U);

  // Lookup_n-D: '<S4>/max //w power neg' incorporates:
  //   Inport: '<Root>/RA_N_EM'

  rtb_A = look2_binlcapw(Electrical_System_supervision_U.RA_N_EM, rtb_A,
    *(real_T (*)[10])&Electrical_System_superv_ConstP.pooled3[0], *(real_T (*)
    [22])&Electrical_System_superv_ConstP.pooled4[0], *(real_T (*)[220])&
    Electrical_System_superv_ConstP.pooled2[0], *(uint32_T (*)[2])&
    Electrical_System_superv_ConstP.pooled8[0], 10U);

  // Switch: '<S4>/Switch' incorporates:
  //   Inport: '<Root>/RA_N_EM'
  //   Switch: '<S4>/Switch1'

  if (!(Electrical_System_supervision_U.RA_N_EM >= -5.0)) {
    rtb_Switch = rtb_A;
    rtb_Switch1 = rtb_Minwpowerneg;
  }

  // End of Switch: '<S4>/Switch'

  // Switch: '<S5>/Switch' incorporates:
  //   Gain: '<S5>/Efficiency P neg'
  //   Gain: '<S5>/Efficiency P pos'
  //   Inport: '<Root>/RA_N_EM'
  //   Product: '<S5>/Divide1'

  if (Electrical_System_supervision_U.RA_N_EM * rtb_Switch >= 0.0) {
    rtb_Minwpowerneg = 0.92 * rtb_Switch;
  } else {
    rtb_Minwpowerneg = 1.08 * rtb_Switch;
  }

  // Outport: '<Root>/SYSE_TQ_MAX' incorporates:
  //   Gain: '<S5>/Differential ratio'

  Electrical_System_supervision_Y.SYSE_TQ_MAX = 10.0 * rtb_Minwpowerneg;

  // Switch: '<S5>/Switch' incorporates:
  //   Gain: '<S5>/Efficiency P neg'
  //   Gain: '<S5>/Efficiency P pos'
  //   Inport: '<Root>/RA_N_EM'
  //   Product: '<S5>/Divide1'

  if (Electrical_System_supervision_U.RA_N_EM * rtb_Switch1 >= 0.0) {
    rtb_Minwpowerneg = 0.92 * rtb_Switch1;
  } else {
    rtb_Minwpowerneg = 1.08 * rtb_Switch1;
  }

  // Outport: '<Root>/SYSE_TQ_MIN' incorporates:
  //   Gain: '<S5>/Differential ratio'

  Electrical_System_supervision_Y.SYSE_TQ_MIN = 10.0 * rtb_Minwpowerneg;

  // End of Outputs for SubSystem: '<Root>/Electrical_System_supervision'
}

// Model initialize function
void Electrical_System_supervisionModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&Electrical_System_supervisio_M), (NULL));

  // external inputs
  (void) memset((void *)&Electrical_System_supervision_U, 0,
                sizeof(ExtU_Electrical_System_superv_T));

  // external outputs
  (void) memset((void *)&Electrical_System_supervision_Y, 0,
                sizeof(ExtY_Electrical_System_superv_T));
}

// Model terminate function
void Electrical_System_supervisionModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
Electrical_System_supervisionModelClass::Electrical_System_supervisionModelClass
  ()
{
}

// Destructor
Electrical_System_supervisionModelClass::
  ~Electrical_System_supervisionModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Electrical_System_su_T * Electrical_System_supervisionModelClass::
  getRTM()
{
  return (&Electrical_System_supervisio_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
