#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, temp;
    double aver = 0.0, w = 0.0;
    vector<int> a, b;
    cout << "Podaj ilosc liczb: " << endl;
    cin >> n;
    cout << "Wypisz liczby: " << endl;
    while (a.size() < n) {
        cin >> temp;
        a.push_back(temp);
    }
    cout << "Wypisz wagi: " << endl;
    while (b.size() < n) {
        cin >> temp;
        b.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        aver += double(a[i] * b[i]);
        w += double(b[i]);
    }
    aver /= w;
    cout << "Srednia wazona liczb wynosi: " << aver << endl;
    return 0;
}
