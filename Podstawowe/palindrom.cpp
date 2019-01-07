#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    int k,n,p=0;

    cin >> n;
    k=n;
    while (k>0){
        p=p*10+k%10;
        k=k/10;
    }

    if (n==p) cout << "TAK";
    else cout << "NIE";

return 0;
}

