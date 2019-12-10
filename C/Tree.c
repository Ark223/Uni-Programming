
#include <stdio.h>
#include <conio.h>

void FillText(char* a, int n)
{
    for (int i = 1; i <= n; i++) printf("%s", a);
}

int main()
{
    int n = 0, b = -1;
    printf("Ilosc pieter: ");
    scanf("%d", &n); printf("\n");
    for (int i = 0; i <= n; i++)
    {
        if (i == n) b = -1;
        int max = 2 * n - 1; b += 2;
        int step = (max - b) / 2;
        FillText(" ", step);
        FillText("*", max - step * 2);
        FillText(" ", step);
        printf("\n");
    }
    getche();
    return 0;
}
