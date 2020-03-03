#include <iostream>
using namespace std;

int Silnia(int n) {
    int a = 1;
    while (n > 0) {
        a *= n; n--;
    }
    return a;
}

int SilniaRecursively(int n) {
    return n < 2 ? 1 : SilniaRecursively(n - 1) * n;
}

int main()
{
    int a, b, c;
    cout << "Wpisz liczbe: " << endl;
    cin >> a;
	int b = Silnia(a), c = SilniaRecursively(a);
    cout << "Silnia liczona iteracyjnie: " << b << endl;
    cout << "Silnia liczona rekurencyjnie: " << c << endl;
}
