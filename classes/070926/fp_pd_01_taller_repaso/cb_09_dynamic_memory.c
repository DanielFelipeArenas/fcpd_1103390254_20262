/*
 * @file cb_09_dynamic_memory.c
 * @brief exercise on assigning a letter based on a numerical value
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-12
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int number;
    int sum = 0;
    int *array;

    printf("How many numbers do you wish to enter? ");
    scanf("%d", &number);

    array = (int*) malloc(number * sizeof(int));

    if (array == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 1;
    }

    printf("\nEnter the %d values:\n", number);
    for (int i = 0; i < number; i++) {
        printf("Values %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < number; i++) {
        sum += array[i];
    }

    printf("\nThe sum of the elements is: %d\n", sum);

    free(array);

    return 0;
}