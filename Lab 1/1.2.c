#include <stdio.h>

int main()
{
    int a;
    printf("Podaj liczbe calkowita:\n");
    scanf("%d", &a);
    printf("Zamiana na postac zmiennoprzecinkowa: %f\n", (float)a);
    printf("Zamiana na postac napisowa: %c\n", (char)a);
    return 0;
}
