#include "saveData.h"
#include <iostream>	//Pour afficher les messages (cout)
#include <fstream>	//Pour la lecture des fichier en C++
using namespace std;

float *sendData(float sum_save,string filename_save) {

ofstream f(filename_save.c_str());

if(f) {
	f << sum_save;
	}
return 0;
}
