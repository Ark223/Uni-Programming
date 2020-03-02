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
	int a;
	cout << "Wpisz liczbe: " << endl;
	cin >> a;
	cout << "Silnia liczona iteracyjnie: " << Silnia(a) << endl;
	cout << "Silnia liczona rekurencyjnie: " << SilniaRecursively(a) << endl;
}

