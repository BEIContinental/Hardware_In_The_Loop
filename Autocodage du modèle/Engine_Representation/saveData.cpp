#include "saveData.h"
#include <iostream> //Pour afficher les messages (cout)
#include <fstream> //Pour la lecture des fichier en C++
using namespace std;

float *saveData(int taille ,long double *sum_save,string filename_save){

ofstream f(filename_save.c_str());

if(f) {
    for (int i=0 ; i<taille ; i++){
        f << sum_save[i] << endl;
    }
}
return 0;
}

