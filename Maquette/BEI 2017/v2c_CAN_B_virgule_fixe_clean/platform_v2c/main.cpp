/*************************************************
 * *******************   Main    *****************
 *************************************************/

#include <stdio.h>

#include "pere.h"
#include "fils1.h"
#include "fils2.h"

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int pipe_p_1[2]; // Déclaration du pipe entre le père et le fils1
int pipe_1_2[2]; // Déclaration du pipe entre le fils1 et le fils2

int main(void)
{
    pid_t pid_fils1; // Déclaration du processus fils1
    pid_t pid_fils2; // Déclaration du processus fils2
    
    pipe(pipe_p_1); // Création du pipe entre le père et le fils1
    pipe(pipe_1_2); // Création du pipe entre le fils1 et le fils2
    
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    
    pid_fils1 = fork(); // Création du fils1
    if(pid_fils1 == -1)
    {
        fprintf(stderr, "Erreur de création du processus fils1.\n");
        return 1;
    }
    
    if(pid_fils1 == 0)
    {
        // On est dans le fils1
        fils1();
    }
    else
    {
        pid_fils2 = fork(); // Création du fils2
        if(pid_fils2 == -1)    
        {
            fprintf(stderr, "Erreur de création du processus fils2.\n");
            return 1;
        }
        
        if (pid_fils2 == 0)
        {
            // On est dans le fils2
            fils2();
        }
        else {
            // On est dans le père
            pere();
        }
    }
    
    return 0;
}
