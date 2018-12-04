//
// File: ICE.cpp
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
#include "ICE.h"
#include "ICE_private.h"

// Named constants for Chart: '<S2>/Chart'
#define ICE_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define ICE_IN_STATE_1                 ((uint8_T)1U)
#define ICE_IN_STATE_21                ((uint8_T)2U)
#define ICE_IN_STATE_22                ((uint8_T)3U)
#define ICE_IN_STATE_3                 ((uint8_T)4U)
#define ICE_IN_STATE_4                 ((uint8_T)5U)
#define ICE_IN_STATE_5                 ((uint8_T)6U)

real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T y;
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Lookup 1-D
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
    iLeft = maxIndex;
    frac = 0.0;
  }

  // Interpolation 1-D
  // Interpolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Overflow mode: 'portable wrapping'

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
  }

  return y;
}

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
void ICEModelClass::step()
{
  real_T rtb_Switch1;
  real_T rtb_DiscreteTransferFcn3;
  real_T rtb_Delay;
  real_T rtb_Switch1_n;
  real_T DiscreteTransferFcn3_tmp;

  // Outputs for Atomic SubSystem: '<Root>/ICE'
  // DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn3' incorporates:
  //   Inport: '<Root>/FA_ICE_TQ_SP'

  DiscreteTransferFcn3_tmp = ICE_U.FA_ICE_TQ_SP - -0.7389033942558747 *
    ICE_DW.DiscreteTransferFcn3_states;
  rtb_DiscreteTransferFcn3 = 0.13054830287206268 * DiscreteTransferFcn3_tmp +
    0.13054830287206268 * ICE_DW.DiscreteTransferFcn3_states;

  // Lookup_n-D: '<S1>/TQ_STARTER' incorporates:
  //   Inport: '<Root>/FA_N_ICE'

  rtb_Delay = look1_binlcapw(ICE_U.FA_N_ICE, *(real_T (*)[101])&
    ICE_ConstP.TQ_STARTER_bp01Data[0], *(real_T (*)[101])&
    ICE_ConstP.TQ_STARTER_tableData[0], 100U);

  // Switch: '<S1>/Switch1' incorporates:
  //   Constant: '<S1>/Constant4'
  //   Inport: '<Root>/FA_STARTER_REQUEST'

  if (ICE_U.FA_STARTER_REQUEST != 0.0) {
    rtb_Switch1 = rtb_Delay;
  } else {
    rtb_Switch1 = 0.0;
  }

  // End of Switch: '<S1>/Switch1'

  // Lookup_n-D: '<S1>/TQ_LOSS' incorporates:
  //   Inport: '<Root>/FA_N_ICE'

  rtb_Delay = look1_binlxpw(ICE_U.FA_N_ICE, *(real_T (*)[18])&
    ICE_ConstP.TQ_LOSS_bp01Data[0], *(real_T (*)[18])&
    ICE_ConstP.TQ_LOSS_tableData[0], 17U);

  // Chart: '<S2>/Chart' incorporates:
  //   Constant: '<S2>/fa_conso_idle'
  //   Inport: '<Root>/FA_ICE_STATE'

  // Gateway: ICE/Gas consumption/Chart
  // During: ICE/Gas consumption/Chart
  if (ICE_DW.is_active_c1_ICE == 0U) {
    // Entry: ICE/Gas consumption/Chart
    ICE_DW.is_active_c1_ICE = 1U;

    // Entry Internal: ICE/Gas consumption/Chart
    // Transition: '<S3>:46'
    ICE_DW.is_c1_ICE = ICE_IN_STATE_1;
    ICE_DW.tp_STATE_1 = 1U;
  } else {
    switch (ICE_DW.is_c1_ICE) {
     case ICE_IN_STATE_1:
      // During 'STATE_1': '<S3>:44'
      // '<S3>:45:1' sf_internal_predicateOutput = ...
      // '<S3>:45:1' (FA_ICE_STATE==2.1);
      if (ICE_U.FA_ICE_STATE == 2.1) {
        // Transition: '<S3>:45'
        ICE_DW.tp_STATE_1 = 0U;
        ICE_DW.is_c1_ICE = ICE_IN_STATE_21;
      } else {
        // '<S3>:55:1' sf_internal_predicateOutput = ...
        // '<S3>:55:1' (FA_ICE_STATE==5);
        if (ICE_U.FA_ICE_STATE == 5.0) {
          // Transition: '<S3>:55'
          ICE_DW.tp_STATE_1 = 0U;
          ICE_DW.is_c1_ICE = ICE_IN_STATE_5;
        } else {
          // '<S3>:74:1' sf_internal_predicateOutput = ...
          // '<S3>:74:1' (FA_ICE_STATE==2.2);
          if (ICE_U.FA_ICE_STATE == 2.2) {
            // Transition: '<S3>:74'
            ICE_DW.tp_STATE_1 = 0U;
            ICE_DW.is_c1_ICE = ICE_IN_STATE_22;
          } else {
            // '<S3>:75:1' sf_internal_predicateOutput = ...
            // '<S3>:75:1' (FA_ICE_STATE==3);
            if (ICE_U.FA_ICE_STATE == 3.0) {
              // Transition: '<S3>:75'
              ICE_DW.tp_STATE_1 = 0U;
              ICE_DW.is_c1_ICE = ICE_IN_STATE_3;
            } else {
              // '<S3>:44:1' FA_GAS_CONSUMPTION=0;
              ICE_B.FA_GAS_CONSUMPTION = 0.0;
            }
          }
        }
      }
      break;

     case ICE_IN_STATE_21:
      // During 'STATE_21': '<S3>:43'
      // '<S3>:59:1' sf_internal_predicateOutput = ...
      // '<S3>:59:1' (FA_ICE_STATE==1);
      if (ICE_U.FA_ICE_STATE == 1.0) {
        // Transition: '<S3>:59'
        ICE_DW.is_c1_ICE = ICE_IN_STATE_1;
        ICE_DW.tp_STATE_1 = 1U;
      } else {
        // '<S3>:62:1' sf_internal_predicateOutput = ...
        // '<S3>:62:1' (FA_ICE_STATE==2.2);
        if (ICE_U.FA_ICE_STATE == 2.2) {
          // Transition: '<S3>:62'
          ICE_DW.is_c1_ICE = ICE_IN_STATE_22;
        } else {
          // '<S3>:43:1' FA_GAS_CONSUMPTION=0;
          ICE_B.FA_GAS_CONSUMPTION = 0.0;
        }
      }
      break;

     case ICE_IN_STATE_22:
      // During 'STATE_22': '<S3>:51'
      // '<S3>:60:1' sf_internal_predicateOutput = ...
      // '<S3>:60:1' (FA_ICE_STATE==3);
      if (ICE_U.FA_ICE_STATE == 3.0) {
        // Transition: '<S3>:60'
        ICE_DW.is_c1_ICE = ICE_IN_STATE_3;
      } else {
        // '<S3>:52:1' sf_internal_predicateOutput = ...
        // '<S3>:52:1' (FA_ICE_STATE==1);
        if (ICE_U.FA_ICE_STATE == 1.0) {
          // Transition: '<S3>:52'
          ICE_DW.is_c1_ICE = ICE_IN_STATE_1;
          ICE_DW.tp_STATE_1 = 1U;
        } else {
          // '<S3>:61:1' sf_internal_predicateOutput = ...
          // '<S3>:61:1' (FA_ICE_STATE==4);
          if (ICE_U.FA_ICE_STATE == 4.0) {
            // Transition: '<S3>:61'
            ICE_DW.is_c1_ICE = ICE_IN_STATE_4;
          } else {
            // '<S3>:67:1' sf_internal_predicateOutput = ...
            // '<S3>:67:1' ((FA_ICE_STATE==5.1)||(FA_ICE_STATE==5.2));
            if ((ICE_U.FA_ICE_STATE == 5.1) || (ICE_U.FA_ICE_STATE == 5.2)) {
              // Transition: '<S3>:67'
              ICE_DW.is_c1_ICE = ICE_IN_STATE_5;
            } else {
              // '<S3>:51:1' FA_GAS_CONSUMPTION=0;
              ICE_B.FA_GAS_CONSUMPTION = 0.0;
            }
          }
        }
      }
      break;

     case ICE_IN_STATE_3:
      // During 'STATE_3': '<S3>:53'
      // '<S3>:56:1' sf_internal_predicateOutput = ...
      // '<S3>:56:1' (FA_ICE_STATE==4);
      if (ICE_U.FA_ICE_STATE == 4.0) {
        // Transition: '<S3>:56'
        ICE_DW.is_c1_ICE = ICE_IN_STATE_4;
      } else {
        // '<S3>:50:1' sf_internal_predicateOutput = ...
        // '<S3>:50:1' (FA_ICE_STATE==1);
        if (ICE_U.FA_ICE_STATE == 1.0) {
          // Transition: '<S3>:50'
          ICE_DW.is_c1_ICE = ICE_IN_STATE_1;
          ICE_DW.tp_STATE_1 = 1U;
        } else {
          // '<S3>:64:1' sf_internal_predicateOutput = ...
          // '<S3>:64:1' ((FA_ICE_STATE==5.1)||(FA_ICE_STATE==5.2));
          if ((ICE_U.FA_ICE_STATE == 5.1) || (ICE_U.FA_ICE_STATE == 5.2)) {
            // Transition: '<S3>:64'
            ICE_DW.is_c1_ICE = ICE_IN_STATE_5;
          } else {
            // '<S3>:65:1' sf_internal_predicateOutput = ...
            // '<S3>:65:1' (FA_ICE_STATE==2);
            if (ICE_U.FA_ICE_STATE == 2.0) {
              // Transition: '<S3>:65'
              ICE_DW.is_c1_ICE = ICE_IN_STATE_22;
            } else {
              // '<S3>:68:1' sf_internal_predicateOutput = ...
              // '<S3>:68:1' (FA_ICE_STATE==2.1);
              if (ICE_U.FA_ICE_STATE == 2.1) {
                // Transition: '<S3>:68'
                ICE_DW.is_c1_ICE = ICE_IN_STATE_21;
              } else {
                // '<S3>:53:1' FA_GAS_CONSUMPTION=fa_conso_idle;
                ICE_B.FA_GAS_CONSUMPTION = 0.15361111111111109;
              }
            }
          }
        }
      }
      break;

     case ICE_IN_STATE_4:
      // During 'STATE_4': '<S3>:63'
      // '<S3>:57:1' sf_internal_predicateOutput = ...
      // '<S3>:57:1' (FA_ICE_STATE==3);
      if (ICE_U.FA_ICE_STATE == 3.0) {
        // Transition: '<S3>:57'
        ICE_DW.is_c1_ICE = ICE_IN_STATE_3;
      } else {
        // '<S3>:48:1' sf_internal_predicateOutput = ...
        // '<S3>:48:1' ((FA_ICE_STATE==5.1)||(FA_ICE_STATE==5.2));
        if ((ICE_U.FA_ICE_STATE == 5.1) || (ICE_U.FA_ICE_STATE == 5.2)) {
          // Transition: '<S3>:48'
          ICE_DW.is_c1_ICE = ICE_IN_STATE_5;
        } else {
          // '<S3>:54:1' sf_internal_predicateOutput = ...
          // '<S3>:54:1' (FA_ICE_STATE==1);
          if (ICE_U.FA_ICE_STATE == 1.0) {
            // Transition: '<S3>:54'
            ICE_DW.is_c1_ICE = ICE_IN_STATE_1;
            ICE_DW.tp_STATE_1 = 1U;
          } else {
            // '<S3>:69:1' sf_internal_predicateOutput = ...
            // '<S3>:69:1' (FA_ICE_STATE==2.1);
            if (ICE_U.FA_ICE_STATE == 2.1) {
              // Transition: '<S3>:69'
              ICE_DW.is_c1_ICE = ICE_IN_STATE_21;
            } else {
              // '<S3>:63:1' FA_GAS_CONSUMPTION=fa_conso_idle;
              ICE_B.FA_GAS_CONSUMPTION = 0.15361111111111109;
            }
          }
        }
      }
      break;

     default:
      // During 'STATE_5': '<S3>:47'
      // '<S3>:42:1' sf_internal_predicateOutput = ...
      // '<S3>:42:1' (FA_ICE_STATE==4);
      if (ICE_U.FA_ICE_STATE == 4.0) {
        // Transition: '<S3>:42'
        ICE_DW.is_c1_ICE = ICE_IN_STATE_4;
      } else {
        // '<S3>:58:1' sf_internal_predicateOutput = ...
        // '<S3>:58:1' (FA_ICE_STATE==1);
        if (ICE_U.FA_ICE_STATE == 1.0) {
          // Transition: '<S3>:58'
          ICE_DW.is_c1_ICE = ICE_IN_STATE_1;
          ICE_DW.tp_STATE_1 = 1U;
        } else {
          // '<S3>:49:1' sf_internal_predicateOutput = ...
          // '<S3>:49:1' (FA_ICE_STATE==3);
          if (ICE_U.FA_ICE_STATE == 3.0) {
            // Transition: '<S3>:49'
            ICE_DW.is_c1_ICE = ICE_IN_STATE_3;
          } else {
            // '<S3>:47:1' FA_GAS_CONSUMPTION=0;
            ICE_B.FA_GAS_CONSUMPTION = 0.0;
          }
        }
      }
      break;
    }
  }

  // End of Chart: '<S2>/Chart'

  // Lookup_n-D: '<S2>/Lookup table consumption' incorporates:
  //   Inport: '<Root>/FA_N_ICE'

  rtb_Switch1_n = look2_binlcapw(rtb_DiscreteTransferFcn3, ICE_U.FA_N_ICE,
    *(real_T (*)[43])&ICE_ConstP.Lookuptableconsumption_bp01Data[0], *(real_T (*)
    [56])&ICE_ConstP.Lookuptableconsumption_bp02Data[0], *(real_T (*)[2408])
    ICE_ConstInitP.Lookuptableconsumption_tableDat, *(uint32_T (*)[2])&
    ICE_ConstP.Lookuptableconsumption_maxIndex[0], 43U);

  // Switch: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/Constant'
  //   Inport: '<Root>/FA_N_ICE'
  //   Product: '<S2>/Product3'

  if (!(rtb_DiscreteTransferFcn3 * ICE_U.FA_N_ICE > 0.0)) {
    rtb_Switch1_n = 0.0;
  }

  // End of Switch: '<S2>/Switch'

  // Switch: '<S2>/Switch1' incorporates:
  //   Constant: '<S2>/Constant1'
  //   Gain: '<S2>/W -> kW'
  //   Gain: '<S2>/g//h -> g//s'
  //   Gain: '<S2>/tr//m->rad//s'
  //   Inport: '<Root>/FA_ICE_STATE'
  //   Inport: '<Root>/FA_N_ICE'
  //   Product: '<S2>/Product1'
  //   Product: '<S2>/Product2'
  //   RelationalOperator: '<S2>/RelationalOperator1'

  if (ICE_U.FA_ICE_STATE <= 5.0) {
    rtb_Switch1_n = ICE_B.FA_GAS_CONSUMPTION;
  } else {
    rtb_Switch1_n = 0.10471975511965977 * ICE_U.FA_N_ICE *
      rtb_DiscreteTransferFcn3 * 0.001 * rtb_Switch1_n * 0.00027777777777777778;
  }

  // End of Switch: '<S2>/Switch1'

  // Switch: '<S2>/Switch2' incorporates:
  //   Delay: '<S2>/Delay'
  //   RelationalOperator: '<S2>/Relational Operator1'

  if (rtIsNaN(rtb_Switch1_n)) {
    rtb_Switch1_n = ICE_DW.Delay_DSTATE;
  }

  // End of Switch: '<S2>/Switch2'

  // Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn3'
  ICE_DW.DiscreteTransferFcn3_states = DiscreteTransferFcn3_tmp;

  // Update for Delay: '<S2>/Delay'
  ICE_DW.Delay_DSTATE = rtb_Switch1_n;

  // End of Outputs for SubSystem: '<Root>/ICE'

  // Outport: '<Root>/FA_GAS_CONSUMPTION'
  ICE_Y.FA_GAS_CONSUMPTION = rtb_Switch1_n;

  // Outputs for Atomic SubSystem: '<Root>/ICE'
  // Outport: '<Root>/FA_TQ_ICE' incorporates:
  //   Sum: '<S1>/Add1'

  ICE_Y.FA_TQ_ICE = (rtb_DiscreteTransferFcn3 + rtb_Switch1) + rtb_Delay;

  // End of Outputs for SubSystem: '<Root>/ICE'

  // Outport: '<Root>/FA_TQ_STARTER'
  ICE_Y.FA_TQ_STARTER = rtb_Switch1;
}

