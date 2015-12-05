//Zadatak 4
//Prezime i ime:Leon Redžiæ
//Matièni broj:43284
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct T41{
  char treca[41];
  int druga;
  int cetvrta;
  char peta[41];
};//struct
void zadatak(){
  int i,b,broj;
  fstream dat;
  dat.open ("Podaci_za_testiranje.txt",ios::out);
  b = 41 % 2 + 3;
  dat << "treca\t";
  dat << "druga\t";
  dat << "cetvrta\t";
  dat << "peta\t";
  dat << endl;
  for (i=1;i<=b;i++){
    broj = (41 + i + b) * 53 + 1027;
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 100 << "\t";
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << endl;
  }//for
  dat.close();dat.clear();
  cout << "Otvorite najprije datoteku 'Podaci_za_testiranje.txt' !" << endl;
};
void P432841(char Ftreca[],int Fdruga,int Fcetvrta,char Fpeta[]){
  ofstream dat43284;
  T41 z41;
  strcpy(z41.treca,Ftreca);
  z41.druga = Fdruga;
  z41.cetvrta = Fcetvrta;
  strcpy(z41.peta,Fpeta);
  dat43284.open("41341.dat",ios::out|ios::app|ios::binary);
  dat43284.write((char*)&z41,sizeof(z41));
  // ****
  dat43284.close();
};

int main(){
  char treca[41];
  int druga;
  int cetvrta;
  char peta[41];
  zadatak();
  char dalje;
  do{
    cout << "treca: "; cin >> treca;
    cout << "druga: "; cin >> druga;
    cout << "cetvrta: "; cin >> cetvrta;
    cout << "peta: "; cin >> peta;
    P432841(treca,druga,cetvrta,peta);
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "--------" << endl;
	int a=1;
  ifstream f43284;
  T41 z41;
  f43284.open("41341.dat",ios::in|ios::binary);
  while(1){
    f43284.read((char*)&z41,sizeof(z41));
    if (f43284.eof()) break;
    a = ++a;
    cout << "---------------------" << endl;
    cout << "treca: " << z41.treca << endl;
    cout << "druga: " << z41.druga << endl;
    cout << "cetvrta: " << z41.cetvrta << endl;
    cout << "peta: " << z41.peta << endl;
  }
  f43284.close();
  cout << "int* = " << sizeof(int*) << " B" << endl;
  cout << "==================================================" << endl;
  cout << "Leon Redžiæ 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upišite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomoæu ALT+PrtScrn) prozor
//s izvršenjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljedeæa pitanja:
//1. Koja je velièina datoteke "41341.dat" (u bajtima, kad sadrži podatke iz testnog primjera), a koliko memorijskog prostora (u bajtima) zauzima struktura T41?
//2. Koje vrijednosti ima datoteèni pokazivaè za upis na poziciji // **** prilikom upisa testnih podataka? (ispisati niz brojeva)
//3. Koje ste datoteène objekte koristili u primjeru, te kakvi su to objekti po tipu i dosegu?
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvršite traženu modifikaciju u programu:
//Umjesto korištenja funkcije P432841 podatke upisujte u datoteku unutar funkcije main (funkcionalnost treba ostati ista).
//Ažurirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja ukljuèuje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Domaæe zadaæe'
