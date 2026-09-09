#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_value 100

void fill_array (int array[], int size){
    for (int i=0;i<size;i++){
        array[i]=rand() % (max_value + 1);
    }
}

void print_array (int array[], int size){
    printf("\nArray = (");
    for (int i=0;i<size;i++){
        printf(", %d",array[i]);
    }
    printf(")\n");
}

int is_prime (int number){
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

void count_prime_numbers (int array[], int size){
    int prime_numbers = 0;
    for (int i=0;i<size;i++){
        if (is_prime (array[i]) == 1){
            prime_numbers = prime_numbers + 1;
        }
    }
    print_array (array, size);
    printf ("There is a total of %d prime numbers.", prime_numbers);
}

int main (){
    srand(time(NULL));
    int array_size;
    printf("Enter the array size: ");
    scanf("%d", &array_size);
    if (array_size<=1){
        printf("\nInvalid number");
        return 1;
    }
    int array[array_size];
    fill_array(array, array_size);
    count_prime_numbers(array, array_size);
    return 0;
}