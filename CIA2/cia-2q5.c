#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a string with dynamic memory allocation
char* readStringDynamic() {
    char *str = (char*)malloc(100 * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    return str;
}

// Function to read a string with a predefined size
char* readStringPredefined(int size) {
    char *str = (char*)malloc(size * sizeof(char)); // Dynamically allocate memory
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter a string: ");
    fgets(str, size, stdin);
    if (strlen(str) >= size - 1) {
        printf("Input too long, truncating.\n");
    }
    return str;
}

// Function to compare both string input methods
void compareFunctions() {
    char *str1 = readStringDynamic();
    printf("Dynamic String: %s\n", str1);
    free(str1);

    int size = 50;
    char* str2 = readStringPredefined(size);
    printf("Predefined String: %s\n", str2);
    free(str2); // Don't forget to free the memory allocated for the predefined string
}

int main() {
    int choice;
    printf("Choose a string input method:\n1. Dynamic allocation\n2. Predefined size\n");
    scanf("%d", &choice);
    getchar();  // Consume the newline character left by scanf

    if (choice == 1) {
        char* str = readStringDynamic();
        printf("Dynamic Input: %s\n", str);
        free(str);
    } else if (choice == 2) {
        int size = 50;
        char* str = readStringPredefined(size);
        printf("Predefined Input: %s\n", str);
        free(str);
    } else {
        printf("Invalid choice.\n");
    }

    compareFunctions(); // Compare both methods
    return 0;
}
