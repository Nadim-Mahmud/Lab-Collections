#include<bits/stdc++.h>
#include<mpi.h>


/*
    replacing with the last processes message while using mpi_any tag
    to receicing from any source

    And last line is printing the message count
*/


using namespace std;

int main(){

    int comm_size, my_rank;
    MPI_Status status;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if(my_rank==3){
        MPI_Send("nadim", 5, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
    else if(my_rank==1){
        MPI_Send("nihal", 5, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
    if(my_rank==0){
        char str[100];
        MPI_Recv(str, 100, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        cout<<"String : "<<str<<"\nSource process : "<<status.MPI_SOURCE<<endl;
        cout<<status.MPI_ERROR<<endl; // if error then 0
       
        puts("\n\n\nPrinting Count");       
        int count;
        MPI_Get_count(&status, MPI_CHAR, &count);
        cout<<count<<endl;
    }


    MPI_Finalize();
    return 0;
}