// Model initialize function
void ICEModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  ICE_ConstInitP.Lookuptableconsumption_tableDat[0] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[3] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[4] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[5] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[6] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[7] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[8] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[9] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[10] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[11] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[12] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[13] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[14] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[15] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[16] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[17] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[18] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[19] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[20] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[21] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[22] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[23] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[24] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[25] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[26] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[27] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[28] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[29] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[30] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[31] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[32] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[33] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[34] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[35] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[36] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[37] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[38] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[39] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[40] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[41] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[42] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[43] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[44] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[45] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[46] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[47] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[48] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[49] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[50] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[51] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[52] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[53] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[54] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[55] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[56] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[57] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[58] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[59] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[60] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[61] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[62] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[63] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[64] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[65] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[66] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[67] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[68] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[69] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[70] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[71] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[72] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[73] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[74] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[75] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[76] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[77] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[78] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[79] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[80] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[81] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[82] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[83] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[84] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[85] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[86] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[87] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[88] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[89] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[90] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[91] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[92] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[93] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[94] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[95] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[96] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[97] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[98] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[99] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[100] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[101] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[102] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[103] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[104] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[105] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[106] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[107] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[108] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[109] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[110] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[111] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[112] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[113] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[114] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[115] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[116] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[117] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[118] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[119] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[120] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[121] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[122] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[123] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[124] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[125] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[126] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[127] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[128] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[163] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[164] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[165] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[166] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[167] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[168] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[169] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[170] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[171] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[206] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[207] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[208] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[209] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[210] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[211] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[212] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[213] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[214] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[249] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[250] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[251] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[252] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[253] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[254] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[255] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[256] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[257] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[294] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[295] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[296] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[297] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[298] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[299] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[300] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[338] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[339] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[340] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[341] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[342] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[343] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[382] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[383] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[384] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[385] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[386] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[426] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[427] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[428] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[429] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[469] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[470] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[471] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[472] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[512] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[513] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[514] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[515] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[556] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[557] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[558] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[599] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[600] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[601] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[643] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[644] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[686] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[687] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[729] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[730] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[772] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[773] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[816] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[859] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[902] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[945] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[988] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1031] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1074] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1117] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1160] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1203] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1246] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1289] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1332] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1375] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1418] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1461] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1504] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1547] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1590] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1633] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1676] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1719] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1762] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1805] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1848] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1890] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1891] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1933] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1934] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1975] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1976] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[1977] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2017] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2018] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2019] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2020] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2060] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2061] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2062] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2063] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2103] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2104] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2105] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2106] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2145] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2146] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2147] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2148] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2149] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2187] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2188] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2189] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2190] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2191] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2192] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2229] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2230] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2231] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2232] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2233] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2234] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2235] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2271] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2272] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2273] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2274] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2275] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2276] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2277] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2278] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2312] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2313] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2314] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2315] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2316] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2317] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2318] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2319] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2320] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2321] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2354] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2355] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2356] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2357] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2358] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2359] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2360] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2361] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2362] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2363] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2364] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2365] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2366] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2367] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2368] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2369] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2370] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2371] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2372] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2373] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2374] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2375] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2376] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2377] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2378] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2379] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2380] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2381] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2382] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2383] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2384] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2385] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2386] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2387] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2388] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2389] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2390] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2391] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2392] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2393] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2394] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2395] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2396] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2397] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2398] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2399] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2400] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2401] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2402] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2403] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2404] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2405] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2406] = rtNaN;
  ICE_ConstInitP.Lookuptableconsumption_tableDat[2407] = rtNaN;

  // initialize error status
  rtmSetErrorStatus((&ICE_M), (NULL));

  // block I/O
  (void) memset(((void *) &ICE_B), 0,
                sizeof(B_ICE_T));

  // states (dwork)
  (void) memset((void *)&ICE_DW, 0,
                sizeof(DW_ICE_T));

  // external inputs
  (void) memset((void *)&ICE_U, 0,
                sizeof(ExtU_ICE_T));

  // external outputs
  (void) memset((void *)&ICE_Y, 0,
                sizeof(ExtY_ICE_T));

  // SystemInitialize for Atomic SubSystem: '<Root>/ICE'
  // SystemInitialize for Chart: '<S2>/Chart'
  ICE_DW.tp_STATE_1 = 0U;
  ICE_DW.is_active_c1_ICE = 0U;
  ICE_DW.is_c1_ICE = ICE_IN_NO_ACTIVE_CHILD;

  // End of SystemInitialize for SubSystem: '<Root>/ICE'
}

// Model terminate function
void ICEModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
ICEModelClass::ICEModelClass()
{
}

// Destructor
ICEModelClass::~ICEModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_ICE_T * ICEModelClass::getRTM()
{
  return (&ICE_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
