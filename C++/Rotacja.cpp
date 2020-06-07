#include <iostream>
#include <vector>
using namespace std;

int** obrocMacierz(int** a, int n, int sel) {
    int** b = new int*[n];
    for (int i = 0; i < n; i++) {
        b[i] = new int[n];
        for (int j = 0; j < n; j++)
            b[i][j] = (sel > 0) ?
                a[n - j - 1][i] :
                a[j][n - i - 1];
    } return b;
}

void wyswietl(int** a, int n) {
    cout << "\nMacierz: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int n = 2;
    cout << "Podaj rozmiar macierzy: " << endl; cin >> n;
    cout << "Wypelnij macierz liczbami: " << endl;
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    while (1) {
        wyswietl(a, n);
        cout << "\nOpcje: " << endl;
        cout << "1. Obrot w lewo." << endl;
        cout << "2. Obrot w prawo." << endl;
        cout << "3. Wyjscie." << endl;
        int sel = 0; cin >> sel;
        if (sel < 1 || sel > 2) return 0;
        a = obrocMacierz(a, n, sel - 1);
    }
    return 0;
}
