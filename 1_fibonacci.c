#include <stdio.h>

void fibonacci(int n) {
    int first = 0, second = 1, third;
    
    if (n <= 0) {
        printf("Please enter a positive number\n");
        return;
    }
    
    printf("Fibonacci series up to %d terms:\n", n);
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", first);
        } else if (i == 1) {
            printf("%d ", second);
        } else {
            third = first + second;
            printf("%d ", third);
            first = second;
            second = third;
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    fibonacci(n);
    
    return 0;
}
