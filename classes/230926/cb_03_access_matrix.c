/*
 * @file cb_03_access_matrix.c
 * @brief create a dynamic matrix and print its values
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 50

// Print the matrix values.
void print_matrix(int **M, int col, int rows) {
  printf("[\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < col; j++) {
      if (j == col - 1) {
        printf("%4d\n", *(*(M + i) + j));
      } else {
        printf("%4d", *(*(M + i) + j));
      }
    }
    if (i == rows - 1) {
      printf("]\n");
    };
  }
}

// Fill the matrix with random numbers.
void fill_matrix(int **M, int col, int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < col; j++) {
      *(*(M + i) + j) = rand() % (MAX - MIN + 1) + MIN;
    }
  }
}

// Create memory for the matrix.
int **assign_memory(int col, int rows) {
  int **M = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    *(M + i) = (int *)malloc(col * sizeof(int));
  }
  return M;
}

// Free the matrix memory.
void free_matrix(int **M, int rows) {
  for (int i = 0; i < rows; i++) {
    free((*(M + i)));
  }
  free(M);
}

// Create, fill, print, and free the matrix.
int main() {
  srand(time(NULL));
  int rows = 3;
  int col = 3;
  int **Matrix = assign_memory(col, rows);
  fill_matrix(Matrix, col, rows);
  print_matrix(Matrix, col, rows);
  free_matrix(Matrix, rows);
}
