#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,a,c,m,i,n;

    puts("Enter number of random number and mod :");

    freopen("random_number_using_builtin_fuction.txt","w",stdout);

    cin>>n>>m;

    for(i=0;i<=n;i++){
        x = rand()%m;
        cout<<((double)x/(double)m)<<" ";
    }

    return 0;
}
