#include<bits/stdc++.h>
using namespace std;

#define MX 100000

int numbers[MX];

int main(){

    int i,j,k,n,rgm,x,a,c,m,runs,mr;
    double z,mean,variance;
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
    runs = 0;
    mr = -1;

    freopen("run_test.txt","w",stdout);

    for(i=1;i<=n;i++){
        filein>>numbers[i];
    }

    puts("Sequence of run ups and downs : ");
    for(i=1;i<n;i++){
        if(numbers[i+1]>numbers[i]){
            cout<<'+'<<" ";
            if(mr!=1) runs++;
            mr = 1;
        }
        else{
            cout<<'-'<<" ";
            if(mr!=0) runs++;
            mr = 0;
        }
    }

    mean = (2*n-1)/3;
    variance = (16*n-29)/90;
    z = ((double)runs - mean)/sqrt(variance);


    puts("\n\n");
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
