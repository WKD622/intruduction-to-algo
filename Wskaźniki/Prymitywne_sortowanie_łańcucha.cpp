#include <iostream>

using namespace std;

struct node{
    int wartosc;
    node *next;
};

void utworz(node *&poczatek, int d){
    node *aktualny=NULL;
    node *poprzedni=NULL;
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

void drukuj(node *poczatek){
    while (poczatek!=NULL){
        cout << poczatek->wartosc << " ";
        poczatek=poczatek->next;
    }
    cout << endl;
}

node *odklej_z_poczatku(node *&lancuch){
    node *odklejony_element=new node;
    node *pom=lancuch;

    lancuch = lancuch->next;
    odklejony_element->next=pom;
    pom->next=NULL;
    odklejony_element=odklejony_element->next;

    return odklejony_element;
}

node *sortuj(node *&poczatek){
    node *wstawiany=NULL;
    node *posortowany=NULL;
    node *pom=NULL;
    node *wartownik=new node;

    posortowany=odklej_z_poczatku(poczatek);
    wartownik->next=posortowany;
    posortowany->next=NULL;

    while(poczatek != NULL){
        pom=wartownik;
        posortowany=wartownik->next;
        wstawiany=odklej_z_poczatku(poczatek);
        wstawiany->next=NULL;
        while (posortowany!=NULL and wstawiany->wartosc > posortowany->wartosc){
            posortowany=posortowany->next;
            pom=pom->next;
        }
        pom->next=wstawiany;
        wstawiany->next=posortowany;
    }
    return wartownik->next;
}

int main(){

    node *lista1=NULL;
    cout << "tworz lista 1:" << endl;
    utworz(lista1,5);
    cout << "lista 1: " << endl;
    drukuj(lista1);

    cout << "posortowany " << endl;
    drukuj(sortuj(lista1));

}

