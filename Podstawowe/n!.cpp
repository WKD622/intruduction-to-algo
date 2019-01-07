#include<stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

int main (){

    long long int m=1,n,i,j,lp=0,ld=0;
    cout << "Podaj n dla ktorego chcesz wyliczyc n!: ";
    cin >> n;

    for (i=1;i<=n;i++){
        j=i;
        while (j%2==0){
            ld=ld+1;
            j=j/2;
        }
        while (j%5==0){
            lp=lp+1;
            j=j/5;
        }

        m=m%10*j;

    }

    for (i=1;i<=(ld-lp);i++)
        {
        m=(m*2)%10;
        }

    cout << "Ostatnia cyfra " << n << "! to:" << m%10;



    return 0;
}

