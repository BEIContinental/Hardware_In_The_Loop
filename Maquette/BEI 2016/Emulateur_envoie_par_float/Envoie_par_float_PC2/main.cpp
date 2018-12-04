/*/Fonctionnement du main






-Attention cout renvoie une avec tronquée du float
le float vaut avec cout : 1.23457e+07
Le float vaut avec printf : 12345678.000000
L'utilisation de printf est recommandée




/*/
#include "LectureData.h"
#include "somme.h"
#include "sendFloat.h"
#include "recvFloat.h"
#include "saveData.h"

using namespace std;



int main()
{

	cout << "Debut du main PC1" << endl;



	  

        char port[5]={'c','a','n','A','\0'};
        
        cout << "Debut reception du nombre de lignes" << endl;
        int taille = (int)recvFloat(port);
        cout << "Fin reception du nombre de lignes" << endl;        
        cout << "Debut reception de " << taille << " floats" << endl;
       
        float r_tab[taille];

        for(int ind=0 ; ind<taille ; ind++){
        float r=recvFloat(port);
        r_tab[ind]=r;
        //usleep(100);
        }
        cout << "Fin reception de " << taille << " floats" << endl;
        cout << "Debut du print du tableau" << endl;
        for(int ind=0 ; ind<taille ; ind++){
        printf("Le float %i vaut avec printf : %f\n",ind , r_tab[ind]);
        }


	cout << "Fin du main PC1" << endl;

return 0;
}
