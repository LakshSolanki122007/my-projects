#include <stdio.h>

int main() {
    char name[50];
    float computer_architecture, operating_system, C_language, total, percentage;
    printf("Enter Student Name: ");
    scanf("%s", name);

    printf("Enter marks in Computer Architecture: ");
    scanf("%f", &computer_architecture);

    printf("Enter marks in Operating System: ");
    scanf("%f", &operating_system);   // fixed: was &Operating_System

    printf("Enter marks in C Language: ");
    scanf("%f", &C_language);

    total = computer_architecture + operating_system + C_language;
    percentage = (total / 300.0f) * 100.0f;  // use float literal for clarity

    printf("\n--- Student result ---\n");
    printf("Name: %s\n", name);
    printf("Total Marks: %.2f\n", total);
    printf("Percentage: %.2f%%\n", percentage);

    if (percentage >= 60) {
        printf("Division: First\n");
    } else if (percentage >= 45) {
        printf("Division: Second\n");
    } else if (percentage >= 33) {
        printf("Division: Third\n");
    } else {
        printf("Division: Failed\n");
    }
    return 0;   
}