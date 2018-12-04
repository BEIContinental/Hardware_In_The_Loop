/*************************************************
*******************   fils 1      ****************
*************************************************/

#include "fils1.h"
#include "sendFloat.h"

int fils1()
{
	#define TAILLE_MESSAGE 256
    char can[15] = "canA";
	char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];

	extern int pipe_1[2];

        printf("Fermeture de l'entrée dans le fils1.\n\n");
        close(pipe_1[1]);
	float consi;
		while(1){

		//envoie de l'entrée 1
		read(pipe_1[0], messageLire, TAILLE_MESSAGE);
  		consi = atof(messageLire);
		sendFloat(1,consi,can);

		//envoie de l'entrée 2
		read(pipe_1[0], messageLire, TAILLE_MESSAGE);
  		consi = atof(messageLire);
		sendFloat(2,consi,can);

		printf("Fin de lenvoie par le fils 1 (pid = %d).\n",getpid());
		//printf("Fin du fils1\n");
		}
return 0;
}
