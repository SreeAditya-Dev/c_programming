#include <string.h>
#include <stdio.h>


void main(){
    char str1[20]="hello";
    char str2[21]="hellom";
    char str3[5];
    // printf("%s",strcat(str1,str2));
    //printf("\n");
    //strcpy(str3,str1);
    //printf("%s",str3);
    printf("%d",strncmp(str1,str2,10));
    
}