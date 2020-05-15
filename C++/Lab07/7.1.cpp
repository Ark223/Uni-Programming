#include <iostream>
using namespace std;

void Merge(int a[], int start, int mid, int end, int n) {
    int i, j, k, t[n];
    for (i = start; i <= end; i++) t[i] = a[i];
    i = start; j = mid + 1; k = start;
    while (i <= mid && j <= end) {
        if (t[i] < t[j]) a[k++] = t[i++];
        else a[k++] = t[j++];
    }
    while (i <= mid) a[k++] = t[i++];
}

void MergeSort(int a[], int start, int end, int n) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    MergeSort(a, start, mid, n);
    MergeSort(a, mid + 1, end, n);
    Merge(a, start, mid, end, n);
}

int main() {
    int a[] = {5, 7, 1, 8, 6, 2, 0, 4, 9, 3}, n = 10;
    MergeSort(a, 0, n - 1, n);
    cout << "Posortowane liczby przez scalanie: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " "; cout << endl;
    return 0;
}
