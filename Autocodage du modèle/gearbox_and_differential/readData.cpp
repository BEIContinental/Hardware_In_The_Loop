#include "readData.h"
#include <iostream> //Pour afficher les messages (cout)
#include <fstream> //Pour la lecture des fichier en C++
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

float* readData(long double tableau[TAILLEMAX], string filename_save){

    ifstream fichierlu(filename_save.c_str());
    //float tableau[1024];

    if(fichierlu)
    {
    //L'ouverture s'est bien passée, on peut donc lire

        string ligne; //Une variable pour stocker les lignes lues
        int i = 0;
        long double nombre;

        while(fichierlu >> nombre) //Tant qu'on n'est pas à la fin, on lit
        {
            tableau[i]=nombre;
            //tableau.push_back(12);
            i++;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }

return 0;
}
