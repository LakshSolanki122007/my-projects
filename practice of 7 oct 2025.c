#include <stdio.h>

int main(void)
{
    char name[20], rno[5];
    int hindi, english, maths;
    float total, per;

    printf("Enter Roll No == ");
    scanf("%s", rno);

    printf("Enter Name == ");
    scanf("%s", name);

    printf("Enter Hindi Marks == ");
    scanf("%d", &hindi);

    printf("Enter English Marks == ");
    scanf("%d", &english);

    return 0;
}