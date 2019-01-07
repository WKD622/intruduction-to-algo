#include <iostream>

using namespace std;

int main(){

    const int n=50;
    int licz1[n],licz2[n],w[n];
    int l1,l2,i,pom,p=0;

    cout << "Podaj liczbe 1:" << endl;
    cin >> l1;
    cout << "Pojda liczbe 2:" << endl;
    cin >> l2;

    for (i=0;i<n;i++){
        licz1[i]=0;
        licz2[i]=0;
        w[i]=0;
    }

    for (i=n-1;i>0;i--){
        pom=l1%10;
        l1=l1/10;
        licz1[i]=pom;
        pom=l2%10;
        l2=l2/10;
        licz2[i]=pom;
    }
    for (i=n-1;i>0;i--){
        pom=licz1[i]+licz2[i]+p;
        p=pom/10;
        w[i]=pom%10;
    }

    for (i=0;i<n;i++){
        if (w[i]!=0) cout << w[i] << " ";
    }



    return 0;
}
