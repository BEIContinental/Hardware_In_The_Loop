/*
 * File: ert_main.cpp
 *
 * Code generated for Simulink model 'platform'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Feb 17 11:51:33 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "platform.h"         /* Model's header file */
#include "saveData.h"
#include "rtwtypes.h"
#include "ert_main.h"

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = 0;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(platform_M, "Overrun");
    return;
  }

  OverrunFlag = TRUE;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */

  /* Step the model */
  platform_step();
  
  /* Indicate task complete */
  OverrunFlag = FALSE;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustates how you do this relative to initializing the model.
 */
int_T ert_main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  platform_initialize();

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.0001 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   */
     
  const int taille = 15000;
  platform_U.CMD_BRAKE_SP=0;
  platform_U.FA_TQ=50;
  platform_U.F_ext=0;
  platform_U.RA_TQ=300;
  platform_U.Slope=0;
  platform_U.Wind=0;
  printf("Simulation du modele pour une entree = %f\n",platform_U.CMD_BRAKE_SP);
  double PLAN_tab[taille];
  double PLASPEED_tab[taille];
  double FA_TQ_tab[taille];
  double RA_TQ_tab[taille];
  
  for(int i=0 ; i<taille ;i++){
  rt_OneStep();
  /* Get model outputs here */
  //inp_tab[i]=platform_U.input;
  PLAN_tab[i]=platform_Y.PLA_N;
  PLASPEED_tab[i]=platform_Y.PLA_SPEED;
  FA_TQ_tab[i]=platform_U.FA_TQ;
  RA_TQ_tab[i]=platform_U.RA_TQ;

  printf("Modele_1er_ordre_Y.ouput = %f\n",platform_Y.PLA_SPEED);
  //usleep(10000); //sleep 10ms
  }
  
  saveData(taille,PLAN_tab,"PLA_N_C.txt");
  saveData(taille,PLASPEED_tab,"PLA_SPEED_C.txt");
  saveData(taille,FA_TQ_tab,"FA_TQ_C.txt");
  saveData(taille,RA_TQ_tab,"RA_TQ_C.txt");

  fflush((NULL));
  //while (rtmGetErrorStatus(platform_M) == (NULL)) {
    /*  Perform other application tasks here */
  //}

  /* Disable rt_OneStep() here */

  /* Terminate model */
  platform_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
