#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int redni_broj = 100;
int kat = 0;
int n = 100;
int p;
bool t = false;
class kategorije{
public:
	kategorije *sljedeci;
	int rb;
	char naslov[35];
	char urednik[35];
	void funkcija(int x = 0){
		
		switch(x){
			case 0:
				kat++;
			kategorije *zadnji;
			zadnji = this;
			while (zadnji->sljedeci)
					zadnji=zadnji->sljedeci;
			kategorije *novi;
			novi = new kategorije;
			novi->sljedeci = NULL;
			zadnji->sljedeci = novi;
			novi->rb = redni_broj;
			redni_broj++;
			cout << "Naslov: ";
			cin.ignore();
			cin.getline(novi->naslov,35);
			cout << "Urednik: ";
			cin.getline(novi->urednik,35);

			break;
			case 1:
				for(kategorije *s = this->sljedeci;s;s=s->sljedeci)
					cout << "Redni broj: " << s->rb << endl << "Naslov: " << s->naslov<<endl<<"Urednik: "<<s->urednik<<endl;
			break;
			case 2:
				for(kategorije *s = this->sljedeci;s;s=s->sljedeci)
					if(s->rb == p) t = true;
			break;
			
		}

	
	}
};
fstream dat;
kategorije *lista;
class radovi{
	public:
		int sifra;
		int rb;
		char naslov[35];
		double vrijeme;
	void funkcija(int x = 0){
		switch(x){
			case 0:
				clock_t vrijeme1,vrijeme2;
				vrijeme1=clock();
				double razlika;
				dat.open("radovi.dat", ios::in|ios::out|ios::app|ios::binary);
  				cout << "Sifra rada: ";
  				cin >> sifra;
  				t = false;
				cout << "Redni broj kategorije: ";
				cin >> p;
  				do
				  lista->funkcija(2);
  				while(!t && cout << "Redni broj ne postoji, ponovni unos: " && cin >> p);
  				rb = p;
  				if( rb > n) n = rb;
  				cout << "Naslov: ";
  				cin.ignore();
  				cin.getline(naslov,35);
  				vrijeme2 = clock();
  				vrijeme = vrijeme2-vrijeme1;
    			dat.write((char *)this,sizeof(*this));
				dat.close();
				dat.clear();
			break;
			case 1:
			dat.open("radovi.dat", ios::in|ios::binary);
			int k;
			cout << "Unesite redni broj kategorije: ";
			cin >> k;
		while(1){
    		  dat.read ((char *)this,sizeof(*this));
     		 if (dat.eof())break;
     		 if(rb != k) continue;
     		 cout << "======"<<endl;
     		 cout << "Sifra: " << sifra << endl;
     		 cout <<"Redni broj:" <<  rb << endl;
      		cout << "Naslov: " << naslov << endl;
      		cout << "Vrijeme: "<< vrijeme << endl;
    	}
		dat.close(); dat.clear();
	}
	}
};

int main(){
	int izbor;
	int x;
	lista = new kategorije;
	lista->sljedeci = NULL;
	radovi rad;
	dat.open("radovi.dat", ios::out);
	dat.close();
	dat.clear();
	do{
		cout << "1. Mogucnost jedan!" <<endl;
		cout << "9. Izlaz" << endl;
		cin >> izbor;
		switch(izbor){
			case 1:
			cout << "1. Unos kategorije"<<endl;
			cout << "2. ispis kategorije"<<endl;
			cout << "3. Unos radovi"<<endl;
			cout << "4. ispis radovi"<<endl;
			cin >> x;	
			if(x == 1) lista->funkcija(0);
			if(x == 2) lista->funkcija(1);
			if(x == 3) rad.funkcija(0);
			if(x == 4) rad.funkcija(1);
			
			cout << endl << "Broj elemenata kategorije: " << kat << endl;
			cout << "Najveci redni broj je: " << n<< endl;
			break;
		}
	} while(izbor != 9);
	system("pause");
	return 0;
}
