#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <fstream>

using namespace std;
int main()
{
   int n,i=0,j=0,iloczyn=1;
   cout << "Podaj liczbe:" << endl;
   cin >> n;

    while(n!=4 && n!=2 && n!=0){
        n-=3;
        i++;
    }
    while(n!=0){
        n-=2;
        j++;
    }

    for(int k=0; k<i ;k++){
        cout << 3 <<"*";
        iloczyn=iloczyn*3;
    }
    for(int k=0; k<j; k++){
        cout << 2 <<"*";
        iloczyn=iloczyn*2;
    }
    cout << "=" << iloczyn;
return 0;
}
