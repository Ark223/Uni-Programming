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
    int b = Max(a, n), c = Min(a, n), d = Sum(a, n);
    double e = Average(a, n), f = StandardDeviation(a, n), g = Variance(a, n);
    cout << "Najwieksza wartosc: " << b << endl;
    cout << "Najmniejsza wartosc: " << c << endl;
    cout << "Srednia arytmetyczna: " << e << endl;
    cout << "Suma elementow: " << d << endl;
    cout << "Odchylenie standardowe: " << f << endl;
    cout << "Wariancja: " << g << endl;
    vector<int> h = DividableByThree(a, n);
    if (h.size() > 0) {
        cout << "Liczby podzielne przez 3: ";
        for (int i = 0; i < h.size(); i++)
            cout << h[i] << ' '; cout << endl;
    }
    cout << "Podaj numer elementu tablicy aby wyswietlic jego wartosc: ";
    cin >> temp;
    if (temp > 0 && temp <= n) {
        cout << "Element " << temp << " posiada wartosc: " << a[temp - 1] << endl;
    }
    return 0;
}
