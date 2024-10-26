#include <stdio.h>
#include <string.h>

int main() {
    // Example strings
    char str1[50] = "Hello, World!";
    char str2[50] = "Programming in C";
    char str3[50];
    char str4[50] = "Hello, World!";
    char *ptr;

    printf("Original strings:\n");
    printf("str1: %s\nstr2: %s\n", str1, str2);

    // 1. strlen() - Find length of a string
    printf("\n1. Length of str1: %zu\n", strlen(str1));

    // 2. strcpy() - Copy string from one to another
    strcpy(str3, str1);
    printf("2. Copy of str1 to str3: %s\n", str3);

    // 3. strncpy() - Copy specified number of characters
    strncpy(str3, str2, 11);  // Copy first 11 chars of str2 to str3
    str3[11] = '\0';  // Null terminate the string
    printf("3. Copy first 11 characters of str2 to str3: %s\n", str3);

    // 4. strcat() - Concatenate two strings
    strcat(str1, " Welcome!");
    printf("4. Concatenation of str1 with ' Welcome!': %s\n", str1);

    // 5. strncat() - Concatenate specified number of characters
    strncat(str2, " is fun ", 7);  // Add 7 characters of " is fun" to str2
    printf("5. Concatenation of first 7 characters to str2: %s\n", str2);

    // 6. strcmp() - Compare two strings (case-sensitive)
    // printf("%s\n %s", str1, str2);
    printf("6. Comparing str1 and str4: %d\n", strcmp(str1, str1));

    // 7. strncmp() - Compare first n characters
    printf("7. Comparing first 5 characters of str1 and str4: %d\n", strncmp(str1, str4, 5));

    // 8. strchr() - Find first occurrence of a character
    ptr = strchr(str1, 'W');
    printf("8. First occurrence of 'W' in str1: %s\n", ptr);

    // 9. strrchr() - Find last occurrence of a character
    ptr = strrchr(str1, 'o');
    printf("9. Last occurrence of 'o' in str1: %s\n", ptr);

    // 10. strstr() - Find first occurrence of a substring
    ptr = strstr(str1, "World");
    printf("10. First occurrence of 'World' in str1: %s\n", ptr);

    // 11. strtok() - Tokenize a string using delimiter
    char str5[50] = "C-programming, string-functions";
    char *token = strtok(str5, "-,");
    printf("11. Tokenizing str5: \n");
    while (token != NULL) {
        printf("   %s\n", token);
        token = strtok(NULL, "-,");
    }

    // 12. memset() - Fill memory with a constant byte
    memset(str3, '*', 5);  // Fill first 5 characters of str3 with '*'
    str3[5] = '\0';
    printf("12. Filling first 5 characters of str3 with '*': %s\n", str3);

    // 13. memcmp() - Compare memory areas
    int result = memcmp(str1, str4, 5);
    printf("13. Comparing first 5 bytes of str1 and str4: %d\n", result);

    // 14. memcpy() - Copy memory area
    memcpy(str3, str2, 7);  // Copy first 7 characters of str2 to str3
    str3[7] = '\0';
    printf("14. Copying first 7 bytes from str2 to str3: %s\n", str3);

    // 15. memmove() - Move memory area (safe for overlapping memory)
    memmove(str1 + 6, str1, 5);  // Move first 5 chars of str1 within the same string
    printf("15. Memory move within str1: %s\n", str1);

    return 0;
}
