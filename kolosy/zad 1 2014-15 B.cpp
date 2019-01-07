#include <iostream>

using namespace std;

int main(){

    const int n=30;
    int a,b,c,d,e,k=0,f=1,i;
    int t[n];

    for (i=0;i<n;i++)
        t[i]=0;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;

    if (a==(b+c+d+e)/4){
        t[k]=a;
        k++;
    }

    if(b==(a+c+d+e)/4){
        t[k]=b;
        k++;
    }

    while (f!=0){
        cin >> f;
        if (f!=0){
            if(c==(a+b+d+e)/4){
                t[k]=c;
                k++;
            }
            a=b;
            b=c;
            c=d;
            d=e;
            e=f;
        }
        if(f==0){
            if(c==(a+b+d+e)/4){
                t[k]=c;
                k++;
            }
            if(d==(a+b+c+e)/4){
                t[k]=d;
                k++;
            }
            if(e==(a+b+c+d)/4){
                t[k]=e;
                k++;
            }
        }
    }

    for(i=0;i<n;i++)
        if (t[i]!=0) cout << t[i];

    return 0;
}
