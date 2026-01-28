#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char input[20];
    int arr[100];
    int i = 0, j;

    clrscr();

    printf("Enter numbers (press Enter without typing to stop):\n");

    while (1) {
        gets(input);          // Turbo C supports gets()

        if (strlen(input) == 0) {
            break;            // Stop when Enter is pressed
        }

        arr[i] = atoi(input); // Convert string to integer
        i++;
    }

    printf("\nYou entered:\n");
    for (j = 0; j < i; j++) {
        printf("%d ", arr[j]);
    }

    getch();
}
