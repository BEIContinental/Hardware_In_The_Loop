//
// File: ert_main.cpp
//
// Code generated for Simulink model 'Platform'.
//
// Model version                  : 1.3
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 03:34:05 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "Platform.h"                  // Model's header file
#include "rtwtypes.h"
#include "readData.h"
#include "saveData.h"

static PlatformModelClass Platform_Obj;// Instance of model class

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
    rtmSetErrorStatus(Platform_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  Platform_Obj.step();

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
  Platform_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  const int taille = 20001;
  // Inputs
  long double F_ext[taille];
  long double FA_PLA_F_BRAKE[taille];
  long double FA_TQ[taille];
  long double RA_PLA_F_BRAKE[taille];
  long double RA_TQ[taille];
  long double Slope___[taille];
  long double Wind[taille];
  // Inputs initialization
  readData(F_ext, "INPUTS/F_ext.txt");
  readData(FA_PLA_F_BRAKE, "INPUTS/FA_PLA_F_BRAKE.txt");
  readData(FA_TQ, "INPUTS/FA_TQ.txt");
  readData(RA_PLA_F_BRAKE, "INPUTS/RA_PLA_F_BRAKE.txt");
  readData(RA_TQ, "INPUTS/RA_TQ.txt");
  readData(Slope___, "INPUTS/Slope___.txt");
  readData(Wind, "INPUTS/Wind.txt");
  // Outputs
  long double PLA_N[taille];
  long double PLA_SPEED[taille];

  for (int i=0 ; i < taille ; i++)
  {
      Platform_Obj.Platform_U.FA_PLA_F_BRAKE = FA_PLA_F_BRAKE[i];
      Platform_Obj.Platform_U.FA_TQ = FA_TQ[i];
      Platform_Obj.Platform_U.F_ext = F_ext[i];
      Platform_Obj.Platform_U.RA_PLA_F_BRAKE = RA_PLA_F_BRAKE[i];
      Platform_Obj.Platform_U.RA_TQ = RA_TQ[i];
      Platform_Obj.Platform_U.Slope = Slope___[i];
      Platform_Obj.Platform_U.Wind = Wind[i];

      rt_OneStep();

      PLA_N[i] = Platform_Obj.Platform_Y.PLA_N;
      PLA_SPEED[i] = Platform_Obj.Platform_Y.PLA_SPEED;
  }

  //saveData(taille, PLA_N, "OUTPUTS_CODE/PLAN_N_code.txt");
  //saveData(taille, PLA_SPEED, "OUTPUTS_CODE/PLA_SPEED_code.txt");

  cout << "Done" << endl;

  fflush((NULL));
  while (rtmGetErrorStatus(Platform_Obj.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  Platform_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
