#include <string.h>

void main(){
    char ar[3][100][3];
    printf("Enter elements of matrix A (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%s", ar[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("[%s %s %s]", ar[i][0], ar[i][1], ar[i][2]);
        printf("\n");
    }
}