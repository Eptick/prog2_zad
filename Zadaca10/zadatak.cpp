//Zadatak 10
//Prezime i ime:Red�i� Leon
//Mati�ni broj:43284
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
  cout << "Red�i� Leon 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upi�ite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomo�u ALT+PrtScrn) prozor
//s izvr�enjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljede�a pitanja:
//1. Koliko memorijskog prostora zauzimaju objekti iz klase lista1, a koliko od toga otpada na sadr�ani objekt (sadrzaj)?
//2. Definirajte stati�ko polje od 37 elemenata iz klase lista1_podaci.
//3. Napi�ite programski kod koji bi, umetnut u metodu unos, na poziciju ozna�enu s //*
//   omogu�io upis unesenih podataka u datoteku 'podaci.dat'.
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvr�ite tra�enu modifikaciju u programu:
//Promijenite asocijaciju me�u klasama lista1 i class lista1_podaci tako da lista1 naslje�uje klasu lista1_podaci
//(umjesto sadr�avanja objekta iz klase lista1_podaci).
//Funkcionalnost primjera mora ostati ista.
//A�urirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja uklju�uje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Doma�e zada�e'
