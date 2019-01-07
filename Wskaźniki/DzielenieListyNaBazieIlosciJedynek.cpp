/*(kartkówki 2011/2012)
Dana jest lista jednokierunkowa zawieraj¹ca liczby ca³kowite.
Liczbê oznaczamy jako niskobitow¹, jeœli w reprezentacji binarnej liczba jedynek jest mniejsza ni¿ 8, œredniobitow¹, gdy liczba jedynek pomiêdzy 8 a 24, wysokobitow¹, gdy liczba jedynek przekracza 24.
Napisaæ funkcjê, która podzieli listê na trzy listy z liczbami nisko, œrednio i wysokobitowymi, a nastêpnie z³¹czy te listy w jedn¹.

*/

#include <iostream>

using namespace std;

struct node{
    long long int wartosc;
    node *next;
};

void tworz(node *&poczatek, int d){
    node *aktualny=NULL;
    node *poprzedni=NULL;
    int liczba;
    for (int i=0; i<d; i++){
        aktualny=new node;
        cin >> liczba;
        aktualny->wartosc=liczba;
        aktualny->next=poprzedni;
        poprzedni=aktualny;
    }
    poczatek=aktualny;
}

void drukuj(node *poczatek){
    while (poczatek!=NULL){
        cout << poczatek->wartosc << " ";
        poczatek=poczatek->next;
    }
    cout << endl;
}

int liczba_jedynek(int liczba){
    int liczba_j=0;
    while (liczba != 0){
        if (liczba%2 == 1){
            liczba=liczba/2;
            liczba_j++;
        }
        else {liczba=liczba/2;}
    }
    return liczba_j;
}

void dziel(node *poczatek, node *&niskobitowa, node *&sredniobitowa, node *&wysokobitowa){
    niskobitowa->next=NULL;
    sredniobitowa->next=NULL;
    wysokobitowa->next=NULL;
    while (poczatek!=NULL){
        if (liczba_jedynek(poczatek->wartosc) < 8){
            niskobitowa->next=poczatek;
            poczatek=poczatek->next;
            niskobitowa=niskobitowa->next;
            niskobitowa->next=NULL;
        }
            else if (liczba_jedynek(poczatek->wartosc) >= 8 and liczba_jedynek(poczatek->wartosc) <= 24){
                sredniobitowa->next=poczatek;
                poczatek=poczatek->next;
                sredniobitowa=sredniobitowa->next;
                sredniobitowa->next=NULL;
            }
                else{
                    wysokobitowa->next=poczatek;
                    poczatek=poczatek->next;
                    wysokobitowa=wysokobitowa->next;
                    wysokobitowa->next=NULL;
                }
    }
}

int main(){
    int d;
    node *lista=NULL;
    node *niskobitowa=new node;
    node *wartownik1=niskobitowa;
    node *sredniobitowa=new node;
    node *wartownik2=sredniobitowa;
    node *wysokobitowa=new node;
    node *wartownik3=wysokobitowa;

    cout << "podaj dlugosc listy:" << endl;
    cin >> d;
    cout << "podaj elementy listy:" << endl;
    tworz(lista,d);
    cout << "lista, ktora utworzyles:" << endl;
    drukuj(lista);
    dziel(lista,niskobitowa,sredniobitowa,wysokobitowa);
    cout << "<8:" << endl;
    drukuj(wartownik1->next);
    cout << "(8,24):" << endl;
    drukuj(wartownik2->next);
    cout << "24<" << endl;
    drukuj(wartownik3->next);

    delete wartownik1;
    delete wartownik2;
    delete wartownik3;

    return 0;
}
