#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file_content[1000], clipboard[1000], temp[1000];
    char file_name[100];
    int choice, start, end;
    
    printf("Enter the file name: ");
    scanf("%s", file_name);
    
    // Open the file in read mode
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s. Please check if the file exists.\n", file_name);
        return 1; // Return with error code
    }

    // Read file content into file_content buffer
    fread(file_content, sizeof(char), sizeof(file_content) - 1, file);  // Leave space for the null terminator
    file_content[sizeof(file_content) - 1] = '\0'; // Ensure null termination
    fclose(file);

    do {
        printf("1. Cut  2. Copy  3. Paste  4. Duplicate  5. Find  6. Replace  7. Save 8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) { 
            printf("Enter range (start end): ");
            scanf("%d %d", &start, &end);
            if (start < 0 || end >= strlen(file_content) || start > end) {
                printf("Invalid range.\n");
            } else {
                strncpy(temp, file_content + end, strlen(file_content) - end);
                strncpy(file_content + start, temp, strlen(temp) + 1);
            }
        }
        else if (choice == 2) {
            printf("Enter range (start end): ");
            scanf("%d %d", &start, &end);
            if (start < 0 || end >= strlen(file_content) || start > end) {
                printf("Invalid range.\n");
            } else {
                strncpy(clipboard, file_content + start, end - start);
                clipboard[end - start] = '\0';  // Null-terminate clipboard
            }
        }
        else if (choice == 3) {
            printf("Enter position: ");
            scanf("%d", &start);
            if (start < 0 || start >= strlen(file_content)) {
                printf("Invalid position.\n");
            } else {
                strcpy(temp, file_content + start);
                strcpy(file_content + start, clipboard);
                strcat(file_content, temp);
            }
        }
        else if (choice == 4) {
            printf("Duplicate content: %s\n", file_content);
        }
        else if (choice == 5) {
            printf("Enter word to find: ");
            scanf("%s", temp);
            char *ptr = strstr(file_content, temp);
            while (ptr) {
                printf("Found at: %ld\n", ptr - file_content);
                ptr = strstr(ptr + 1, temp);  // Find next occurrence
            }
        }
        else if (choice == 6) {
            printf("Enter word to replace: ");
            scanf("%s", temp);
            char replace[100];
            printf("Enter replacement word: ");
            scanf("%s", replace);
            char *ptr = strstr(file_content, temp);
            while (ptr) {
                strncpy(ptr, replace, strlen(replace));
                ptr = strstr(ptr + strlen(replace), temp);  // Find next occurrence
            }
        }
        else if (choice == 7) {
            // Open the file in write mode and save the modified content
            file = fopen(file_name, "w");
            if (file == NULL) {
                printf("Error opening file %s for writing.\n", file_name);
                return 1;
            }
            fprintf(file, "%s", file_content);  // Write modified content to the file
            fclose(file);
            printf("File content saved successfully.\n");
        }
    } while (choice != 8);
    
    return 0;
}
