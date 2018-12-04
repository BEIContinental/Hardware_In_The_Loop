/*************************************************
 * ******************   Fils 2      **************
 *************************************************/

/* Fils 2, qui envoie les nouvelles vitesses (vitesse du véhicule et vitesse de la roue) au superviseur par le bus CAN souhaité */

#include "fils2.h"

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int fils2() {
    
    char can[15] = "canA";
    
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    extern int pipe_1_2[2];
    
    //printf("Fermeture de l'entree tube 1_2 dans le fils2 (pid = %d) .\n",getpid());
    close(pipe_1_2[1]);
    
    float pla_speed;
    float pla_n;
    
    FixedPoint fixed_point;
    
    while(1) {
        printf("Début de l'envoi des vitesses au superviseur par le fils2 (pid = %d)\n",getpid());
        
        // Vitesse du véhicule
        read(pipe_1_2[0], messageLire, TAILLE_MESSAGE);
        pla_speed = atof(messageLire);
        printf("Le fils2 envoie la vitesse du véhicule km/h= %f au superviseur\n",pla_speed);
        sendInt16(1,fixed_point.to_can_u16(pla_speed, 130.0, 0.0),can);
        
        // Vitesse des roues
        read(pipe_1_2[0], messageLire, TAILLE_MESSAGE);
        pla_n = atof(messageLire);
        printf("Le fils2 envoie la vitesse de la roue tr/min = %f au superviseur\n",pla_n);
        sendInt16(2,fixed_point.to_can_u16(pla_n, 1100.0, 0.0),can);
        
        printf("Fin de l'envoi des vitesses au superviseur par le fils2\n (pid = %d)\n\n",getpid());
    }
    
    return 0;
}
