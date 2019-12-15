#include <stdio.h>
#include <conio.h>
#include <string.h>

int ConvertToBin(int n)
{
    int a = 0, b = 1;
    while (n != 0) { int c = n % 2; n /= 2; a += b * c; b *= 10; }
    return a;
}

int ConvertStringToNumber(char* s)
{
    int a = 0;
    for (int i = 0; i < strlen(s); i++)
        a = a * 10 + (int)s[i] - 48;
    return a;
}

int IsNumber(char* s)
{
    for (int i = 0; i < strlen(s); i++)
        if (!(s[i] >= '0' && s[i] <= '9')) return 0;
    return 1;
}

int main()
{
    char a[12];
    printf("Podaj liczbe dziesietna:\n");
    scanf("%s", &a);
    if (!IsNumber(a)) { printf("Wprowadzono bledna liczbe\n"); return 0; }
    int b = ConvertStringToNumber(a);
    printf(b < 0 ? "Wprowadzono bledna liczbe\n" :
           "Liczba w postaci binarnej jest rowna: %d\n", ConvertToBin(b));
    getche();
    return 0;
}
