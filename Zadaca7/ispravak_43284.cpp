//Zadatak 7
//Prezime i ime:Leon Redžiæ
//Matièni broj:43284
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct w43284{
  int kljuc;
  char treca[41];
  int cetvrta;
  char peta[41];
  int sedma;
};//struct
void zadatak(){
  int i,b,broj;
  fstream dat;
  dat.open ("Podaci_za_testiranje.txt",ios::out);
  b = 41 % 2 + 3;
  dat << "kljuc\t";
  dat << "treca\t";
  dat << "cetvrta\t";
  dat << "peta\t";
  dat << "sedma\t";
  dat << endl;
  for (i=1;i<=b;i++){
    broj = (41 + i + b) * 57 + 1279;
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 100 << "\t";
    dat << char(broj%26+65) << char((broj+7)%26+65) << char((broj+77)%26+65) << "\t";
    dat << broj++ % 100 << "\t";
    dat << endl;
  }//for
  dat.close();dat.clear();
  cout << "Otvorite najprije datoteku 'Podaci_za_testiranje.txt' !" << endl;
};
void brisanje_sadrzaja(){
  fstream dat;
  dat.open ("datoteka3.dat",ios::out);
  dat.close();dat.clear();
};//brisanje sadrzaja
void W_43284(int Fkljuc,char Ftreca[],int Fcetvrta,char Fpeta[],int Fsedma){
  fstream dat;
  w43284 z41;
  z41.kljuc = Fkljuc;
  strcpy(z41.treca,Ftreca);
  z41.cetvrta = Fcetvrta;
  strcpy(z41.peta,Fpeta);
  z41.sedma = Fsedma;
  dat.open ("datoteka3.dat",ios::out|ios::app|ios::binary);
  dat.write ((char *)&z41,sizeof(w43284));
  dat.close();dat.clear();
};
int X_43284(w43284 *v_41){
  fstream dat;
  w43284 z41;
  int brojac=41+99;
  dat.open ("datoteka3.dat",ios::in|ios::binary);
  // ***
  dat.seekg(0,ios::end);
  //cout << "Velicina datoteke u broju zapisa: " <<  dat.tellg()/sizeof(w43284) << endl;
  dat.seekg(0, ios::beg);
  while(1){
    dat.read((char *)&z41,sizeof(w43284));
    if (dat.eof())break;
    cout << "---------------------" << endl;
    memcpy(&v_41[--brojac],&z41,sizeof(w43284));
    cout << "kljuc: " << z41.kljuc << endl;
    cout << "treca: " << z41.treca << endl;
    cout << "cetvrta: " << z41.cetvrta << endl;
    cout << "peta: " << z41.peta << endl;
    cout << "sedma: " << z41.sedma << endl;
  }
  dat.close();dat.clear();
  return brojac;
};
void funkcija(w43284 *p,int b){
	cout << "==========FUNKCIJA==========" << endl;
	for(int i = 1; i <= b; i++){
		cout << "Kljuc: ";
		cout << p[41+99-i].kljuc << endl;
		cout << "Peta: ";
		cout << p[41+99-i].peta << endl;
		cout << "Treca: ";
		cout << p[41+99-i].treca << endl;
	}
	cout << "============KRAJ============" << endl;
}
int main(){
  zadatak();
  brisanje_sadrzaja();
  int kljuc;
  char treca[41];
  int cetvrta;
  char peta[41];
  int sedma;
  int b = 0;
  w43284 v_41[41+100];
  char dalje;
  do{
  	b++;
    cout << "kljuc: "; cin >> kljuc;
    cout << "treca: "; cin >> treca;
    cout << "cetvrta: "; cin >> cetvrta;
    cout << "peta: "; cin >> peta;
    cout << "sedma: "; cin >> sedma;
    W_43284(kljuc,treca,cetvrta,peta,sedma);
    cout << "Dalje (d/n)? ";
    cin >> dalje;
  } while (dalje=='d');
  cout << "--------" << endl;
  X_43284(v_41);
  funkcija(v_41, b);
  cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "int* = " << sizeof(int*) << " B" << endl;
  cout << "Leon Redžiæ 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upišite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomoæu ALT+PrtScrn) prozor
//s izvršenjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljedeæa pitanja:
//1. Koja je velièina datoteke "datoteka3.dat" (u bajtima, kad sadrži podatke iz testnog primjera), a koliko memorijskog prostora (u bajtima) zauzima polje v_41?
//2. Napišite kod koji bi na poziciji // *** ispisao velièinu datoteke u broju zapisa (tako da ostatak programa radi nepromijenjeno!).
//3. Koju vrijednost vraæa funkcija X_43284 za unesene testne podatke?
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvršite traženu modifikaciju u programu:
//Napišite funkciju koja ispiše sadržaj polja u redoslijedu unosa testnih podataka. Poziv je iz funkcije main.
//Argumenti funkcije su adresa polja i broj elemenata polja (prebrojati elemente kod unosa podataka). Za svaki element polja ispisuju se vrijednost kljuèa i vrijednosti svih znakovnih atributa.
//Ažurirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja ukljuèuje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Domaæe zadaæe'
