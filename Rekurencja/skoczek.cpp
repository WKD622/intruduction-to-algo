#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

    const int maks=4;
    int t[maks][maks],i,j;

    bool mozna (int w, int k, int i, int&w2, int&k2){
        int dx[]={1,2,2,1,-1,-2,-2,-1};
        int dy[]={2,1,-1,-2,-2,-1,1,2};
        w2=w+dx[i];
        k2=k+dy[i];

        return ((w2>=0) and (k2>=0) and (w2<maks) and (k2<maks) and (t[w2][k2]==0));
    }

    void wypisz (){
        system ( "cls" );
        for (i=0;i<maks;i++){
            for (j=0;j<maks;j++){
                cout.width(2);
                cout << t[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        Sleep (1000);
    }


    void skoczek (int w, int k, int n){
        int w2,k2;
        t[w][k]=n;
        wypisz();
        if (maks*maks==n){
            wypisz();
        }else{
            for (int i=0; i<8; i++){
                if (mozna(w,k,i,w2,k2)) skoczek(w2,k2,n+1);
                } t[w][k]=0;
                 wypisz();
        }
    }

    int main(){

    for (i=0;i<maks;i++)
        for (j=0;j<maks;j++)
            t[i][j]=0;

    skoczek(0,0,1);

    return 0;
    }
