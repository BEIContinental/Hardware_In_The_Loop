//
// File: ICE_control.cpp
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
#include "ICE_control.h"
#include "ICE_control_private.h"

// Named constants for Chart: '<S1>/ICE state machine'
#define ICE__IN_Standard_force_tracking ((uint8_T)2U)
#define ICE_control_IN_Force_tracking  ((uint8_T)1U)
#define ICE_control_IN_Idle            ((uint8_T)2U)
#define ICE_control_IN_IdleTransOn     ((uint8_T)3U)
#define ICE_control_IN_InjectionInhibed ((uint8_T)1U)
#define ICE_control_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ICE_control_IN_Running         ((uint8_T)1U)
#define ICE_control_IN_Stall           ((uint8_T)2U)
#define ICE_control_IN_Start           ((uint8_T)3U)
#define ICE_control_IN_Starter         ((uint8_T)1U)
#define ICE_control_IN_StarterAndTQI   ((uint8_T)2U)

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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
      y = 0.0;
    } else {
      y = (tmp - floor(tmp)) * u1;
    }
  }

  return y;
}

// Model step function
void ICE_controlModelClass::step()
{
  real_T rtb_MAXTQICE;
  real_T rtb_TQLOSS;
  boolean_T rtb_RelationalOperator_dr;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_RelationalOperator2_l;
  real_T rtb_Add_o;
  real_T rtb_Product1;
  real_T rtb_Switch3;
  real_T rtb_Switch2;
  real_T rtb_Uk1;
  real_T rtb_Switch;
  real_T rtb_MathFunction;
  real_T rtb_Add3;
  real_T DiscreteTimeIntegrator;
  real_T DiscreteTimeIntegrator_j;
  real_T rtb_Add_m;

  // Outputs for Atomic SubSystem: '<Root>/ICE_control'
  // Lookup_n-D: '<S1>/TQ LOSS' incorporates:
  //   Inport: '<Root>/FA_N_ICE'

  rtb_TQLOSS = look1_binlxpw(ICE_control_U.FA_N_ICE, *(real_T (*)[18])&
    ICE_control_ConstP.TQLOSS_bp01Data[0], *(real_T (*)[18])&
    ICE_control_ConstP.TQLOSS_tableData[0], 17U);

  // Logic: '<S9>/Logical Operator1' incorporates:
  //   Delay: '<S9>/Delay'
  //   Delay: '<S9>/Delay1'
  //   Inport: '<Root>/FA_ICE_RESET_SYNCHRO'
  //   Logic: '<S9>/Logical Operator'
  //   Logic: '<S9>/Logical Operator2'

  rtb_LogicalOperator1 = ((ICE_control_DW.Delay1_DSTATE ||
    (ICE_control_DW.Delay_DSTATE != 0)) && (!ICE_control_U.FA_ICE_RESET_SYNCHRO));

  // Chart: '<S1>/ICE state machine' incorporates:
  //   Inport: '<Root>/CMD_FA_TQ_SP'
  //   Inport: '<Root>/DRI_GBX_SP'
  //   Inport: '<Root>/FA_CLU_STUCK'
  //   Inport: '<Root>/FA_N_ICE'
  //   Inport: '<Root>/FA_START_ICE'

  // Gateway: ICE_control/ICE state machine
  // During: ICE_control/ICE state machine
  if (ICE_control_DW.is_active_c2_ICE_control == 0U) {
    // Entry: ICE_control/ICE state machine
    ICE_control_DW.is_active_c2_ICE_control = 1U;

    // Entry Internal: ICE_control/ICE state machine
    // Transition: '<S3>:4'
    ICE_control_DW.is_c2_ICE_control = ICE_control_IN_Stall;

    // Outport: '<Root>/FA_ICE_STATE'
    // Entry 'Stall': '<S3>:1'
    ICE_control_Y.FA_ICE_STATE = 1.0;
  } else {
    switch (ICE_control_DW.is_c2_ICE_control) {
     case ICE_control_IN_Running:
      // During 'Running': '<S3>:86'
      if ((ICE_control_U.FA_START_ICE != 1.0) || (ICE_control_U.FA_N_ICE < 400.0))
      {
        // Transition: '<S3>:44'
        // Exit Internal 'Running': '<S3>:86'
        // Exit Internal 'Force_tracking': '<S3>:3'
        ICE_control_DW.is_Force_tracking = ICE_control_IN_NO_ACTIVE_CHILD;
        ICE_control_DW.is_Running = ICE_control_IN_NO_ACTIVE_CHILD;
        ICE_control_DW.is_c2_ICE_control = ICE_control_IN_Stall;

        // Outport: '<Root>/FA_ICE_STATE'
        // Entry 'Stall': '<S3>:1'
        ICE_control_Y.FA_ICE_STATE = 1.0;
      } else {
        switch (ICE_control_DW.is_Running) {
         case ICE_control_IN_Force_tracking:
          // During 'Force_tracking': '<S3>:3'
          if ((ICE_control_U.FA_CLU_STUCK == 0.0) || (ICE_control_U.DRI_GBX_SP ==
               0.0)) {
            // Transition: '<S3>:65'
            // Exit Internal 'Force_tracking': '<S3>:3'
            ICE_control_DW.is_Force_tracking = ICE_control_IN_NO_ACTIVE_CHILD;
            ICE_control_DW.is_Running = ICE_control_IN_Idle;

            // Outport: '<Root>/FA_ICE_STATE'
            // Entry 'Idle': '<S3>:2'
            ICE_control_Y.FA_ICE_STATE = 3.0;
          } else if (ICE_control_DW.is_Force_tracking ==
                     ICE_control_IN_InjectionInhibed) {
            // During 'InjectionInhibed': '<S3>:88'
            if (ICE_control_U.CMD_FA_TQ_SP > rtb_TQLOSS) {
              // Transition: '<S3>:92'
              ICE_control_DW.is_Force_tracking = ICE__IN_Standard_force_tracking;

              // Outport: '<Root>/FA_ICE_STATE'
              // Entry 'Standard_force_tracking': '<S3>:87'
              ICE_control_Y.FA_ICE_STATE = 5.1;
            } else {
              if ((ICE_control_U.FA_N_ICE < 1200.0) &&
                  (ICE_control_U.FA_CLU_STUCK == 1.0) &&
                  (ICE_control_U.DRI_GBX_SP != 0.0)) {
                // Transition: '<S3>:51'
                ICE_control_DW.is_Force_tracking =
                  ICE_control_IN_NO_ACTIVE_CHILD;
                ICE_control_DW.is_Running = ICE_control_IN_IdleTransOn;

                // Outport: '<Root>/FA_ICE_STATE'
                // Entry 'IdleTransOn': '<S3>:45'
                ICE_control_Y.FA_ICE_STATE = 4.0;
              }
            }
          } else {
            // During 'Standard_force_tracking': '<S3>:87'
            if (ICE_control_U.CMD_FA_TQ_SP == rtb_TQLOSS) {
              // Transition: '<S3>:94'
              ICE_control_DW.is_Force_tracking = ICE_control_IN_InjectionInhibed;

              // Outport: '<Root>/FA_ICE_STATE'
              // Entry 'InjectionInhibed': '<S3>:88'
              ICE_control_Y.FA_ICE_STATE = 5.2;
            }
          }
          break;

         case ICE_control_IN_Idle:
          // During 'Idle': '<S3>:2'
          if ((ICE_control_U.FA_CLU_STUCK != 0.0) && (ICE_control_U.DRI_GBX_SP
               != 0.0)) {
            // Transition: '<S3>:48'
            ICE_control_DW.is_Running = ICE_control_IN_IdleTransOn;

            // Outport: '<Root>/FA_ICE_STATE'
            // Entry 'IdleTransOn': '<S3>:45'
            ICE_control_Y.FA_ICE_STATE = 4.0;
          }
          break;

         default:
          // During 'IdleTransOn': '<S3>:45'
          if ((ICE_control_U.FA_CLU_STUCK == 0.0) || (ICE_control_U.DRI_GBX_SP ==
               0.0)) {
            // Transition: '<S3>:49'
            ICE_control_DW.is_Running = ICE_control_IN_Idle;

            // Outport: '<Root>/FA_ICE_STATE'
            // Entry 'Idle': '<S3>:2'
            ICE_control_Y.FA_ICE_STATE = 3.0;
          } else {
            if ((ICE_control_U.FA_CLU_STUCK == 1.0) && (ICE_control_U.DRI_GBX_SP
                 != 0.0) && (ICE_control_U.CMD_FA_TQ_SP > 0.0)) {
              // Transition: '<S3>:50'
              ICE_control_DW.is_Running = ICE_control_IN_Force_tracking;

              // Entry Internal 'Force_tracking': '<S3>:3'
              // Transition: '<S3>:96'
              ICE_control_DW.is_Force_tracking = ICE__IN_Standard_force_tracking;

              // Outport: '<Root>/FA_ICE_STATE'
              // Entry 'Standard_force_tracking': '<S3>:87'
              ICE_control_Y.FA_ICE_STATE = 5.1;
            }
          }
          break;
        }
      }
      break;

     case ICE_control_IN_Stall:
      // During 'Stall': '<S3>:1'
      if ((ICE_control_U.FA_START_ICE == 1.0) && (ICE_control_U.FA_N_ICE < 30.0))
      {
        // Transition: '<S3>:24'
        ICE_control_DW.is_c2_ICE_control = ICE_control_IN_Start;

        // Entry Internal 'Start': '<S3>:20'
        // Transition: '<S3>:82'
        ICE_control_DW.is_Start = ICE_control_IN_Starter;

        // Outport: '<Root>/FA_ICE_STATE'
        // Entry 'Starter': '<S3>:70'
        ICE_control_Y.FA_ICE_STATE = 2.1;
      } else {
        if ((ICE_control_U.FA_START_ICE == 1.0) && (ICE_control_U.FA_N_ICE >
             600.0) && (ICE_control_U.DRI_GBX_SP != 0.0) &&
            (ICE_control_U.FA_CLU_STUCK == 1.0)) {
          // Transition: '<S3>:132'
          ICE_control_DW.is_c2_ICE_control = ICE_control_IN_Running;
          ICE_control_DW.is_Running = ICE_control_IN_Force_tracking;

          // Entry Internal 'Force_tracking': '<S3>:3'
          // Transition: '<S3>:96'
          ICE_control_DW.is_Force_tracking = ICE__IN_Standard_force_tracking;

          // Outport: '<Root>/FA_ICE_STATE'
          // Entry 'Standard_force_tracking': '<S3>:87'
          ICE_control_Y.FA_ICE_STATE = 5.1;
        }
      }
      break;

     default:
      // During 'Start': '<S3>:20'
      if (ICE_control_U.FA_N_ICE > 600.0) {
        // Transition: '<S3>:42'
        // Exit Internal 'Start': '<S3>:20'
        ICE_control_DW.is_Start = ICE_control_IN_NO_ACTIVE_CHILD;
        ICE_control_DW.is_c2_ICE_control = ICE_control_IN_Running;

        // Entry Internal 'Running': '<S3>:86'
        // Transition: '<S3>:112'
        if ((ICE_control_U.FA_CLU_STUCK != 0.0) && (ICE_control_U.DRI_GBX_SP !=
             0.0)) {
          // Transition: '<S3>:47'
          ICE_control_DW.is_Running = ICE_control_IN_IdleTransOn;

          // Outport: '<Root>/FA_ICE_STATE'
          // Entry 'IdleTransOn': '<S3>:45'
          ICE_control_Y.FA_ICE_STATE = 4.0;
        } else {
          // Transition: '<S3>:46'
          ICE_control_DW.is_Running = ICE_control_IN_Idle;

          // Outport: '<Root>/FA_ICE_STATE'
          // Entry 'Idle': '<S3>:2'
          ICE_control_Y.FA_ICE_STATE = 3.0;
        }
      } else if (ICE_control_U.FA_START_ICE != 1.0) {
        // Transition: '<S3>:102'
        // Exit Internal 'Start': '<S3>:20'
        ICE_control_DW.is_Start = ICE_control_IN_NO_ACTIVE_CHILD;
        ICE_control_DW.is_c2_ICE_control = ICE_control_IN_Stall;

        // Outport: '<Root>/FA_ICE_STATE'
        // Entry 'Stall': '<S3>:1'
        ICE_control_Y.FA_ICE_STATE = 1.0;
      } else if (ICE_control_DW.is_Start == ICE_control_IN_Starter) {
        // During 'Starter': '<S3>:70'
        if ((ICE_control_U.FA_N_ICE > 250.0) && rtb_LogicalOperator1) {
          // Transition: '<S3>:73'
          ICE_control_DW.is_Start = ICE_control_IN_StarterAndTQI;

          // Outport: '<Root>/FA_ICE_STATE'
          // Entry 'StarterAndTQI': '<S3>:72'
          ICE_control_Y.FA_ICE_STATE = 2.2;
        }
      } else {
        // During 'StarterAndTQI': '<S3>:72'
        if (ICE_control_U.FA_N_ICE < 250.0) {
          // Transition: '<S3>:101'
          ICE_control_DW.is_Start = ICE_control_IN_NO_ACTIVE_CHILD;
          ICE_control_DW.is_c2_ICE_control = ICE_control_IN_Stall;

          // Outport: '<Root>/FA_ICE_STATE'
          // Entry 'Stall': '<S3>:1'
          ICE_control_Y.FA_ICE_STATE = 1.0;
        }
      }
      break;
    }
  }

  // End of Chart: '<S1>/ICE state machine'

  // RateLimiter: '<S5>/Rate Limiter' incorporates:
  //   Inport: '<Root>/CMD_FA_TQ_SP'

  rtb_Add_o = ICE_control_U.CMD_FA_TQ_SP - ICE_control_DW.PrevY;
  if (rtb_Add_o > 0.2) {
    rtb_Add3 = ICE_control_DW.PrevY + 0.2;
  } else if (rtb_Add_o < -1.0) {
    rtb_Add3 = ICE_control_DW.PrevY + -1.0;
  } else {
    rtb_Add3 = ICE_control_U.CMD_FA_TQ_SP;
  }

  ICE_control_DW.PrevY = rtb_Add3;

  // End of RateLimiter: '<S5>/Rate Limiter'

  // Switch: '<S5>/Switch' incorporates:
  //   Constant: '<S5>/PUC'
  //   Constant: '<S5>/zero'
  //   RelationalOperator: '<S5>/Relational Operator1'

  if (!(ICE_control_Y.FA_ICE_STATE == 5.2)) {
    rtb_Add3 = 0.0;
  }

  // End of Switch: '<S5>/Switch'

  // RelationalOperator: '<S4>/Relational Operator' incorporates:
  //   Constant: '<S4>/StarterAndTQI'

  rtb_RelationalOperator_dr = (ICE_control_Y.FA_ICE_STATE == 2.2);

  // RelationalOperator: '<S4>/Relational Operator2' incorporates:
  //   Constant: '<S4>/IdleTransOn'

  rtb_RelationalOperator2_l = (ICE_control_Y.FA_ICE_STATE == 4.0);

  // Switch: '<S4>/Switch4' incorporates:
  //   Constant: '<S4>/zero4'
  //   LookupNDDirect: '<S4>/fa_kp_idle_tr_on'
  //
  //  About '<S4>/fa_kp_idle_tr_on':
  //   1-dimensional Direct Look-Up returning a Scalar

  if (rtb_RelationalOperator2_l) {
    // LookupNDDirect: '<S4>/fa_kp_idle_tr_on' incorporates:
    //   Inport: '<Root>/DRI_GBX_SP'
    //
    //  About '<S4>/fa_kp_idle_tr_on':
    //   1-dimensional Direct Look-Up returning a Scalar

    if (ICE_control_U.DRI_GBX_SP > 6.0) {
      rtb_MAXTQICE = 6.0;
    } else if (ICE_control_U.DRI_GBX_SP < 0.0) {
      rtb_MAXTQICE = 0.0;
    } else {
      rtb_MAXTQICE = ICE_control_U.DRI_GBX_SP;
    }

    rtb_Switch = ICE_control_ConstP.fa_kp_idle_tr_on_table[(int32_T)rtb_MAXTQICE];
  } else {
    rtb_Switch = 0.11619828285090543;
  }

  // End of Switch: '<S4>/Switch4'

  // Product: '<S4>/Product' incorporates:
  //   Constant: '<S4>/Idle speed set point'
  //   Inport: '<Root>/FA_N_ICE'
  //   Sum: '<S4>/Add2'

  rtb_Add_o = (750.0 - ICE_control_U.FA_N_ICE) * rtb_Switch;

  // Switch: '<S4>/Switch2' incorporates:
  //   Gain: '<S4>/1//fa_taui_idle1'
  //   Gain: '<S4>/1//fa_taui_idle2'

  if (rtb_RelationalOperator2_l) {
    rtb_Switch = 5.1523385962105115;
  } else {
    rtb_Switch = 12.18794345961944;
  }

  // End of Switch: '<S4>/Switch2'

  // Product: '<S4>/Product1'
  rtb_Product1 = rtb_Switch * rtb_Add_o;

  // Switch: '<S4>/Switch3' incorporates:
  //   Constant: '<S4>/Constant'
  //   Delay: '<S12>/Delay'

  if (ICE_control_DW.Delay_DSTATE_g) {
    rtb_Switch3 = 0.0;
  } else {
    rtb_Switch3 = rtb_Product1;
  }

  // End of Switch: '<S4>/Switch3'

  // Logic: '<S4>/Logical Oprator' incorporates:
  //   Constant: '<S4>/Idle'
  //   RelationalOperator: '<S4>/Relational Operator1'

  rtb_RelationalOperator2_l = (rtb_RelationalOperator_dr ||
    (ICE_control_Y.FA_ICE_STATE == 3.0) || rtb_RelationalOperator2_l);

  // DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  if (ICE_control_DW.DiscreteTimeIntegrator_SYSTEM_E != 0) {
    DiscreteTimeIntegrator = ICE_control_DW.DiscreteTimeIntegrator_DSTATE;
  } else if (rtb_RelationalOperator2_l &&
             (ICE_control_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    ICE_control_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
    DiscreteTimeIntegrator = ICE_control_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    DiscreteTimeIntegrator = 0.005 * rtb_Switch3 +
      ICE_control_DW.DiscreteTimeIntegrator_DSTATE;
  }

  // End of DiscreteIntegrator: '<S4>/Discrete-Time Integrator'

  // Sum: '<S4>/Add'
  rtb_Add_o += DiscreteTimeIntegrator;

  // Switch: '<S11>/Switch2' incorporates:
  //   Constant: '<S4>/Max'
  //   Constant: '<S4>/Min'
  //   RelationalOperator: '<S11>/LowerRelop1'
  //   RelationalOperator: '<S11>/UpperRelop'
  //   Switch: '<S11>/Switch'

  if (rtb_Add_o > 100.0) {
    rtb_Uk1 = 100.0;
  } else if (rtb_Add_o < -5.0) {
    // Switch: '<S11>/Switch' incorporates:
    //   Constant: '<S4>/Min'

    rtb_Uk1 = -5.0;
  } else {
    rtb_Uk1 = rtb_Add_o;
  }

  // End of Switch: '<S11>/Switch2'

  // Switch: '<S4>/Switch' incorporates:
  //   Constant: '<S4>/zero'
  //   Sum: '<S4>/Starter compensation'

  if (rtb_RelationalOperator2_l) {
    // Switch: '<S4>/Switch1' incorporates:
    //   Constant: '<S4>/zero1'
    //   Inport: '<Root>/FA_TQ_STARTER'

    if (rtb_RelationalOperator_dr) {
      rtb_Switch = ICE_control_U.FA_TQ_STARTER;
    } else {
      rtb_Switch = 0.0;
    }

    // End of Switch: '<S4>/Switch1'
    rtb_Switch = rtb_Uk1 - rtb_Switch;
  } else {
    rtb_Switch = 0.0;
  }

  // End of Switch: '<S4>/Switch'

  // Switch: '<S10>/Switch' incorporates:
  //   Constant: '<S10>/Force traking'
  //   Constant: '<S10>/Force traking1'
  //   Constant: '<S10>/IdleTransOn'
  //   Constant: '<S10>/zero'
  //   Inport: '<Root>/CMD_FA_TQ_SP'
  //   Logic: '<S10>/Logical Operator'
  //   RelationalOperator: '<S10>/Relational Operator'
  //   RelationalOperator: '<S10>/Relational Operator1'
  //   RelationalOperator: '<S10>/Relational Operator2'

  if ((ICE_control_Y.FA_ICE_STATE == 4.0) || (ICE_control_Y.FA_ICE_STATE == 5.1)
      || (ICE_control_Y.FA_ICE_STATE == 3.0)) {
    rtb_MAXTQICE = ICE_control_U.CMD_FA_TQ_SP;
  } else {
    rtb_MAXTQICE = 0.0;
  }

  // End of Switch: '<S10>/Switch'

  // Switch: '<S6>/Switch' incorporates:
  //   Constant: '<S6>/Stall'
  //   Constant: '<S6>/Starter'
  //   Constant: '<S6>/zero'
  //   Logic: '<S6>/Logical Operator'
  //   RelationalOperator: '<S6>/Relational Operator'
  //   RelationalOperator: '<S6>/Relational Operator1'

  if ((ICE_control_Y.FA_ICE_STATE != 2.1) && (ICE_control_Y.FA_ICE_STATE != 1.0))
  {
    rtb_Switch2 = rtb_TQLOSS;
  } else {
    rtb_Switch2 = 0.0;
  }

  // End of Switch: '<S6>/Switch'

  // Sum: '<S1>/Add' incorporates:
  //   UnaryMinus: '<S6>/Loss compentation'

  rtb_Switch += (rtb_MAXTQICE + rtb_Add3) + -rtb_Switch2;

  // Lookup_n-D: '<S1>/MAX TQ ICE' incorporates:
  //   Inport: '<Root>/FA_N_ICE'

  rtb_MAXTQICE = look1_binlcapw(ICE_control_U.FA_N_ICE, *(real_T (*)[52])&
    ICE_control_ConstP.MAXTQICE_bp01Data[0], *(real_T (*)[52])&
    ICE_control_ConstP.MAXTQICE_tableData[0], 51U);

  // Sum: '<S1>/Add1'
  rtb_Switch2 = rtb_MAXTQICE - rtb_TQLOSS;

  // Relay: '<S2>/Relay' incorporates:
  //   Inport: '<Root>/FA_N_ICE'

  if (ICE_control_U.FA_N_ICE >= 5750.0) {
    ICE_control_DW.Relay_Mode = true;
  } else {
    if (ICE_control_U.FA_N_ICE <= 4400.0) {
      ICE_control_DW.Relay_Mode = false;
    }
  }

  // MultiPortSwitch: '<S2>/Multiport Switch1' incorporates:
  //   Relay: '<S2>/Relay'

  if (!ICE_control_DW.Relay_Mode) {
    // MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
    //   Constant: '<S2>/Constant4'
    //   Constant: '<S2>/Constant5'
    //   Constant: '<S2>/HYSTERESIS'
    //   Inport: '<Root>/FA_N_ICE'
    //   RelationalOperator: '<S2>/Relational Operator'
    //   Sum: '<S2>/Add'

    if (!(4000.0 - ICE_control_U.FA_N_ICE <= 0.0)) {
      rtb_Add3 = 1.0;
    } else {
      // Product: '<S2>/Divide' incorporates:
      //   Sum: '<S2>/Add8'

      rtb_Add3 = ((4000.0 - ICE_control_U.FA_N_ICE) + ICE_control_ConstB.Add2) /
        ICE_control_ConstB.Add2;

      // MinMax: '<S2>/MinMax1'
      if (!(rtb_Add3 >= 0.0)) {
        rtb_Add3 = 0.0;
      }

      // End of MinMax: '<S2>/MinMax1'

      // MinMax: '<S2>/MinMax'
      if ((1.0 <= rtb_Add3) || rtIsNaN(rtb_Add3)) {
        rtb_Add3 = 1.0;
      }

      // End of MinMax: '<S2>/MinMax'
    }

    // End of MultiPortSwitch: '<S2>/Multiport Switch'
  } else {
    // Sum: '<S2>/Add3' incorporates:
    //   Inport: '<Root>/FA_N_ICE'

    rtb_Add3 = ICE_control_ConstB.Add6 - ICE_control_U.FA_N_ICE;

    // MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
    //   Constant: '<S2>/Constant2'
    //   Constant: '<S2>/Constant6'
    //   RelationalOperator: '<S2>/Relational Operator1'

    if (!(rtb_Add3 <= 0.0)) {
      rtb_Add3 = 1.0;
    } else {
      // Product: '<S2>/Divide1' incorporates:
      //   Sum: '<S2>/Add4'

      rtb_Add3 = (rtb_Add3 + ICE_control_ConstB.Add5) / ICE_control_ConstB.Add5;

      // MinMax: '<S2>/MinMax3'
      if (!(rtb_Add3 >= 0.0)) {
        rtb_Add3 = 0.0;
      }

      // End of MinMax: '<S2>/MinMax3'

      // MinMax: '<S2>/MinMax2'
      if ((1.0 <= rtb_Add3) || rtIsNaN(rtb_Add3)) {
        rtb_Add3 = 1.0;
      }

      // End of MinMax: '<S2>/MinMax2'
    }

    // End of MultiPortSwitch: '<S2>/Multiport Switch2'
  }

  // End of MultiPortSwitch: '<S2>/Multiport Switch1'

  // RelationalOperator: '<S7>/LowerRelop1'
  rtb_RelationalOperator_dr = (rtb_Switch > rtb_Switch2);

  // Switch: '<S7>/Switch' incorporates:
  //   Constant: '<S1>/Constant'
  //   RelationalOperator: '<S7>/UpperRelop'

  if (rtb_Switch < 0.0) {
    rtb_Switch = 0.0;
  }

  // End of Switch: '<S7>/Switch'

  // Switch: '<S7>/Switch2'
  if (!rtb_RelationalOperator_dr) {
    rtb_Switch2 = rtb_Switch;
  }

  // End of Switch: '<S7>/Switch2'

  // Logic: '<S8>/Logical Operator' incorporates:
  //   Constant: '<S8>/Starter'
  //   Constant: '<S8>/StarterAndTQI'
  //   RelationalOperator: '<S8>/Relational Operator'
  //   RelationalOperator: '<S8>/Relational Operator1'

  rtb_RelationalOperator_dr = ((ICE_control_Y.FA_ICE_STATE == 2.2) ||
    (ICE_control_Y.FA_ICE_STATE == 2.1));

  // Gain: '<S9>/tr//min > deg//s' incorporates:
  //   Inport: '<Root>/FA_N_ICE'

  rtb_Switch = 6.0 * ICE_control_U.FA_N_ICE;

  // DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  if (ICE_control_DW.DiscreteTimeIntegrator_SYSTEM_d != 0) {
    DiscreteTimeIntegrator_j = ICE_control_DW.DiscreteTimeIntegrator_DSTATE_c;
  } else if (rtb_RelationalOperator_dr &&
             (ICE_control_DW.DiscreteTimeIntegrator_PrevRe_g <= 0)) {
    ICE_control_DW.DiscreteTimeIntegrator_DSTATE_c = 0.0;
    DiscreteTimeIntegrator_j = ICE_control_DW.DiscreteTimeIntegrator_DSTATE_c;
  } else {
    DiscreteTimeIntegrator_j = 0.005 * rtb_Switch +
      ICE_control_DW.DiscreteTimeIntegrator_DSTATE_c;
  }

  // End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator'

  // Math: '<S9>/Math Function' incorporates:
  //   Constant: '<S9>/top after 1.5 turn'

  rtb_MathFunction = rt_modd_snf(DiscreteTimeIntegrator_j, 540.0);

  // Update for Delay: '<S9>/Delay1'
  ICE_control_DW.Delay1_DSTATE = rtb_LogicalOperator1;

  // Update for Delay: '<S9>/Delay' incorporates:
  //   RelationalOperator: '<S13>/FixPt Relational Operator'
  //   UnitDelay: '<S13>/Delay Input1'
  //
  //  Block description for '<S13>/Delay Input1':
  //
  //   Store in Global RAM

  ICE_control_DW.Delay_DSTATE = (rtb_MathFunction <
    ICE_control_DW.DelayInput1_DSTATE);

  // Signum: '<S12>/SignPreSat'
  if (rtb_Add_o < 0.0) {
    rtb_Add_m = -1.0;
  } else if (rtb_Add_o > 0.0) {
    rtb_Add_m = 1.0;
  } else if (rtb_Add_o == 0.0) {
    rtb_Add_m = 0.0;
  } else {
    rtb_Add_m = rtb_Add_o;
  }

  // Signum: '<S12>/SignPreIntegrator'
  if (rtb_Product1 < 0.0) {
    rtb_Product1 = -1.0;
  } else if (rtb_Product1 > 0.0) {
    rtb_Product1 = 1.0;
  } else {
    if (rtb_Product1 == 0.0) {
      rtb_Product1 = 0.0;
    }
  }

  // Update for Delay: '<S12>/Delay' incorporates:
  //   Logic: '<S12>/AND'
  //   RelationalOperator: '<S12>/Equal'
  //   RelationalOperator: '<S12>/NotEqual'
  //   Signum: '<S12>/SignPreIntegrator'
  //   Signum: '<S12>/SignPreSat'

  ICE_control_DW.Delay_DSTATE_g = ((rtb_Add_o != rtb_Uk1) && (rtb_Add_m ==
    rtb_Product1));

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  ICE_control_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
  ICE_control_DW.DiscreteTimeIntegrator_DSTATE = 0.005 * rtb_Switch3 +
    DiscreteTimeIntegrator;
  ICE_control_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    rtb_RelationalOperator2_l;

  // Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  ICE_control_DW.DiscreteTimeIntegrator_SYSTEM_d = 0U;
  ICE_control_DW.DiscreteTimeIntegrator_DSTATE_c = 0.005 * rtb_Switch +
    DiscreteTimeIntegrator_j;
  ICE_control_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    rtb_RelationalOperator_dr;

  // Update for UnitDelay: '<S13>/Delay Input1'
  //
  //  Block description for '<S13>/Delay Input1':
  //
  //   Store in Global RAM

  ICE_control_DW.DelayInput1_DSTATE = rtb_MathFunction;

  // End of Outputs for SubSystem: '<Root>/ICE_control'

  // Outport: '<Root>/FA_TQ_MAX_ICE'
  ICE_control_Y.FA_TQ_MAX_ICE = rtb_MAXTQICE;

  // Outputs for Atomic SubSystem: '<Root>/ICE_control'
  // Outport: '<Root>/FA_ICE_TQ_SP' incorporates:
  //   Product: '<S1>/Product'

  ICE_control_Y.FA_ICE_TQ_SP = rtb_Add3 * rtb_Switch2;

  // End of Outputs for SubSystem: '<Root>/ICE_control'

  // Outport: '<Root>/FA_STARTER_REQUEST'
  ICE_control_Y.FA_STARTER_REQUEST = rtb_RelationalOperator_dr;

  // Outport: '<Root>/FA_TQ_MIN_ICE'
  ICE_control_Y.FA_TQ_MIN_ICE = rtb_TQLOSS;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.01, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  (&ICE_control_M)->Timing.clockTick0++;
}

