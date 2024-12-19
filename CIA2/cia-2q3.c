#include <stdio.h>

long long factorialForLoop(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long factorialWhileLoop(int n) {
    long long result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

long long factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

void maxFactorialValue() {
    printf("Maximum values for factorial calculation:\n");
    printf("int: %lld\n", 20);  
    printf("long int: %lld\n", 170);  
    printf("long long int: %lld\n", 170);  
}

int main() {
    int choice, number;
    long long result;

    do {
        printf("Menu:\n");
        printf("1. Factorial using For Loop\n");
        printf("2. Factorial using While Loop\n");
        printf("3. Factorial using Recursion\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2 || choice == 3) {
            printf("Enter a positive number: ");
            scanf("%d", &number);

            if (number < 0) {
                printf("Invalid input, number must be positive.\n");
            } else {
                if (choice == 1) {
                    result = factorialForLoop(number);
                } else if (choice == 2) {
                    result = factorialWhileLoop(number);
                } else {
                    result = factorialRecursive(number);
                }
                printf("Factorial: %lld\n", result);
            }
        }
    } while (choice != 4);

    return 0;
}
