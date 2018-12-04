/*******************************************************/
/***************    main superviseur     ***************/
/*******************************************************/

#include "sendFloat.h"
#include "recvFloat.h"
#include "saveData.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MESSAGE 256 //Correspond à la taille de la chaîne à lire et à écrire
#define CONSIGNE 100 //Consigne a envoyer

int main(void)
{
    pid_t pid_fils1;
    pid_t pid_fils2;
    int descripteurTube[2];

    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    printf("Création du tube.\n");
    
    if(pipe(descripteurTube) != 0)
    {
        fprintf(stderr, "Erreur de création du tube.\n");
        return EXIT_FAILURE;
    }

	int ii = 0;  /// initialise le fichier de sauvegarde pour ii=0

    pid_fils1 = fork(); //Creation du premier fils
    
    if(pid_fils1 == 0) //On est dans le fils 1 envoie la consigne dans le canA
    {
        printf("Fermeture de l'entrée dans le fils1.\n\n");
        close(descripteurTube[1]);

		while(1)
		{
			//printf("\nDebut du fils1\n");
			read(descripteurTube[0], messageLire, TAILLE_MESSAGE);
			float consigne;
			consigne = atof(messageLire);
			printf("Début de lenvoie par le fils 1 (pid = %d).\n",getpid());
			sendFloat(consigne);
			printf("Fin de lenvoie par le fils 1 (pid = %d).\n\n",getpid());
			//printf("Fin du fils1\n");
		}
    }
    else //On est dans le père
    {
		if(pid_fils1 == -1) //Verification que le fils 2 est bien cree   
		{
			fprintf(stderr, "Erreur de création du processus1.\n");
			return 1;
		}
		
		pid_fils2 = fork(); //Creation du deuxieme fils

		if(pid_fils2 == 0) // on est dans le fils 2
		{ 
			char can[15] = "canA";
			float sortie_modele ;
			while(1)
			{
				//printf("\nDebut du fils2\n");
				//printf("\nDebut de la reception de la sortie par le fils2 (pid = %d).\n",getpid());
				sortie_modele = recvFloat(can);
				//printf("Fin de la reception de la sortie par le fils2 (pid = %d).\n",getpid());
				saveData(sortie_modele,"Data.txt",ii);
				printf("Ecriture dans le fichier texte terminée fils 2 (pid = %d) .\n",getpid());
				ii=1;
				//printf("Fin du fils2\n");
			}
		}
		else //On est dans le père
		{ 
			if(pid_fils2 == -1) //Verification que le fils 2 est bien cree  
			{	
				fprintf(stderr, "Erreur de création du processus2.\n");
				return 1;
			}
			
			printf("Fermeture de la sortie dans le père.\n");
			close(descripteurTube[0]);

			for (int i=0;i<15000;i++)
			{
				//sprintf(messageEcrire, "Nombre ecris = %d",i);
				//printf("\nDebut du père\n");
				sprintf(messageEcrire, "CONSIGNE");
				printf("Nous sommes dans le père (pid = %d).\nIl envoie au fils : \"%s\".\n", getpid(), messageEcrire);

				write(descripteurTube[1], messageEcrire, TAILLE_MESSAGE);
				//printf("Fin du père\n");
				usleep(10000);
			}
			wait(NULL);
		}	
    }
	return 0;
}
