#include <stdio.h>

// Function to display a welcome message
void displayWelcome() {
    printf("Welcome to the Practice Program for 21 Oct!\n");
}

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
float divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0.0;
    }
    return (float)a / b;
}

int main() {
    int num1, num2;
    char op;
    displayWelcome();

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (op) {
        case '+':
            printf("Result: %d\n", add(num1, num2));
            break;
        case '-':
            printf("Result: %d\n", subtract(num1, num2));
            break;
        case '*':
            printf("Result: %d\n", multiply(num1, num2));
            break;
        case '/':
            printf("Result: %.2f\n", divide(num1, num2));
            break;
        default:
            printf("Invalid operator!\n");
    }

    printf("Thank you for practicing on 21 Oct!\n");
    return
}