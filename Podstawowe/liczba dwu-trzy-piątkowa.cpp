#include <iostream>

using namespace std;

int main(){

    int n,i2,i3,i5,l=0;

    cin >> n;

    i2=1;
    while (i2<=n){
        i3=i2;
        while(i3<=n){
            i5=i3;
            while(i5<=n){
                i5=i5*5;
                l++;
            }
            i3=i3*3;
        }
        i2=i2*2;
    }

cout << l;
}
