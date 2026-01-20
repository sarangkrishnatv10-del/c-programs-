#include <stdio.h>

int main() {
    int arr[1000];
    int count = 0;
    int num;
    
    printf("Read Integer Series (Enter blank line to end):\n");
    printf("Enter integers (one per line):\n");
    
    while (scanf("%d", &num) == 1) {
        arr[count] = num;
        count++;
    }
    
    printf("\nArray of numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Total numbers entered: %d\n", count);
    
    return 0;
}
