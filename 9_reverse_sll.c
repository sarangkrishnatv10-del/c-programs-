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

void reverseList(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
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
    int n, value;
    
    printf("Reverse a Singly Linked List\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertNode(&head, value);
    }
    
    printf("\nOriginal ");
    displayList(head);
    
    reverseList(&head);
    
    printf("Reversed ");
    displayList(head);
    
    return 0;
}
