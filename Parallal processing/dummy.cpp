#include<bits/stdc++.h>
using namespace std;
#define ll long long

void compare_and_store(ll A[], ll B[], int size){
    puts("me");
    vector<ll>tmp(size+size);
    merge(A, A+size, B, B+size,tmp.begin());
    for(int i=0; i<tmp.size(); i++){
        if(i<size){
            A[i] = tmp[i];
        }
        else{
            B[i-size] = tmp[i];
        }
    }
    tmp.clear();
}

int main(){
  ll b[] = {1,2};
  ll a[] = {3,4};
  int i;

  compare_and_store(a,b,2);
  for(i=0;i<2;i++){
    cout<<a[i]<<endl;
  }
  for(i=0;i<2;i++){
    cout<<b[i]<<endl;
  }
  return 0;
}