#include <stdio.h>

void print(char name[100][100], int mark[100][4], int nos) { 
    //char sub[4][20] = {"Mathematics", "English", "Science", "History"};
    
    for (int i = 0; i < nos; i++) {
        printf("name: %s\n", name[i]);
        printf("[");
        for (int j = 0; j < 4; j++) {
            printf("%d ",mark[i][j]);
        }
        printf("]");
        printf("\n"); 
}
}

int main() { 
    char name[100][100]; 
    int mark[100][4];
    char sub[4][20] = {"Mathematics", "English", "Science", "History"}; 
    char top[3][20] = {"exams", "quizzes", "projects"}; 
    int nos = 0;
    int r;
    
    printf("Enter the number of students: ");
    scanf("%d", &nos); 
    
    printf("Enter the details of the students:\n");

    for (int i=0;i<nos;i++){
        printf("enter the name:");
        scanf("%s",name[i]);
        printf("enter the mark of the student marks\n");
        for (int j=0;j<4;j++){
            printf("enter the %s mark\n",sub[j]);
            int m=0;
            for (int k=0;k<3;k++){
                printf("enter the mark in %s ",top[k]);
                scanf("%d",&r);
                m=m+r;
            mark[i][j]=m;
                

        }
    }
    }

    print(name, mark, nos); 

    return 0; 
}
