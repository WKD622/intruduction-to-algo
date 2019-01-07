#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct node{
    int w;
    node *next;
};

void tworz(node *&poczatek, int d){
    node *aktualny=NULL;
    node *poprzedni=NULL;
    int l;

    for(int i=0; i<d; i++){
        aktualny=new node;
        cin >> l;
        aktualny->w=l;
        aktualny->next=poprzedni;
        poprzedni=aktualny;
    }
    poczatek=aktualny;
}

void drukuj(node *poczatek){
    while (poczatek!=NULL){
        cout << poczatek->w << " ";
        poczatek=poczatek->next;
    }
}

node *sym(node* poczatek1, node *poczatek2){
    node *wynikowy=new node;
    node *wartownik=wynikowy;

    while (poczatek1!=NULL and poczatek2!=NULL){
        if (poczatek1->w < poczatek2->w){
            wynikowy->next=poczatek1;
            wynikowy=poczatek1;
            poczatek1=poczatek1->next;
            wynikowy->next=NULL;
        }
        else if (poczatek2->w < poczatek1->w){
                wynikowy->next=poczatek2;
                wynikowy=poczatek2;
                poczatek2=poczatek2->next;
                wynikowy->next=NULL;
        }
        else if (poczatek1->w == poczatek2->w){
                poczatek1=poczatek1->next;
                poczatek2=poczatek2->next;
        }
    }
    if (poczatek2 != NULL) wynikowy->next=poczatek2;
    while (wynikowy->next != NULL) wynikowy=wynikowy->next;
    if (poczatek1 != NULL) wynikowy->next=poczatek1;

    wynikowy=wartownik->next;
    delete wartownik;
    return wynikowy;
}

int main(){

    node *lista1;
    node *lista2;
    cout << "tworzysz liste 1:" << endl;
    tworz(lista1,5);
    cout << endl << "tworzysz liste 2:" << endl;
    tworz(lista2,5);
    cout << endl << "XOR:" << endl;
    drukuj(sym(lista1,lista2));
    return 0;

}
