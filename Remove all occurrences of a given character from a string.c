#include <stdio.h>

int main() {
    char str[100], ch;
    int i, j = 0;
    char result[100];

    printf("Enter a string: ");
    gets(str);
    printf("Enter the character to remove: ");
    scanf("%c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    printf("String after removal: %s\n", result);
    return 0;
}
