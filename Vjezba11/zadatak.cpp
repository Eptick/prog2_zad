#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;
int broj_predmeta = 0;
int broj_prijava = 0;
class cstudij{
	public:
		cstudij *sljedeci;
		virtual void unos(){};
		virtual void ispis(bool x = false){}; // 2
		virtual int sifra(bool x){};
};
cstudij *lista;
cstudij *_zadnji;
class cpredmet;
cpredmet *novip;
class cprijava; // 2
cprijava *novap; // 2

class cpredmet : public cstudij{
	public:
		int sPredmeta;
		char naziv[35];
		cpredmet(){ // 3
			cout << "Novi predmet!\n";
		}
		void unos(){
			broj_predmeta++;
			novip->sljedeci = NULL;
			cout << "\nSifra predmeta: ";
			cin >> sPredmeta;
			cstudij *s;
			do
			for(s=lista->sljedeci;s;s=s->sljedeci)
				if(s->sifra(true) == sPredmeta)
					break;
			while(s && s->sifra(true) == sPredmeta 
					&& strcmp(typeid(*s).name(),"8cpredmet") == 0 && 
					cout << "Sifra postoji, ponovni unos: " && cin >> sPredmeta);
			cout << "Naziv Predmeta: ";
			cin.ignore();
			cin.getline(naziv,35);
			_zadnji->sljedeci = novip;
			_zadnji = novip;		
		}
		void ispis(bool x = false){ // 2
			cout << "\nSifra predmeta: "<<sPredmeta<<
			"\nNaziv Predmeta: "<< naziv << endl;
			if(x) cout << "==== POPIS PRIJAVA ====" << endl;
			if(x) for (cstudij *s=lista->sljedeci;s;s=s->sljedeci)
	        		if (sPredmeta == s->sifra(true) && strcmp(typeid(*s).name(),"8cprijava") == 0 ) 
	                    s->ispis(); 
		}
		int sifra(bool x){
			if(x)
				return sPredmeta;
			else
				cout <<"Naziv predmeta: "<<  naziv << endl;
			return 0;
		}
};
class cprijava : public cstudij{
	public:
		int sPrijave;
		double mbStudenta;
		int sPredmeta;
		char rok[15];
		cprijava(){ // 3
			cout << "Nova prijava!\n";
		}
		void unos(){ // 2
			broj_prijava++;
			novap->sljedeci = NULL;
			_zadnji->sljedeci = novap;
			_zadnji = novap;
			cout << "\nSifra prijave: ";
			cin >> sPrijave;
			cout << "Maticni broj studenta: ";
			cin >> mbStudenta;
			cout << "Sifra predmeta: ";
			cin >> sPredmeta;
			bool k = false;
			do
			for (cstudij *s=lista->sljedeci;s;s=s->sljedeci)
	        	if (sPredmeta == s->sifra(true) && strcmp(typeid(*s).name(),"8cpredmet") == 0  )
	                    k = true;
	        while(!k && cout << "Sifra ne postoji, ponovni unos: " && cin >> sPredmeta);
	        cstudij *s;
	        for(s=lista->sljedeci;s;s=s->sljedeci)
				if(s->sifra(true) == sPredmeta && strcmp(typeid(*s).name(),"8cpredmet") == 0)
					break;
			s->sifra(false);
			cout << "Rok: ";
			cin.ignore();
			cin.getline(rok,15);	
		}
		void ispis(bool x = false){ // 2
			cout << "\nSifra prijave: "<<sPrijave<<
			"\nMaticni broj studenta: "<<mbStudenta<<
			"\nSifra predmeta: "<<sPredmeta<<
			"\nRok: "<<rok<<endl;
		}	
		int sifra(bool x){ // 2
			return sPredmeta;
		}
};

int main(){
	int x;
	int sifra;
	char izbor;
	lista = new cstudij;
	lista->sljedeci = NULL;
	_zadnji = lista;
	do{ 
		izbor = 'x';
		cout << "1. Unos predmeta/unos prijava/ispis predmeta i prijava\n" << 
 				"2. Ispis predmeta/ispis prijava (odvojeno)\n" <<
				"3. Ispis liste prijava zadanog predmeta (prema sifri predmeta)\n"<<
				"9. Izlaz" << endl;
		cin >> x; 
		switch(x){
			case 1:
				cout << "Trenutni broj elemenata liste: " << broj_predmeta + broj_prijava<<endl;
				cout << "Unos ili ispis(u/i): ";
				cin >> izbor;
				if(izbor == 'u' && cout << "Predmet(0) ili prijava(1): ") cin >> izbor;
				if(izbor == 'i')
					for(cstudij *s =lista->sljedeci;s;s=s->sljedeci)
						s->ispis();
				if(izbor == '0') novip = new cpredmet;
				if(izbor == '0') novip->unos();
				if(izbor == '1' && broj_predmeta == 0 && cout << "Unos nije moguc!" << endl) break;
				if(izbor == '1') novap = new cprijava; // 2 
				if(izbor == '1') novap->unos(); // 2
				
			break;
			case 2: // 2
				cout << "Trenutni broj predmeta: " << broj_predmeta  << endl
				<< "Trenutni broj prijava : "<< broj_prijava<<endl;
				cout << "Zelite li popis predmeta(0) ili prijava(1): ";
				cin >> izbor;
				for(cstudij *s =lista->sljedeci;s;s=s->sljedeci)
					if(izbor == '0' && strcmp(typeid(*s).name(),"8cpredmet") == 0 )
						s->ispis();
					else if(izbor == '1' && strcmp(typeid(*s).name(),"8cprijava") == 0 )
						s->ispis();	
			break;
			case 3: // 2
				cout << "Trenutni broj predmeta: " << broj_predmeta  << endl
				<< "Trenutni broj prijava : "<< broj_prijava<<endl;
				if(broj_predmeta == 0 && cout << "Nema predmeta\n\n") break;
				cout << "Unesite sifru predmeta: ";
				cin >> sifra;
				for(cstudij *s =lista->sljedeci;s;s=s->sljedeci)
					if(s->sifra(true) == sifra && strcmp(typeid(*s).name(),"8cpredmet") == 0 )
						s->sifra(false);
				for(cstudij *s =lista->sljedeci;s;s=s->sljedeci)
					if(s->sifra(true) == sifra && strcmp(typeid(*s).name(),"8cprijava") == 0 )
						s->ispis();
			break;
		}
	} while(izbor != 9);
	system("pause");
	return 0;
}

