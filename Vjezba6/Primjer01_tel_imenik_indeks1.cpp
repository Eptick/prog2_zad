//Telefonski imenik: indeksna datoteka (1)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "biblioteka_tel_imenik.cc"
using namespace std;
struct timenik{
  int rb_zapisa;
  int tel_broj;
  char prez_ime[35];
  char adresa[50];
};//timenik
struct tindeks{
	int tel_broj;
	int adresa;
};//tindeks
fstream dat,ind;  // datoteèni objekti
void brisanje_sadrzaja(){
  dat.open ("imenik.dat",ios::out);
  dat.close();dat.clear();
  ind.open ("imenik.ind",ios::out);
  ind.close();ind.clear();
};//brisanje sadrzaja
void unos_zapisa_rucno(){
  timenik slog;
  tindeks indeks;
  int brojac_zapisa;
  //1.utvrditi koliko je zapisa veæ u datoteci
  dat.open ("imenik.dat",ios::in|ios::binary);
  if (!dat){
    brojac_zapisa=0;
    dat.open ("imenik.dat",ios::out|ios::binary);//kreiranje datoteke
  } else { // datoteka postoji
    dat.seekg (0, ios::end);
    brojac_zapisa=dat.tellg()/sizeof(timenik);
    dat.close();dat.clear();
    dat.open ("imenik.dat",ios::out|ios::in|ios::ate|ios::binary);
    ind.open ("imenik.ind",ios::out|ios::in|ios::ate|ios::binary);
  }
  //2.upis novog zapisa u datoteku
  brojac_zapisa++;
  cout << "Zapis br. " << brojac_zapisa << endl;
  slog.rb_zapisa=brojac_zapisa;
  cout << "Telefonski broj:";while (!unos_tel(slog.tel_broj));
  cout << "Prezime i ime:";unos(slog.prez_ime);
  cout << "Adresa:";unos(slog.adresa);
  dat.write ((char *)&slog,sizeof(timenik));
  indeks.tel_broj=slog.tel_broj;
  indeks.adresa=(int)dat.tellp()-sizeof(timenik);
  ind.write ((char *)&indeks,sizeof(tindeks));
  dat.close();dat.clear();
  ind.close();ind.clear();
};//unos_zapisa_rucno
void ispis_svih_zapisa(){
  timenik slog;
  tindeks indeks;
  dat.open ("imenik.dat",ios::in|ios::binary);
  ind.open ("imenik.ind",ios::in|ios::binary);
    while (1){
    ind.read ((char *)&indeks,sizeof(tindeks));
    if (ind.eof())break;
    dat.seekg(indeks.adresa);
    dat.read ((char *)&slog, sizeof(timenik));
    cout << "Zapis br. " << slog.rb_zapisa << endl;
    cout << "Telefonski broj:00"<<slog.tel_broj << endl;
    cout << "Prezime i ime:"<<slog.prez_ime<<endl;
    cout << "Adresa:"<<slog.adresa<<endl;
  }//while
  dat.close();dat.clear();
  ind.close();ind.clear();
};//ispis_svih_zapisa
void generiranje_zapisa(int broj_zapisa){
  timenik slog;
  tindeks indeks;
  int brojac_zapisa,i,j;
  //1.utvrditi koliko je zapisa veæ u datoteci
  dat.open ("imenik.dat",ios::in|ios::binary);
  if (!dat){
    brojac_zapisa=0;
    dat.open ("imenik.dat",ios::out|ios::binary);//kreiranje datoteke
  } else { // datoteka postoji
    dat.seekg (0, ios::end);
    brojac_zapisa=dat.tellg()/sizeof(timenik);
    dat.close();dat.clear();
    dat.open ("imenik.dat",ios::out|ios::in|ios::ate|ios::binary);
    ind.open ("imenik.ind",ios::out|ios::in|ios::ate|ios::binary);
  }
  //2.upis novih zapisa u datoteku
  for (i=1;i<=broj_zapisa;i++){
    brojac_zapisa++;
    slog.rb_zapisa=brojac_zapisa;
    slog.tel_broj=rand()%1000+rand()%1000*1000+1000000;
    // prezime i ime
    slog.prez_ime[0]=char(rand()%26+65);
    for (j=1;j<=6;j++)
      slog.prez_ime[j]=char(rand()%26+97);
    slog.prez_ime[7]=' ';
    slog.prez_ime[8]=char(rand()%26+65);
    for (j=9;j<=16;j++)
      slog.prez_ime[j]=char(rand()%26+97);
    slog.prez_ime[17]='\0';
    // adresa
    slog.adresa[0]=char(rand()%26+65);
    for (j=1;j<=10;j++)
      slog.adresa[j]=char(rand()%26+97);
    slog.adresa[11]=' ';
    slog.adresa[12]=char(rand()%10+48);
    slog.adresa[13]='\0';
    dat.write ((char *)&slog,sizeof(timenik));
    indeks.tel_broj=slog.tel_broj;
    indeks.adresa=(int)dat.tellp()-sizeof(timenik);
    ind.write ((char *)&indeks,sizeof(tindeks));
  }//for
  dat.close();dat.clear();
  ind.close();ind.clear();
};//generiranje_zapisa
void pretrazivanje_zapisa(int tel_broj){
  vrijeme_pocetak();
  timenik slog;
  tindeks indeks;
  bool nadjen=false;
  int brojac=0;
  dat.open ("imenik.dat",ios::in|ios::binary);
  ind.open ("imenik.ind",ios::in|ios::binary);
  while (1){
    ind.read ((char *)&indeks, sizeof(tindeks));
    brojac++;
    if (ind.eof())break;
    if (indeks.tel_broj==tel_broj){
      dat.seekg(indeks.adresa);
      dat.read ((char *)&slog, sizeof(timenik));
      nadjen=true;
      cout << "Zapis br. " << slog.rb_zapisa << endl;
      cout << "Telefonski broj:00"<<slog.tel_broj << endl;
      cout << "Prezime i ime:"<<slog.prez_ime<<endl;
      cout << "Adresa:"<<slog.adresa<<endl;
      break;
    }//if
  }//while
  dat.close();dat.clear();
  ind.close();ind.clear();
  vrijeme_kraj();
  if (!nadjen) cout << "Zapis nije pronadjen!" << endl;
  cout <<"Ukupan broj procitanih zapisa:"<<brojac<<endl;
  cout <<"Vrijeme pretrazivanja:"<<vrijeme_proteklo()<<endl;
};//pretrazivanje_zapisa
int main(){
  int izbor,tel_broj,broj_zapisa;
  do{cout << endl;
    cout << "0. brisanje sadrzaja obje datoteke" << endl;
    cout << "1. unos novog zapisa u obje datoteke (rucno)" << endl;
    cout << "2. ispis zapisa o svim pretplatnicima" << endl;
    cout << "3. generiranje zapisa o pretplatnicima" << endl;
    cout << "4. pretrazivanje zapisa po telefonskom broju" << endl;
    cout << "9. izlaz iz programa" << endl;
    cin >> izbor;
    switch (izbor){
      case 0:brisanje_sadrzaja();break;
      case 1:unos_zapisa_rucno();break;
      case 2:ispis_svih_zapisa();break;
      case 3:cout << "Koliko zapisa zelite generirati?";
             cin>>broj_zapisa;
             vrijeme_pocetak();
             generiranje_zapisa(broj_zapisa);
             vrijeme_kraj();
             cout <<"Vrijeme generiranja:"<<vrijeme_proteklo()<<endl;
             break;
      case 4: cout << "Telefonski broj:";while (!unos_tel(tel_broj));
              pretrazivanje_zapisa(tel_broj);break;
    }//switch
  } while (izbor!=9);
	return 1;
}
