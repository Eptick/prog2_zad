#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
//7,13,19
using namespace std;

struct roba{
	int sifra;
	char naziv[30];
	int cijena;
	int kolicina;
	double vUnosa;
};
void provjera(int &sifra){
	roba h;
	bool is = false;
	fstream dat("roba_Redzic_Leon.dat",ios::in | ios::binary);
	if(dat.is_open()){
			dat.seekg(0,ios::beg);
			while(1){	
				dat.read((char*)&h,sizeof(roba));
				if (dat.eof()) break;
				if(sifra == h.sifra) {
					is = true;
					break;	
				}
			}
		}
		if(is){
				cout << "Sifra vec postoji!" << endl;
				dat.seekg(0,ios::end);
				cout << "Datoteka Sadrzi " << dat.tellg()/sizeof(roba) << " zapisa."<< endl;
				cout << "Ponovni unos sifre: ";
				cin >> sifra;
				dat.close();	
				provjera(sifra);
			}	
	dat.close();	
}
void unos(){
	roba h;
	bool d = false;
	fstream dat("roba_Redzic_Leon.dat",ios::in | ios::binary);
	
	if(dat.is_open()){
		dat.seekg(0, ios::end);  
		if(dat.tellg() == 0) cout << "Datoteka je prazna!" << endl; else {
			dat.seekg(0,ios::beg);
			while(1){	
				dat.read((char*)&h,sizeof(roba));
				if (dat.eof()) break;
				cout << "=============================" << endl;
				cout << "Sifra: " << h.sifra << endl;
				cout << "Naziv: " << h.naziv << endl;
				cout << "Cijena: " << h.cijena << endl;
				cout << "Kolicina: " << h.kolicina << endl;
				cout << "Vrijeme unosa: " << h.vUnosa << endl;
			}
		}
		dat.close();
		vrijeme_pocetak();
		do{
		cout << "===============UNOS================" << endl;
		if(d) cout << "Cijena * kolicina mora bit izmedju 10 i 1000" << endl;	
		cout << "Sifra: ";
		cin >> h.sifra;
		provjera(h.sifra);
		cout << "Naziv: ";
		unos(h.naziv);
		cout << "Cijena: ";
		cin >> h.cijena;
		cout << "Kolicina: ";
		cin >> h.kolicina ;
		d = true;
		}while(h.cijena * h.kolicina < 10 || h.cijena * h.kolicina > 1000);
		vrijeme_kraj();
		h.vUnosa = vrijeme_proteklo()/1000;
		dat.open("roba_Redzic_Leon.dat", ios::out | ios::app | ios::binary);
		dat.write((char*)&h,sizeof(h));
	} else {
		cout << "Datoteka nije kreirana" << endl;
	}
	dat.close();
}
void ispis(){
	roba h;
	char naziv[50];
	double sUnosa = 0;
	int vRobe = 0;
	int brUnosa;
	cout << "Unesite naziv datoteke: ";
	unos(naziv);
	fstream dat(naziv,ios::in | ios::binary);
		if(dat.is_open()){
		dat.seekg(0, ios::end);  
		if(dat.tellg() == 0) cout << "Datoteka je prazna!" << endl;
		else {
			cout << "Datoteka sadrzi podatke!" << endl;
			dat.seekg(0,ios::end);
			brUnosa = dat.tellg()/sizeof(roba);
			cout << "Sadrzi " << dat.tellg()/sizeof(roba) << " zapisa."<< endl;
			dat.seekg(0,ios::beg);
			while(1){	
				dat.read((char*)&h,sizeof(roba));
				if (dat.eof()) break;
				cout << "=============================" << endl;
				cout << "Sifra: " << h.sifra << endl;
				cout << "Naziv: " << h.naziv << endl;
				cout << "Cijena: " << h.cijena << endl;
				cout << "Kolicina: " << h.kolicina << endl;
				cout << "Vrijednost: " << h.cijena * h.kolicina << endl;
				vRobe += h.cijena * h.kolicina;
				cout << "Vrijeme unosa: " << h.vUnosa << endl;
				sUnosa += h.vUnosa;
			}
			cout << "=======================" << endl;
			cout << "Ukupna vrijednost robe: " << vRobe << endl;
			cout << "Prosjecno vrijeme unosa: " << sUnosa/brUnosa << endl;
		}
	} else {
		cout << "Datoteka nije kreirana" << endl;
	}
	dat.close();
}

int main() {
	int izbor;
	char p;
	do{
		cout << "1. Unos podataka o robi u datoteku" << endl;
		cout << "2. Ispis sadrzaja datoteke u robu" << endl;
		cout << "3. Sortiranje dateteke uz pomoæ vezane liste" << endl;
		cin >> izbor;
		if(izbor == 0) {
					fstream file("roba_Redzic_Leon.dat",ios::in | ios::binary);
					if(file.is_open()){
						cout << "File postoji! Zelite li izbrisati i kreirati novu? (d/n): ";
						cin >> p;
						if(p == 'd'){
							file.close();
							file.open("roba_Redzic_Leon.dat", ios::out | ios::binary);
							file.close();	
						}
					} else {
						cout << "File ne postoji!" << endl;
						file.close();
						file.open("roba_Redzic_Leon.dat", ios::out | ios::binary);
						file.close();
					}
		}
		if(izbor == 1)	unos();
		if(izbor == 2) ispis();
	}while(izbor != 9);
	system("pause");
	return 0;
}
