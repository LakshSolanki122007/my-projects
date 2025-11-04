#include <stdio.h>

int main(void)
{
    int n = 5, i = 1;
    long long x = 0, a = 1; /* use long long to reduce overflow risk */
    while (i <= n) {
        x = (i % 2 == 0) ? (x * 10 + i) : ((i * a) + x);
        a *= 10;
        i++;
    }
    printf("%lld\n", x);
    return 0;
}
