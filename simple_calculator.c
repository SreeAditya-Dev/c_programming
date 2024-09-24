#include <stdio.h>
#include <math.h>

int main() {
    float a, b;
    int choice;
    printf("\n<<<<<<<< Simple Calculator >>>>>>>>\n");
    printf("Choices:\n 1. Add\n 2. Subtract\n 3. Multiply\n 4. Division\n 5. Power\n 6. Square Root\n 7. Exit\n");

    do {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                printf("Addition result: %f\n", a + b);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                printf("Subtraction result: %f\n", a - b);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                printf("Multiplication result: %f\n", a * b);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                if (b != 0) {
                    printf("Division result: %f\n", a / b);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;

            case 5:
                printf("Enter base and exponent: ");
                scanf("%f %f", &a, &b);
                printf("Power result: %f\n", pow(a, b));
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%f", &a);
                if (a >= 0) {
                    printf("Square root result: %f\n", sqrt(a));
                } else {
                    printf("Error: Square root of a negative number is not possible.\n");
                }
                break;

            case 7:
                printf("Exiting the calculator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7); 

    return 0;
}
