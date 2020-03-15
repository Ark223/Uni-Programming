#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	while (true) {
		cout << "Podaj dlugosci trojkata a, b i c: " << endl;
		cin >> a >> b >> c;
		if (a > 0 && b > 0 && c > 0 &&
			a + b > c && a + c > b && b + c > a) break;
		cout << "Trojkat jest niemozliwy dla podanych dlugosci! Sprobuj ponownie!" << endl;
	}
	double t = (a + b + c) / 2;
	double area = sqrt(t * (t - a) * (t - b) * (t - c));
	int circumference = a + b + c;
	cout << "Pole trojkata: " << area << endl;
	cout << "Obwod trojkata: " << circumference << endl;
	return 0;
}

