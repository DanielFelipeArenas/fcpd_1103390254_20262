/*
 * @file cb_04_swap_pointers.c
 * @brief exercise to swap values using pointers in C
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-27
*/
#include <stdio.h>

// Function for swap number with pointers
void swap_pointer(int *number_a, int *number_b){
    int temp = *number_a;
    *number_a= *number_b;
    *number_b= temp;
}

int main (){
    int number_a, number_b;
    printf("Enter number a: ");
    scanf("%d", &number_a);
    printf("\nEnter number b: ");
    scanf("%d", &number_b);
    printf("before changing\nnumber a: %d\n number b: %d", number_a, number_b);
    swap_pointer(&number_a,&number_b);
    printf("\nafter changing\nnumber a: %d\nnumber b: %d", number_a, number_b);
    return 0;
}
