#include <iostream>	//Pour afficher les messages (cout)
#include <fstream>		//Pour la lecture des fichier en C++
#include <stdlib.h>
#include <string>

#include "LectureData.h"

using namespace std;
	int NbLignes(string FileNameInput){
	ifstream f;
	f.open(FileNameInput.c_str());
	string line;
	int NbLigne = 0;
	while(getline(f, line))
	{
	++NbLigne;
	} 
	return NbLigne;

	}

  float *LectureData(string FileNameInput){
  ifstream f;
  f.open(FileNameInput.c_str());  // Ouverture du fichier en mode lecture


//On ne récupère pas la taille du tableau car le renvoie dans le main dans un tableau de même taille.
//On prend une taille de tableau de 50
   
	int dim = NbLignes(FileNameInput);
	float *TABLEAU=new float[dim];
	string chaine;


//on remet le curseur au debut
f.clear();
f.seekg(0); 

if (f){
int i=0;
	for ( i ; i < dim ; i++) {
		getline(f, chaine);
		TABLEAU[i]=atof(chaine.c_str());
		cout << "La valeur de tab " << i << " est " << TABLEAU[i] << endl;
	}
}

  return TABLEAU;
}

