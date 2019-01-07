#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){
    const int n=4,m=n*n;
    int o,l,i,j,k=0,p=0,min;
    int t1[n][n],t2[m];
    srand(time(NULL));
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            t1[i][j]=rand()%9+1;
            cout << t1[i][j] << " ";
        }
        cout << endl;
    }
    p=0;
    for (l=0;l<m;l++){
            for (i=0;i<n;i++)
                for (j=0;j<n;j++)
                    if (t1[i][j]!=0){
                        min=t1[i][j];
                        break;
                        break;
                    }
            for (i=0;i<n;i++)
                for (j=0;j<n;j++)
                    if (t1[i][j]<min && t1[i][j]!=p && t1[i][j]!=0){
                        min=t1[i][j];
                        p=min;
                    }
            for (i=0;i<n;i++)
                for (j=0;j<n;j++)
                    if (t1[i][j]==min){
                        t1[i][j]=0;
                        t2[k]=min;
                        k++;
                    }
            }
    cout << endl;
    for (i=0;i<m;i++)
    cout << t2[i] << " ";
return 0;
}
