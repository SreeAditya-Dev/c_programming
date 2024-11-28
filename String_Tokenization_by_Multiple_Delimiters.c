#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    const char *delimiters = " ;.,";
    char *token = strtok(str, delimiters);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiters);
    }
    return 0;
}

