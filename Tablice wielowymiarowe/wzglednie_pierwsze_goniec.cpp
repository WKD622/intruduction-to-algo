/*Dana jest du¿a tablica typu tab=array [1..max, 1..max] of integer
wype³niona liczbami naturalnymi. Proszê napisaæ funkcjê, która sprawdza czy
w tablicy istniej¹ dwa elementy odleg³e o jeden ruch skoczka szachowego,
których wartoœci s¹ liczbami wzglêdnie pierwszymi.
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=8;
int t[n][n];

bool wzglednie_pierwsze(int a, int b){
    if ((a>0 and b>1) or (a>1 and b>0)){
        int c;
        while(b != 0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        if (a==1) return true;
    }
    else return false;
}

bool ruch(int x, int y, int k, int w){
    int kk=x+k;
    int wk=y+w;
    if (kk>0 and kk<8 and wk >0 and wk<8){
        if (wzglednie_pierwsze(t[kk][wk],t[x][y])){
            t[kk][wk]=t[kk][wk]*(-1);
            t[x][y]=t[x][y]*(-1);
            return true;
        }
        else return false;
    }
}

bool skoczek(int x, int y){
    int tabk[8]={1,2,2,1,-1,-2,-2,-1};
    int tabw[8]={2,1,-1,-2,-2,-1,1,2};
    for (int i=0; i<n; i++){
        if (t[x][y]>0){
            if (ruch(x,y,tabk[i],tabw[i])) return true;
        }
    }
}

void wypelnij(){
    srand(time(0));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            t[i][j]=rand()%15+1;
}

int main(){
    wypelnij();
    int licznik=0;
    for (int x=0; x<n; x++)
        for (int y=0; y<n; y++)
            if (skoczek(x,y)) licznik++;

    if (licznik>1) cout << "istnieja!";
}
