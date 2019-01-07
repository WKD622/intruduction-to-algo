/*1. Na szachownicy o wymiarach 201 wierszy i 201 kolumn umieszczono pewn� liczb� wie�
szachowych tak, �e ka�de z p�l na jest szachowane. Przyszed� z�y cz�owiek i zmieni� po�o�enie jednej z
wie� na szachownicy, tak �e nie wszystkie pola s� szachowane. Prosz� zaproponowa� funkcj�, kt�ra
znajdzie przeniesienie jednej wie�y tak aby ponownie wszystkie pola by�y szachowane. Do funkcji
przekazujemy tablic� bool t[201][201] z uk�adem wie� po zmianie, funkcja powinna wyznaczy� i
zwr�ci� dwa pola (wiersz, kolumna) � sk�d , dok�d nale�y przenie�� wie��.
*/
// 0 - pola puste, nieszachowane
// 1,2,3... - pola na ktorych stoi wieza n
// -1 - pola szachowane.

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

const int n=15;
int t[n][n];

void zeruj(){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            t[i][j]=0;
}

void wypisz(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
        cout.width(5);
        cout << t[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void szachuj(int w, int k, int c){
    for (int i=0; i<n; i++){
        if (t[w][i]==0) t[w][i]=c+1000;
        if (t[i][k]==0) t[i][k]=c+1000;
    }
    t[w][k]=c;
}

bool sprawdz(int w, int k){
    if (t[w][k]==0) return false;
    else return true;
}

void wypelnij(){
    srand(time(NULL));
    int c=1, p,w,k;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (sprawdz(i,j)==false){
                p=rand()%2;
                if (p==1){
                    w=rand()%n;
                    szachuj(w,j,c);
                    c++;
                }else{
                    k=rand()%n;
                    szachuj(i,k,c);
                    c++;
                }
            system ("cls");
            wypisz();
            getch();
            }

}

int main(){
    zeruj();
    wypisz();
    wypelnij();
    return 0;
}
