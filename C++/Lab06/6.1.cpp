#include <iostream>
using namespace std;

int main() {
    int a[] = {5, 7, 1, 8, 6, 2, 0, 4, 9, 3}, n = 10;
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[k]) k = j;
        int temp = a[k];
        a[k] = a[i];
        a[i] = temp;
    }
    cout << "Posortowane liczby przez wybieranie: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " "; cout << endl;
    return 0;
}
