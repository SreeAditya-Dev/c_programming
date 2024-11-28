#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct quiz_question {
    char question[200];
    char option[4][4][2000];
    char answer[20];
    char difficulty[10];

};
struct quiz_question arr[100]; // Array to hold up to 10 questions

void attend_Quiz(){
    for (int a=0;a<strlen(arr);a++){
        int ans[10];
        printf("Question: %s\n", arr[0].question);
        printf("Options:\n");
        for (int i = 0; i < 4; i++) {
            printf("%s\n", arr[0].option[i]);
        }
        printf("enter the option:");
        scanf("%d",&ans);

        printf("Correct Answer: %s\n", arr[0].answer);
        printf("Difficulty: %s\n", arr[0].difficulty);
    }


}

void main(){
    printf("enter the choice:\n1.attend Quiz\n2.add questions\n3.update questions\n4.remove the question\n");
    char name[30];
    printf("enter the name :");
    scanf("%s",name);
    int choice;
    scanf("%d",&choice);
    

    switch (choice)
    {
    case(1):
        
        break;
    
    default:
        break;
    }
    


    struct quiz_question q1={"how is pm of india",{{{{1},{"trump"}},{{2},{"modi"}},{{3},{"biden"}},{{4},{"stalin"}}},"b.modi","easy"}};
    printf("question: %s\n",q1.question);
    printf("options:\n\t%s\n\t%s\n\t%s\n\t%s\n",q1.option[0][0],q1.option[1][0],q1.option[2][0],q1.option[3][0]);
    printf("answer: %s\n",q1.answer);
    printf("difficulty: %s\n",q1.difficulty);
    printf("\n");
    struct quiz_question q2={"how is pm of india",{{{{1},{"trump"}},{{2},{"modi"}},{{3},{"biden"}},{{4},{"stalin"}}},"b.modi","easy"}};
    printf("question: %s\n",q2.question);
    printf("options:\n\t%s\n\t%s\n\t%s\n\t%s\n",q2.option[0][0],q2.option[1][0],q2.option[2][0],q2.option[3][0]);
    printf("answer: %s\n",q2.answer);
    printf("difficulty: %s",q2.difficulty);
    printf("\n");
    printf("\n");
    




}