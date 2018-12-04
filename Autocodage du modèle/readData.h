#ifndef READDATA_H_INCLUDED
#define READDATA_H_INCLUDED
#include <string>
#include <iostream> //Pour afficher les messages (cout)
#include <fstream> //Pour la lecture des fichier en C++
#include <sstream>
#include <vector>
#define TAILLEMAX 30000

using namespace std;

//float* readData(vector<long double> tableau, string filename_save);
float* readData(long double tableau[TAILLEMAX], string filename_save);

#endif // READDATA_H_INCLUDED
