#include <stdio.h>

int main()
{
    int a, b = 0;
    for (a = 32; a <= 255; a++)
    {
        b++;
        printf("%c", (char)a);
        if (b > 15) { printf("\n"); b = 0; }
    }
    return 0;
}
