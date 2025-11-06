#include <stdio.h>
#include <stdlib.h>  // rand() ke liye

// Linear Search function
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Position return kar
        }
    }
    return -1;  // Not found
}

// Binary Search function (array sorted hona chahiye)
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int size = 10;  // Array size
    int arr[10];    // Integer array for treasures (numbers as treasures)
    int target, choice, pos;

    // Random treasures fill kar (0 se 100 tak)
    printf("Treasure Hunt Game!\n");
    srand(42);  // Seed for random, same har baar
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        printf("Treasure %d: %d\n", i+1, arr[i]);
    }

    printf("\nKya dhundna hai? Target number daal: ");
    scanf("%d", &target);

    printf("Search type choose kar (1: Linear, 2: Binary): ");
    scanf("%d", &choice);

    if (choice == 1) {
        pos = linearSearch(arr, size, target);
    } else if (choice == 2) {
        // Binary ke liye sort kar le array
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        printf("Sorted array for Binary: ");
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n");
        pos = binarySearch(arr, size, target);
    } else {
        printf("Galat choice bhai!\n");
        return 1;
    }

    if (pos != -1) {
        printf("Treasure mile! Position %d pe hai (0-based index).\n", pos);
    } else {
        printf("Koi treasure nahi mila us number ka. Try again!\n");
    }

    return 0;
}