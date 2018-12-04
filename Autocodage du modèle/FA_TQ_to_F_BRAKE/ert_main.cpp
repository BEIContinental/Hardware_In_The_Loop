//
// File: ert_main.cpp
//
// Code generated for Simulink model 'FA_TQ_to_F_BRAKE'.
//
// Model version                  : 1.2
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 06:31:15 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "FA_TQ_to_F_BRAKE.h"          // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"
#include <vector>


static FA_TQ_to_F_BRAKEModelClass FA_TQ_to_F_BRAKE_Obj;// Instance of model class

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
    rtmSetErrorStatus(FA_TQ_to_F_BRAKE_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  FA_TQ_to_F_BRAKE_Obj.step();

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
  FA_TQ_to_F_BRAKE_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.2 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

    const int taille = 20001;

    // Input
    long double CMD_FA_MECHANICAL_BRAKE[taille];
    // Input initialization
    readData(CMD_FA_MECHANICAL_BRAKE, "INPUTS/CMD_FA_MECHANICAL_BRAKE.txt");
    // Output
    vector<long double> FA_PLA_F_BRAKE(taille);

    for (int i=0 ; i < taille ; i++)
    {
        FA_TQ_to_F_BRAKE_Obj.FA_TQ_to_F_BRAKE_U.CMD_FA_MECHANICAL_BRAKE = CMD_FA_MECHANICAL_BRAKE[i];

        rt_OneStep();

        FA_PLA_F_BRAKE[i] = FA_TQ_to_F_BRAKE_Obj.FA_TQ_to_F_BRAKE_Y.FA_PLA_F_BRAKE;
    }

    saveData(taille, FA_PLA_F_BRAKE, "OUTPUTS_CODE/FA_PLA_F_BRAKE_code.txt");

    cout << "Done" << endl;

  fflush((NULL));
  while (rtmGetErrorStatus(FA_TQ_to_F_BRAKE_Obj.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  FA_TQ_to_F_BRAKE_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
