#include <stdio.h>

int main()
{
    int students, subjects = 4, assessments = 3;
    char subjectNames[4][10] = {"Maths  ", "English", "Science", "History"};
    printf("Enter the number of students: ");
    scanf("%d", &students);

    char studentNames[students][20];  // name of all the sutdents only
    float grades[students][4][3];     // input grades for 4 sub and each 3 test
    float subjectTotals[students][4]; // 3 test average
    float finalavgstu[students];      // total score of student (avg of 4 sub)
    float classAvgSub[4];
    char stugrades[students][4]; // students sub wise grading(a,b,c,d,e,f)

    for (int i = 0; i < students; i++)
    {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", studentNames[i]);

        for (int j = 0; j < subjects; j++)
        {
            printf("Enter grades for %s in %s (3 assessments): \n", studentNames[i], subjectNames[j]);
            printf("Enter the marks scored in the exams (out of 10) :");
            scanf("%f", &grades[i][j][0]);
            printf("Enter the marks scored in the quizzes (out of 10) :");
            scanf("%f", &grades[i][j][1]);
            printf("Enter the marks scored in the projects (out of 10) :");
            scanf("%f", &grades[i][j][2]);
        }
    }

    // Q1
    printf("\nStudent's Overall performance :\n");
    for (int i = 0; i < students; i++)
    {
        float finaltotal = 0;
        for (int j = 0; j < 4; j++)
        {
            float total = 0;
            for (int k = 0; k < 3; k++)
            {
                total += grades[i][j][k];
            }
            float avg = total / 3;
            subjectTotals[i][j] = avg;
            finaltotal += subjectTotals[i][j];
        }
        finalavgstu[i] = finaltotal / 4;
        printf(" Student name :%s \n Marks scored : %0.2f \n", studentNames[i], finalavgstu[i]);
    }

    // Q2
    printf("\nSubject wise class average :\n");
    for (int j = 0; j < subjects; j++)
    {
        float subtotal = 0;
        for (int i = 0; i < students; i++)
        {
            subtotal += subjectTotals[i][j];
        }
        classAvgSub[j] = subtotal / students;
        printf(" %s: %0.2f\n", subjectNames[j], classAvgSub[j]);
    }

    float max = finalavgstu[0];
    int stu = 0;
    for (int i = 1; i < students; i++)
    {
        if (finalavgstu[i] > max)
        {
            max = finalavgstu[i];
            stu = i;
        }
    }
    printf("\n");
    printf("Top performer student : \n");
    printf(" Student Name : %s \n", studentNames[stu]);
    printf(" Total marks scored : %0.2f \n", finalavgstu[stu]);

    // Q3
    printf("\nStudent's subject wise grades based on grading level : \n");
    for (int i = 0; i < students; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (subjectTotals[i][j] >= 9)
            {
                stugrades[i][j] = 'A';
            }
            else if (subjectTotals[i][j] >= 8)
            {
                stugrades[i][j] = 'B';
            }
            else if (subjectTotals[i][j] >= 7)
            {
                stugrades[i][j] = 'C';
            }
            else if (subjectTotals[i][j] >= 6)
            {
                stugrades[i][j] = 'D';
            }
            else if (subjectTotals[i][j] >= 5)
            {
                stugrades[i][j] = 'E';
            }
            else
            {
                stugrades[i][j] = 'F';
            }
        }
        printf(" Student name :%s \n", studentNames[i]);
        for (int j = 0; j < 4; j++)
        {
            printf("  %s : %c \n", subjectNames[j], stugrades[i][j]);
        }
    }

    // 4
    printf("\n");
    for (int j = 0; j < 4; j++)
    {
        printf("Students who need to be focused on the subject %s : \n", subjectNames[j]);
        int emp = 0;
        for (int i = 0; i < students; i++)
        {
            if (stugrades[i][j] == 'F')
            {
                printf("%s \n", studentNames[i]);
                emp = 1;
            }
        }
        if (emp == 0)
        {
            printf("None \n");
        }
    }
}
