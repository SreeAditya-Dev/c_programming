//Database System for Student Records Using Multidimensional Arrays and Double Pointers

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int id;
    int *scores;
    int numSubjects;
} Student;

// Function to add a new student record
void addStudent(Student **students, int *count, int subjects) {
    *students = (Student *)realloc(*students, (*count + 1) * sizeof(Student));
    Student *newStudent = &(*students)[*count];

    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent->id);

    newStudent->numSubjects = subjects;
    newStudent->scores = (int *)malloc(subjects * sizeof(int));

    printf("Enter scores for %d subjects: ", subjects);
    for (int i = 0; i < subjects; i++) {
        scanf("%d", &newStudent->scores[i]);
    }

    (*count)++;
}

// Function to calculate and display average score for each student
void displayRecords(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("\nStudent Name: %s, ID: %d\n", students[i].name, students[i].id);
        int total = 0;
        for (int j = 0; j < students[i].numSubjects; j++) {
            total += students[i].scores[j];
        }
        printf("Average Score: %.2f\n", (double)total / students[i].numSubjects);
    }
}

// Free allocated memory
void freeRecords(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        free(students[i].scores);
    }
    free(students);
}

int main() {
    Student *students = NULL;
    int studentCount = 0, subjects;

    printf("Enter the number of subjects for each student: ");
    scanf("%d", &subjects);

    int choice;
    do {
        printf("\n1. Add Student Record\n2. Display All Records\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent(&students, &studentCount, subjects);
            break;
        case 2:
            displayRecords(students, studentCount);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    freeRecords(students, studentCount);

    return 0;
}
