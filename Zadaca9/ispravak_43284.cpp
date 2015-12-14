//Zadatak 9
//Prezime i ime:Redžiæ Leon
//Matièni broj:43284
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
  cout << "Redžiæ Leon 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upišite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomoæu ALT+PrtScrn) prozor
//s izvršenjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljedeæa pitanja:
//1. Napišite još jedan konstruktor klase lista1 (uz postojeæi). Novi konstruktor treba samo ispisati tekst "Novi konstruktor.".
//2. Koliko memorijskog prostora (u bajtima) zauzima pojedini objekt iz klase lista1, 
//   a koliko zauzima cijela vezana lista (ukljuèujuæi glavu; kad sadrži podatke za testiranje)?
//3. Definirajte statièko polje od 39 elemenata iz klase lista1.
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvršite traženu modifikaciju u programu:
//Klasi lista1 dodajte metodu M43284 (argument je vrijednost kljuèa) za pretraživanje vezane liste.
//Metoda treba ispisati vrijednosti atributa naðenog elementa vezane liste, odnosno, da element nije naðen.
//Na poziciji oznaèenoj s // *** u funkciji main() upitajte korisnika za vrijednost kljuèa i pozovite metodu za pretraživanje.
//Ažurirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja ukljuæuje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Domaæe zadaæe'
