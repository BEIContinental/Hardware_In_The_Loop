#include "clearData.h"
#include <iostream>	//Pour afficher les messages (cout)
#include <fstream>	//Pour la lecture des fichier en C++
using namespace std;

double *clearData( string filename_save){
	//// Inititialise le fichier txt

	ofstream fichier(filename_save.c_str(),ios::trunc);

	if(fichier) {}
	else {cerr << "clear data failled on file" << filename_save << endl;}
	return 0;
}