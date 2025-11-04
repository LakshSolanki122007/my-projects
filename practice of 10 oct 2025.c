#include <stdio.h>

int main(void)
{
    int num1, num2, sum, diff, prod, quotient;

    printf("Enter the first number: ");
    if (scanf("%d", &num1) != 1) return 1;

    printf("Enter the second number: ");
    if (scanf("%d", &num2) != 1) return 1;

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;

    printf("sum = %d\n", sum);
    printf("diff = %d\n", diff);
    printf("mul = %d\n", prod);

    if (num2 == 0) {
        printf("div = undefined (division by zero)\n");
    } else {
        quotient = num1 / num2;
        printf("div = %d\n", quotient);
    }

    return 0;
}