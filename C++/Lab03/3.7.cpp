#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Podaj wspolczynniki a, b i c: " << endl;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            cout << (c != 0 ? "Rownanie jest sprzeczne" :
                "Rownanie ma nieskonczenie wiele rozwiazan");
            return 0;
        }
        cout << "Rownanie ma jedno rozwiazanie: " << (-c / b) << endl;
        return 0;
    }
    double delta = b * b - 4.0 * a * c;
    if (delta < 0.0) {
        cout << "Rownanie nie posiada rzeczywistych rozwiazan" << endl;
        return 0;
    }
    else if (delta == 0.0) {
        cout << "Rownanie ma 1 jedno rozwiazanie: " << -b / (2 * a) << endl;
        return 0;
    }
    delta = sqrt(delta);
    cout << "Rownanie ma 2 rozwiazania: " << (-b - delta) / (2 * a)
        << " oraz " << (-b + delta) / (2 * a);
    return 0;

}
