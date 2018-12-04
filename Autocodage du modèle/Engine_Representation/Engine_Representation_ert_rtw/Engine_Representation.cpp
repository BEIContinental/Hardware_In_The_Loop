//
// File: Engine_Representation.cpp
//
// Code generated for Simulink model 'Engine_Representation'.
//
// Model version                  : 1.1798
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Tue Jan 23 15:26:15 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Engine_Representation.h"
#include "Engine_Representation_private.h"

// Lookup Binary Search Utility BINARYSEARCH_real_T
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  // Find the location of current input value in the data table.
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    // Less than or equal to the smallest point in the table.
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    // Greater than or equal to the largest point in the table.
    *piLeft = iHi;
  } else {
    uint32_T i;

    // Do a binary search.
    while (( *piRght - *piLeft ) > 1U ) {
      // Get the average of the left and right indices using to Floor rounding.
      i = (*piLeft + *piRght) >> 1;

      // Move either the right index or the left index so that
      //  LeftDataPoint <= CurrentValue < RightDataPoint
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

// Lookup Utility LookUp_real_T_real_T
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

// Model step function
void Engine_RepresentationModelClass::step()
{
  real_T DiscreteTransferFcn3_tmp;

  // Outputs for Atomic SubSystem: '<Root>/Engine_Representation'

  // Lookup: '<S1>/Maximum torque'
  //  About '<S1>/Maximum torque':
  //  Input0  Data Type:  Floating Point real_T
  //  Output0 Data Type:  Floating Point real_T
  //  Lookup Method: Linear_Endpoint
  //
  //  XData parameter uses the same data type and scaling as Input0
  //  YData parameter uses the same data type and scaling as Output0

  LookUp_real_T_real_T( &(Engine_Representation_Y.RA_TQ_MAX_ME),
                       Engine_Representation_P.ra_em_max_tq,
                       Engine_Representation_U.RA_N_EM,
                       Engine_Representation_P.ra_electrical_machine_speed, 20U);

  // Lookup: '<S1>/Minimum torque'
  //  About '<S1>/Minimum torque':
  //  Input0  Data Type:  Floating Point real_T
  //  Output0 Data Type:  Floating Point real_T
  //  Lookup Method: Linear_Endpoint
  //
  //  XData parameter uses the same data type and scaling as Input0
  //  YData parameter uses the same data type and scaling as Output0

  LookUp_real_T_real_T( &(Engine_Representation_Y.RA_TQ_MIN_ME),
                       Engine_Representation_P.ra_em_min_tq,
                       Engine_Representation_U.RA_N_EM,
                       Engine_Representation_P.ra_electrical_machine_speed, 20U);

  // Switch: '<S2>/Switch2' incorporates:
  //   Inport: '<Root>/CMD_RA_TQ_SP'
  //   RelationalOperator: '<S2>/LowerRelop1'
  //   RelationalOperator: '<S2>/UpperRelop'
  //   Switch: '<S2>/Switch'

  if (Engine_Representation_U.CMD_RA_TQ_SP >
      Engine_Representation_Y.RA_TQ_MAX_ME) {
    DiscreteTransferFcn3_tmp = Engine_Representation_Y.RA_TQ_MAX_ME;
  } else if (Engine_Representation_U.CMD_RA_TQ_SP <
             Engine_Representation_Y.RA_TQ_MIN_ME) {
    // Switch: '<S2>/Switch'
    DiscreteTransferFcn3_tmp = Engine_Representation_Y.RA_TQ_MIN_ME;
  } else {
    DiscreteTransferFcn3_tmp = Engine_Representation_U.CMD_RA_TQ_SP;
  }

  // End of Switch: '<S2>/Switch2'

  // DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn3'
  DiscreteTransferFcn3_tmp = (DiscreteTransferFcn3_tmp -
    Engine_Representation_P.DiscreteTransferFcn3_DenCoef[1] *
    Engine_Representation_DW.DiscreteTransferFcn3_states) /
    Engine_Representation_P.DiscreteTransferFcn3_DenCoef[0];

  // Outport: '<Root>/RA_TQ_ME' incorporates:
  //   DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn3'

  Engine_Representation_Y.RA_TQ_ME =
    Engine_Representation_P.DiscreteTransferFcn3_NumCoef[0] *
    DiscreteTransferFcn3_tmp +
    Engine_Representation_P.DiscreteTransferFcn3_NumCoef[1] *
    Engine_Representation_DW.DiscreteTransferFcn3_states;

  // Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn3'
  Engine_Representation_DW.DiscreteTransferFcn3_states =
    DiscreteTransferFcn3_tmp;

  // End of Outputs for SubSystem: '<Root>/Engine_Representation'
}

// Model initialize function
void Engine_RepresentationModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&Engine_Representation_M), (NULL));

  // states (dwork)
  (void) memset((void *)&Engine_Representation_DW, 0,
                sizeof(DW_Engine_Representation_T));

  // external inputs
  (void) memset((void *)&Engine_Representation_U, 0,
                sizeof(ExtU_Engine_Representation_T));

  // external outputs
  (void) memset((void *)&Engine_Representation_Y, 0,
                sizeof(ExtY_Engine_Representation_T));

  // InitializeConditions for Atomic SubSystem: '<Root>/Engine_Representation'
  // InitializeConditions for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn3' 
  Engine_Representation_DW.DiscreteTransferFcn3_states =
    Engine_Representation_P.DiscreteTransferFcn3_InitialSta;

  // End of InitializeConditions for SubSystem: '<Root>/Engine_Representation'
}

