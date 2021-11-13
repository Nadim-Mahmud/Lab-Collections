#include<bits/stdc++.h>
#include<omp.h>

using namespace std;


int main(int argv, char * argc[]){

    int thread_count = strtol(argc[1], NULL, 10);

    int A[100][100], B[100], C[100][100], i, j, n, m;

    freopen("in.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for(i = 0; i < m; i++){
        scanf("%d", &B[i]);
    }

    # pragma omp parallel for num_threads(thread_count) \
    default(none) shared(A, B, C, n, m) private(i, j)

    for(i = 0; i < n; i++){
        C[i][0] = 0;
        for(j = 0; j < m; j++){
            C[i][0] += A[i][j] * B[j];
        }
    }



    // printing after multiplicaiton
    puts("After multiplication");
    for(i = 0; i < n; i++){
        cout<<C[i][0]<<endl;
    }



    return 0;
}