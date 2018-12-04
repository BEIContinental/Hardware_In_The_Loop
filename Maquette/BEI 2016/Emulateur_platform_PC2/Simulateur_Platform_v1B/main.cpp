#include "platform.h"         /* Model's header file */
#include "saveData.h"
#include "rtwtypes.h"
#include "ert_main.h"
#include "recvFloat.h"
#include "sendFloat.h"
#include "fils1.h"
#include "fils2.h"
#include "pere.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

    int pipe_p_1[2];
    int pipe_1_2[2];

int main(void)
{
    pid_t pid_fils1;
    pid_t pid_fils2;

    pipe(pipe_p_1);
    pipe(pipe_1_2);

    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    
    pid_fils1 = fork();
    
    if(pid_fils1 == -1)    
    {
        fprintf(stderr, "Erreur de création du processus fils1.\n");
        return 1;
    }
   if(pid_fils2 == -1)    
    {
        fprintf(stderr, "Erreur de création du processus fils2.\n");
        return 1;
    }

        if(pid_fils1 == 0)
        {
        // on est dans le fils1

        fils1();

        }
        else 
        {
        pid_fils2 = fork();            
                if (pid_fils2 == 0)
                {
                // on est dans le fils2
                
                fils2();
     
                }
                else {
                        //on est dans le pere
                        pere();

               }
        }
    return 0;
}
