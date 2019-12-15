#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int NegateBin(int n)
{
    char t1[12]; char t2[12];
    sprintf(t1, "%d", n);
    for (int i = 0; i < strlen(t1); i++)
        t2[i] = t1[i] == '0' ? '1' : '0';
    return ConvertStringToNumber(t2);
}

int main(int argc, char* argv[])
{
    int a = atoi(argv[1]), b = atoi(argv[2]), oper = atoi(argv[3]);
    if (a < 0 || b < 0) { printf("Wprowadzono bledne liczby\n"); return 0; }
    int a2 = ConvertToBin(a), b2 = ConvertToBin(b), c;
    switch(oper)
    {
        case 1: c = a & b; break;
        case 2: c = a | b; break;
        case 3: c = a ^ b; break;
        case 4: break;
        default: printf("Wprowadzono bledna operacje\n"); break;
    }
    if (!(oper <= 4)) return 0;
    printf("a: %d\nb: %d\n", a2, b2);
    if (oper == 4)
        printf("Negacja a: %d\nNegacja b: %d\n", NegateBin(a2), NegateBin(b2));
    else
        printf("Wynik operacji: %d\n", ConvertToBin(c));
    return 0;
}
