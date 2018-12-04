/*************************************************
*******************   Consigne  ****************
*************************************************/

#include "consigne.h"
#include "saveData.h"

using namespace std;
int consigne()
{
	#define TAILLE_MESSAGE 256
	char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];

	extern int pipe_1[2];	//Pour communication entre les processus

	printf("Fermeture de la sortie dans le père.\n");
	close(pipe_1[0]);
	float fa_tq;
	int ii=0; //initialisation pour la sauvegarde des points (ii=0 pour effacer ii=1 pour ecrire à la suite)
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
		fa_tq=atof(messageEcrire);
		saveData(fa_tq,"fa_tq.txt",ii);
		printf("Nous sommes dans le père (pid = %d).\nIl envoie au fils : \"%s\".\n", getpid(), messageEcrire);

		write(pipe_1[1], messageEcrire, TAILLE_MESSAGE);

		//entrée ra_tq
		if (i<350){
		sprintf(messageEcrire, "500");
		}
		else{
		sprintf(messageEcrire, "50");
		}
		fa_tq=atof(messageEcrire);
		saveData(fa_tq,"ra_tq.txt",ii);
		printf("Nous sommes dans le père (pid = %d).\nIl envoie au fils : \"%s\".\n", getpid(), messageEcrire);

		write(pipe_1[1], messageEcrire, TAILLE_MESSAGE);
		//printf("Fin du père\n");
		usleep(10000);
		//usleep(50000);
		//sleep(10);
		ii=1;
	}
	//wait(NULL);
	return 0;
}
