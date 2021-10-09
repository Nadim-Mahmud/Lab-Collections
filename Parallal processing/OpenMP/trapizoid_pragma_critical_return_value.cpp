

#include<bits/stdc++.h>

#ifdef _OPENMP
#include<omp.h>
#endif

using namespace std;

int cnt = 0;

double func(double x){
    return x*x;
}

double trapizoid(double a, double b, int n){
    
    double segment_area,tmp, height, left_end, right_end, trap_count;
    int i, my_rank, number_of_thread;
    
    #ifdef _OPENMP
        my_rank = omp_get_thread_num();
        number_of_thread = omp_get_num_threads();
    #endif

    trap_count = n / number_of_thread;

     height = (b-a)/(double)n;

    left_end = a + height*my_rank*trap_count;
    right_end = left_end + height*trap_count;


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


int main(int argc, char * argv[]){

    double a, b, total_area = 0.0;
    int n;

    int thread_count = strtol(argv[1],NULL,10);
    a = 2.0;
    b = 4.0;
    n = 4000;
    // this pragma is a pre processor which will start openmp code if we don't put this , then the programm will run as a seial code of cpp
    # pragma omp parallel num_threads(thread_count)
    { 
        double result = 0.0;
        result = trapizoid(a, b, n);
        # pragma omp critical
            total_area += result;
    }

    cout<<"total area = "<<total_area<<endl;
    

    return 0;
}
