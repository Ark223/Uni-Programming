#include <stdio.h>
#include <string.h>

void sklej(char* a, char* b)
{
    while(*a) a++; while(*a++ = *b++);
}

int main()
{
    char a[100]; char b[100];
    printf("Podaj 2 teksty: \n");
    scanf("%s %s", &a, &b);
    sklej(a, b);
    printf("%s", a);
    return 0;
}
