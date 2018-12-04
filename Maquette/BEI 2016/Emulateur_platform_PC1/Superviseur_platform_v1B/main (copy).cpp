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

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int main(void)
{
    pid_t pid_fils1;
    pid_t pid_fils2;
    int descripteurTube[2];

   // unsigned char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    printf("Création du tube.\n");
    
    if(pipe(descripteurTube) != 0)
    {
        fprintf(stderr, "Erreur de création du tube.\n");
        return EXIT_FAILURE;
    }

    pid_fils1 = fork();
    pid_fils2 = fork();

    if(pid_fils1 == -1)    
    {
        fprintf(stderr, "Erreur de création du processus1.\n");
        return 1;
    }
  if(pid_fils2 == -1)    
    {
        fprintf(stderr, "Erreur de création du processus2.\n");
        return 1;
    }

    if(pid_fils1 == 0) //on est dans le fils envoie la consigne dans le canA
    {
        printf("Fermeture de l'entrée dans le fils1.\n\n");
        close(descripteurTube[1]);

        
		while(1){
		
		read(descripteurTube[0], messageLire, TAILLE_MESSAGE);

		//printf("Nous sommes dans le fils (pid = %d).\nIl a reçu le message suivant du père : \"%s\".\n\n\n", getpid(), messageLire);
		float consigne;
  		consigne = atof(messageLire);
		sendFloat(consigne);

		}
    }
 /*  int ii = 0;  /// initialise le fichier de sauvegarde pour ii=0

 if(pid_fils2 == 0)
      { 
	char can[15] = "canA";
	float sortie_modele ;
        sortie_modele = recvFloat(can);
	saveData(sortie_modele,"Data.txt",ii);
        printf("\nSauvegard de points terminé.\n");
       ii++;
      }*/

 else  //if ((pid_fils2 != 0)||(pid_fils1 != 0))
     {
        printf("\nFermeture de la sortie dans le père.\n");
        close(descripteurTube[0]);

	for (int i=0;i<15000;i++){
        //sprintf(messageEcrire, "Nombre ecris = %d",i);
        sprintf(messageEcrire, "200");
        printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils : \"%s\".\n\n\n", getppid(), messageEcrire);

        write(descripteurTube[1], messageEcrire, TAILLE_MESSAGE);
	usleep(10000);
	}
        wait(NULL);
     }
    return 0;
}
