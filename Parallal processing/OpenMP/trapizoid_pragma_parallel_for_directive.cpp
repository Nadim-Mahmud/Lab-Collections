
#include<bits/stdc++.h>

#ifdef _OPENMP
#include<omp.h>
#endif

using namespace std;

int cnt = 0;

double func(double x){
    return x*x;
}



int main(int argc, char * argv[]){

    double a, b, total_area = 0.0, h;
    int n,i;

    int thread_count = strtol(argv[1],NULL,10);
    a = 2.0;
    b = 4.0;
    n = 4000;
    
    h = (b-a)/(double)n;
    total_area = (func(a) + func(b))/2.0;


    // this pragma is a pre processor which will start openmp code if we don't put this , then the programm will run as a seial code of cpp
    # pragma omp parallel for num_threads(thread_count) \
        reduction(+ : total_area) 
    for(i = 1; i <= n-1 ; i++)
        total_area += func( a + h*i);
    total_area *= h;

    cout<<"total area = "<<total_area<<endl;
    

    return 0;
}
