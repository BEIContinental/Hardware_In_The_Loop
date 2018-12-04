/*************************************************
*******************   fils 2      ****************
*************************************************/

#include "fils2.h"
#include "recvFloat.h"
#include "saveData.h"

int fils2()
{		int ii=0; 		// initialise le fichier de sauvegarde pour ii=0
		char can[15] = "canA";
		float sortie_modele_pla_speed,sortie_modele_pla_N ;
		while(1){
		//printf("\nDebut du fils2\n");
		//printf("\nDebut de la reception de la sortie par le fils2 (pid = %d).\n",getpid());

		//reception de la sortie 1
		sortie_modele_pla_speed = recvFloat(1,can);

		//reception de la sortie 2
		sortie_modele_pla_N = recvFloat(2,can);

		//printf("Fin de la reception de la sortie par le fils2 (pid = %d).\n",getpid());
		saveData(sortie_modele_pla_speed,"pla_speed.txt",ii);
		saveData(sortie_modele_pla_N,"pla_N.txt",ii);

		printf("Ecriture dans le fichier texte terminée fils 2 (pid = %d) .\n",getpid());
	        ii=1;
		//printf("Fin du fils2\n");
		}
return 0;
}
