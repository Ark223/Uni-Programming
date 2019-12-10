#include <stdio.h>

int main()
{
    char a;
    printf("Podaj znak:\n");
    scanf("%c", &a);
    printf(a >= 'A' && a <= 'Z' ? "Podany znak to duza litera" :
           "Podany znak nie jest duza litera");
    return 0;
}
