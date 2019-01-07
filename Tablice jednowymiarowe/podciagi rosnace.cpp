#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=100;
int t[n];
int r1,r2,r3,l=1,maks=0;

void randomize(){
    srand(time(NULL));
    for (int i=0; i<n; i++)
        t[i]=rand()%10+1;
}

void wypisz(){
    for (int i=0; i<n; i++)
        cout << t[i] << " ";
        cout << endl;
}

int main(){
    randomize();
    wypisz();

    r3=t[1]-t[0];
    for (int i=0;i<n/2;i++)
        if (t[i]==t[n-i-1])
            if (t[i+1]==t[n-i-2]){
                r1=t[i+1]-t[i];
                r2=t[n-i-2]-t[n-i-1];
                if (r1==r2 and r1==r3 and r2==r3){
                    r3=r1;
                    l++;
                }
                if (r1!=r2 or r1!=r3 or r2!=r3){
                    if (l>maks){
                        maks=l;
                        l=0;
                    }
                }
            }
    cout << endl << maks;
    return 0;
}
