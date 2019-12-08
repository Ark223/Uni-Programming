#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, i, j, k, l;
    printf("Podaj wspolrzedne ramki (x1, y1, x2, y2):\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (i = 1; i <= y1 - 1; i++) printf("\n");
    for (j = y1; j <= y2; j++)
    {
        for (k = 1; k <= x1 - 1; k++) printf(" ");
        for (l = x1; l <= x2; l++)
        {
            if (l == x1 && j == y1) printf("%c", 201);
            else if (l == x1 && j == y2) printf("%c", 200);
            else if (l == x2 && j == y1) printf("%c", 187);
            else if (l == x2 && j == y2) printf("%c", 188);
            else if (l == x1 || l == x2) printf("%c", 186);
            else if (j == y1 || j == y2) printf("%c", 205);
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
