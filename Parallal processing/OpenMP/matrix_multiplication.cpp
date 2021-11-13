#include<bits/stdc++.h>
#include<omp.h>
#include<time.h>

#define MX 10005

using namespace std;

int A[MX][MX], B[MX], C[MX][MX], i, j, n, m;


int main(int argv, char * argc[]){

    int thread_count = strtol(argc[1], NULL, 10);

    // input section

    //freopen("in.txt", "r", stdin);
    //scanf("%d %d", &n, &m);
    n = MX - 5;
    m = MX - 5;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            //scanf("%d", &A[i][j]);
            A[i][j] = rand()%100;
        }
    }

    for(i = 0; i < m; i++){
        //scanf("%d", &B[i]);
        B[i] = rand()%100;
    }


    // serial Part

    clock_t start = clock();

    for(i = 0; i < n; i++){
        C[i][0] = 0;
        for(j = 0; j < m; j++){
            C[i][0] += A[i][j] * B[j];
        }
    }

    clock_t end = clock();
    double elapsed = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time for Serial Program : %.9lf\n", elapsed*1000.0);
    

    // Perallel part

    clock_t startp = clock();


    # pragma omp parallel for num_threads(thread_count) \
    default(none) shared(A, B, C, n, m) private(i, j)

    for(i = 0; i < n; i++){
        C[i][0] = 0;
        for(j = 0; j < m; j++){
            C[i][0] += A[i][j] * B[j];
        }
    }

    clock_t endp = clock();
    double elapsedp = (double)(endp - startp)/CLOCKS_PER_SEC;

    printf("Time for Parallel Program : %.9lf\n", elapsedp*1000.0);
    
    // printing after multiplicaiton
    puts("After multiplication");
    for(i = 0; i < n; i++){
        //cout<<C[i][0]<<endl;
    }



    return 0;
}