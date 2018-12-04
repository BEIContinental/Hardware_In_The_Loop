//
// File: Platform.cpp
//
// Code generated for Simulink model 'Platform'.
//
// Model version                  : 1.4
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 03:57:00 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Platform.h"
#include "Platform_private.h"

// Model step function
void PlatformModelClass::step()
{
  // local block i/o variables
  real_T rtb_Delay;
  real_T rtb_DiscreteZeroPole;
  real_T rtb_Switch;
  real_T rtb_Product;
  real_T u0;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;

  // Outputs for Atomic SubSystem: '<Root>/Platform'
  // Delay: '<S2>/Delay'
  rtb_Delay = Platform_DW.Delay_DSTATE;

  // DiscreteZeroPole: '<S2>/Discrete Zero-Pole'
  {
    rtb_DiscreteZeroPole = 1.0*rtb_Delay;
    rtb_DiscreteZeroPole += 2.0*Platform_DW.DiscreteZeroPole_DSTATE;
  }

  // Outport: '<Root>/PLA_SPEED' incorporates:
  //   Gain: '<S1>/Gain'

  Platform_Y.PLA_SPEED = 3.6 * rtb_DiscreteZeroPole;

  // Sum: '<S4>/Sum' incorporates:
  //   Inport: '<Root>/Wind'

  rtb_Switch = rtb_DiscreteZeroPole + Platform_U.Wind;

  // Product: '<S4>/Product'
  rtb_Product = rtb_Switch * rtb_Switch;

  // Abs: '<S7>/Abs'
  rtb_Switch = fabs(rtb_DiscreteZeroPole);

  // Switch: '<S7>/Switch2' incorporates:
  //   Constant: '<S7>/Constant'
  //   Constant: '<S7>/Constant2'
  //   Gain: '<S7>/Gain1'
  //   Sum: '<S7>/Sum'

  if (rtb_Switch > 0.01) {
    rtb_Switch = 2.8414768374999997 * rtb_Switch + 43.23751985;
  } else {
    rtb_Switch = 51.885023819999994;
  }

  // End of Switch: '<S7>/Switch2'

  // Sum: '<S1>/Sum1' incorporates:
  //   Inport: '<Root>/FA_PLA_F_BRAKE'
  //   Inport: '<Root>/RA_PLA_F_BRAKE'

  u0 = Platform_U.FA_PLA_F_BRAKE + Platform_U.RA_PLA_F_BRAKE;

  // Signum: '<S4>/Sign'
  if (rtb_DiscreteZeroPole < 0.0) {
    tmp = -1.0;
  } else if (rtb_DiscreteZeroPole > 0.0) {
    tmp = 1.0;
  } else if (rtb_DiscreteZeroPole == 0.0) {
    tmp = 0.0;
  } else {
    tmp = rtb_DiscreteZeroPole;
  }

  // Signum: '<S8>/Sign' incorporates:
  //   Inport: '<Root>/Slope'

  if (Platform_U.Slope < 0.0) {
    tmp_0 = -1.0;
  } else if (Platform_U.Slope > 0.0) {
    tmp_0 = 1.0;
  } else if (Platform_U.Slope == 0.0) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = Platform_U.Slope;
  }

  // Signum: '<S8>/Sign1'
  if (rtb_DiscreteZeroPole < 0.0) {
    tmp_1 = -1.0;
  } else if (rtb_DiscreteZeroPole > 0.0) {
    tmp_1 = 1.0;
  } else if (rtb_DiscreteZeroPole == 0.0) {
    tmp_1 = 0.0;
  } else {
    tmp_1 = rtb_DiscreteZeroPole;
  }

  // Signum: '<S7>/Sign'
  if (rtb_DiscreteZeroPole < 0.0) {
    tmp_2 = -1.0;
  } else if (rtb_DiscreteZeroPole > 0.0) {
    tmp_2 = 1.0;
  } else if (rtb_DiscreteZeroPole == 0.0) {
    tmp_2 = 0.0;
  } else {
    tmp_2 = rtb_DiscreteZeroPole;
  }

  // Signum: '<S5>/Sign'
  if (rtb_DiscreteZeroPole < 0.0) {
    tmp_3 = -1.0;
  } else if (rtb_DiscreteZeroPole > 0.0) {
    tmp_3 = 1.0;
  } else if (rtb_DiscreteZeroPole == 0.0) {
    tmp_3 = 0.0;
  } else {
    tmp_3 = rtb_DiscreteZeroPole;
  }

  // Saturate: '<S5>/Saturation'
  if (u0 > 1000.0) {
    u0 = 1000.0;
  } else {
    if (u0 < 0.0) {
      u0 = 0.0;
    }
  }

  // Sum: '<S2>/Sum' incorporates:
  //   Gain: '<S4>/Gain'
  //   Gain: '<S4>/Gain1'
  //   Gain: '<S5>/Gain2'
  //   Gain: '<S6>/Gain1'
  //   Gain: '<S7>/Gain'
  //   Gain: '<S8>/Gain'
  //   Gain: '<S8>/Gain1'
  //   Gain: '<S8>/Gain2'
  //   Inport: '<Root>/FA_TQ'
  //   Inport: '<Root>/F_ext'
  //   Inport: '<Root>/RA_TQ'
  //   Inport: '<Root>/Slope'
  //   Product: '<S4>/Product1'
  //   Product: '<S5>/Product1'
  //   Product: '<S7>/Product'
  //   Product: '<S8>/Product'
  //   Product: '<S8>/Product1'
  //   Saturate: '<S5>/Saturation'
  //   Signum: '<S4>/Sign'
  //   Signum: '<S5>/Sign'
  //   Signum: '<S7>/Sign'
  //   Signum: '<S8>/Sign'
  //   Signum: '<S8>/Sign1'
  //   Sum: '<S1>/Sum'
  //   Trigonometry: '<S8>/Trigonometric Function'
  //   Trigonometry: '<S8>/Trigonometric Function1'

  rtb_Switch = (((((Platform_U.FA_TQ + Platform_U.RA_TQ) * 3.1847133757961785 +
                   -(0.52992 * rtb_Product * tmp)) + -(sin(atan(0.01 *
    Platform_U.Slope)) * 12258.3125 * (tmp_0 * tmp_1))) + -(rtb_Switch * tmp_2))
                + -(tmp_3 * u0)) + Platform_U.F_ext;

  // Gain: '<S2>/Gain'
  rtb_Product = 0.0008 * rtb_Switch;

  // Abs: '<S3>/Abs1'
  rtb_Switch = fabs(rtb_Switch);

  // Outport: '<Root>/PLA_N' incorporates:
  //   Gain: '<S1>/m//s -> tr//min'

  Platform_Y.PLA_N = 30.41177256533032 * rtb_DiscreteZeroPole;

  // Switch: '<S3>/Switch' incorporates:
  //   Abs: '<S3>/Abs'
  //   Constant: '<S10>/Constant'
  //   Constant: '<S3>/Constant'
  //   Constant: '<S9>/Constant'
  //   Logic: '<S3>/Logical Operator'
  //   RelationalOperator: '<S10>/Compare'
  //   RelationalOperator: '<S9>/Compare'

  if ((fabs(rtb_DiscreteZeroPole) <= 0.01) && (rtb_Switch <= 51.885023819999994))
  {
    rtb_Product = 0.0;
  }

  // End of Switch: '<S3>/Switch'

  // Update for Delay: '<S2>/Delay' incorporates:
  //   Gain: '<S2>/Gain7'

  Platform_DW.Delay_DSTATE = 0.005 * rtb_Product;

  // Update for DiscreteZeroPole: '<S2>/Discrete Zero-Pole'
  {
    Platform_DW.DiscreteZeroPole_DSTATE = rtb_Delay + 1.0*
      Platform_DW.DiscreteZeroPole_DSTATE;
  }

  // End of Outputs for SubSystem: '<Root>/Platform'
}

// Model initialize function
void PlatformModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&Platform_M), (NULL));

  // states (dwork)
  (void) memset((void *)&Platform_DW, 0,
                sizeof(DW_Platform_T));

  // external inputs
  (void) memset((void *)&Platform_U, 0,
                sizeof(ExtU_Platform_T));

  // external outputs
  (void) memset((void *)&Platform_Y, 0,
                sizeof(ExtY_Platform_T));
}

// Model terminate function
void PlatformModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
PlatformModelClass::PlatformModelClass()
{
}

// Destructor
PlatformModelClass::~PlatformModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Platform_T * PlatformModelClass::getRTM()
{
  return (&Platform_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
