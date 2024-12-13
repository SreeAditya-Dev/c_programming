#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Insert at the end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (!head) return newNode; // If list is empty
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Delete a node by value
Node* deleteByValue(Node* head, int value) {
    if (!head) {
        printf("List is empty.\n");
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;

    // If the head node is to be deleted
    if (temp->data == value) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the node to delete
    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Value not found in the list.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// Traverse and display the list
void displayList(Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search for a value in the list
void search(Node* head, int value) {
    Node* temp = head;
    int position = 0;
    while (temp) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}

// Main function
int main() {
    Node* head = NULL; // Initialize the linked list as empty

    // Insert elements
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Initial List:\n");
    displayList(head);

    // Search for a value
    search(head, 30);
    search(head, 50);

    // Delete a value
    printf("After deleting 20:\n");
    head = deleteByValue(head, 20);
    displayList(head);

    printf("After deleting 10:\n");
    head = deleteByValue(head, 10);
    displayList(head);

    // Free the remaining memory
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}