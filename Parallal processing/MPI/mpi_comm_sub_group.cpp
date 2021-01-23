#include<bits/stdc++.h>
#include "mpi.h"
using namespace std;

/**
 * Main COMM world remains intact while sub groups are created according to the color
 * Message can be pass among any process using COMM_WORLD but
 * no sub group can interchange messages.... the message can be pass localy on subgroups 
 * new ranks of sub group determines acceding order of COMM_WORLD rank
 * */


int main(){
    int comm_sz,my_rank,new_sz,new_rank,color;
    MPI_Comm new_comm;

    MPI_Init(NULL,NULL);
    
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    /*new_comm contains new communication sub world*/
    color = my_rank%2; //splitting acoording to odd and even.... different colour means different set of groups 

    MPI_Comm_split(MPI_COMM_WORLD, color,my_rank,&new_comm);
    
    MPI_Comm_size(new_comm,&new_sz);
    MPI_Comm_rank(new_comm,&new_rank);

    printf("size : %d  new_size : %d, rank: %d new_rank : %d\n",comm_sz,new_sz,my_rank,new_rank);





    MPI_Finalize();

    return 0;
}