// Booking System for Movie Theater Seats Using a Jagged Array

#include <stdio.h>
#include <stdlib.h>

// Function to book a seat
void bookSeat(int **seats, int row, int seat) {
    if (seats[row][seat] == 0) {
        seats[row][seat] = 1;
        printf("Seat booked successfully!\n");
    } else {
        printf("Seat already booked!\n");
    }
}

// Function to cancel a booking
void cancelSeat(int **seats, int row, int seat) {
    if (seats[row][seat] == 1) {
        seats[row][seat] = 0;
        printf("Booking cancelled!\n");
    } else {
        printf("Seat was not booked!\n");
    }
}

// Function to display the seating arrangement
void displaySeats(int **seats, int rows, int *seatsPerRow) {
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < seatsPerRow[i]; j++) {
            printf("%d ", seats[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int **seats = (int **)malloc(rows * sizeof(int *));
    int *seatsPerRow = (int *)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        printf("Enter the number of seats in row %d: ", i + 1);
        scanf("%d", &seatsPerRow[i]);

        seats[i] = (int *)malloc(seatsPerRow[i] * sizeof(int));

        for (int j = 0; j < seatsPerRow[i]; j++) {
            seats[i][j] = 0; // All seats are initially available
        }
    }

    int choice, row, seat;
    do {
        printf("\n1. Book a Seat\n2. Cancel Booking\n3. Display Seats\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter row and seat to book: ");
            scanf("%d %d", &row, &seat);
            bookSeat(seats, row - 1, seat - 1);
            break;
        case 2:
            printf("Enter row and seat to cancel: ");
            scanf("%d %d", &row, &seat);
            cancelSeat(seats, row - 1, seat - 1);
            break;
        case 3:
            displaySeats(seats, rows, seatsPerRow);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(seats[i]);
    }
    free(seats);
    free(seatsPerRow);

    return 0;
}
