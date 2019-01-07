#include <iostream>
using namespace std;


int main(){

    const int n=10;
    int i,w,m,mi,q;
    int t[n];

    for (i=0;i<n;i++){
        cin >> t[i];
        }

    w=1;

    while (w!=0){
        cin >> w;

        if (w!=0){
            m=t[0];
            mi=0;
            for (i=1;i<n;i++)
            if (t[i]<m){
                mi=i;
                m=t[i];
            }
            if (w>t[mi]) t[mi]=w;
        }
    }

    m=t[0];
    for (i=0;i<n;i++)
            if (t[i]<m){
                m=t[i];
            }

cout << "ta wartosc " << m;

    return 0;
}
