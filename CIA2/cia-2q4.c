#include <stdio.h>
#include <stdlib.h>

void matrixMultiplicationArray(int matrix1[3][3], int matrix2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void matrixMultiplicationPointer(int *matrix1, int *matrix2, int *result) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(result + i*3 + j) = 0;
            for (int k = 0; k < 3; k++) {
                *(result + i*3 + j) += (*(matrix1 + i*3 + k)) * (*(matrix2 + k*3 + j));
            }
        }
    }
}

void matrixMultiplicationDynamic(int rows1, int cols1, int rows2, int cols2, int **matrix1, int **matrix2, int **result) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void matrixMultiplicationRecursive(int matrix1[3][3], int matrix2[3][3], int result[3][3], int n) {
    if (n == 0) return;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    matrixMultiplicationRecursive(matrix1, matrix2, result, n - 1);
}

int main() {
    int matrix1[3][3], matrix2[3][3], result[3][3];

    printf("Enter elements for 3x3 matrix1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements for 3x3 matrix2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    matrixMultiplicationArray(matrix1, matrix2, result);
    printf("Result using array multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    matrixMultiplicationPointer(&matrix1[0][0], &matrix2[0][0], &result[0][0]);
    printf("Result using pointer multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    int **dynMatrix1 = (int **)malloc(3 * sizeof(int *));
    int **dynMatrix2 = (int **)malloc(3 * sizeof(int *));
    int **dynResult = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        dynMatrix1[i] = (int *)malloc(3 * sizeof(int));
        dynMatrix2[i] = (int *)malloc(3 * sizeof(int));
        dynResult[i] = (int *)malloc(3 * sizeof(int));
    }

    matrixMultiplicationDynamic(3, 3, 3, 3, dynMatrix1, dynMatrix2, dynResult);
    printf("Result using dynamic memory allocation:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", dynResult[i][j]);
        }
        printf("\n");
    }

    matrixMultiplicationRecursive(matrix1, matrix2, result, 3);
    printf("Result using recursion:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
