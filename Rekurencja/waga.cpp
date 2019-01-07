#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

const int n=4;
int t[n],pr1;

void wypelnij(){
    for (int i=0;i<n;i++){
        cin >> t[i];
        }
}

void wypisz(){
    for (int i=0;i<n;i++){
        cout << t[i];
        }
}

bool waga(int produkt,int p){
    if(produkt==0) cout<<"Da sie!" << endl;
    else{
    //cout<<"prod "<<produkt<< "  p= "<<p<<endl;
    //Sleep(1000);
        if (p<n){
            waga(produkt-t[p],p+1);
            waga(produkt+t[p],p+1);
            waga(produkt,p+1);
        }
    }
}

int main(){

    cout << "Podaj mase produktu: " << endl;
    cin >> pr1;
    cout << "Podaj 4 odwazniki:" << endl;
    wypelnij();
//  wypisz();
    waga(pr1,0);
//  cout << endl << "Wyszlismy!";


    return 0;
}
