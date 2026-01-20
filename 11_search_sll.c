#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertNode(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int searchNode(Node *head, int value) {
    int position = 1;
    
    while (head != NULL) {
        if (head->data == value) {
            return position;
        }
        head = head->next;
        position++;
    }
    
    return -1;
}

void displayList(Node *head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int n, value, searchValue;
    
    printf("Search in Singly Linked List\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertNode(&head, value);
    }
    
    displayList(head);
    
    printf("\nEnter the number to search: ");
    scanf("%d", &searchValue);
    
    int position = searchNode(head, searchValue);
    
    if (position != -1) {
        printf("Number %d found at position %d\n", searchValue, position);
    } else {
        printf("Number %d not found in the list\n", searchValue);
    }
    
    return 0;
}
