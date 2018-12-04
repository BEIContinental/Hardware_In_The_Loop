//
// File: ert_main.cpp
//
// Code generated for Simulink model 'Auxiliary_network_12V'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Fri Jan 26 08:13:27 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "Auxiliary_network_12V.h"     // Model's header file
#include "rtwtypes.h"
#include "saveData.h"
#include "readData.h"
#include <vector>

static Auxiliary_network_12VModelClass Auxiliary_network_12V_Obj;// Instance of model class

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
    rtmSetErrorStatus(Auxiliary_network_12V_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  Auxiliary_network_12V_Obj.step();

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
  Auxiliary_network_12V_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.01 seconds (the model's base sample time) here.  The
  //  call syntax for rt_OneStep is
  //
  //   rt_OneStep();

    const int taille = 20001;
    // Input
    long double SYSE_VOLTAGE_HV[taille];
    // Input initialization
    readData(SYSE_VOLTAGE_HV, "INPUTS/SYSE_VOLTAGE_HV.txt");
    // Output
    vector<long double> SYSE_AUX_CURRENT(taille);

    for (int i = 0 ; i < taille ; i++)
    {
        Auxiliary_network_12V_Obj.Auxiliary_network_12V_U.SYSE_VOLTAGE_HV = SYSE_VOLTAGE_HV[i];

        rt_OneStep();

        SYSE_AUX_CURRENT[i] = Auxiliary_network_12V_Obj.Auxiliary_network_12V_Y.SYSE_AUX_CURRENT;
    }

    saveData(taille, SYSE_AUX_CURRENT, "OUTPUTS_CODE/SYSE_AUX_CURRENT_code.txt");

  fflush((NULL));
  while (rtmGetErrorStatus(Auxiliary_network_12V_Obj.getRTM()) == (NULL)) {
    //  Perform other application tasks here
  }

  // Disable rt_OneStep() here

  // Terminate model
  Auxiliary_network_12V_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
