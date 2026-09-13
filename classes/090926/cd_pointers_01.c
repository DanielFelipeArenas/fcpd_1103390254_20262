/*
 * @file cd_pointers_01.c
 * @brief basic Exercise of pointers in C
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-09
*/
#include <stdio.h>

void swap_pointer(int *number_a, int *number_b){
    int temp = *number_a;
    *number_a= *number_b;
    *number_b= temp;
}

int main(){
    int x = 52;
    int y = 23;
    printf("Before\nX = %d\nY = %d",x,y);
    swap_pointer(&x,&y);
    printf("\nAfter\nX = %d\nY = %d",x,y);
    return 0;
}