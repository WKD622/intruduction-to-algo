/*Dany jest �a�cuch zbudowany w oparciu o elementy typu:
pnode = ^ node;
node = record
val : integer;
next : pnode;
end;
Dane s� dwa niepuste �a�cuchy, z kt�rych ka�dy zawiera niepowtarzaj�ce si� elementy. Elementy w pierwszym �a�cuchu s� uporz�dkowane rosn�co, w drugim elementy wyst�puj� w przypadkowej kolejno�ci.
Prosz� napisa� procedur�, kt�ra z dw�ch takich �a�cuch�w stworzy jeden, w kt�rym uporz�dkowane elementy b�d� stanowi� sum� mnogo�ciow� element�w z �a�cuch�w wej�ciowych.
Do procedury nale�y przekaza� wskazania na oba �a�cuchy.
Na przyk�ad dla �a�cuch�w:
2 -> 3 -> 5 ->7-> 11
8 -> 2 -> 7 -> 4
powinien pozosta� �a�cuch:
2 -> 3 -> 4 -> 5 ->7-> 8 -> 11*/

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

node *suma_mnogosciowa(node *poczatek1, node *poczatek2){ //wstawiam poczatek2 do poczatek1
    node *wstawiana=NULL;
    node *wartownik=new node;
    wartownik->next=poczatek1;
    node *pom=NULL;

    while(poczatek2 != NULL){
        pom=wartownik;
        poczatek1=wartownik->next;
        wstawiana=odklej_z_poczatku(poczatek2);
        while (wstawiana->wartosc > poczatek1->wartosc ){
            poczatek1=poczatek1->next;
            pom=pom->next;
        }
        if (poczatek1->wartosc > wstawiana->wartosc){
            pom->next=wstawiana;
            wstawiana->next=poczatek1;
        }
    }
    poczatek1=wartownik->next;
    delete wartownik;
    return poczatek1;
}

int main(){

    node *lista1=NULL;
    node *lista2=NULL;
    cout << "tworz lista 1:" << endl;
    utworz(lista1,4);
    cout << "lista 1: " << endl;
    drukuj(lista1);
    cout << "tworz lista 2:" << endl;
    utworz(lista2,3);
    cout << "lista 2: " << endl;
    drukuj(lista2);
    cout << "suma mnogosciowa " << endl;
    drukuj(suma_mnogosciowa(lista1, lista2));

}
