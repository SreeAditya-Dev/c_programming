#include <stdio.h>

double my_sqrt(double x) {
    if (x < 0) {
        return -1; // Return -1 for negative input as error indication
    }
    double guess = x / 2.0; // Initial guess
    double epsilon = 0.00001; // Precision level
    while ((guess * guess - x) > epsilon || (x - guess * guess) > epsilon) {
        guess = (guess + x / guess) / 2.0; // Update guess
    }
    return guess;
}

int main() {
    double number;
    printf("Enter a non-negative number: ");
    scanf("%lf", &number);
    double result = my_sqrt(number);
    if (result == -1) {
        printf("Error: Cannot compute square root of a negative number.\n");
    } else {
        printf("The square root of %.2f is: %.5f\n", number, result);
    }
    return 0;
}
    