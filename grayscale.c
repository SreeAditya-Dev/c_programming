#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an RGB pixel
typedef struct {
    int R;
    int G;
    int B;
} RGB;

// Function to apply grayscale filter to an image matrix
void apply_grayscale(RGB **image, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Convert RGB to grayscale using the formula
            int gray = (int)(0.3 * image[i][j].R + 0.59 * image[i][j].G + 0.11 * image[i][j].B);
            image[i][j].R = image[i][j].G = image[i][j].B = gray;  // Set all RGB values to the grayscale value
        }
    }
}

// Function to print the grayscale matrix
void print_grayscale(RGB **image, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d, %d) ", image[i][j].R, image[i][j].G, image[i][j].B);
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the image matrix
void free_image(RGB **image, int m) {
    for (int i = 0; i < m; i++) {
        free(image[i]);
    }
    free(image);
}

int main() {
    int m, n; // Number of rows and columns for the image matrix

    // Get dimensions of the image from the user
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    // Allocate memory for the image matrix
    RGB **image = (RGB **)malloc(m * sizeof(RGB *));
    for (int i = 0; i < m; i++) {
        image[i] = (RGB *)malloc(n * sizeof(RGB));
    }

    // Get RGB values for each pixel from the user
    printf("Enter RGB values for each pixel (R, G, B) in the format 'R G B':\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter RGB values for pixel (%d, %d):\n", i, j);
            printf("  Red (0-255): ");
            scanf("%d", &image[i][j].R);
            printf("  Green (0-255): ");
            scanf("%d", &image[i][j].G);
            printf("  Blue (0-255): ");
            scanf("%d", &image[i][j].B);
        }
    }

    // Apply grayscale filter
    apply_grayscale(image, m, n);

    // Print the grayscale image
    printf("\nGrayscale Image:\n");
    print_grayscale(image, m, n);

    // Free the allocated memory
    free_image(image, m);

    return 0;
}
