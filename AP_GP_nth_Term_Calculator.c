#include <stdio.h>
int main()
{
    char choice, loop = 'y';
    printf("Enter the following to do the respective operation\n");
    printf("a for Arithmetic progression\n");
    printf("b for Geometric progression\n");
    while (loop == 'y')
    {
        int a, d, n, n_term, r;
        printf("Enter your choice: ");
        scanf("%c", &choice);
        getchar();
        switch (choice)
        {
        case 'a':
            printf("Enter the first term ,'a':");
            scanf("%d", &a);
            printf("Enter the common difference ,'d':");
            scanf("%d", &d);
            getchar();
            printf("Enter the value of 'n' to find the n th term :");
            scanf("%d", &n);
            getchar();
            if (n > 0)
            {
                n_term = a + ((n - 1) * d);
                printf("The n th term of the AP is : %d\n", n_term);
            }
            else
            {
                printf("The value of n cannot be less than 1 .\n");
            }
            break;
        case 'b':
            printf("Enter the first term ,'a':");
            scanf("%d", &a);
            printf("Enter the constant ratio ,'r':");
            scanf("%d", &r);
            getchar();
            printf("Enter the value of 'n' to find the n th term :");
            scanf("%d", &n);
            getchar();
            if (n > 0)
            {
                n_term = a;
                for (int i = 0; i < n - 1; i++)
                {
                    n_term = r * n_term;
                }
                printf("The n th term of the GP is : %d\n", n_term);
            }
            else
            {
                printf("The value of n cannot be less than 1 .\n");
            }
            break;

        default:
            printf("Invalid choice. Please enter 'a' or 'b'.\n");
            break;
        }
        printf("Do you want to continue [y/n]:");
        scanf("%c", &loop);
        getchar();
    }
    if (loop != 'n')
    {
        printf("wrong input !!!!!\n");
    }
    else
    {
        printf("Thank you.");
    }
}
