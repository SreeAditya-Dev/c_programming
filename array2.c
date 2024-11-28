// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
   char arr1[3][3][100];
   char arr2[3][3][100];

   for (int i=0;i<3;i++){
    scanf("%s %s %s %s %s %s",arr1[i][0],arr1[i][1],arr1[i][2],arr2[i][0],arr2[i][1],arr2[i][2]);
   }
   

printf("%s",arr1[0][2]);
printf("\n");
   for (int i = 0; i < 1; i++) {
        printf("[%s %s %s]\n", arr1[i][0], arr1[i][1], arr1[i][2]);
    }
printf("\n");

   for (int i = 0; i < 3; i++) {
        printf("[%s %s %s][%s %s %s]\n", arr1[i][0], arr1[i][1], arr1[i][2],arr2[i][0], arr2[i][1], arr2[i][2]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("[%s %s %s]\n", arr2[i][0], arr2[i][1], arr2[i][2]);
    }
printf("\n");

for (int i = 0; i < 3; i++) {
        printf("[%s %s %s]\n",strcat(arr1[i][0],arr2[i][0]) , strcat(arr1[i][1],arr2[i][1]),strcat(arr1[i][2],arr2[i][2]));
    }


for (int i = 0; i < 3; i++) {
        printf("[%s %s %s]\n",arr1[i][0]arr2[i][0] , arr1[i][1]+arr2[i][1], arr1[i][2]+arr2[i][2]);
    }
    
}
