#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <fstream>

using namespace std;
int main()
{
    int i=0,j,k,a=1;
    cout << "Podaj ile liczb pierwszych" << endl;
    cin >> k;
    while (i<k){
        a++;
        j=2;
        while (j<a && a%j!=0)
            j++;

        if (j==a) {
            cout << a << endl;
            i++;
        }
    }

return 0;
}
