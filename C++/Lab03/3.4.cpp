#include <iostream>
using namespace std;

double MathPow(double a, int n) {
    if (n > 0) return a * MathPow(a, n - 1);
    else if (n < 0) return 1.0 / MathPow(a, -n);
    return 1.0;
}

int main() {
    double a; int n;
    cout << "Podaj liczbe: " << endl;
    cin >> a;
    cout << "Podaj potege: " << endl;
    cin >> n;
	double b = MathPow(a, n);
    cout << "Wynik: " << b << endl;
    return 0;
}
