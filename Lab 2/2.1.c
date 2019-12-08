#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    while(1)
    {
        int a = (int)rand() % 6 + 1;
        printf("%d\n", a);
        if (a == 6) break;
    }
    return 0;
}
