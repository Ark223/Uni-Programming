#include <stdio.h>
#include <math.h>

void oblicz(int i, float *a, char **typ)
{
    switch(i)
    {
        case 1: *a = sqrtf(*a); *typ = "Pierwiastek"; break;
        case 2: *a = sinf(*a); *typ = "Sinus"; break;
        case 3: *a = expf(*a); *typ = "Liczba Eulera do potegi"; break;
        default: break;
    }
}

int main()
{
    float a;
    printf("Podaj liczbe: \n");
    scanf("%f", &a);
    char *typ;
    for (int i = 1; i < 4; i++)
    {
        float b = a;
        oblicz(i, &a, &typ);
        printf("%s liczby %f: %f\n", typ, b, a);
        a = b;
    }
    return 0;
}
