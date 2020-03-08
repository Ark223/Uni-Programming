#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    double x1, x2;
    cout << "Podaj wspolczynniki a, b i c: " << endl;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            cout << (c != 0 ? "Rownanie jest sprzeczne" :
                "Rownanie ma nieskonczenie wiele rozwiazan");
            return 0;
        }
        x1 = -c / b;
        cout << "Rownanie ma jedno rozwiazanie: " << x1 << endl;
        return 0;
    }
    double delta = b * b - 4.0 * a * c;
    if (delta < 0.0) {
        cout << "Rownanie nie posiada rzeczywistych rozwiazan" << endl;
        return 0;
    }
    else if (delta == 0.0) {
        x1 = -b / (2 * a);
        cout << "Rownanie ma jedno rozwiazanie: " << x1 << endl;
        return 0;
    }
    delta = sqrt(delta);
    x1 = (-b - delta) / (2 * a); x2 = (-b + delta) / (2 * a);
    cout << "Rownanie ma dwa rozwiazania: " << x1 << " oraz " << x2;
    return 0;
}

