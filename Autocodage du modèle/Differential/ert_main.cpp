//
// File: ert_main.cpp
//
// Code generated for Simulink model 'Differential'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
// C/C++ source code generated on : Fri Jan 26 01:30:15 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: 32-bit Generic
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "Differential.h"              // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"

static DifferentialModelClass Differential_Obj;// Instance of model class

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
    rtmSetErrorStatus(Differential_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  Differential_Obj.step();

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
  Differential_Obj.initialize();
  int taille= 20001;

  //Inputs
  long double RA_TQ_ME[taille];
  long double RA_TQ_MIN_ME[taille];
  long double RA_TQ_MAX_ME[taille];
  long double PLA_N[taille];

  //Outputs
  long double RA_TQ[taille];
  long double RA_TQ_MIN[taille];
  long double RA_TQ_MAX[taille];
  long double RA_N_EM[taille];


  //init des entrées
  readData(RA_TQ_ME,"INPUTS/RA_TQ_ME.txt");
  readData(RA_TQ_MIN_ME,"INPUTS/RA_TQ_MIN_ME.txt");
  readData(RA_TQ_MAX_ME,"INPUTS/RA_TQ_MAX_ME.txt");
  readData(PLA_N,"INPUTS/PLA_N.txt");

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();
  for (int i=0; i < 20001;i++)
  {
     Differential_Obj.Differential_U.RA_TQ_ME= RA_TQ_ME[i];
     Differential_Obj.Differential_U.RA_TQ_MIN_ME= RA_TQ_MIN_ME[i];
     Differential_Obj.Differential_U.RA_TQ_MAX_ME= RA_TQ_MAX_ME[i];
     Differential_Obj.Differential_U.PLA_N=PLA_N[i];

     rt_OneStep();

     RA_TQ[i]=Differential_Obj.Differential_Y.RA_TQ__MINMAX[0];
     RA_TQ_MIN[i]=Differential_Obj.Differential_Y.RA_TQ__MINMAX[1];
     RA_TQ_MAX[i]=Differential_Obj.Differential_Y.RA_TQ__MINMAX[2];
     RA_N_EM[i]=Differential_Obj.Differential_Y.RA_N_EM;
  }
//printf("%f \n", RA_TQ[0]);
  saveData(taille,RA_TQ,"OUTPUTS_CODE/RA_TQ_code.txt");
  saveData(taille,RA_TQ_MIN,"OUTPUTS_CODE/RA_TQ_MIN_code.txt");
  saveData(taille,RA_TQ_MAX,"OUTPUTS_CODE/RA_TQ_MAX_code.txt");
  saveData(taille,RA_N_EM,"OUTPUTS_CODE/RA_N_EM_code.txt");
  printf("autocoding done \n");

  fflush((NULL));
  while (rtmGetErrorStatus(Differential_Obj.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  Differential_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
