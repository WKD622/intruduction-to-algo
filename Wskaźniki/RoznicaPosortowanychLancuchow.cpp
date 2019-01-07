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
        cin >> element;
        aktualny = new node;
        aktualny->wartosc=element;
        aktualny->next=poprzedni;
        poprzedni=aktualny;
    }
    poczatek=aktualny;
}

void drukuj(node *poczatek){
    while(poczatek!=NULL){
        cout << poczatek->wartosc << " ";
        poczatek=poczatek->next;
    }
    cout << endl;
}

void grzmot(node *&poczatek1, node *&poczatek2){
    node *wartownik1=new node;
    wartownik1->next=poczatek1;
    node *wartownik2=new node;
    wartownik2->next=poczatek2;

    node* poprzedni1=wartownik1;
    node* nastepny1=poczatek1;
    node *poprzedni2=wartownik2;
    node *nastepny2=poczatek2;

    while (nastepny1!=NULL and nastepny2!=NULL){

        if(nastepny1->wartosc < nastepny2->wartosc){
            poprzedni1->next=nastepny1->next;
            delete nastepny1;
            nastepny1=poprzedni1->next;
        }
            else if(nastepny2->wartosc < nastepny1->wartosc){
                poprzedni2->next=nastepny2->next;
                delete nastepny2;
                nastepny2=poprzedni2->next;
            }
                else{
                    poprzedni1=nastepny1;
                    nastepny1=nastepny1->next;
                    poprzedni2=nastepny2;
                    nastepny2=nastepny2->next;
                }
    }

    if (nastepny1!=NULL){
        node *pom=NULL;
        while (nastepny1!=pom){
            pom=nastepny1;
            while (pom->next!=NULL) pom=pom->next;
            delete pom;
        }
        poprzedni1->next=NULL;
    }
    if (nastepny2!=NULL){
        node *pom=NULL;
        while (nastepny2!=pom){
            pom=nastepny2;
            while (pom->next!=NULL) pom=pom->next;
            delete pom;
        }
        poprzedni2->next=NULL;

    }
    poczatek1=wartownik1->next;
    poczatek2=wartownik2->next;
    delete wartownik1;
    delete wartownik2;
}

int main(){
    node *lista1=NULL;
    node *lista2=NULL;

    utworz(lista1,4);
    utworz(lista2,3);

    drukuj(lista1);
    drukuj(lista2);

    grzmot(lista1,lista2);

    drukuj(lista1);
    drukuj(lista2);

    return 0;
}
