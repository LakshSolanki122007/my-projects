#include <stdio.h>

int main()
{
    int a = 10, b = 5;

    // Arithmetic operators
    printf("Arithmetic Operators:\n");
    printf("%d\n", (a + b));
    printf("%d\n", (a - b));
    printf("%d\n", (a * b));
    printf("%d\n", (a / b));
    printf("%d\n", (a % 3));

    // Relational operators
    a = 15, b = 10;  // just reassign, not redeclare
    printf("\nRelational Operators:\n");
    printf("%d\n", (a > b));
    printf("%d\n", (a >= b));
    printf("%d\n", (a < b));
    printf("%d\n", (a <= b));
    printf("%d\n", (a == b));
    printf("%d\n", (a != b));

    // Logical operators
    printf("\nLogical Operators:\n");
    printf("A\tB\tA&&B\tA||B\n");
    printf("%d\t%d\t%d\t%d\n", 0, 0, 0 && 0, 0 || 0);
    printf("%d\t%d\t%d\t%d\n", 0, 1, 0 && 1, 0 || 1);
    printf("%d\t%d\t%d\t%d\n", 1, 0, 1 && 0, 1 || 0);
    printf("%d\t%d\t%d\t%d\n", 1, 1, 1 && 1, 1 || 1);

    int n = 125;
    printf("\nRange & Condition Checks:\n");
    printf("%d\n", (n >= 100 && n <= 999)); // check 3-digit number
    printf("%d\n", (n % 2 == 0 || n % 7 == 0)); // divisible by 2 or 7

    // Assignment operators
    a = 10, b = 5;
    printf("\nAssignment Operators:\n");
    printf("%d\n", (a += b));
    printf("%d\n", (a -= b));
    printf("%d\n", (a *= b));
    printf("%d\n", (a /= b));
    printf("%d\n", (a %= b));

    return 0;
}