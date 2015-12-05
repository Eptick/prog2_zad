#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;
struct telement {
	int sifra;
	char prez_ime[35];
	char naslov[40];
	double vUnosa;
	telement *sljedeci;
};
void F_1(telement *glava){
	telement *novi, *zadnji;
	zadnji = glava;
	int sifra;
	bool nidanine = false;
	while (zadnji->sljedeci)
		zadnji = zadnji->sljedeci;
	novi = new telement; 
	vrijeme_pocetak();
	do{
		cout << "Unesite sifru: ";
		cin >> sifra;
		telement *pregled;
		pregled = glava;
		while (pregled->sljedeci){
			pregled = pregled->sljedeci;
			if(pregled->sifra == sifra){
				nidanine = true;
				cout << "Sifra vec postoji!" << endl;
				break;
			} else {
				nidanine = false;
			}
		}
	}while((novi->sifra < 1000 || novi->sifra >= 2000 ) && nidanine);
	zadnji->sljedeci = novi;
	novi->sljedeci = NULL;
	novi->sifra = sifra;
	cout << "Unesite prezime i ime: ";
	unos(novi->prez_ime);
	cout << "Unesite naslov rada: ";
	unos(novi->naslov);
	vrijeme_kraj();
	cout << "Vrijeme potrebno za unos jest: " << vrijeme_proteklo()/1000 << " sekundi." << endl;
	novi->vUnosa = vrijeme_proteklo()/1000;
	cout << "Kraj unosa" << endl;
}
void F_2(telement *lista){
	telement *zadnji;
	zadnji = lista;
	int br_elemenata;
	while (zadnji->sljedeci){
		zadnji = zadnji->sljedeci;
		br_elemenata++;
	}
	cout << "Lista sadrži " << br_elemenata << " elemenata" << endl;
	double *vremena = new double[br_elemenata];
	double suma = 0;
	zadnji = lista;
	while (zadnji->sljedeci){
		zadnji = zadnji->sljedeci;
		cout << "Sifra: " << zadnji->sifra << endl;
		cout << "Prezime i ime: " << zadnji->prez_ime<<endl;
		cout << "Naslov rada: " << zadnji->naslov<<endl;
		cout << "Vrijeme unosa: " << zadnji->vUnosa<<endl;
		suma+= zadnji->vUnosa;
	}
	cout << "Prosjecno vrijeme unosa jest: " << suma/br_elemenata << "." << endl;
}
int main() {
	int izbor;
	telement *lista = NULL;
	do{
		cout << "0. Alokacija glave vezane liste" << endl;
		cout << "1. Unos novog elementa vetane liste " << endl;
		cout << "2. Ispis sadrzaja vezane liste" << endl;
		cout << "9. Izlaz iz programa" << endl;
		cin >> izbor;
		switch(izbor){
			case 0:
				if(lista == NULL){
					cout << "Alociram glavu vezane liste." << endl;
					lista = new telement;
					lista ->sljedeci = NULL;
				} else {
					cout << "Lista je vec alocirana!" << endl;
				}
				break;
			case 1:
				if(lista == NULL){
					cout << "Molimo alocirajte glavu vezane liste (Mogucnost 0)" << endl;
				} else {
					F_1(lista);
				}
				break;
			case 2:
				if(lista == NULL){
					cout << "Molimo alocirajte glavu vezane liste (Mogucnost 0)" << endl;
				} else {
					F_2(lista);
				}
				break;
			case 9:
				cout << "Izlazim iz programa" << endl;
				break;	
		}	
	}while(izbor!=9);
	system("pause");
	return 0;
}
