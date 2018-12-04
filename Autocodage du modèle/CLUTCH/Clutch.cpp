//
// File: Clutch.cpp
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

// Model step function
void ClutchModelClass::step()
{
  int32_T rowIdx;
  real_T rtb_Ratioofstatictokinetic;
  real_T rtb_trminrads;
  real_T rtb_Switch1;
  real_T rtb_EngineInertia1;

  // Outputs for Atomic SubSystem: '<Root>/Clutch'
  // Gain: '<S1>/ tr//min > rad//s' incorporates:
  //   Delay: '<S1>/Delay2'

  rtb_trminrads = 0.10471975511965977 * Clutch_DW.Delay2_DSTATE;

  // Switch: '<S1>/Switch2' incorporates:
  //   Constant: '<S1>/Constant'
  //   Inport: '<Root>/CMD_CLUTCH_SP'
  //   Inport: '<Root>/DRI_GBX_SP'

  if (Clutch_U.DRI_GBX_SP != 0.0) {
    rtb_Ratioofstatictokinetic = Clutch_U.CMD_CLUTCH_SP;
  } else {
    rtb_Ratioofstatictokinetic = 1.0;
  }

  // End of Switch: '<S1>/Switch2'

  // Lookup_n-D: '<S1>/CLU_PV_SENSITIVITY'
  rtb_Ratioofstatictokinetic = look1_binlcapw(rtb_Ratioofstatictokinetic,
    *(real_T (*)[7])&Clutch_ConstP.CLU_PV_SENSITIVITY_bp01Data[0], *(real_T (*)
    [7])&Clutch_ConstP.CLU_PV_SENSITIVITY_tableData[0], 6U);

  // Product: '<S1>/Prodct' incorporates:
  //   Constant: '<S1>/fa_max_tq_clu'

  rtb_Ratioofstatictokinetic *= 206.0;

  // Relay: '<S1>/Relay' incorporates:
  //   Delay: '<S1>/Delay4'

  if (Clutch_DW.Delay4_DSTATE >= 0.0) {
    Clutch_DW.Relay_Mode = true;
  } else {
    if (Clutch_DW.Delay4_DSTATE <= 0.0) {
      Clutch_DW.Relay_Mode = false;
    }
  }

  if (Clutch_DW.Relay_Mode) {
    rowIdx = 1;
  } else {
    rowIdx = -1;
  }

  // End of Relay: '<S1>/Relay'

  // Product: '<S1>/Max Dynamic Friction Torque'
  rtb_Switch1 = rtb_Ratioofstatictokinetic * (real_T)rowIdx;

  // Gain: '<S1>/Engine Inertia1' incorporates:
  //   Delay: '<S1>/Delay'
  //   Sum: '<S1>/E_Sum'

  rtb_EngineInertia1 = (Clutch_DW.Delay_DSTATE - rtb_Switch1) *
    17.241379310344826;

  // Gain: '<S1>/Ratio of static to kinetic'
  rtb_Ratioofstatictokinetic *= 1.5;

  // CombinatorialLogic: '<S2>/Combinatorial  Logic3' incorporates:
  //   Abs: '<S2>/Abs'
  //   Abs: '<S2>/Abs1'
  //   Abs: '<S2>/Abs2'
  //   Constant: '<S3>/Constant'
  //   Delay: '<S1>/Delay'
  //   Delay: '<S1>/Delay3'
  //   Delay: '<S2>/Delay'
  //   Logic: '<S2>/Logic'
  //   RelationalOperator: '<S2>/Relational Operator'
  //   RelationalOperator: '<S2>/Relational Operator1'
  //   RelationalOperator: '<S3>/Compare'
  //   Sum: '<S2>/Sum1'
  //
  //  Block description for '<S2>/Combinatorial  Logic3':
  //   TRUTH_TABLE_FROM_FABIEN

  rowIdx = (int32_T)(((((uint32_T)((fabs(Clutch_DW.Delay3_DSTATE - rtb_trminrads)
    <= 40.0) && (fabs(Clutch_DW.Delay_DSTATE) <= rtb_Ratioofstatictokinetic)) <<
                        1) + (rtb_Ratioofstatictokinetic <= fabs
    (Clutch_DW.Delay_DSTATE))) << 1) + Clutch_DW.Delay_DSTATE_m);

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
  //   CombinatorialLogic: '<S2>/Combinatorial  Logic3'
  //
  //  Block description for '<S2>/Combinatorial  Logic3':
  //   TRUTH_TABLE_FROM_FABIEN

  if (Clutch_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    Clutch_DW.DiscreteTimeIntegrator_DSTATE = rtb_trminrads;
    rtb_Ratioofstatictokinetic = Clutch_DW.DiscreteTimeIntegrator_DSTATE;
  } else if ((!Clutch_ConstP.CombinatorialLogic3_table[(uint32_T)rowIdx]) &&
             (Clutch_DW.DiscreteTimeIntegrator_PrevRese == 1)) {
    Clutch_DW.DiscreteTimeIntegrator_DSTATE = rtb_trminrads;
    rtb_Ratioofstatictokinetic = Clutch_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    rtb_Ratioofstatictokinetic = 0.005 * rtb_EngineInertia1 +
      Clutch_DW.DiscreteTimeIntegrator_DSTATE;
  }

  // End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

  // Switch: '<S1>/Switch' incorporates:
  //   CombinatorialLogic: '<S2>/Combinatorial  Logic3'
  //
  //  Block description for '<S2>/Combinatorial  Logic3':
  //   TRUTH_TABLE_FROM_FABIEN

  if (Clutch_ConstP.CombinatorialLogic3_table[(uint32_T)rowIdx]) {
    // Outport: '<Root>/FA_TQ_CLU' incorporates:
    //   Delay: '<S1>/Delay'

    Clutch_Y.FA_TQ_CLU = Clutch_DW.Delay_DSTATE;
  } else {
    // Outport: '<Root>/FA_TQ_CLU'
    Clutch_Y.FA_TQ_CLU = rtb_Switch1;
  }

  // End of Switch: '<S1>/Switch'

  // Update for Delay: '<S1>/Delay2' incorporates:
  //   Update for Inport: '<Root>/FA_N_GBX'

  Clutch_DW.Delay2_DSTATE = Clutch_U.FA_N_GBX;

  // Update for Delay: '<S1>/Delay' incorporates:
  //   Update for Inport: '<Root>/FA_TQ_ICE'

  Clutch_DW.Delay_DSTATE = Clutch_U.FA_TQ_ICE;

  // Update for Delay: '<S1>/Delay3'
  Clutch_DW.Delay3_DSTATE = rtb_Ratioofstatictokinetic;

  // Update for Delay: '<S1>/Delay4' incorporates:
  //   Sum: '<S1>/W_Slip'

  Clutch_DW.Delay4_DSTATE = rtb_Ratioofstatictokinetic - rtb_trminrads;

  // Update for Delay: '<S2>/Delay' incorporates:
  //   CombinatorialLogic: '<S2>/Combinatorial  Logic3'
  //
  //  Block description for '<S2>/Combinatorial  Logic3':
  //   TRUTH_TABLE_FROM_FABIEN

  Clutch_DW.Delay_DSTATE_m = Clutch_ConstP.CombinatorialLogic3_table[(uint32_T)
    rowIdx];

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
  //   CombinatorialLogic: '<S2>/Combinatorial  Logic3'
  //
  //  Block description for '<S2>/Combinatorial  Logic3':
  //   TRUTH_TABLE_FROM_FABIEN

  Clutch_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  Clutch_DW.DiscreteTimeIntegrator_DSTATE = 0.005 * rtb_EngineInertia1 +
    rtb_Ratioofstatictokinetic;
  Clutch_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    Clutch_ConstP.CombinatorialLogic3_table[(uint32_T)rowIdx];

  // Switch: '<S1>/Switch1' incorporates:
  //   CombinatorialLogic: '<S2>/Combinatorial  Logic3'
  //
  //  Block description for '<S2>/Combinatorial  Logic3':
  //   TRUTH_TABLE_FROM_FABIEN

  if (Clutch_ConstP.CombinatorialLogic3_table[(uint32_T)rowIdx]) {
    rtb_Ratioofstatictokinetic = rtb_trminrads;
  }

  // End of Switch: '<S1>/Switch1'

  // Outport: '<Root>/FA_N_ICE' incorporates:
  //   Gain: '<S1>/rad//s> tr//min'

  Clutch_Y.FA_N_ICE = 9.5492965855137211 * rtb_Ratioofstatictokinetic;

  // Outport: '<Root>/FA_CLU_STUCK' incorporates:
  //   CombinatorialLogic: '<S2>/Combinatorial  Logic3'
  //
  //  Block description for '<S2>/Combinatorial  Logic3':
  //   TRUTH_TABLE_FROM_FABIEN

  Clutch_Y.FA_CLU_STUCK = Clutch_ConstP.CombinatorialLogic3_table[(uint32_T)
    rowIdx];

  // End of Outputs for SubSystem: '<Root>/Clutch'
}

// Model initialize function
void ClutchModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&Clutch_M), (NULL));

  // states (dwork)
  (void) memset((void *)&Clutch_DW, 0,
                sizeof(DW_Clutch_T));

  // external inputs
  (void) memset((void *)&Clutch_U, 0,
                sizeof(ExtU_Clutch_T));

  // external outputs
  (void) memset((void *)&Clutch_Y, 0,
                sizeof(ExtY_Clutch_T));

  // SystemInitialize for Atomic SubSystem: '<Root>/Clutch'
  // InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' 
  Clutch_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  Clutch_DW.DiscreteTimeIntegrator_PrevRese = 2;

  // End of SystemInitialize for SubSystem: '<Root>/Clutch'
}

// Model terminate function
void ClutchModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
ClutchModelClass::ClutchModelClass()
{
}

// Destructor
ClutchModelClass::~ClutchModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Clutch_T * ClutchModelClass::getRTM()
{
  return (&Clutch_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
