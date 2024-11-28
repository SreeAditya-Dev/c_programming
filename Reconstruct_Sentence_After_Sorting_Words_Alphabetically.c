#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return strcasecmp(*(const char **)a, *(const char **)b);
}

int main() {
    char str[100], *tokens[20];
    fgets(str, sizeof(str), stdin);
    int count = 0;
    char *token = strtok(str, " \n");
    while (token != NULL) {
        tokens[count++] = token;
        token = strtok(NULL, " \n");
    }
    qsort(tokens, count, sizeof(char *), compare);
    for (int i = 0; i < count; i++) {
        printf("%s%s", tokens[i], (i < count - 1) ? " " : "\n");
    }
    return 0;
}
