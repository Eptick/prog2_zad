#include <iostream>
#include "biblioteka_vrijeme.cc"
#include <string.h>
using namespace std;
struct telement{
	int rbRobe;
	char nazivRobe[50];
	float cijenaKomada;
	int kolicina;
	double vUnosa;
	telement *pret_ljevo;
	telement *sljed_desno;
};
void dodavanje_kraj(telement *lista){
	telement *zadnji;
	telement *novi;
	char izbor;
	bool k;
	zadnji = lista;
	int brojac = 0;
	while(zadnji->sljed_desno != NULL){
		zadnji = zadnji->sljed_desno;
		brojac++;
	}
	cout << "Lista sadrzi " << brojac << " elemenata." << endl;
	do{	
		novi = new telement;
		novi->sljed_desno = NULL;
		novi->pret_ljevo = zadnji;
		vrijeme_pocetak();
		k = false;
		do{
			if(k == true) {
				cout << "Umnozak cijene i kolicina mora biti manji od 1000" << endl;	
			}
			cout << "Unesite redni broj robe: ";
			cin >> novi->rbRobe;
			cout << "Unesite naziv robe: ";
			unos(novi->nazivRobe);
			cout << "Unesite cijenu komada: ";
			cin >> novi->cijenaKomada;
			cout << "Unesite kolicinu: ";
			cin >> novi->kolicina;
			k = true;
		}while((novi->kolicina * novi->cijenaKomada) > 1000);
		vrijeme_kraj();
		novi->vUnosa = vrijeme_proteklo()/1000;
		cout << "vrijeme unosa: " << vrijeme_proteklo()/1000 << endl;
		zadnji->sljed_desno = novi;
		zadnji = novi;
		cout << "Jos unosa? (d/n)";
		cin >> izbor;
	} while(izbor != 'n');
	zadnji = lista;
	brojac = 0;
	while(zadnji->sljed_desno != NULL){
		zadnji = zadnji->sljed_desno;
		brojac++;
	}
	cout << "Lista sadrzi " << brojac << " elemenata." << endl;
}
void dodavanje_pocetak(telement *lista){
	telement *prvi;
	telement *novi;
	char izbor;
	bool k;
	do{
		prvi = lista->sljed_desno;
		novi = new telement;
		novi->pret_ljevo = lista;	
		lista->sljed_desno = novi;
		if(prvi != NULL){
		novi->sljed_desno = prvi;
		prvi->pret_ljevo = novi;
		} else {
			novi->sljed_desno = NULL;
		}
		vrijeme_pocetak();
		k = false;
		do{
			if(k == true) {
				cout << "Umnozak cijene i kolicina mora biti manji od 1000" << endl;	
			}
			cout << "Unesite redni broj robe: ";
			cin >> novi->rbRobe;
			cout << "Unesite naziv robe: ";
			unos(novi->nazivRobe);
			cout << "Unesite cijenu komada: ";
			cin >> novi->cijenaKomada;
			cout << "Unesite kolicinu: ";
			cin >> novi->kolicina;
			k = true;
		}while((novi->kolicina * novi->cijenaKomada) > 1000);
		vrijeme_kraj();
		novi->vUnosa = vrijeme_proteklo()/1000;
		prvi = novi;
		cout << "vrijeme unosa: " << vrijeme_proteklo()/1000 << endl;
		cout << "Još unosa? (d/n)";
		cin >> izbor;
	} while(izbor != 'n');
	telement *zadnji = lista;
	cout << "===============LISTA================"<<endl;
	while(zadnji->sljed_desno != NULL){
		zadnji = zadnji->sljed_desno;
	}
	while(zadnji != lista){
		cout << "Redni broj robe: ";
		cout << zadnji->rbRobe << endl;
		cout << "Naziv robe: ";
		cout << zadnji->nazivRobe << endl;
		cout << "Vrijednost: ";
		cout << zadnji->cijenaKomada * zadnji->kolicina << endl;
		cout << "Vrijeme unosa: ";
		cout << zadnji->vUnosa << endl;
		zadnji = zadnji->pret_ljevo; 
	}
	cout << "===========KRAJ LISTE================"<<endl;
}
void dodaj_element_u_stablo(telement *stablo, telement *unos){
  	telement *zadnji;
	telement *novi;
  	int dalje=1;
	zadnji=stablo;
	do{
		if (unos->rbRobe>zadnji->rbRobe){
			
			if (zadnji->sljed_desno!=NULL){
				zadnji=zadnji->sljed_desno;
			} else{
				
				novi=new telement;
				zadnji->sljed_desno=novi;
				novi->rbRobe=unos->rbRobe;
				novi->cijenaKomada = unos->cijenaKomada;
				novi->kolicina = unos->kolicina;
				strcpy(novi->nazivRobe,unos->nazivRobe);
				novi->vUnosa = unos->vUnosa;
				novi->pret_ljevo=NULL;
				novi->sljed_desno=NULL;
				dalje=0;
			}
		} else {
	
			if (zadnji->pret_ljevo!=NULL){
				zadnji=zadnji->pret_ljevo;
			} else { 
			
				novi = new telement;
				zadnji->pret_ljevo = novi;
				novi->rbRobe=unos->rbRobe;
				novi->cijenaKomada = unos->cijenaKomada;
				novi->kolicina = unos->kolicina;
				strcpy(novi->nazivRobe,unos->nazivRobe);
				novi->vUnosa = unos->vUnosa;
				novi->pret_ljevo = NULL;
				novi->sljed_desno = NULL;
				dalje=0;
			}
		}
	}while (dalje==1);
};
void dealociraj_stablo(telement *stablo){
  static telement *korijen=stablo;
	if (stablo==NULL) return;
		dealociraj_stablo (stablo->pret_ljevo);
	if (stablo!=korijen) delete stablo;
		dealociraj_stablo (stablo->sljed_desno);
};
void alociraj_stablo(telement *stablo, telement *lista){
	telement *zadnji;
	zadnji = lista;
	while(zadnji->sljed_desno != NULL){
		zadnji = zadnji->sljed_desno;
		dodaj_element_u_stablo(stablo, zadnji);
	}
}
void sort_silazno(telement *stablo){
    static telement *korijen=stablo;
	if (stablo==NULL) return;
		sort_silazno(stablo->sljed_desno);
	if (stablo!=korijen) {
		cout << "Redni broj robe: ";
		cout << stablo->rbRobe << endl;
		cout << "Naziv robe: ";
		cout << stablo->nazivRobe << endl;
		cout << "Cijena komada: ";
		cout << stablo->cijenaKomada << endl;
		cout << "Kolicina: ";
		cout << stablo->kolicina << 
		cout << "Vrijeme unosa: ";
		cout << stablo->vUnosa << endl;
	}
	sort_silazno(stablo->pret_ljevo);
};
void sort_uzlazno(telement *stablo){
  static telement *korijen=stablo;
	if (stablo==NULL) return;
		sort_uzlazno (stablo->pret_ljevo);
	if (stablo!=korijen) {
		cout << "Redni broj robe: ";
		cout << stablo->rbRobe << endl;
		cout << "Naziv robe: ";
		cout << stablo->nazivRobe << endl;
		cout << "Cijena komada: ";
		cout << stablo->cijenaKomada << endl;
		cout << "Kolicina: ";
		cout << stablo->kolicina << 
		cout << "Vrijeme unosa: ";
		cout << stablo->vUnosa << endl;
	}
	sort_uzlazno (stablo->sljed_desno);
};
int main(){
	int unos;
	int sort;
	telement *lista = NULL;
	telement *stablo = NULL;
	do{
		cout << "0. Alokacija glave vezane liste i korijena binarnog stabla. " << endl;
		cout << "1. Dodavanje elementa na kraj dvostruko vezane liste " << endl;
		cout << "2.	Dodavanje elementa na poèetak dvostruko vezane liste " << endl;
		cout << "3. Binarno stablo (kreiranje i ispis)" << endl;
		cout << "9. Izlaz iz programa" << endl;
		cin >> unos;
		switch(unos){
			case 0:
				if(lista != NULL){
					cout << "Vec je alocirano!" << endl;
				} else {
					lista = new telement;
					stablo = new telement;
					lista->pret_ljevo = NULL;
					lista->sljed_desno = NULL;
					stablo->pret_ljevo = NULL;
					stablo->sljed_desno = NULL;
					cout << "Alocirano!" << endl;
				}
				break;
			case 1:
				if(lista == NULL){
					cout << "Lista i stablo nisu alocirani (mogucnost 0)" << endl;	
				} else {
					dodavanje_kraj(lista);
				}
				break;
			case 2:
				if(lista == NULL){
					cout << "Lista i stablo nisu alocirani (mogucnost 0)" << endl;	
				} else {
					dodavanje_pocetak(lista);
				}
				break;
			case 3:
				if(stablo != NULL ){
					cout << "Stablo je vec alocirano" << endl;	
					dealociraj_stablo(stablo);
					stablo = new telement;
					stablo->pret_ljevo= NULL;
					stablo->sljed_desno = NULL;
					alociraj_stablo(stablo, lista);
					cout << "Novo stablo je napravljeno" << endl;
					do{
					cout << "Zelite li sortirano ulazno(1) ili silazno(2): ";
					cin >> sort;	
					}while(sort != 1 && sort != 2);
					if(sort == 1){
						sort_uzlazno(stablo);
					} else{
						sort_silazno(stablo);
					}
				} else {
					cout << "Stablo nije alocirano (mogucnost 0)" << endl;
				}
				break;
		}
	}while(unos!=9);
	cout << "Kraj programa!" << endl;
	system("pause");
	return 0;
}
