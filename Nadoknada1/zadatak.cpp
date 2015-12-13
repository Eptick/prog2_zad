#include <iostream>
using namespace std;
#include "biblioteka_vrijeme.cc" // ili biblioteka_vrijeme2.cc
int is = 0, ne = 0,n=0;
class cpravokutnik{
		cvrijeme vrijeme;
		float sirina, visina;
	public:
		static int brojac;
		char naziv[35];
		float x1,x2,y1,y2;
	float povrsina(){ 
		sirina = x2-x1;
		visina = y2-y1;
		if(sirina<=0 || visina <= 0) return -1;
		return sirina * visina;
	}
	void unos(){
		char k;
		vrijeme.pocetak();
		cout << "Naziv pravokutnika: ";
		cin.ignore();
		cin.getline(naziv,35);
		do{
		k = 'n';
		cout << "x1: ";
		cin >> x1;
		cout << "y1: ";
		cin >> y1;
		cout << "x2: ";
		cin >> x2;
		cout << "y2: ";
		cin >> y2;
		if(povrsina() == -1 && cout << "Stranice ne cine pravokutnik, zelite li ponoviti unos?(d/n): ")cin >> k;
		}while(k=='d');
		if(x1 >= x2 || y1 >= y2) ne++;
		else is++;
		vrijeme.kraj();
		brojac++;
		 cout <<"Broj ispravnih pravokutnika: " << is << endl
			<< "Broj nepispravnih pravokutnika: " << ne << endl << endl;
	}
	void ispis(){
		cout << "==================" << endl;
		cout << "Naziv trokuta: " << naziv << endl;
		if(!(x1 >= x2 || y1 >= y2))
		cout << "x1: " << x1 << endl
		<< "y1: " << y1 << endl
		<< "x2: " << x2 << endl
		<< "y2: " << y2 << endl; //Maknuti ovu ; ako se ispisuje povrsina
	  //<< "Povrisina: " << povrsina() << endl; Ako trazi da treba i povrsinu ispisat. U zadatku pise da ne treba pa mi je to cudno.
		else cout << "Stranice ne cine pravokutnik!" << endl;
		cout << "Vrijeme: " << vrijeme.proteklo() << endl;
	}
};
cpravokutnik *polje;
int cpravokutnik::brojac = 0;
int main(){
	int izbor,i,s;
	do{
	cout << "1. Dinamicka alokacija polja pravokutnika/ispis podataka o pravokutnicima" << endl
	<< "2. Unos podataka o pravokutnicima" << endl
	<< "3. Ispis podataka o svim pravokutnicima" << endl
	<< "9. Izlaz iz programa" << endl;
	cin >> izbor;
	if(izbor == 9) break;
	s = 2;
	if(!polje && cout << "0 - polje nije alocirano!"<< endl << endl) s= 0;
	if(polje && cpravokutnik::brojac == 0 && cout << "1 - Polje je prazno i alocirano na " << n << " elemenata!" << endl << endl) s = 1;
	if(s == 2)cout <<"Broj ispravnih pravokutnika: " << is << endl << "Broj nepispravnih pravokutnika: " << ne << endl << endl;
	if(s == 0 && (izbor == 2 || izbor == 3 ) && cout << "Alocirajte polje" << endl) continue;
	
	if(izbor == 1 && s == 0 && cout << "Koliko elemenata polja zelite?: ") cin >> n;
	if(izbor == 1 && s == 0) polje = new cpravokutnik[n];	
	i = 0;
	if(izbor == 1 && s == 2)
		while(i<cpravokutnik::brojac)polje[i++].ispis();
		
	if(izbor == 2 && cpravokutnik::brojac < n) polje[cpravokutnik::brojac].unos();
	if(izbor == 2 && n!= 0 && cpravokutnik::brojac >= n) cout << "Polje je puno!" << endl;
	i = 0;
	if(s<2) continue;
	if(izbor == 3) while(i<cpravokutnik::brojac)polje[i++].ispis();

	}while(1);
	if(polje) delete []polje;
	system("pause");
	return 0;
}
// Testni podatci: 1, 10, 2, Naziv, 1, 1, 2, 2, 3, 9
