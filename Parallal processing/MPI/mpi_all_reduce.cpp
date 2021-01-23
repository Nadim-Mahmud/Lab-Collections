#include<bits/stdc++.h>
#include<mpi.h>
using namespace std;


double func(double x){
    return x*x;
}

double trapizoid(double left_end, double right_end, int trap_count, double height){
    
    double segment_area,tmp;
    int i;
    /*calculating area of trapizoid of two end point*/
    // cout<<"start - ";
    segment_area = (func(left_end) + func(right_end))/2.0;
    for(i=1; i < trap_count; i++){
        segment_area += func(left_end + i*height);
    }
    segment_area *= height;
    //cout<<"end"<<endl;
    return segment_area;
}

int main(){
    int my_rank, comm_sz, n = 420000000, local_n;
    double a = 0.0, b = 3.00, height, local_left_point, local_right_point,total_area,local_area;
    int source; 

    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    height = (b-a)/(double)n;
    
    local_n = n/comm_sz;
    local_left_point = a + my_rank*local_n*height;

    if(my_rank == comm_sz-1 && n%comm_sz != 0){
        local_n = n % comm_sz;  // while number of iteration is not divided by the process
    }

    local_right_point = local_left_point + local_n*height;

    local_area = trapizoid(local_left_point,local_right_point,local_n,height);
   
    //cout<<my_rank<<endl;
    //calculate the with butterfly structure so all process have the result at the end
    MPI_Allreduce(&local_area, &total_area, 1, MPI_DOUBLE, MPI_SUM,MPI_COMM_WORLD);

        //printing output

    if(my_rank==2)
         printf("from process %d, Our estimate of the integral = %.20f \n", my_rank,total_area); 

    MPI_Finalize();
    return 0;
}