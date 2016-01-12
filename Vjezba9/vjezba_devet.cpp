#include <iostream>
#include <cstdlib>

using namespace std;

float uk_iznos, brojac;

class cstavka {
	  public:
	  		 int sifra;
	  		 char naziv[50];
	  		 float vrijednost;
	  		 cstavka *sljedeci;
      public:
	  		 void unos () { 		//unos nove stavke u listu
                  cstavka *pom;
                  pom = this;
                  while (pom->sljedeci!=NULL)
                        pom=pom->sljedeci;
                  cstavka *novi = new cstavka;;
                  pom->sljedeci=novi;
                  cout<<"\nUnesite stavku: "<<endl;
                  cout<<"Sifra: ";
                  cin>>novi->sifra;
                  cout<<"Naziv: ";
                  cin.ignore();
                  cin.getline (novi->naziv, 50);
                  cout<<"Vrijednost: ";
                  cin>>novi->vrijednost;
   			 }
   			 
   			 void ispis () {		//ispis svih stavki iz liste
   			      cout<<"\nIspis svih stavki racuna: "<<endl;
			      for (cstavka *setac=this->sljedeci;setac;setac=setac->sljedeci)
                      cout<<"\nSifra: "<<setac->sifra<<"\nNaziv: "<<setac->naziv<<"\nVrijednost: "<<setac->vrijednost<<endl;
			 }
			 
			 void iznos () {		//ukupan iznos svih stavki jednog raèuna
 	  		      for (cstavka *setac=this->sljedeci;setac;setac=setac->sljedeci)
                     uk_iznos+=setac->vrijednost;     
			 }
			 
			 void dealokacija () { //dealokacija liste (glava ostaje)
			      if(this->sljedeci==NULL) return; //ako je lista prazna vracamo se odmah (ako dvaput dealociramo zaredom bez ovoga æe se krešat)
			      cstavka *tekuci, *pom;
			      tekuci=this->sljedeci;
			      pom=this->sljedeci->sljedeci;
                  while (tekuci) {
                        delete tekuci;         //dealociramo tekuæi
                        tekuci=pom;            //u tekuæi spremamo sljedeæi
                        if(pom) pom=pom->sljedeci; //kad tekuæi bude zadnji, pom æe biti NULL, pa je potreban ovaj uvjet jer se program crasha kad pokuša napravit NULL=NULL->sljedeci
                  }
                  this->sljedeci=NULL; //nakon što je lista (ukljuèujuæi i prvi element) izbrisana, moramo glavu usmjerit na NULL
			 }
			 
             cstavka () { //konstruktor koji ce prilikom alokacije liste postaviti vrijednost pokazivaca sljedeci i ispisati sljedeci tekst: alociram stavku
                     sljedeci=NULL;
                     cout<<"\nAlociram stavku"<<endl;
             }
             
             ~cstavka() {
                        cout<<"Dealociram  "<<this->naziv<<endl;
             }
             
			 int status () { //mozda cemo morat ic po polju i brojat koliko ta lista ima stavki..
			 	 if (this!=NULL && this->sljedeci==NULL) cout<<"\n1 - lista je prazna"<<endl;
			 	 if (this!=NULL && this->sljedeci==NULL) return 1;
			 	 if (this!=NULL) cout<<"2 - lista sadrzi "<<brojac<<" stavki"<<endl;
                 if (this!=NULL) return 2;
                 //ELSE
                 cout<<"0 - glava liste nije alocirana"<<endl;
                 return 0;
			 } 
};

cstavka *lista = NULL;
cstavka *polje = NULL;

int main () {
	int n, stanje, br_rac, i=0, odabir, br_stavki, rbr;
	char upit, upit2;
	do {
	   	cout<<"1. Alokacija glave liste stavki, unos pojedine stavke, ispis svih stavki racuna"<<endl;
	   	cout<<"2. Ispis svih stavki, ukupan iznos svih stavki, dealokacija liste stavki"<<endl;
	   	cout<<"3. Alokacija polja racuna/unos pojedinog racuna/ispis pojedinog racuna/dealokacija svih racuna"<<endl;
	   	cout<<"4. dodatni zadatak"<<endl;
	   	cout<<"9. Izlaz iz programa"<<endl;
	   	cin>>n;
	   	
	   	switch (n) {
			   case 1:
                    stanje = lista->status();
                    if (stanje==0) 
                       lista = new cstavka;         //prilikom alokacije liste aktivira se konstruktor!
                    lista->unos();
                    brojac++;
                    cout<<"\n------------------------------"<<endl;
                    lista->ispis();
			   		break;
  			   case 2:
                    stanje = lista->status();
                    if (stanje==0) break;
                    lista->ispis();
                    uk_iznos=0;    //prije poziva funkcije za racunanja iznosa resetiramo varijablu uk_iznos
                    lista->iznos();
                    cout<<"\nUkupan iznos svih stavki iznosi: "<<uk_iznos<<endl;
                    cout<<"\nZelite li dealocirati listu stavki (d/n)? ";
                    cin>>upit;
                    if (upit=='d') lista->dealokacija();
                    if (upit=='d') brojac=0; //ako dealociramo elemente onda i restartamo brojac na 0
			   		break;
			   case 3:
                    if (polje==NULL && cout<<"\nZelite li alocirati polje (d/n)?" && cin>>upit2);
                    if (upit2=='n') break;
                    if (polje==NULL && cout<<"Ukupan broj racuna? " && cin>>br_rac)
                       polje = new cstavka[br_rac];
                       
                    cout<<"\nOdaberite sto zelite: "<<endl;
                    cout<<"1. Unos pojedinog racuna \n2. Ispis pojedinog racuna \n3. Dealokaciju svih racuna"<<endl;
                    cin>>odabir;
                    switch (odabir) {
                           case 1:
                                if (i>=br_rac && cout<<"Nemoguce unijeti vise racuna!"<<endl) break;
                                cout<<"\nRedni broj racuna koji se unosi: "<<i<<endl;
                                cout<<"Koliko zelite stavki? ";
                                cin>>br_stavki;
                                for (int j=0;j<br_stavki;j++)
                                    polje[i].unos();
                                i++;
                                break;
                           case 2:
                                if (i==0 && cout<<"Nemoguc ispis, nije dodan niti jedan racun!"<<endl) break;
                                cout<<"Redni broj racuna kojeg zelite ispisati: ";
                                do
                                  cin>>rbr;
                                while ((polje[rbr].sljedeci==NULL && cout<<"Racun s tim rednim brojem nije unesen, unesite ponovno: ") || (rbr>=br_rac && cout<<"Broj premasuje ukupan broj racuna, unesite ponovno: ")); //ovaj zadnji uvjet je da se ne kreša program ako se unese redni broj veæi od broja elemnata polja
                                polje[rbr].ispis();
                                break;
                           case 3:
                                for (int j=0;j<br_rac;j++)
                                    polje[j].dealokacija();
                                delete [] polje;
                                polje=NULL;
                                i=0;
                                break;
                    }
			   		break;
			   case 4:
			   case 9: break;	
			   default: cout<<"Unos pogresan, unesite ponovno!"<<endl;
		}
		cout<<endl;
	} while (n!=9);
	
	system ("pause");
	return 0;
}
