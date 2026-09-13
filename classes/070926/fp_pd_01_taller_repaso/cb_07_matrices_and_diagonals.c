/*
 * @file cb_07_matrices_and_diagonals.c
 * @brief exercise in creating matrices and comparing diagonals
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-12
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_matrix(int size, int matrix[size][size]){
    for (int i=0;i<size;i++){
        for (int j=0; j<size;j++){
            matrix[i][j]=rand() % (100 + 1);
        }
    }
}

void print_matrix (int size, int matrix[size][size]){
    printf("matrix[");
    for (int i=0;i<size;i++){
        printf("\n       (");
        for (int j=0; j<size;j++){
            if (j==size-1){
                printf("%d",matrix[i][j]);
            }else{
                printf("%d, ",matrix[i][j]);
            }
        }
        printf(")\n");
    }
    printf("]\n");
}

int main_diagonal_sum (int size, int matrix[size][size]){
    int sum=0;
    for (int i=0;i<=size-1;i++){
        sum=sum+matrix[i][i];
    }
    return sum;
}

int sum_secondary_diagonal(int size, int matrix[size][size]){
    int sum=0, j=size-1;
    for (int i=0;i<size;i++){
        sum=sum+matrix[i][j];
        j--;
    }
    return sum;
}

void compare_diagonal_sums(int main, int secundary){
    if (main>secundary){
        printf("The sum of the main diagonal is greater, %d > %d", main, secundary);
    }else if (main==secundary){
        printf("The sums of the two diagonals are equal, %d = %d", main, secundary);
    }else{
        printf("The sum of the secundary diagonal is greater, %d > %d", secundary, main);
    }
}

int main(){
    srand(time(NULL));
    printf("Enter the matrix size: \n");
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    if (size<=1){
        printf("\nInvalid number");
        return 1;
    }
    int matrix[size][size];
    fill_matrix(size, matrix);
    print_matrix(size, matrix);
    compare_diagonal_sums(main_diagonal_sum(size, matrix), sum_secondary_diagonal(size, matrix));
    return 0;
}