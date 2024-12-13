#include <stdio.h>
int main()
{
    char word[100], temp;
    printf("Enter a string: ");
    scanf("%[^\n]%*c", word);
    for (int i = 0; word[i] != '\0'; i++)
    {
        for (int j = i + 1; word[j] != '\0'; j++)
        {
            if (word[i] > word[j])
            {
                temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
    printf("Sorted string: %s\n", word);
}
