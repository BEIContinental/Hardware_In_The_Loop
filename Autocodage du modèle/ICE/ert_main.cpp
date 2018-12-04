//
// File: ert_main.cpp
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
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "ICE.h"                       // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"

static ICEModelClass ICE_Obj;          // Instance of model class

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
    rtmSetErrorStatus(ICE_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  ICE_Obj.step();

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
  ICE_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

    const int taille = 20001;
    // Inputs
    long double FA_ICE_STATE[taille];
    long double FA_ICE_TQ_SP[taille];
    long double FA_N_ICE[taille];
    long double FA_STARTER_REQUEST[taille];
    // Inputs initialization
    readData(FA_ICE_STATE, "INPUTS/FA_ICE_STATE.txt");
    readData(FA_ICE_TQ_SP, "INPUTS/FA_ICE_TQ_SP.txt");
    readData(FA_N_ICE, "INPUTS/FA_N_ICE.txt");
    readData(FA_STARTER_REQUEST, "INPUTS/FA_STARTER_REQUEST.txt");
    // Outputs
    long double FA_GAS_CONSUMPTION[taille];
    long double FA_TQ_ICE[taille];
    long double FA_TQ_STARTER[taille];

    for (int i=0 ; i < taille ; i++)
    {
        ICE_Obj.ICE_U.FA_ICE_STATE = FA_ICE_STATE[i];
        ICE_Obj.ICE_U.FA_ICE_TQ_SP = FA_ICE_TQ_SP[i];
        ICE_Obj.ICE_U.FA_N_ICE = FA_N_ICE[i];
        ICE_Obj.ICE_U.FA_STARTER_REQUEST = FA_STARTER_REQUEST[i];
        rt_OneStep();
        FA_GAS_CONSUMPTION[i] = ICE_Obj.ICE_Y.FA_GAS_CONSUMPTION;
        FA_TQ_ICE[i] = ICE_Obj.ICE_Y.FA_TQ_ICE;
        FA_TQ_STARTER[i] = ICE_Obj.ICE_Y.FA_TQ_STARTER;
    }

    saveData(taille, FA_TQ_ICE, "OUTPUTS_CODE/FA_TQ_ICE_code.txt");
    saveData(taille, FA_GAS_CONSUMPTION, "OUTPUTS_CODE/FA_GAS_CONSUMPTION_code.txt");
    saveData(taille, FA_TQ_STARTER, "OUTPUTS_CODE/FA_TQ_STARTER_code.txt");

    cout << "Done" << endl;

  fflush((NULL));
  while (rtmGetErrorStatus(ICE_Obj.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  ICE_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
