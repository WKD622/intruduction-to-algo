/*Proszê napisaæ funkcjê sprawdzaj¹c¹ czy dwa goñce, których wspó³rzêdne
przekazano do funkcji szachuj¹ siê wzajemnie. Wskazówka: jaka zale¿noœæ
zachodzi pomiêdzy wspó³rzêdnymi pól nale¿¹cych do jednej przek¹tnej.
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=8;
int t[n][n];

bool czy_szachuja(int x1, int y1, int k, int w, int x2, int y2){
    int kk=x1+k;
    int wk=y1+w;
    if (kk == x2 and wk == y2) return true;
    else return false;
}

bool gonce(int x1, int y1, int x2, int y2){
    int tabk[8]={1,2,2,1,-1,-2,-2,-1};
    int tabw[8]={2,1,-1,-2,-2,-1,1,2};
    for (int i=0; i<n; i++){
        if (czy_szachuja(x1,y1,tabk[i],tabw[i],x2,y2)) return true;
    }
}

void wypelnij(){
    srand(time(0));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            t[i][j]=rand()%15+1;
}

int main(){
    int x1,y1,x2,y2;

    wypelnij();
    cout << "Podaj wspolrzedne pierwszego gonca: " << endl << "x1: ";
    cin >> x1;
    cout << "y1: ";
    cin >> y1;

    cout << "Podaj wspolrzedne drugiego gonca: " << endl << "x2: ";
    cin >> x2;
    cout << "y2: ";
    cin >> y2;

    if (gonce(x1,y1,x2,y2)) cout << "TAK";
        else cout << "NIE";

    return 0;
}
