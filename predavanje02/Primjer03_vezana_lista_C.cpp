/*vezana lista - strukturni pristup (C)*/
#include <stdio.h>
#include <stdlib.h>
struct tlista{
	tlista *sljedeci;
	int broj;
};
tlista *lista;
void unos(){
	tlista *zadnji,*novi;
	zadnji=lista;
	while (zadnji->sljedeci!=NULL)
		zadnji=zadnji->sljedeci;
	novi= (tlista*)malloc(sizeof(tlista));
	/*novi = new tlista;*/
	zadnji->sljedeci=novi;
	novi->sljedeci=NULL;
	printf ("Broj:");
  scanf ("%d",&novi->broj);
	/*cout << "Broj:";
  cin >> novi->broj;*/
};
void ispis(){
	tlista *tekuci;
	tekuci=lista->sljedeci;
	printf ("Lista:");
	while (tekuci!=NULL){
		printf ("%d%s",tekuci->broj,",");
		/*cout << tekuci->broj << ",";*/
		tekuci=tekuci->sljedeci;
	};
	printf ("NULL\n");
	/*cout << "NULL" << endl;*/
};
void dealokacija_liste(){
	tlista *tekuci,*iduci;
	tekuci=lista->sljedeci;
	while (tekuci!=NULL){
		iduci=tekuci->sljedeci;
		free (tekuci);
		/*delete tekuci;*/
		tekuci=iduci;
	};
	lista->sljedeci=NULL;
};
int broj_elemenata_liste(){
	tlista *tekuci;
	tekuci=lista->sljedeci;
	int broj_el=0;
	while (tekuci!=NULL){
		broj_el++;
		tekuci=tekuci->sljedeci;
	};
	return broj_el;
};
int main(){
	int izbor;
	lista = (tlista*)malloc(sizeof(tlista));
	/*lista = new tlista;*/
	lista->sljedeci=NULL;
	do{
		printf ("Hocete li:\n\n");
		printf ("1. Unos novog elementa liste\n");
		printf ("2. Ispis liste\n");
		printf ("3. Dealokacija liste\n");
		printf ("9. Izlaz\n");
		scanf ("%d",&izbor);
		/*cin >> izbor;*/
		switch (izbor){
			case 1:unos();break;
			case 2:ispis();break;
			case 3:dealokacija_liste();break;
		}
		printf ("%s%d%s","Broj elemenata liste:",broj_elemenata_liste(),"\n");
	}while (izbor!=9);
  return 1;
}
