#include <iostream>

using namespace std;

struct node{
    int x;
    int y;
    node *next;
};

void tworz(node *&poczatek, int d){
    node *aktualny=NULL;
    node *poprzedni=NULL;
    int wspolrzedna1;
    int wspolrzedna2;

    for (int i=0; i<d; i++){
        aktualny=new node;
        cout << "PUNKT " << i+1 << endl;
        cout << "Podaj 1sza wspolrzedna: ";
        cin >> wspolrzedna1;
        aktualny -> x = wspolrzedna1;
        cout << "Podaj 2ga wspolrzedna: ";
        cin >> wspolrzedna2;
        aktualny -> y = wspolrzedna2;

        cout << endl;
        aktualny->next=poprzedni;
        poprzedni=aktualny;
    }

    poczatek=aktualny;
}

void drukuj(node *poczatek){
    while (poczatek!=NULL){
        cout << "("<< poczatek->x << "," << poczatek->y << ")  ";
        poczatek=poczatek->next;
    }
    cout << endl;
}

void dziel(node *poczatek, node *&pierwsza, node *&druga, node *&trzecia, node *&czwarta){

    while(poczatek != NULL){
        if (poczatek->x==0 or poczatek->y==0){ //wspolrzedne nalezace do osi X lub osi Y
            node *pom=poczatek;
            poczatek=poczatek->next;
            delete pom;
        }
            else if (poczatek->x > 0 and poczatek->y > 0){ //pierwsza cwiartka
                pierwsza->next=poczatek;
                poczatek=poczatek->next;
                pierwsza=pierwsza->next;
                pierwsza->next=NULL;
            }
                else if (poczatek->x < 0 and poczatek->y > 0){ //druga cwiartka
                    druga->next=poczatek;
                    poczatek=poczatek->next;
                    druga=druga->next;
                    druga->next=NULL;
                }
                    else if (poczatek->x < 0 and poczatek->y < 0){ //trzecia cwiartka
                        trzecia->next=poczatek;
                        poczatek=poczatek->next;
                        trzecia=trzecia->next;
                        trzecia->next=NULL;
                    }
                        else { //czwarta cwiartka
                            czwarta->next=poczatek;
                            poczatek=poczatek->next;
                            czwarta=czwarta->next;
                            czwarta->next=NULL;
                        }
    }
}

int main(){
    int d;
    node *lista=NULL;

    node *pierwsza=new node;
    node *wartownik1=pierwsza;
    node *druga=new node;
    node *wartownik2=druga;
    node *trzecia=new node;
    node *wartownik3=trzecia;
    node *czwarta=new node;
    node *wartownik4=czwarta;

    cout << "Podaj dlugosc listy: ";
    cin >> d;
    cout << endl << "Podaj elementy lancucha wspolrzednych:" << endl;
    tworz(lista,d);
    cout << "Twoja lista:" << endl;
    drukuj(lista);

    dziel(lista,pierwsza,druga,trzecia,czwarta);

    cout << endl << "pierwsza cwiartka: " << endl;
    drukuj (wartownik1->next);
    cout << "druga cwiartka: " << endl;
    drukuj (wartownik2->next);
    cout << "trzecia cwiartka: " << endl;
    drukuj (wartownik3->next);
    cout << "czwarta cwiartka: " << endl;
    drukuj (wartownik4->next);

    delete wartownik1;
    delete wartownik2;
    delete wartownik3;
    delete wartownik4;

    return 0;
}
