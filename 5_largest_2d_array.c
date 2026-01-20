#include <stdio.h>

int findLargest(int arr[][100], int m, int n) {
    int largest = arr[0][0];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > largest) {
                largest = arr[i][j];
            }
        }
    }
    
    return largest;
}

int main() {
    int m, n;
    
    printf("Find Largest Number in 2D Array\n");
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    
    int arr[100][100];
    
    printf("Enter the elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    int largest = findLargest(arr, m, n);
    
    printf("The largest number in the array is: %d\n", largest);
    
    return 0;
}
