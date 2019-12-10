#include <stdio.h>

int main()
{
    int a;
    printf("Podaj liczbe calkowita:\n");
    scanf("%d", &a);
    if (a & 1 << 4) { printf("Na 5 bicie istnieje wartosc 1\n"); }
    if (a & 1 << 10) { printf("Na 11 bicie istnieje wartosc 1"); }
    return 0;
}
