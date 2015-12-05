#include "biblioteka_vrijeme.cc"
#include <iostream>
#include <math.h>
using namespace std;
float povrsina(float sirina, float visina){return sirina * visina;}
float povrsina(float r){return r * r * M_PI;}
float povrsina(float a, float b, float c){
	float s = (a+b+c) / 2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}	
int main(){
	int izbor;
	do{
		cout << "1.) Izracun povrsine pravokutnika" << endl;
		cout << "2.) Izracun povrsine kruga" << endl;
		cout << "3.) Izracun povrsine trokuta" << endl;
		cout << "4.) Jedna od varijanti" << endl;
		cout << "9.) Izlaz iz programa" << endl;
		cout << "Odaberite jednu od mogucnosti: ";
		cin >> izbor;
		switch(izbor){
			case 1:
				float sirina, visina;
				cout << "Unesite sirinu:";
				vrijeme_pocetak();
				cin >> sirina;
				cout << "Unesite visinu:";
				cin >> visina;
				
				while(sirina <= 0 || sirina > 100 || visina <= 0 || visina > 100){
					cout << "Vrijednosti moraju biti  > 0 i < 100" << endl;
					cout << "Unesite sirinu:";
					cin >> sirina;
					cout << "Unesite visinu:";
					cin >> visina;
				} 
				cout << "Povrsina zadanog pravokutnika jest: " << povrsina(sirina,visina) << endl;
				vrijeme_kraj();
				cout << "Proteklo je " << vrijeme_proteklo() << " stotinki" << endl;
				break;
			case 2:
				float r;
				cout << "Unesite radijus kruga: ";
				vrijeme_pocetak();
				cin >> r;
				while(r<=0 || r > 100) {
					cout << "Vrijednosti moraju biti  > 0 i < 100" << endl;
					cout << "Unesite radijus kruga: ";
					cin >> r;	
				}
				cout << "Povrsina zadanog kruga jest: " << povrsina(r) << endl;
				vrijeme_kraj();
				cout << "Proteklo je " << vrijeme_proteklo() << " stotinki" << endl;
				break;
			case 3:
				float a,b,c;
				bool ponovno;
				do {
					ponovno = false;	
					cout << "Unesite stranicu a: ";
					vrijeme_pocetak();
					cin >> a;
					while(a <= 0 || a > 100){
						cout << "Vrijednost mora biti izmeðu 0 i 101!";
						cout << "Unesite stranicu a: ";
						cin >> a;
					}
					cout << "Unesite stranicu b: ";
					cin >> b;
					while(b <= 0 || b > 100){
						cout << "Vrijednost mora biti izmeðu 0 i 101!";
						cout << "Unesite stranicu b: ";
						cin >> b;
					}
					cout << "Unesite stranicu c: ";
					cin >> c;
					while(c <= 0 || c > 100){
						cout << "Vrijednost mora biti izmeðu 0 i 101!";
						cout << "Unesite stranicu c: ";
						cin >> c;
					}
					if( (a+b) <= c){
						ponovno = true;
						cout << "Nije trokut!" << endl;
					}
				} while(ponovno);
				cout << "Povrsina trokuta jest: " << povrsina (a,b,c) << endl;
				vrijeme_kraj();
				cout << "Proteklo je " << vrijeme_proteklo() << " stotinki" << endl;
				break;
			case 9:
				break;
			case 4:
				break;
			default:
				cout << "Los izbor brateu!" << endl;
				break;
		}
	} while (izbor != 9);
	cout << "TO e TO!" << endl;
	return 0;	
}
