#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

const int maks=8;
int t[maks][maks],l=0,w1,k1;

// zeruje szachownice
void zeruj(){
    for (int i=0;i<maks;i++)
        for (int j=0;j<maks;j++)
            t[i][j]=0;
}

// jedynkuje pola ktore s¹ szachowane
void szachuj(int w,int k,int n){
    int i;
    t[w][k]=n;

    for (i=0;i<maks;i++){
        if (t[i][k]==0) t[i][k]=n+10;
        if (t[w][i]==0) t[w][i]=n+10;
    }
    i=0;
    while (w+i<maks && k+i<maks){
        if (t[w+i][k+i]==0) t[w+i][k+i]=n+10;
        i++;
    }

    i=0;
    while (w-i>=0 && k-i>=0){
        if (t[w-i][k-i]==0) t[w-i][k-i]=n+10;
        i++;
    }

    i=0;
    while (w+i<maks && k-i>=0){
        if (t[w+i][k-i]==0) t[w+i][k-i]=n+10;
        i++;
    }

    i=0;
    while (w-i>=0 && k+i<maks){
        if (t[w-i][k+i]==0) t[w-i][k+i]=n+10;
        i++;
    }
}

// wypisuje tablice
void wypisz (){
        system ( "cls" );
        for (int i=0;i<maks;i++){
            for (int j=0;j<maks;j++){
                cout.width(2);
                if (t[i][j]>10) cout << "x" << " ";
                if (t[i][j]<10) cout << t[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    //getch();
}

// ustawia hetmana
void hetman (int w, int k, int n){
    int i,j;
    szachuj(w,k,n);
    //wypisz ();
    if(n==maks)
       {
       cout << "znalazles";
       wypisz();
        t[w][k]=100;
        getch();
        //wypisz(); l++;
        }else{
        for (i=0;i<maks;i++)
            for (j=0;j<maks;j++){
                if(t[i][j]==0) hetman(i,j,n+1);
            }

         for (int i=0;i<maks;i++)
            for (int j=0;j<maks;j++)
                if (t[i][j]==n or t[i][j]==n+10) t[i][j]=0;
      // wypisz ();
        }
}

// glowny program
int main(){
    cout << "szachownica ma rozmiary 8 x 8"<< endl;
    cout << "Podaj wiersz od 0-7" << endl;
    cin >> w1;
    cout << "Podaj kolumne od 0-7" << endl;
    cin >> k1;

    zeruj();
    hetman (w1,k1,1);


    return 0;
}
