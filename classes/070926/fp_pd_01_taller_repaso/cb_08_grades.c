/*
 * @file cb_08_grades.c
 * @brief exercise on assigning a letter based on a numerical value
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-12
*/
#include <stdio.h>

void grades(int note){
    if (note<=20 && note>=0){
        printf("F");
    }else if (note<=40 && note>20){
        printf("D");
    }else if (note<=60 && note>40){
        printf("C");
    }else if (note<=80 && note>60){
        printf("B");
    }else if (note<=100 && note>80){
        printf("A");
    }else{
        printf("invalid grade");
    }
}

int main(){
    grades (30);
    return 0;
}