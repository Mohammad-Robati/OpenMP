// gcc -o omp_helloc -fopenmp omp_hello.c
// export OMP_NUM_THREADS=2
// ./omp_helloc
// Hello World from thread = 0
// Hello World from thread = 1
// Number of threads = 2

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>

int main(void) {
    int n = 550;
    double a[n][n], b[n][n], c[n][n];
    int i, j, k;
    int thread_num;
    double wtime;
    srand(time(0)); 
    thread_num = omp_get_max_threads();
    wtime = omp_get_wtime();
    #pragma omp parallel shared(a, b, c, n) private(i, j, k)
    #pragma omp for
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand();
            b[i][j] = rand();
        }
    }
    #pragma omp for
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0.0;
            for (k = 0; k < n; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    wtime = omp_get_wtime() - wtime;
    printf("  Elapsed seconds = %g\n", wtime);
    printf("  C(%d,%d)  = %g\n", n, n, c[n-1][n-1]);
    return 0;
}
