/*
 * @file cb_10_academic_system.c
 * @brief exercise involving a basic academic system
 * @author Daniel Felipe Arenas Gómez
 * @date 2026-09-12
*/
#include <stdio.h>
#include <stdlib.h>

#define PASSING_GRADE 3.0

struct Student {
    int id;
    char name[50];
    float grades[3];
    float average;
};

void inputStudents(struct Student *students, int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);

        for (int j = 0; j < 3; j++) {
            printf("Grade %d: ", j + 1);
            scanf("%f", &students[i].grades[j]);
        }
    }
}

void calculateAverages(struct Student *students, int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        float sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].grades[j];
        }
        students[i].average = sum / 3;
    }
}

void printAverages(struct Student *students, int studentCount) {
    printf("\n--- Averages ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s (ID %d): %.2f\n", students[i].name, students[i].id, students[i].average);
    }
}

void printApproved(struct Student *students, int studentCount) {
    printf("\n--- Approved ---\n");
    for (int i = 0; i < studentCount; i++) {
        if (students[i].average >= PASSING_GRADE) {
            printf("%s (ID %d): %.2f\n", students[i].name, students[i].id, students[i].average);
        }
    }
}

int main() {
    int studentCount;

    printf("Number of students: ");
    scanf("%d", &studentCount);

    struct Student *students = malloc(studentCount * sizeof(struct Student));

    inputStudents(students, studentCount);
    calculateAverages(students, studentCount);
    printAverages(students, studentCount);
    printApproved(students, studentCount);

    free(students);

    return 0;
}