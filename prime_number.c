#include <stdio.h>

int main() {
    int n, i;
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("%d is not a prime number.\n", n);
        return 0;
    }

    // Check divisibility
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            printf("%d is not a prime number.\n", n);  // If divisible, it's not prime
            return 0;  // Exit early since we know it's not prime
        }
    }

    // If no divisors were found
    printf("%d is a prime number.\n", n);

    return 0;
}
