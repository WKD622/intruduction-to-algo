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

    int i,n,b;


    cin >> n;
    b=2;
    while (n>1){
    if (n%b==0){
            cout << b << " ";
            n = n/b;
        }
        else
        b = b+1;
     }

return 0;
}
