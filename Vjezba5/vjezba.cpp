#include <iostream>
#include <fstream>
#include "biblioteka_tel_imenik.cc"
using namespace std;

struct roba{
	int rb;
	int sifra;
	char naziv[30];
	int kolicina;
	int cijena;
	double vUnosa;
};

int status(fstream &dat){
	if( dat.is_open() ) if(dat.tellg() == 0) return 1; else{
		roba h;
		int brojac = 0;
		while(1){
			if(dat.eof()) break;
			dat.read((char*)&h, sizeof(h));
			if(h.sifra != 0) brojac++;	
		}
		cout << brojac;
		return 2;	
	}  else return 0;
}
int main(){
	int izbor;
	
	do{
		cout << "1. Kreiranje datoteka preznih zapisa." << endl;
		cout << "2. Unos podataka o robu u relativnu datoteku." << endl;
		cout << "3. Pretraživanje relativne datoteke." << endl;
		cout << "9. Izlaz iz programa." << endl;
		cin >> izbor;
		
		if(izbor == 1){
			fstream dat("roba_redzic_leon.dat", ios::in | ios::binary );
			int s;
			s = status(dat);
			if(s == 1) cout << "Datoteka je prazna. Status 1" << endl;
			if(s == 2) cout << " zapisa se nalazi u datoteci. Status: 2" << endl;	
			dat.close();
			dat.clear();
			if(s == 0) {
				cout << "Datoteka nije kreirana. Status 0" << endl;
				dat.open("roba_redzic_leon.dat", ios::out | ios::binary);
				roba h;
				int x;
				h.sifra = 0;
				h.cijena = 0;
				h.kolicina = 0;
				h.naziv[30] = {0};
				h.naziv[0]='\0';
				h.vUnosa = 0;				
				cout << "Unesite broj upisa u datoteku: ";
				cin >> x;
				for(int i = 0; i < x; i++){
					h.rb = 0;
					dat.write((char*)&h,sizeof(roba));	
				}
				dat.close();
				dat.clear();
			}
		}
			
	}while(izbor!= 9);
	return 1;
}
