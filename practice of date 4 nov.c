#include<stdio.h>
void main()
{
    int arr[11] = {1,2,3,4,5,6,7,8,9,10}; // make space for new element
    int i, data = 100, N = 10;

    // Shift elements right
    for (i = N; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = data;  // Insert new data at beginning
    N = N + 1;

    // Print updated array
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}
