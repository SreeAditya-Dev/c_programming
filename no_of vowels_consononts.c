#include <stdio.h>
int main()
{
    char word[100];
    int vow = 0, cons = 0, other = 0;
    printf("Enter a string: ");
    scanf("%[^\n]%*c", word);
    for (int i = 0; word[i] != '\0'; i++)
    {
        char ch = word[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                vow++;
            }
            else
            {
                cons++;
            }
        }
        else
        {
            other++;
        }
    }
    printf("The no. of Vowels are : %d \n", vow);
    printf("The no. of consonants are : %d \n", cons);
    printf("The no. of other characters(including space) are : %d \n", other);
}
