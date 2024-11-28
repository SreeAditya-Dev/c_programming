#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    int count = 0;
    char *token = strtok(str, " \n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \n");
    }
    printf("%d\n", count);
    return 0;
}
