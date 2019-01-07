/*Dany jest typ szachownica=array[1..8,1..8] of integer. Stoj¹ce na
szachownicy figury oznaczone s¹ liczbami ca³kowitymi np. bia³a wie¿a to 5,
a czarna –5, itd. Proszê napisaæ funkcjê, która sprawdza czy jakiekolwiek
wie¿e szachuj¹ siê wzajemnie.*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=4;
int t[n][n];

void wypelnij(){
    srand(time(0));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            t[i][j]=rand()%13-7;
}

bool wieze(int x, int y){
    bool p=false;
    if (p==false)
        for (int i=0; i<n; i++){
            if (i!=x)
                if (t[i][y]==5 or t[i][y]==(-5)) p=true;
            if (i!=y)
                if (t[x][i]==5 or t[x][i]==(-5)) p=true;


        }
        if (p==true){return true;}
        else return false;
}

void drukuj(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    wypelnij();
    drukuj();
    bool k=false;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (t[i][j]==5 or t[i][j]==-5) if (wieze(i,j))k=true;

    if (k) cout << "TAK";
    else cout << "NIE";

}
