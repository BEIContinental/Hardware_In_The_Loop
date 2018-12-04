/*************************************************
 * ******************   Fils 2      **************
 *************************************************/

#include "fils2.h"

int fils2()
{
    char can[15] = "canA";
    
    int ii=0; // initialise le fichier de sauvegarde pour ii=0
    
    float sortie_modele_pla_speed,sortie_modele_pla_N ;
    uint16_t pla_speed_u16, pla_N_u16;
    
    FixedPoint fixed_point;
    
    while(1){
        printf("Début de la réception des vitesses par le fils2 (pid = %d).\n",getpid());
        
        //reception de la vitesse plateforme
        pla_speed_u16 = recvInt16(1,can);
        sortie_modele_pla_speed = fixed_point.from_can_u16(pla_speed_u16,130.0,0.0);
        
        //reception de la vitesse des roues
        pla_N_u16 = recvInt16(2,can);
        sortie_modele_pla_N = fixed_point.from_can_u16(pla_N_u16,1100.0,0.0);
        
        printf("Fin de la réception des vitesses par le fils2 (pid = %d).\n",getpid());
        
        saveData(sortie_modele_pla_speed,"pla_speed.txt",ii);
        saveData(sortie_modele_pla_N,"pla_N.txt",ii);
        
        printf("Écriture dans le fichier texte terminée par le fils 2 (pid = %d) .\n",getpid());
        ii=1;
    }
    
    return 0;
}
