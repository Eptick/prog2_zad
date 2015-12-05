#include <iostream>
#include <fstream>
#include <cmath>
#include "biblioteka_tel_imenik.cc"
using namespace std;
struct sZapis {
    int sifra;
    char naziv[25];
    float kol;
    float cij;
    int vr;
};
bool nema = 1;
int pom;
int prostak;
int br = 0;
int n = 0;
sZapis zapis;
sZapis z2;

void ispis() {
    cout << endl << "sifra: " << z2.sifra << endl
         << "naziv: " << z2.naziv << endl
         << "cijena: " << z2.cij << endl
         << "kolicina: " << z2.kol << endl
         << "vrijeme (s): " << z2.vr << endl;
}

sZapis procitaj(sZapis& z, int n) {
    fstream dat("roba_redzic_leon.dat", ios::in|ios::binary);
    dat.seekg(n*sizeof(z), ios::beg);
    dat.read((char*)&z, sizeof(z) );
    if(dat) dat.close();
    return z;
}
void zapisi(sZapis& z, int n) {
    fstream dat("roba_redzic_leon.dat", ios::in|ios::out|ios::binary);
    dat.seekp(n*sizeof(z), ios::beg);
    dat.write((char*)&z, sizeof(z) );
    if(dat) dat.close();
}
void isprazni(int n) {
    fstream dat1("roba_redzic_leon.dat", ios::out|ios::binary);
    dat1.close();
    dat1.clear();
    z2.sifra = 0;
    for(int i=0; i<n; i++)
        zapisi(z2, i);
}
void status(int v=1) {
    nema = 0;
    fstream dat("roba_redzic_leon.dat", ios::in|ios::binary);
    if(dat) dat.seekg(0, ios::end);
    if(!dat) nema = 1;
    else pom = dat.tellg()/sizeof(z2);
    if(v && nema) cout << "0 - datoteka nije kreirana" << endl;
    if(dat) dat.close();
    if(nema) return;
    n = pom;
    int a;
    int j = 0;
    for(a=n; j<sqrt(a) && a>1; a--)
        for(j=2; j<sqrt(a); j++)
            if(a%j==0) break;
    prostak = (a==3 ? a : a+1);
    br = 0;
    for(int i=0; i<n; i++)
        if(procitaj(z2, i).sifra) br++;
    if(v)
        if(br) cout << "2 - datoteka sadrzi " << br << " zapisa" << endl;
        else   cout << "1 - datoteka je prazna" << endl;
}

void mog2() {
    status();
    if(nema) return;
    if(br==n) cout << "Svi su zapisi zauzeti." << endl;
    if(br==n) return;
    vrijeme_pocetak();
    cout << "sifra: ";
    cin >> zapis.sifra;
    cout << "naziv: ";
    unos(zapis.naziv);
    while(1) {
        cout << "cijena: ";
        cin >> zapis.cij;
        cout << "kolicina: ";
        cin >> zapis.kol;
        if(zapis.kol*zapis.cij>=10 && zapis.kol*zapis.cij<=9999)
            break;
        cout << "cijena * kolicina mora biti u rasponu 10 - 9999!" << endl;
    }
    vrijeme_kraj();
    zapis.vr = vrijeme_proteklo() / CLOCKS_PER_SEC;
    cout << "vrijeme proteklo (s): " << zapis.vr << endl;
    int rbr = zapis.sifra % prostak;
    cout << endl << "redni broj zapisa: " << rbr << endl;
    if(procitaj(z2, rbr).sifra) cout << "[duplikat] sifra: " << z2.sifra << " naziv: " << z2.naziv << endl;
    int k;
    for(k=rbr; k<n && procitaj(z2, k).sifra; k++)
        if(k==n-1) k = -1;
    zapisi(zapis, k);
    for(int i=0; i<n; i++)
        if(procitaj(z2, i).sifra) ispis();
}

 void mog3() {
     status();
     if(nema) return;
     cout << "Broj nepraznih zapisa: " << br << endl;
     int sifra;
     cout << "Sifra: ";
     cin >> sifra;
     int rbr = sifra % prostak;
     cout << "rbr zapisa: " << rbr << endl;
     if(pom = !procitaj(z2, rbr).sifra) cout << "zapis nije pronadjen" << endl;
     if(pom) return;
     if(pom = (procitaj(z2, rbr).sifra == sifra) ) ispis();
     if(!pom)
         for(int i=rbr; !pom && i<n; i++)
             if(pom = (procitaj(z2, i).sifra == sifra) ) ispis();
             else if(z2.sifra) cout << "[duplikat] sifra: " << z2.sifra << endl;
     if(!pom)
         for(int i=0; !pom && i<rbr; i++)
             if(pom = (procitaj(z2, i).sifra == sifra) ) ispis();
             else if(z2.sifra) cout << "[duplikat] sifra: " << z2.sifra << endl;
     if(!pom) cout << "zapis nije pronadjen" << endl;
 }


int main() {
    char x;
    do {
        cout << endl << "1. Kreiranje datoteke praznih zapisa" << endl;
        cout << "2. Unos podataka o robi u relativnu datoteku (uvazavajuci duplikate)" << endl;
        cout << "3. Pretrazivanje relativne datoteke" << endl;
        cout << "4. (dodatni zadatak)" << endl;
        cout << "9. Izlaz iz programa" << endl;
        cin >> x;
        cout << endl;
        switch(x) {
            case '1':
                status();
                pom = 0;
                if(nema) cout << "Koliko zapisa?: ";
                if(nema) cin >> pom;
                if(nema) isprazni(pom);
                status(0);
                cout << "velicina datoteke: " << n*sizeof(z2) << " bajtova, br. zapisa: " << n << endl;
                cout << "Broj nepraznih zapisa: " << br << endl;
                cout << "Prvi manji prosti broj: " << prostak << endl;
                break;

              case '2':
                  mog2();
                  break;

            case '3':
                mog3();
                break;

            case '*':
               cout << "Koliko zapisa?: ";
               cin >> pom;
               isprazni(pom);
        }
     } while(x != '9');
 return 0;
 }





