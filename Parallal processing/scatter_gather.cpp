#include<bits/stdc++.h>
#include <mpi.h>
using namespace std;
#define ll long long

/* mpi scatter wiil distribute chunck of array block to processes
   mpi gather will gather chunck of array block form processes to process 0
   this program will calculate the avarage of a random array.
*/

int main(void) {
    int comm_sz;
    int my_rank;
    ll total_elements=1000000,elements_perpro;

    double start,end;
    start = MPI_Wtime();

    int n = MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    
    elements_perpro =  total_elements/comm_sz;
    ll *local_rand = (ll*)malloc(sizeof(ll)*elements_perpro);
    ll *rand_n = NULL;

    if(my_rank==0){
       rand_n = (ll*)malloc(sizeof(ll)*total_elements);
       for(int i=0; i<total_elements; i++){
           rand_n[i] = rand()%total_elements;
       }
    }
    
    MPI_Scatter(rand_n, elements_perpro, MPI_LONG_LONG, local_rand, elements_perpro, MPI_LONG_LONG, 0, MPI_COMM_WORLD);


    // calculating avarage of the array in each process
    long double avg=0;
    for(int i=0; i<elements_perpro; i++){
        avg += local_rand[i];
    }
    avg /= (long double)total_elements;
    //cout<<my_rank<<" "<<avg<<endl;

    long double *collect_avg = NULL;
    if(my_rank==0){
        collect_avg = (long double*)malloc(sizeof(long double)*comm_sz);
    }
        
    MPI_Gather(&avg, 1, MPI_LONG_DOUBLE, collect_avg, 1, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD);
    
    if(my_rank==0){
        long double sum = 0;
        for(int i=0; i<comm_sz; i++){
            sum += collect_avg[i];
        }
        printf("Total average - %Lf\n",sum);
    }
    
    end = MPI_Wtime();

    printf("rank %d need %lf time\n",my_rank,end-start);

    free(collect_avg);
    free(rand_n);
    free(local_rand);
    MPI_Finalize();
    return 0;
}