// Model terminate function
void Engine_RepresentationModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
Engine_RepresentationModelClass::Engine_RepresentationModelClass()
{
  static const P_Engine_Representation_T Engine_Representation_P_temp = {
    //  Variable: ra_electrical_machine_speed
    //  Referenced by:
    //    '<S1>/Maximum torque'
    //    '<S1>/Minimum torque'

    { -12000.0, -10800.0, -9600.0, -8400.0, -7200.0, -6000.0, -4800.0, -3600.0,
      -2400.0, -1200.0, 0.0, 1200.0, 2400.0, 3600.0, 4800.0, 6000.0, 7200.0,
      8400.0, 9600.0, 10800.0, 12000.0 },

    //  Variable: ra_em_max_tq
    //  Referenced by: '<S1>/Maximum torque'

    { 39.823008849557517, 44.247787610619469, 53.097345132743357,
      57.522123893805308, 70.796460176991147, 79.646017699115035,
      79.646017699115035, 79.646017699115035, 79.646017699115035,
      79.646017699115035, 79.646017699115035, 79.646017699115035,
      79.646017699115035, 79.646017699115035, 79.646017699115035,
      79.646017699115035, 70.796460176991147, 57.522123893805308,
      53.097345132743357, 44.247787610619469, 39.823008849557517 },

    //  Variable: ra_em_min_tq
    //  Referenced by: '<S1>/Minimum torque'

    { -39.823008849557517, -44.247787610619469, -53.097345132743357,
      -57.522123893805308, -70.796460176991147, -79.646017699115035,
      -79.646017699115035, -79.646017699115035, -79.646017699115035,
      -79.646017699115035, -79.646017699115035, -79.646017699115035,
      -79.646017699115035, -79.646017699115035, -79.646017699115035,
      -79.646017699115035, -70.796460176991147, -57.522123893805308,
      -53.097345132743357, -44.247787610619469, -39.823008849557517 },

    //  Expression: [(hev_dt/(2*(ra_electrical_machine_tau)+hev_dt)) (hev_dt/(2*(ra_electrical_machine_tau)+hev_dt))]
    //  Referenced by: '<S1>/Discrete Transfer Fcn3'

    { 0.047619047619047616, 0.047619047619047616 },

    //  Expression: [1 ((hev_dt-2*(ra_electrical_machine_tau)))/(2*(ra_electrical_machine_tau)+hev_dt)]
    //  Referenced by: '<S1>/Discrete Transfer Fcn3'

    { 1.0, -0.90476190476190466 },
    0.0                                // Expression: 0
                                       //  Referenced by: '<S1>/Discrete Transfer Fcn3'

  };                                   // Modifiable parameters

  // Initialize tunable parameters
  Engine_Representation_P = Engine_Representation_P_temp;
}

// Destructor
Engine_RepresentationModelClass::~Engine_RepresentationModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Engine_Representatio_T * Engine_RepresentationModelClass::getRTM()
{
  return (&Engine_Representation_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
