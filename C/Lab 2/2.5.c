#include <stdio.h>

const int r = 10;

int main()
{
    int i, j;
    printf("%5c", ' ');
    for (i = 1; i <= r; i++) printf("%5d", i);
    for (i = 1; i <= r; i++)
    {
        printf("\n%5d", i);
        for (j = 1; j <= r; j++) printf("%5d", j*i);
    }
    return 0;
}
