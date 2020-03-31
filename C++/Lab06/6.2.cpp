#include <iostream>
using namespace std;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Divide(int a[], int start, int end) {
    int pivot = a[end], i = start - 1;
    for (int j = start; j <= end - 1; j++)
        if (a[j] < pivot) { i++; Swap(&a[i], &a[j]); }
    Swap(&a[i + 1], &a[end]);
    return i + 1;
}

void QuickSort(int a[], int start, int end) {
    if (start >= end) return;
    int p = Divide(a, start, end);
    QuickSort(a, start, p - 1);
    QuickSort(a, p + 1, end);
}

int main() {
    int a[] = {5, 7, 1, 8, 6, 2, 0, 4, 9, 3}, n = 10;
    QuickSort(a, 0, n - 1);
    cout << "Posortowane liczby szybko: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " "; cout << endl;
    return 0;
}
