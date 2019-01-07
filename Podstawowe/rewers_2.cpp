#include<iostream>

using namespace std;

int rewers (int x){
int p=0;
    while (x>0){
        p=p*10+x%10;
        x=x/10;
    }
return p;
}


int main(){
    int x,p;
    cout << "Podaj liczbe: ";
    cin >> x;

while (x!=rewers(x)){
    x=x+rewers(x);
    cout << x <<endl;
}




return 0;
}




