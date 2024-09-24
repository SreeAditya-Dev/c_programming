#include <stdio.h>
int main() {
    char a[5][20];  // Array to store 5 names, each with a maximum length of 19 characters + null terminator
    
    printf("Enter the names of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", a[i]);  // Reading each string (no need for '&')
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", a[i]);  // Printing each string
    }

    return 0;
}
