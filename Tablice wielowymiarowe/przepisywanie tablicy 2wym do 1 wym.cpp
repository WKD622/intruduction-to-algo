#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){

const int n=3,m=n*n;
int t1[n][n],t2[m];
int i,j,p=0;

srand(time(NULL));

for (i=0;i<n;i++)
    for (j=0;j<n;j++){
        t1[j][i]=rand()%10;
        cout << t1[j][i];
    }

for (i=0;i<n;i++)
    for (j=0;j<n;j++){
        t2[p]=t1[j][i];
        cout << t2[p] << " ";
        p++;
    }

return 0;
}
