#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int i, count;
    char msg[512];

    /* ask user for the statement */
    printf("Enter the statement to print: ");
    if (fgets(msg, sizeof msg, stdin) == NULL) {
        fprintf(stderr, "Failed to read statement. Exiting.\n");
        return 1;
    }
    /* remove trailing newline */
    size_t len = strlen(msg);
    if (len > 0 && msg[len - 1] == '\n') {
        msg[len - 1] = '\0';
    }
    if (msg[0] == '\0') {
        fprintf(stderr, "Empty statement. Exiting.\n");
        return 1;
    }

    /* ask user how many times to print */
    printf("Enter number of times to print the statement: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        fprintf(stderr, "Invalid number. Exiting.\n");
        return 1;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) ; /* clear input buffer */

    /* clear the screen and move cursor to home */
    printf("\x1b[2J\x1b[H");

    /* set text color blue (34) and background green (42) */
    printf("\x1b[34;42m");

    for (i = 1; i <= count; i++)
    {
        printf("%s", msg);
        if (i < count) printf(" ");
        fflush(stdout);
        usleep(330000); /* 330 ms */
    }

    /* reset colors and prompt before exit */
    printf("\x1b[0m\n\nPress Enter to exit...");
    getchar();
    return 0;
}
