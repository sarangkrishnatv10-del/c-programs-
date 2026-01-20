#include <stdio.h>
#include <math.h>

int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

int isArmstrong(int num) {
    int original = num;
    int digits = countDigits(num);
    int sum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    
    return original == sum;
}

int main() {
    int num;
    
    printf("Armstrong Number Checker\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isArmstrong(num)) {
        printf("%d is an Armstrong number\n", num);
    } else {
        printf("%d is not an Armstrong number\n", num);
    }
    
    return 0;
}
