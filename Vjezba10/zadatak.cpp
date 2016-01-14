#include <iostream>
#include <cstring>
using namespace std;
int broj_predmeta = 0; // TEST 1
int broj_prijava = 0; // TEST 1
class cpredmeti_zapis{ // TEST 1
	public:
	int sifra;
	char nazivp[35];
	char nazivs[35];
	void unos(){ // TEST 1
		cout << "Unesite sifru: ";
		cin >> sifra;
		cout << "Unesite naziv predmeta: ";
		cin.ignore();
		cin.getline(nazivp,35);
		cout << "Unesite naziv smijera: ";
		cin.getline(nazivs,35);
	}
	void ispis(){ // TEST 1
		cout << "Sifra: " << sifra << endl
		<< "Naziv predmeta: " << nazivp << endl
		<< "Naziv smijera: " << nazivs << endl
		<< "======== ==========" << endl;
	}
};
class cpredmeti {
	public:
	cpredmeti_zapis predmet; // TEST 1
	cpredmeti *sljedeci; // TEST 1
	
	void unos(bool x){ // TEST 1
		broj_predmeta++;
		cpredmeti *novi,*zadnji;
		novi = new cpredmeti; 
		novi->predmet.unos();
		zadnji = this;
		if(x) novi->sljedeci = zadnji->sljedeci;
		if(x) zadnji->sljedeci = novi;
		if(x) return;
    	while (zadnji->sljedeci)
      		zadnji = zadnji->sljedeci; 		           
	    zadnji -> sljedeci = novi;
	}	
	void ispis(){ // TEST 1
		cout << endl;
		for (cpredmeti *setac=this->sljedeci;setac && cout<<"Pokazivac->"<<setac->sljedeci<<endl;setac=setac->sljedeci)
               setac->predmet.ispis();
	}
	bool pretraga(char arg[35]){ // TEST 2
		cout << "Popis predmeta za smijer " << arg <<endl;
		for (cpredmeti *setac=this->sljedeci;setac;setac=setac->sljedeci)
               if (strcmp(setac->predmet.nazivs,arg)==0)
                  cout << "Predmet: " <<  setac->predmet.nazivp<<endl;
	}
};
cpredmeti *predmeti; // TEST 1

class cprijave_zapis{ // TEST 2
	public:
	int sifra_prijave;
	int sifra_predmeta;
	double maticni;
	char rok[15];
	void unos(){// TEST 2
		cout << "Unesite sifru prijave:";
		cin >> sifra_prijave;
		cout << "Unesite sifru predmeta:";
		cin >> sifra_predmeta;
		bool k = false;
		do
		for (cpredmeti *setac=predmeti->sljedeci;setac;setac=setac->sljedeci)
        	if (sifra_predmeta == setac->predmet.sifra )
                    k = true;
        while(!k && cout << "Sifra ne postoji, ponovni unos: " && cin >> sifra_predmeta);
		cout << "Unesite maticni broj: ";
		cin >> maticni;
		cout << "Unesite rok: ";
		cin.ignore();
		cin.getline(rok,15);
	}
	void ispis(){// TEST 2
		cout << "======== ==========" << endl
		<< "Sifra prijave: " << sifra_prijave << endl
		<< "Sifra predmeta: " << sifra_predmeta << endl;
		for (cpredmeti *setac=predmeti->sljedeci;setac;setac=setac->sljedeci)
        	if (sifra_predmeta == setac->predmet.sifra )
                        cout<<"Naziv predmeta " << setac->predmet.nazivp<<endl;
		cout << "Maticni broj: " << maticni << endl
		<< "Rok: " << rok << endl;
	}
};

class cprijave{ // TEST 2
	public:
	cprijave_zapis *zapis;
	cprijave *sljedeci;
	cprijave(){
		zapis = new cprijave_zapis;
		cout << "Konstruktor\n";
	}
	void unos(){ // TEST 2
		broj_prijava++;
		cprijave *novi,*zadnji;
		novi = new cprijave; 
		novi->zapis->unos();
		zadnji = this;
    	while (zadnji->sljedeci)
      		zadnji = zadnji->sljedeci; 		           
	    zadnji -> sljedeci = novi;
	}
	void ispis(){ // TEST 2
    	for (cprijave *setac=this->sljedeci;setac;setac=setac->sljedeci)
               setac->zapis->ispis();
	}
};
cprijave *prijave; // TEST 2
int main(){
	int izbor;
	char dodati;
	int status_predmeti;
	int status_prijave;
	char naziv[35];
	do{ 
		status_predmeti = 2;
		status_prijave = 2;
		dodati = 'b';
		cout << "1. Alokacija glave liste predmeta/\n\tUpis predmeta na kraj liste predmeta i ispis liste\n" <<
	            "2. Popis predmeta zadanog smjera/Unos na pocetak liste predmeta\n" << 
				"3. Unos u listu prijava/Ispis liste prijava za sve predmete\n" <<
				"9. Izlaz" << endl;
		cin >> izbor; 
		if(izbor == 9) break;
		cout << "======== STATUS PREDMETI ============" << endl;
		if(!predmeti && cout << "0 - Nije alocirana lista predmeta" << endl) status_predmeti = 0;
		if(predmeti && predmeti->sljedeci == NULL && cout << "1 - Lista nema elemenata" << endl) status_predmeti = 1;
		if(predmeti && status_predmeti == 2) cout << "2 - Lista predmeta je alocirana i sadrzi " << broj_predmeta << " elemenata" << endl; 
		cout << "============= END ==================" << endl; 
		cout << endl;
		if(status_predmeti == 0 && izbor == 1) predmeti = new cpredmeti;
		if(status_predmeti == 0 && izbor == 1) predmeti->sljedeci = NULL;
		if(status_predmeti == 0 && (izbor == 1 || izbor == 2) ) continue;
		if(izbor == 1) predmeti->unos(false);
		if(izbor == 1) predmeti->ispis();
		/*================	IZNAD JE TEST 1	====================== */
		/*================	ISPOD JE TEST 2	====================== */
		if(izbor == 2 && status_predmeti == 2 && cout << "Unesite naziv smijera: ")cin >> naziv;
		if(izbor == 2 && status_predmeti == 2 ) predmeti->pretraga(naziv);
		if(izbor == 2 && cout << "Zelite li dodati element na pocetak?(d/n): ") cin >> dodati;
		if(dodati == 'd') predmeti->unos(true);
		if(dodati == 'd') predmeti->ispis();
		if(izbor < 3) continue;
		cout << "======== STATUS PRIJAVE ============" << endl;
		if(!prijave && cout << "0 - Nije alocirana lista prijava" << endl) status_prijave = 0;
		if(prijave && prijave->sljedeci == NULL && cout << "1 - Lista nema elemenata" << endl) status_prijave = 1;
		if(prijave && status_prijave == 2) cout << "2 - Lista prijava je alocirana i sadrzi " << broj_prijava << " elemenata" << endl;
		cout << "============= END ==================" << endl << endl;
		if(status_predmeti != 2 && cout << "Unos nije dopusten!" << endl) continue;
		if(status_prijave == 0) prijave = new cprijave;
		if(status_prijave == 0) prijave->sljedeci = NULL;
		if(status_prijave == 0) continue;
		prijave->unos();
		cout << "\n==============ISPIS==============" << endl;
		prijave->ispis();
		/*================	IZNAD JE TEST 2	====================== */
		/*================	ISPOD JE TEST 1	====================== */
	} while(izbor != 9);
	system("pause");
	return 0;
}

