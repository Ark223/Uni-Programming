#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Wypisz 3 liczby:\n");
    scanf("%d %d %d", &a, &b, &c);
    int max = a >= b && a >= c ? a : (b >= a && b >= c ? b : c);
    int min = a <= b && a <= c ? a : (b <= a && b <= c ? b : c);
    printf("Max: %d, Min: %d", max, min);
    return 0;
}
