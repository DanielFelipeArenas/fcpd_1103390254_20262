/*
 * @file cb_07_scalar_product.c
 * @brief calculate scalar product between two vectors
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000
#define MIN 1
#define MAX 50

// Fill the array with random values.
void fill_array(int *arr) {

  for (int i = 0; i < N; i++) {
    *(arr + i) = rand() % (MAX - MIN + 1) + MIN;
  }
}

// Multiply matching values and add the results.
long long scalar_product(int *arra, int *arrb) {
  long long scalar = 0;
  for (int i = 0; i < N; i++) {
    int a = *(arra + i);
    int b = *(arrb + i);
    scalar += (a * b);
  }
  return scalar;
}

// Create the arrays, calculate the product, and show the time.
int main() {
  srand(1);
  int *arr1 = (int *)malloc(N * sizeof(int));
  if (arr1 == NULL) {
    printf("Error: Could not allocate memory.\n");
    return 1;
  }
  int *arr2 = (int *)malloc(N * sizeof(int));
  if (arr2 == NULL) {
    printf("Error: Could not allocate memory.\n");
    return 1;
  }
  fill_array(arr1);
  fill_array(arr2);

  clock_t start_time = clock();
  long long scalar = scalar_product(arr1, arr2);
  double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

  printf("Scalar product  = %lld\n", scalar);

  printf("sequential time: %3fsg\n", elapsed_time);

  free(arr1);
  free(arr2);

  return 0;
}
