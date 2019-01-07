#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

using namespace std;

int main()
{
srand(time(NULL));
int stan=0,t[5],a[5],b,c,d,i=0,j,s,x=0,trafienia,aa,aaa,aaaa,dzien=0,dod,dood,gl;

while(x<1)
{
dzien++;
stan=stan-10;


for(j=0;j<5;j++)
{
s=(rand()%35 ) + 1;

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

dod=( rand() % 4) +1;
dood=(rand( ) % 4) +1;
/*
cout<<"   Wylosowane liczby danego dnia  "<<endl;
for(j=0;j<5;j++)
{

    cout<<t[j]<<"  ";
}
cout<<endl;

cout<<"   Wylosowane liczby gracza danego dnia  "<<endl; */
for(d=0;d<2;d++)
{
    for(j=0;j<5;j++)
{
s=(rand()%35 ) + 1;

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
gl=0;
if(dod==dood) gl=1;

if((trafienia==2) && (gl==0)) stan=stan+5;
if((trafienia==2) && (gl==1)) stan=stan+10;
if((trafienia==3) && (gl==0)) stan=stan+25;
if((trafienia==3) && (gl==1)) stan=stan+80;
if((trafienia==4) && (gl==0)) stan=stan+200;

if((trafienia==4) && (gl==1))  stan=stan+1000;


if((trafienia==5) && (gl==0)) stan=stan+25000;
if((trafienia==5) && (gl==1)) x=1000000;

/*


for(j=0;j<5;j++)
{

    cout<<a[j]<<"  ";
}
cout<<"trafienia:  "<<trafienia<<"  dodatkowa:  "<<gl<<endl;
*/


}












cout<<"dzien  "<<dzien<<"  stan:  "<<stan<<endl;

}
return 0;





}




