#include <iostream>
#include <limits>
using namespace std;

int main() {
    int a = 0;
    for (;;) {
        cout << "Podaj liczbe: " << endl;
        if (cin >> a && a > 1000) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int suma = 0;
    while (a) {
        suma += a % 10;
        a /= 10;
    }
    cout << "Suma cyfr: " << suma << endl;
    return 0;
}
