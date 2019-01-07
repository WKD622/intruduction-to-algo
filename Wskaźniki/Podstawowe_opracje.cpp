#include <iostream>

using namespace std;

struct node{
    int wartosc;
    node*next;
};

void tworz(node* &poczatek, int dlugosc){
    int element;
    node *aktualny = NULL;
    node *nastepny = NULL;
    for (int i=0; i<dlugosc; i++){
        aktualny = new node;
        cin >> element;
        aktualny->wartosc=element; /*(*aktualny).wartosc=element;*/
        aktualny->next=nastepny;
        nastepny=aktualny;

    }
    poczatek=aktualny;
}

void dodaj_na_koniec (node* &poczatek){
    int element;
    cin >> element;
    node* tmp=poczatek;
    node* nowy=NULL;
    while (tmp->next!=NULL){
        tmp=tmp->next;
    }
    nowy = new node;
    tmp -> next = nowy;
    nowy->wartosc=element;
    nowy->next=NULL;
}

void usun(node* &poczatek, int element){

    if (poczatek->wartosc == element){
        node*tmp=poczatek;
        poczatek=poczatek->next;
        delete tmp;
        return;
    }

    node*aktualny = NULL;
    node*poprzedni = poczatek;

    while(poprzedni->next->wartosc!=element){
        poprzedni=poprzedni->next;
    }
    aktualny=poprzedni->next;
    poprzedni->next=aktualny->next;
    delete aktualny;
}

void drukuj(node *kopia){
    while (kopia!=NULL){
        cout << kopia->wartosc << " ";
        kopia=kopia->next;
    }
}

void odwroc(node *&poczatek){
    node *nowy=NULL;
    node *pomocniczy=NULL;
    while (poczatek!=NULL)
    {
        nowy=poczatek;
        poczatek = poczatek -> next;
        nowy -> next = pomocniczy;
        pomocniczy = nowy;
    }
    poczatek = nowy;
}

node *suma(node *poczatek1, node *poczatek2){
    node *scalona= new node;
    node *wartownik=scalona;

    while (poczatek1!=NULL and poczatek2!=NULL){
        if(poczatek1->wartosc < poczatek2->wartosc){
            scalona->next=poczatek1;
            scalona=poczatek1;
            poczatek1=poczatek1->next;
            scalona->next=NULL;
        }else
            if(poczatek1->wartosc == poczatek2->wartosc) poczatek2=poczatek2->next;
            else{
                scalona->next=poczatek2;
                scalona=poczatek2;
                poczatek2=poczatek2->next;
                scalona->next=NULL;
            }
    }
    if (poczatek1!=NULL)scalona->next=poczatek1;
    scalona=wartownik->next;
    delete wartownik;
    return scalona;
}

node *iloczyn(node *poczatek1, node *poczatek2){
    node *wspolna=new node;
    node *wartownik=wspolna;

    while(poczatek1 != NULL and poczatek2 != NULL){
        if (poczatek1->wartosc < poczatek2->wartosc) poczatek1=poczatek1->next;
            else if (poczatek2->wartosc < poczatek1->wartosc) poczatek2=poczatek2->next;
                else if (poczatek1->wartosc == poczatek2->wartosc){
                    wspolna->next=poczatek1;
                    wspolna=poczatek1;
                    poczatek1=poczatek1->next;
                    wspolna->next=NULL;
                }
    }
    wspolna=wartownik->next;
    delete wartownik;
    return wspolna;
}

node *roznica(node *poczatek1, node *poczatek2){ //od poczatek1 odejmuje poczatek2
    node *wynikowa=new node;
    node *wartownik=wynikowa;

    while (poczatek1!=NULL and poczatek2!=NULL){
        if (poczatek1->wartosc < poczatek2->wartosc){
            wynikowa->next=poczatek1;
            wynikowa=wynikowa->next;
            poczatek1=poczatek1->next;
            wynikowa->next=NULL;
        }
            else if (poczatek2->wartosc < poczatek1->wartosc) poczatek2=poczatek2->next;
                else if (poczatek2->wartosc == poczatek1->wartosc){
                    poczatek1=poczatek1->next;
                    poczatek2=poczatek2->next;
                }
    }
    wynikowa->next=poczatek1;
    wynikowa=wartownik->next;
    delete wartownik;
    return wynikowa;
}

int main(){

    node *lista1 = NULL;
    node *lista2 = NULL;
    cout << "tworz liste 1:" << endl;
    tworz(lista1,3);
    cout << "tworz liste 2:" << endl;
    tworz(lista2,2);
    cout <<"LISTA 1:" << endl;
    drukuj(lista1);
    cout << endl <<"LISTA 2:" << endl;
    drukuj(lista2);
    cout << endl << "wynik dzialania:" << endl;
    suma(lista1,lista2);
    cout << endl;
    drukuj(lista1);
    cout << endl;
    drukuj(lista2);
 /* usun(lista,3);
    drukuj(lista);
    cout << endl;
    dodaj_na_koniec(lista);
    drukuj(lista);
    odwroc(lista1);
    node*lista=suma(lista1,lista2);
    node*lista=iloczyn(lista1, lista2); */

    node*lista=roznica(lista1, lista2);
    drukuj(lista);
    return 0;
}
