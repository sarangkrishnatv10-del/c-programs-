#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} CircularQueue;

void initializeQueue(CircularQueue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(CircularQueue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }
    
    printf("Enqueued %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    
    int value = q->front->data;
    Node *temp = q->front;
    
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    
    free(temp);
    printf("Dequeued %d\n", value);
    return value;
}

void displayQueue(CircularQueue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    Node *temp = q->front;
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    
    printf("\n");
}

int main() {
    CircularQueue q;
    initializeQueue(&q);
    
    int choice, value;
    
    printf("Circular Queue using Linked List\n");
    
    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
