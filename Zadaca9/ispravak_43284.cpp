//Zadatak 9
//Prezime i ime:Red�i� Leon
//Mati�ni broj:43284
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
class lista1{
  lista1 *sljedeci;
  public:
  int kljuc;
  int cetvrta;
  float sesta;
  int druga;
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
    cout << "kljuc: "; cin >> novi->kljuc;
    cout << "cetvrta: "; cin >> novi->cetvrta;
    cout << "sesta: "; cin >> novi->sesta;
    cout << "druga: "; cin >> novi->druga;
  };
  void f39(){
    lista1 *tekuci=this->sljedeci;
    while (tekuci){
      cout << "-----------------" << endl;
      cout << "kljuc: " << tekuci->kljuc << endl;
      cout << "cetvrta: " << tekuci->cetvrta << endl;
      cout << "sesta: " << tekuci->sesta << endl;
      cout << "druga: " << tekuci->druga << endl;
      tekuci=tekuci->sljedeci;
    }
  };
  void M43284(int kljuc){
  	 lista1 *tekuci=this->sljedeci;
     bool nadjen = false;
	 while (tekuci){
     	if(kljuc == tekuci->kljuc){
	  		nadjen = true;
	  		break;
	  	} 
     tekuci=tekuci->sljedeci;
     }
     if(nadjen){
     	cout << "-----------------" << endl;
      cout << "kljuc: " << tekuci->kljuc << endl;
      cout << "cetvrta: " << tekuci->cetvrta << endl;
      cout << "sesta: " << tekuci->sesta << endl;
      cout << "druga: " << tekuci->druga << endl;
	 } else cout << "Nije nadjen!"<<endl;
  };
};//lista1
void zadatak(){
  int i,b,broj;
  fstream dat;
  dat.open ("Podaci_za_testiranje.txt",ios::out);
  b = 39 % 2 + 3;
  dat << "kljuc\t";
  dat << "cetvrta\t";
  dat << "sesta\t";
  dat << "druga\t";
  dat << endl;
  for (i=1;i<=b;i++){
    broj = (39 + i + b) * 57 + 971;
    dat << broj++ % 100 << "\t";
    dat << broj++ % 100 << "\t";
    dat << broj++ % 10 << "." << (broj++ +43) % 10 << "\t";
    dat << broj++ % 100 << "\t";
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
  do{
    olista1->f43284();
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "-------------------------------------" << endl;
  olista1->f39();
  // ***
  int kljuc;
  cout << "Unesite vrijednost kljuca za pretragu: ";
  cin >> kljuc;
  olista1->M43284(kljuc);
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
//1. Napi�ite jo� jedan konstruktor klase lista1 (uz postoje�i). Novi konstruktor treba samo ispisati tekst "Novi konstruktor.".
//2. Koliko memorijskog prostora (u bajtima) zauzima pojedini objekt iz klase lista1, 
//   a koliko zauzima cijela vezana lista (uklju�uju�i glavu; kad sadr�i podatke za testiranje)?
//3. Definirajte stati�ko polje od 39 elemenata iz klase lista1.
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvr�ite tra�enu modifikaciju u programu:
//Klasi lista1 dodajte metodu M43284 (argument je vrijednost klju�a) za pretra�ivanje vezane liste.
//Metoda treba ispisati vrijednosti atributa na�enog elementa vezane liste, odnosno, da element nije na�en.
//Na poziciji ozna�enoj s // *** u funkciji main() upitajte korisnika za vrijednost klju�a i pozovite metodu za pretra�ivanje.
//A�urirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja uklju�uje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Doma�e zada�e'
