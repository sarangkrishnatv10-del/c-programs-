#include<stdio.h>

int main(){
    int n, num, rem, result = 0;

    printf("Enter a number: ");
    scanf("%d",&num);

    n = num;
    result = 0;

    while(n != 0){
        rem = n % 10;
        result = result + (rem * rem * rem);
        n = n / 10;
    }

    if(result == num){
        printf("%d is an armstrong number\n", num);
    } else {
        printf("%d is not an armstrong number\n", num);
    }

    return 0;
}
