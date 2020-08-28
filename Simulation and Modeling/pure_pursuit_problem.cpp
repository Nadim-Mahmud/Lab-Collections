#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

#define MX 100000

double  bx[MX],by[MX];
double  fx[MX],fy[MX];
double vf,dist,sin_theta,cos_theta;

int main(){
    int i,mr=0,time,posx=0,posy=0;

    freopen("pure_pursuit_problem.txt","r",stdin);

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    cin>>time;
    for(i=0;i<=time;i++){
        cin>>bx[i]>>by[i];

        posx = min(posx,(int)bx[i]);
        posy = min(posy,(int)by[i]);
    }
    cin>>fx[0]>>fy[0];
    cin>>vf;

    for(i=0;i<=time;i++){

        dist = sqrt((bx[i]-fx[i])*(bx[i]-fx[i]) + (by[i]-fy[i])*(by[i]-fy[i]));
        sin_theta = (by[i]-fy[i])/dist;
        cos_theta = (bx[i]-fx[i])/dist;
        fx[i+1] = fx[i] + vf*cos_theta;
        fy[i+1] = fy[i] + vf*sin_theta;

        posx = min(posx,(int)fx[i]);
        posy = min(posy,(int)fy[i]);

        if(dist<=vf && i<time){
            cout<<"Time : "<<i<<"\nDistance : "<<dist<<endl;
            mr = 1;
            time = i;
            break;
        }
    }

    if(!mr){
        puts("Target Escaped!");
        //return 0;
    }

    ///Plotting the graph

    int fct = 3,inc = 5; ///inc for padding space side and down
    int ymx = getmaxy();
    posx = abs(posx);
    posy = abs(posy);

    setcolor(15);
    line((inc+posx)*fct, 0, (inc+posx)*fct, getmaxy());
    line(0, getmaxy() - (inc+posy)*fct, getmaxx(), getmaxy() - (inc+posy)*fct);

    posx = posx+inc;
    posy = posy+inc;

    bx[0] = (bx[0]+posx)*fct;
    by[0] = (by[0]+posy)*fct;
    fx[0] = (fx[0]+posx)*fct;
    fy[0] = (fy[0]+posy)*fct;


    for(i=1;i<=time;i++){

        bx[i] = (bx[i]+posx)*fct;
        by[i] = (by[i]+posy)*fct;
        fx[i] = (fx[i]+posx)*fct;
        fy[i] = (fy[i]+posy)*fct;

        setcolor(4);
        line(bx[i-1], ymx - by[i-1], bx[i], ymx - by[i]);
        delay(50);

        setcolor(2);
        line(fx[i-1], ymx - fy[i-1], fx[i], ymx - fy[i]);
        delay(50);
    }

    getch();
    closegraph();

    return 0;
}
