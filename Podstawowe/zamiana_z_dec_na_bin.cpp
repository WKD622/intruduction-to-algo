#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
int a,b,c=0,n=1;

cout <<  "Podaj a" << endl;
cin >> a;

while (a!=0)
    {
      b=a%2;
      a=a/2;
      c=c+(b*n);
      n=n*10;
    }

cout << "\nPoszukiwana wartosc:" << c;

return 0;
}


