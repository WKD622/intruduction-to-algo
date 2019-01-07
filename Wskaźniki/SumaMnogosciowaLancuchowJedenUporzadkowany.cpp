/*Dany jest ³añcuch zbudowany w oparciu o elementy typu:
pnode = ^ node;
node = record
val : integer;
next : pnode;
end;
Dane s¹ dwa niepuste ³añcuchy, z których ka¿dy zawiera niepowtarzaj¹ce siê elementy. Elementy w pierwszym ³añcuchu s¹ uporz¹dkowane rosn¹co, w drugim elementy wystêpuj¹ w przypadkowej kolejnoœci.
Proszê napisaæ procedurê, która z dwóch takich ³añcuchów stworzy jeden, w którym uporz¹dkowane elementy bêd¹ stanowiæ sumê mnogoœciow¹ elementów z ³añcuchów wejœciowych.
Do procedury nale¿y przekazaæ wskazania na oba ³añcuchy.
Na przyk³ad dla ³añcuchów:
2 -> 3 -> 5 ->7-> 11
8 -> 2 -> 7 -> 4
powinien pozostaæ ³añcuch:
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
