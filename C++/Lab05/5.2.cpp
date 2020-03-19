#include <iostream>
using namespace std;

int main() {
    int a[] = {5, 7, 1, 8, 6, 2, 0, 4, 9, 3}, n = 10;
    for (int i = 1; i < n; i++) {
        int l = a[i], j = i - 1;
        while (j >= 0 && a[j] > l) {
            a[j + 1] = a[j]; j -= 1;
        }
        a[j + 1] = l;
    }
    cout << "Posortowane liczby przez wstawianie: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " "; cout << endl;
    return 0;
}
