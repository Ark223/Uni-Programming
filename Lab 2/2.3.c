#include <stdio.h>
#include <conio.h>

int main()
{
    int N, a, b = 0;
    printf("Ile liczb chcesz dodac?\n");
    scanf("%d", &N);
    printf("Wypisz %d liczb:\n", N);
    for (unsigned i = 1; i <= N; i++)
    {
        scanf("\n%d", &a);
        b += a;
    }
    printf("Suma: %d", b);
    getche();
    return 0;
}
