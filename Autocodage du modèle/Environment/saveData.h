#ifndef SAVEDATA_H_INCLUDED
#define SAVEDATA_H_INCLUDED
#include <iostream> //Pour afficher les messages (cout)
#include <fstream> //Pour la lecture des fichier en C++
#include <vector>


using namespace std;

float *saveData(int taille ,vector<long double> sum_save,string filename_save);

#endif // SAVEDATA_H_INCLUDED
