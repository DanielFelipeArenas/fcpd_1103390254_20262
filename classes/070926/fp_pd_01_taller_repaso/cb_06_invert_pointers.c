/*
 * @file cb_06_invert_pointers.c
 * @brief exercise in reversing the numbers in an array in C
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-12
*/
#include <stdio.h>

void print_array (int array[], int size){
    printf("\nArray = (");
    for (int i=0;i<size;i++){
        if (i==size-1){
            printf("%d",array[i]);
        }else{
            printf("%d, ",array[i]);
        }
    }
    printf(")\n");
}

int determine_center (int size){
    return (size%2==0) ? size/2 : (size-1)/2;
}

void invert_array(int array[], int size){
    int *pointer_a, *pointer_b,j=size-1,temp;
    for (int i = 0;i<determine_center(size);i++){
        pointer_a=&array[i];
        pointer_b=&array[j];
        
        temp = *pointer_a;
        *pointer_a=*pointer_b;
        *pointer_b=temp;

        j--;
    }
}

int main(){
    printf("Test 1 with even size:");
    int array[6] = {1,2,3,4,5,6};
    print_array(array,6);
    invert_array(array,6);
    print_array(array,6);
    printf("\nTest 2 with odd size:");
    int array_b[5] = {1,2,3,4,5};
    print_array(array_b,5);
    invert_array(array_b,5);
    print_array(array_b,5);
    return 0;
}