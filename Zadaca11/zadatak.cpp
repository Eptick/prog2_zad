//Zadatak 11
//Prezime i ime:Leon Redžiæ
//Matièni broj:43284
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
int suma=0;
class lista1_osnovna{
protected:
  lista1_osnovna *sljedeci;
public:
  int kljuc;
  float prva;
  char treca[37];
  float sesta;
  lista1_osnovna(){
    sljedeci=NULL;
  };
  virtual void unos(){};
  virtual void ispis(){};
  virtual void f43284();
  virtual int f37();
};
lista1_osnovna *olista1,*novi;
void lista1_osnovna::f43284(){
    lista1_osnovna *zadnji;
    zadnji=this;
    while (zadnji->sljedeci)
      zadnji=zadnji->sljedeci;
    zadnji->sljedeci=novi;
    novi->unos();
};
int lista1_osnovna::f37(){
    lista1_osnovna *tekuci=this->sljedeci;
    while (tekuci){
      cout << "-----------------" << endl;
      tekuci->ispis();
      tekuci=tekuci->sljedeci;
      suma += 4;
    }
    return suma;
};
class lista1:public lista1_osnovna{
public:
  lista1(){
    sljedeci=NULL;
  };
  void unos(){
    cout << "kljuc: "; cin >> kljuc;
    cout << "prva: "; cin >> prva;
    cout << "treca: "; cin >> treca;
    cout << "sesta: "; cin >> sesta;
  }
  void ispis(){
    cout << "kljuc: " << kljuc << endl;
    cout << "prva: " << prva << endl;
    cout << "treca: " << treca << endl;
    cout << "sesta: " << sesta << endl;
  }
  void f43284(){
    lista1 *zadnji;
    zadnji=this;
    while (zadnji->sljedeci)
      zadnji=(lista1*)zadnji->sljedeci;
    zadnji->sljedeci=novi;
    novi->unos();
  };
  int vlista1;
  int f37(){
    lista1 *tekuci=(lista1*)this->sljedeci;
    while (tekuci){
      cout << "-----------------" << endl;
      tekuci->ispis();
      tekuci=(lista1*)tekuci->sljedeci;
      suma += 3;
    }
    return suma;
 };
};//lista1
class lista12:public lista1_osnovna{
public:
  lista12(){
    sljedeci=NULL;
  };
  char c37[37];
  void unos(){
    cout << "kljuc: "; cin >> kljuc;
    cout << "prva: "; cin >> prva;
    cout << "treca: "; cin >> treca;
    cout << "sesta: "; cin >> sesta;
  }
  void ispis(){
    cout << "kljuc: " << kljuc << endl;
    cout << "prva: " << prva << endl;
    cout << "treca: " << treca << endl;
    cout << "sesta: " << sesta << endl;
  }
  void f43284(){
    lista12 *zadnji;
    zadnji=this;
    while (zadnji->sljedeci)
      zadnji=(lista12*)zadnji->sljedeci;
    zadnji->sljedeci=novi;
    novi->unos();
  };
  int f37(){
    lista12 *tekuci=(lista12*)this->sljedeci;
    while (tekuci){
      cout << "-----------------" << endl;
      tekuci->ispis();
      tekuci=(lista12*)tekuci->sljedeci;
      suma += 2;
    }
    return suma;
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
    broj = (37 + i + b) * 57 + 873;
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
  olista1=new lista1_osnovna;
  cout << "Size of lista1_osnovna: " << sizeof(lista1_osnovna) <<endl;
  char dalje;
  int b=0;
  do{
    b++;
    if (b%2==1)
      novi=new lista1;
    else
      novi=new lista12;
    olista1->f43284();
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "-------------------------------------" << endl;
  olista1->f37();
  cout << "----------------------------------------------" << endl;
  cout << "int* = " << sizeof(int*) << " b" << endl;
  cout << "Leon Redžiæ 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upišite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomoæu ALT+PrtScrn) prozor
//s izvršenjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljedeæa pitanja:
//1. Koliko memorijskog prostora zauzima svaki pojedini element u vezanoj listi (ukljuèujuæi glavu; kad su upisani testni podaci)? Ispišite niz brojeva.
//2. Definirajte dva statièka polja tako da zauzmu jednaki memorijski prostor. Prvo polje sadrži elemente iz klase lista1, a drugo iz klase lista12.
//3. Kolika je vrijednost varijable suma pri izlasku iz programa (nakon unosa testnih podataka)?
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvršite traženu modifikaciju u programu:
//Dodajte u funkciju main kod koji ispisuje vrijednosti atributa kljuc u svim elementima liste (bez glave), te (na kraju) njihovu aritmetièku sredinu (na toèno jednu decimalu preciznosti!).
//Ažurirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja ukljuæuje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Domaæe zadaæe'
