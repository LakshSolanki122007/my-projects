#include <stdio.h>  

int main() {  
    int i = 1;
top:
    printf("%d ", i++);  
    if (i <= 100)
        goto top;
    return 0;  
}
