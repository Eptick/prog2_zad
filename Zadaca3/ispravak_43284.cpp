//Zadatak 3
//Prezime i ime:Redzic Leon
//Mati�ni broj:43284
#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
using namespace std;
struct telement{
  int kljuc;
  char treca[41];
  int druga;
  int cetvrta;
  char peta[41];
  telement *lijevo,*desno;
};//struct
void zadatak(long plus=1224){
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
    broj = (41 + i + b) * 51 + plus;
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
void S_43284_1(telement *stablo){
  telement *zadnji,*novi;
  int dalje=1;
  int kljuc;
  zadnji=stablo;
  cout << "Kljuc = ";
  cin >> kljuc;
  do{
    if (kljuc>zadnji->kljuc){
      if (zadnji->desno!=NULL){zadnji=zadnji->desno;} //prijelaz na desni pod�vor
    else{ // dodavanje desnog pod�vora
      novi=new telement;
      zadnji->desno=novi;
      cout << "Dodajem desni podcvor:" << endl;
      novi->kljuc=kljuc;
      cout << "treca: ";
      cin >> novi->treca;
      cout << "druga: ";
      cin >> novi->druga;
      cout << "cetvrta: ";
      cin >> novi->cetvrta;
      cout << "peta: ";
      cin >> novi->peta;
      novi->lijevo=NULL;
      novi->desno=NULL;
      dalje=0;
      }//if
    }//if
    else{//broj<=zadnji->kljuc
      if (zadnji->lijevo!=NULL){zadnji=zadnji->lijevo;} //prijelaz na lijevi pod�vor
    else{ // dodavanje lijevog pod�vora
      novi=new telement;
      zadnji->lijevo=novi;
      cout << "Dodajem lijevi podcvor:" << endl;
      novi->kljuc=kljuc;
      cout << "treca: ";
      cin >> novi->treca;
      cout << "druga: ";
      cin >> novi->druga;
      cout << "cetvrta: ";
      cin >> novi->cetvrta;
      cout << "peta: ";
      cin >> novi->peta;
      novi->lijevo=NULL;
      novi->desno=NULL;
      dalje=0;
      }//if
    }
  }while (dalje==1);
};
void S_43284_2(telement *stablo){
  static telement *korijen=stablo;
  if (stablo==NULL) return;
    S_43284_2 (stablo->lijevo);
  if (stablo!=korijen){
    cout << "----------------------------- " << endl;
    cout << "kljuc: " << stablo -> kljuc << endl;   
    cout << "treca: " << stablo -> treca << endl;
    cout << "druga: " << stablo -> druga << endl;
    cout << "cetvrta: " << stablo -> cetvrta << endl;
    cout << "peta: " << stablo -> peta << endl;
  }
    S_43284_2 (stablo->desno);
};
void *T_43284(telement *stablo, int broj=100){//vra�a adresu �vora ili NULL
  telement *tekuci=stablo;
  while (tekuci){
    if ((tekuci->kljuc==broj)&&(tekuci!=stablo))break;
    if (broj>tekuci->kljuc)
      tekuci=tekuci->desno;
    else
      tekuci=tekuci->lijevo;
  };//while
  if (tekuci == NULL){
  	cout << "Cvor nije pronadjen!" << endl;
  } else {
  	cout << "Kljuc: "<< tekuci ->kljuc << endl;
 	cout << "Treca: "<< tekuci ->treca << endl;
  	cout << "Druga: "<< tekuci ->druga << endl;
  	cout << "Cetvrta: "<< tekuci ->cetvrta << endl;
  	cout << "Peta: "<< tekuci ->peta << endl;
  }
};
int main(){
  cout << sizeof(telement);
  zadatak();
  char dalje;
  int izbor,kljuc;
  telement *stablo = new telement;
  stablo->lijevo=NULL;
  stablo->desno=NULL;
  do{
    cout << "1. dodavanje cvora u binarno stablo" << endl;
    cout << "2. ispis cvorova u uzlaznom redoslijedu" << endl;
    cout << "3. pretrazivanje binarnog stabla" << endl;
    cout << "9. izlaz iz programa" << endl;
    cin >> izbor;
    switch (izbor){
      case 1: S_43284_1(stablo);break;
      case 2: S_43284_2(stablo);
              cout << "kraj!" << endl;break;
      case 3: cout << "Kljuc = ";
              cin >> kljuc;
              T_43284(stablo,kljuc);
              break;
      case 9: break;
    }//switch
  } while(izbor!=9);
  cout << "int = " << sizeof(int) << " b" << endl;
  cout << "----------------------- -----------------------" << endl;
  cout << "Redzic Leon 43284 \nKraj programa." << endl;
  cin >> dalje;
}
//Zadaci:
//Prevedite i pokrenite primjer. Upi�ite podatke za testiranje (u datoteci 'Podaci_za_testiranje.txt').
//Kad dobijete poruku "Kraj programa" iskopirajte (pomo�u ALT+PrtScrn) prozor
//s izvr�enjem u Word-ov dokument.
//Odgovorite (u Wordovom dokumentu, iza slike) na sljede�a pitanja:
//1. Koliko memorijskog prostora u radnoj memoriji zauzima �vor binarnog stabla (iz ovog primjera) i kojeg je on tipa?
//2. Koliko �vorova binarnog stabla (ne ra�unaju�i korijen) nakon unosa testnih podataka ima pokaziva� lijevo postavljen na NULL?
//3. Navedite sve podrazumijevane argumente funkcije, te njihove tipove i dosege.
//Spremite Word-ov dokument u datoteku 'zadatak_43284.doc'
//------1 BOD-----
//Izvr�ite tra�enu modifikaciju u programu:
//Funkciju T_43284 modificirajte tako da bude bez tipa (void) i da prije povratka ispi�e vrijednosti atributa na�enog �vora
//ili poruku da �vor nije prona�en (odgovaraju�e ispise unutar funkcije main treba ukloniti).
//A�urirani program spremite u datoteku 'ispravak_43284.cpp'
//------1 BOD-----
//Formirajte .ZIP datoteku 'zadatak_43284.zip' koja uklju�uje:
//- zadatak.cpp (bez izmjena!)
//- zadatak_43284.doc (Word-ov dokument sa slikom i odgovorima)
//- ispravak_43284.cpp
//- Podaci_za_testiranje.txt
// .ZIP datoteku snimite (upload) na FOI E-Learning sustav pod 'Doma�e zada�e'
