#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int choose;
    double a, b, result;
    cout << "Podaj liczbe a i b: " << endl;
    cin >> a >> b;
    cout << "Dzialania: \n1.Suma\n2.Roznica\n3.Iloczyn\n4.Iloraz" << endl;
    cin >> choose;
    while (choose == 4 && b == 0.0) {
        cout << "Nie mozna dzielic przez zero! Prosze wpisac inna liczbe!" << endl;
        cin >> b;
    }
    switch (choose) {
        case 1: result = a + b; break;
        case 2: result = a - b; break;
        case 3: result = a * b; break;
        default: result = a / b; break;
    }
    cout << "Wynik: " << result << endl;
    return 0;
}

