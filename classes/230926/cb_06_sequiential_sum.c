/*
 * @file cb_06_sequiential_sum.c
 * @brief exercise to sum values in sequence
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-27
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000000

// Fill the array with numbers from 1 to N.
void fill_array (int *arr){
    for (int i = 0; i < N; i++){
        *(arr+i)=i+1;
    }
}

// Add all array values.
void count (int *arr,long long *sum){
    for (int i = 0;i<N;i++){
        *sum= *sum+*(arr+i);
    }
}

// Create the array, calculate the sum, and show the time.
int main(){
    int *arr=(int *) calloc (N,sizeof(int));
    fill_array(arr);
    long long sum=0;
    clock_t start_time = clock();
    count(arr,&sum);
    double elapsed_time = (double) (clock() - start_time) / CLOCKS_PER_SEC;
    printf("Sum: %lld\n", sum);
    printf("Sequential Time: %.3fsg\n", elapsed_time);
    return 0;
}
