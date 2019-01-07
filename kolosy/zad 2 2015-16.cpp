#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main (){

    const int n=99;
    int t[n];
    int i,r,p,iloscu=2,iloscd=2,maksu=0,maksd=0;

    srand( time(NULL));

    for (i=0;i<=98;i++){
        t[i]=rand() %98 + 1;
        cout << t[i] << "  ";

    }

    p=t[1]-t[0];
    for (i=1;i<=98;i++){
        r=t[i+1]-t[i];

        if (r==p){
                if(r>0) iloscd++;
                if(r<0) iloscu++;

            if (iloscd>=maksd) maksd=iloscd;
            if (iloscu>=maksu) maksu=iloscu;
        }
        else {iloscd=2; iloscu=2;}

        p=r;
    }

cout << endl;
cout << "dlugosc najdluzszego ciagu dodatniego " << maksd << endl;
cout << "dlugosc najdluzszego ciagu ujemnego " << maksu << endl;




return 0;
}
