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

void zlicz2(char* tekst, char znak, int* wystap)
{
    int a = 0, i = 0;
    while (tekst[i])
    {
        if (tekst[i] == znak) a++;
        i++;
    }
    *wystap = a;
}

int main()
{
    char tekst[100]; char znak;
    printf("Podaj tekst: \n");
    scanf("%s", &tekst);
    int litery; int cyfry; int wystap;
    zlicz_wystapienia(tekst, &litery, &cyfry);
    printf("Ilosc malych liter: %d  Ilosc cyfr: %d\nPodaj znak: ", litery, cyfry);
    scanf(" %c", &znak);
    zlicz2(tekst, znak, &wystap);
    printf("Ilosc wystapien znaku: %d\n", wystap);
    return 0;
}
