/*
 * @file cb_04_factorial_parity.c
 * @brief exercise on factorial, greater and lesser in C
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-07
*/
#include <stdio.h>

void is_even (int number){
    (number%2 == 0) ? printf("\nits even\n") : printf("\nits odd\n");
}

int factorial (int number){
    for (int i = (number-1); i>1; i--){
        number = number * i;
    }
    return number;
}

int main(){
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    if (number<0){
        printf("\nInvalid number");
        return 1;
    }
    is_even(number);
    printf("factorial of %d is %d",number, factorial(number));
    return 0;
}