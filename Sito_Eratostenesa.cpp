#include<iostream>
#include<math.h>

using namespace std;

const long long int n=100000;
long long int i,j,k;
bool t[n];

int main(){

for (i=2;i<=n;i++)
    t[i]=true;

t[1]=false;

for (i=2;i<=n;i++){
    if (t[i]==true)
        for (j=2;j<sqrt(i-1);j++){
            if (i%j==0){
                t[i]=false;
                    for (k=i;k<=n;k=k+k){
                    t[k]=false;
                }

            }
        }
}

for (i=2;i<n;i++)
{
    if (t[i]==true) cout << i << " ";
}



return 0;
}
