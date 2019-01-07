#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;
const int n=10;
int t[n][n];

void losuj(){
    srand(time(NULL));
    for (int i=0;i<n;i++)
        for (int j=0; j<n; j++)
            t[i][j]=rand()%2;

}

void wypisz(){
    for (int i=0;i<n;i++){
        for (int j=0; j<n; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

void zatop(int w, int k){
    if (t[w][k]==1){
        t[w][k]=0;
        zatop(w+1,k);
        zatop(w,k+1);
        zatop(w-1,k);
        zatop(w,k-1);
    }
}
int main(){
    int w, k;

    losuj();
    wypisz();

    cout << "Podaj wiersz: ";
    cin >> w;
    cout << "Podaj kolumne: ";
    cin >> k;

    for(int i=0;i<20;i++)
        zatop(w,k);

    wypisz();


    return 0;
}
