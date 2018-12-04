#include "platform.h"         /* Model's header file */
#include "saveData.h"
#include "rtwtypes.h"
#include "ert_main.h"
#include "recvFloat.h"
#include "sendFloat.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int main(void)
{
    pid_t pid_fils1;
    pid_t pid_fils2;
    int descripteurTube[2];
    int descripteurTube1_2[2];
   // unsigned char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    printf("Création du tube.\n");
    
    if(pipe(descripteurTube) != 0)
    {
        fprintf(stderr, "Erreur de création du tube.\n");
        return EXIT_FAILURE;
    }
    if(pipe(descripteurTube1_2) != 0)
    {
        fprintf(stderr, "Erreur de création du tube1_2.\n");
        return EXIT_FAILURE;
    }


    pid_fils1 = fork();
    
    if(pid_fils1 == -1)    
    {
        fprintf(stderr, "Erreur de création du processus fils1.\n");
        return 1;
    }
   if(pid_fils2 == -1)    
    {
        fprintf(stderr, "Erreur de création du processus fils2.\n");
        return 1;
    }

    if(pid_fils1 == 0)
    {
        printf("Fermeture de l'entrée tube dans le fils1 (pid = %d).\n\n",getpid());
        close(descripteurTube[1]);
        printf("Fermeture de la sortie tube 1_2 dans le fils1 (pid = %d).\n\n",getpid());
        close(descripteurTube1_2[0]);
        platform_initialize();
        
		while(1){
		
		read(descripteurTube[0], messageLire, TAILLE_MESSAGE);

		//printf("Nous sommes dans le fils (pid = %d).\nIl a reçu le message suivant du père : \"%s\".\n\n\n", getpid(), messageLire);
		  //platform_U.CMD_BRAKE_SP=0;
          platform_U.FA_TQ=atof(messageLire);
          /*/platform_U.F_ext=0;
          platform_U.RA_TQ=0;
          platform_U.Slope=0;
          platform_U.Wind=0;/*/
		rt_OneStep();
                sprintf(messageEcrire, "%f",platform_Y.PLA_SPEED);
                write(descripteurTube1_2[1], messageEcrire, TAILLE_MESSAGE);
  		//printf("Vitesse du véhicule = %f\n",platform_Y.PLA_SPEED);
        
		}

    }


        else 
        {
        pid_fils2 = fork();            
                if (pid_fils2 == 0)
                {
                        printf("Fermeture de l'entree tube 1_2 dans le fils2 (pid = %d) .\n\n",getpid());
                        close(descripteurTube1_2[1]);
                        float speed;
                        while(1){
                                read(descripteurTube1_2[0], messageLire, TAILLE_MESSAGE);
                                speed = atof(messageLire);
                                printf("Envoie de la Vitesse du véhicule = %f au PC1\n",speed);
                                //sleep(5);   
                                sendFloat(speed);
                        }
     
                }
                else {

                printf("\nFermeture de la sortie dans le père (pid = %d).\n", getpid());
                close(descripteurTube[0]);
                float consigne;
                char can[15]="canA";
	                for (int i=0;i<15000;i++){
                        
                        consigne = recvFloat(can); 
                        sprintf(messageEcrire, "%f",consigne);
                        printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils : \"%s\".\n\n\n", getpid(), messageEcrire);

                        write(descripteurTube[1], messageEcrire, TAILLE_MESSAGE);

	                }
                wait(NULL);
                }
        }
    return 0;
}
