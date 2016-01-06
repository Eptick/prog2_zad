//Konstruktor i destruktor
#include <iostream>
using namespace std;
class cpravokutnik {
    public: int x1,y1,x2,y2;
    private: int sirina, visina;
    public:
  cpravokutnik(){//konstruktor 1
    cout << " -> konstruktor 1. this = " << (int)(size_t)this << endl;
  }//pravokutnik 1
  cpravokutnik(int x1_,int y1_,int x2_,int y2_){//konstruktor 2
    cout << " -> konstruktor 2 (s argumentima). this = " << (int)(size_t)this << endl;
    x1=x1_;y1=y1_;x2=x2_;y2=y2_;
  }//pravokutnik 2
  ~cpravokutnik(){//destruktor
    cout << " -> destruktor. this = " << (int)(size_t)this << endl;
  }//~cpravokutnik
	int povrsina (){
    visina = y2 - y1;
    sirina = x2 - x1;
		return sirina * visina;
	};//povrsina
};//cpravokutnik
cpravokutnik p1(50,50,100,150),*objekt; // statièki objekt i pokazivaè na objekt
int main(){
  cout << "Staticki objekt p1 je upravo alociran! Adresa p1 = " << (int)(size_t)&p1 << endl;
  cout << "Povrsina p1 = " << p1.povrsina() << endl;
  cout << "Dinamicka alokacija objekta:" << endl;
  objekt = new cpravokutnik;//alokacija objekta
  cout << "objekt = " << (int)(size_t)objekt << endl;
  delete objekt;//dealokacija objekta
  cout << "Dinamicki objekt je upravo dealociran!" << endl;
  cout << "Staticki objekt p1 dealocira se na kraju!" << endl;
}//main
