#include <stdio.h>

int main(void)
{
    int n = 1549;
    int sum = 0;
    do {
        do {
            sum = sum + (n % 10);
            n = n / 10;
        } while (n != 0);
        if (sum <= 9)
            break;
        n = sum;
        printf("%d\n\n", sum);
        sum = 0;
    } while (1);
    printf("%d\n", sum);
    return 0;
}