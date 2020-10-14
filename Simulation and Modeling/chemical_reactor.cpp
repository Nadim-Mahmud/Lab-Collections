#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

#define MX 100000

double a[MX],b[MX],c[MX],mx=0;

int main(){
    double dt,time,i=0,k1,k2;
    int in=0,j,k;

    freopen("chemical_reactor.txt","r",stdin);

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    cin>>k1>>k2; // rate of reaction
    cin>>a[0]>>b[0];   // initial amount of a and b
    time = 5;
    dt = 0.10;

    puts("........................................");
    puts("|  Time   |  A(t)   |   B(t)  |  C(t)  |");
    puts("........................................");
    printf("|  %5.2lf  |  %5.2lf |  %5.2lf  | %5.2lf  |\n",i,a[0],b[0],c[0]);
    mx = max(a[in],max(b[in],c[in]));
    for(i=dt;i<=time;i+=dt){
        in++;
        a[in] = a[in-1] + (k2*c[in-1] - k1*a[in-1]*b[in-1])*dt;
        b[in] = b[in-1] + (k2*c[in-1] - k1*a[in-1]*b[in-1])*dt;
        c[in] = c[in-1] + (2*k1*a[in-1]*b[in-1] - 2*k2*c[in-1])*dt;
        printf("|  %5.2lf  |  %5.2lf  |  %5.2lf  | %5.2lf  |\n",i,a[in],b[in],c[in]);
        mx = max(a[in],max(b[in],c[in]));
    }
    puts("........................................");


    ///Graphics part :

    int fctx,fcty,inc = 30; ///inc for padding space side and down
    int ymx = getmaxy();
    fctx = (double)(getmaxx()-inc)/in;
    fcty = (getmaxy()-inc*4)/(int)mx;

    setcolor(15);
    line(inc, 0, inc, getmaxy());
    line(0, ymx - inc, getmaxx(), ymx - inc);

    for(j=1,k=30+fctx; j<=in; j++,k+=fctx){

        setcolor(15);
        line(k-fctx, ymx - inc - a[j-1]*fcty, k, ymx - inc - a[j]*fcty);
        delay(10);

        setcolor(15);
        line(k-fctx, ymx - inc - b[j-1]*fcty, k, ymx - inc - b[j]*fcty);
        delay(10);

        setcolor(4);
        line(k-fctx, ymx - inc - c[j-1]*fcty, k, ymx - inc - c[j]*fcty);
        delay(10);

    }

    getch();
    closegraph();

    return 0;
}

