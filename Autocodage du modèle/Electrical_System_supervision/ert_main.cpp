//
// File: ert_main.cpp
//
// Code generated for Simulink model 'Electrical_System_supervision'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 09:11:10 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "Electrical_System_supervision.h" // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"
#include <vector>

static Electrical_System_supervisionModelClass Electrical_System_supervisi_Obj;// Instance of model class

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
    rtmSetErrorStatus(Electrical_System_supervisi_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  Electrical_System_supervisi_Obj.step();

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
  Electrical_System_supervisi_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  const int taille = 20001;
  // Inputs
  long double RA_N_EM[taille];
  long double SYSE_AUX_CURRENT[taille];
  long double SYSE_SOC[taille];
  long double SYSE_VOLTAGE_HV[taille];
  // Inputs initialization
  readData(RA_N_EM, "INPUTS/RA_N_EM.txt");
  readData(SYSE_AUX_CURRENT, "INPUTS/SYSE_AUX_CURRENT.txt");
  readData(SYSE_SOC, "INPUTS/SYSE_SOC.txt");
  readData(SYSE_VOLTAGE_HV, "INPUTS/SYSE_VOLTAGE_HV.txt");
  // Outputs
  vector<long double> SYSE_TQ_MAX(taille);
  vector<long double> SYSE_TQ_MIN(taille);

  for (int i=0 ; i<taille ; i++)
  {
      Electrical_System_supervisi_Obj.Electrical_System_supervision_U.RA_N_EM = RA_N_EM[i];
      Electrical_System_supervisi_Obj.Electrical_System_supervision_U.SYSE_AUX_CURRENT = SYSE_AUX_CURRENT[i];
      Electrical_System_supervisi_Obj.Electrical_System_supervision_U.SYSE_SOC = SYSE_SOC[i];
      Electrical_System_supervisi_Obj.Electrical_System_supervision_U.SYSE_VOLTAGE_HV = SYSE_VOLTAGE_HV[i];

      rt_OneStep();

      SYSE_TQ_MAX[i] = Electrical_System_supervisi_Obj.Electrical_System_supervision_Y.SYSE_TQ_MAX;
      SYSE_TQ_MIN[i] = Electrical_System_supervisi_Obj.Electrical_System_supervision_Y.SYSE_TQ_MIN;
  }

  saveData(taille, SYSE_TQ_MAX, "OUTPUTS_CODE/SYSE_TQ_MAX_code.txt");
  saveData(taille, SYSE_TQ_MIN, "OUTPUTS_CODE/SYSE_TQ_MIN_code.txt");

  fflush((NULL));
  while (rtmGetErrorStatus(Electrical_System_supervisi_Obj.getRTM()) == (NULL))
  {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  Electrical_System_supervisi_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
