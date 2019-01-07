#include <iostream>

using namespace std;

const int n=10;

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

void sortuj(node *t[n], node *&lista){

    node *b[n];

    for (int i=0; i<n; i++) b[i]=t[i];

    while (lista!=NULL){
        int a=lista->wartosc%10;
        b[a]->next=lista;
        lista=lista->next;
        b[a]=b[a]->next;
    }
    for (int i=0; i<n; i++) b[i]->next=NULL;
}

int main(){
    node *t[n];
    node *lista=NULL;

    for (int i=0; i<n; i++){
        t[i]=new node;
        t[i]->next=NULL;
    }

    utworz(lista,10);
    drukuj(lista);
    sortuj(t,lista);

    for (int i=0; i<n; i++){
        t[i]=t[i]->next;
        drukuj(t[i]);
    }

    /*node *scalony=NULL;
    scalony=new node;
    scalony->next=t[0];

    for (int i=0; i<10; i++){
        while(t[i]->next!=NULL) t[i]=t[i]->next;

        int k=i;

        if(t[i+1] != NULL){
            t[i]->next=t[i+1];
            }
            else if(t[i+1] == NULL){
                i++;
                while(t[i+1] == NULL) i++;
                t[k]->next=t[i+1];
            }
    }
    while (t[9]->next!=NULL) t[9]=t[9]->next;


    cout << endl << "SCALONY:" << endl;
    drukuj(scalony->next);
*/
    return 0;
}
