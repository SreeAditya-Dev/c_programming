#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of contacts and name length
#define MAX_CONTACTS 100
#define NAME_LENGTH 50

// Function prototypes
void addContact(char names[][NAME_LENGTH], char **phoneNumbers, int *contactCount);
void searchContact(char names[][NAME_LENGTH], char **phoneNumbers, int contactCount);
void deleteContact(char names[][NAME_LENGTH], char **phoneNumbers, int *contactCount);

int main() {
    char names[MAX_CONTACTS][NAME_LENGTH];
    char *phoneNumbers[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    printf("Contact Management System\n");

    while (1) {
        // Menu options
        printf("\n1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(names, phoneNumbers, &contactCount);
                break;
            case 2:
                searchContact(names, phoneNumbers, contactCount);
                break;
            case 3:
                deleteContact(names, phoneNumbers, &contactCount);
                break;
            case 4:
                // Free allocated memory before exiting
                for (int i = 0; i < contactCount; i++) {
                    free(phoneNumbers[i]);
                }
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a contact
void addContact(char names[][NAME_LENGTH], char **phoneNumbers, int *contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    // Get name
    printf("Enter name: ");
    scanf("%s", names[*contactCount]);

    // Get phone number
    char tempPhone[20];
    printf("Enter phone number: ");
    scanf("%s", tempPhone);

    // Allocate memory for the phone number and store it
    phoneNumbers[*contactCount] = (char *)malloc(strlen(tempPhone) + 1);
    if (phoneNumbers[*contactCount] == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(phoneNumbers[*contactCount], tempPhone);

    (*contactCount)++;
    printf("Contact added successfully.\n");
}

// Function to search for a contact
void searchContact(char names[][NAME_LENGTH], char **phoneNumbers, int contactCount) {
    char searchName[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("Found: %s - %s\n", names[i], phoneNumbers[i]);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to delete a contact
void deleteContact(char names[][NAME_LENGTH], char **phoneNumbers, int *contactCount) {
    char deleteName[NAME_LENGTH];
    printf("Enter the name to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < *contactCount; i++) {
        if (strcmp(names[i], deleteName) == 0) {
            // Free the allocated memory for the phone number
            free(phoneNumbers[i]);

            // Shift remaining contacts
            for (int j = i; j < *contactCount - 1; j++) {
                strcpy(names[j], names[j + 1]);
                phoneNumbers[j] = phoneNumbers[j + 1];
            }
            (*contactCount)--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}
