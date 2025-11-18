#include <stdio.h>

int main() {

    int A[5][5], B[5][5], C[5][5];
    int i, j, k;
    int R1, C1, R2, C2;

    printf("Matrix Multiplication\n\n");

    printf("Enter First Matrix size (Max 5x5)\n");
    printf("Rows: ");
    scanf("%d", &R1);
    printf("Cols: ");
    scanf("%d", &C1);

    printf("\nEnter Second Matrix size (Max 5x5)\n");
    printf("Rows: ");
    scanf("%d", &R2);
    printf("Cols: ");
    scanf("%d", &C2);

    if (C1 != R2) {
        printf("\nMatrix multiplication NOT possible!\n");
        return 0;
    }

    printf("\nEnter First Matrix elements:\n");
    for (i = 0; i < R1; i++) {
        for (j = 0; j < C1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter Second Matrix elements:\n");
    for (i = 0; i < R2; i++) {
        for (j = 0; j < C2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix multiplication
    for (i = 0; i < R1; i++) {
        for (j = 0; j < C2; j++) {
            C[i][j] = 0;
            for (k = 0; k < C1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix:\n");
    for (i = 0; i < R1; i++) {
        for (j = 0; j < C2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
