//Zadatak 6
//Prezime i ime:Leon Redžiæ
//Matièni broj:43284
#include <iostream>
#include <fstream>
#include <cstring>
#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc"
struct k36a{
  int kljuc;
  char peta[36];
  int sedma;
  char treca[36];
  float prva;
  float sesta;
};//struct
tindeks indeks;
void zadatak(){
  int i,b,broj;
  fstream dat;
  dat.open ("Podaci_za_testiranje.txt",ios::out);
  b = 36 % 2 + 3;
  dat << "kljuc\t";
  dat << "peta\t";
  dat << "sedma\t";
  dat << "treca\t";
  dat << "prva\t";
  dat << "sesta\t";
  dat << endl;
  for (i=1;i<=b;i++){
    broj = (36 + i + b) * 49 + 1287;
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 10 << "." << (broj++ +43) % 10 << "\t";
    dat << broj++ % 10 << "." << (broj++ +43) % 10 << "\t";
    dat << endl;
  }//for
  dat.close();dat.clear();
  cout << "Otvorite najprije datoteku 'Podaci_za_testiranje.txt' !" << endl;
};
int c_36(){
  fstream dat,ind;
  k36a z36;
  dat.open ("datoteka5.dat",ios::in|ios::binary);
  ind.open ("datoteka5.ind",ios::in|ios::binary);
  while(1){
    ind.read ((char *)&indeks,sizeof(tindeks));
    if (ind.eof())break;
    dat.seekg(indeks.adresa);
    dat.read((char *)&z36,sizeof(k36a));
    // ***
    cout << "Stanje datotecnog: " << dat.tellg() << endl;
    cout << "---------------------" << endl;
    cout << "kljuc: " << z36.kljuc << endl;
    cout << "peta: " << z36.peta << endl;
    cout << "sedma: " << z36.sedma << endl;
    cout << "treca: " << z36.treca << endl;
    cout << "prva: " << z36.prva << endl;
    cout << "sesta: " << z36.sesta << endl;
  }
  dat.close();dat.clear();ind.close();ind.clear();
  return indeks.adresa;
};
void c_43284(int Fkljuc,char Fpeta[],int Fsedma,char Ftreca[],float Fprva,float Fsesta){
  fstream dat,ind;
  k36a z36;
  z36.kljuc = Fkljuc;
  strcpy(z36.peta,Fpeta);
  z36.sedma = Fsedma;
  strcpy(z36.treca,Ftreca);
  z36.prva = Fprva;
  z36.sesta = Fsesta;
  dat.open ("datoteka5.dat",ios::out|ios::in|ios::binary);
  ind.open ("datoteka5.ind",ios::out|ios::in|ios::binary);
  dat.seekp (0, ios::end);
  ind.seekp (0, ios::end);
  dat.write ((char *)&z36,sizeof(k36a));
  indeks.kljuc=z36.kljuc;
  indeks.adresa=(int)dat.tellp()-sizeof(k36a);
  ind.write ((char *)&indeks,sizeof(tindeks));
  dat.close();dat.clear();ind.close();ind.clear();
  preslozi_indeks("datoteka5.ind",indeks);
};
void pretrazivanje(int kljuc){
	tindeks ps;
	k36a pom;
	bool f = false;
	fstream ind("datoteka5.ind", ios::in | ios::binary);
	ind.seekg(0, ios::beg);
	while(1){
		ind.read((char*)&ps,sizeof(ps));
		if(ind.eof()) break;
		if(ps.kljuc == kljuc) f=true;
		if(ps.kljuc == kljuc) break;
	}
	if(f) {
		fstream dat("datoteka5.dat", ios::in | ios::binary );
		dat.seekg(ps.adresa);
		dat.read((char*)&pom, sizeof(k36a));
		dat.close();
		dat.clear();
		cout << "Adresa: " << ps.adresa << endl;
		cout << "Kljuc: " << pom.kljuc << endl;
		cout << "Peta: " << pom.peta << endl;
		cout << "Sedma: " << pom.sedma << endl;
		cout << "Treca: " << pom.treca << endl;
		cout << "Prva: " << pom.prva << endl;	
		cout << "Sesta: " << pom.sesta << endl;	
	} else {
		cout << "Nije nadjen!" << endl;
	}
	
	ind.close();
	ind.clear();	
};
int main(){

  fstream dat,ind;
  dat.open ("datoteka5.dat",ios::out|ios::binary);//kreiranje datoteka
  ind.open ("datoteka5.ind",ios::out|ios::binary);
  dat.close();dat.clear();ind.close();ind.clear();
  int kljuc;
  char peta[36];
  int sedma;
  char treca[36];
  float prva;
  float sesta;
  zadatak();
  char dalje;
  do{
    cout << "kljuc: "; cin >> kljuc;
    cout << "peta: "; cin >> peta;
    cout << "sedma: "; cin >> sedma;
    cout << "treca: "; cin >> treca;
    cout << "prva: "; cin >> prva;
    cout << "sesta: "; cin >> sesta;
    c_43284(kljuc,peta,sedma,treca,prva,sesta);
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "--------" << endl;
  c_36();
  
  cout << "Unesite kljuc za pretrazivanje: ";
  cin >> kljuc;
  pretrazivanje(kljuc);
  
  cout << "=================================================" << endl;
  cout << "int* = " << sizeof(int*) << " B" << endl;
  cout << "Leon Redžiæ 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upišite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomoæu ALT+PrtScrn) prozor
//s izvršenjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljedeæa pitanja:
//1. Koja je velièina datoteke "datoteka5.ind" (u bajtima, kad sadrži podatke iz testnog primjera), a koliko memorijskog prostora (u bajtima) zauzima zapis indeksne datoteke?
//2. Koji je tip zapisa matiène datoteke, a koji indeksne datoteke?
//3. Ispišite niz stanja datoteènog pokazivaèa (u datoteci dat) za èitanje na poziciji oznaèenoj s // *** (pri unesenim testnim podacima).
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvršite traženu modifikaciju u programu:
//Napišite funkciju za pretraživanje datoteke po kljuèu (argument je vrijednost kljuèa) koja slijedno pretražuje indeksnu datoteku.
//Funkcija treba ispisati adresu zapisa u matiènoj datoteci i sve varijable iz zapisa matiène datoteke, odnosno poruku da zapis nije pronaðen. Poziv funkcije treba biti iz funkcije main.
//Ažurirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja ukljuèuje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Domaæe zadaæe'
