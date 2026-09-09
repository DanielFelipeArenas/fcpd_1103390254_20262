#include <stdio.h>

int sum_recursion(int number){
    if (number == 0) { 
        return 0;
    } 
    return (number % 10) + sum_recursion(number / 10);
}

int main(){
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    printf("\nthe sum of the digits is: %d", sum_recursion(number));
    return 0;
}