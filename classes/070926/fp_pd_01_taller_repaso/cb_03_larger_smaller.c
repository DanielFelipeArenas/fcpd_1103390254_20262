/*
 * @file cb_03_larger_smaller.c
 * @brief exercise in determining major and minor in C
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-07
*/
#include <stdio.h>

void find_largest(int number_a, int number_b, int number_c){
    printf("larger number: %d\n", (number_a > number_b) ? ((number_a > number_c) ? number_a : number_c) : ((number_b > number_c) ? number_b : number_c));
}

void find_minor(int number_a, int number_b, int number_c){
    printf("smaller number: %d", (number_a < number_b) ? ((number_a < number_c) ? number_a : number_c) : ((number_b < number_c) ? number_b : number_c));
}

int main (){
    int number_a,number_b,number_c;
    printf("enter number a: ");
    scanf("%d", &number_a);
    printf("\nenter number b: ");
    scanf("%d", &number_b);
    printf("\nenter number c: ");
    scanf("%d", &number_c);
    find_largest(number_a, number_b, number_c);
    find_minor(number_a, number_b, number_c);
    return 0;
}