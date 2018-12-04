#include "LectureData.h"
#include "somme.h"
#include "sendFloat.h"
#include "recvFloat.h"
#include "saveData.h"

using namespace std;



int main()
{

	cout << "Debut du main PC1" << endl;
	
	cout << "Debut lecture du fichier" << endl;
	int taille = NbLignes("fichier_a_lire_PC1.txt"); //fonction présente dans LectureData.cpp
	float *TABLEAU=new float[taille];
	TABLEAU=LectureData("fichier_a_lire_PC1.txt");
	cout << "Fin lecture du fichier" << endl;

	cout << "Debut envoie du nombre de ligne au PC2" << endl;
	sendFloat(taille);
	cout << "Fin envoie du nombre de ligne au PC2" << endl << endl;
	
	cout << "Debut envoie de " << taille << " floats" << endl << endl;
	for(int ind=0 ; ind<NbLignes("fichier_a_lire_PC1.txt") ; ind++){

	printf("Le nombre vaut : %f\n",TABLEAU[ind]);
	sendFloat(TABLEAU[ind]);
        usleep(1000);
	}
	cout << endl <<"Fin envoie de " << taille << " floats" << endl << endl;


	cout << "Fin du main PC1" << endl;

/*/	
	cout << "Debut envoie " << endl;
	float nombre=12345678;
	for(int ind=0 ; ind<20 ; ind++){
	nombre=nombre+1;
	printf("Le nombre vaut : %f\n",nombre);
	sendFloat(nombre);
        usleep(1000);
	}

/*/

return 0;
}
