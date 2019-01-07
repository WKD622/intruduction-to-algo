#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()

{
float r=0,s,b,n,a=1,eps=1e-10;

cout << "Wprowadz liczbe, ktora chcesz spierwiastkowac: \n";
cin >> s;
cout << "Podaj stopieñ pierwiastka \n";
cin >> n;

b=(1/n)*((n-1)*a+(s/pow(a,n)));

while ( abs(a-b)>eps && r < 10000 )
{
    a=b;
    b=(1/n)*((n-1)*a+(s/pow(a,n)));
    cout << b << " \n";
    r=r+1;
}

cout << "\nPierwiastek z " << s << " to " << b ;

return 0;
}

