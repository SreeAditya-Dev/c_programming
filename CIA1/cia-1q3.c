#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);
    return root;
}

Node* sortArray(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
    return root;
}

Node* searchNode(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return searchNode(root->left, value);
    return searchNode(root->right, value);
}

void printTree(Node* root, int level) {
    if (root != NULL) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++)
            printf("  ");
        printf("%d\n", root->data);
        printTree(root->left, level + 1);
    }
}

int main() {
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = sortArray(arr, n);
    printTree(root, 0);
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);
    Node* result = searchNode(root, value);
    if (result != NULL)
        printf("Value found: %d\n", result->data);
    else
        printf("Value not found\n");
    return 0;
}
