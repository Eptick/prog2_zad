#include <iostream>
#include <cstring>
using namespace std;
class cklasa{
  public: int a,b;
  void metoda(){
    cout << "Adresa objekta preko kojeg je metoda pozvana: " << (size_t)this << endl; // size_t = unsigned integral type
    cout << "Vrijednosti atributa su: " << this->a << " i " << this -> b << endl;
  };//metoda
};//cklasa
cklasa objekt1,objekt2;
int main(){
  objekt1.a=5;objekt1.b=10;
  cout << "Adresa objekta objekt1: " << (size_t)&objekt1 << endl;
  objekt1.metoda();
  objekt2.a=7;objekt2.b=9;
  cout << "Adresa objekta objekt2: " << (size_t)&objekt2 << endl;
  objekt2.metoda();
}//main
