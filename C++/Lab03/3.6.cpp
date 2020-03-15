#include <iostream>
using namespace std;

int main() {
    int a1, b1, c1, a2, b2, c2;
    cout << "Podaj liczby: a1, b1, c1, a2, b2, c2" << endl;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    double detA = a1 * b2 - b1 * a2,
        detX = c1 * b2 - b1 * c2,
        detY = a1 * c2 - c1 * a2;
    if (detA != 0) {
        double x = detX / detA, y = detY / detA;
        cout << "Uklad jest oznaczony (posiada rozwiazanie): \nx = "
            << x << "\ny = " << y << endl; return 0;
    }
    cout << ((detX == 0 && detY == 0) ?
        "Uklad jest nieoznaczony (posiada nieskonczenie wiele rozwiazan)" :
        "Uklad jest sprzeczny (brak rozwiazan)") << endl;
    return 0;
}

