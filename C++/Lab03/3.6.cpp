#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int Sum(vector<int> a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

double Average(vector<int> a, int n) {
	return (Sum(a, n) + 0.0) / double(n);
}

int Max(vector<int> a, int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int Min(vector<int> a, int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

double Variance(vector<int> a, int n) {
	double b = 0.0;
	int aver = Average(a, n);
	for (int i = 0; i < n; i++)
		b += pow((a[i] - aver), 2);
	return b / double(n);
}

double StandardDeviation(vector<int> a, int n) {
	return sqrt(Variance(a, n));
}

vector<int> DividableByThree(vector<int> a, int n) {
	vector<int> b;
	for (int i = 0; i < n; i++)
        if (a[i] % 3 == 0)
            b.push_back(a[i]);
	return b;
}

int main() {
    vector<int> a;
    int n, temp;
    cout << "Okresl rozmiar tablicy: " << endl;
    cin >> n;
    cout << "Wypisz liczby: " << endl;
    while (a.size() < n) {
        cin >> temp;
        a.push_back(temp);
    }
	cout << "Wpisane liczby: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' '; cout << endl;
	cout << "Najwieksza wartosc: " << Max(a, n) << endl;
	cout << "Najmniejsza wartosc: " << Min(a, n) << endl;
	cout << "Srednia arytmetyczna: " << Average(a, n) << endl;
	cout << "Suma elementow: " << Sum(a, n) << endl;
	cout << "Odchylenie standardowe: " << StandardDeviation(a, n) << endl;
	cout << "Wariancja: " << Variance(a, n) << endl;
	vector<int> c = DividableByThree(a, n);
	if (c.size() > 0) {
        cout << "Liczby podzielne przez 3: ";
        for (int i = 0; i < c.size(); i++)
            cout << c[i] << ' '; cout << endl;
	}
	cout << "Podaj numer elementu tablicy aby go wyswietlic: ";
	cin >> temp;
	if (temp > 0 && temp <= n) {
        cout << "Element " << temp << " posiada wartosc: " << a[temp - 1] << endl;
	}
    return 0;
}