// Model initialize function
void ICE_controlModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize real-time model
  (void) memset((void *)(&ICE_control_M), 0,
                sizeof(RT_MODEL_ICE_control_T));

  // states (dwork)
  (void) memset((void *)&ICE_control_DW, 0,
                sizeof(DW_ICE_control_T));

  // external inputs
  (void) memset((void *)&ICE_control_U, 0,
                sizeof(ExtU_ICE_control_T));

  // external outputs
  (void) memset((void *)&ICE_control_Y, 0,
                sizeof(ExtY_ICE_control_T));

  // SystemInitialize for Atomic SubSystem: '<Root>/ICE_control'
  // InitializeConditions for RateLimiter: '<S5>/Rate Limiter'
  ICE_control_DW.PrevY = 0.0;

  // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' 
  ICE_control_DW.DiscreteTimeIntegrator_PrevRese = 2;

  // InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' 
  ICE_control_DW.DiscreteTimeIntegrator_PrevRe_g = 2;

  // SystemInitialize for Chart: '<S1>/ICE state machine'
  ICE_control_DW.is_Running = ICE_control_IN_NO_ACTIVE_CHILD;
  ICE_control_DW.is_Force_tracking = ICE_control_IN_NO_ACTIVE_CHILD;
  ICE_control_DW.is_Start = ICE_control_IN_NO_ACTIVE_CHILD;
  ICE_control_DW.is_active_c2_ICE_control = 0U;
  ICE_control_DW.is_c2_ICE_control = ICE_control_IN_NO_ACTIVE_CHILD;

  // SystemInitialize for Outport: '<Root>/FA_ICE_STATE' incorporates:
  //   SystemInitialize for Chart: '<S1>/ICE state machine'

  ICE_control_Y.FA_ICE_STATE = 0.0;

  // End of SystemInitialize for SubSystem: '<Root>/ICE_control'

  // Enable for Atomic SubSystem: '<Root>/ICE_control'
  // Enable for DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  ICE_control_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  // Enable for DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  ICE_control_DW.DiscreteTimeIntegrator_SYSTEM_d = 1U;

  // End of Enable for SubSystem: '<Root>/ICE_control'
}

// Model terminate function
void ICE_controlModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
ICE_controlModelClass::ICE_controlModelClass()
{
}

// Destructor
ICE_controlModelClass::~ICE_controlModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_ICE_control_T * ICE_controlModelClass::getRTM()
{
  return (&ICE_control_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
