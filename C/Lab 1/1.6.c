#include <stdio.h>

int main()
{
    int a, b, c, d, count = 0;
    printf("Wypisz 4 liczby:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a >= 0) count++;
    if (b >= 0) count++;
    if (c >= 0) count++;
    if (d >= 0) count++;
    printf(count > 2 ? "Wiecej jest dodatnich liczb" :
           (count < 2 ? "Wiecej jest ujemnych liczb" :
           "Liczb dodatnich i ujemnych jest tyle samo"));
    return 0;
}
