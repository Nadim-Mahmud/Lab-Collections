#include<bits/stdc++.h>
#include<mpi.h>
using namespace std;

// m = rows = must be equals to number of  process
// n = columns

int main(){
    int my_rank, comm_sz;
    int local_ans = 0, n, m;
    // must initialized with NULL char
    int * arra = NULL;
    int * local_arra = NULL;
    int * ans = NULL;
    int mult[] = {2, 2, 2}; 


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    scanf("%d %d", &m, &n);
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    local_arra = (int *)malloc(sizeof(int)*n);
    

    if(my_rank == 0){
        ans = (int *)malloc(sizeof(int)*n);
        arra = (int *)malloc(sizeof(int)*m*n);
        for(int i=0; i < m*n; i++){
            scanf("%d", &arra[i]);
        }
    }
    // I don't konw why but input arra and local array both parameter must pass local_arr size
    MPI_Scatter(arra, n, MPI_INT, local_arra, n, MPI_INT, 0, MPI_COMM_WORLD);

    // Mulitiplication part block partition 
    // Assuming each row is a block 

    for(int i = 0; i < n; i++){
        local_ans = local_ans + local_arra[i] * mult[i];
    }

    // using senders arr size on both side
    MPI_Gather(&local_ans, 1, MPI_INT, ans, 1, MPI_INT, 0, MPI_COMM_WORLD);
    //MPI_Allgather(&local_ans, 1, MPI_INT, ans, 1, MPI_INT, MPI_COMM_WORLD);

    if(my_rank == 0){
        for(int i = 0; i < m; i++){
            cout<<ans[i]<<endl;
        }
    }

/*
    cout<<"From : "<<my_rank<<endl;
    for(int i = 0; i < n; i++){
        cout<<local_arra[i]<<" ";
    }
    cout<<endl;
*/
    free(ans);
    free(arra);
    free(local_arra);
    MPI_Finalize();
   
    return 0;
}
