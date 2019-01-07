#include <iostream>
#include <time.h>
#include <cstdlib>1

using namespace std;

const int n=10;
int t[n],p;

bool znajdz(int p, int i, int k){
    if (i==p) cout << "jest";
    else if (k<n){
        znajdz(p,i*t[k],k+1);
        znajdz(p,i,k+1);
    }
}

int main(){
    srand(time(NULL));
    for (int i=0;i<n;i++){
        t[i]=rand()%12;
        cout << t[i] << " ";
    }

    cout << "Podaj p:" << endl;
    cin >> p;

    znajdz(p,1,0);







    return 0;

}

