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

    vector<ll>arr;
    if(my_rank==0){
        arr = {0,1,2,3,4};
    }

    int send_count[comm_sz];
    int displs[comm_sz];

    //number of data of each process and their starting position in array
    local_n = n/comm_sz;
    if(n%comm_sz!=0){
        local_n = (n-n%comm_sz)/(comm_sz-1);
    }
    for(int i=0; i<comm_sz; i++){
        send_count[i] = local_n;
        displs[i] = i*local_n;
    }
    if(n%comm_sz!=0){
        send_count[comm_sz-1] = n%comm_sz; // last process data
    }
    //int send_count[comm_sz] = {2,2,1};
    //int displs[comm_sz] = {0,2,4};

    local_n = send_count[my_rank];
    ll local_arr[local_n];

    MPI_Scatterv(arr.data(), send_count, displs, MPI_LONG_LONG, local_arr, local_n, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    for(int i=0;i<send_count[my_rank];i++){
        printf("rank %d data %lld\n",my_rank,local_arr[i]);
    }

    arr.clear();
    MPI_Finalize();
    return 0;
}

