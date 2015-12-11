#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "biblioteka_vrijeme.cc" // ili biblioteka_vrijeme2.cc
int is = 0, ne = 0,n=0;
float p = 0;
class ctrokut{
		cvrijeme vrijeme;
		float s;
	public:
		static int brojac;
		char naziv[35];
		float a,b,c;
	float povrsina(){ return sqrt(s*(s-a)*(s-b)*(s-c)); }
	void unos(){
		char k;
		vrijeme.pocetak();
		cout << "Naziv trokuta: ";
		cin.ignore();
		cin.getline(naziv,35);
		do{
		k = 'n';
		cout << "Stranica a: ";
		cin >> a;
		cout << "Stranica b: ";
		cin >> b;
		cout << "Stranica c: ";
		cin >> c;
		s = (a+b+c)/2;
		if((s <= a || s <= b || s <= c) && cout << "Stranice ne cine trokut, zelite li ponoviti unos?(d/n): ")cin >> k;
		}while(k=='d');
		if(s <= a || s <= b || s <= c) ne++;
		else is++;
		vrijeme.kraj();
		brojac++;
		cout << endl << "Ukupan broj unesenih trokuta: " << brojac << endl;
	}
	void ispis(){
		cout << "==================" << endl;
		cout << "Naziv trokuta: " << naziv << endl;
		if(!(s <= a || s <= b || s <= c))
		cout << "Stranica a: " << a << endl
		<< "Stranica b: " << b << endl
		<< "Stranica c: " << c << endl
		<< "Povrsina: " << povrsina() << endl;
		else cout << "Stranice ne cine trokut!" << endl;
		cout << "Vrijeme: " << vrijeme.proteklo() << endl;
		if(!(s <= a || s <= b || s <= c)) p += povrsina();
	}
};
ctrokut *polje;
int ctrokut::brojac = 0;
int main(){
	int izbor,i,s;
	do{
	cout << "1. Dinamicka alokacija polja trokuta" << endl
	<< "2. Unos podataka o trokutima" << endl
	<< "3. Ispis podataka o svim trokutima" << endl
	<< "4. dodatna mogucnost!" << endl
	<< "9. Izlaz iz programa" << endl;
	cin >> izbor;
	if(izbor == 9) break;
	s = 2;
	if(!polje && cout << "0 - polje nije alocirano!"<< endl << endl) s= 0;
	if(polje && ctrokut::brojac == 0 && cout << "1 - Polje je prazno i alocirano na " << n << " elemenata!" << endl << endl) s = 1;
	if(s == 2)cout << "2 - Polje je alocirano na " << n << " elemenata i sadrzi " << ctrokut::brojac << " trokuta" << endl << endl;
	
	if(izbor == 1 && s == 0 && cout << "Koliko elemenata polja zelite?: ") cin >> n;
	if(izbor == 1 && s == 0) polje = new ctrokut[n];	
		
	if(izbor == 2 && ctrokut::brojac < n) polje[ctrokut::brojac].unos();
	if(izbor == 2 && n!= 0 && ctrokut::brojac >= n) cout << "Polje je puno!" << endl;
	i = 0;
	p = 0;
	if(s<2) continue;
	if(izbor == 3) while(i<ctrokut::brojac)polje[i++].ispis();
	if(izbor == 3) cout << endl <<"Broj ispravnih trokuta: " << is << " s ukupnom povrsinom: " << p << endl
	<< "Broj unosa gdje stranice ne cine trokut: " << ne << endl << endl;
	if(izbor < 4) continue;
	srand(time(0));
	rand();
	char novi[35];
	int r = rand()%ctrokut::brojac;
	polje[r].ispis();
	cout << "Unesite novi naziv Trokuta: ";
	cin.ignore();
	cin.getline(novi,35);
	strcpy(polje[r].naziv,novi);
	polje[r].ispis();
	}while(1);
	if(polje) delete []polje;
	system("pause");
	return 0;
}
/*
Testni podatci: 1, 10, 2, Naziv, 10, 10, 10, 3
*/
