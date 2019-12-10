#include <stdio.h>
#include "3.3-silnia.c"

int main()
{
    int n = 0;
    long long res;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    res = SilniaInt(n);
    printf("Wartosc silnii z %d dla typu int: %lld\n", n, res);
    res = SilniaLong(n);
    printf("Wartosc silnii z %d dla typu long: %lld\n", n, res);
    res = SilniaLongLong(n);
    printf("Wartosc silnii z %d dla typu long long: %lld\n", n, res);
    res = SilniaRecursive(n);
    printf("Wartosc silnii z %d rekursywnie: %lld\n", n, res);
    wynik = res;
    return 0;
}
