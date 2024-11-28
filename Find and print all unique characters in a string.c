#include <stdio.h>

int main() {
    char str[100];
    int i, j, unique;

    printf("Enter a string: ");
    gets(str);

    printf("Unique characters: ");
    for (i = 0; str[i] != '\0'; i++) {
        unique = 1;
        for (j = 0; str[j] != '\0'; j++) {
            if (i != j && str[i] == str[j]) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            printf("%c ", str[i]);
        }
    }
    return 0;
}
