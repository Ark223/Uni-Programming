#include <stdio.h>

void zlicz_wystapienia(char* tekst, int* litery, int* cyfry)
{
    int a = 0, b = 0, i = 0;
    while (tekst[i])
    {
        if (tekst[i] >= 'a' && tekst[i] <= 'z') a++;
        else if (tekst[i] >= '0' && tekst[i] <= '9') b++;
        i++;
    }
    *litery = a; *cyfry = b;
}

int main()
{
    char tekst[100];
    printf("Podaj tekst: \n");
    scanf("%s", &tekst);
    int litery; int cyfry;
    zlicz_wystapienia(tekst, &litery, &cyfry);
    printf("Ilosc malych liter: %d  Ilosc cyfr: %d", litery, cyfry);
    return 0;
}
