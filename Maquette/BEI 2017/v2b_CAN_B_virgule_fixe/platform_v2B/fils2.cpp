/*************************************************
*******************   fils 2      ****************
*************************************************/

#include "fils2.h"
#include "sendFloat.h"
#include "fixedPoint.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int fils2() {

	char can[15] = "canA";

        char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
        extern int pipe_1_2[2];

        printf("Fermeture de l'entree tube 1_2 dans le fils2 (pid = %d) .\n\n",getpid());
        close(pipe_1_2[1]);

        float pla_speed;
        float pla_n;

	FixedPoint fixed_point;

        while(1) {
                read(pipe_1_2[0], messageLire, TAILLE_MESSAGE);
                pla_speed = atof(messageLire);
                printf("Envoie de la vitesse du véhicule km/h= %f au superviseur\n",pla_speed); 
                sendFloat(1,fixed_point.to_can_u16(pla_speed, 130.0, 0.0),can);

                read(pipe_1_2[0], messageLire, TAILLE_MESSAGE);
                pla_n = atof(messageLire);
                printf("Envoie de la vitesse de la roue tr/min = %f au superviseur\n",pla_n);
                sendFloat(2,fixed_point.to_can_u16(pla_n, 1100.0, 0.0),can);
        }

	return 0;
}
