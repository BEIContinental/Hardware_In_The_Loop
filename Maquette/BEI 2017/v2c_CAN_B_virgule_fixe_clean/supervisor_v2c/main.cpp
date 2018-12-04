/*******************************************************
***************    Main supervisor     ***************
*******************************************************/
 
 #include <stdio.h>
 
 #include "pere.h"
 #include "fils1.h"
 #include "fils2.h"
 
 #define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */
 
 /* Définition du pipe en dehors du main pour qu'il ne dépende pas du main.
  * Si on le crée dans le main, il ne pourra pas être vu par les fils ! */
 int pipe_1[2];
 
 int main(void)
 {
     pid_t pid_fils1; // Déclaration du processus fils1
     pid_t pid_fils2; // Déclaration du processus fils2
     
     char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];
     
     pipe(pipe_1); //Pour communication entre les processus
     
     pid_fils1 = fork(); // Création du fils1
     if(pid_fils1 == -1)    
     {
         fprintf(stderr, "Erreur de création du processus1.\n");
         return 1;
     }
     
     if(pid_fils1 == 0) {
         //On est dans le fils1
         //Envoie la consigne dans le bus CAN
         fils1();
     }
     else{
         pid_fils2 = fork(); // Création du fils2
         if(pid_fils2 == -1)    
         {
             fprintf(stderr, "Erreur de création du processus2.\n");
             return 1;
         }
         
         if(pid_fils2 == 0){
             // On est dans le fils 2
             // Réception et stockage de la sortie
             fils2();
         }
         else{
             //On est dans le pere
             //Génération de la consigne
             pere();
         }	
     }
     
     return 0;
 }
 
