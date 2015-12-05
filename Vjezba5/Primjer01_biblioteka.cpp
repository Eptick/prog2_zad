//Upis u tekstualnu datoteku
#include <iostream>
#include <fstream>
#include "biblioteka_tel_imenik.cc"
using namespace std;
int main(){
  char niz[200];
  int tel;
  cout << "Niz:"; unos(niz);
  cout << niz << endl;
  cout << "Telefonski broj: ";
  while (!unos_tel(tel)); //poziva unos_tel tako dugo dok ne vrati ispravan tel. broj
  cout << tel <<endl;
	return 1;
}
