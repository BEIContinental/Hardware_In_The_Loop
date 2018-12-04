// Programme de test d'envoie de trames 4 février 2015

/*/#include <iostream>	//Pour afficher les messages (cout)
#include <fstream>		//Pour la lecture des fichier en C++
#include <stdlib.h>
#include <string>/*/
#include "LectureData.h"
#include "somme.h"
#include "sendData.h"
#include "recvData.h"
#include "saveData.h"

using namespace std;



int main()
{
  cout << "Debut du main PC2" << endl;
  cout << "Attente de la reception du fichier envoyé par le PC1" << endl;
  cout << "Debut de la reception du fichier : fichier_a_lire_PC2.txt" << endl;
  recvData("fichier_a_lire_PC2.txt");
  cout << "Fin de la reception du fichier : fichier_a_lire_PC2.txt" << endl;

cout << "sauvegarde des données dans 10 sec" << endl;
for (int i=0;i<10;i++){
sleep(1);
cout << i << endl;
}
float SUM=somme(LectureData("fichier_a_lire_PC2.txt"),"fichier_a_lire_PC2.txt");
saveData(SUM , "somme_PC2.txt");
cout << SUM << endl;



cout << "envoie des données dans 10 sec" << endl;
for (int i=0;i<10;i++){
sleep(1);
cout << i << endl;
}

sendData("somme_PC2.txt");

cout << "Fin du main PC2" << endl;


	return 0;
}
