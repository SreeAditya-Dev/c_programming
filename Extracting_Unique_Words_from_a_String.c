#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isUnique(char *word, char words[][20], int count) {
    for (int i = 0; i < count; i++) {
        if (strcasecmp(word, words[i]) == 0) return 0;
    }
    return 1;
}

int main() {
    char str[100], words[20][20];
    fgets(str, sizeof(str), stdin);
    int count = 0;
    char *token = strtok(str, " ,.\n");
    while (token != NULL) {
        if (isUnique(token, words, count)) {
            strcpy(words[count++], token);
        }
        token = strtok(NULL, " ,.\n");
    }
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}
