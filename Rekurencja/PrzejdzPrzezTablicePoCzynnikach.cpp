#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int n=10;
int t[]={1,2,5,3,3,3,1,2,9,9};

bool mozna(int p){
    int a;
    if (p==n-1){
        cout << "mozna";
        return true;

    }
    else if (p<n-1){
        a=t[p];
        cout << "lala: " << a << endl;
        if (a==1) mozna(p+1);
        else while (a!=1){
                cout << a << endl;
            for (int i=2;i<=a;i++){
                if (a%i==0){
                    while (a%i==0){
                        a=a/i;
                    }
                   mozna(p+i);
                }
            }
        }
    }
}


int main(){
    srand(time(NULL));
    /*for (int i=0;i<n;i++){
        t[i]=rand()%15+1;
    }*/
    mozna(0);












return 0;

}
