#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <signal.h>

/* Ensure math functions are declared for strict ISO C99 builds */
#ifndef __cplusplus
double cos(double);
double sin(double);
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define W 60
#define H 20
#define BURSTS 6
#define FRAMES 18

const char *colors[] = {
    "\x1b[31m", /* red */ "\x1b[33m", /* yellow */ "\x1b[32m", /* green */
    "\x1b[36m", /* cyan */ "\x1b[34m", /* blue */ "\x1b[35m", /* magenta */
};
const char *reset = "\x1b[0m";

void clear_screen() {
    printf("\x1b[2J\x1b[H");
}

static void restore_cursor_and_exit(int signo) {
    (void)signo;
    printf("\x1b[?25h"); // show cursor
    fflush(stdout);
    _exit(1);
}

int main(void) {
    /* ensure cursor is restored on SIGINT/SIGTERM */
    signal(SIGINT, restore_cursor_and_exit);
    signal(SIGTERM, restore_cursor_and_exit);

    srand((unsigned)time(NULL));
    char canvas[H][W+1];
    clear_screen();
    printf("\x1b[?25l"); // hide cursor

    size_t ncolors = sizeof(colors) / sizeof(colors[0]);
    for (int b = 0; b < BURSTS; ++b) {
        // choose burst center and color
        int cx = 6 + rand() % (W - 12);
        int cy = 3 + rand() % (H - 6);
        const char *col = colors[rand() % ncolors];

        for (int f = 0; f < FRAMES; ++f) {
            // reset canvas
            for (int y = 0; y < H; ++y) {
                for (int x = 0; x < W; ++x) canvas[y][x] = ' ';
                canvas[y][W] = '\0';
            }

            // draw stars (points radiating outward)
            int radius = f;
            for (int p = 0; p < 120; ++p) {
                double angle = (rand() % 360) * (M_PI / 180.0);
                double spread = ((double)rand() / (double)RAND_MAX) * radius;
                int x = cx + (int)(cos(angle) * spread + 0.5);
                int y = cy + (int)(sin(angle) * spread + 0.5);
                if (x >= 0 && x < W && y >= 0 && y < H) {
                    char ch = (rand() % 3 == 0) ? '*' : (rand() % 2 ? '+' : '.');
                    canvas[y][x] = ch;
                }
            }

            // slight twinkle: place a few brighter center sparks
            if (f < 3) {
                for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; ++dy) {
                    int x = cx + dx, y = cy + dy;
                    if (x>=0 && x<W && y>=0 && y<H) canvas[y][x] = '@';
                }
            }

            // render
            printf("\x1b[H"); // move cursor home
            for (int y = 0; y < H; ++y) {
                // print line with color where there is a non-space
                for (int x = 0; x < W; ++x) {
                    char c = canvas[y][x];
                    if (c != ' ')
                        printf("%s%c%s", col, c, reset);
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            fflush(stdout);
            usleep(90000); // 90ms per frame
        }
        // brief pause between bursts
        usleep(300000);
    }

    printf("\x1b[?25h"); // show cursor
    printf("\nDone — enjoy the show!\n");
    return 0;
}