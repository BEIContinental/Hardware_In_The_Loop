//
// File: ert_main.cpp
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
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "Clutch.h"                    // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"

static ClutchModelClass Clutch_Obj;    // Instance of model class

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
    rtmSetErrorStatus(Clutch_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  Clutch_Obj.step();

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
  Clutch_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

    const int taille = 20001;
    // Inputs
    long double FA_TQ_ICE[taille];
    long double FA_N_GBX[taille];
    long double CMD_CLUTCH_SP[taille];
    long double DRI_GBX_SP[taille];
    // Inputs initialization
    readData(FA_TQ_ICE, "INPUTS/FA_TQ_ICE.txt");
    readData(FA_N_GBX, "INPUTS/FA_N_GBX.txt");
    readData(CMD_CLUTCH_SP, "INPUTS/CMD_CLUTCH_SP.txt");
    readData(DRI_GBX_SP, "INPUTS/DRI_GBX_SP.txt");
    // Outputs
    long double FA_N_ICE[taille];
    long double FA_TQ_CLU[taille];
    long double FA_CLU_STUCK[taille];

    for (int i=0 ; i < taille ; i++)
    {
        Clutch_Obj.Clutch_U.FA_TQ_ICE = FA_TQ_ICE[i];
        Clutch_Obj.Clutch_U.FA_N_GBX = FA_N_GBX[i];
        Clutch_Obj.Clutch_U.CMD_CLUTCH_SP = CMD_CLUTCH_SP[i];
        Clutch_Obj.Clutch_U.DRI_GBX_SP = DRI_GBX_SP[i];
        rt_OneStep();
        FA_N_ICE[i] = Clutch_Obj.Clutch_Y.FA_N_ICE;
        FA_TQ_CLU[i] = Clutch_Obj.Clutch_Y.FA_TQ_CLU;
        FA_CLU_STUCK[i] = Clutch_Obj.Clutch_Y.FA_CLU_STUCK;
    }

    saveData(taille, FA_N_ICE, "OUTPUTS/FA_N_ICE_code.txt");
    saveData(taille, FA_TQ_CLU, "OUTPUTS/FA_TQ_CLU_code.txt");
    saveData(taille, FA_CLU_STUCK, "OUTPUTS/FA_CLU_STUCK_code.txt");

    cout << "Done" << endl;

  fflush((NULL));
  while (rtmGetErrorStatus(Clutch_Obj.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  Clutch_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
