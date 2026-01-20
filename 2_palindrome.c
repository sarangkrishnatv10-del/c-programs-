#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindromeNumber(int num) {
    int original = num;
    int reversed = 0;
    
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    return original == reversed;
}

int isPalindromeString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }
        left++;
        right--;
    }
    
    return 1;
}

int main() {
    int choice;
    
    printf("Palindrome Checker\n");
    printf("1. Check Number\n");
    printf("2. Check String\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        
        if (isPalindromeNumber(num)) {
            printf("%d is a palindrome\n", num);
        } else {
            printf("%d is not a palindrome\n", num);
        }
    } else if (choice == 2) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        
        if (isPalindromeString(str)) {
            printf("%s is a palindrome\n", str);
        } else {
            printf("%s is not a palindrome\n", str);
        }
    } else {
        printf("Invalid choice\n");
    }
    
    return 0;
}
