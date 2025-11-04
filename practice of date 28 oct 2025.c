#include <stdio.h>

int main() {
    int i, j, n = 5;

    // Upper half
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++)
            printf("*");
        for(j = 1; j <= 2*(n - i); j++)
            printf(" ");
        for(j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }

    // Lower half
    for(i = n; i >= 1; i--) {
        for(j = 1; j <= i; j++)
            printf("*");
        for(j = 1; j <= 2*(n - i); j++)
            printf(" ");
        for(j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}