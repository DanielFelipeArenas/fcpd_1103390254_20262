/*
 * @file cb_01_access_array.c
 * @brief create a dynamic array and print its values
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 10

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

// Fill the array with random numbers.
void fill_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    *(array + i) = rand() % (MAX - MIN + 1) + MIN;
  }
}

// Create, fill, and print the array.
int main() {
  srand(time(NULL));
  int size = 10;
  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
    printf("Error: Could not allocate memory.");
    return 1;
  }
  fill_array(arr, size);
  print_array(arr, size);

  return 0;
}
