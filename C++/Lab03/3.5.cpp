#include <iostream>
using namespace std;

int main() {
	int a = 0;
	while (a <= 1000) {
		cout << "Podaj liczbe: " << endl;
		cin >> a;
	}
	int suma = 0;
	while (a) {
		suma += a % 10;
		a /= 10;
	}
	cout << "Suma cyfr: " << suma << endl;
	return 0;
}
