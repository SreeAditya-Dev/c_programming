#include <stdio.h>

int main() {
    int ar[3][3]= {{1, 2, 8}, {3, 4, 9}, {5, 6, 0}};
    int *ptr = (int *)ar;  // Pointer to the first element of the array


    for (int i = 0; i < 3; i++) {
        printf("[%d %d %d]", ar[i][0], ar[i][1], ar[i][2]);
        printf("\n");
    }

    // Second part: Printing elements using pointer arithmetic
    printf("Pointer-based access:\n");
    for (int i = 0; i < 9; i++) {  // 3x3 matrix has 9 elements
        printf("[%d] ", *(ptr + i));  // Dereference the pointer to get the value
        if ((i + 1) % 3 == 0) printf("\n");  // Newline after every 3 elements
    }

    return 0;
}
