/*************************************************
*******************    pere       ****************
*************************************************/

#include "recvFloat.h"
#include "pere.h"
#include "fixedPoint.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int pere(){

	char can[15]="canA";

        char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
        extern int pipe_p_1[2];

        printf("\nFermeture de la sortie dans le père (pid = %d).\n",getpid());
        close(pipe_p_1[0]);

	float consigne;

	FixedPoint fixed_point;

                while(1) {
                
                //entree fa_tq
                consigne = fixed_point.from_can_u16(recvFloat(1,can), 5000.0, 0.0);
                sprintf(messageEcrire, "%f",consigne);
                printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils1 : \"%s\".\n\n\n", getpid(), messageEcrire);
                write(pipe_p_1[1], messageEcrire, TAILLE_MESSAGE);

                //entree ra_tq
                consigne = fixed_point.from_can_u16(recvFloat(2,can), 1000.0, 0.0);
                sprintf(messageEcrire, "%f",consigne);
                printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils1 : \"%s\".\n\n\n", getpid(), messageEcrire);
                write(pipe_p_1[1], messageEcrire, TAILLE_MESSAGE);

                }

	return 0;
}

