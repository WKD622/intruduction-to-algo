#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

using namespace std;

int main()
{
srand(time(NULL));
int stan=0,t[5],a[5],b,c,d,i=0,j,s,x=0,trafienia,aa,aaa,aaaa,dzien=0;

while(stan<1)
{
dzien++;
stan=stan-5;


for(j=0;j<5;j++)
{
s=(rand()%42 ) + 1;

c=0;
for(b=0;b<5;b++)

{

if(s==t[b])
{
c=1;
break;
}
}

t[j]=s;
if (c) j--;
}
/*
cout<<"   Wylosowane liczby danego dnia  "<<endl;
for(j=0;j<5;j++)
{

    cout<<t[j]<<"  ";
}
cout<<endl;

cout<<"   Wylosowane liczby gracza danego dnia  "<<endl; */
for(d=0;d<4;d++)
{
    for(j=0;j<5;j++)
{
s=(rand()%42 ) + 1;

c=0;
for(b=0;b<5;b++)

{

if(s==a[b])
{
c=1;
break;
}
}

a[j]=s;
if (c) j--;
}

trafienia=0;

for(aa=0;aa<5;aa++)
{
    for(aaa=0;aaa<5;aaa++)
    {
        if(t[aa]==a[aaa]) trafienia=trafienia+1;
    }
}




if(trafienia==3) stan=stan+25;
if(trafienia==4)  stan=stan+600;


if(trafienia==5)
{stan=stan + 200000;
x=10000;}


/*
for(j=0;j<5;j++)
{

    cout<<a[j]<<"  ";
}
cout<<"trafienia:  "<<trafienia<<endl;

*/

}












cout<<"dzien  "<<dzien<<"  stan:  "<<stan<<endl;

}
return 0;





}




