//
// File: ert_main.cpp
//
// Code generated for Simulink model 'gearbox_and_differential'.
//
// Model version                  : 1.2
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 02:56:48 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "gearbox_and_differential.h"  // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"
#include <vector>

static gearbox_and_differentialModelClass gearbox_and_differential_Obj;// Instance of model class

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(gearbox_and_differential_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  gearbox_and_differential_Obj.step();

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example "main" function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific.  This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Initialize model
  gearbox_and_differential_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  const int taille = 20001;
  // Inputs
  long double DRI_GBX_SP[taille];
  long double FA_N_ICE[taille];
  long double FA_TQ_CLU[taille];
  long double FA_TQ_MAX_ICE[taille];
  long double FA_TQ_MIN_ICE[taille];
  long double PLA_N[taille];
  // Inputs initialization
  readData(DRI_GBX_SP , "INPUTS/DRI_GBX_SP.txt");
  readData(FA_N_ICE, "INPUTS/FA_N_ICE.txt");
  readData(FA_TQ_CLU, "INPUTS/FA_TQ_CLU.txt");
  readData(FA_TQ_MAX_ICE, "INPUTS/FA_TQ_MAX_ICE.txt");
  readData(FA_TQ_MIN_ICE, "INPUTS/FA_TQ_MIN_ICE.txt");
  readData(PLA_N, "INPUTS/PLA_N.txt");
  // Outputs
  vector<long double> FA_N_GBX(taille);
  vector<long double> FA_TQ(taille);
  vector<long double> FA_TQ_MAX(taille);
  vector<long double> FA_TQ_MIN(taille);

  for (int i=0 ; i < taille ; i++)
  {
      gearbox_and_differential_Obj.gearbox_and_differential_U.DRI_GBX_SP = DRI_GBX_SP[i];
      gearbox_and_differential_Obj.gearbox_and_differential_U.FA_N_ICE = FA_N_ICE[i];
      gearbox_and_differential_Obj.gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[0] = FA_TQ_MAX_ICE[i];
      gearbox_and_differential_Obj.gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[1] = FA_TQ_MIN_ICE[i];
      gearbox_and_differential_Obj.gearbox_and_differential_U.FA_TQ_AND_MINMAX_ICE[2] = FA_TQ_CLU[i];

      rt_OneStep();

      FA_N_GBX[i] = gearbox_and_differential_Obj.gearbox_and_differential_Y.FA_N_GBX;
      FA_TQ[i] = gearbox_and_differential_Obj.gearbox_and_differential_Y.FA_TQ_AND_MINMAX[2];
      FA_TQ_MAX[i] = gearbox_and_differential_Obj.gearbox_and_differential_Y.FA_TQ_AND_MINMAX[0];
      FA_TQ_MIN[i] = gearbox_and_differential_Obj.gearbox_and_differential_Y.FA_TQ_AND_MINMAX[1];
  }

  saveData(taille, FA_N_GBX, "OUTPUTS_CODE/FA_N_GBX_code.txt");
  saveData(taille, FA_TQ, "OUTPUTS_CODE/FA_TQ_code.txt");
  saveData(taille, FA_TQ_MAX, "OUTPUTS_CODE/FA_TQ_MAX_code.txt");
  saveData(taille, FA_TQ_MIN, "OUTPUTS_CODE/FA_TQ_MIN_code.txt");

  cout << "Done" << endl;

  fflush((NULL));
  while (rtmGetErrorStatus(gearbox_and_differential_Obj.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  gearbox_and_differential_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
