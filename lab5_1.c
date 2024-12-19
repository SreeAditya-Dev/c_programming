#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 19) {
        printf("Error: Please provide exactly 18 integers as command-line arguments.\n");
        return 1;
    }

    int num[3][3][3];
    int inputnum[18];
    int index = 0;

    // Convert command-line arguments to integers and store in inputnum[]
    for (int i = 1; i < argc; i++) {
        inputnum[i-1] = atoi(argv[i]);
    }

    // Fill the first two matrices num[0] and num[1] with inputnum[]
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                num[k][i][j] = inputnum[index++];
            }
        }
    }

    // Calculate the sum of the first two matrices and store in num[2]
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            num[2][i][j] = num[0][i][j] + num[1][i][j];
        }
    }

    // Display the first matrix
    printf("Matrix 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", num[0][i][j]);
        }
        printf("\n");
    }

    // Display the second matrix
    printf("Matrix 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", num[1][i][j]);
        }
        printf("\n");
    }

    // Display the sum matrix
    printf("Sum of Matrices:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", num[2][i][j]);
        }
        printf("\n");
    }

    return 0;
}