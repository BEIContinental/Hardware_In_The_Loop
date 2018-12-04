/*************************************************
*******************   fils 1      ****************
*************************************************/
#include "platform.h"
#include "rtwtypes.h"
#include "ert_main.h"
#include "fils1.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int fils1(){
        char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
        extern int pipe_p_1[2];
        extern int pipe_1_2[2];

        printf("Fermeture de l'entrée tube dans le fils1 (pid = %d).\n\n",getpid());
        close(pipe_p_1[1]);
        printf("Fermeture de la sortie tube 1_2 dans le fils1 (pid = %d).\n\n",getpid());
        close(pipe_1_2[0]);
        platform_initialize();
        
		while(1){
		


		//printf("Nous sommes dans le fils (pid = %d).\nIl a reçu le message suivant du père : \"%s\".\n\n\n", getpid(), messageLire);
		//platform_U.CMD_BRAKE_SP=0;
       		read(pipe_p_1[0], messageLire, TAILLE_MESSAGE);
                platform_U.FA_TQ=atof(messageLire);
        
       		read(pipe_p_1[0], messageLire, TAILLE_MESSAGE);
                platform_U.RA_TQ=atof(messageLire);
                /*/platform_U.F_ext=0;
                platform_U.Slope=0;
                platform_U.Wind=0;/*/
		rt_OneStep();
                sprintf(messageEcrire, "%f",platform_Y.PLA_SPEED);
                write(pipe_1_2[1], messageEcrire, TAILLE_MESSAGE);
                
                sprintf(messageEcrire, "%f",platform_Y.PLA_N);
                write(pipe_1_2[1], messageEcrire, TAILLE_MESSAGE);
  		//printf("Vitesse du véhicule = %f\n",platform_Y.PLA_SPEED);
        
		}
return 0;
}

