//Jednostavna vezana lista u C++
#include <iostream>
using namespace std;
struct tstudent{
  int mat_br;
  char prez_ime[35];
  int god_stu;
  tstudent *sljedeci;
};//struct
void dodaj_element(tstudent *lista){ // dodaje element na kraj liste
  tstudent *novi,*zadnji;
  zadnji = lista;
  while (zadnji->sljedeci)
    zadnji = zadnji->sljedeci;       // pronalaženje zadnjeg elementa u listi
  novi = new tstudent;                // alokacija novog elementa liste
  zadnji -> sljedeci = novi;         // povezivanje zadnje elementa u listi s novim elementom
  novi -> sljedeci = NULL;           // novi je sada zadnji element u listi
  cout << "Maticni broj: ";
  cin >> novi -> mat_br;
  cout << "Prezime i ime: ";
  cin >> novi -> prez_ime;
  cout << "Godina studija: ";
  cin >> novi -> god_stu;
};//dodaj_element
void ispisi_sve_elemente(tstudent *lista){ // ispis svih elemenata liste
  tstudent *tekuci = lista -> sljedeci;  // tekuci se usmjerava na poèetni element za ispis
  while (tekuci){
    cout << "Maticni broj: " << tekuci -> mat_br << endl;
    cout << "Prezime i ime: " << tekuci -> prez_ime << endl;
    cout << "Godina studija: " << tekuci -> god_stu << endl;
    cout << "---------------------" << endl;
    tekuci = tekuci -> sljedeci;   // kretanje kroz listu
  };
};//ispisi_sve_elemente
int main(){
  char dalje;
  tstudent *lista = new tstudent; // alokacija glave liste
  lista -> sljedeci = NULL;      // kraj liste
  do{
    dodaj_element(lista);
    ispisi_sve_elemente(lista);
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
}//main
