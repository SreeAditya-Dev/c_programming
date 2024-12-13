#include <stdio.h>
int main ()
{
    int a, b, c;
    printf ("Enter the first number:");
    scanf ("%d", &a);
    printf ("Enter the second number:");
    scanf ("%d", &b);
    printf ("Enter the third number:");
    scanf ("%d", &c);
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    printf ("The highest number out of %d, %d, %d is %d", a, b, c, max);
}
