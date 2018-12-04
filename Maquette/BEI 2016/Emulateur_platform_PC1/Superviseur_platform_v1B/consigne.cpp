/*************************************************
*******************   Consigne  ****************
*************************************************/

#include "consigne.h"

using namespace std;
int consigne()
{
	#define TAILLE_MESSAGE 256
	char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];

	extern int pipe_1[2];	//Pour communication entre les processus

	printf("Fermeture de la sortie dans le père.\n");
	close(pipe_1[0]);

	for (int i=0;i<1000;i++){
		//sprintf(messageEcrire, "Nombre ecris = %d",i);
		printf("\nDebut du père\n");
				
		//entrée fa_tq
		if (i<350){
		sprintf(messageEcrire, "2500");
		}
		else{
		sprintf(messageEcrire, "100");
		}
		printf("Nous sommes dans le père (pid = %d).\nIl envoie au fils : \"%s\".\n", getpid(), messageEcrire);

		write(pipe_1[1], messageEcrire, TAILLE_MESSAGE);

		//entrée ra_tq
		if (i<350){
		sprintf(messageEcrire, "500");
		}
		else{
		sprintf(messageEcrire, "50");
		}
		printf("Nous sommes dans le père (pid = %d).\nIl envoie au fils : \"%s\".\n", getpid(), messageEcrire);

		write(pipe_1[1], messageEcrire, TAILLE_MESSAGE);
		//printf("Fin du père\n");
		usleep(10000);
		//usleep(50000);
		//sleep(10);
	}
	wait(NULL);
	return 0;
}
