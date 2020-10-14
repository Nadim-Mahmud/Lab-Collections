#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,a,c,m,i,n=100;

    puts("Enter seed multiplier increamenter and mod :");

    freopen("Linear_congruential_method.txt","w",stdout);

    cin>>x>>a>>c>>m;

    for(i=0;i<=n;i++){
        x = (x*a + c)%m;
        cout<<((double)x/(double)m)<<" ";
    }

    return 0;
}
