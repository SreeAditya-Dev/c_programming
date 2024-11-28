#include <stdio.h>  // Use stdio.h for input/output functions

int main() {
    char ar[3][3][100];  // Corrected array size for a 3x3 matrix of strings
    printf("Enter elements of matrix A (3x3):\n");
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%s", ar[i][j]);
        }
    }

    printf("Matrix A:\n");
    for (int i = 0; i < 3; i++) {
        printf("[%s %s %s]\n", ar[i][0], ar[i][1], ar[i][2]);
    }
    
    return 0;  // Return 0 to indicate successful execution
}
