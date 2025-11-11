#include<stdio.h>
#include<string.h>
void main()
{
    int arr [10] = {4,7,1,9,10,2,5,3,6,8};
    int i , j , t , N = 10;
    for(i = 0 ; i < N; i++){
        printf("%d",arr[i]);
    }
    for (i = 0 ; i < N - 1; i++){
        for (j = i + 1; j < N - 1; j++){
            t = arr [i];
            arr[i] = arr [j];
            arr[j] = t;
        }
    }
    printf ("\n\nAfter Soring -- \n\n");
    for (i = 0; i < N; i++){
        printf("%d     ", arr[i]);
    }
}