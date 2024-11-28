#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NUM_SUBJECTS 4


void inputStudentData(char names[][50], int rollNumbers[], float grades[][NUM_SUBJECTS], int numStudents);
void calculateAverages(float grades[][NUM_SUBJECTS], float averages[], int numStudents);
void classAverage(float grades[][NUM_SUBJECTS], int numStudents);
void topPerformers(char names[][50], float averages[], int numStudents);
void gradingStatistics(float averages[], int numStudents);
void focusSuggestion(char names[][50], float averages[], int numStudents);

int main() {
    char names[MAX_STUDENTS][50];
    int rollNumbers[MAX_STUDENTS];
    float grades[MAX_STUDENTS][NUM_SUBJECTS];
    float averages[MAX_STUDENTS];
    int numStudents;
    
 
    printf("Enter number of students: ");
    scanf("%d", &numStudents);
    

    inputStudentData(names, rollNumbers, grades, numStudents);
    

    calculateAverages(grades, averages, numStudents);
    

    classAverage(grades, numStudents);
    topPerformers(names, averages, numStudents);
    

    gradingStatistics(averages, numStudents);
    
 
    focusSuggestion(names, averages, numStudents);
    
    return 0;
}


void inputStudentData(char names[][50], int rollNumbers[], float grades[][NUM_SUBJECTS], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter name for student %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &rollNumbers[i]);

        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter grade for subject %d (0-100): ", j + 1);
            scanf("%f", &grades[i][j]);
        }
    }
}


void calculateAverages(float grades[][NUM_SUBJECTS], float averages[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        float sum = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            sum += grades[i][j];
        }
        averages[i] = sum / NUM_SUBJECTS;
    }
}


void classAverage(float grades[][NUM_SUBJECTS], int numStudents) {
    float subjectTotals[NUM_SUBJECTS] = {0};
    
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            subjectTotals[j] += grades[i][j];
        }
    }

    printf("\nClass Averages per subject:\n");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("Subject %d average: %.2f\n", j + 1, subjectTotals[j] / numStudents);
    }
}


void topPerformers(char names[][50], float averages[], int numStudents) {
    float highestAverage = 0;
    char topStudent[50];
    
    for (int i = 0; i < numStudents; i++) {
        if (averages[i] > highestAverage) {
            highestAverage = averages[i];
            strcpy(topStudent, names[i]);
        }
    }
    
    printf("\nTop Performer: %s with an average of %.2f\n", topStudent, highestAverage);
}


void gradingStatistics(float averages[], int numStudents) {
    int gradeCount[5] = {0};
    
    for (int i = 0; i < numStudents; i++) {
        if (averages[i] >= 90) gradeCount[0]++; 
        else if (averages[i] >= 80) gradeCount[1]++; 
        else if (averages[i] >= 70) gradeCount[2]++; 
        else if (averages[i] >= 60) gradeCount[3]++; 
        else gradeCount[4]++; 
    }
    
    printf("\nGrading Statistics:\n");
    printf("A: %d\nB: %d\nC: %d\nD: %d\nFail: %d\n", gradeCount[0], gradeCount[1], gradeCount[2], gradeCount[3], gradeCount[4]);
}


void focusSuggestion(char names[][50], float averages[], int numStudents) {
    printf("\nStudents Needing Focus:\n");
    for (int i = 0; i < numStudents; i++) {
        if (averages[i] < 60) {
            printf("%s needs attention with an average of %.2f\n", names[i], averages[i]);
        }
    }
}
