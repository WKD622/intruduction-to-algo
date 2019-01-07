#include <iostream>
#include <math.h>

using namespace std;

int main()



{
    int a,b,kopia,p,r,l,i;
    bool pierwsza;

    cout << "Podaj liczbe w systemie dziesietnym" << endl;
    cin >> a;
    cout << endl;


for (b=3;b<10;b++){
    l=0;
    kopia=a;
    p=1;
    pierwsza=true;

    while (kopia!=0){
         r=kopia%b;
         if (r!=1 || r!=0)
                for (i=2;i<r;i++){
                    if (r%i==0) pierwsza=false;
            }
         if (r==1) pierwsza = false;
         if (r==0) pierwsza = false;

         kopia=kopia/b;
         l=l+(r*p);
         p=p*10;
    }
    cout << l << endl;

    if (pierwsza==true)
        cout << "sklada sie z samych pierwszych" << endl;
}

return 0;
}
