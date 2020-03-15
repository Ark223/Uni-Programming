#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Podaj ilosc wyrazow ciagu Fibonacciego: ";
	cin >> n;
	long long a = 0, b = 1;
	for (int i = 0; i < n; i++) {
		cout << b << " ";
		b += a; a = b - a;
	}
	return 0;
}

