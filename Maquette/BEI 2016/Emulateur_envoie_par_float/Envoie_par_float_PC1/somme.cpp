#include <iostream>	//Pour afficher les messages (cout)
#include <fstream>		//Pour la lecture des fichier en C++
#include <stdlib.h>
#include <string>

#include "somme.h"

using namespace std;

float somme(  float *TABLEAU , string FileNameInput_s){

 ifstream f;
 f.open(FileNameInput_s.c_str());  // Ouverture du fichier en mode lecture
 string line_s;
 int NbLigne_s = 0;
    while(getline(f, line_s))
    {
        ++NbLigne_s;
    } 
int dim_s=NbLigne_s;


float SUM=0;
	for (int i_s=0 ; i_s < dim_s ; i_s++) {
	float TABi = TABLEAU[i_s];
	SUM = SUM + TABi;
cout << "La valeur de la somme a l'instant " << i_s << " est " << SUM << endl;
	}
//float *SOMME=&SUM;

//return SOMME;
 return SUM;
}

