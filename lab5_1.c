#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 1;
    }

    int rows = 0;
    int cols = 0;

    for (char *p = argv[1]; *p; p++) {
        rows = rows * 10 + (*p - '0');
    }
    for (char *p = argv[2]; *p; p++) {
        cols = cols * 10 + (*p - '0');
    }

    int **matrix;
    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    int index = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = 0;
            for (char *p = argv[index]; *p; p++) {
                value = value * 10 + (*p - '0');
            }
            matrix[i][j] = value;
            index++;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {./matrix_program 2 2 1 2 3 4

        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
