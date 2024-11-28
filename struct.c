#include <stdio.h>

struct details
{
    char name[200];
    union con {
        int phone_no;
        char mail[500];
    } contact;
    int choice;  
};

void main() {
    int a;
    printf("Contact Management System\n");
    printf("How many contacts would you like to store? ");
    scanf("%d", &a);
    printf("\n");

    struct details *contacts = malloc(a * sizeof(struct details));

    for (int i = 0; i < a; i++) {
        printf("Enter the name: ");
        scanf("%s", contacts[i].name);

        printf("Do you need to enter: \n1. Email\n2. Phone Number\n");
        scanf("%d", &contacts[i].choice);

        if (contacts[i].choice == 1) {
            printf("Enter the email: ");
            scanf("%s", contacts[i].contact.mail);
        }
        else if (contacts[i].choice == 2) {
            printf("Enter the phone number: ");
            scanf("%d", &contacts[i].contact.phone_no);
        }
        else {
            printf("Invalid choice! Please enter a valid option (1 or 2).\n");
        }
    }


    printf("\nStored Contacts:\n");
    for (int i = 0; i < a; i++) {
        printf("\nName: %s\n", contacts[i].name);
        if (contacts[i].choice == 1) {
            printf("Email: %s\n", contacts[i].contact.mail);
        } else if (contacts[i].choice == 2) {
            printf("Phone Number: %d\n", contacts[i].contact.phone_no);
        }
    }
}

