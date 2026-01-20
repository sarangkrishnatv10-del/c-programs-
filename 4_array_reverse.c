#include <stdio.h>

void reverseArray(int arr[], int size) {
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int left = 0, right = size - 1;
    
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    
    printf("Array Reverse Program\n");
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    reverseArray(arr, size);
    
    return 0;
}
