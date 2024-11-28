#include <stdio.h>
#include <string.h>

int main() {
    char str[100], *tokens[20];
    fgets(str, sizeof(str), stdin);
    int count = 0;
    char *token = strtok(str, " \n");
    while (token != NULL) {
        tokens[count++] = token;
        token = strtok(NULL, " \n");
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%s%s", tokens[i], (i > 0) ? " " : "\n");
    }
    return 0;
}
