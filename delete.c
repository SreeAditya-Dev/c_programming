#include <stdio.h>
#include <stdlib.h>

void deleteLine(const char *filename, int lineToDelete) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error: Cannot open temporary file.\n");
        fclose(file);
        return;
    }

    char buffer[1024];
    int currentLine = 1;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (currentLine != lineToDelete) {
            fputs(buffer, temp);
        }
        currentLine++;
    }

    fclose(file);
    fclose(temp);

    // Replace original file with the updated content
    remove(filename);
    rename("temp.txt", filename);

    printf("Line %d has been deleted successfully.\n", lineToDelete);
}

int main() {
    char filename[100];
    int lineToDelete;

    printf("Enter the file name: ");
    scanf("%s", filename);

    printf("Enter the line number to delete: ");
    scanf("%d", &lineToDelete);

    deleteLine(filename, lineToDelete);

    return 0;
}
