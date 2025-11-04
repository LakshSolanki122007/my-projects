#include <stdio.h>

int main()
{
    char name[20], rno[5];
    int hindi, english, maths;
    float total, per;

    printf("Enter Roll No -- ");
    scanf("%s", rno);  // Corrected variable name

    printf("Enter Name -- ");
    scanf("%s", name);

    printf("Enter Hindi marks -- ");
    scanf("%d", &hindi);

    printf("Enter English marks -- ");
    scanf("%d", &english);

    printf("Enter Maths marks -- ");
    scanf("%d", &maths);

    printf("\n\nStudent Details are --\n\n");
    printf("Roll no -- %s\n", rno);
    printf("Name -- %s\n", name);
    printf("Hindi -- %d\n", hindi);
    printf("English -- %d\n", english);
    printf("Maths -- %d\n", maths);

    total = hindi + english + maths;
    printf("Total Marks -- %.2f / 300\n", total);

    per = (total * 100) / 300;
    printf("Percentage -- %.2f %%\n", per);

    if (per >= 60)
        printf("First Division\n");
    else if (per >= 48)
        printf("Second Division\n");
    else if (per >= 36)
        printf("Third Division\n");
    else
        printf("Fail\n");

    return 0;
}
