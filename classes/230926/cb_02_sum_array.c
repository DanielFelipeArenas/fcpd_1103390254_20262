/*
 * @file cb_02_sum_array.c
 * @brief sum the values in an array
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 50

// Fill the array with random numbers.
void fill_array(int *arr, int size) {

  for (int i = 0; i < size; i++) {
    *(arr + i) = rand() % (MAX - MIN + 1) + MIN;
  }
}

// Print the array values.
void print_array(int *array, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d]\n", *(array + i));
      break;
    }
    printf("%d, ", *(array + i));
  }
}

// Add the array values.
int sum_array(int *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += *(arr + i);
  }
  return sum;
}

// Create the array, find its sum, and print the values.
int main() {
  srand(time(NULL));
  int sum = 0;
  int size = 10;
  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
    printf("Error: Could not allocate memory.");
    return 1;
  }
  fill_array(arr, size);
  print_array(arr, size);
  sum = sum_array(arr, size);
  printf("The sum of the array values is %d\n", sum);

  return 0;
}
