#include<iostream>
#include<fstream>
//Ako trazi rpreciznost dve znamenke
//#include <iomanip>
#include <cstring>
#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc"
using namespace std;
int zapisa;
struct zapis{
	int sifra;
	char naziv[25];
	float cijena;
	int kolicina;
	double t;
};
int status(fstream &dat,string naziv="roba_redzic_leon.dat"){
	dat.open(naziv.c_str(),ios::in);
	if(!dat.is_open()) return 0;
	dat.seekg(0,ios::end);
	if(!dat.tellg()) return 1;
	zapisa = dat.tellg() / sizeof(zapis);
	return 2;
}
void m1(){
	fstream dat, ind;
	tindeks indeks;zapis z;
	char izbor;int s = status(dat);
	dat.close();dat.clear();
	if(s == 0) cout << "0 Datoteka ne postoji"<<endl;
	if(s == 1) cout << "1 datoteka je prazna" << endl;
	if(s == 2) cout << "2 Datoteka sadrzi " << zapisa << " zapisa" << endl;
	if(s == 0) dat.open("roba_redzic_leon.dat",ios::out | ios::binary);
	if(s == 0) ind.open("roba_redzic_leon.ind",ios::out | ios::binary);
	izbor = 'f';
	if(s == 1 || s == 2)cout << "Zelite li postojece ili nove datoteke?(p/n): ";
	while(izbor != 'p' && izbor != 'n' && s != 0) if(s == 1 || s == 2) cin >> izbor;
	if(izbor == 'n') dat.open("roba_redzic_leon.dat",ios::out | ios::binary);
	if(izbor == 'n') ind.open("roba_redzic_leon.ind",ios::out | ios::binary);
	if(izbor == 'p') dat.open("roba_redzic_leon.dat",ios::out | ios::in | ios::binary | ios::ate);
	if(izbor == 'p') ind.open("roba_redzic_leon.ind",ios::out | ios::in | ios::binary | ios::ate);
	indeks.adresa = dat.tellg();
	vrijeme_pocetak();
	cout << "Sifra: ";cin >> z.sifra;indeks.kljuc = z.sifra;
	cout << "Naziv: ";unos(z.naziv);
	cout << "Cijena: ";cin >> z.cijena;
	cout << "Kolcina: ";cin >> z.kolicina;
	vrijeme_kraj();
	z.t = vrijeme_proteklo()/1000;
	dat.write((char*)&z,sizeof(z));
	ind.write((char*)&indeks,sizeof(indeks));
	dat.close();dat.clear();
	ind.close();ind.clear();
	preslozi_indeks((char*)"roba_redzic_leon.ind", indeks);
	ind.open("roba_redzic_leon.ind", ios::in | ios::binary);
	cout << "ISPIS" << endl;
	while(1){
		ind.read((char*)&indeks,sizeof(indeks));
		if(ind.eof()) break;
		cout << "Sifra: " << indeks.kljuc << endl
		<< "Adresa: " << indeks.adresa << endl;
	}
}
void m2(){
	fstream dat, ind; zapis z;
	tindeks indeks; bool n = false; int sifra,v;
	int s = status(dat); dat.close();dat.clear();
	if(s == 0) cout << "0 Datoteka ne postoji"<<endl;
	if(s == 0) return;
	if(s == 1) cout << "1 datoteka je prazna" << endl;
	if(s == 2) cout << "2 Datoteka sadrzi " << zapisa << " zapisa" << endl;
	cout << "Unos sifre: ";
	cin >> sifra;
	int x =pretrazivanje_zapisa((char*)"roba_redzic_leon.ind",sifra);
	ind.open("roba_redzic_leon.ind", ios::in | ios::binary);
	ind.seekg(0,ios::end);
	cout << "Velicina datoteke: " << ind.tellg() << " bajtova" << endl;
	ind.close(); ind.clear();
	if(x == -1) cout << "Ne postoji"<< endl;
	if(x == -1) return;
	dat.open("roba_redzic_leon.dat", ios::in | ios::binary);
	dat.seekg(x);
	dat.read((char*)&z,sizeof(z));
	dat.close(); dat.clear();
	if(x != -1) cout << "Adresa: " << x << endl
	<< "Sifra: " << sifra << endl
	<< "Naziv: " << z.naziv << endl
	<< "Cijena: " << z.cijena << endl
	<< "Kolcina: " << z.kolicina << endl
	<< "Vrijeme: " << z.t << endl;
}
void m3(){
	char naziv[40];
	fstream dat,ind;
	double vUnosa = 0;
	float v = 0;
	tindeks indeks;
	zapis z;
	cout << "Unesite naziv maticne datoteke: ";
	unos(naziv);
	int s = status(dat,naziv);
	dat.close(); dat.clear();
	if(s == 0) cout << "0 Datoteka ne postoji! " << endl;
	if(s == 0) return;
	if(s == 1) cout << "1 Datoteka je prazna! " << endl;
	if(s == 2) cout << "2 Datoteka sadrzi " << zapisa << " zapisa! " << endl;
	dat.open((char*)naziv,ios::in | ios::binary);
	ind.open("roba_redzic_leon.ind",ios::in | ios::binary);
	while(1){
		ind.read((char*)&indeks,sizeof(indeks));
		if(ind.eof()) break;
		dat.seekg(indeks.adresa);
		dat.read((char*)&z,sizeof(z));
	cout << "Sifra: " << z.sifra << endl
	<< "Naziv: " << z.naziv << endl
	<< "Cijena: " << z.cijena << endl
	<< "Kolcina: " << z.kolicina << endl
	<< "Vrijeme: " << z.t << endl;
	vUnosa += z.t;
	v += z.cijena * z.kolicina;
	}
	dat.close();dat.clear();
	ind.close();ind.clear();
	cout << "Vrijednost sve robe: " << v << endl
	<< "Ukupno vrijeme unosa: " << vUnosa << endl;
}
int main(){
	int izbor;
	//Ako trazi rpreciznost dve znamenke
	//cout << setprecision(2) << fixed;
	fstream mat;
	fstream ind;
	do{
		cout << "1. Rucni unos podataka o robi u indeksiranu datoteku" << endl
		<< "2. Pretrazivanje ineksirane datoteke prema sifri robe" << endl
		<< "3. Ispis sadrzaja maticne datoteke u redosljedu sifra robe" << endl;
		cout << "Izbor: ";
		cin >> izbor;	
		if(izbor == 1) m1();
		if(izbor == 2) m2();
		if(izbor == 3) m3();
	}while(izbor!=9);
	cout << "Kraj programa!" << endl;
	system("pause");
	return 0;
}
//OTPRILIKE PIŠEM NAPAMET TESTNE 
//Prvo testiranje
// 2 1 10 10 10 10 1 p 20 20 20 20 2 10 2 30 9
//Drugo testiranje
//Izbrisat datoteke!
// 2 1 10 10 10 10 1 p 20 20 20 20 2 10 2 30 3 roba_redzic_leon.dat 9
