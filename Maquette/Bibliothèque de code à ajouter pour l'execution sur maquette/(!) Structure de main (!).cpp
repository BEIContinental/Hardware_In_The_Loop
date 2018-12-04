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

    pid_fils1 = fork(); //Creation du premier fils
    
    if(pid_fils1 == 0) //On est dans le fils 1 envoie la consigne dans le canA
    {
        printf("Fermeture de l'entrée dans le fils1.\n\n");
        close(descripteurTube[1]);

		while(1)
		{
			//Debut du fils1
			
			//Ecrire code a executer sur le fils1
			
			//Fin du fils1
		}
    }
    else //On est dans le père
    {
		if(pid_fils1 == -1) //Verification que le fils 1 est bien cree   
		{
			fprintf(stderr, "Erreur de création du processus1.\n");
			return 1;
		}
		
		pid_fils2 = fork(); //Creation du deuxieme fils

		if(pid_fils2 == 0) // on est dans le fils 2
		{ 
			while(1)
			{
				//Debut du fils2
				
				//Ecrire code a executer sur le fils2
				
				//Fin du fils2
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

			//Debut du pere
			
			//Ecrire code a executer sur le pere
			
			//Fin du pere
			wait(NULL);
		}	
    }
	return 0;
}
