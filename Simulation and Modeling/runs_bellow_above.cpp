#include<bits/stdc++.h>
using namespace std;

#define MX 100000

int numbers[MX];

int main(){

    int i,j,k,n,rgm,x,a,c,m,runs,mr,n1,n2;
    double z,mean,variance,mean_middle;
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
    runs = n1 = n2 = 0;
    mr = -1;
    mean_middle = ((double)m-1.0+0)/2.0;

    freopen("run_test.txt","w",stdout);

    for(i=1;i<=n;i++){
        filein>>numbers[i];
    }

    puts("Sequence of run ups and downs : ");
    for(i=1;i<n;i++){
        if(numbers[i]>mean_middle){
            cout<<'+'<<" ";
            if(mr!=1) runs++,n1++;
            mr = 1;
        }
        else{
            cout<<'-'<<" ";
            if(mr!=0) runs++,n2++;
            mr = 0;
        }
    }

    mean = 2*n1*n2/n + .5;
    variance = 2*n1*n2*(2*n1*n2 - n)/n*n*(n-1);
    z = ((double)runs - mean)/sqrt(variance);


    puts("\n\n");
    cout<<"Above from the mean : "<<n1<<endl;
    cout<<"Below from the mean : "<<n2<<endl;
    cout<<"Middle position mean : "<<mean_middle<<endl;
    cout<<"Total numbers : "<<n<<endl;
    cout<<"Number of runs : "<<runs<<endl;
    cout<<"Mean : "<<mean<<endl;
    cout<<"Variance : "<<variance<<endl;
    cout<<"Z0 : "<<z<<endl;

    if(z>=-1.96 && z <= 1.96) puts("Result : ACCEPTED");
    else puts("Result : NOT ACCEPTED");

    filein.close();

    return 0;
}
