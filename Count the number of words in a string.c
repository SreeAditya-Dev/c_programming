#include <stdio.h>

int main() {
    char str[100];
    int i, word_count = 1;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0') {
            word_count++;
        }
    }

    printf("Number of words: %d\n", word_count);
    return 0;
}
