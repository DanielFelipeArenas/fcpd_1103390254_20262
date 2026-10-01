/*
 * @file omp_06_parallel_sum.c
 * @brief exercise to sum values in parallel
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-27
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000000

// Fill the array with numbers from 1 to N.
void fill_array (int *arr){
    for (int i = 0; i < N; i++){
        *(arr+i)=i+1;
    }
}

// Add array values with OpenMP.
void sum_numbers(int *arr, long long *result_sum) {
    long long local_sum = 0;
    // Share the loop between threads.
    #pragma omp parallel for reduction(+:local_sum)
    for (int i = 0; i < N; i++) {
        local_sum = local_sum + *(arr + i);
    }
    *result_sum = local_sum;
}

// Create the array, calculate the sum, and show the time.
int main() {
    int *arr = (int *)calloc(N, sizeof(int));
    if (arr == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 1;
    }
    fill_array(arr);
    long long total_sum = 0;
    double start_time = omp_get_wtime();
    sum_numbers(arr, &total_sum);
    double elapsed_time = omp_get_wtime() - start_time;
    printf("Parallel Time: %.3f seconds\n", elapsed_time);
    printf("The sum is equal to %lld\n", total_sum);
    free(arr);
    arr = NULL;
    
    return 0;
}
