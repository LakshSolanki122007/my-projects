#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    double a, b, result;
    char op;

    printf("Basic Calculator\n\n");

    printf("Enter First Number: ");
    if (scanf("%lf", &a) != 1) return 1;

    printf("Enter Second Number: ");
    if (scanf("%lf", &b) != 1) return 1;

    printf("\nFirst number -- %.6g\nSecond number -- %.6g\n", a, b);

    printf("\nEnter Operator (+, -, *, /): ");
    if (scanf(" %c", &op) != 1) return 1;

    switch (op) {
        case '+':
            result = a + b;
            printf("\nResult: %.6g\n", result);
            break;
        case '-':
            result = a - b;
            printf("\nResult: %.6g\n", result);
            break;
        case '*':
            result = a * b;
            printf("\nResult: %.6g\n", result);
            break;
        case '/':
            if (b == 0.0) {
                printf("\nError: division by zero\n");
            } else {
                result = a / b;
                printf("\nResult: %.6g\n", result);
            }
            break;
        default:
            printf("\nUnknown operator '%c'\n", op);
            break;
    }

    return 0;
}