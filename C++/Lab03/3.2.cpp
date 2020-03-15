#include <iostream>
#include <math.h>
using namespace std;

int Det(int matrix[15][15], int size) {
    int det = 0, temp[15][15];
    if (size == 1) return matrix[0][0];
    else if (size == 2)
        return matrix[0][0] * matrix[1][1]
            - matrix[0][1] * matrix[1][0];
    else {
        for (int i = 0; i < size; i++) {
            int i2 = 0;
            for (int j = 1; j < size; j++) {
                int j2 = 0;
                for (int k = 0; k < size; k++) {
                    if (i == k) continue;
                    temp[i2][j2] = matrix[j][k]; j2++;
                } i2++;
            }
            det += pow(-1, i) * matrix[0][i] * Det(temp, size - 1);
        }
    }
    return det;
}

int** Multiplication(int a[15][15], int b[15][15], int size) {
    int** result = new int*[size];
    for (int i = 0; i < size; i++) {
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
    return result;
}

int** Transpose(int a[15][15], int size) {
    int** result = new int*[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0) result[j] = new int[size];
            result[j][i] = a[i][j];
        }
    }
    return result;
}

int main() {
    int choose, size, a[15][15];
    cout << "Okresl rozmiar macierzy kwadratowej: " << endl;
    cin >> size;
    cout << "Wypisz liczby: " << endl;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> a[i][j];
    cout << "Macierz ma postac: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << "Wybierz dzialanie: \n1. Wyznacznik macierzy\n" <<
        "2. Mnozenie macierzy\n3. Obliczanie transpozycji" << endl;
    cin >> choose;
    switch (choose) {
        case 1: {
            int det = Det(a, size);
            cout << "Wyznacznik macierzy wynosi: " << det << endl;
            break;
        }
        case 2: {
            int b[15][15];
            cout << "Wypisz liczby dla drugiej macierzy: " << endl;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    cin >> b[i][j];
            int** multi = Multiplication(a, b, size);
            cout << "Wynik mnozenia: " << endl;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++)
                    cout << multi[i][j] << "\t";
                cout << endl;
            }
            break;
        }
        case 3: {
            int** trans = Transpose(a, size);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++)
                    cout << trans[i][j] << "\t";
                cout << endl;
            }
            break;
        }
    }
    return 0;
}

