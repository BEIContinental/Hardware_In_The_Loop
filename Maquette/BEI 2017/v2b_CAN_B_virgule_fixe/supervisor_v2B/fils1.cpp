/*************************************************
*******************   fils 1      ****************
*************************************************/

#include "fils1.h"
#include "sendFloat.h"
#include "fixedPoint.hpp"

#define TAILLE_MESSAGE 256

int fils1()
{
    	char can[15] = "canA";

	char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
	extern int pipe_1[2];

        printf("Fermeture de l'entrée dans le fils1.\n\n");
        close(pipe_1[1]);

	uint16_t consi;

	FixedPoint fixed_point;

		while(1){
		printf("Début de lenvoie par le fils1 (pid = %d).\n",getpid());

		//envoie de l'entrée 1
		read(pipe_1[0], messageLire, TAILLE_MESSAGE);
  		consi = fixed_point.to_can_u16(atof(messageLire), 5000.0, 0.0);
		sendFloat(1,consi,can);

		//envoie de l'entrée 2
		read(pipe_1[0], messageLire, TAILLE_MESSAGE);
  		consi = fixed_point.to_can_u16(atof(messageLire), 1000.0, 0.0);
		sendFloat(2,consi,can);

		printf("Fin de lenvoie par le fils1 (pid = %d).\n",getpid());
		}

	return 0;
}
