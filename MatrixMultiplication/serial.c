#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(void) {
    int n = 550;
    double a[n][n], b[n][n], c[n][n];
    int i, j, k;
    clock_t t; 
    t = clock(); 
    srand(time(0)); 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand();
            b[i][j] = rand();
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0.0;
            for (k = 0; k < n; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("  Elapsed seconds = %g\n", time_taken);
    printf("  C(%d,%d)  = %g\n", n, n, c[n-1][n-1]);
    return 0;
}
