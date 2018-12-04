/*******************************************************/
/***************    main superviseur     ***************/
/*******************************************************/

//include des différentes fonctions créées par l'utilisateur
#include "sendFloat.h"
#include "recvFloat.h"
#include "saveData.h"
#include "pere.h"
#include "fils1.h"
#include "fils2.h"

#include <stdio.h>	//pour les printf

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int pipe_1[2];  //definition du pipe en dehors du main pour qu'il ne dependent pas du main
		//si on le creer dans le main il ne pourra pas être vu par les fils

int main(void)
{
    pid_t pid_fils1;
    pid_t pid_fils2;
   //int descripteurTube[2];
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    printf("Création du tube.\n");
    
			//Pour communication entre les processus
pipe(pipe_1);

    pid_fils1 = fork();

    if(pid_fils1 == -1)    
    {
        fprintf(stderr, "Erreur de création du processus1.\n");
        return 1;
    }

	if(pid_fils1 == 0) {
	//on est dans le fils1
	//envoie la consigne dans le canA
	fils1();
	}
	else{
		pid_fils2 = fork();

		if(pid_fils2 == -1)    
		{
			fprintf(stderr, "Erreur de création du processus2.\n");
			return 1;
		}

		if(pid_fils2 == 0){
		// on est dans le fils 2
		// reception et stockage de la sortie
		fils2();
	 	}
	 	else{
		//on est dans le pere
		//generation de la consigne
		consigne();
		}	
     }
     return 0;
}
