#include<stdio.h>
void main()
{
    int i, j, N = 5, X = 1;

    for (i = 1; i <= N + N - 1; i++) {
        for (j = 1; j <= X; j++) {
            printf("*");
        }
        printf("\n");

        // Change direction after reaching the middle
        if (i < N)
            X++;
        else
            X--;
    }
}