/*1. Na szachownicy o wymiarach 201 wierszy i 201 kolumn umieszczono pewn¹ liczbê wie¿
szachowych tak, ¿e ka¿de z pól na jest szachowane. Przyszed³ z³y cz³owiek i zmieni³ po³o¿enie jednej z
wie¿ na szachownicy, tak ¿e nie wszystkie pola s¹ szachowane. Proszê zaproponowaæ funkcjê, która
znajdzie przeniesienie jednej wie¿y tak aby ponownie wszystkie pola by³y szachowane. Do funkcji
przekazujemy tablicê bool t[201][201] z uk³adem wie¿ po zmianie, funkcja powinna wyznaczyæ i
zwróciæ dwa pola (wiersz, kolumna) – sk¹d , dok¹d nale¿y przenieœæ wie¿ê.
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
