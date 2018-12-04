/*************************************************
 * ******************   Fils 1      **************
 *************************************************/

/* Fils 1, qui effectue le pas de simulation de la plateforme après avoir reçu les nouvelles consignes du père */

#include "fils1.h"

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int fils1() {
    
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    extern int pipe_p_1[2];
    extern int pipe_1_2[2];
    
    //printf("Fermeture de l'entrée tube p_1 dans le fils1 (pid = %d).\n",getpid());
    close(pipe_p_1[1]);
    //printf("Fermeture de la sortie tube 1_2 dans le fils1 (pid = %d).\n",getpid());
    close(pipe_1_2[0]);
    
    platform_initialize();
    
    while(1) {
        printf("Début de l'exécution d'un pas de simulation par le fils1 (pid = %d)\n",getpid());
        
        read(pipe_p_1[0], messageLire, TAILLE_MESSAGE);
        platform_U.FA_TQ=atof(messageLire);
        //printf("Le fils1 a reçu la consigne FA_TQ suivante du père : \"%s\".\n", getpid(), messageLire);
        
        read(pipe_p_1[0], messageLire, TAILLE_MESSAGE);
        platform_U.RA_TQ=atof(messageLire);
        //printf("Le fils1 a reçu lla consigne RA_TQ suivante du père : \"%s\".\n", getpid(), messageLire);
        
        rt_OneStep();
        
        sprintf(messageEcrire, "%f",platform_Y.PLA_SPEED);
        write(pipe_1_2[1], messageEcrire, TAILLE_MESSAGE);
        
        sprintf(messageEcrire, "%f",platform_Y.PLA_N);
        write(pipe_1_2[1], messageEcrire, TAILLE_MESSAGE);
        
        printf("Fin de l'exécution d'un pas de simulation par le fils1 (pid = %d)\n\n",getpid());
    }
    
    platform_terminate();
    
    return 0;
}
