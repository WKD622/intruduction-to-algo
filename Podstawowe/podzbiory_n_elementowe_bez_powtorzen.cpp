#include<stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

int dlugosc_liczby(int zbior){

    int dlugosc=0;

    while(zbior!=0){
        zbior=zbior/10;
        dlugosc++;
    }
return dlugosc;

}



int main(){

    int zbior,dlugosc,i,maksb=0,kopia,kopia2,k,l,suma=0,a,b,c,n,j,podzbior,palindrom,h,g;

    cout << "Podaj elementy zbioru:" << endl;
    cin >> zbior;
    cout << "Podaj dlugosc podzbiorow:" << endl;
    cin >> g;

    dlugosc=dlugosc_liczby(zbior); //zwracam dlugosc liczby

    for (i=1;i<=dlugosc;i++){      // licze maksymalna wartosc liczby binarnej o dlugosci liczby zbioru
        maksb=maksb*10+1;
    }

    kopia=maksb;                   //przeliczanie maks z bin na dec
    i=0;

    while (kopia!=0){
        k=kopia%10;
        kopia=kopia/10;
        suma=suma+k*pow(2,i);
        i++;
    }

cout <<endl;
cout << "Podzbiory:" << endl;



    for (j=1;j<=suma;j++){          //porownywanie kolejnych binarnychg i wypisywanie odpowiednich zbiorów
        c=0;
        n=1;
        a=j;
        while (a!=0){
            b=a%2;
            a=a/2;
            c=c+(b*n);
            n=n*10;
        }
    //    cout << "binarna :" <<c << endl;

        kopia2=c;
        h=0;
        while (kopia2!=0){
            k=kopia2%10;
            kopia2=kopia2/10;
            if (k==1) h=h+1;
        }

        if (h==g){
            kopia2=c;
            kopia=zbior;
            podzbior=0;


                while (kopia2!=0){
                    k=kopia2%10;
                    kopia2=kopia2/10;
                    if (k==1){
                            l=kopia%10;
                            kopia=kopia/10;
                            podzbior=podzbior*10+l;
                    }
                    else kopia=kopia/10;

                }

                palindrom=0;
                kopia=podzbior;
                while (kopia>0){
                    palindrom=palindrom*10+kopia%10;
                    kopia=kopia/10;
                }
                cout << palindrom << endl;
        }
    }



    return 0;
}
