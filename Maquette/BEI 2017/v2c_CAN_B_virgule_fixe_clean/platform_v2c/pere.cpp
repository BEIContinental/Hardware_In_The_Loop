/*************************************************
 * ******************    Père       ****************
 *************************************************/

/* Père, qui récupère les nouvelles consignes de couple envoyées par le superviseur sur le bus CAN désiré */

#include "pere.h"

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int pere(){
    
    char can[15]="canA";
    
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    extern int pipe_p_1[2];
    
    //printf("\nFermeture de la sortie tube p_1 dans le père (pid = %d).\n",getpid());
    close(pipe_p_1[0]);
    
    float consigne;
    
    FixedPoint fixed_point;
    
    while(1) {
        printf("Début de l'envoi des consignes de couples au fils1 par le père (pid = %d)\n",getpid());
        
        //entree fa_tq
        consigne = fixed_point.from_can_u16(recvInt16(1,can), 5000.0, 0.0);
        sprintf(messageEcrire, "%f",consigne);
        printf("Le père envoie le message suivant au fils1 : \"%s\".\n",messageEcrire);
        write(pipe_p_1[1], messageEcrire, TAILLE_MESSAGE);
        
        //entree ra_tq
        consigne = fixed_point.from_can_u16(recvInt16(2,can), 1000.0, 0.0);
        sprintf(messageEcrire, "%f",consigne);
        printf("Le père envoie le message suivant au fils1 : \"%s\".\n",messageEcrire);
        write(pipe_p_1[1], messageEcrire, TAILLE_MESSAGE);
        
        printf("Fin de l'envoi des consignes de couples au fils1 par le père (pid = %d)\n\n",getpid());
    }
    
    return 0;
}

