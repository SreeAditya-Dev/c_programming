#include <stdio.h>

void main(){
    int year;
    printf("enter the year to check whether it is leap year  are not:");
    scanf("%d",&year);
    
    if (year%400==0 || year%100==0 || year%4==0){
                printf("the given year %d is leap year\n",year);

    }
    else{
                printf("not a leap year\n");
    }
}