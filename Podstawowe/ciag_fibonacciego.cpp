#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=3;
int mala1=0, mala2=0, t[3]={1,0};

void szukaj( int t[n], int sumai, int sumal, int k, int l){
    for (int i=k;i<n;i++){
        sumal+=t[i];
        sumai+=i;
        if (sumal==sumai && l>=2){
                cout << "jest!!!" << endl;
                l++;
        }
        szukaj(t,k+1,sumai,sumal,l);
    }
    l=1;
}

int main(){
    szukaj(t,0,0,0,1);
    return 0;
}
