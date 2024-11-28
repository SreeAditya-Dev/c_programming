# include <stdio.h>
#include <string.h>

void main(){
    float mark[5][3];
    printf("calculate sum and avg of 5 students\n");
    for (int i=0;i<5;i++){
        printf("enter the mark student %d",i+1);
        scanf("%f",&mark[i][3]);
    }
    float sum=0;
    float avg;
    for (int j=0;j<5;j++){
        sum=sum+mark[j][3];
    }
    printf("sum of the five students is: %.2f\n",sum);
    avg=sum/5.0;
    printf("avg of the students is %.2f",avg);
}