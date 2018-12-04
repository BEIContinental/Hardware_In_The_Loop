#include "saveData.h"

float *saveData(float sum_save, string filename_save,int i) {
    
    /// Initialise le fichier
    if (i == 0){clearData(filename_save);}
    
    //// sauvegarde des points
    ofstream fichier(filename_save.c_str(),ios::app);
    
    if(fichier) {
        fichier << sum_save << endl;
        fichier.close();  // on referme le fichier
    }
    else {cerr << "La sauvegarde de points n'a pas abouti" << endl;}
    return 0;
}
