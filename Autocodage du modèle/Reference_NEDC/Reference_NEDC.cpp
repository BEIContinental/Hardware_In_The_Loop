//
// File: Reference_NEDC.cpp
//
// Code generated for Simulink model 'Reference_NEDC'.
//
// Model version                  : 1.3
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 06:55:38 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Reference_NEDC.h"
#include "Reference_NEDC_private.h"

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

uint32_T plook_u32d_bincka(real_T u, const real_T bp[], uint32_T maxIndex)
{
  uint32_T bpIndex;

  // Prelookup - Index only
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T bpIdx;

  // Binary Search
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
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

// Model step function
void Reference_NEDCModelClass::step()
{
  uint32_T bpIdx;
  real_T rtb_NEDCspeed;

  // Outputs for Atomic SubSystem: '<Root>/Reference_NEDC'

  // Clock: '<S1>/Clock'
  Reference_NEDC_B.Clock = (&Reference_NEDC_M)->Timing.t[0];

  // Lookup_n-D: '<S1>/NEDC gear'
  bpIdx = plook_u32d_bincka(Reference_NEDC_B.Clock, *(real_T (*)[52])&
    Reference_NEDC_ConstP.NEDCgear_bp01Data[0], 51U);

  // Lookup_n-D: '<S1>/NEDC speed'
  rtb_NEDCspeed = look1_binlxpw(Reference_NEDC_B.Clock, *(real_T (*)[135])&
    Reference_NEDC_ConstP.NEDCspeed_bp01Data[0], *(real_T (*)[135])&
    Reference_NEDC_ConstP.NEDCspeed_tableData[0], 134U);

  // Outport: '<Root>/DRI_REF_GBX' incorporates:
  //   Lookup_n-D: '<S1>/NEDC gear'
  //   Quantizer: '<S1>/Quantizer'

  Reference_NEDC_Y.DRI_REF_GBX = rt_roundd_snf
    (Reference_NEDC_ConstP.NEDCgear_tableData[bpIdx]);

  // Outport: '<Root>/DRI_REF_SPEED' incorporates:
  //   Gain: '<S1>/m//s -> km//h'

  Reference_NEDC_Y.DRI_REF_SPEED = 3.6 * rtb_NEDCspeed;

  // End of Outputs for SubSystem: '<Root>/Reference_NEDC'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&Reference_NEDC_M)->Timing.t[0] =
    (++(&Reference_NEDC_M)->Timing.clockTick0) * (&Reference_NEDC_M)
    ->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.01s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.01, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&Reference_NEDC_M)->Timing.clockTick1++;
  }
}

// Model initialize function
void Reference_NEDCModelClass::initialize()
{
  // Registration code

  // initialize real-time model
  (void) memset((void *)(&Reference_NEDC_M), 0,
                sizeof(RT_MODEL_Reference_NEDC_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&Reference_NEDC_M)->solverInfo, &(&Reference_NEDC_M
                          )->Timing.simTimeStep);
    rtsiSetTPtr(&(&Reference_NEDC_M)->solverInfo, &rtmGetTPtr((&Reference_NEDC_M)));
    rtsiSetStepSizePtr(&(&Reference_NEDC_M)->solverInfo, &(&Reference_NEDC_M)
                       ->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&Reference_NEDC_M)->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus((&Reference_NEDC_M)))));
    rtsiSetRTModelPtr(&(&Reference_NEDC_M)->solverInfo, (&Reference_NEDC_M));
  }

  rtsiSetSimTimeStep(&(&Reference_NEDC_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&(&Reference_NEDC_M)->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr((&Reference_NEDC_M), &(&Reference_NEDC_M)->Timing.tArray[0]);
  (&Reference_NEDC_M)->Timing.stepSize0 = 0.01;

  // block I/O
  (void) memset(((void *) &Reference_NEDC_B), 0,
                sizeof(B_Reference_NEDC_T));

  // external outputs
  (void) memset((void *)&Reference_NEDC_Y, 0,
                sizeof(ExtY_Reference_NEDC_T));
}

// Model terminate function
void Reference_NEDCModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
Reference_NEDCModelClass::Reference_NEDCModelClass()
{
}

// Destructor
Reference_NEDCModelClass::~Reference_NEDCModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Reference_NEDC_T * Reference_NEDCModelClass::getRTM()
{
  return (&Reference_NEDC_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
