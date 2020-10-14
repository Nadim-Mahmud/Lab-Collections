#include<bits/stdc++.h>
using namespace std;

#define MX 100000

int  occurrence[MX];

int main(){

    int i,j,k,n,rgm,x,a,c,m,d,ex,rn,in,tmp;
    double chi,total;
    ofstream fileout;
    ifstream filein;

    fileout.open("random_numbers.txt");
    filein.open("random_numbers.txt");

    ///Segment-1
    /// Random numbers stored on "random_numbers.txt"

    //puts("Enter the number of random numbers to generate :");
    //cin>>n;
    n = 5000;
    m = 1000;

    puts("Enter '1' to chose LCM, '2' to chose builtin fucntion :");
    cin>>rgm;

    if(rgm==1){
        puts("Enter seed multiplier increamenter :");
        cin>>x>>a>>c;
        for(i=0;i<=n;i++){
            x = (x*a + c)%m;
            fileout<<x<<" ";
        }
    }
    else{
        //puts("Enter value of mod :");
        //cin>>m;
        for(i=0;i<=n;i++){
            x = rand()%m;
            fileout<<x<<" ";
        }
    }
    fileout.close();

    ///Segment-2
    ///Output stored on "chi_square.txt"

    k =  10;
    d = m/k;
    ex = n/k;
    rn = 0;
    total = 0;

    freopen("chi_square.txt","w",stdout);

    for(i=0;i<n;i++){
        filein>>x;
        in = (x/d)+1;
        occurrence[in]++;
    }

    puts("..............................................................................");
    puts("|  SL  |    Range    | Occurrence | Expected occ  |  (O-E)^2  |   (O-E)^2/E  |");
    puts("..............................................................................");

    for(i=1;i<=k;i++){

        tmp = (occurrence[i]-ex)*(occurrence[i]-ex);
        chi = (double)tmp/(double)ex;
        total += chi;

        printf("|  %2d  | %4d - %4d |    %4d    |     %4d      |  %7d  | %10.2lf   |\n",i,rn,rn+d-1,occurrence[i],ex,tmp,chi);
        rn += d;
    }

    puts("..............................................................................");
    printf("|                                            Total chi-square = %10.4lf   |\n",total);
    puts("..............................................................................");


    if(total>=1.73 && total <= 23.6) puts("Result : ACCEPTED");
    else puts("Result : NOT ACCEPTED");

    filein.close();

    return 0;
}
