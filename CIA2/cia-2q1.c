#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 1000
#define MAX_INDENT 100

int count_indentation(char *line) {
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ') count++;
        else if (line[i] == '\t') count += 4; 
        else break;
    }
    return count;
}

int main() {
    char input_file[50], output_file[50];
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    FILE *infile = fopen(input_file, "r");
    if (infile == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    FILE *outfile = fopen(output_file, "w");
    if (outfile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(infile);
        return 1;
    }

    char *groups[MAX_INDENT][MAX_LINES] = {NULL};
    int group_counts[MAX_INDENT] = {0};
    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, infile)) {
        int indent = count_indentation(line);
        groups[indent][group_counts[indent]++] = strdup(line);
    }

    for (int i = 0; i < MAX_INDENT; i++) {
        if (group_counts[i] > 0) {
            for (int j = 0; j < group_counts[i]; j++) {
                fprintf(outfile, "%s", groups[i][j]);
                free(groups[i][j]);
            }
            fprintf(outfile, "\n");
        }
    }

    fclose(infile);
    fclose(outfile);
    printf("File processing complete.\n");
    return 0;
}
