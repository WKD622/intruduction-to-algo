#include <iostream>

using namespace std;

struct node{
    int w;
    node *next;
};

node *lista1=new node;
node *lista2=new node;
node *wartownik1=lista1;
node *wartownik2=lista2;

void tworz(node *&poczatek, int d){
    node *aktualny=NULL;
    node *poprzedni=NULL;
    int l;
    for (int i=0; i<d; i++){
        aktualny=new node;
        cin >> l;
        aktualny->w=l;
        aktualny->next=poprzedni;
        poprzedni=aktualny;
    }
    poczatek=aktualny;
}

void drukuj(node *poczatek){
    while(poczatek!=NULL){
        cout << poczatek->w << " ";
        poczatek=poczatek->next;
    }
    cout << endl;
}

void rozdziel(node *poczatek){
    while(poczatek!=NULL){
        if (poczatek->w%3 == 1){
            lista1->next=poczatek;
            lista1=lista1->next;
            poczatek=poczatek->next;
            lista1->next=NULL;
        }
            else if (poczatek->w%3 == 2){
                lista2->next=poczatek;
                lista2=lista2->next;
                poczatek=poczatek->next;
                lista2->next=NULL;
            }
                else {
                    node *pom=poczatek;
                    poczatek=poczatek->next;
                    delete pom;
                }
    }
}

int main(){
    int d;
    cout << "podaj dlugosc listy:" << endl;
    cin >> d;
    node *lista=NULL;
    cout << "podaj elementy listy:" << endl;
    tworz(lista,d);
    cout << "stworzyles liste:" << endl;
    drukuj(lista);
    rozdziel(lista);
    cout << "lista 1:" << endl;
    drukuj(wartownik1->next);
    cout << "lista 2:" << endl;
    drukuj(wartownik2->next);

    delete wartownik1;
    delete wartownik2;
    return 0;
}
