#include <stdio.h>

void SwapElements(int *a, int *b)
{
    int c = *a; *a = *b; *b = c;
}

void BubbleSort(int cyfry[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (cyfry[j] > cyfry[j + 1])
                SwapElements(&cyfry[j], &cyfry[j + 1]);
}

int main()
{
    int cyfry[] = {2, 7, 12, 6, 13, 4, 30, 5, 1, 3};
    int size = sizeof(cyfry) / sizeof(cyfry[0]);
    BubbleSort(cyfry, size);
    printf("Posortowane: ");
    for (int i = 0; i < size; i++) printf("%d ", cyfry[i]);
    return 0;
}
