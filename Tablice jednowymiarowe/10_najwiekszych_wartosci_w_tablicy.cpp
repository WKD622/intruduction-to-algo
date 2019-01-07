#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int m=10, n=4;
int t1[m],t2[n],maks,mini,k,i;

void randomize(){
    srand(time(NULL));
    for (int i=0;i<m;i++)
        t1[i]=rand()%50+1;
}



int main(){

    randomize();

    for (int i=0;i<n;i++)
        t2[i]=t1[i];

    for (int i=n;i<m;i++){
        mini=t2[0];

        for (int j=1;j<n;j++){     //wartosc minimalna w tablicy 2
            if (t2[j]<mini){
                mini=t2[j];
                k=j;
            }

            if (t1[i]!=t2[j]){
                if (mini<t1[i]){
                    t2[k]=t1[i];
                }
            }
        }
    }

    for (int i=0; i<m; i++)
        cout << t1[i] << " ";
    cout << endl;
    for (int i=0; i<n; i++)
        cout << t2[i] << " ";

    return 0;
}
