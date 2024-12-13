#include <stdio.h>
#include <string.h>

// Function prototypes
void printDestinations(const char destinations[][30], int size, const float fares[]);
float calculateFare(const float fares[], int destinationIndex);
void printTicket(const char destination[], float fare);
void issueTicket(const char destinations[][30], const float fares[], int size);

int main() {
    // Array of destinations and corresponding fares
    const char destinations[][30] = {"Station A", "Station B", "Station C", "Station D"};
    const float fares[] = {10.0, 20.0, 30.0, 40.0};
    int destinationCount = sizeof(fares) / sizeof(fares[0]);

    int exitProgram = 0;

    while (!exitProgram) {
        printf("\n*** Metro Ticket Vending Machine ***\n");
        printf("1. View Destinations\n");
        printf("2. Issue Ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printDestinations(destinations, destinationCount, fares);
                break;
            case 2:
                issueTicket(destinations, fares, destinationCount);
                break;
            case 3:
                printf("Exiting the system. Have a great day!\n");
                exitProgram = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display available destinations and fares
void printDestinations(const char destinations[][30], int size, const float fares[]) {
    printf("\nAvailable Destinations:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Rs. %.2f\n", i + 1, destinations[i], fares[i]);
    }
}

// Function to calculate fare dynamically
float calculateFare(const float fares[], int destinationIndex) {
    return *(fares + destinationIndex); // Using pointer arithmetic
}

// Function to print the ticket
void printTicket(const char destination[], float fare) {
    printf("\n********** Metro Ticket **********\n");
    printf("Destination: %s\n", destination);
    printf("Fare: Rs. %.2f\n", fare);
    printf("**********************************\n");
}

// Function to issue a ticket
void issueTicket(const char destinations[][30], const float fares[], int size) {
    int destinationChoice;
    printDestinations(destinations, size, fares);

    printf("Enter the number corresponding to your destination: ");
    scanf("%d", &destinationChoice);

    if (destinationChoice < 1 || destinationChoice > size) {
        printf("Invalid selection. Please try again.\n");
        return;
    }

    destinationChoice--; // Adjust for zero-based index
    float fare = calculateFare(fares, destinationChoice);
    printf("The fare for %s is Rs. %.2f\n", destinations[destinationChoice], fare);

    float payment;
    printf("Enter payment amount: ");
    scanf("%f", &payment);

    if (payment < fare) {
        printf("Insufficient payment. Transaction failed.\n");
    } else {
        printTicket(destinations[destinationChoice], fare);
        if (payment > fare) {
            printf("Change returned: Rs. %.2f\n", payment - fare);
        }
        printf("Ticket successfully issued.\n");
    }
}
