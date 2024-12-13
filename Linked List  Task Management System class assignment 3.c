#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Task structure
typedef struct Task {
    int task_id;
    char description[100];
    char assigned_person[50];
    char deadline[15];
    char status[15];
    struct Task* next;
} Task;

// Function to create a new task node
Task* createTask(int id, char* description, char* person, char* deadline, char* status) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    newTask->task_id = id;
    strcpy(newTask->description, description);
    strcpy(newTask->assigned_person, person);
    strcpy(newTask->deadline, deadline);
    strcpy(newTask->status, status);
    newTask->next = NULL;
    return newTask;
}

// Function to add a new task to the linked list
void addTask(Task** head, int id, char* description, char* person, char* deadline, char* status) {
    Task* newTask = createTask(id, description, person, deadline, status);
    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

// Function to update the status of a task by its ID
void updateTaskStatus(Task* head, int id, char* newStatus) {
    Task* temp = head;
    while (temp != NULL) {
        if (temp->task_id == id) {
            strcpy(temp->status, newStatus);
            printf("Task %d status updated to '%s'.\n", id, newStatus);
            return;
        }
        temp = temp->next;
    }
    printf("Task with ID %d not found.\n", id);
}

// Function to delete a completed task by its ID
void deleteCompletedTask(Task** head, int id) {
    Task *temp = *head, *prev = NULL;
    while (temp != NULL && temp->task_id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Task with ID %d not found.\n", id);
        return;
    }
    if (strcmp(temp->status, "Completed") != 0) {
        printf("Task %d is not marked as 'Completed'. Cannot delete.\n", id);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Task %d deleted successfully.\n", id);
}

// Function to display all tasks
void displayTasks(Task* head) {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }
    Task* temp = head;
    while (temp != NULL) {
        printf("Task ID: %d\n", temp->task_id);
        printf("Description: %s\n", temp->description);
        printf("Assigned Person: %s\n", temp->assigned_person);
        printf("Deadline: %s\n", temp->deadline);
        printf("Status: %s\n", temp->status);
        printf("--------------------------\n");
        temp = temp->next;
    }
}

// Main function to demonstrate the Task Management System
int main() {
    Task* head = NULL;
    int choice, id;
    char description[100], person[50], deadline[15], status[15];

    do {
        printf("\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. Update Task Status\n");
        printf("3. Delete Completed Task\n");
        printf("4. Display All Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter Task ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Task Description: ");
                fgets(description, 100, stdin);
                description[strcspn(description, "\n")] = '\0';
                printf("Enter Assigned Person: ");
                fgets(person, 50, stdin);
                person[strcspn(person, "\n")] = '\0';
                printf("Enter Deadline (DD/MM/YYYY): ");
                fgets(deadline, 15, stdin);
                deadline[strcspn(deadline, "\n")] = '\0';
                printf("Enter Status: ");
                fgets(status, 15, stdin);
                status[strcspn(status, "\n")] = '\0';
                addTask(&head, id, description, person, deadline, status);
                break;
            case 2:
                printf("Enter Task ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new status: ");
                fgets(status, 15, stdin);
                status[strcspn(status, "\n")] = '\0';
                updateTaskStatus(head, id, status);
                break;
            case 3:
                printf("Enter Task ID to delete: ");
                scanf("%d", &id);
                deleteCompletedTask(&head, id);
                break;
            case 4:
                displayTasks(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory
    Task* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
