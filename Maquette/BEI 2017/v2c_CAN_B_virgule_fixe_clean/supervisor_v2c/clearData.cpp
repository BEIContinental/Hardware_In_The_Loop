#include "clearData.h"

double *clearData( string filename_save){
    //// Inititialise le fichier txt
    
    ofstream fichier(filename_save.c_str(),ios::trunc);
    
    if(fichier) {
    }
    else {cerr << "clear data failled on file" << filename_save << endl;}
    return 0;
}
