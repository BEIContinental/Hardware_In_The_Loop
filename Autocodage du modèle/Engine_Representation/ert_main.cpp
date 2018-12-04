//
// File: ert_main.cpp
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
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "Engine_Representation.h"     // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"

static Engine_RepresentationModelClass Engine;// Instance of model class

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
    rtmSetErrorStatus(Engine.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  Engine.step();

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
// illustates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Initialize model
  Engine.initialize();
  int taille= 20001;

  //Inputs
  long double CMD_RA_TQ_SP[taille];
  long double RA_N_EM[taille];

  //Outputs
  long double RA_TQ_ME[taille];
  long double RA_TQ_MIN_ME[taille];
  long double RA_TQ_MAX_ME[taille];


  //init des entrées
  readData(CMD_RA_TQ_SP,"INPUTS/CMD_RA_TQ_SP.txt");
  readData(RA_N_EM,"INPUTS/RA_N_EM.txt");

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  for (int i=0; i < 20001;i++)
  {
     Engine.Engine_Representation_U.CMD_RA_TQ_SP= CMD_RA_TQ_SP[i];
     Engine.Engine_Representation_U.RA_N_EM= RA_N_EM[i];
     rt_OneStep();
     RA_TQ_ME[i]=Engine.Engine_Representation_Y.RA_TQ_ME;
     RA_TQ_MIN_ME[i]=Engine.Engine_Representation_Y.RA_TQ_MIN_ME;
     RA_TQ_MAX_ME[i]=Engine.Engine_Representation_Y.RA_TQ_MAX_ME;
  }

  saveData(taille,RA_TQ_ME,"OUTPUTS_CODE/RA_TQ_ME_code.txt");
  saveData(taille,RA_TQ_MIN_ME,"OUTPUTS_CODE/RA_TQ_MIN_ME_code.txt");
  saveData(taille,RA_TQ_MAX_ME,"OUTPUTS_CODE/RA_TQ_MAX_ME_code.txt");
  printf("autocoding done");

  fflush((NULL));
  while (rtmGetErrorStatus(Engine.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }
  // Disable rt_OneStep() here
  // Terminate model
  Engine.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
