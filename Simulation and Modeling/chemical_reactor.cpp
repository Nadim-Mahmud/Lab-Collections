#include<bits/stdc++.h>
using namespace std;

#define MX 100000

double a[MX],b[MX],c[MX];

int main(){
    double dt,time,i=0,k1,k2;
    int in=0;

    freopen("chemical_reactor.txt","r",stdin);

    cin>>k1>>k2; // rate of reaction
    cin>>a[0]>>b[0];   // initial amount of a and b
    time = 5;
    dt = 0.10;

    puts("........................................");
    puts("|  Time   |  A(t)   |   B(t)  |  C(t)  |");
    puts("........................................");
    printf("|  %5.2lf  |  %5.2lf |  %5.2lf  | %5.2lf  |\n",i,a[0],b[0],c[0]);

    for(i=dt;i<=time;i+=dt){
        in++;
        a[in] = a[in-1] + (k2*c[in-1] - k1*a[in-1]*b[in-1])*dt;
        b[in] = b[in-1] + (k2*c[in-1] - k1*a[in-1]*b[in-1])*dt;
        c[in] = c[in-1] + (2*k1*a[in-1]*b[in-1] - 2*k2*c[in-1])*dt;
        printf("|  %5.2lf  |  %5.2lf  |  %5.2lf  | %5.2lf  |\n",i,a[in],b[in],c[in]);
    }
    puts("........................................");


    ///Graphics part :





    return 0;
}

