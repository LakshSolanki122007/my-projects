#include <stdio.h>
#include <string.h>

void main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i, data = 7, N = 10, C = 0;
    int Beg = 0, End = N - 1, Mid = (Beg + End) / 2;

    // Display the array
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Binary search loop
    while (1) {
        if (arr[Mid] == data) {
            printf("Data Found -- %d\n\n", data);
            C = 1;
            break;
        }

        if (data > arr[Mid])
            Beg = Mid + 1;
        else
            End = Mid - 1;

        Mid = (Beg + End) / 2;

        if (Beg > End)
            break;
    }

    if (C == 0)
        printf("Data Not Found ..\n\n");
}
