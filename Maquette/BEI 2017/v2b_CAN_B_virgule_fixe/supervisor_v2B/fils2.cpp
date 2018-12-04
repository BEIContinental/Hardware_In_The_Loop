/*************************************************
*******************   fils 2      ****************
*************************************************/

#include "fils2.h"
#include "recvFloat.h"
#include "saveData.h"
#include "fixedPoint.hpp"

int fils2()
{
	char can[15] = "canA";

	int ii=0; 		// initialise le fichier de sauvegarde pour ii=0

	float sortie_modele_pla_speed,sortie_modele_pla_N ;
	uint16_t pla_speed_u16, pla_N_u16;

	FixedPoint fixed_point;

	while(1){
		//printf("\nDebut du fils2\n");
		//printf("\nDebut de la reception de la sortie par le fils2 (pid = %d).\n",getpid());

		//reception de la sortie 1
		pla_speed_u16 = recvFloat(1,can);
		sortie_modele_pla_speed = fixed_point.from_can_u16(pla_speed_u16,130.0,0.0);

		//reception de la sortie 2
		pla_N_u16 = recvFloat(2,can);
		sortie_modele_pla_N = fixed_point.from_can_u16(pla_N_u16,1100.0,0.0);

		//printf("Fin de la reception de la sortie par le fils2 (pid = %d).\n",getpid());
		saveData(sortie_modele_pla_speed,"pla_speed.txt",ii);
		saveData(sortie_modele_pla_N,"pla_N.txt",ii);

		printf("Ecriture dans le fichier texte terminée fils 2 (pid = %d) .\n",getpid());
	        ii=1;
		//printf("Fin du fils2\n");
	}

	return 0;
}
