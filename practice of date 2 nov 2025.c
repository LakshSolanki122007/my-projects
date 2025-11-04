#include <stdio.h>
#include <string.h>

#define ITEMS 5
#define MAXCHAR 20

int main()
{
    char string[ITEMS][MAXCHAR], dummy[MAXCHAR];
    int i, j;

    /* Reading the list */
    printf("Enter names of %d items:\n", ITEMS);
    for (i = 0; i < ITEMS; i++) {
        scanf("%s", string[i]);
    }

    /* Sorting begins */
    for (i = 1; i < ITEMS; i++) {
        for (j = 1; j <= ITEMS - i; j++) {
            if (strcmp(string[j - 1], string[j]) > 0) {
                /* Exchange of contents */
                strcpy(dummy, string[j - 1]);
                strcpy(string[j - 1], string[j]);
                strcpy(string[j], dummy);
            }
        }
    }

    /* Sorting completed */
    printf("\nAlphabetical list:\n");
    for (i = 0; i < ITEMS; i++) {
        printf("%s\n", string[i]);
    }

    return 0;
}
