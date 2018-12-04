//
// File: Power_efficiency0.cpp
//
// Code generated for Simulink model 'Power_efficiency0'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Thu Jan 25 16:08:45 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Power_efficiency0.h"
#include "Power_efficiency0_private.h"

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  // Lookup 2-D
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
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
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
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  // Interpolation 2-D
  // Interpolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  bpIdx = iLeft * stride + bpIndices[0U];
  yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) -
          yL_1d) * frac + yL_1d;
}

// Model step function
void Power_efficiency0ModelClass::step()
{
  real_T rtb_Efficiencyconversion;
  real_T rtb_W;

  // Outputs for Atomic SubSystem: '<Root>/Power_efficiency'
  // Lookup_n-D: '<S1>/Efficiency (%)' incorporates:
  //   Inport: '<Root>/RA_N_EM'
  //   Inport: '<Root>/RA_TQ_ME'

  rtb_Efficiencyconversion = look2_binlxpw(Power_efficiency0_U.RA_TQ_ME,
    Power_efficiency0_U.RA_N_EM, *(real_T (*)[37])&
    Power_efficiency0_P.ra_electrical_machine_torque[0], *(real_T (*)[21])&
    Power_efficiency0_P.ra_electrical_machine_speed[0], *(real_T (*)[777])&
    Power_efficiency0_P.ra_electrical_machine_efficiency[0], *(uint32_T (*)[2])&
    Power_efficiency0_P.Efficiency_maxIndex[0], 37U);

  // Gain: '<S1>/Efficiency conversion'
  rtb_Efficiencyconversion *= Power_efficiency0_P.Efficiencyconversion_Gain;

  // Product: '<S1>/Product' incorporates:
  //   Gain: '<S1>/tr//min -> rad//s'
  //   Inport: '<Root>/RA_N_EM'
  //   Inport: '<Root>/RA_TQ_ME'

  rtb_W = Power_efficiency0_P.trminrads_Gain * Power_efficiency0_U.RA_N_EM *
    Power_efficiency0_U.RA_TQ_ME;

  // Switch: '<S1>/Switch' incorporates:
  //   Product: '<S1>/Divide'
  //   Product: '<S1>/Product1'

  if (rtb_W >= Power_efficiency0_P.Switch_Threshold) {
    rtb_W *= 1.0 / rtb_Efficiencyconversion;
  } else {
    rtb_W *= rtb_Efficiencyconversion;
  }

  // End of Switch: '<S1>/Switch'

  // Outport: '<Root>/RA_EM_CURRENT' incorporates:
  //   Inport: '<Root>/SYSE_VOLTAGE_HV'
  //   Product: '<S1>/Divide1'

  Power_efficiency0_Y.RA_EM_CURRENT = rtb_W /
    Power_efficiency0_U.SYSE_VOLTAGE_HV;

  // End of Outputs for SubSystem: '<Root>/Power_efficiency'
}

// Model initialize function
void Power_efficiency0ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  Power_efficiency0_P.ra_electrical_machine_efficiency[0] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[1] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[2] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[3] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[4] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[5] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[6] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[29] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[30] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[31] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[32] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[33] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[34] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[35] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[36] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[37] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[38] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[39] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[40] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[41] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[68] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[69] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[70] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[71] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[72] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[73] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[74] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[75] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[76] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[77] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[108] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[109] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[110] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[111] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[147] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[629] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[665] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[666] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[667] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[668] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[669] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[699] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[700] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[701] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[702] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[703] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[704] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[705] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[706] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[707] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[735] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[736] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[737] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[738] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[739] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[740] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[741] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[742] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[743] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[744] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[745] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[746] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[770] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[771] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[772] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[773] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[774] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[775] = rtNaN;
  Power_efficiency0_P.ra_electrical_machine_efficiency[776] = rtNaN;

  // initialize error status
  rtmSetErrorStatus((&Power_efficiency0_M), (NULL));

  // external inputs
  (void) memset((void *)&Power_efficiency0_U, 0,
                sizeof(ExtU_Power_efficiency0_T));

  // external outputs
  Power_efficiency0_Y.RA_EM_CURRENT = 0.0;
}

