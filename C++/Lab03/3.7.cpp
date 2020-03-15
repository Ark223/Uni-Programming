#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long n;
    cout << "Podaj liczbe: " << endl;
    cin >> n;
    long long t = (long long)sqrt(n);
    for (int i = 2; i <= t; i++) {
        if (n % i == 0) {
            cout << "Podana liczba nie jest pierwsza" << endl;
            return 0;
        }
    }
    cout << "Podana liczba jest pierwsza" << endl;
    return 0;
}

