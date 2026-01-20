#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int length = strlen(binary);
    
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - i - 1);
        }
    }
    
    return decimal;
}

int main() {
    char binary[100];
    
    printf("Binary to Decimal Conversion\n");
    printf("Enter binary number: ");
    scanf("%s", binary);
    
    int decimal = binaryToDecimal(binary);
    
    printf("Binary: %s\n", binary);
    printf("Decimal: %d\n", decimal);
    
    return 0;
}
