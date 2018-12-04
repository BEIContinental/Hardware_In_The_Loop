/*************************************************
*******************    pere       ****************
*************************************************/


#include "pere.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "recvFloat.h"

using namespace std;

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int pere(){

        char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
        extern int pipe_p_1[2];

        printf("\nFermeture de la sortie dans le père (pid = %d).\n",getpid());
        close(pipe_p_1[0]);
        float consigne;
        char can[15]="canA";
                while(1){
                
                //entree fa_tq
                consigne = recvFloat(1,can); 
                sprintf(messageEcrire, "%f",consigne);
                printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils : \"%s\".\n\n\n", getpid(), messageEcrire);
                write(pipe_p_1[1], messageEcrire, TAILLE_MESSAGE);

                //entree fa_tq
                consigne = recvFloat(2,can); 
                sprintf(messageEcrire, "%f",consigne);
                printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils : \"%s\".\n\n\n", getpid(), messageEcrire);
                write(pipe_p_1[1], messageEcrire, TAILLE_MESSAGE);

                /*/consigne = recvFloat(2,can); 
                sprintf(messageEcrire, "%f",consigne);
                printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils : \"%s\".\n\n\n", getpid(), messageEcrire);
                write(pipe_p_1[1], messageEcrire, TAILLE_MESSAGE);/*/

                }
        wait(NULL);
return 0;

}

