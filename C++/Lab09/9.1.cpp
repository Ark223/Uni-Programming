#include <iostream>
using namespace std;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int i, int j) {
    int c = a[i];
    while (i < j) {
        while (i < j && a[j] >= c) j--;
        while (i < j && a[i] < c) i++;
        if (i < j) Swap(&a[i], &a[j]);
    }
    return i;
}

int main() {
    int a[] = {5, 7, 1, 8, 6, 2, 0, 4, 9, 3}, k, n = 10;
    cout << "Ktory element znalezc? "; cin >> k;
    if (k > n || k < 1) { cout << "Zly element!"; return 0; }
    int i = 0, j = n - 1;
    while (i != j) {
        int p = Partition(a, i, j);
        p += 1 - i;
        if (p >= k) j = p + i - 1;
        else { k -= p; i += p; }
    }
    cout << "Wybrany element to: " << a[i] << endl;
}
