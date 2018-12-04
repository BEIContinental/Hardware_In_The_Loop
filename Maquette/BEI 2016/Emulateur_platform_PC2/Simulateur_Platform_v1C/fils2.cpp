/*************************************************
*******************   fils 2      ****************
*************************************************/

#include "fils2.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "sendFloat.h"



#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int fils2(){

        char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
        extern int pipe_1_2[2];

        printf("Fermeture de l'entree tube 1_2 dans le fils2 (pid = %d) .\n\n",getpid());
        close(pipe_1_2[1]);
        float pla_speed;
        float pla_n;
        while(1){
                read(pipe_1_2[0], messageLire, TAILLE_MESSAGE);
                pla_speed = atof(messageLire);
                printf("Envoie de la Vitesse du véhicule km/h= %f au PC1\n",pla_speed);
                //sleep(1);   
                sendFloat(1,pla_speed);

                read(pipe_1_2[0], messageLire, TAILLE_MESSAGE);
                pla_n = atof(messageLire);
                printf("Envoie de la Vitesse de la roue tr/min = %f au PC1\n",pla_n);
                //sleep(1);   
                sendFloat(2,pla_n);
        }
return 0;
}
