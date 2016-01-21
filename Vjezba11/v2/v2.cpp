// Redosljed prepisivanja
// Prazan main, pa klasa cstudij i ono malo ispod nje, varijable od main bez inicijalizacije liste,
// do-while i ono u njemu, prazan switch pa onda klasa cpredmet, 
// poslje klase cpredmet popunit case 1 do oznake za testiranje 2
// testirati prvi puta na 6 {}, nakon toga prepisati klasu cprijava i ostatak case 1, pa case 2, pa case 3
// Podatci za testiranje na dnu
#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;
class cstudij{
	public:
		cstudij *sljedeci;
		virtual void unos() = 0;
		virtual void ispis(bool x = false) = 0;
		virtual int sifra(bool x) = 0;
};
//=== POČETAK ONO MALO ISPOD NJE ===
int broj_predmeta = 0;
int broj_prijava = 0;
bool p = false;
cstudij *lista;
cstudij *_zadnji;
class cpredmet;
cpredmet *novip;
class cprijava;
cprijava *novap; 
//=== KRAJ ONO MALO ISPOD NJE ===
class cpredmet : public cstudij{
	public:
		int sPredmeta;
		char naziv[35];
		cpredmet(){
		if(p) 
			cout << "Novi predmet!\n"; 
		if(!p)	p = true; 
		} 
		int sifra(bool x){
			if(x)
				return sPredmeta;
			else
				cout <<"Naziv predmeta: "<<  naziv << endl;
			return -1;
		}
		void unos(){
			broj_predmeta++;
			novip->sljedeci = NULL;
			cout << "\nSifra predmeta: ";
			cin >> sPredmeta;
			cstudij *s;
			// U ovoj do while petlji paziti da svuda budu razmaci i da bude tocno tako prepisano
			// Tocno prepisati kak je napisano
			do
			for(s=lista->sljedeci;s;s=s->sljedeci)
				if(s->sifra(true) == sPredmeta)
					break;
			while(s && s->sifra(true) == sPredmeta && strcmp(typeid(*s).name(),"8cpredmet") == 0 && cout << "Sifra postoji, ponovni unos: " && cin >> sPredmeta);
			cout << "Naziv Predmeta: ";
			cin.ignore();
			cin.getline(naziv,35);
			_zadnji->sljedeci = novip;
			_zadnji = novip;		
		}
		void ispis(bool x = false){
			cout << "\nSifra predmeta: "<<sPredmeta<<
			"\nNaziv Predmeta: "<< naziv << endl;
			if(x) cout << "==== POPIS PRIJAVA ====" << endl;
			if(x) for (cstudij *s=lista->sljedeci;s;s=s->sljedeci)
	        		if (sPredmeta == s->sifra(true) && strcmp(typeid(*s).name(),"8cprijava") == 0 ) 
	                    s->ispis(); 
		}
	
};
// Sve iznad ove linije prepisat za prvo testiranje

// Ovu klasu cprijava prepisati za drugo testiranje;
class cprijava : public cstudij{
	public:
		int sPrijave;
		double mbStudenta;
		int sPredmeta;
		char rok[15];
		cprijava(){
			cout << "Nova prijava!\n";
		}
		int sifra(bool x){ 
			return sPredmeta;
		}
		void unos(){
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
			// U ovoj do while petlji paziti da svuda budu razmaci i da bude tocno prepisano
			// Tocno prepisati kak je napisano
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
		void ispis(bool x = false){
			cout << "\nSifra prijave: "<<sPrijave<<
			"\nMaticni broj studenta: "<<mbStudenta<<
			"\nSifra predmeta: "<<sPredmeta<<
			"\nRok: "<<rok<<endl;
		}	
};

int main(){
	//=== POČETAK VARIJABLE OD MAIN ===
	int x;
	int sifra;
	char izbor; 
	//=== KRAJ VARIJABLE OD MAIN ===
	//=== OVO PREPISATI POSLJE KLASE CPREDMET ===
	lista = new cpredmet;
	lista->sljedeci = NULL;
	_zadnji = lista; 
	//=== OVO PREPISATI POSLJE KLASE CPREDMET ===
	do{ 
		//=== POČETAK ONO U NJEMU ===
		izbor = 'x';
		cout << "1. Unos predmeta/unos prijava/ispis predmeta i prijava\n" << 
 				"2. Ispis predmeta/ispis prijava (odvojeno)\n" <<
				"3. Ispis liste prijava zadanog predmeta (prema sifri predmeta)\n"<<
				"9. Izlaz" << endl;
		cin >> x; 
		//=== KRAJ ONO U NJEMU ===
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
				// Ovo ispod do break ne prepisivati za prvo testiranje;
				// ============== SVE ISPOD OVOGA U DRUGO TESTIRANJE ============== 
				if(izbor == '1' && broj_predmeta == 0 && cout << "Unos nije moguc!" << endl) break; // 2
				if(izbor == '1') novap = new cprijava; // 2
				if(izbor == '1') novap->unos(); // 2
			break;
			// Case 2 prepisivati za drugo testiranje
			case 2: 
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
			// Case 3 prepisivati za drugo testiranje
			case 3:
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
			// ============== SVE IZNAD OVOGA U DRUGO TESTIRANJE ============== 
		}
	} while(x != 9);
	system("pause");
	return 0;
}

// Podatci za prvo testiranje
// 1 u 0 1 n1 1 u 0 1 2 n2 1 i 9
// Poslje prvog testiranja najprije prepisati class cprijava cijelu! onda ostatak case 1, pa case 2, pa case 3;
// Poslje prvog testiranja prepisati ostatak case 1 (one if(izbor == '1'))
// Poslje prvog testiranja prepisati case 2 i case 3
// Podatci za drugo testiranje
// 3 1 u 0 1 n1 1 u 0 1 2 n2 1 i 1 u 1 1 1 4 1 10.10.10 3 1 9 

