#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=4;
int t[n][n],w,k,w_maks,k_min,w1,k1;

int main(){
    srand(time(NULL));

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            t[i][j]=rand()%4+1;
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    k_min=0;
    for (int i=0;i<n;i++)
        k_min+=t[0][i];


    for (int i=0;i<n;i++){
        k=0;
        w=0;
        for (int j=0;j<n;j++){
            k=k+t[i][j];
            w=w+t[j][i];
        }
        if (w>w_maks){
            w_maks=w;
            w1=i;
        }
        if (k<k_min){
            k_min=k;
            k1=i;
        }
    }

    cout << "ten element tablicy ma wspolrzedne:   " << w1 << "   " << k1<< endl;

    return 0;
}
