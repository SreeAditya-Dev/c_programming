#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct quiz_question {
    char question[200];
    char option[4][200];
    char answer[20];
    char difficulty[10];
};

struct quiz_question arr[100];
int question_count = 0;

void add_question() {
    if (question_count < 100) {
        struct quiz_question q;
        printf("Enter the question: ");
        getchar();
        fgets(q.question, sizeof(q.question), stdin);
        q.question[strcspn(q.question, "\n")] = 0;
        
        for (int i = 0; i < 4; i++) {
            printf("Enter option %d: ", i + 1);
            fgets(q.option[i], sizeof(q.option[i]), stdin);
            q.option[i][strcspn(q.option[i], "\n")] = 0;
        }
        
        printf("Enter the correct answer: ");
        fgets(q.answer, sizeof(q.answer), stdin);
        q.answer[strcspn(q.answer, "\n")] = 0;
        
        printf("Enter the difficulty: ");
        fgets(q.difficulty, sizeof(q.difficulty), stdin);
        q.difficulty[strcspn(q.difficulty, "\n")] = 0;

        arr[question_count++] = q;
        printf("Question added successfully!\n");
    } else {
        printf("Question bank is full!\n");
    }
}

void attend_Quiz() {
    for (int i = 0; i < question_count; i++) {
        int ans;
        printf("Question: %s\n", arr[i].question);
        printf("Options:\n");
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, arr[i].option[j]);
        }
        printf("Enter the option number: ");
        scanf("%d", &ans);

        if (strcmp(arr[i].option[ans-1], arr[i].answer) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect! Correct Answer: %s\n", arr[i].answer);
        }
        printf("Difficulty: %s\n", arr[i].difficulty);
    }
}

void main() {
    int choice;
    do {
        printf("Enter the choice:\n1. Attend Quiz\n2. Add Questions\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (question_count > 0) {
                    attend_Quiz();
                } else {
                    printf("No questions available. Please add questions first.\n");
                }
                break;
            case 2:
                add_question();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}
