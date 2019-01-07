#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=8;
int t[n]={1,1,3,2,4,2,1,3};

void losuj(){
    srand(time(NULL));
    for (int i=0;i<n;i++)
        t[i]=rand()%10+1;
}

void wypisz(){
    for (int i=0;i<n;i++)
        cout << t[i] << " ";
}


bool znajdz(int suma1, int suma2, int suma3, int i){

    if (i==n) return (suma1==suma2 && suma2==suma3);

    {
    return znajdz(suma1+t[i], suma2, suma3,i+1) or znajdz(suma1, suma2+t[i], suma3,i+1) or znajdz(suma1, suma2, suma3+t[i],i+1);
    }
}

int main(){

   // losuj();
    wypisz();
    if (znajdz(0,0,0,0)==true) cout << "Jest taki podzial";


    return 0;
}
