#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c=0,a1,b1,c1,dt,time,i=0,k1,k2;

    freopen("chemical_reactor.txt","r",stdin);

    cin>>k1>>k2; // rate of reaction
    cin>>a>>b;   // initial amount of a and b
    time = 5;
    dt = 0.10;

    puts("..........................................");
    puts("|  Time  |   A(t)   |   B(t)  |   C(t)   |");
    puts("..........................................");
    printf("|  %.2lf  |  %.2lf  |  %.2lf  | %2.2lf  |\n",i,a,b,c);

    for(i=dt;i<=time;i+=dt){
        a1 = a + (k2*c - k1*a*b)*dt;
        b1 = b + (k2*c - k1*a*b)*dt;
        c1 = c + (2*k1*a*b - 2*k2*c)*dt;
        a = a1,b=b1,c=c1;
        printf("|  %.2lf  |  %.2lf  |  %.2lf  | %2.2lf  |\n",i,a,b,c);
    }

    return 0;
}
