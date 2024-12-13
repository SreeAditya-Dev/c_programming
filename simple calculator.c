#include <stdio.h>

int main ()
{
    char choice, loop = 'y';
    float first, second;

    printf ("Enter the following to do the respective operation\n");
    printf ("a for Addition\n");
    printf ("b for Subtraction\n");
    printf ("c for Multiplication\n");
    printf ("d for Division\n");

    while (loop == 'y')
    {
        printf ("Enter your choice: ");
        scanf ("%c", &choice);
        getchar ();
        switch (choice)
        {
        case 'a':
            printf ("Enter the first number: ");
            scanf ("%f", &first);
            printf ("Enter the second number: ");
            scanf ("%f", &second);
            getchar ();
            printf ("The sum of %f and %f is: %f\n", first, second, first + second);
            break;
        case 'b':
            printf ("Enter the first number: ");
            scanf ("%f", &first);
            printf ("Enter the second number: ");
            scanf ("%f", &second);
            getchar ();
            printf ("The difference between %f and %f is: %f\n", first, second, first - second);
            break;
        case 'c':
            printf ("Enter the first number: ");
            scanf ("%f", &first);
            printf ("Enter the second number: ");
            scanf ("%f", &second);
            getchar ();
            printf ("The product of %f and %f is: %f\n", first, second, first * second);
            break;
        case 'd':
            printf ("Enter the first number: ");
            scanf ("%f", &first);
            printf ("Enter the second number: ");
            scanf ("%f", &second);
            getchar ();
            if (second == 0)
            {
                printf ("The second number cannot be zero.\n");
            }
            else
            {
                printf ("The result of %f divided by %f is: %f\n", first, second, first / second);
            }
            break;
        default:
            printf ("Invalid choice. Please enter 'a', 'b', 'c', or 'd'.\n");
            break;
        }
        printf ("Do you want to continue [y/n]:");
        scanf ("%c", &loop);
        getchar ();
    }
    if (loop != 'n')
    {
        printf ("wrong input !!!!!\n");
    }
    else
    {
        printf ("Thank you.");
    }
}

