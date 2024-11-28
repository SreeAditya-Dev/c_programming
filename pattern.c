#include <stdio.h>
#include <string.h>

// Function to render text as ASCII art (basic example)
void renderText(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        switch (text[i]) {
            case 'A':
                printf("    A\n   A A\n  AAAAA\n A     A\n");
                break;
            case 'D':
                printf(" DDDD\n D   D\n D   D\n DDDD\n");
                break;
            case 'I':
                printf(" III\n  I \n  I \n III\n");
                break;
            case 'T':
                printf(" TTTTT\n   T  \n   T  \n   T  \n");
                break;
            case 'Y':
                printf(" Y   Y\n  Y Y \n   Y  \n   Y  \n");
                break;
            default:
                printf(" %c\n", text[i]); // Default: print the character
        }
    }
}

// Function to apply color
void setColor(const char *color) {
    if (strcmp(color, "red") == 0)
        printf("\033[1;31m"); // Red
    else if (strcmp(color, "green") == 0)
        printf("\033[1;32m"); // Green
    else if (strcmp(color, "yellow") == 0)
        printf("\033[1;33m"); // Yellow
    else if (strcmp(color, "blue") == 0)
        printf("\033[1;34m"); // Blue
    else
        printf("\033[0m"); // Default (reset)
}

// Main function
int main() {
    char text[100];
    char color[20];

    printf("Enter the text you want to format: ");
    scanf("%s", text);

    printf("Enter the color you want (e.g., red, green, yellow): ");
    scanf("%s", color);

    setColor(color); // Apply the color
    renderText(text); // Render the text
    printf("\033[0m"); // Reset color

    return 0;
}
