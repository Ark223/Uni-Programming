#include <iostream>
using namespace std;

int main() {
    int a[] = {5, 7, 1, 8, 6, 2, 0, 4, 9, 3}, n = 10;
    for (int i = 1; i < n; i++) {
        int k = a[i], j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j]; // Przesuñ elementy wektora a które s¹
            j -= 1;          // wiêksze od elementu k o jedno miejsce dalej
        }
        a[j + 1] = k;
    }
    cout << "Posortowane liczby przez wstawianie: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " "; cout << endl;
    return 0;
}
