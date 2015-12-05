//Zadatak 8
//Prezime i ime:Red�i� Leon
//Mati�ni broj:43284
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
class c43284{
  protected:
  int z_43284;
  public:
  char peta[38];
  char treca[38];
  int druga;
  int cetvrta;
  float sesta;
  void W_231(){
    cout << "peta: "; cin >> peta;
    cout << "treca: "; cin >> treca;
    cout << "druga: "; cin >> druga;
    cout << "cetvrta: "; cin >> cetvrta;
    cout << "sesta: "; cin >> sesta;
  };
  void T_43284(){
    cout << "-----------------" << endl;
    cout << "peta: " << peta << endl;
    cout << "treca: " << treca << endl;
    cout << "druga: " << druga << endl;
    cout << "cetvrta: " << cetvrta << endl;
    cout << "sesta: " << sesta << endl;
  };
};//class
void zadatak(){
  int i,b,broj;
  fstream dat;
  dat.open ("Podaci_za_testiranje.txt",ios::out);
  b = 38 % 2 + 3;
  dat << "peta\t";
  dat << "treca\t";
  dat << "druga\t";
  dat << "cetvrta\t";
  dat << "sesta\t";
  dat << endl;
  for (i=1;i<=b;i++){
    broj = (38 + i + b) * 53 + 979;
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 100 << "\t";
    dat << broj++ % 100 << "\t";
    dat << broj++ % 10 << "." << (broj++ +43) % 10 << "\t";
    dat << endl;
  }//for
  dat.close();dat.clear();
  cout << "Otvorite najprije datoteku 'Podaci_za_testiranje.txt' !" << endl;
};
int main(){
  zadatak();
  c43284 polje[38+50];
  char dalje;
  int a=0,i;
  do{
    polje[a++].W_231();
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "-------------------------------------" << endl;
  for (i=0;i<a;i++)
    polje[i].T_43284();// ***
  cout << "===============================================" << endl;
  cout << "int* = " << sizeof(int*) << " B" << endl;
  cout << "Red�i� Leon 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upi�ite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomo�u ALT+PrtScrn) prozor
//s izvr�enjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljede�a pitanja:
//1. Koji su atributi, a koje metode klase c43284? Koja su prava pristupa �lanovima klase c43284?
//2. Koliko memorijskog prostora (u bajtima) zauzima pojedini objekt iz klase c43284, a koliko cijelo polje (iz primjera)?
//3. Napi�ite programski kod koji zamjenjuje redak ozna�en s // *** tako da se (s cout; umjesto poziva metode) ispisuje vrijednost atributa sesta (ako takav postoji).
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvr�ite tra�enu modifikaciju u programu:
//Metodu T_43284 zamijenite metodom R_38() (bez tipa) koja ispisuje vrijednosti svih znakovnih atributa (ili poruku da takvih nema).
//A�urirajte funciju main, tako da se poziva metoda R_38().
//A�urirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja uklju�uje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Doma�e zada�e'
