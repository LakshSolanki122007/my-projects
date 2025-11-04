#include<stdio.h>
#include<string.h>
void main()
{
    int N = 5 , i , j , X = 1;
    for (i = 1; i <= N; i++){
        for (j = 1 , X = 1 ; j <= N + N - 1; j++){
            (j <= i || j >= N + N - i) ? printf ("%d", X): 
            printf (" ");
        }
        printf ("\n");
        }
    }