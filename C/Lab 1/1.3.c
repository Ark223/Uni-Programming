#include <stdio.h>

int main()
{
    float a, b, c = 0.0;
    char oper = '+';
    printf("Podaj 2 liczby:\n");
    scanf("%f %f", &a, &b);
    printf("Podaj operacje:\n");
    scanf("%hh", &oper);
    switch(oper)
    {
        case '+': c = a + b; break;
        case '-': c = a - b; break;
        case '*': c = a * b; break;
        case '/': c = a / b; break;
        default: break;
    }
    printf("Wynik: %.3f\n", c);
    return 0;
}
