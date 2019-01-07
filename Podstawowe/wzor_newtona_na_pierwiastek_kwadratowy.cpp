#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()

{
float s,b,a=1,eps=1e-10;

cout << "Wprowadz liczbe, ktora chcesz spierwiastkowac: \n";
cin >> s;

b=(s/a+a)/2.0;

while ( abs(a-b)>eps )
{
    a=b;
    b=(s/a+a)/2.0;
    cout << b << " \n";
}

cout << "\nPierwiastek z " << s << " to " << b ;

return 0;
}
