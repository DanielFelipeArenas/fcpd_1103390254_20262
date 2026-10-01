/*
 * @file cb_08_matrix_multiplication_sequiential.c
 * @brief multiply two square matrices in sequence
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

// Create a matrix of integers.
int **create_matrix() {
    int **matrix = (int **)calloc(N, sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        *(matrix + i) = (int *)calloc(N, sizeof(int));
        if (*(matrix + i) == NULL) {
            for (int j = 0; j < i; j++) {
                free(*(matrix + j));
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

// Create a matrix for the result.
long long **create_result_matrix() {
    long long **matrix = (long long **)calloc(N, sizeof(long long *));
    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        *(matrix + i) = (long long *)calloc(N, sizeof(long long));
        if (*(matrix + i) == NULL) {
            for (int j = 0; j < i; j++) {
                free(*(matrix + j));
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

// Fill each row with numbers from 1 to N.
void fill_matrix(int **matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(matrix + i) + j) = j + 1;
        }
    }
}

// Multiply the two matrices in sequence.
void multiply_matrices(int **matrix_a, int **matrix_b, long long **matrix_c) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(matrix_c + i) + j) = 0;
            for (int k = 0; k < N; k++) {
                *(*(matrix_c + i) + j) +=
                    (long long)*(*(matrix_a + i) + k) * *(*(matrix_b + k) + j);
            }
        }
    }
}

// Print the first rows and columns of a matrix.
void print_matrix(int **matrix, char name) {
    int print_size = N < 3 ? N : 3;
    printf("Matrix %c (first %d rows and columns):\n", name, print_size);
    for (int i = 0; i < print_size; i++) {
        for (int j = 0; j < print_size; j++) {
            printf("%d\t", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

// Print the first rows and columns of the result.
void print_result_matrix(long long **matrix) {
    int print_size = N < 3 ? N : 3;
    printf("Result matrix (first %d rows and columns):\n", print_size);
    for (int i = 0; i < print_size; i++) {
        for (int j = 0; j < print_size; j++) {
            printf("%lld\t", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

// Free the memory used by an integer matrix.
void free_matrix(int **matrix) {
    for (int i = 0; i < N; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}

// Free the memory used by the result matrix.
void free_result_matrix(long long **matrix) {
    for (int i = 0; i < N; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}

// Create the matrices, multiply them, and show the time.
int main() {
    int **matrix_a = create_matrix();
    int **matrix_b = create_matrix();
    long long **matrix_c = create_result_matrix();

    if (matrix_a == NULL || matrix_b == NULL || matrix_c == NULL) {
        printf("Error: Could not allocate memory.\n");
        if (matrix_a != NULL) {
            free_matrix(matrix_a);
        }
        if (matrix_b != NULL) {
            free_matrix(matrix_b);
        }
        if (matrix_c != NULL) {
            free_result_matrix(matrix_c);
        }
        return 1;
    }

    fill_matrix(matrix_a);
    fill_matrix(matrix_b);

    print_matrix(matrix_a, 'A');
    print_matrix(matrix_b, 'B');

    clock_t start_time = clock();
    multiply_matrices(matrix_a, matrix_b, matrix_c);
    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    print_result_matrix(matrix_c);
    printf("Sequential time: %.6f seconds\n", elapsed_time);

    free_matrix(matrix_a);
    free_matrix(matrix_b);
    free_result_matrix(matrix_c);

    return 0;
}
