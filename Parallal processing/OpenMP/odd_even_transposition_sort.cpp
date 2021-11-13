#include<bits/stdc++.h>
#include<omp.h>

using namespace std;


int main(int argc, char * argv[]){

    int thread_count = strtol(argv[1],NULL,10);

    int i, tmp, n=20, ara[10000], phase;
    
    for(i = 0; i < n; i++){
        ara[i] =  rand()%100;
    }

#  pragma omp parallel num_threads(thread_count) \
        default(none) shared(ara, n) private(phase, i, tmp)
       
        for(phase = 0; phase <= n; phase++ ){
            if(phase%2 == 0){
                # pragma omp for 
                for(i = 1; i < n; i += 2){
                    if(ara[i-1] > ara[i]){
                        tmp = ara[i-1];
                        ara[i-1] =  ara[i];
                        ara[i] = tmp;
                        //cout<<omp_get_thread_num()<<endl;
                    }
                }
            }
            else{
                # pragma omp for
                for(i = 1; i < n-1; i += 2){
                    if(ara[i] > ara[i+1]){
                        tmp = ara[i+1];
                        ara[i+1] =  ara[i];
                        ara[i] = tmp;
                    }
                }
            }
        }



    puts("Sorted array :");
    for(i=0; i < n; i++){
        cout<<ara[i]<<" ";
    }
    puts("");

    return 0;
}