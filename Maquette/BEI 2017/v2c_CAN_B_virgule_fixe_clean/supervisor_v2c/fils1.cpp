/*************************************************
 * ******************   Fils 1      ****************
 *************************************************/

#include "fils1.h"

#define TAILLE_MESSAGE 256

int fils1()
{
    char can[15] = "canA";
    
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    extern int pipe_1[2];
    
    //printf("Fermeture de l'entrée tube dans le fils1 (pid = %d).\n",getpid());
    close(pipe_1[1]);
    
    uint16_t consi;
    
    FixedPoint fixed_point;
    
    while(1) {
        printf("Début de l'envoi des consignes à la plateforme par le fils1 (pid = %d)\n",getpid());
        
        //entrée fa_tq
        read(pipe_1[0], messageLire, TAILLE_MESSAGE);
        consi = fixed_point.to_can_u16(atof(messageLire), 5000.0, 0.0);
        sendInt16(1,consi,can);
        
        //entrée ra_tq
        read(pipe_1[0], messageLire, TAILLE_MESSAGE);
        consi = fixed_point.to_can_u16(atof(messageLire), 1000.0, 0.0);
        sendInt16(2,consi,can);
        
        printf("Fin de l'envoi des consignes à la plateforme par le fils1 (pid = %d)\n\n",getpid());
    }
    
    return 0;
}