// Model terminate function
void Power_efficiency0ModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
Power_efficiency0ModelClass::Power_efficiency0ModelClass()
{
  static const P_Power_efficiency0_T Power_efficiency0_P_temp = {
    //  Variable: ra_electrical_machine_efficiency
    //  Referenced by: '<S1>/Efficiency (%)'

    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 91.3, 91.3, 91.3, 91.5, 91.3, 91.0,
      90.5, 89.600000000000009, 87.0, 83.0, 75.0, 40.0, 75.0, 83.0, 87.0,
      89.600000000000009, 90.5, 91.0, 91.3, 91.5, 91.3, 91.3, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 92.0, 92.0, 92.0, 92.0, 92.4,
      92.5, 92.600000000000009, 92.5, 92.300000000000011, 91.600000000000009,
      90.2, 87.0, 80.0, 40.0, 80.0, 87.0, 90.2, 91.600000000000009,
      92.300000000000011, 92.5, 92.600000000000009, 92.5, 92.4, 92.0, 92.0, 92.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 92.0, 92.0, 92.0, 93.0,
      93.300000000000011, 93.7, 93.8, 94.0, 94.199999999999989,
      94.199999999999989, 93.899999999999991, 93.0, 91.0, 85.0, 40.0, 85.0, 91.0,
      93.0, 93.899999999999991, 94.199999999999989, 94.199999999999989, 94.0,
      93.8, 93.7, 93.300000000000011, 93.0, 92.0, 92.0, 92.0, 92.0, 0.0, 0.0,
      0.0, 0.0, 90.1, 91.8, 92.0, 92.5, 92.5, 93.2, 93.5, 93.8,
      94.199999999999989, 94.3, 94.399999999999991, 94.5, 94.6, 94.3, 93.7, 92.0,
      85.0, 40.0, 85.0, 92.0, 93.7, 94.3, 94.6, 94.5, 94.399999999999991, 94.3,
      94.199999999999989, 93.8, 93.5, 93.2, 92.5, 92.2, 92.0, 91.8, 90.1, 0.0,
      90.0, 90.1, 91.8, 92.0, 92.2, 92.5, 93.0, 93.100000000000009, 93.5, 93.7,
      93.8, 94.0, 94.1, 94.199999999999989, 94.0, 93.100000000000009, 91.5, 85.0,
      40.0, 85.0, 91.5, 93.100000000000009, 94.0, 94.199999999999989, 94.1, 94.0,
      93.8, 93.7, 93.5, 93.100000000000009, 93.0, 92.5, 92.2, 92.0, 91.8, 90.1,
      90.0, 90.0, 90.100000000000009, 90.2, 90.3, 90.4, 91.100000000000009,
      91.600000000000009, 92.0, 92.4, 92.800000000000011, 93.100000000000009,
      93.4, 93.600000000000009, 93.8, 93.5, 93.0, 91.3, 85.0, 40.0, 85.0, 91.3,
      93.0, 93.5, 93.8, 93.600000000000009, 93.4, 93.100000000000009,
      92.800000000000011, 92.4, 92.0, 91.600000000000009, 91.100000000000009,
      90.4, 90.3, 90.2, 90.100000000000009, 90.0, 86.5, 87.0, 87.5, 88.0, 89.0,
      89.5, 90.100000000000009, 90.5, 91.2, 91.600000000000009,
      92.100000000000009, 92.5, 93.100000000000009, 93.2, 93.2, 93.0, 91.5, 85.0,
      40.0, 85.0, 91.5, 93.0, 93.2, 93.2, 93.100000000000009, 92.5,
      92.100000000000009, 91.600000000000009, 91.2, 90.5, 90.100000000000009,
      89.5, 89.0, 88.0, 87.5, 87.0, 86.5, 82.5, 83.5, 84.5, 85.5, 86.0, 86.5,
      87.0, 88.0, 89.2, 89.9, 90.600000000000009, 91.2, 92.0, 92.4, 92.7,
      92.600000000000009, 92.0, 86.0, 40.0, 86.0, 92.0, 92.600000000000009, 92.7,
      92.4, 92.0, 91.2, 90.600000000000009, 89.9, 89.2, 88.0, 87.0, 86.5, 86.0,
      85.5, 84.5, 83.5, 82.5, 76.0, 77.0, 78.0, 79.5, 80.5, 81.0, 82.0, 83.0,
      84.0, 86.0, 86.5, 87.5, 89.2, 90.2, 91.3, 91.7, 91.3, 87.0, 40.0, 87.0,
      91.3, 91.7, 91.3, 90.2, 89.2, 87.5, 86.5, 86.0, 84.0, 83.0, 82.0, 81.0,
      80.5, 79.5, 78.0, 77.0, 76.0, 56.000000000000007, 57.999999999999993, 60.0,
      61.0, 62.0, 63.0, 65.0, 68.0, 69.0, 70.0, 72.0, 75.0, 78.0, 80.0, 83.0,
      85.0, 87.0, 86.0, 40.0, 86.0, 87.0, 85.0, 83.0, 80.0, 78.0, 75.0, 72.0,
      70.0, 69.0, 68.0, 65.0, 63.0, 62.0, 61.0, 60.0, 57.999999999999993,
      56.000000000000007, 56.000000000000007, 57.999999999999993, 60.0, 61.0,
      62.0, 63.0, 65.0, 68.0, 69.0, 70.0, 72.0, 75.0, 78.0, 80.0, 83.0, 85.0,
      87.0, 86.0, 40.0, 86.0, 87.0, 85.0, 83.0, 80.0, 78.0, 75.0, 72.0, 70.0,
      69.0, 68.0, 65.0, 63.0, 62.0, 61.0, 60.0, 57.999999999999993,
      56.000000000000007, 56.000000000000007, 57.999999999999993, 60.0, 61.0,
      62.0, 63.0, 65.0, 68.0, 69.0, 70.0, 72.0, 75.0, 78.0, 80.0, 83.0, 85.0,
      87.0, 86.0, 40.0, 86.0, 87.0, 85.0, 83.0, 80.0, 78.0, 75.0, 72.0, 70.0,
      69.0, 68.0, 65.0, 63.0, 62.0, 61.0, 60.0, 57.999999999999993,
      56.000000000000007, 76.0, 77.0, 78.0, 79.5, 80.5, 81.0, 82.0, 83.0, 84.0,
      86.0, 86.5, 87.5, 89.2, 90.2, 91.3, 91.7, 91.3, 87.0, 40.0, 87.0, 91.3,
      91.7, 91.3, 90.2, 89.2, 87.5, 86.5, 86.0, 84.0, 83.0, 82.0, 81.0, 80.5,
      79.5, 78.0, 77.0, 76.0, 82.5, 83.5, 84.5, 85.5, 86.0, 86.5, 87.0, 88.0,
      89.2, 89.9, 90.600000000000009, 91.2, 92.0, 92.4, 92.7, 92.600000000000009,
      92.0, 86.0, 40.0, 86.0, 92.0, 92.600000000000009, 92.7, 92.4, 92.0, 91.2,
      90.600000000000009, 89.9, 89.2, 88.0, 87.0, 86.5, 86.0, 85.5, 84.5, 83.5,
      82.5, 86.5, 87.0, 87.5, 88.0, 89.0, 89.5, 90.100000000000009, 90.5, 91.2,
      91.600000000000009, 92.100000000000009, 92.5, 93.100000000000009, 93.2,
      93.2, 93.0, 91.5, 85.0, 40.0, 85.0, 91.5, 93.0, 93.2, 93.2,
      93.100000000000009, 92.5, 92.100000000000009, 91.600000000000009, 91.2,
      90.5, 90.100000000000009, 89.5, 89.0, 88.0, 87.5, 87.0, 86.5, 90.0,
      90.100000000000009, 90.2, 90.3, 90.4, 91.100000000000009,
      91.600000000000009, 92.0, 92.4, 92.800000000000011, 93.100000000000009,
      93.4, 93.600000000000009, 93.8, 93.5, 93.0, 91.3, 85.0, 40.0, 85.0, 91.3,
      93.0, 93.5, 93.8, 93.600000000000009, 93.4, 93.100000000000009,
      92.800000000000011, 92.4, 92.0, 91.600000000000009, 91.100000000000009,
      90.4, 90.3, 90.2, 90.100000000000009, 90.0, 90.0, 90.1, 91.8, 92.0, 92.2,
      92.5, 93.0, 93.100000000000009, 93.5, 93.7, 93.8, 94.0, 94.1,
      94.199999999999989, 94.0, 93.100000000000009, 91.5, 85.0, 40.0, 85.0, 91.5,
      93.100000000000009, 94.0, 94.199999999999989, 94.1, 94.0, 93.8, 93.7, 93.5,
      93.100000000000009, 93.0, 92.5, 92.2, 92.0, 91.8, 90.1, 90.0, 0.0, 90.1,
      91.8, 92.0, 92.5, 92.5, 93.2, 93.5, 93.8, 94.199999999999989, 94.3,
      94.399999999999991, 94.5, 94.6, 94.3, 93.7, 92.0, 85.0, 40.0, 85.0, 92.0,
      93.7, 94.3, 94.6, 94.5, 94.399999999999991, 94.3, 94.199999999999989, 93.8,
      93.5, 93.2, 92.5, 92.5, 92.5, 91.8, 90.1, 0.0, 0.0, 0.0, 0.0, 0.0, 92.0,
      92.0, 92.0, 93.0, 93.300000000000011, 93.7, 93.8, 94.0, 94.199999999999989,
      94.199999999999989, 93.899999999999991, 93.0, 91.0, 85.0, 40.0, 85.0, 91.0,
      93.0, 93.899999999999991, 94.199999999999989, 94.199999999999989, 94.0,
      93.8, 93.7, 93.300000000000011, 93.0, 92.0, 92.0, 92.5, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 92.0, 92.0, 92.0, 92.0, 92.4, 92.5,
      92.600000000000009, 92.5, 92.300000000000011, 91.600000000000009, 90.2,
      87.0, 80.0, 40.0, 80.0, 87.0, 90.2, 91.600000000000009, 92.300000000000011,
      92.5, 92.600000000000009, 92.5, 92.4, 92.0, 92.0, 92.0, 92.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 91.3, 91.3, 91.3, 91.5,
      91.3, 91.0, 90.5, 89.600000000000009, 87.0, 83.0, 75.0, 40.0, 75.0, 83.0,
      87.0, 89.600000000000009, 90.5, 91.0, 91.3, 91.5, 91.3, 91.3, 91.3, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    //  Variable: ra_electrical_machine_speed
    //  Referenced by: '<S1>/Efficiency (%)'

    { -12000.0, -10800.0, -9600.0, -8400.0, -7200.0, -6000.0, -4800.0, -3600.0,
      -2400.0, -1200.0, 0.0, 1200.0, 2400.0, 3600.0, 4800.0, 6000.0, 7200.0,
      8400.0, 9600.0, 10800.0, 12000.0 },

    //  Variable: ra_electrical_machine_torque
    //  Referenced by: '<S1>/Efficiency (%)'

    { -79.646017699115035, -75.221238938053091, -70.796460176991147,
      -66.3716814159292, -61.946902654867252, -57.522123893805308,
      -53.097345132743357, -48.672566371681413, -44.247787610619469,
      -39.823008849557517, -35.398230088495573, -30.973451327433626,
      -26.548672566371678, -22.123893805309734, -17.699115044247787,
      -13.274336283185839, -8.8495575221238933, -4.4247787610619467, 0.0,
      4.4247787610619467, 8.8495575221238933, 13.274336283185839,
      17.699115044247787, 22.123893805309734, 26.548672566371678,
      30.973451327433626, 35.398230088495573, 39.823008849557517,
      44.247787610619469, 48.672566371681413, 53.097345132743357,
      57.522123893805308, 61.946902654867252, 66.3716814159292,
      70.796460176991147, 75.221238938053091, 79.646017699115035 },
    0.01,                              // Expression: 1/100
                                       //  Referenced by: '<S1>/Efficiency conversion'

    0.10471975511965977,               // Expression: 2*pi/60
                                       //  Referenced by: '<S1>/tr//min -> rad//s'

    0.0,                               // Expression: 0
                                       //  Referenced by: '<S1>/Switch'


    //  Computed Parameter: Efficiency_maxIndex
    //  Referenced by: '<S1>/Efficiency (%)'

    { 36U, 20U }
  };                                   // Modifiable parameters

  // Initialize tunable parameters
  Power_efficiency0_P = Power_efficiency0_P_temp;
}

// Destructor
Power_efficiency0ModelClass::~Power_efficiency0ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Power_efficiency0_T * Power_efficiency0ModelClass::getRTM()
{
  return (&Power_efficiency0_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
