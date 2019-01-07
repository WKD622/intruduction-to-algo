#include <iostream>

using namespace std;

struct node{
    int wartosc;
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

bool czy_w_k_l_p(int liczba){ //sprawdza liczby pierwsze ktorych wielokrotnoscia kwadratu jest dana liczba do 1000

    for (int j=2; j<1001; j++){
        bool czy_pierwsza=true;
        int kopia=j;

        for (int i=2; i<j; i++)
            if (kopia%i==0) czy_pierwsza=false;

        if (czy_pierwsza)
            if (liczba%(j*j)==0) return true;
    }
}

node *dziel(node *poczatek, node *&w_k_l_p, node *&pozostale){ //w_k_l_p - wielokrotonsc kwadaratu liczby pierwszej
    w_k_l_p->next=NULL;
    pozostale->next=NULL;
    while (poczatek != NULL){
        if (czy_w_k_l_p(poczatek->wartosc)){
            w_k_l_p->next=poczatek;
            w_k_l_p=w_k_l_p->next;
            poczatek=poczatek->next;
            w_k_l_p->next=NULL;
        }
            else{
                pozostale->next=poczatek;
                pozostale=pozostale->next;
                poczatek=poczatek->next;
                pozostale->next=NULL;
            }
    }
}

int main(){
    node *lista;
    node *w_k_l_p = new node;
    node *wartownik1 = w_k_l_p;
    node *pozostale = new node;
    node *wartownik2 = pozostale;
    int d;

    cout << "pojda dlugosc lancucha:" << endl;
    cin >> d;

    cout << "podaj elementy lancucha:" << endl;
    tworz(lista,d);

    cout << "lista, ktora stworzyles:" << endl;
    drukuj(lista);

    dziel(lista,w_k_l_p,pozostale);
    cout << "w_k_l_p" << endl;
    drukuj(wartownik1->next);
    cout << "pozostale" << endl;
    drukuj (wartownik2->next);

    delete wartownik1;
    delete wartownik2;

    return 0;
}
