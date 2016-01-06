//Zadatak 10
//Prezime i ime:Redžiæ Leon
//Matièni broj:43284
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
class lista1_podaci{
public:
  int kljuc;
  float prva;
  char treca[37];
  float sesta;
  void unos(){
    cout << "kljuc: "; cin >> kljuc;
    cout << "prva: "; cin >> prva;
    cout << "treca: "; cin >> treca;
    cout << "sesta: "; cin >> sesta;
//*
  };
  void ispis(){
    cout << "kljuc: " << kljuc << endl;
    cout << "prva: " << prva << endl;
    cout << "treca: " << treca << endl;
    cout << "sesta: " << sesta << endl;
  };
};
class lista1{
  lista1 *sljedeci;
public:
  lista1_podaci sadrzaj;
  lista1(){
    sljedeci=NULL;
  };
  void f43284(){
    lista1 *zadnji,*novi;
    zadnji=this;
    while (zadnji->sljedeci)
      zadnji=zadnji->sljedeci;
    novi = new lista1;
    zadnji->sljedeci=novi;
    novi->sadrzaj.unos();
  };
  void f37(){
    lista1 *tekuci=this->sljedeci;
    while (tekuci){
      cout << "-----------------" << endl;
      tekuci->sadrzaj.ispis();
      tekuci=tekuci->sljedeci;
    }
  };
};//lista1
void zadatak(){
  int i,b,broj;
  fstream dat;
  dat.open ("Podaci_za_testiranje.txt",ios::out);
  b = 37 % 2 + 3;
  dat << "kljuc\t";
  dat << "prva\t";
  dat << "treca\t";
  dat << "sesta\t";
  dat << endl;
  for (i=1;i<=b;i++){
    broj = (37 + i + b) * 59 + 871;
    dat << broj++ % 100 << "\t";
    dat << broj++ % 10 << "." << (broj++ +43) % 10 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 10 << "." << (broj++ +43) % 10 << "\t";
    dat << endl;
  }//for
  dat.close();dat.clear();
  cout << "Otvorite najprije datoteku 'Podaci_za_testiranje.txt' !" << endl;
};
int main(){
  zadatak();
  lista1 *olista1;
  olista1=new lista1;
  char dalje;
  int b=0,i;
  do{
    olista1->f43284();
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "-------------------------------------" << endl;
  olista1->f37();
  cout << "----------------------------------------------" << endl;
  cout << "int* = " << sizeof(int*) << " B" << endl;
  cout << "Redžiæ Leon 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upišite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomoæu ALT+PrtScrn) prozor
//s izvršenjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljedeæa pitanja:
//1. Koliko memorijskog prostora zauzimaju objekti iz klase lista1, a koliko od toga otpada na sadržani objekt (sadrzaj)?
//2. Definirajte statièko polje od 37 elemenata iz klase lista1_podaci.
//3. Napišite programski kod koji bi, umetnut u metodu unos, na poziciju oznaèenu s //*
//   omoguæio upis unesenih podataka u datoteku 'podaci.dat'.
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvršite traženu modifikaciju u programu:
//Promijenite asocijaciju meðu klasama lista1 i class lista1_podaci tako da lista1 nasljeðuje klasu lista1_podaci
//(umjesto sadržavanja objekta iz klase lista1_podaci).
//Funkcionalnost primjera mora ostati ista.
//Ažurirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja ukljuæuje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Domaæe zadaæe'
