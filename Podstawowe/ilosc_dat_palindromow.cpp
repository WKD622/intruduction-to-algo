#include <iostream>
#include <math.h>

using namespace std;

const int r=2016;
int ru,mu,du,data1,kopia,rewers,i,j,k;

int main (){

cout << "Podaj rok swojego urodzenia: (4 cyfrowy)" << endl;
cin >> ru;

cout << "Podaj miesiac swojego urodzenia:" << endl;
cin >> mu;

cout << "Podaj dzien swojego urodzenia:" << endl;
cin >> du;

cout << "Od twojego urodzenia nastepujace daty byly palindoramami:" <<endl;


    for (j=mu;j<=12;j++){
        for (k=du;k<=31;k++){
            data1=ru*10000+j*100+k;

            //sprawdzanie rewersu

            kopia=data1;
            rewers=0;
            while (kopia>0){
                rewers=rewers*10+kopia%10;
                kopia=kopia/10;
            }
            if (rewers==data1) cout << data1 << endl;
        }
    }

for (i=ru+1;i<=r;i++){
    for (j=1;j<=12;j++){
        for (k=1;k<=31;k++){
            data1=i*10000+j*100+k;

            //sprawdzanie rewersu

            kopia=data1;
            rewers=0;
            while (kopia>0){
                rewers=rewers*10+kopia%10;
                kopia=kopia/10;
            }
            if (rewers==data1) cout << data1 << endl;
        }
    }
}






return 0;
}
