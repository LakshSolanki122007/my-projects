// Nested if

#include <stdio.h>

int main(void)
{
    int year = 2021;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                printf("Leap year\n");
            } else {
                printf("Not a leap year\n");
            }
        } else {
            printf("Leap year\n");
        }
    } else {
        printf("Not a leap year\n");
    }
    return 0;
}