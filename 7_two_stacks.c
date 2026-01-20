#include <stdio.h>

#define SIZE 100

typedef struct {
    int arr[SIZE];
    int top1;
    int top2;
} TwoStacks;

void initializeStacks(TwoStacks *stacks) {
    stacks->top1 = -1;
    stacks->top2 = SIZE;
}

void push1(TwoStacks *stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->arr[++stacks->top1] = value;
        printf("Pushed %d to Stack 1\n", value);
    } else {
        printf("Stack 1 is full\n");
    }
}

void push2(TwoStacks *stacks, int value) {
    if (stacks->top2 > stacks->top1 + 1) {
        stacks->arr[--stacks->top2] = value;
        printf("Pushed %d to Stack 2\n", value);
    } else {
        printf("Stack 2 is full\n");
    }
}

int pop1(TwoStacks *stacks) {
    if (stacks->top1 >= 0) {
        return stacks->arr[stacks->top1--];
    } else {
        printf("Stack 1 is empty\n");
        return -1;
    }
}

int pop2(TwoStacks *stacks) {
    if (stacks->top2 < SIZE) {
        return stacks->arr[stacks->top2++];
    } else {
        printf("Stack 2 is empty\n");
        return -1;
    }
}

int main() {
    TwoStacks stacks;
    initializeStacks(&stacks);
    
    int choice, value;
    
    printf("Two Stacks in Single Array\n");
    
    while (1) {
        printf("\n1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push1(&stacks, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push2(&stacks, value);
                break;
            case 3: {
                int val = pop1(&stacks);
                if (val != -1) {
                    printf("Popped %d from Stack 1\n", val);
                }
                break;
            }
            case 4: {
                int val = pop2(&stacks);
                if (val != -1) {
                    printf("Popped %d from Stack 2\n", val);
                }
                break;
            }
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
