#include<bits/stdc++.h>
#include <mpi.h>
using namespace std;
#define ll long long

/* sort an array
*/

int main(void) {
    int comm_sz;
    int my_rank;
    int n=5,local_n;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    local_n = n/comm_sz;

    vector<ll>arr;
    
    int send_count[comm_sz] = {2,2,1};
    int displs[comm_sz] = {0,2,4};
    ll local_arr[send_count[my_rank]];

    
    if(my_rank==0){
        arr = {0,1,2,3,4};
    }

    MPI_Scatterv(arr.data(), send_count, displs, MPI_LONG_LONG, local_arr, send_count[my_rank], MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    for(int i=0;i<send_count[my_rank];i++){
        printf("rank %d data %lld\n",my_rank,local_arr[i]);
    }

    arr.clear();
    MPI_Finalize();
    return 0;
}

