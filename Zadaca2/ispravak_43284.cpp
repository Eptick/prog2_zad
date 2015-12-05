//Zadatak 2
//Prezime i ime:Redzic Leon
//Mati�ni broj:43284
#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
using namespace std;
struct t43284{
  char treca[41];
  int druga;
  int cetvrta;
  char peta[41];
  t43284 *sljedeci;
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
    broj = (41 + i + b) * 63 + 1127;
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 100 << "\t";
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << endl;
  }//for
  dat.close();dat.clear();
  cout << "Otvorite najprije datoteku 'Podaci_za_testiranje.txt' !" << endl;
};
int F_43284(t43284 *lista){
	int zbroj = 0;
  t43284 *novi,*zadnji;
  zadnji = lista;
  while (zadnji->sljedeci)
    zadnji = zadnji->sljedeci;
  novi = new t43284;
  zadnji -> sljedeci = novi;
  novi -> sljedeci = NULL;
  cout << "treca: "; cin >> novi -> treca;
  cout << "druga: "; cin >> novi -> druga;
  suma += druga;
  cout << "cetvrta: "; cin >> novi -> cetvrta;
  suma += cetvrta;
  cout << "peta: "; cin >> novi -> peta;
  return suma;
};
float F_41(t43284 *lista){
  float suma=0;
  t43284 *tekuci = lista -> sljedeci;
  while (tekuci){
        cout << "treca: " << tekuci -> treca << endl;
        cout << "druga: " << tekuci -> druga << endl;
        cout << "cetvrta: " << tekuci -> cetvrta << endl;
        cout << "peta: " << tekuci -> peta << endl;
    cout << "---------------------" << endl;
    tekuci = tekuci -> sljedeci;
    suma += 41 % 10;
  };
  return suma;
};
int main(){
  zadatak();
  char dalje;
  t43284 *lista = new t43284;
  lista -> sljedeci = NULL;
  do{
    cout << "F_43284 vraca: " << F_43284(lista) << endl;
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "--------" << endl;
  F_41(lista);
  cout << "----------------------------------------------" << endl;
  cout << "int = " << sizeof(int) << " b" << endl;
  cout << "Redzic Leon 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upi�ite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomo�u ALT+PrtScrn) prozor
//s izvr�enjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljede�a pitanja:
//1. Koliko memorijskog prostora u radnoj memoriji zauzimaju podaci tipa t43284, te navedite globalne varijable koje su tog tipa?
//2. Napi�ite deklaraciju stati�kog polja od 41 elemenata tipa t43284 .
//3. Koju vrijednost vra�a funkcija F_41 za unesene testne podatke?
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvr�ite tra�enu modifikaciju u programu:
//Funkciju F_43284 modificirajte tako da bude tipa int, vra�a zbroj svih cijelih brojeva koje korisnik unese
//ili nulu ako me�u unesenim podacima nema cijelih brojeva. Vrijednost funkcije F_43284 ispi�ite unutar funkcije main.
//A�urirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja uklju�uje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Doma�e zada�e'
