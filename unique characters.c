#include <stdio.h>
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);
    printf("The unique characters in the string are : \n");
    for (int i = 0; str[i] != '\0'; i++)
    {
        int uni = 1;
        for (int j = 0; str[j] != '\0'; j++)
        {
            if (str[i] == str[j] && i != j)
            {
                uni = 0;
                break;
            }
        }
        if (uni)
        {
            printf("%c \n", str[i]);
        }
    }
}
