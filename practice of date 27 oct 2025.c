#include<stdio.h>
#include<string.h>
void main()
{
    int n = 100 , i , c = 0, J , cntr = 0, sum = 0;
    for(J = 2; J <= n; J++){
        for(i = 2; J<=n; J++){
            if(J % i == 0)
            c++;
        }
        if(c == 1){
            printf("%d+", J);
            cntr++;
            sum += J;
        }
    }
    printf("\b\b= %d", sum);
    printf("\n\nTotal Prime Numbers Between %d - %d = %d\n\n",2,n,cntr);
}