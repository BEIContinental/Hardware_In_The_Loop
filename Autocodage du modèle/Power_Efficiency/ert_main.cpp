//
// File: ert_main.cpp
//
// Code generated for Simulink model 'Power_efficiency0'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Thu Jan 25 16:08:45 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "Power_efficiency0.h"         // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"

static Power_efficiency0ModelClass Power_efficiency;// Instance of model class

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
    rtmSetErrorStatus(Power_efficiency.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  Power_efficiency.step();

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
  Power_efficiency.initialize();
  int taille= 20001;

  //Inputs
  long double RA_TQ_ME[taille];
  long double RA_N_EM[taille];
  long double SYSE_VOLTAGE_HV[taille];

  //Outputs
  long double RA_EM_CURRENT[taille];

  //init des entrées
  readData(RA_TQ_ME,"INPUTS/RA_TQ_ME.txt");
  readData(RA_N_EM,"INPUTS/RA_N_EM.txt");
  readData(SYSE_VOLTAGE_HV,"INPUTS/SYSE_VOLTAGE_HV.txt");

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

   for (int i=0; i < taille;i++)
  {
     Power_efficiency.Power_efficiency0_U.RA_N_EM=RA_N_EM[i];
     Power_efficiency.Power_efficiency0_U.RA_TQ_ME=RA_TQ_ME[i];
     Power_efficiency.Power_efficiency0_U.SYSE_VOLTAGE_HV=SYSE_VOLTAGE_HV[i];

     rt_OneStep();
     RA_EM_CURRENT[i]=Power_efficiency.Power_efficiency0_Y.RA_EM_CURRENT;
  }

  saveData(taille,RA_EM_CURRENT,"OUTPUTS_CODE/RA_EM_CURRENT_code.txt");
  printf("autocoding done");
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(Power_efficiency.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  Power_efficiency.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
