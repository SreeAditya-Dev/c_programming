#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], words[20][20];
    int freq[20] = {0};
    fgets(str, sizeof(str), stdin);
    int count = 0;
    char *token = strtok(str, " ,.\n");
    while (token != NULL) {
        strcpy(words[count], token);
        for (int i = 0; i < count; i++) {
            if (strcasecmp(words[i], token) == 0) {
                freq[i]++;
                goto next;
            }
        }
        freq[count++] = 1;
        next:
        token = strtok(NULL, " ,.\n");
    }
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }
    return 0;
}
