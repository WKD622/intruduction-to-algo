#include <iostream>

using namespace std;

struct node{
    int wartosc;
    node *next;
};

bool piatki(int liczba){
    int ilosc_p=0;
    while(liczba!=0){
        if (liczba%8==5){
            ilosc_p++;
            liczba=liczba/8;
        }
        else liczba=liczba/8;
    }
    if (ilosc_p%2==1) return true;
}

void drukuj(node *poczatek){
    while (poczatek != NULL){
        cout << poczatek->wartosc << " ";
        poczatek=poczatek->next;
    }
}

void tworz(node *&poczatek, int d){
    node *poprzedni=NULL;
    node *aktualny=NULL;
    int element;
    for (int i=0; i<d; i++){
        aktualny = new node;
        cin >> element;
        aktualny -> wartosc = element;
        aktualny -> next = poprzedni;
        poprzedni = aktualny;
    }
    poczatek=aktualny;
}

node *przenies(node *&poczatek){
    node *wartownik=poczatek;
    node *poprzedni=poczatek;
    poczatek=poczatek->next;

    while(poczatek!=NULL){
        if (piatki(poczatek->wartosc)){
            poprzedni->next=poczatek->next;
            poczatek->next=wartownik;
            wartownik=poczatek;
            poczatek=poprzedni->next;
        }
            else {
                poczatek=poczatek->next;
                poprzedni=poprzedni->next;
            }
    }
    poczatek=wartownik;
    wartownik=NULL;
    poprzedni=NULL;
    delete wartownik;
    delete poprzedni;
    return poczatek;
}

int main(){
    int d;
    node *lista=NULL;

    cout << "Podaj dlugosc listy: ";
    cin >> d;
    cout << "Podaj elementy listy:" << endl;
    tworz(lista,d);
    cout << endl << "Lista, ktora stworzyles:" << endl;
    drukuj (lista);
    cout << endl << "Lista ktore ma na poczatku liczby ktore w system osemkowym maja nieparzysta liczbe piatek:" << endl;
    drukuj(przenies(lista));

    return 0;
}
