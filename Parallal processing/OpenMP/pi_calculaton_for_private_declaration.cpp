/// giving wrong ans

#include<bits/stdc++.h>

#ifdef _OPENMP
#include<omp.h>
#endif

using namespace std;


int main(int argc, char * argv[]){

    int i, n;
    double sum, factor;

    int thread_count = strtol(argv[1],NULL,10);

    sum = 0.0;
    n = 1000000;

    // this pragma is a pre processor which will start openmp code if we don't put this , then the programm will run as a seial code of cpp
    # pragma omp parallel for num_threads(thread_count) \
        reduction(+ : sum) private(factor)
            for(i = 0 ; i <= n ; i++){
                if(i % 2 == 0){
                    factor = 1.0;
                }
                else{
                    factor = -1.0;
                }
                sum += factor/(2.0 * (double)i + 1);
            }

  

    cout<<"PI : "<<sum * 4.0<<endl;

    return 0;
}
