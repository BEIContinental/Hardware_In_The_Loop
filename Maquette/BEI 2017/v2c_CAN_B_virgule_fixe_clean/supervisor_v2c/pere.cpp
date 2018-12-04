/*************************************************
 * ******************   Père  ****************
 *************************************************/

#include "pere.h"

#define TAILLE_MESSAGE 256

int pere() {
    
    char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
    
    extern int pipe_1[2];	//Pour communication entre les processus
    
    //printf("\nFermeture de la sortie tube dans le père (pid = %d).\n",getpid());
    close(pipe_1[0]);
    
    float fa_tq;
    
    int ii=0; //initialisation pour la sauvegarde des points (ii=0 pour effacer ii=1 pour ecrire à la suite)
    
    for (int i=0;i<1000;i++){
        
        printf("Début de l'envoi des consignes de couples au fils1 par le père (pid = %d)\n",getpid());
        
        //entrée fa_tq
        if (i<350){
            sprintf(messageEcrire, "2500");
        }
        else{
            sprintf(messageEcrire, "100");
        }
        fa_tq=atof(messageEcrire);
        saveData(fa_tq,"fa_tq.txt",ii);
        
        printf("Le père envoie au fils1 : \"%s\".\n",messageEcrire);
        write(pipe_1[1], messageEcrire, TAILLE_MESSAGE);

        //entrée ra_tq
        if (i<350){
            sprintf(messageEcrire, "500");
        }
        else{
            sprintf(messageEcrire, "50");
        }
        fa_tq=atof(messageEcrire);
        saveData(fa_tq,"ra_tq.txt",ii);
        
        printf("Le père envoie au fils1 : \"%s\".\n",messageEcrire);
        write(pipe_1[1], messageEcrire, TAILLE_MESSAGE);
        
        printf("Fin de l'envoi des consignes de couples au fils1 par le père (pid = %d)\n\n",getpid());
        
        usleep(10000); //Horloge de 10 ms
        ii=1;
    }
    
    return 0;
}
