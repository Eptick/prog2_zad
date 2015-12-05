//Zadatak 5
//Prezime i ime:Leon Redžiæ
//Matièni broj:43284
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
struct t41{
  int kljuc;
  char treca[41];
  int druga;
  int cetvrta;
  char peta[41];
};//struct
int prost_broj;
void zadatak(){
  int i,b,broj;
  fstream dat;
  dat.open ("Podaci_za_testiranje.txt",ios::out);
  b = 41 % 2 + 3;
  dat << "kljuc\t";
  dat << "treca\t";
  dat << "druga\t";
  dat << "cetvrta\t";
  dat << "peta\t";
  dat << endl;
  for (i=1;i<=b;i++){
    broj = (41 + i + b) * 57 + 1353;
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 100 << "\t";
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << endl;
  }//for
  dat.close();dat.clear();
  cout << "Otvorite najprije datoteku 'Podaci_za_testiranje.txt' !" << endl;
};
int prvi_manji_prost(int x){
  int i,j,prost;
  for (i=x;i>1;i--){
    prost = 1; // pretpostavka da je prost broj
    for (j=2;j<sqrt(i);j++){
      if (i%j==0){prost=0;break;}
    } // for j
    if (prost) return i;
  }//for i
  return 0;
};//prvi_manji_prost
void kreiranje_datoteke(int vd){
  fstream dat;
  t41 slog;
  int i;
  slog.kljuc=0;//'prazan' slog
  prost_broj=prvi_manji_prost(vd);
  cout << "Prosti broj=" << prost_broj << endl;
  dat.open ("datoteka3.dat",ios::out|ios::binary);
  for (i=0;i<vd;i++){
    dat.write ((char *)&slog,sizeof(t41));
  }//for
  dat.close();dat.clear();
};//kreiranje_datoteke
void F_41_1(int Fkljuc,char Ftreca[],int Fdruga,int Fcetvrta,char Fpeta[]){
  fstream dat;
  t41 z41;
  z41.kljuc = Fkljuc;
  strcpy(z41.treca,Ftreca);
  z41.druga = Fdruga;
  z41.cetvrta = Fcetvrta;
  strcpy(z41.peta,Fpeta);
  t41 slog2;
  int rbz; // redni broj zapisa
  rbz=z41.kljuc%prost_broj; //Ovo još treba provjeriti!
  dat.open ("datoteka3.dat",ios::in|ios::out|ios::binary);//U/I datoteka
  dat.seekg(rbz*sizeof(t41));
  do{ // traženje prve slobodne pozicije
    dat.read((char *)&slog2,sizeof(t41));
  }while (slog2.kljuc>0);
  rbz=(dat.tellg()/sizeof(t41))-1;
  dat.seekp(rbz*sizeof(t41));
  dat.write ((char *)&z41,sizeof(t41));
  dat.close();dat.clear();
};
char F_41_2(){
  fstream f43284;
  t41 z41;
  f43284.open("datoteka3.dat",ios::in|ios::binary);
  while(1){
    f43284.read((char*)&z41,sizeof(z41));
    if (f43284.eof()) break;
    if (z41.kljuc>0){
      cout << "---------------------" << endl;
      cout << "kljuc: " << z41.kljuc << endl;
      cout << "treca: " << z41.treca << endl;
      cout << "druga: " << z41.druga << endl;
      cout << "cetvrta: " << z41.cetvrta << endl;
      cout << "peta: " << z41.peta << endl;
    }
  }
  f43284.close();
  return (char)(z41.kljuc+65);
};
void pretrazivanje(int kljuc){
	t41 slog;
	bool nadjen = false;
  int rbz;
  rbz=kljuc%prost_broj; 
  fstream dat;
  dat.open ("datoteka3.dat",ios::in|ios::binary);
  dat.seekg(rbz*sizeof(t41));
  do{ 
    dat.read((char *)&slog,sizeof(t41));
    if(slog.kljuc == kljuc) nadjen = true;
  }while (slog.kljuc>0 && !nadjen);
  if(nadjen){
  	cout << "KLJUC: " << slog.kljuc << endl;
  	cout << "DRUGA: " << slog.druga << endl;
  	cout << "CETVRTA: " << slog.cetvrta << endl;
  } else {
  	cout << "Nije nadjen" << endl;
  }
  dat.close(); dat.clear();
};
int main(){
  int kljuc;
  char treca[41];
  int druga;
  int cetvrta;
  char peta[41];
  zadatak();
  char dalje;
  kreiranje_datoteke(100+41);
  do{
    cout << "kljuc: "; cin >> kljuc;
    cout << "treca: "; cin >> treca;
    cout << "druga: "; cin >> druga;
    cout << "cetvrta: "; cin >> cetvrta;
    cout << "peta: "; cin >> peta;
    F_41_1(kljuc,treca,druga,cetvrta,peta);
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "--------" << endl;
  F_41_2();
  
  
  cout << "================PRETRAZIVANJE================" << endl;
  cout << "Pretraživanje po kljucu: ";
  cin >> kljuc;
  pretrazivanje(kljuc);
  cout << "================KRAJ================" << endl;
  
  
  cout << "int* = " << sizeof(int*) << " B" << endl;
  cout << "==============================================" << endl;
  cout << "Leon Redžiæ 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upišite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomoæu ALT+PrtScrn) prozor
//s izvršenjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljedeæa pitanja:
//1. Koja je velièina datoteke "datoteka3.dat" (u bajtima, kad sadrži podatke iz testnog primjera), a koliko memorijskog prostora (u bajtima) zauzima varijabla z41?
//2. Za svako otvaranje datoteke ispišite: naziv fizièke datoteke, mod otvaranja i numerièka vrijednost moda otvaranja (u dekadskom brojevnom sustavu).
//3. Koju vrijednost vraæa funkcija F_41_2 za unesene testne podatke?
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvršite traženu modifikaciju u programu:
//Napišite funkciju za pretraživanje datoteke po kljuèu koja koristi metodu prostih brojeva (argument je vrijednost kljuèa).
//Funkcija treba ispisati sve varijable tipa int iz zapisa datoteke, odnosno poruku da zapis nije pronaðen. Poziv funkcije treba biti iz funkcije main.
//Ažurirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja ukljuèuje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Domaæe zadaæe'
