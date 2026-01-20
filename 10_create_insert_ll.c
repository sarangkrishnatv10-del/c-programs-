#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertAtBeginning(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at beginning\n", value);
}

void insertAtEnd(Node **head, int value) {
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
    printf("Inserted %d at end\n", value);
}

void insertAtPosition(Node **head, int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    Node *temp = *head;
    int count = 1;
    
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", value, pos);
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
    int choice, value, pos;
    
    printf("Create and Insert into Linked List\n");
    
    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, value, pos);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
