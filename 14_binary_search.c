#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int size;
    
    printf("Binary Search on Sorted Array\n");
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }
    
    return 0;
}
