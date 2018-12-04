/*
 * File: ert_main.cpp
 *
 * Code generated for Simulink model 'simulink_seance4_2sorties'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Fri Jan 15 09:10:47 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "simulink_seance4_2sorties.h" /* Model's header file */
#include "rtwtypes.h"
#include "saveData.h"

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
    rtmSetErrorStatus(simulink_seance4_2sorties_M, "Overrun");
    return;
  }

  OverrunFlag = TRUE;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  simulink_seance4_2sorties_step();

  /* Get model outputs here */

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
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  simulink_seance4_2sorties_initialize();

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.0001 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */

    const int taille = 150;
  simulink_seance4_2sorties_U.u=1.0;
  printf("Simulation du modele pour une entree = %f\n",simulink_seance4_2sorties_U.u);
  double out_tab1[taille];
  double inp_tab[taille];
  double out_tab2[taille];

  for(int i=0 ; i<taille ;i++){
	    rt_OneStep();
	    inp_tab[i]=simulink_seance4_2sorties_U.u;
		out_tab1[i]=simulink_seance4_2sorties_Y.y_sortie1;
		out_tab2[i]=simulink_seance4_2sorties_Y.y_sortie2;
  }

  printf("simulink_seance4_2sorties_Y.y_sortie1 = %f\n",simulink_seance4_2sorties_Y.y_sortie1);
  printf("simulink_seance4_2sorties_Y.y_sortie2 = %f\n",simulink_seance4_2sorties_Y.y_sortie2);
  
  
  saveData(taille,inp_tab,"u.txt");
  saveData(taille,out_tab1,"y_sortie1.txt");
  saveData(taille,out_tab2,"y_sortie2.txt");

  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(simulink_seance4_2sorties_M) == (NULL)) {
    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  simulink_seance4_2sorties_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
