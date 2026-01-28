#include <stdio.h>

int main() {
    int i, j, r, c;
    int a[100][100];
    int lar;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    printf("Enter the elements:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatrix elements are:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    lar = a[0][0];   // initialize largest value

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] > lar) {
                lar = a[i][j];
            }
        }
    }

    printf("\nThe largest element is: %d\n", lar);

    return 0;
}
