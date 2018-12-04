#include "LectureData.h"
#include "somme.h"
#include "sendData.h"
#include "recvData.h"
#include "saveData.h"

using namespace std;



int main()
{

  cout << "Debut du main PC1" << endl;

  cout << "Debut envoie du fichier : fichier_a_lire_PC1.txt " << endl;
  sendData("fichier_a_lire_PC1.txt");
  cout << "Fin envoie du fichier : fichier_a_lire_PC1.txt " << endl;

  cout << "Attente d'une réponse du PC2" << endl;
  cout << "Debut reception du fichier : somme_PC1.txt" << endl;
  recvData("somme_PC1.txt");
  cout << "Fin reception du fichier : somme_PC1.txt" << endl;

  cout << "Debut lecture data du fichier : somme_PC1.txt" << endl;
  cout << "La somme vaut : " << *LectureData("somme_PC1.txt") << endl;
  cout << "Fin lecture data du fichier : somme_PC1.txt" << endl;

cout << "Fin du main PC1" << endl;

/*/
cout << "Debut du main PC1" << endl;
float SUM = somme(LectureData("fichier_a_lire_PC1.txt"),"fichier_a_lire_PC1.txt") ;
cout << SUM << endl;
cout << "Fin du main PC1" << endl;
/*/
return 0;
}
